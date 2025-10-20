#include <stdint.h>        // standard integer definition
#include <string.h>        // string manipulation
#include "driver_flash.h"         // flash definition
#include "co_error.h"      // error definition
#include "uart0.h"
#include "rwip.h"
#include "ll.h"
#include "driver_flash.h"
#include "wdt.h"
#include "icu.h"
#if(SPI_DRIVER==1)
#include "spi.h"
#endif
#include "driver_gpio.h"
#define FLASH_OTP_ADDRESS_BLOCK1    0x001000
#define FLASH_OTP_ADDRESS_BLOCK2    0x002000
#define FLASH_CALI_DATA_ADDRESS     FLASH_OTP_ADDRESS_BLOCK1
#define SDADC_CALI_DATA_LEN         8
const char otp_chip_magic[8] = {'B','K','3','4','3','7','0','B'};
/// Flash environment structure
struct flash_env_tag
{
    /// base address
    uint32_t    base_addr;
    /// length
    uint32_t    length;
    /// type
    uint32_t    space_type;
};

/// Flash environment structure variable
struct flash_env_tag flash_env;
uint32_t flash_mid = 0;
uint8_t flash_uid[16];
static uint8_t flash_enable_write_flag1;
static uint8_t flash_enable_write_flag2;
static uint8_t flash_enable_write_flag3;
static uint8_t flash_enable_write_flag4;
static uint8_t flash_enable_erase_flag1;
static uint8_t flash_enable_erase_flag2;
extern void code_sanity_check( uint8_t *uid );


void set_flash_clk(unsigned char clk_conf) 
{
    //note :>16M don't use la for flash debug
    unsigned int temp0;
    temp0 = REG_FLASH_CONF;
    REG_FLASH_CONF = ( (clk_conf << BIT_FLASH_CLK_CONF)
                      | (temp0    &  SET_MODE_SEL)
                      | (temp0    &  SET_FWREN_FLASH_CPU)
                      | (temp0    &  SET_WRSR_DATA)
                      | (temp0    &  SET_CRC_EN));
    while(REG_FLASH_OPERATE_SW & 0x80000000){;}
}
uint8_t check_flash_ID(void)
{
    return(flash_mid == get_flash_ID());
}
uint32_t get_flash_ID(void)
{
    unsigned int temp0;

    while(REG_FLASH_OPERATE_SW & 0x80000000);

    REG_FLASH_OPERATE_SW = ( FLASH_ADDR_FIX
                            | (FLASH_OPCODE_RDID << BIT_OP_TYPE_SW)
                            | (0x1 << BIT_OP_SW));
    while(REG_FLASH_OPERATE_SW & 0x80000000);

    for (temp0=0; temp0<8; temp0++)
            REG_FLASH_DATA_SW_FLASH = 0xffffffff;

    return REG_FLASH_RDID_DATA_FLASH ;
}

uint32_t flash_read_sr(void)
{
    uint32_t temp = 0;

    while(REG_FLASH_OPERATE_SW & 0x80000000);

    REG_FLASH_OPERATE_SW = ( FLASH_ADDR_FIX
                            | (FLASH_OPCODE_RDSR << BIT_OP_TYPE_SW)
                            | (0x1 << BIT_OP_SW));

    
    while(REG_FLASH_OPERATE_SW & 0x80000000);

    temp = (REG_FLASH_SR_DATA_CRC_CNT&0xff);

    REG_FLASH_OPERATE_SW = ( FLASH_ADDR_FIX
                            | (FLASH_OPCODE_RDSR2 << BIT_OP_TYPE_SW)
                            | (0x1 << BIT_OP_SW));

    while(REG_FLASH_OPERATE_SW & 0x80000000);

    temp |= (REG_FLASH_SR_DATA_CRC_CNT&0xff) << 8;

    return temp ;
}

void flash_write_sr_temp( uint8_t bytes,  uint16_t val )
{
    if(flash_mid != get_flash_ID())
    return;
    switch(flash_mid)
    {
        case MX_FLASH_4M:
        case MX_FLASH_1:   //MG xx
        REG_FLASH_CONF &= 0xffdf0fff;
        break;     

        case GD_FLASH_1:  //QD xx ,
        case BY25Q80:
        case PN25f04:
        REG_FLASH_CONF &= 0xfefe0fff;
        break;
        case P25Q40U:
        case TH25D40HB:
        REG_FLASH_CONF &= 0xfef00fff;
        break;
        case XTX_FLASH_1:   //XTX xx
        case GD_MD25D40:
        case GD_GD25WD40:
        case P25D22U:
        case P25D24U:    
        default:
        REG_FLASH_CONF &= 0xffff0fff;
        break;
    }

    if(bytes==0||bytes>2)
    {
        return;
    }
    REG_FLASH_CONF |= (val << BIT_WRSR_DATA)|SET_FWREN_FLASH_CPU;
    while(REG_FLASH_OPERATE_SW & 0x80000000);
    if(flash_mid != get_flash_ID())
        return;
    if( bytes == 1 ) 
    {
        REG_FLASH_OPERATE_SW = (FLASH_ADDR_FIX|(FLASH_OPCODE_WRSR << BIT_OP_TYPE_SW)
                               | (0x1<< BIT_OP_SW)
                               | (0x1<< BIT_WP_VALUE));
        
    }
    else if(bytes == 2 )
    {
        REG_FLASH_OPERATE_SW = (FLASH_ADDR_FIX|(FLASH_OPCODE_WRSR2 << BIT_OP_TYPE_SW)
                               | (0x1<< BIT_OP_SW)
                               | (0x1<< BIT_WP_VALUE));       
    }
        
    while(REG_FLASH_OPERATE_SW & 0x80000000);


    REG_FLASH_OPERATE_SW = FLASH_ADDR_FIX; 

    while(REG_FLASH_OPERATE_SW & 0x80000000);
}

void flash_write_sr( uint8_t bytes,  uint16_t val )
{
    static uint8_t write_sr_cnt = 0;
    #ifdef CHECK_LOW_VOLT_ENABLE
    check_low_volt_sleep();
    #endif
    if(flash_read_sr() == val) 
    {
        return; 
    }
    //uart_printf("write sr=%x\n",val);   
    flash_write_sr_temp(bytes, val);

    while (flash_read_sr() != val)
    {
        flash_write_sr_temp(bytes, val);
        
        write_sr_cnt++;
        if(write_sr_cnt > 20)
        {
            uart_printf("boot write sr error! WDT_RESET!!!\r\n");
            wdt_enable(0x10);
            while(1);
        }
    }
}
void flash_wp_128k(void)
{
    uint32_t flash_sr;
    #ifdef CHECK_LOW_VOLT_ENABLE
    check_low_volt_sleep();
    #endif
    flash_sr=flash_read_sr( );
   // uart_printf("flash_sr=%x\n",flash_sr);   
    switch(flash_mid)
    {
        case MX_FLASH_4M:
        case MX_FLASH_1:   //MG xx
            if(flash_sr!=0x088C)
                flash_write_sr( 2, 0x088C );
            break;
        case XTX_FLASH_1:   //XTX xx
            if(flash_sr!=0xAC)
                flash_write_sr( 1, 0xAC );
            break;   

        case GD_FLASH_1:  //QD xx ,
        case BY25Q80:
        case PN25f04:
            if(flash_sr!=0x00ac)
                flash_write_sr( 2, 0x00ac );
            break;
        case P25Q40U:
        case TH25D40HB:
            if(flash_sr!=0x002c)
                flash_write_sr( 2, 0x002c );  
            break;
        case P25D22U:
        case P25D24U: 
            if(flash_sr!=0x00a8)
                flash_write_sr( 1, 0xa8 );
            break;
        case GD_MD25D40:
        case GD_GD25WD40:    
        default:
            if(flash_sr!=0x98)
                flash_write_sr( 1, 0x98 );
            break;    
    }
}

void flash_wp_256k( void)
{
    uint32_t flash_sr;
    #ifdef CHECK_LOW_VOLT_ENABLE
    check_low_volt_sleep();
    #endif
    flash_sr=flash_read_sr( );
    
   // uart_printf("flash_sr=%x\n",flash_sr);   
    switch(flash_mid)
    {
        case MX_FLASH_4M:
        case MX_FLASH_1://MG xx
            if(flash_sr!=0x088C)
                flash_write_sr( 2, 0x088C );
            break;
        case XTX_FLASH_1://XTX xx
            if(flash_sr!=0xAC)
                flash_write_sr( 1, 0xAC );
            break;   

        case GD_FLASH_1://QD xx ,
        case BY25Q80:
        case PN25f04:
            if(flash_sr!=0x00ac)
                flash_write_sr( 2, 0x00ac );
            break;
        case P25Q40U:
        case TH25D40HB:
            if(flash_sr!=0x002c)
            flash_write_sr( 2, 0x002c );  
            break;
        case P25D22U:
        case P25D24U:
            if(flash_sr!=0x9c)
                flash_write_sr( 1, 0x9c );
            break;
        case GD_MD25D40:
        case GD_GD25WD40:    
        default:
            if(flash_sr!=0x98)
                flash_write_sr( 1, 0x98 );
            break;    
    }
}

void flash_wp_ALL( void )
{
    uint32_t flash_sr;
    #ifdef CHECK_LOW_VOLT_ENABLE
    check_low_volt_sleep();
    #endif
    flash_sr=flash_read_sr();
    
    switch(flash_mid)
    {
        case MX_FLASH_4M:
        case MX_FLASH_1://MG xx
            if(flash_sr!=0x00bc)
                flash_write_sr( 2, 0x00bc );
            break;
        case XTX_FLASH_1://XTX xx
            if(flash_sr!=0xBC)    
                flash_write_sr( 1, 0xBC );
            break;  
        case GD_FLASH_1://QD xx ,
        case BY25Q80:
        case PN25f04:
            if(flash_sr!=0x0094)
                flash_write_sr( 2, 0x0094 );
            break;
        case P25Q40U:
        case TH25D40HB:
            if(flash_sr!=0x0010)
                flash_write_sr( 2, 0x0010 );
            break;    
        case GD_MD25D40:
        case GD_GD25WD40:
        case P25D22U:
        case P25D24U:    
        default:
            if(flash_sr!=0x9c)
                flash_write_sr( 1, 0x9c );
            break;    
    }
}



void flash_init(void)
{   
    flash_mid = get_flash_ID();
    uart_printf("flash_mid=%x\n",flash_mid);
    
    #if(CODE_SANITY_CHECK_ENABLE==1)
    get_flash_uid();
    code_sanity_check(flash_uid);
    #endif
    
    flash_set_dual_mode();       
    set_flash_clk(0x00);    
    
}


void flash_erase_sector(uint32_t address)
{
    GLOBAL_INT_DISABLE();
    if(flash_enable_erase_flag1==FLASH_ERASE_ENABLE1&&flash_enable_erase_flag2==FLASH_ERASE_ENABLE2)    
    {
        flash_wp_128k();
        
        while(REG_FLASH_OPERATE_SW & 0x80000000);

        REG_FLASH_OPERATE_SW = ( (address << BIT_ADDRESS_SW)
                               | (FLASH_OPCODE_SE<< BIT_OP_TYPE_SW)
                               | (0x1             << BIT_OP_SW));

        while(REG_FLASH_OPERATE_SW & 0x80000000);

        flash_wp_ALL();
    }
    GLOBAL_INT_RESTORE();
}



void flash_read_data (uint8_t *buffer, uint32_t address, uint32_t len)
{
    
    uint32_t i;
    uint32_t addr = address&(~0x1F);
    uint32_t buf[8];
    uint8_t *pb = (uint8_t *)&buf[0];
   
    if (len == 0)
        return;
    GLOBAL_INT_DISABLE();
    while(REG_FLASH_OPERATE_SW & 0x80000000);
 
    while (len)
    {
        REG_FLASH_OPERATE_SW = (  (addr << BIT_ADDRESS_SW)
                                | (FLASH_OPCODE_READ << BIT_OP_TYPE_SW)
                                | (0x1 << BIT_OP_SW));
        while(REG_FLASH_OPERATE_SW & 0x80000000);
        addr+=32;

        for (i = 0; i < 8; i++)
            buf[i] = REG_FLASH_DATA_FLASH_SW;

        for (i = (address & 0x1F); i < 32; i++)
        {
            *buffer++ = pb[i];
            address++;
            len--;
            if (len == 0)
                break;
        }
    }    
    REG_FLASH_OPERATE_SW=FLASH_ADDR_FIX ;
    for (i=0; i<8; i++)
        REG_FLASH_DATA_SW_FLASH = 0xffffffff;
    GLOBAL_INT_RESTORE();
}

void flash_write_data (uint8_t *buffer, uint32_t address, uint32_t len)
{
    uint32_t  i;
    uint32_t addr = address&(~0x1F);
    uint32_t buf[8] = {~0x00UL};
    uint8_t *pb = (uint8_t *)&buf[0];
    if (len == 0)
        return;
    GLOBAL_INT_DISABLE();

    while(REG_FLASH_OPERATE_SW & 0x80000000);
    
    flash_enable_write_flag3=FLASH_WRITE_ENABLE3; 
    flash_wp_128k();

    while(len) 
    {
        if((address & 0x1F) || (len < 32))
            flash_read_data(pb, addr, 32);

        for(i = (address & 0x1F); i < 32; i++) 
        {
            if(len)
            {
                pb[i] = *buffer++;
                address++;
                len--;
            }
        }

        flash_enable_write_flag4=FLASH_WRITE_ENABLE4; 
        for (i=0; i<8; i++)
            REG_FLASH_DATA_SW_FLASH = buf[i];


        if(flash_enable_write_flag1==FLASH_WRITE_ENABLE1 && flash_enable_write_flag2==FLASH_WRITE_ENABLE2 )
        {
            while(REG_FLASH_OPERATE_SW & 0x80000000);
            
            if(flash_enable_write_flag3==FLASH_WRITE_ENABLE3 && flash_enable_write_flag4==FLASH_WRITE_ENABLE4)
            {
                REG_FLASH_OPERATE_SW = (  (addr << BIT_ADDRESS_SW)
                                    | (FLASH_OPCODE_PP << BIT_OP_TYPE_SW)
                                    | (0x1 << BIT_OP_SW));
            }
            while(REG_FLASH_OPERATE_SW & 0x80000000);
        }
        addr+=32;
    }
        // 2021/7/16 user maybe modify this ,the SRreg(proctor) is more slower by writed, n*100 times?
    flash_wp_ALL();
    REG_FLASH_OPERATE_SW=FLASH_ADDR_FIX ;
    flash_enable_write_flag3=0;
    flash_enable_write_flag4=0;
    for (i=0; i<8; i++)
        REG_FLASH_DATA_SW_FLASH = 0xffffffff;
    GLOBAL_INT_RESTORE();
}

void flash_set_qe(void)
{
    uint32_t temp0;
    while(REG_FLASH_OPERATE_SW & 0x80000000){;}

    temp0 = REG_FLASH_CONF; //����WRSR Status data

    if(flash_mid == XTX_FLASH_1)  // wanghong
    return;
    if((flash_mid == MX_FLASH_1)||(flash_mid == MX_FLASH_4M))  // wanghong
    {
        //WRSR QE=1
        REG_FLASH_CONF = ((temp0 &  SET_FLASH_CLK_CONF)
                            | (temp0 &  SET_MODE_SEL)
                            | (temp0 &  SET_FWREN_FLASH_CPU)
                            | (temp0 & SET_WRSR_DATA)
                            | (0x1 << 16) // SET QE=1,quad enable
                            | (temp0 &  SET_CRC_EN));
        //Start WRSR
        REG_FLASH_OPERATE_SW = (  FLASH_ADDR_FIX
                                | (FLASH_OPCODE_WRSR2 << BIT_OP_TYPE_SW)
                                | (0x1 << BIT_OP_SW)); 
    }
    else
    {
        REG_FLASH_CONF = ( (temp0 &  SET_FLASH_CLK_CONF)
                            | (temp0 &  SET_MODE_SEL)
                            | (temp0 &  SET_FWREN_FLASH_CPU)
                            | (temp0 & SET_WRSR_DATA)
                            | (0x01 << 19)
                            | (temp0 &  SET_CRC_EN));
        //Start WRSR
        REG_FLASH_OPERATE_SW = ( FLASH_ADDR_FIX
                                | (FLASH_OPCODE_WRSR2 << BIT_OP_TYPE_SW)
                                | (0x1 << BIT_OP_SW)); 
    }
    while(REG_FLASH_OPERATE_SW & 0x80000000);
}



void clr_flash_qwfr(void)
{
    uint32_t temp0,mod_sel;    
    
    temp0 = REG_FLASH_CONF;
    while(REG_FLASH_OPERATE_SW & 0x80000000){;}
    mod_sel = temp0 & (0xC << BIT_MODE_SEL); //??3ymode_sel?D
    mod_sel |= (0x1 << BIT_MODE_SEL);
    REG_FLASH_CONF = (  (temp0 &  SET_FLASH_CLK_CONF)
                        | mod_sel
                        | (temp0 &  SET_FWREN_FLASH_CPU)
                        | (temp0 &  SET_WRSR_DATA)
                        | (temp0 &  SET_CRC_EN));
    //reset flash
    
    if(flash_mid == XTX_FLASH_1)
    {
        REG_FLASH_OPERATE_SW = (  (FLASH_ADDR_FIX<< BIT_ADDRESS_SW)
                                | (FLASH_OPCODE_CRMR << BIT_OP_TYPE_SW)
                                | (0x1               << BIT_OP_SW));
    }
    else
    {
        REG_FLASH_OPERATE_SW = (  (FLASH_ADDR_FIX<< BIT_ADDRESS_SW)
                                | (FLASH_OPCODE_CRMR2 << BIT_OP_TYPE_SW)
                                | (0x1               << BIT_OP_SW));
    }

    while(REG_FLASH_OPERATE_SW & 0x80000000);
}


void flash_set_dual_mode(void)
{
    clr_flash_qwfr();
    REG_FLASH_CONF &= (~(7<<BIT_MODE_SEL));
    REG_FLASH_CONF |= (1<<BIT_MODE_SEL);
    while(REG_FLASH_OPERATE_SW & 0x80000000);
}


uint8_t flash_read( uint32_t address, uint32_t len, uint8_t *buffer)
{
    uint32_t pre_address;
    uint32_t post_address;
    uint32_t pre_len;
    uint32_t post_len;
    uint32_t page0;
    uint32_t page1;
    page0 = address &(~FLASH_PAGE_MASK);
    page1 = (address + len) &(~FLASH_PAGE_MASK);
    if(page0 != page1)
    {
        pre_address = address;
        pre_len = page1 - address;
        flash_read_data(buffer, pre_address, pre_len);
        post_address = page1;
        post_len = address + len - page1;
        flash_read_data((buffer + pre_len), post_address, post_len);
    }
    else
    {
        flash_read_data(buffer, address, len);
    }
        
    return CO_ERROR_NO_ERROR;
}

uint8_t flash_write( uint32_t address, uint32_t len, uint8_t *buffer)
{
    uint32_t pre_address;
    uint32_t post_address;
    uint32_t pre_len;
    uint32_t post_len;
    uint32_t page0;
    uint32_t page1;
    
    if(flash_mid != get_flash_ID())
    {
        uart_printf("flash = 0x%x\r\n", get_flash_ID());
        return CO_ERROR_UNDEFINED;
    }

    flash_enable_write_flag1=FLASH_WRITE_ENABLE1; 
    
    page0 = address &(~FLASH_PAGE_MASK);
    page1 = (address + len) &(~FLASH_PAGE_MASK);
     
    if(page0 != page1)
    {
        pre_address = address;
        pre_len = page1 - address;
        flash_enable_write_flag2=FLASH_WRITE_ENABLE2;
        flash_write_data(buffer, pre_address, pre_len);
        
        post_address = page1;
        post_len = address + len - page1;
        flash_write_data((buffer + pre_len), post_address, post_len);

    }
    else
    {
        flash_enable_write_flag2=FLASH_WRITE_ENABLE2;
        flash_write_data(buffer, address, len);

    }
    flash_enable_write_flag1=0; 
    flash_enable_write_flag2=0;    
    
    return CO_ERROR_NO_ERROR;
}


uint8_t flash_erase(uint32_t address, uint32_t len)
{
    /* assume: the worst span is four sectors*/
    int erase_addr;
    int erase_len;


    flash_enable_erase_flag1=FLASH_ERASE_ENABLE1;
    
    if(flash_mid != get_flash_ID())
    {
        return CO_ERROR_UNDEFINED;
    }
    
    
    {
        erase_addr = address & (~FLASH_ERASE_SECTOR_SIZE_MASK);
        erase_len = len;
    }
    do
    {
        int i;
        int erase_whole_sector_cnt;
        //erase_whole_sector_cnt = erase_len >> FLASH_ERASE_SECTOR_SIZE_RSL_BIT_CNT;
        erase_whole_sector_cnt = erase_len/FLASH_ERASE_SECTOR_SIZE + (erase_len%FLASH_ERASE_SECTOR_SIZE>0? 1:0);

        flash_enable_erase_flag2=FLASH_ERASE_ENABLE2;
        for(i = 0; i < erase_whole_sector_cnt; i ++)
        {
            flash_erase_sector(erase_addr);
            erase_addr += FLASH_ERASE_SECTOR_SIZE;
            //erase_len -= FLASH_ERASE_SECTOR_SIZE;
        }
    }
    while(0);
    
    flash_enable_erase_flag1=0;
    flash_enable_erase_flag2=0;
    return CO_ERROR_NO_ERROR;
}

void get_flash_uid(void)
{
    #if(SPI_DRIVER==1)
    int i;
    uint8_t spi_wbuf[21];
    uint8_t spi_rbuf[21];
   
    uart_printf("==get_flash_uid==\r\n");
    
    setf_SYS_Reg0xf_spi_fla_sel;
    spi_init(SPI_MASTER,2,SPI_8BITS,0);

    memset(spi_wbuf,0,sizeof(spi_wbuf));
    memset(spi_rbuf,0,sizeof(spi_rbuf));
    spi_wbuf[0]=0x4b;

    spi_read_flash_uid(&spi_wbuf[0],21,&spi_rbuf[0],21);
    clrf_SYS_Reg0xf_spi_fla_sel;
    spi_uninit(0);
    uart_printf("flash_uid:");
    for(i=5;i<21;i++)
    {
        flash_uid[i-5]=spi_rbuf[i];
        uart_printf("%02x,",spi_rbuf[i]);
    }
    uart_printf(" \r\n");
    #endif
}
void flash_read_otp_data(uint8_t *buffer, uint32_t address, uint32_t len)
{
    uint32_t i;
    uint32_t addr = address&(~0x1F);
    uint32_t buf[8];
    uint8_t *pb = (uint8_t *)&buf[0];
       
    if (len == 0 || len > 256)
        return;
    GLOBAL_INT_DISABLE();
    while(REG_FLASH_OPERATE_SW & 0x80000000);
 
    while (len)
    {
        REG_FLASH_OPERATE_SW = (  (addr << BIT_ADDRESS_SW)
                                | (FLASH_OPCODE_RDSCUR << BIT_OP_TYPE_SW)
                                | (0x1 << BIT_OP_SW));
        while(REG_FLASH_OPERATE_SW & 0x80000000);
        addr+=32;

        for (i = 0; i < 8; i++)
            buf[i] = REG_FLASH_DATA_FLASH_SW;

        for (i = (address & 0x1F); i < 32; i++)
        {
            *buffer++ = pb[i];
            address++;
            len--;
            if (len == 0)
                break;
        }
    }    
    REG_FLASH_OPERATE_SW=FLASH_ADDR_FIX ;
    for (i=0; i<8; i++)
        REG_FLASH_DATA_SW_FLASH = 0xffffffff;
    GLOBAL_INT_RESTORE();
}
int8_t get_flash_otp_calibration(CALI_TAG tag,uint8_t *cali_data)
{
    int8_t ret = -1;
    bool tlv_loop = TRUE;
    bool tlv_valid = TRUE;
    t_TLV_TYPE tlv_data;
    uint8_t otp_buff[256];
    uint8_t pos = 0,len = 0;
    flash_read_otp_data(otp_buff,FLASH_CALI_DATA_ADDRESS,256);
    if(memcmp(otp_buff,otp_chip_magic,sizeof(otp_chip_magic))) /* correct cali data from OTP */
    {
        uart_printf("OTP has no cali-data!!!\r\n");
        return -1;
    }
    pos += sizeof(otp_chip_magic); // magic offset;
    while(tlv_loop) {
        memcpy((uint8_t *)&tlv_data, otp_buff + pos, sizeof(t_TLV_TYPE));
        tlv_valid = TRUE;
        switch(tlv_data.tag) {
            case TLV_TAG_CALI_INVALID:
                tlv_valid = FALSE;
                break;
            case TLV_TAG_CALI_END:
                tlv_loop = FALSE;
                break;
            case TLV_TAG_CALI_SDADC:
                len = SDADC_CALI_DATA_LEN; // K = int16,B = int16
                break;
            default:len = 0; break; //// the tag is valid,but don't parse;
        }
        if(tlv_loop) {
            pos += sizeof(t_TLV_TYPE);
            if(tlv_valid) {   // this type is valid;
                if(tlv_data.len > len) {// TLV.len is error
                    uart_printf("TLV.err\r\n");
                } else {
                    len = tlv_data.len;
                }
                if((cali_data != NULL) && (tlv_data.tag == tag)) {
                    memcpy(cali_data,otp_buff + pos,len);
                    ret = len;
                    break;
                }
                pos += len;
            }
        }
    } 
    return ret;  
}
#if 0
void flash_write_some_data(uint8_t *buffer, uint32_t address, uint32_t len)
    // �����浱ǰ��ַ�µ�����1K����
{
    unsigned char flash_temp[1024];
    flash_wp_256k(); // �� bug 1�� �����ռ䲻�ԣ�2��д��û�лָ�����
    flash_read(address&0xfffffc00, 1024,flash_temp);//the addr is the word,so the addr +20
    memcpy(&flash_temp[address&0x3ff],buffer,len);
    flash_erase(address,0x1000);
    flash_write(address&0xfffffc00,1024,flash_temp);
    flash_wp_ALL();

}

#define  TEST_FLASH_ADDRESS  0x3ff00
#define  TEST_LEN 0xff
void flash_test(void)
{
    unsigned char w_temp[TEST_LEN];
    unsigned char r_temp[TEST_LEN];
    int i;
    uart_printf("==============FLASH_TEST==============\r\n");
   
    uart_printf("==============ADDR = 0x3ff00,LEN = 0xff==============\r\n");
    Delay_ms(20);

    flash_wp_128k();
    uart_printf("flash_test_org:\n ");
    flash_read(TEST_FLASH_ADDRESS ,TEST_LEN,r_temp);

    for (i=0; i<TEST_LEN; i++)
    {
        uart_printf("%x,",r_temp[i]);
        w_temp[i] = i;
    }
    uart_printf("\n flash write 1:\r\n ");
    
    flash_write(TEST_FLASH_ADDRESS ,TEST_LEN,w_temp);
    
    flash_read(TEST_FLASH_ADDRESS ,TEST_LEN,r_temp);

    uart_printf("flash read 1:\r\n ");
    for (i=0; i<TEST_LEN; i++)
    {
        uart_printf("%x,",r_temp[i]);
    }
    uart_printf("\n flase earse\r\n");
    flash_erase(TEST_FLASH_ADDRESS,TEST_LEN);
    
    flash_read(TEST_FLASH_ADDRESS ,TEST_LEN,r_temp);

    uart_printf("flash read 2:\r\n ");
    for (i=0; i<TEST_LEN; i++)
    {
        uart_printf("%x,",r_temp[i]);
        w_temp[i] = i+0x55;
    }
    uart_printf("\n flash write 2:\r\n");
    flash_write(TEST_FLASH_ADDRESS ,TEST_LEN,w_temp);
    
    flash_read(TEST_FLASH_ADDRESS ,TEST_LEN,r_temp);

    uart_printf("flash read 3:\r\n ");
    for (i=0; i<TEST_LEN; i++)
    {
        uart_printf("%x,",r_temp[i]);
    }
    uart_printf("\n ");
    uart_printf("==============FLASH_TEST_END==============\r\n");

}
#endif

