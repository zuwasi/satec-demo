#ifndef _BK3437_REGLIST_H_
#define _BK3437_REGLIST_H_


//************************************************************//
//GPIO_MAP
//************************************************************//
#define BASEADDR_GPIO_MAP                                       ATE Test

//************************************************************//
//SYS
//************************************************************//
#define BASEADDR_SYS                                            0x00800000
//addSYS_Reg0x0
#define addSYS_Reg0x0                                           *((volatile unsigned long *) (0x00800000+0x0*4))


#define posSYS_Reg0x0_jtag_mode                                 9
#define bitSYS_Reg0x0_jtag_mode                                 0x200
#define set_SYS_Reg0x0_jtag_mode(val)                           addSYS_Reg0x0 = ((addSYS_Reg0x0 & (~0x200)) | ((val) << 9))
#define setf_SYS_Reg0x0_jtag_mode                               addSYS_Reg0x0 |= 0x200
#define clrf_SYS_Reg0x0_jtag_mode                               addSYS_Reg0x0 &= ~0x200
#define get_SYS_Reg0x0_jtag_mode                                ((addSYS_Reg0x0 & 0x200) >> 9)


#define posSYS_Reg0x0_dis_ram_rent                              1
#define bitSYS_Reg0x0_dis_ram_rent                              0x1E
#define set_SYS_Reg0x0_dis_ram_rent(val)                        addSYS_Reg0x0 = ((addSYS_Reg0x0 & (~0x1E)) | ((val) << 1))
#define get_SYS_Reg0x0_dis_ram_rent                             ((addSYS_Reg0x0 & 0x1E) >> 1)

#define posSYS_Reg0x0_dis_pwr_save                              0
#define bitSYS_Reg0x0_dis_pwr_save                              0x1
#define set_SYS_Reg0x0_dis_pwr_save(val)                        addSYS_Reg0x0 = ((addSYS_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_SYS_Reg0x0_dis_pwr_save                            addSYS_Reg0x0 |= 0x1
#define clrf_SYS_Reg0x0_dis_pwr_save                            addSYS_Reg0x0 &= ~0x1
#define get_SYS_Reg0x0_dis_pwr_save                             (addSYS_Reg0x0 & 0x1)

//addSYS_Reg0x1
#define addSYS_Reg0x1                                           *((volatile unsigned long *) (0x00800000+0x1*4))


#define posSYS_Reg0x1_gotosleep                                 1
#define bitSYS_Reg0x1_gotosleep                                 0x2
#define set_SYS_Reg0x1_gotosleep(val)                           addSYS_Reg0x1 = ((addSYS_Reg0x1 & (~0x2)) | ((val) << 1))
#define setf_SYS_Reg0x1_gotosleep                               addSYS_Reg0x1 |= 0x2
#define clrf_SYS_Reg0x1_gotosleep                               addSYS_Reg0x1 &= ~0x2
#define get_SYS_Reg0x1_gotosleep                                ((addSYS_Reg0x1 & 0x2) >> 1)

#define posSYS_Reg0x1_CPU_PWD                                   0
#define bitSYS_Reg0x1_CPU_PWD                                   0x1
#define set_SYS_Reg0x1_CPU_PWD(val)                             addSYS_Reg0x1 = ((addSYS_Reg0x1 & (~0x1)) | ((val) << 0))
#define setf_SYS_Reg0x1_CPU_PWD                                 addSYS_Reg0x1 |= 0x1
#define clrf_SYS_Reg0x1_CPU_PWD                                 addSYS_Reg0x1 &= ~0x1
#define get_SYS_Reg0x1_CPU_PWD                                  (addSYS_Reg0x1 & 0x1)

//addSYS_Reg0x2
#define addSYS_Reg0x2                                           *((volatile unsigned long *) (0x00800000+0x2*4))
#define posSYS_Reg0x2_core_div                                  0
#define bitSYS_Reg0x2_core_div                                  0x7F
#define set_SYS_Reg0x2_core_div(val)                            addSYS_Reg0x2 = ((addSYS_Reg0x2 & (~0x7F)) | ((val) << 0))
#define get_SYS_Reg0x2_core_div                                 (addSYS_Reg0x2 & 0x7F)

#define posSYS_Reg0x2_core_sel                                  7
#define bitSYS_Reg0x2_core_sel                                  0x180
#define set_SYS_Reg0x2_core_sel(val)                            addSYS_Reg0x2 = ((addSYS_Reg0x2 & (~0x180)) | ((val) << 7))
#define get_SYS_Reg0x2_core_sel                                 ((addSYS_Reg0x2 & 0x180) >> 7)

#define posSYS_Reg0x2_dsp_div2                                  9
#define bitSYS_Reg0x2_dsp_div2                                  0x200
#define set_SYS_Reg0x2_dsp_div2(val)                            addSYS_Reg0x2 = ((addSYS_Reg0x2 & (~0x200)) | ((val) << 9))
#define setf_SYS_Reg0x2_dsp_div2                                addSYS_Reg0x2 |= 0x200
#define clrf_SYS_Reg0x2_dsp_div2                                addSYS_Reg0x2 &= ~0x200
#define get_SYS_Reg0x2_dsp_div2                                 ((addSYS_Reg0x2 & 0x200) >> 9)

#define posSYS_Reg0x2_cpu_div2                                  10
#define bitSYS_Reg0x2_cpu_div2                                  0x400
#define set_SYS_Reg0x2_cpu_div2(val)                            addSYS_Reg0x2 = ((addSYS_Reg0x2 & (~0x400)) | ((val) << 10))
#define setf_SYS_Reg0x2_cpu_div2                                addSYS_Reg0x2 |= 0x400
#define clrf_SYS_Reg0x2_cpu_div2                                addSYS_Reg0x2 &= ~0x400
#define get_SYS_Reg0x2_cpu_div2                                 ((addSYS_Reg0x2 & 0x400) >> 10)

#define posSYS_Reg0x2_ahb_div2                                  11
#define bitSYS_Reg0x2_ahb_div2                                  0x800
#define set_SYS_Reg0x2_ahb_div2(val)                            addSYS_Reg0x2 = ((addSYS_Reg0x2 & (~0x800)) | ((val) << 11))
#define setf_SYS_Reg0x2_ahb_div2                                addSYS_Reg0x2 |= 0x800
#define clrf_SYS_Reg0x2_ahb_div2                                addSYS_Reg0x2 &= ~0x800
#define get_SYS_Reg0x2_ahb_div2                                 ((addSYS_Reg0x2 & 0x800) >> 11)

//addSYS_Reg0x3
#define addSYS_Reg0x3                                           *((volatile unsigned long *) (0x00800000+0x3*4))
#define posSYS_Reg0x3_uart0_pwd                                 0
#define bitSYS_Reg0x3_uart0_pwd                                 0x1
#define set_SYS_Reg0x3_uart0_pwd(val)                           addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x1)) | ((val) << 0))
#define setf_SYS_Reg0x3_uart0_pwd                               addSYS_Reg0x3 |= 0x1
#define clrf_SYS_Reg0x3_uart0_pwd                               addSYS_Reg0x3 &= ~0x1
#define get_SYS_Reg0x3_uart0_pwd                                (addSYS_Reg0x3 & 0x1)

#define posSYS_Reg0x3_uart1_pwd                                 1
#define bitSYS_Reg0x3_uart1_pwd                                 0x2
#define set_SYS_Reg0x3_uart1_pwd(val)                           addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x2)) | ((val) << 1))
#define setf_SYS_Reg0x3_uart1_pwd                               addSYS_Reg0x3 |= 0x2
#define clrf_SYS_Reg0x3_uart1_pwd                               addSYS_Reg0x3 &= ~0x2
#define get_SYS_Reg0x3_uart1_pwd                                ((addSYS_Reg0x3 & 0x2) >> 1)

#define posSYS_Reg0x3_tim0_pwd                                  2
#define bitSYS_Reg0x3_tim0_pwd                                  0x4
#define set_SYS_Reg0x3_tim0_pwd(val)                            addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x4)) | ((val) << 2))
#define setf_SYS_Reg0x3_tim0_pwd                                addSYS_Reg0x3 |= 0x4
#define clrf_SYS_Reg0x3_tim0_pwd                                addSYS_Reg0x3 &= ~0x4
#define get_SYS_Reg0x3_tim0_pwd                                 ((addSYS_Reg0x3 & 0x4) >> 2)

#define posSYS_Reg0x3_tim1_pwd                                  3
#define bitSYS_Reg0x3_tim1_pwd                                  0x8
#define set_SYS_Reg0x3_tim1_pwd(val)                            addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x8)) | ((val) << 3))
#define setf_SYS_Reg0x3_tim1_pwd                                addSYS_Reg0x3 |= 0x8
#define clrf_SYS_Reg0x3_tim1_pwd                                addSYS_Reg0x3 &= ~0x8
#define get_SYS_Reg0x3_tim1_pwd                                 ((addSYS_Reg0x3 & 0x8) >> 3)

#define posSYS_Reg0x3_pwm0_pwd                                  4
#define bitSYS_Reg0x3_pwm0_pwd                                  0x10
#define set_SYS_Reg0x3_pwm0_pwd(val)                            addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x10)) | ((val) << 4))
#define setf_SYS_Reg0x3_pwm0_pwd                                addSYS_Reg0x3 |= 0x10
#define clrf_SYS_Reg0x3_pwm0_pwd                                addSYS_Reg0x3 &= ~0x10
#define get_SYS_Reg0x3_pwm0_pwd                                 ((addSYS_Reg0x3 & 0x10) >> 4)


#define posSYS_Reg0x3_pwm1_pwd                                  6
#define bitSYS_Reg0x3_pwm1_pwd                                  0x40
#define set_SYS_Reg0x3_pwm1_pwd(val)                            addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x40)) | ((val) << 6))
#define setf_SYS_Reg0x3_pwm1_pwd                                addSYS_Reg0x3 |= 0x40
#define clrf_SYS_Reg0x3_pwm1_pwd                                addSYS_Reg0x3 &= ~0x40
#define get_SYS_Reg0x3_pwm1_pwd                                 ((addSYS_Reg0x3 & 0x40) >> 6)


#define posSYS_Reg0x3_rtc_pwd                                   8
#define bitSYS_Reg0x3_rtc_pwd                                   0x100
#define set_SYS_Reg0x3_rtc_pwd(val)                             addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x100)) | ((val) << 8))
#define setf_SYS_Reg0x3_rtc_pwd                                 addSYS_Reg0x3 |= 0x100
#define clrf_SYS_Reg0x3_rtc_pwd                                 addSYS_Reg0x3 &= ~0x100
#define get_SYS_Reg0x3_rtc_pwd                                  ((addSYS_Reg0x3 & 0x100) >> 8)

#define posSYS_Reg0x3_irda_pwd                                  9
#define bitSYS_Reg0x3_irda_pwd                                  0x200
#define set_SYS_Reg0x3_irda_pwd(val)                            addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x200)) | ((val) << 9))
#define setf_SYS_Reg0x3_irda_pwd                                addSYS_Reg0x3 |= 0x200
#define clrf_SYS_Reg0x3_irda_pwd                                addSYS_Reg0x3 &= ~0x200
#define get_SYS_Reg0x3_irda_pwd                                 ((addSYS_Reg0x3 & 0x200) >> 9)

#define posSYS_Reg0x3_sadc_pwd                                  10
#define bitSYS_Reg0x3_sadc_pwd                                  0x400
#define set_SYS_Reg0x3_sadc_pwd(val)                            addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x400)) | ((val) << 10))
#define setf_SYS_Reg0x3_sadc_pwd                                addSYS_Reg0x3 |= 0x400
#define clrf_SYS_Reg0x3_sadc_pwd                                addSYS_Reg0x3 &= ~0x400
#define get_SYS_Reg0x3_sadc_pwd                                 ((addSYS_Reg0x3 & 0x400) >> 10)

#define posSYS_Reg0x3_usb_pwd                                   11
#define bitSYS_Reg0x3_usb_pwd                                   0x800
#define set_SYS_Reg0x3_usb_pwd(val)                             addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x800)) | ((val) << 11))
#define setf_SYS_Reg0x3_usb_pwd                                 addSYS_Reg0x3 |= 0x800
#define clrf_SYS_Reg0x3_usb_pwd                                 addSYS_Reg0x3 &= ~0x800
#define get_SYS_Reg0x3_usb_pwd                                  ((addSYS_Reg0x3 & 0x800) >> 11)

#define posSYS_Reg0x3_i2c_pwd                                   12
#define bitSYS_Reg0x3_i2c_pwd                                   0x1000
#define set_SYS_Reg0x3_i2c_pwd(val)                             addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x1000)) | ((val) << 12))
#define setf_SYS_Reg0x3_i2c_pwd                                 addSYS_Reg0x3 |= 0x1000
#define clrf_SYS_Reg0x3_i2c_pwd                                 addSYS_Reg0x3 &= ~0x1000
#define get_SYS_Reg0x3_i2c_pwd                                  ((addSYS_Reg0x3 & 0x1000) >> 12)

#define posSYS_Reg0x3_spi_pwd                                   13
#define bitSYS_Reg0x3_spi_pwd                                   0x2000
#define set_SYS_Reg0x3_spi_pwd(val)                             addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x2000)) | ((val) << 13))
#define setf_SYS_Reg0x3_spi_pwd                                 addSYS_Reg0x3 |= 0x2000
#define clrf_SYS_Reg0x3_spi_pwd                                 addSYS_Reg0x3 &= ~0x2000
#define get_SYS_Reg0x3_spi_pwd                                  ((addSYS_Reg0x3 & 0x2000) >> 13)

#define posSYS_Reg0x3_efuse_pwd                                 14
#define bitSYS_Reg0x3_efuse_pwd                                 0x4000
#define set_SYS_Reg0x3_efuse_pwd(val)                           addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x4000)) | ((val) << 14))
#define setf_SYS_Reg0x3_efuse_pwd                               addSYS_Reg0x3 |= 0x4000
#define clrf_SYS_Reg0x3_efuse_pwd                               addSYS_Reg0x3 &= ~0x4000
#define get_SYS_Reg0x3_efuse_pwd                                ((addSYS_Reg0x3 & 0x4000) >> 14)

#define posSYS_Reg0x3_wdt_pwd                                   15
#define bitSYS_Reg0x3_wdt_pwd                                   0x8000
#define set_SYS_Reg0x3_wdt_pwd(val)                             addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x8000)) | ((val) << 15))
#define setf_SYS_Reg0x3_wdt_pwd                                 addSYS_Reg0x3 |= 0x8000
#define clrf_SYS_Reg0x3_wdt_pwd                                 addSYS_Reg0x3 &= ~0x8000
#define get_SYS_Reg0x3_wdt_pwd                                  ((addSYS_Reg0x3 & 0x8000) >> 15)

#define posSYS_Reg0x3_bk24_pwd                                  16
#define bitSYS_Reg0x3_bk24_pwd                                  0x10000
#define set_SYS_Reg0x3_bk24_pwd(val)                            addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x10000)) | ((val) << 16))
#define setf_SYS_Reg0x3_bk24_pwd                                addSYS_Reg0x3 |= 0x10000
#define clrf_SYS_Reg0x3_bk24_pwd                                addSYS_Reg0x3 &= ~0x10000
#define get_SYS_Reg0x3_bk24_pwd                                 ((addSYS_Reg0x3 & 0x10000) >> 16)

#define posSYS_Reg0x3_rwbt_pwd                                  17
#define bitSYS_Reg0x3_rwbt_pwd                                  0x20000
#define set_SYS_Reg0x3_rwbt_pwd(val)                            addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x20000)) | ((val) << 17))
#define setf_SYS_Reg0x3_rwbt_pwd                                addSYS_Reg0x3 |= 0x20000
#define clrf_SYS_Reg0x3_rwbt_pwd                                addSYS_Reg0x3 &= ~0x20000
#define get_SYS_Reg0x3_rwbt_pwd                                 ((addSYS_Reg0x3 & 0x20000) >> 17)

#define posSYS_Reg0x3_dma_pwd                                   18
#define bitSYS_Reg0x3_dma_pwd                                   0x40000
#define set_SYS_Reg0x3_dma_pwd(val)                             addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x40000)) | ((val) << 18))
#define setf_SYS_Reg0x3_dma_pwd                                 addSYS_Reg0x3 |= 0x40000
#define clrf_SYS_Reg0x3_dma_pwd                                 addSYS_Reg0x3 &= ~0x40000
#define get_SYS_Reg0x3_dma_pwd                                  ((addSYS_Reg0x3 & 0x40000) >> 18)

#define posSYS_Reg0x3_i2s_pwd                                   19
#define bitSYS_Reg0x3_i2s_pwd                                   0x80000
#define set_SYS_Reg0x3_i2s_pwd(val)                             addSYS_Reg0x3 = ((addSYS_Reg0x3 & (~0x80000)) | ((val) << 19))
#define setf_SYS_Reg0x3_i2s_pwd                                 addSYS_Reg0x3 |= 0x80000
#define clrf_SYS_Reg0x3_i2s_pwd                                 addSYS_Reg0x3 &= ~0x80000
#define get_SYS_Reg0x3_i2s_pwd                                  ((addSYS_Reg0x3 & 0x80000) >> 19)













//addSYS_Reg0x4
#define addSYS_Reg0x4                                           *((volatile unsigned long *) (0x00800000+0x4*4))
#define posSYS_Reg0x4_wdtclksel                                 0
#define bitSYS_Reg0x4_wdtclksel                                 0x3
#define set_SYS_Reg0x4_wdtclksel(val)                           addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x3)) | ((val) << 0))
#define get_SYS_Reg0x4_wdtclksel                                (addSYS_Reg0x4 & 0x3)

#define posSYS_Reg0x4_tim0_sel                                  2
#define bitSYS_Reg0x4_tim0_sel                                  0x4
#define set_SYS_Reg0x4_tim0_sel(val)                            addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x4)) | ((val) << 2))
#define setf_SYS_Reg0x4_tim0_sel                                addSYS_Reg0x4 |= 0x4
#define clrf_SYS_Reg0x4_tim0_sel                                addSYS_Reg0x4 &= ~0x4
#define get_SYS_Reg0x4_tim0_sel                                 ((addSYS_Reg0x4 & 0x4) >> 2)

#define posSYS_Reg0x4_tim1_sel                                  3
#define bitSYS_Reg0x4_tim1_sel                                  0x8
#define set_SYS_Reg0x4_tim1_sel(val)                            addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x8)) | ((val) << 3))
#define setf_SYS_Reg0x4_tim1_sel                                addSYS_Reg0x4 |= 0x8
#define clrf_SYS_Reg0x4_tim1_sel                                addSYS_Reg0x4 &= ~0x8
#define get_SYS_Reg0x4_tim1_sel                                 ((addSYS_Reg0x4 & 0x8) >> 3)

#define posSYS_Reg0x4_pwm0_sel                                  4
#define bitSYS_Reg0x4_pwm0_sel                                  0x30
#define set_SYS_Reg0x4_pwm0_sel(val)                            addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x30)) | ((val) << 4))
#define get_SYS_Reg0x4_pwm0_sel                                 ((addSYS_Reg0x4 & 0x30) >> 4)

#define posSYS_Reg0x4_pwm1_sel                                  6
#define bitSYS_Reg0x4_pwm1_sel                                  0xC0
#define set_SYS_Reg0x4_pwm1_sel(val)                            addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0xC0)) | ((val) << 6))
#define get_SYS_Reg0x4_pwm1_sel                                 ((addSYS_Reg0x4 & 0xC0) >> 6)

#define posSYS_Reg0x4_rtc_sel                                   8
#define bitSYS_Reg0x4_rtc_sel                                   0x100
#define set_SYS_Reg0x4_rtc_sel(val)                             addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x100)) | ((val) << 8))
#define setf_SYS_Reg0x4_rtc_sel                                 addSYS_Reg0x4 |= 0x100
#define clrf_SYS_Reg0x4_rtc_sel                                 addSYS_Reg0x4 &= ~0x100
#define get_SYS_Reg0x4_rtc_sel                                  ((addSYS_Reg0x4 & 0x100) >> 8)


#define posSYS_Reg0x4_sadc_sel                                  10
#define bitSYS_Reg0x4_sadc_sel                                  0x400
#define set_SYS_Reg0x4_sadc_sel(val)                            addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x400)) | ((val) << 10))
#define setf_SYS_Reg0x4_sadc_sel                                addSYS_Reg0x4 |= 0x400
#define clrf_SYS_Reg0x4_sadc_sel                                addSYS_Reg0x4 &= ~0x400
#define get_SYS_Reg0x4_sadc_sel                                 ((addSYS_Reg0x4 & 0x400) >> 10)

#define posSYS_Reg0x4_spi_sel                                   11
#define bitSYS_Reg0x4_spi_sel                                   0x800
#define set_SYS_Reg0x4_spi_sel(val)                             addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x800)) | ((val) << 11))
#define setf_SYS_Reg0x4_spi_sel                                 addSYS_Reg0x4 |= 0x800
#define clrf_SYS_Reg0x4_spi_sel                                 addSYS_Reg0x4 &= ~0x800
#define get_SYS_Reg0x4_spi_sel                                  ((addSYS_Reg0x4 & 0x800) >> 11)


#define posSYS_Reg0x4_i2smclk_en                                13
#define bitSYS_Reg0x4_i2smclk_en                                0x2000
#define set_SYS_Reg0x4_i2smclk_en(val)                          addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x2000)) | ((val) << 13))
#define setf_SYS_Reg0x4_i2smclk_en                              addSYS_Reg0x4 |= 0x2000
#define clrf_SYS_Reg0x4_i2smclk_en                              addSYS_Reg0x4 &= ~0x2000
#define get_SYS_Reg0x4_i2smclk_en                               ((addSYS_Reg0x4 & 0x2000) >> 13)

#define posSYS_Reg0x4_i2smclk_div                               14
#define bitSYS_Reg0x4_i2smclk_div                               0x7C000
#define set_SYS_Reg0x4_i2smclk_div(val)                         addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x7C000)) | ((val) << 14))
#define get_SYS_Reg0x4_i2smclk_div                              ((addSYS_Reg0x4 & 0x7C000) >> 14)

#define posSYS_Reg0x4_pll_out_en                                19
#define bitSYS_Reg0x4_pll_out_en                                0x80000
#define set_SYS_Reg0x4_pll_out_en(val)                          addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x80000)) | ((val) << 19))
#define setf_SYS_Reg0x4_pll_out_en                              addSYS_Reg0x4 |= 0x80000
#define clrf_SYS_Reg0x4_pll_out_en                              addSYS_Reg0x4 &= ~0x80000
#define get_SYS_Reg0x4_pll_out_en                               ((addSYS_Reg0x4 & 0x80000) >> 19)

#define posSYS_Reg0x4_pll_out_sel                               20
#define bitSYS_Reg0x4_pll_out_sel                               0x100000
#define set_SYS_Reg0x4_pll_out_sel(val)                         addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x100000)) | ((val) << 20))
#define setf_SYS_Reg0x4_pll_out_sel                             addSYS_Reg0x4 |= 0x100000
#define clrf_SYS_Reg0x4_pll_out_sel                             addSYS_Reg0x4 &= ~0x100000
#define get_SYS_Reg0x4_pll_out_sel                              ((addSYS_Reg0x4 & 0x100000) >> 20)

#define posSYS_Reg0x4_pll_out_div                               21
#define bitSYS_Reg0x4_pll_out_div                               0xE00000
#define set_SYS_Reg0x4_pll_out_div(val)                         addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0xE00000)) | ((val) << 21))
#define get_SYS_Reg0x4_pll_out_div                              ((addSYS_Reg0x4 & 0xE00000) >> 21)

#define posSYS_Reg0x4_xtal_out_en                               24
#define bitSYS_Reg0x4_xtal_out_en                               0x1000000
#define set_SYS_Reg0x4_xtal_out_en(val)                         addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x1000000)) | ((val) << 24))
#define setf_SYS_Reg0x4_xtal_out_en                             addSYS_Reg0x4 |= 0x1000000
#define clrf_SYS_Reg0x4_xtal_out_en                             addSYS_Reg0x4 &= ~0x1000000
#define get_SYS_Reg0x4_xtal_out_en                              ((addSYS_Reg0x4 & 0x1000000) >> 24)

#define posSYS_Reg0x4_xtal_out_sel                              25
#define bitSYS_Reg0x4_xtal_out_sel                              0x2000000
#define set_SYS_Reg0x4_xtal_out_sel(val)                        addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x2000000)) | ((val) << 25))
#define setf_SYS_Reg0x4_xtal_out_sel                            addSYS_Reg0x4 |= 0x2000000
#define clrf_SYS_Reg0x4_xtal_out_sel                            addSYS_Reg0x4 &= ~0x2000000
#define get_SYS_Reg0x4_xtal_out_sel                             ((addSYS_Reg0x4 & 0x2000000) >> 25)

#define posSYS_Reg0x4_xtal_out_div                              26
#define bitSYS_Reg0x4_xtal_out_div                              0x1C000000
#define set_SYS_Reg0x4_xtal_out_div(val)                        addSYS_Reg0x4 = ((addSYS_Reg0x4 & (~0x1C000000)) | ((val) << 26))
#define get_SYS_Reg0x4_xtal_out_div                             ((addSYS_Reg0x4 & 0x1C000000) >> 26)


//addSYS_Reg0x5
#define addSYS_Reg0x5                                           *((volatile unsigned long *) (0x00800000+0x5*4))

#define posSYS_Reg0x5_rw_ant_ctrl                               0
#define bitSYS_Reg0x5_rw_ant_ctrl                               0xFFFF
#define set_SYS_Reg0x5_rw_ant_ctrl(val)                         addSYS_Reg0x5 = ((addSYS_Reg0x5 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x5_rw_ant_ctrl                              (addSYS_Reg0x5 & 0xFFFF)

//addSYS_Reg0x6
#define addSYS_Reg0x6                                           *((volatile unsigned long *) (0x00800000+0x6*4))

#define posSYS_Reg0x6_sw_dbg_gpio                               0
#define bitSYS_Reg0x6_sw_dbg_gpio                               0xFF
#define set_SYS_Reg0x6_sw_dbg_gpio(val)                         addSYS_Reg0x6 = ((addSYS_Reg0x6 & (~0xFF)) | ((val) << 0))
#define get_SYS_Reg0x6_sw_dbg_gpio                              (addSYS_Reg0x6 & 0xFF)

//addSYS_Reg0x7
#define addSYS_Reg0x7                                           *((volatile unsigned long *) (0x00800000+0x7*4))

//addSYS_Reg0x8
#define addSYS_Reg0x8                                           *((volatile unsigned long *) (0x00800000+0x8*4))

//addSYS_Reg0x9
#define addSYS_Reg0x9                                           *((volatile unsigned long *) (0x00800000+0x9*4))

//addSYS_Reg0xa
#define addSYS_Reg0xa                                           *((volatile unsigned long *) (0x00800000+0xa*4))

//addSYS_Reg0xb
#define addSYS_Reg0xb                                           *((volatile unsigned long *) (0x00800000+0xb*4))

#define posSYS_Reg0xb_pwd_on_boostsel                           4
#define bitSYS_Reg0xb_pwd_on_boostsel                           0x10
#define set_SYS_Reg0xb_pwd_on_boostsel(val)                     addSYS_Reg0xb = ((addSYS_Reg0xb & (~0x10)) | ((val) << 4))
#define setf_SYS_Reg0xb_pwd_on_boostsel                         addSYS_Reg0xb |= 0x10
#define clrf_SYS_Reg0xb_pwd_on_boostsel                         addSYS_Reg0xb &= ~0x10
#define get_SYS_Reg0xb_pwd_on_boostsel                          ((addSYS_Reg0xb & 0x10) >> 4)


#define posSYS_Reg0xb_pwd_on_boost                              2
#define bitSYS_Reg0xb_pwd_on_boost                              0x4
#define set_SYS_Reg0xb_pwd_on_boost(val)                        addSYS_Reg0xb = ((addSYS_Reg0xb & (~0x4)) | ((val) << 2))
#define setf_SYS_Reg0xb_pwd_on_boost                            addSYS_Reg0xb |= 0x4
#define clrf_SYS_Reg0xb_pwd_on_boost                            addSYS_Reg0xb &= ~0x4
#define get_SYS_Reg0xb_pwd_on_boost                             ((addSYS_Reg0xb & 0x4) >> 2)

#define posSYS_Reg0xb_pwd_boost                                 1
#define bitSYS_Reg0xb_pwd_boost                                 0x2
#define set_SYS_Reg0xb_pwd_boost(val)                           addSYS_Reg0xb = ((addSYS_Reg0xb & (~0x2)) | ((val) << 1))
#define setf_SYS_Reg0xb_pwd_boost                               addSYS_Reg0xb |= 0x2
#define clrf_SYS_Reg0xb_pwd_boost                               addSYS_Reg0xb &= ~0x2
#define get_SYS_Reg0xb_pwd_boost                                ((addSYS_Reg0xb & 0x2) >> 1)

#define posSYS_Reg0xb_cache_load_mode                           0
#define bitSYS_Reg0xb_cache_load_mode                           0x1
#define set_SYS_Reg0xb_cache_load_mode(val)                     addSYS_Reg0xb = ((addSYS_Reg0xb & (~0x1)) | ((val) << 0))
#define setf_SYS_Reg0xb_cache_load_mode                         addSYS_Reg0xb |= 0x1
#define clrf_SYS_Reg0xb_cache_load_mode                         addSYS_Reg0xb &= ~0x1
#define get_SYS_Reg0xb_cache_load_mode                          (addSYS_Reg0xb & 0x1)

//addSYS_Reg0xc
#define addSYS_Reg0xc                                           *((volatile unsigned long *) (0x00800000+0xc*4))

#define posSYS_Reg0xc_reserved1                                 23
#define bitSYS_Reg0xc_reserved1                                 0x800000
#define set_SYS_Reg0xc_reserved1(val)                           addSYS_Reg0xc = ((addSYS_Reg0xc & (~0x800000)) | ((val) << 23))
#define setf_SYS_Reg0xc_reserved1                               addSYS_Reg0xc |= 0x800000
#define clrf_SYS_Reg0xc_reserved1                               addSYS_Reg0xc &= ~0x800000
#define get_SYS_Reg0xc_reserved1                                ((addSYS_Reg0xc & 0x800000) >> 23)

#define posSYS_Reg0xc_pwm_ctrl2                                 22
#define bitSYS_Reg0xc_pwm_ctrl2                                 0x400000
#define set_SYS_Reg0xc_pwm_ctrl2(val)                           addSYS_Reg0xc = ((addSYS_Reg0xc & (~0x400000)) | ((val) << 22))
#define setf_SYS_Reg0xc_pwm_ctrl2                               addSYS_Reg0xc |= 0x400000
#define clrf_SYS_Reg0xc_pwm_ctrl2                               addSYS_Reg0xc &= ~0x400000
#define get_SYS_Reg0xc_pwm_ctrl2                                ((addSYS_Reg0xc & 0x400000) >> 22)

#define posSYS_Reg0xc_pwm_ctrl1                                 21
#define bitSYS_Reg0xc_pwm_ctrl1                                 0x200000
#define set_SYS_Reg0xc_pwm_ctrl1(val)                           addSYS_Reg0xc = ((addSYS_Reg0xc & (~0x200000)) | ((val) << 21))
#define setf_SYS_Reg0xc_pwm_ctrl1                               addSYS_Reg0xc |= 0x200000
#define clrf_SYS_Reg0xc_pwm_ctrl1                               addSYS_Reg0xc &= ~0x200000
#define get_SYS_Reg0xc_pwm_ctrl1                                ((addSYS_Reg0xc & 0x200000) >> 21)

#define posSYS_Reg0xc_pwm_ctrl0                                 20
#define bitSYS_Reg0xc_pwm_ctrl0                                 0x100000
#define set_SYS_Reg0xc_pwm_ctrl0(val)                           addSYS_Reg0xc = ((addSYS_Reg0xc & (~0x100000)) | ((val) << 20))
#define setf_SYS_Reg0xc_pwm_ctrl0                               addSYS_Reg0xc |= 0x100000
#define clrf_SYS_Reg0xc_pwm_ctrl0                               addSYS_Reg0xc &= ~0x100000
#define get_SYS_Reg0xc_pwm_ctrl0                                ((addSYS_Reg0xc & 0x100000) >> 20)

#define posSYS_Reg0xc_reserved5                                 18
#define bitSYS_Reg0xc_reserved5                                 0xC0000
#define set_SYS_Reg0xc_reserved5(val)                           addSYS_Reg0xc = ((addSYS_Reg0xc & (~0xC0000)) | ((val) << 18))
#define get_SYS_Reg0xc_reserved5                                ((addSYS_Reg0xc & 0xC0000) >> 18)

#define posSYS_Reg0xc_debug_set                                 0
#define bitSYS_Reg0xc_debug_set                                 0x3FFFF
#define set_SYS_Reg0xc_debug_set(val)                           addSYS_Reg0xc = ((addSYS_Reg0xc & (~0x3FFFF)) | ((val) << 0))
#define get_SYS_Reg0xc_debug_set                                (addSYS_Reg0xc & 0x3FFFF)

//addSYS_Reg0xd
#define addSYS_Reg0xd                                           *((volatile unsigned long *) (0x00800000+0xd*4))

#define posSYS_Reg0xd_OSC_en_sel                                7
#define bitSYS_Reg0xd_OSC_en_sel                                0x80
#define set_SYS_Reg0xd_OSC_en_sel(val)                          addSYS_Reg0xd = ((addSYS_Reg0xd & (~0x80)) | ((val) << 7))
#define setf_SYS_Reg0xd_OSC_en_sel                              addSYS_Reg0xd |= 0x80
#define clrf_SYS_Reg0xd_OSC_en_sel                              addSYS_Reg0xd &= ~0x80
#define get_SYS_Reg0xd_OSC_en_sel                               ((addSYS_Reg0xd & 0x80) >> 7)

#define posSYS_Reg0xd_PLL_PWR_sel                               6
#define bitSYS_Reg0xd_PLL_PWR_sel                               0x40
#define set_SYS_Reg0xd_PLL_PWR_sel(val)                         addSYS_Reg0xd = ((addSYS_Reg0xd & (~0x40)) | ((val) << 6))
#define setf_SYS_Reg0xd_PLL_PWR_sel                             addSYS_Reg0xd |= 0x40
#define clrf_SYS_Reg0xd_PLL_PWR_sel                             addSYS_Reg0xd &= ~0x40
#define get_SYS_Reg0xd_PLL_PWR_sel                              ((addSYS_Reg0xd & 0x40) >> 6)



//addSYS_Reg0xe
#define addSYS_Reg0xe                                           *((volatile unsigned long *) (0x00800000+0xe*4))

//addXVR_Reg0xe
#define addXVR_Reg0xe                                           *((volatile unsigned long *) (0x00806E00+0xe*4))
#define posXVR_Reg0xe_trig_digpll_dco                            24
#define bitXVR_Reg0xe_trig_digpll_dco                            0x1000000
#define set_XVR_Reg0xe_trig_digpll_dco(val)                      addXVR_Reg0xe = ((addXVR_Reg0xe & (~0x1000000)) | ((val) << 24))
#define setf_XVR_Reg0xe_trig_digpll_dco                          addXVR_Reg0xe |= 0x1000000
#define clrf_XVR_Reg0xe_trig_digpll_dco                          addXVR_Reg0xe &= ~0x1000000
#define get_XVR_Reg0xe_trig_digpll_dco                           ((addXVR_Reg0xe & 0x1000000) >> 24)

#define posSYS_Reg0xe_flashilde                                 2
#define bitSYS_Reg0xe_flashilde                                 0x4
#define set_SYS_Reg0xe_flashilde(val)                           addSYS_Reg0xe = ((addSYS_Reg0xe & (~0x4)) | ((val) << 2))
#define setf_SYS_Reg0xe_flashilde                               addSYS_Reg0xe |= 0x4
#define clrf_SYS_Reg0xe_flashilde                               addSYS_Reg0xe &= ~0x4
#define get_SYS_Reg0xe_flashilde                                ((addSYS_Reg0xe & 0x4) >> 2)


#define posSYS_Reg0xe_resettrx                                  0
#define bitSYS_Reg0xe_resettrx                                  0x1
#define set_SYS_Reg0xe_resettrx(val)                            addSYS_Reg0xe = ((addSYS_Reg0xe & (~0x1)) | ((val) << 0))
#define setf_SYS_Reg0xe_resettrx                                addSYS_Reg0xe |= 0x1
#define clrf_SYS_Reg0xe_resettrx                                addSYS_Reg0xe &= ~0x1
#define get_SYS_Reg0xe_resettrx                                 (addSYS_Reg0xe & 0x1)

//addSYS_Reg0xf
#define addSYS_Reg0xf                                           *((volatile unsigned long *) (0x00800000+0xf*4))
#define posSYS_Reg0xf_ccalivalue                                24
#define bitSYS_Reg0xf_ccalivalue                                0xFF000000
#define get_SYS_Reg0xf_ccalivalue                               ((addSYS_Reg0xf & 0xFF000000) >> 24)

#define posSYS_Reg0xf_fcalivalue                                12
#define bitSYS_Reg0xf_fcalivalue                                0xFFF000
#define get_SYS_Reg0xf_fcalivalue                               ((addSYS_Reg0xf & 0xFFF000) >> 12)

#define posSYS_Reg0xf_usb_plug_flag                             11
#define bitSYS_Reg0xf_usb_plug_flag                             0x800
#define get_SYS_Reg0xf_usb_plug_flag                            ((addSYS_Reg0xf & 0x800) >> 11)

#define posSYS_Reg0xf_pll2_unlock                               10
#define bitSYS_Reg0xf_pll2_unlock                               0x400
#define get_SYS_Reg0xf_pll2_unlock                              ((addSYS_Reg0xf & 0x400) >> 10)






#define posSYS_Reg0xf_spi_fla_sel                               1
#define bitSYS_Reg0xf_spi_fla_sel                               0x2
#define set_SYS_Reg0xf_spi_fla_sel(val)                         addSYS_Reg0xf = ((addSYS_Reg0xf & (~0x2)) | ((val) << 1))
#define setf_SYS_Reg0xf_spi_fla_sel                             addSYS_Reg0xf |= 0x2
#define clrf_SYS_Reg0xf_spi_fla_sel                             addSYS_Reg0xf &= ~0x2
#define get_SYS_Reg0xf_spi_fla_sel                              ((addSYS_Reg0xf & 0x2) >> 1)

#define posSYS_Reg0xf_boot_rom_enable                           0
#define bitSYS_Reg0xf_boot_rom_enable                           0x1
#define set_SYS_Reg0xf_boot_rom_enable(val)                     addSYS_Reg0xf = ((addSYS_Reg0xf & (~0x1)) | ((val) << 0))
#define setf_SYS_Reg0xf_boot_rom_enable                         addSYS_Reg0xf |= 0x1
#define clrf_SYS_Reg0xf_boot_rom_enable                         addSYS_Reg0xf &= ~0x1
#define get_SYS_Reg0xf_boot_rom_enable                          (addSYS_Reg0xf & 0x1)

//addSYS_Reg0x10
#define addSYS_Reg0x10                                          *((volatile unsigned long *) (0x00800000+0x10*4))
#define posSYS_Reg0x10_int_pwm0_en                              0
#define bitSYS_Reg0x10_int_pwm0_en                              0x1
#define set_SYS_Reg0x10_int_pwm0_en(val)                        addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x1)) | ((val) << 0))
#define setf_SYS_Reg0x10_int_pwm0_en                            addSYS_Reg0x10 |= 0x1
#define clrf_SYS_Reg0x10_int_pwm0_en                            addSYS_Reg0x10 &= ~0x1
#define get_SYS_Reg0x10_int_pwm0_en                             (addSYS_Reg0x10 & 0x1)

#define posSYS_Reg0x10_int_pwm1_en                              1
#define bitSYS_Reg0x10_int_pwm1_en                              0x2
#define set_SYS_Reg0x10_int_pwm1_en(val)                        addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x2)) | ((val) << 1))
#define setf_SYS_Reg0x10_int_pwm1_en                            addSYS_Reg0x10 |= 0x2
#define clrf_SYS_Reg0x10_int_pwm1_en                            addSYS_Reg0x10 &= ~0x2
#define get_SYS_Reg0x10_int_pwm1_en                             ((addSYS_Reg0x10 & 0x2) >> 1)

#define posSYS_Reg0x10_int_timer0_en                            2
#define bitSYS_Reg0x10_int_timer0_en                            0x4
#define set_SYS_Reg0x10_int_timer0_en(val)                      addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x4)) | ((val) << 2))
#define setf_SYS_Reg0x10_int_timer0_en                          addSYS_Reg0x10 |= 0x4
#define clrf_SYS_Reg0x10_int_timer0_en                          addSYS_Reg0x10 &= ~0x4
#define get_SYS_Reg0x10_int_timer0_en                           ((addSYS_Reg0x10 & 0x4) >> 2)

#define posSYS_Reg0x10_int_timer1_en                            3
#define bitSYS_Reg0x10_int_timer1_en                            0x8
#define set_SYS_Reg0x10_int_timer1_en(val)                      addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x8)) | ((val) << 3))
#define setf_SYS_Reg0x10_int_timer1_en                          addSYS_Reg0x10 |= 0x8
#define clrf_SYS_Reg0x10_int_timer1_en                          addSYS_Reg0x10 &= ~0x8
#define get_SYS_Reg0x10_int_timer1_en                           ((addSYS_Reg0x10 & 0x8) >> 3)

#define posSYS_Reg0x10_int_uart0_en                             4
#define bitSYS_Reg0x10_int_uart0_en                             0x10
#define set_SYS_Reg0x10_int_uart0_en(val)                       addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x10)) | ((val) << 4))
#define setf_SYS_Reg0x10_int_uart0_en                           addSYS_Reg0x10 |= 0x10
#define clrf_SYS_Reg0x10_int_uart0_en                           addSYS_Reg0x10 &= ~0x10
#define get_SYS_Reg0x10_int_uart0_en                            ((addSYS_Reg0x10 & 0x10) >> 4)

#define posSYS_Reg0x10_int_uart1_en                             5
#define bitSYS_Reg0x10_int_uart1_en                             0x20
#define set_SYS_Reg0x10_int_uart1_en(val)                       addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x20)) | ((val) << 5))
#define setf_SYS_Reg0x10_int_uart1_en                           addSYS_Reg0x10 |= 0x20
#define clrf_SYS_Reg0x10_int_uart1_en                           addSYS_Reg0x10 &= ~0x20
#define get_SYS_Reg0x10_int_uart1_en                            ((addSYS_Reg0x10 & 0x20) >> 5)

#define posSYS_Reg0x10_int_spi0_en                              6
#define bitSYS_Reg0x10_int_spi0_en                              0x40
#define set_SYS_Reg0x10_int_spi0_en(val)                        addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x40)) | ((val) << 6))
#define setf_SYS_Reg0x10_int_spi0_en                            addSYS_Reg0x10 |= 0x40
#define clrf_SYS_Reg0x10_int_spi0_en                            addSYS_Reg0x10 &= ~0x40
#define get_SYS_Reg0x10_int_spi0_en                             ((addSYS_Reg0x10 & 0x40) >> 6)

#define posSYS_Reg0x10_int_i2c0_en                              7
#define bitSYS_Reg0x10_int_i2c0_en                              0x80
#define set_SYS_Reg0x10_int_i2c0_en(val)                        addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x80)) | ((val) << 7))
#define setf_SYS_Reg0x10_int_i2c0_en                            addSYS_Reg0x10 |= 0x80
#define clrf_SYS_Reg0x10_int_i2c0_en                            addSYS_Reg0x10 &= ~0x80
#define get_SYS_Reg0x10_int_i2c0_en                             ((addSYS_Reg0x10 & 0x80) >> 7)

#define posSYS_Reg0x10_int_adc_en                               8
#define bitSYS_Reg0x10_int_adc_en                               0x100
#define set_SYS_Reg0x10_int_adc_en(val)                         addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x100)) | ((val) << 8))
#define setf_SYS_Reg0x10_int_adc_en                             addSYS_Reg0x10 |= 0x100
#define clrf_SYS_Reg0x10_int_adc_en                             addSYS_Reg0x10 &= ~0x100
#define get_SYS_Reg0x10_int_adc_en                              ((addSYS_Reg0x10 & 0x100) >> 8)

#define posSYS_Reg0x10_int_aon_gpio_en                          9
#define bitSYS_Reg0x10_int_aon_gpio_en                          0x200
#define set_SYS_Reg0x10_int_aon_gpio_en(val)                    addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x200)) | ((val) << 9))
#define setf_SYS_Reg0x10_int_aon_gpio_en                        addSYS_Reg0x10 |= 0x200
#define clrf_SYS_Reg0x10_int_aon_gpio_en                        addSYS_Reg0x10 &= ~0x200
#define get_SYS_Reg0x10_int_aon_gpio_en                         ((addSYS_Reg0x10 & 0x200) >> 9)

#define posSYS_Reg0x10_int_rtc_en                               10
#define bitSYS_Reg0x10_int_rtc_en                               0x400
#define set_SYS_Reg0x10_int_rtc_en(val)                         addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x400)) | ((val) << 10))
#define setf_SYS_Reg0x10_int_rtc_en                             addSYS_Reg0x10 |= 0x400
#define clrf_SYS_Reg0x10_int_rtc_en                             addSYS_Reg0x10 &= ~0x400
#define get_SYS_Reg0x10_int_rtc_en                              ((addSYS_Reg0x10 & 0x400) >> 10)

#define posSYS_Reg0x10_int_i2s_en                               11
#define bitSYS_Reg0x10_int_i2s_en                               0x800
#define set_SYS_Reg0x10_int_i2s_en(val)                         addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x800)) | ((val) << 11))
#define setf_SYS_Reg0x10_int_i2s_en                             addSYS_Reg0x10 |= 0x800
#define clrf_SYS_Reg0x10_int_i2s_en                             addSYS_Reg0x10 &= ~0x800
#define get_SYS_Reg0x10_int_i2s_en                              ((addSYS_Reg0x10 & 0x800) >> 11)

#define posSYS_Reg0x10_int_aon_rtc_en                           12
#define bitSYS_Reg0x10_int_aon_rtc_en                           0x1000
#define set_SYS_Reg0x10_int_aon_rtc_en(val)                     addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x1000)) | ((val) << 12))
#define setf_SYS_Reg0x10_int_aon_rtc_en                         addSYS_Reg0x10 |= 0x1000
#define clrf_SYS_Reg0x10_int_aon_rtc_en                         addSYS_Reg0x10 &= ~0x1000
#define get_SYS_Reg0x10_int_aon_rtc_en                          ((addSYS_Reg0x10 & 0x1000) >> 12)


#define posSYS_Reg0x10_int_irda_en                              13
#define bitSYS_Reg0x10_int_irda_en                              0x2000
#define set_SYS_Reg0x10_int_irda_en(val)                        addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x2000)) | ((val) << 13))
#define setf_SYS_Reg0x10_int_irda_en                            addSYS_Reg0x10 |= 0x2000
#define clrf_SYS_Reg0x10_int_irda_en                            addSYS_Reg0x10 &= ~0x2000
#define get_SYS_Reg0x10_int_irda_en                             ((addSYS_Reg0x10 & 0x2000) >> 13)



#define posSYS_Reg0x10_int_usb_en                               17
#define bitSYS_Reg0x10_int_usb_en                               0x20000
#define set_SYS_Reg0x10_int_usb_en(val)                         addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x20000)) | ((val) << 17))
#define setf_SYS_Reg0x10_int_usb_en                             addSYS_Reg0x10 |= 0x20000
#define clrf_SYS_Reg0x10_int_usb_en                             addSYS_Reg0x10 &= ~0x20000
#define get_SYS_Reg0x10_int_usb_en                              ((addSYS_Reg0x10 & 0x20000) >> 17)

#define posSYS_Reg0x10_int_dma_en                               18
#define bitSYS_Reg0x10_int_dma_en                               0x40000
#define set_SYS_Reg0x10_int_dma_en(val)                         addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x40000)) | ((val) << 18))
#define setf_SYS_Reg0x10_int_dma_en                             addSYS_Reg0x10 |= 0x40000
#define clrf_SYS_Reg0x10_int_dma_en                             addSYS_Reg0x10 &= ~0x40000
#define get_SYS_Reg0x10_int_dma_en                              ((addSYS_Reg0x10 & 0x40000) >> 18)

#define posSYS_Reg0x10_int_bk24_en                              19
#define bitSYS_Reg0x10_int_bk24_en                              0x80000
#define set_SYS_Reg0x10_int_bk24_en(val)                        addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x80000)) | ((val) << 19))
#define setf_SYS_Reg0x10_int_bk24_en                            addSYS_Reg0x10 |= 0x80000
#define clrf_SYS_Reg0x10_int_bk24_en                            addSYS_Reg0x10 &= ~0x80000
#define get_SYS_Reg0x10_int_bk24_en                             ((addSYS_Reg0x10 & 0x80000) >> 19)

#define posSYS_Reg0x10_int_rwble_en                             20
#define bitSYS_Reg0x10_int_rwble_en                             0x100000
#define set_SYS_Reg0x10_int_rwble_en(val)                       addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x100000)) | ((val) << 20))
#define setf_SYS_Reg0x10_int_rwble_en                           addSYS_Reg0x10 |= 0x100000
#define clrf_SYS_Reg0x10_int_rwble_en                           addSYS_Reg0x10 &= ~0x100000
#define get_SYS_Reg0x10_int_rwble_en                            ((addSYS_Reg0x10 & 0x100000) >> 20)

#define posSYS_Reg0x10_int_rwbt_en                              21
#define bitSYS_Reg0x10_int_rwbt_en                              0x200000
#define set_SYS_Reg0x10_int_rwbt_en(val)                        addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x200000)) | ((val) << 21))
#define setf_SYS_Reg0x10_int_rwbt_en                            addSYS_Reg0x10 |= 0x200000
#define clrf_SYS_Reg0x10_int_rwbt_en                            addSYS_Reg0x10 &= ~0x200000
#define get_SYS_Reg0x10_int_rwbt_en                             ((addSYS_Reg0x10 & 0x200000) >> 21)

#define posSYS_Reg0x10_int_rwdm_en                              22
#define bitSYS_Reg0x10_int_rwdm_en                              0x400000
#define set_SYS_Reg0x10_int_rwdm_en(val)                        addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x400000)) | ((val) << 22))
#define setf_SYS_Reg0x10_int_rwdm_en                            addSYS_Reg0x10 |= 0x400000
#define clrf_SYS_Reg0x10_int_rwdm_en                            addSYS_Reg0x10 &= ~0x400000
#define get_SYS_Reg0x10_int_rwdm_en                             ((addSYS_Reg0x10 & 0x400000) >> 22)

#define posSYS_Reg0x10_int_clk_est_en                           23
#define bitSYS_Reg0x10_int_clk_est_en                           0x800000
#define set_SYS_Reg0x10_int_clk_est_en(val)                     addSYS_Reg0x10 = ((addSYS_Reg0x10 & (~0x800000)) | ((val) << 23))
#define setf_SYS_Reg0x10_int_clk_est_en                         addSYS_Reg0x10 |= 0x800000
#define clrf_SYS_Reg0x10_int_clk_est_en                         addSYS_Reg0x10 &= ~0x800000
#define get_SYS_Reg0x10_int_clk_est_en                          ((addSYS_Reg0x10 & 0x800000) >> 23)


//addSYS_Reg0x11
#define addSYS_Reg0x11                                          *((volatile unsigned long *) (0x00800000+0x11*4))
#define posSYS_Reg0x11_int_pwm0_pri                             0
#define bitSYS_Reg0x11_int_pwm0_pri                             0x1
#define set_SYS_Reg0x11_int_pwm0_pri(val)                       addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x1)) | ((val) << 0))
#define setf_SYS_Reg0x11_int_pwm0_pri                           addSYS_Reg0x11 |= 0x1
#define clrf_SYS_Reg0x11_int_pwm0_pri                           addSYS_Reg0x11 &= ~0x1
#define get_SYS_Reg0x11_int_pwm0_pri                            (addSYS_Reg0x11 & 0x1)

#define posSYS_Reg0x11_int_pwm1_pri                             1
#define bitSYS_Reg0x11_int_pwm1_pri                             0x2
#define set_SYS_Reg0x11_int_pwm1_pri(val)                       addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x2)) | ((val) << 1))
#define setf_SYS_Reg0x11_int_pwm1_pri                           addSYS_Reg0x11 |= 0x2
#define clrf_SYS_Reg0x11_int_pwm1_pri                           addSYS_Reg0x11 &= ~0x2
#define get_SYS_Reg0x11_int_pwm1_pri                            ((addSYS_Reg0x11 & 0x2) >> 1)

#define posSYS_Reg0x11_int_timer0_pri                           2
#define bitSYS_Reg0x11_int_timer0_pri                           0x4
#define set_SYS_Reg0x11_int_timer0_pri(val)                     addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x4)) | ((val) << 2))
#define setf_SYS_Reg0x11_int_timer0_pri                         addSYS_Reg0x11 |= 0x4
#define clrf_SYS_Reg0x11_int_timer0_pri                         addSYS_Reg0x11 &= ~0x4
#define get_SYS_Reg0x11_int_timer0_pri                          ((addSYS_Reg0x11 & 0x4) >> 2)

#define posSYS_Reg0x11_int_timer1_pri                           3
#define bitSYS_Reg0x11_int_timer1_pri                           0x8
#define set_SYS_Reg0x11_int_timer1_pri(val)                     addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x8)) | ((val) << 3))
#define setf_SYS_Reg0x11_int_timer1_pri                         addSYS_Reg0x11 |= 0x8
#define clrf_SYS_Reg0x11_int_timer1_pri                         addSYS_Reg0x11 &= ~0x8
#define get_SYS_Reg0x11_int_timer1_pri                          ((addSYS_Reg0x11 & 0x8) >> 3)

#define posSYS_Reg0x11_int_uart0_pri                            4
#define bitSYS_Reg0x11_int_uart0_pri                            0x10
#define set_SYS_Reg0x11_int_uart0_pri(val)                      addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x10)) | ((val) << 4))
#define setf_SYS_Reg0x11_int_uart0_pri                          addSYS_Reg0x11 |= 0x10
#define clrf_SYS_Reg0x11_int_uart0_pri                          addSYS_Reg0x11 &= ~0x10
#define get_SYS_Reg0x11_int_uart0_pri                           ((addSYS_Reg0x11 & 0x10) >> 4)

#define posSYS_Reg0x11_int_uart1_pri                            5
#define bitSYS_Reg0x11_int_uart1_pri                            0x20
#define set_SYS_Reg0x11_int_uart1_pri(val)                      addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x20)) | ((val) << 5))
#define setf_SYS_Reg0x11_int_uart1_pri                          addSYS_Reg0x11 |= 0x20
#define clrf_SYS_Reg0x11_int_uart1_pri                          addSYS_Reg0x11 &= ~0x20
#define get_SYS_Reg0x11_int_uart1_pri                           ((addSYS_Reg0x11 & 0x20) >> 5)

#define posSYS_Reg0x11_int_spi0_pri                             6
#define bitSYS_Reg0x11_int_spi0_pri                             0x40
#define set_SYS_Reg0x11_int_spi0_pri(val)                       addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x40)) | ((val) << 6))
#define setf_SYS_Reg0x11_int_spi0_pri                           addSYS_Reg0x11 |= 0x40
#define clrf_SYS_Reg0x11_int_spi0_pri                           addSYS_Reg0x11 &= ~0x40
#define get_SYS_Reg0x11_int_spi0_pri                            ((addSYS_Reg0x11 & 0x40) >> 6)

#define posSYS_Reg0x11_int_i2c0_pri                             7
#define bitSYS_Reg0x11_int_i2c0_pri                             0x80
#define set_SYS_Reg0x11_int_i2c0_pri(val)                       addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x80)) | ((val) << 7))
#define setf_SYS_Reg0x11_int_i2c0_pri                           addSYS_Reg0x11 |= 0x80
#define clrf_SYS_Reg0x11_int_i2c0_pri                           addSYS_Reg0x11 &= ~0x80
#define get_SYS_Reg0x11_int_i2c0_pri                            ((addSYS_Reg0x11 & 0x80) >> 7)

#define posSYS_Reg0x11_int_adc_pri                              8
#define bitSYS_Reg0x11_int_adc_pri                              0x100
#define set_SYS_Reg0x11_int_adc_pri(val)                        addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x100)) | ((val) << 8))
#define setf_SYS_Reg0x11_int_adc_pri                            addSYS_Reg0x11 |= 0x100
#define clrf_SYS_Reg0x11_int_adc_pri                            addSYS_Reg0x11 &= ~0x100
#define get_SYS_Reg0x11_int_adc_pri                             ((addSYS_Reg0x11 & 0x100) >> 8)

#define posSYS_Reg0x11_int_aon_gpio_pri                         9
#define bitSYS_Reg0x11_int_aon_gpio_pri                         0x200
#define set_SYS_Reg0x11_int_aon_gpio_pri(val)                   addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x200)) | ((val) << 9))
#define setf_SYS_Reg0x11_int_aon_gpio_pri                       addSYS_Reg0x11 |= 0x200
#define clrf_SYS_Reg0x11_int_aon_gpio_pri                       addSYS_Reg0x11 &= ~0x200
#define get_SYS_Reg0x11_int_aon_gpio_pri                        ((addSYS_Reg0x11 & 0x200) >> 9)

#define posSYS_Reg0x11_int_rtc_pri                              10
#define bitSYS_Reg0x11_int_rtc_pri                              0x400
#define set_SYS_Reg0x11_int_rtc_pri(val)                        addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x400)) | ((val) << 10))
#define setf_SYS_Reg0x11_int_rtc_pri                            addSYS_Reg0x11 |= 0x400
#define clrf_SYS_Reg0x11_int_rtc_pri                            addSYS_Reg0x11 &= ~0x400
#define get_SYS_Reg0x11_int_rtc_pri                             ((addSYS_Reg0x11 & 0x400) >> 10)

#define posSYS_Reg0x11_int_i2s_pri                              11
#define bitSYS_Reg0x11_int_i2s_pri                              0x800
#define set_SYS_Reg0x11_int_i2s_pri(val)                        addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x800)) | ((val) << 11))
#define setf_SYS_Reg0x11_int_i2s_pri                            addSYS_Reg0x11 |= 0x800
#define clrf_SYS_Reg0x11_int_i2s_pri                            addSYS_Reg0x11 &= ~0x800
#define get_SYS_Reg0x11_int_i2s_pri                             ((addSYS_Reg0x11 & 0x800) >> 11)

#define posSYS_Reg0x11_int_aon_rtc_pri                          12
#define bitSYS_Reg0x11_int_aon_rtc_pri                          0x1000
#define set_SYS_Reg0x11_int_aon_rtc_pri(val)                    addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x1000)) | ((val) << 12))
#define setf_SYS_Reg0x11_int_aon_rtc_pri                        addSYS_Reg0x11 |= 0x1000
#define clrf_SYS_Reg0x11_int_aon_rtc_pri                        addSYS_Reg0x11 &= ~0x1000
#define get_SYS_Reg0x11_int_aon_rtc_pri                         ((addSYS_Reg0x11 & 0x1000) >> 12)





#define posSYS_Reg0x11_int_usb_pri                              17
#define bitSYS_Reg0x11_int_usb_pri                              0x20000
#define set_SYS_Reg0x11_int_usb_pri(val)                        addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x20000)) | ((val) << 17))
#define setf_SYS_Reg0x11_int_usb_pri                            addSYS_Reg0x11 |= 0x20000
#define clrf_SYS_Reg0x11_int_usb_pri                            addSYS_Reg0x11 &= ~0x20000
#define get_SYS_Reg0x11_int_usb_pri                             ((addSYS_Reg0x11 & 0x20000) >> 17)

#define posSYS_Reg0x11_int_dma_pri                              18
#define bitSYS_Reg0x11_int_dma_pri                              0x40000
#define set_SYS_Reg0x11_int_dma_pri(val)                        addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x40000)) | ((val) << 18))
#define setf_SYS_Reg0x11_int_dma_pri                            addSYS_Reg0x11 |= 0x40000
#define clrf_SYS_Reg0x11_int_dma_pri                            addSYS_Reg0x11 &= ~0x40000
#define get_SYS_Reg0x11_int_dma_pri                             ((addSYS_Reg0x11 & 0x40000) >> 18)


#define posSYS_Reg0x11_int_rwble_pri                            20
#define bitSYS_Reg0x11_int_rwble_pri                            0x100000
#define set_SYS_Reg0x11_int_rwble_pri(val)                      addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x100000)) | ((val) << 20))
#define setf_SYS_Reg0x11_int_rwble_pri                          addSYS_Reg0x11 |= 0x100000
#define clrf_SYS_Reg0x11_int_rwble_pri                          addSYS_Reg0x11 &= ~0x100000
#define get_SYS_Reg0x11_int_rwble_pri                           ((addSYS_Reg0x11 & 0x100000) >> 20)

#define posSYS_Reg0x11_int_rwbt_pri                             21
#define bitSYS_Reg0x11_int_rwbt_pri                             0x200000
#define set_SYS_Reg0x11_int_rwbt_pri(val)                       addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x200000)) | ((val) << 21))
#define setf_SYS_Reg0x11_int_rwbt_pri                           addSYS_Reg0x11 |= 0x200000
#define clrf_SYS_Reg0x11_int_rwbt_pri                           addSYS_Reg0x11 &= ~0x200000
#define get_SYS_Reg0x11_int_rwbt_pri                            ((addSYS_Reg0x11 & 0x200000) >> 21)

#define posSYS_Reg0x11_int_rwdm_pri                             22
#define bitSYS_Reg0x11_int_rwdm_pri                             0x400000
#define set_SYS_Reg0x11_int_rwdm_pri(val)                       addSYS_Reg0x11 = ((addSYS_Reg0x11 & (~0x400000)) | ((val) << 22))
#define setf_SYS_Reg0x11_int_rwdm_pri                           addSYS_Reg0x11 |= 0x400000
#define clrf_SYS_Reg0x11_int_rwdm_pri                           addSYS_Reg0x11 &= ~0x400000
#define get_SYS_Reg0x11_int_rwdm_pri                            ((addSYS_Reg0x11 & 0x400000) >> 22)





//addSYS_Reg0x12
#define addSYS_Reg0x12                                          *((volatile unsigned long *) (0x00800000+0x12*4))
#define posSYS_Reg0x12_int_pwm0_sta                             0
#define bitSYS_Reg0x12_int_pwm0_sta                             0x1
#define get_SYS_Reg0x12_int_pwm0_sta                            (addSYS_Reg0x12 & 0x1)

#define posSYS_Reg0x12_int_pwm1_sta                             1
#define bitSYS_Reg0x12_int_pwm1_sta                             0x2
#define get_SYS_Reg0x12_int_pwm1_sta                            ((addSYS_Reg0x12 & 0x2) >> 1)

#define posSYS_Reg0x12_int_timer0_sta                           2
#define bitSYS_Reg0x12_int_timer0_sta                           0x4
#define get_SYS_Reg0x12_int_timer0_sta                          ((addSYS_Reg0x12 & 0x4) >> 2)

#define posSYS_Reg0x12_int_timer1_sta                           3
#define bitSYS_Reg0x12_int_timer1_sta                           0x8
#define get_SYS_Reg0x12_int_timer1_sta                          ((addSYS_Reg0x12 & 0x8) >> 3)

#define posSYS_Reg0x12_int_uart0_sta                            4
#define bitSYS_Reg0x12_int_uart0_sta                            0x10
#define get_SYS_Reg0x12_int_uart0_sta                           ((addSYS_Reg0x12 & 0x10) >> 4)

#define posSYS_Reg0x12_int_uart1_sta                            5
#define bitSYS_Reg0x12_int_uart1_sta                            0x20
#define get_SYS_Reg0x12_int_uart1_sta                           ((addSYS_Reg0x12 & 0x20) >> 5)

#define posSYS_Reg0x12_int_spi0_sta                             6
#define bitSYS_Reg0x12_int_spi0_sta                             0x40
#define get_SYS_Reg0x12_int_spi0_sta                            ((addSYS_Reg0x12 & 0x40) >> 6)

#define posSYS_Reg0x12_int_i2c0_sta                             7
#define bitSYS_Reg0x12_int_i2c0_sta                             0x80
#define get_SYS_Reg0x12_int_i2c0_sta                            ((addSYS_Reg0x12 & 0x80) >> 7)

#define posSYS_Reg0x12_int_adc_sta                              8
#define bitSYS_Reg0x12_int_adc_sta                              0x100
#define get_SYS_Reg0x12_int_adc_sta                             ((addSYS_Reg0x12 & 0x100) >> 8)

#define posSYS_Reg0x12_int_aon_gpio_sta                         9
#define bitSYS_Reg0x12_int_aon_gpio_sta                         0x200
#define get_SYS_Reg0x12_int_aon_gpio_sta                        ((addSYS_Reg0x12 & 0x200) >> 9)

#define posSYS_Reg0x12_int_rtc_sta                              10
#define bitSYS_Reg0x12_int_rtc_sta                              0x400
#define get_SYS_Reg0x12_int_rtc_sta                             ((addSYS_Reg0x12 & 0x400) >> 10)

#define posSYS_Reg0x12_int_i2s_sta                              11
#define bitSYS_Reg0x12_int_i2s_sta                              0x800
#define get_SYS_Reg0x12_int_i2s_sta                             ((addSYS_Reg0x12 & 0x800) >> 11)

#define posSYS_Reg0x12_int_aon_rtc_sta                          12
#define bitSYS_Reg0x12_int_aon_rtc_sta                          0x1000
#define get_SYS_Reg0x12_int_aon_rtc_sta                         ((addSYS_Reg0x12 & 0x1000) >> 12)





#define posSYS_Reg0x12_int_usb_sta                              17
#define bitSYS_Reg0x12_int_usb_sta                              0x20000
#define get_SYS_Reg0x12_int_usb_sta                             ((addSYS_Reg0x12 & 0x20000) >> 17)

#define posSYS_Reg0x12_int_dma_sta                              18
#define bitSYS_Reg0x12_int_dma_sta                              0x40000
#define get_SYS_Reg0x12_int_dma_sta                             ((addSYS_Reg0x12 & 0x40000) >> 18)


#define posSYS_Reg0x12_int_rwble_sta                            20
#define bitSYS_Reg0x12_int_rwble_sta                            0x100000
#define get_SYS_Reg0x12_int_rwble_sta                           ((addSYS_Reg0x12 & 0x100000) >> 20)

#define posSYS_Reg0x12_int_rwbt_sta                             21
#define bitSYS_Reg0x12_int_rwbt_sta                             0x200000
#define get_SYS_Reg0x12_int_rwbt_sta                            ((addSYS_Reg0x12 & 0x200000) >> 21)

#define posSYS_Reg0x12_int_rwdm_sta                             22
#define bitSYS_Reg0x12_int_rwdm_sta                             0x400000
#define get_SYS_Reg0x12_int_rwdm_sta                            ((addSYS_Reg0x12 & 0x400000) >> 22)



//addSYS_Reg0x13
#define addSYS_Reg0x13                                          *((volatile unsigned long *) (0x00800000+0x13*4))
#define posSYS_Reg0x13_PLL_gate_time                            24
#define bitSYS_Reg0x13_PLL_gate_time                            0xFF000000
#define set_SYS_Reg0x13_PLL_gate_time(val)                      addSYS_Reg0x13 = ((addSYS_Reg0x13 & (~0xFF000000)) | ((val) << 24))
#define get_SYS_Reg0x13_PLL_gate_time                           ((addSYS_Reg0x13 & 0xFF000000) >> 24)

#define posSYS_Reg0x13_clk_gate_time                            16
#define bitSYS_Reg0x13_clk_gate_time                            0xFF0000
#define set_SYS_Reg0x13_clk_gate_time(val)                      addSYS_Reg0x13 = ((addSYS_Reg0x13 & (~0xFF0000)) | ((val) << 16))
#define get_SYS_Reg0x13_clk_gate_time                           ((addSYS_Reg0x13 & 0xFF0000) >> 16)

#define posSYS_Reg0x13_boost_pwd_delay_TIME                     0
#define bitSYS_Reg0x13_boost_pwd_delay_TIME                     0xFFFF
#define set_SYS_Reg0x13_boost_pwd_delay_TIME(val)               addSYS_Reg0x13 = ((addSYS_Reg0x13 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x13_boost_pwd_delay_TIME                    (addSYS_Reg0x13 & 0xFFFF)

//addSYS_Reg0x14
#define addSYS_Reg0x14                                          *((volatile unsigned long *) (0x00800000+0x14*4))

//addSYS_Reg0x15
#define addSYS_Reg0x15                                          *((volatile unsigned long *) (0x00800000+0x15*4))

//addSYS_Reg0x16
#define addSYS_Reg0x16                                          *((volatile unsigned long *) (0x00800000+0x16*4))

//addSYS_Reg0x17
#define addSYS_Reg0x17                                          *((volatile unsigned long *) (0x00800000+0x17*4))

#define posSYS_Reg0x17_PWM23_SEL                                11
#define bitSYS_Reg0x17_PWM23_SEL                                0x800
#define set_SYS_Reg0x17_PWM23_SEL(val)                          addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x800)) | ((val) << 11))
#define setf_SYS_Reg0x17_PWM23_SEL                              addSYS_Reg0x17 |= 0x800
#define clrf_SYS_Reg0x17_PWM23_SEL                              addSYS_Reg0x17 &= ~0x800
#define get_SYS_Reg0x17_PWM23_SEL                               ((addSYS_Reg0x17 & 0x800) >> 11)

#define posSYS_Reg0x17_PWM12_SEL                                10
#define bitSYS_Reg0x17_PWM12_SEL                                0x400
#define set_SYS_Reg0x17_PWM12_SEL(val)                          addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x400)) | ((val) << 10))
#define setf_SYS_Reg0x17_PWM12_SEL                              addSYS_Reg0x17 |= 0x400
#define clrf_SYS_Reg0x17_PWM12_SEL                              addSYS_Reg0x17 &= ~0x400
#define get_SYS_Reg0x17_PWM12_SEL                               ((addSYS_Reg0x17 & 0x400) >> 10)

#define posSYS_Reg0x17_id_gnd                                   9
#define bitSYS_Reg0x17_id_gnd                                   0x200
#define set_SYS_Reg0x17_id_gnd(val)                             addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x200)) | ((val) << 9))
#define setf_SYS_Reg0x17_id_gnd                                 addSYS_Reg0x17 |= 0x200
#define clrf_SYS_Reg0x17_id_gnd                                 addSYS_Reg0x17 &= ~0x200
#define get_SYS_Reg0x17_id_gnd                                  ((addSYS_Reg0x17 & 0x200) >> 9)

#define posSYS_Reg0x17_adc_q_sel                                8
#define bitSYS_Reg0x17_adc_q_sel                                0x100
#define set_SYS_Reg0x17_adc_q_sel(val)                          addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x100)) | ((val) << 8))
#define setf_SYS_Reg0x17_adc_q_sel                              addSYS_Reg0x17 |= 0x100
#define clrf_SYS_Reg0x17_adc_q_sel                              addSYS_Reg0x17 &= ~0x100
#define get_SYS_Reg0x17_adc_q_sel                               ((addSYS_Reg0x17 & 0x100) >> 8)

#define posSYS_Reg0x17_enb_busrt_sel                            7
#define bitSYS_Reg0x17_enb_busrt_sel                            0x80
#define set_SYS_Reg0x17_enb_busrt_sel(val)                      addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x80)) | ((val) << 7))
#define setf_SYS_Reg0x17_enb_busrt_sel                          addSYS_Reg0x17 |= 0x80
#define clrf_SYS_Reg0x17_enb_busrt_sel                          addSYS_Reg0x17 &= ~0x80
#define get_SYS_Reg0x17_enb_busrt_sel                           ((addSYS_Reg0x17 & 0x80) >> 7)

#define posSYS_Reg0x17_enb_busrt_reg                            6
#define bitSYS_Reg0x17_enb_busrt_reg                            0x40
#define set_SYS_Reg0x17_enb_busrt_reg(val)                      addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x40)) | ((val) << 6))
#define setf_SYS_Reg0x17_enb_busrt_reg                          addSYS_Reg0x17 |= 0x40
#define clrf_SYS_Reg0x17_enb_busrt_reg                          addSYS_Reg0x17 &= ~0x40
#define get_SYS_Reg0x17_enb_busrt_reg                           ((addSYS_Reg0x17 & 0x40) >> 6)

#define posSYS_Reg0x17_ana_test_pin                             5
#define bitSYS_Reg0x17_ana_test_pin                             0x20
#define set_SYS_Reg0x17_ana_test_pin(val)                       addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x20)) | ((val) << 5))
#define setf_SYS_Reg0x17_ana_test_pin                           addSYS_Reg0x17 |= 0x20
#define clrf_SYS_Reg0x17_ana_test_pin                           addSYS_Reg0x17 &= ~0x20
#define get_SYS_Reg0x17_ana_test_pin                            ((addSYS_Reg0x17 & 0x20) >> 5)

#define posSYS_Reg0x17_BB_TEST_PIN                              4
#define bitSYS_Reg0x17_BB_TEST_PIN                              0x10
#define set_SYS_Reg0x17_BB_TEST_PIN(val)                        addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x10)) | ((val) << 4))
#define setf_SYS_Reg0x17_BB_TEST_PIN                            addSYS_Reg0x17 |= 0x10
#define clrf_SYS_Reg0x17_BB_TEST_PIN                            addSYS_Reg0x17 &= ~0x10
#define get_SYS_Reg0x17_BB_TEST_PIN                             ((addSYS_Reg0x17 & 0x10) >> 4)

#define posSYS_Reg0x17_CLK16M_PWD                               3
#define bitSYS_Reg0x17_CLK16M_PWD                               0x8
#define set_SYS_Reg0x17_CLK16M_PWD(val)                         addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x8)) | ((val) << 3))
#define setf_SYS_Reg0x17_CLK16M_PWD                             addSYS_Reg0x17 |= 0x8
#define clrf_SYS_Reg0x17_CLK16M_PWD                             addSYS_Reg0x17 &= ~0x8
#define get_SYS_Reg0x17_CLK16M_PWD                              ((addSYS_Reg0x17 & 0x8) >> 3)

#define posSYS_Reg0x17_HP_LDO_PWD                               2
#define bitSYS_Reg0x17_HP_LDO_PWD                               0x4
#define set_SYS_Reg0x17_HP_LDO_PWD(val)                         addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x4)) | ((val) << 2))
#define setf_SYS_Reg0x17_HP_LDO_PWD                             addSYS_Reg0x17 |= 0x4
#define clrf_SYS_Reg0x17_HP_LDO_PWD                             addSYS_Reg0x17 &= ~0x4
#define get_SYS_Reg0x17_HP_LDO_PWD                              ((addSYS_Reg0x17 & 0x4) >> 2)

#define posSYS_Reg0x17_CLK96M_PWD                               1
#define bitSYS_Reg0x17_CLK96M_PWD                               0x2
#define set_SYS_Reg0x17_CLK96M_PWD(val)                         addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x2)) | ((val) << 1))
#define setf_SYS_Reg0x17_CLK96M_PWD                             addSYS_Reg0x17 |= 0x2
#define clrf_SYS_Reg0x17_CLK96M_PWD                             addSYS_Reg0x17 &= ~0x2
#define get_SYS_Reg0x17_CLK96M_PWD                              ((addSYS_Reg0x17 & 0x2) >> 1)

#define posSYS_Reg0x17_cb_bias_pwd                              0
#define bitSYS_Reg0x17_cb_bias_pwd                              0x1
#define set_SYS_Reg0x17_cb_bias_pwd(val)                        addSYS_Reg0x17 = ((addSYS_Reg0x17 & (~0x1)) | ((val) << 0))
#define setf_SYS_Reg0x17_cb_bias_pwd                            addSYS_Reg0x17 |= 0x1
#define clrf_SYS_Reg0x17_cb_bias_pwd                            addSYS_Reg0x17 &= ~0x1
#define get_SYS_Reg0x17_cb_bias_pwd                             (addSYS_Reg0x17 & 0x1)

//addSYS_Reg0x18
#define addSYS_Reg0x18                                          *((volatile unsigned long *) (0x00800000+0x18*4))

#define posSYS_Reg0x18_ret_itcm_ram_dis                         7
#define bitSYS_Reg0x18_ret_itcm_ram_dis                         0x80
#define set_SYS_Reg0x18_ret_itcm_ram_dis(val)                   addSYS_Reg0x18 = ((addSYS_Reg0x18 & (~0x80)) | ((val) << 7))
#define setf_SYS_Reg0x18_ret_itcm_ram_dis                       addSYS_Reg0x18 |= 0x80
#define clrf_SYS_Reg0x18_ret_itcm_ram_dis                       addSYS_Reg0x18 &= ~0x80
#define get_SYS_Reg0x18_ret_itcm_ram_dis                        ((addSYS_Reg0x18 & 0x80) >> 7)

#define posSYS_Reg0x18_ret_rw_ram1_dis                          6
#define bitSYS_Reg0x18_ret_rw_ram1_dis                          0x40
#define set_SYS_Reg0x18_ret_rw_ram1_dis(val)                    addSYS_Reg0x18 = ((addSYS_Reg0x18 & (~0x40)) | ((val) << 6))
#define setf_SYS_Reg0x18_ret_rw_ram1_dis                        addSYS_Reg0x18 |= 0x40
#define clrf_SYS_Reg0x18_ret_rw_ram1_dis                        addSYS_Reg0x18 &= ~0x40
#define get_SYS_Reg0x18_ret_rw_ram1_dis                         ((addSYS_Reg0x18 & 0x40) >> 6)

#define posSYS_Reg0x18_ret_rw_ram0_dis                          5
#define bitSYS_Reg0x18_ret_rw_ram0_dis                          0x20
#define set_SYS_Reg0x18_ret_rw_ram0_dis(val)                    addSYS_Reg0x18 = ((addSYS_Reg0x18 & (~0x20)) | ((val) << 5))
#define setf_SYS_Reg0x18_ret_rw_ram0_dis                        addSYS_Reg0x18 |= 0x20
#define clrf_SYS_Reg0x18_ret_rw_ram0_dis                        addSYS_Reg0x18 &= ~0x20
#define get_SYS_Reg0x18_ret_rw_ram0_dis                         ((addSYS_Reg0x18 & 0x20) >> 5)

#define posSYS_Reg0x18_ret_icache_ram_dis                       4
#define bitSYS_Reg0x18_ret_icache_ram_dis                       0x10
#define set_SYS_Reg0x18_ret_icache_ram_dis(val)                 addSYS_Reg0x18 = ((addSYS_Reg0x18 & (~0x10)) | ((val) << 4))
#define setf_SYS_Reg0x18_ret_icache_ram_dis                     addSYS_Reg0x18 |= 0x10
#define clrf_SYS_Reg0x18_ret_icache_ram_dis                     addSYS_Reg0x18 &= ~0x10
#define get_SYS_Reg0x18_ret_icache_ram_dis                      ((addSYS_Reg0x18 & 0x10) >> 4)

#define posSYS_Reg0x18_ret_dtcm_ram3_dis                        3
#define bitSYS_Reg0x18_ret_dtcm_ram3_dis                        0x8
#define set_SYS_Reg0x18_ret_dtcm_ram3_dis(val)                  addSYS_Reg0x18 = ((addSYS_Reg0x18 & (~0x8)) | ((val) << 3))
#define setf_SYS_Reg0x18_ret_dtcm_ram3_dis                      addSYS_Reg0x18 |= 0x8
#define clrf_SYS_Reg0x18_ret_dtcm_ram3_dis                      addSYS_Reg0x18 &= ~0x8
#define get_SYS_Reg0x18_ret_dtcm_ram3_dis                       ((addSYS_Reg0x18 & 0x8) >> 3)

#define posSYS_Reg0x18_ret_dtcm_ram2_dis                        2
#define bitSYS_Reg0x18_ret_dtcm_ram2_dis                        0x4
#define set_SYS_Reg0x18_ret_dtcm_ram2_dis(val)                  addSYS_Reg0x18 = ((addSYS_Reg0x18 & (~0x4)) | ((val) << 2))
#define setf_SYS_Reg0x18_ret_dtcm_ram2_dis                      addSYS_Reg0x18 |= 0x4
#define clrf_SYS_Reg0x18_ret_dtcm_ram2_dis                      addSYS_Reg0x18 &= ~0x4
#define get_SYS_Reg0x18_ret_dtcm_ram2_dis                       ((addSYS_Reg0x18 & 0x4) >> 2)

#define posSYS_Reg0x18_ret_dtcm_ram1_dis                        1
#define bitSYS_Reg0x18_ret_dtcm_ram1_dis                        0x2
#define set_SYS_Reg0x18_ret_dtcm_ram1_dis(val)                  addSYS_Reg0x18 = ((addSYS_Reg0x18 & (~0x2)) | ((val) << 1))
#define setf_SYS_Reg0x18_ret_dtcm_ram1_dis                      addSYS_Reg0x18 |= 0x2
#define clrf_SYS_Reg0x18_ret_dtcm_ram1_dis                      addSYS_Reg0x18 &= ~0x2
#define get_SYS_Reg0x18_ret_dtcm_ram1_dis                       ((addSYS_Reg0x18 & 0x2) >> 1)

#define posSYS_Reg0x18_ret_dtcm_ram0_dis                        0
#define bitSYS_Reg0x18_ret_dtcm_ram0_dis                        0x1
#define set_SYS_Reg0x18_ret_dtcm_ram0_dis(val)                  addSYS_Reg0x18 = ((addSYS_Reg0x18 & (~0x1)) | ((val) << 0))
#define setf_SYS_Reg0x18_ret_dtcm_ram0_dis                      addSYS_Reg0x18 |= 0x1
#define clrf_SYS_Reg0x18_ret_dtcm_ram0_dis                      addSYS_Reg0x18 &= ~0x1
#define get_SYS_Reg0x18_ret_dtcm_ram0_dis                       (addSYS_Reg0x18 & 0x1)

//addSYS_Reg0x19
#define addSYS_Reg0x19                                          *((volatile unsigned long *) (0x00800000+0x19*4))

//addSYS_Reg0x1a
#define addSYS_Reg0x1a                                          *((volatile unsigned long *) (0x00800000+0x1a*4))

//addSYS_Reg0x1b
#define addSYS_Reg0x1b                                          *((volatile unsigned long *) (0x00800000+0x1b*4))

//addSYS_Reg0x1c
#define addSYS_Reg0x1c                                          *((volatile unsigned long *) (0x00800000+0x1c*4))

#define posSYS_Reg0x1c_BMC_prio_mode                            16
#define bitSYS_Reg0x1c_BMC_prio_mode                            0x10000
#define set_SYS_Reg0x1c_BMC_prio_mode(val)                      addSYS_Reg0x1c = ((addSYS_Reg0x1c & (~0x10000)) | ((val) << 16))
#define setf_SYS_Reg0x1c_BMC_prio_mode                          addSYS_Reg0x1c |= 0x10000
#define clrf_SYS_Reg0x1c_BMC_prio_mode                          addSYS_Reg0x1c &= ~0x10000
#define get_SYS_Reg0x1c_BMC_prio_mode                           ((addSYS_Reg0x1c & 0x10000) >> 16)

#define posSYS_Reg0x1c_BMC_prio                                 0
#define bitSYS_Reg0x1c_BMC_prio                                 0xFFFF
#define set_SYS_Reg0x1c_BMC_prio(val)                           addSYS_Reg0x1c = ((addSYS_Reg0x1c & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x1c_BMC_prio                                (addSYS_Reg0x1c & 0xFFFF)

//addSYS_Reg0x1d
#define addSYS_Reg0x1d                                          *((volatile unsigned long *) (0x00800000+0x1d*4))
#define posSYS_Reg0x1d_power_state                              0
#define bitSYS_Reg0x1d_power_state                              0xF
#define get_SYS_Reg0x1d_power_state                             (addSYS_Reg0x1d & 0xF)

//addSYS_Reg0x1e
#define addSYS_Reg0x1e                                          *((volatile unsigned long *) (0x00800000+0x1e*4))
#define posSYS_Reg0x1e_rfu                                      24
#define bitSYS_Reg0x1e_rfu                                      0xFF000000
#define set_SYS_Reg0x1e_rfu(val)                                addSYS_Reg0x1e = ((addSYS_Reg0x1e & (~0xFF000000)) | ((val) << 24))
#define get_SYS_Reg0x1e_rfu                                     ((addSYS_Reg0x1e & 0xFF000000) >> 24)

#define posSYS_Reg0x1e_rwby_clk_gate_disable                    24
#define bitSYS_Reg0x1e_rwby_clk_gate_disable                    0xF000000
#define set_SYS_Reg0x1e_rwby_clk_gate_disable(val)              addSYS_Reg0x1e = ((addSYS_Reg0x1e & (~0xF000000)) | ((val) << 24))
#define get_SYS_Reg0x1e_rwby_clk_gate_disable                   ((addSYS_Reg0x1e & 0xF000000) >> 24)

#define posSYS_Reg0x1e_ahb_clk_gate_disable                     16
#define bitSYS_Reg0x1e_ahb_clk_gate_disable                     0xFF0000
#define set_SYS_Reg0x1e_ahb_clk_gate_disable(val)               addSYS_Reg0x1e = ((addSYS_Reg0x1e & (~0xFF0000)) | ((val) << 16))
#define get_SYS_Reg0x1e_ahb_clk_gate_disable                    ((addSYS_Reg0x1e & 0xFF0000) >> 16)

#define posSYS_Reg0x1e_apb_clk_gate_disable                     0
#define bitSYS_Reg0x1e_apb_clk_gate_disable                     0xFFFF
#define set_SYS_Reg0x1e_apb_clk_gate_disable(val)               addSYS_Reg0x1e = ((addSYS_Reg0x1e & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x1e_apb_clk_gate_disable                    (addSYS_Reg0x1e & 0xFFFF)

//addSYS_Reg0x20
#define addSYS_Reg0x20                                          *((volatile unsigned long *) (0x00800000+0x20*4))
#define posSYS_Reg0x20_itcm_ram_pwd                             0
#define bitSYS_Reg0x20_itcm_ram_pwd                             0xFFFF
#define set_SYS_Reg0x20_itcm_ram_pwd(val)                       addSYS_Reg0x20 = ((addSYS_Reg0x20 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x20_itcm_ram_pwd                            (addSYS_Reg0x20 & 0xFFFF)

//addSYS_Reg0x21
#define addSYS_Reg0x21                                          *((volatile unsigned long *) (0x00800000+0x21*4))
#define posSYS_Reg0x21_em_ram0_pwd                              0
#define bitSYS_Reg0x21_em_ram0_pwd                              0xFFFF
#define set_SYS_Reg0x21_em_ram0_pwd(val)                        addSYS_Reg0x21 = ((addSYS_Reg0x21 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x21_em_ram0_pwd                             (addSYS_Reg0x21 & 0xFFFF)

//addSYS_Reg0x22
#define addSYS_Reg0x22                                          *((volatile unsigned long *) (0x00800000+0x22*4))
#define posSYS_Reg0x22_em_ram1_pwd                              0
#define bitSYS_Reg0x22_em_ram1_pwd                              0xFFFF
#define set_SYS_Reg0x22_em_ram1_pwd(val)                        addSYS_Reg0x22 = ((addSYS_Reg0x22 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x22_em_ram1_pwd                             (addSYS_Reg0x22 & 0xFFFF)

//addSYS_Reg0x23
#define addSYS_Reg0x23                                          *((volatile unsigned long *) (0x00800000+0x23*4))

//addSYS_Reg0x24
#define addSYS_Reg0x24                                          *((volatile unsigned long *) (0x00800000+0x24*4))
#define posSYS_Reg0x24_bk24_pwd                                 0
#define bitSYS_Reg0x24_bk24_pwd                                 0xFFFF
#define set_SYS_Reg0x24_bk24_pwd(val)                           addSYS_Reg0x24 = ((addSYS_Reg0x24 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x24_bk24_pwd                                (addSYS_Reg0x24 & 0xFFFF)

//addSYS_Reg0x25
#define addSYS_Reg0x25                                          *((volatile unsigned long *) (0x00800000+0x25*4))
#define posSYS_Reg0x25_rw_wireless_pwd                          0
#define bitSYS_Reg0x25_rw_wireless_pwd                          0xFFFF
#define set_SYS_Reg0x25_rw_wireless_pwd(val)                    addSYS_Reg0x25 = ((addSYS_Reg0x25 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x25_rw_wireless_pwd                         (addSYS_Reg0x25 & 0xFFFF)

//addSYS_Reg0x26
#define addSYS_Reg0x26                                          *((volatile unsigned long *) (0x00800000+0x26*4))
#define posSYS_Reg0x26_dtcm_ram1_pwd                            0
#define bitSYS_Reg0x26_dtcm_ram1_pwd                            0xFFFF
#define set_SYS_Reg0x26_dtcm_ram1_pwd(val)                      addSYS_Reg0x26 = ((addSYS_Reg0x26 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x26_dtcm_ram1_pwd                           (addSYS_Reg0x26 & 0xFFFF)

//addSYS_Reg0x27
#define addSYS_Reg0x27                                          *((volatile unsigned long *) (0x00800000+0x27*4))
#define posSYS_Reg0x27_dtcm_ram2_pwd                            0
#define bitSYS_Reg0x27_dtcm_ram2_pwd                            0xFFFF
#define set_SYS_Reg0x27_dtcm_ram2_pwd(val)                      addSYS_Reg0x27 = ((addSYS_Reg0x27 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x27_dtcm_ram2_pwd                           (addSYS_Reg0x27 & 0xFFFF)

//addSYS_Reg0x28
#define addSYS_Reg0x28                                          *((volatile unsigned long *) (0x00800000+0x28*4))
#define posSYS_Reg0x28_dtcm_ram3_pwd                            0
#define bitSYS_Reg0x28_dtcm_ram3_pwd                            0xFFFF
#define set_SYS_Reg0x28_dtcm_ram3_pwd(val)                      addSYS_Reg0x28 = ((addSYS_Reg0x28 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x28_dtcm_ram3_pwd                           (addSYS_Reg0x28 & 0xFFFF)

//addSYS_Reg0x29
#define addSYS_Reg0x29                                          *((volatile unsigned long *) (0x00800000+0x29*4))
#define posSYS_Reg0x29_rom_pwd                                  0
#define bitSYS_Reg0x29_rom_pwd                                  0xFFFF
#define set_SYS_Reg0x29_rom_pwd(val)                            addSYS_Reg0x29 = ((addSYS_Reg0x29 & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x29_rom_pwd                                 (addSYS_Reg0x29 & 0xFFFF)

//addSYS_Reg0x2a
#define addSYS_Reg0x2a                                          *((volatile unsigned long *) (0x00800000+0x2a*4))
#define posSYS_Reg0x2a_att_ram_pwd                              0
#define bitSYS_Reg0x2a_att_ram_pwd                              0xFFFF
#define set_SYS_Reg0x2a_att_ram_pwd(val)                        addSYS_Reg0x2a = ((addSYS_Reg0x2a & (~0xFFFF)) | ((val) << 0))
#define get_SYS_Reg0x2a_att_ram_pwd                             (addSYS_Reg0x2a & 0xFFFF)

//addSYS_Reg0x30
#define addSYS_Reg0x30                                          *((volatile unsigned long *) (0x00800000+0x30*4))

//addSYS_Reg0x31
#define addSYS_Reg0x31                                          *((volatile unsigned long *) (0x00800000+0x31*4))

//addSYS_Reg0x32
#define addSYS_Reg0x32                                          *((volatile unsigned long *) (0x00800000+0x32*4))

//addSYS_Reg0x33
#define addSYS_Reg0x33                                          *((volatile unsigned long *) (0x00800000+0x33*4))


//************************************************************//
//PMU
//************************************************************//
#define BASEADDR_PMU                                            0x00800800
//addPMU_Reg0x0
#define addPMU_Reg0x0                                           *((volatile unsigned long *) (0x00800800+0x0*4))

#define posPMU_Reg0x0_reset_reason                              8
#define bitPMU_Reg0x0_reset_reason                              0x700
#define set_PMU_Reg0x0_reset_reason(val)                        addPMU_Reg0x0 = ((addPMU_Reg0x0 & (~0x700)) | ((val) << 8))
#define get_PMU_Reg0x0_reset_reason                             ((addPMU_Reg0x0 & 0x700) >> 8)



#define posPMU_Reg0x0_digital_reset                             1
#define bitPMU_Reg0x0_digital_reset                             0x2
#define set_PMU_Reg0x0_digital_reset(val)                       addPMU_Reg0x0 = ((addPMU_Reg0x0 & (~0x2)) | ((val) << 1))
#define setf_PMU_Reg0x0_digital_reset                           addPMU_Reg0x0 |= 0x2
#define clrf_PMU_Reg0x0_digital_reset                           addPMU_Reg0x0 &= ~0x2
#define get_PMU_Reg0x0_digital_reset                            ((addPMU_Reg0x0 & 0x2) >> 1)

#define posPMU_Reg0x0_all_reset                                 0
#define bitPMU_Reg0x0_all_reset                                 0x1
#define set_PMU_Reg0x0_all_reset(val)                           addPMU_Reg0x0 = ((addPMU_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_PMU_Reg0x0_all_reset                               addPMU_Reg0x0 |= 0x1
#define clrf_PMU_Reg0x0_all_reset                               addPMU_Reg0x0 &= ~0x1
#define get_PMU_Reg0x0_all_reset                                (addPMU_Reg0x0 & 0x1)

//addPMU_Reg0x1
#define addPMU_Reg0x1                                           *((volatile unsigned long *) (0x00800800+0x1*4))
#define posPMU_Reg0x1_reg0_w_en                                 15
#define bitPMU_Reg0x1_reg0_w_en                                 0x8000
#define set_PMU_Reg0x1_reg0_w_en(val)                           addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x8000)) | ((val) << 15))
#define setf_PMU_Reg0x1_reg0_w_en                               addPMU_Reg0x1 |= 0x8000
#define clrf_PMU_Reg0x1_reg0_w_en                               addPMU_Reg0x1 &= ~0x8000
#define get_PMU_Reg0x1_reg0_w_en                                ((addPMU_Reg0x1 & 0x8000) >> 15)

#define posPMU_Reg0x1_pwd_sys_ldo                               11
#define bitPMU_Reg0x1_pwd_sys_ldo                               0x800
#define set_PMU_Reg0x1_pwd_sys_ldo(val)                         addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x800)) | ((val) << 11))
#define setf_PMU_Reg0x1_pwd_sys_ldo                             addPMU_Reg0x1 |= 0x800
#define clrf_PMU_Reg0x1_pwd_sys_ldo                             addPMU_Reg0x1 &= ~0x800
#define get_PMU_Reg0x1_pwd_sys_ldo                              ((addPMU_Reg0x1 & 0x800) >> 11)

#define posPMU_Reg0x1_force_rw_wake                             10
#define bitPMU_Reg0x1_force_rw_wake                             0x400
#define set_PMU_Reg0x1_force_rw_wake(val)                       addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x400)) | ((val) << 10))
#define setf_PMU_Reg0x1_force_rw_wake                           addPMU_Reg0x1 |= 0x400
#define clrf_PMU_Reg0x1_force_rw_wake                           addPMU_Reg0x1 &= ~0x400
#define get_PMU_Reg0x1_force_rw_wake                            ((addPMU_Reg0x1 & 0x400) >> 10)

#define posPMU_Reg0x1_rc32k_deep_en                             9
#define bitPMU_Reg0x1_rc32k_deep_en                             0x200
#define set_PMU_Reg0x1_rc32k_deep_en(val)                       addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x200)) | ((val) << 9))
#define setf_PMU_Reg0x1_rc32k_deep_en                           addPMU_Reg0x1 |= 0x200
#define clrf_PMU_Reg0x1_rc32k_deep_en                           addPMU_Reg0x1 &= ~0x200
#define get_PMU_Reg0x1_rc32k_deep_en                            ((addPMU_Reg0x1 & 0x200) >> 9)

#define posPMU_Reg0x1_direct_wake_enable                        8
#define bitPMU_Reg0x1_direct_wake_enable                        0x100
#define set_PMU_Reg0x1_direct_wake_enable(val)                  addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x100)) | ((val) << 8))
#define setf_PMU_Reg0x1_direct_wake_enable                      addPMU_Reg0x1 |= 0x100
#define clrf_PMU_Reg0x1_direct_wake_enable                      addPMU_Reg0x1 &= ~0x100
#define get_PMU_Reg0x1_direct_wake_enable                       ((addPMU_Reg0x1 & 0x100) >> 8)

#define posPMU_Reg0x1_wdt_reset_ctrl1                           7
#define bitPMU_Reg0x1_wdt_reset_ctrl1                           0x80
#define set_PMU_Reg0x1_wdt_reset_ctrl1(val)                     addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x80)) | ((val) << 7))
#define setf_PMU_Reg0x1_wdt_reset_ctrl1                         addPMU_Reg0x1 |= 0x80
#define clrf_PMU_Reg0x1_wdt_reset_ctrl1                         addPMU_Reg0x1 &= ~0x80
#define get_PMU_Reg0x1_wdt_reset_ctrl1                          ((addPMU_Reg0x1 & 0x80) >> 7)

#define posPMU_Reg0x1_rc32k_rc1k_sel                            6
#define bitPMU_Reg0x1_rc32k_rc1k_sel                            0x40
#define set_PMU_Reg0x1_rc32k_rc1k_sel(val)                      addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x40)) | ((val) << 6))
#define setf_PMU_Reg0x1_rc32k_rc1k_sel                          addPMU_Reg0x1 |= 0x40
#define clrf_PMU_Reg0x1_rc32k_rc1k_sel                          addPMU_Reg0x1 &= ~0x40
#define get_PMU_Reg0x1_rc32k_rc1k_sel                           ((addPMU_Reg0x1 & 0x40) >> 6)

#define posPMU_Reg0x1_rc32k_xtal32k_sel                         5
#define bitPMU_Reg0x1_rc32k_xtal32k_sel                         0x20
#define set_PMU_Reg0x1_rc32k_xtal32k_sel(val)                   addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x20)) | ((val) << 5))
#define setf_PMU_Reg0x1_rc32k_xtal32k_sel                       addPMU_Reg0x1 |= 0x20
#define clrf_PMU_Reg0x1_rc32k_xtal32k_sel                       addPMU_Reg0x1 &= ~0x20
#define get_PMU_Reg0x1_rc32k_xtal32k_sel                        ((addPMU_Reg0x1 & 0x20) >> 5)

#define posPMU_Reg0x1_clk32k_src_sel                            4
#define bitPMU_Reg0x1_clk32k_src_sel                            0x10
#define set_PMU_Reg0x1_clk32k_src_sel(val)                      addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x10)) | ((val) << 4))
#define setf_PMU_Reg0x1_clk32k_src_sel                          addPMU_Reg0x1 |= 0x10
#define clrf_PMU_Reg0x1_clk32k_src_sel                          addPMU_Reg0x1 &= ~0x10
#define get_PMU_Reg0x1_clk32k_src_sel                           ((addPMU_Reg0x1 & 0x10) >> 4)

#define posPMU_Reg0x1_wdt_reset_ctrl                            3
#define bitPMU_Reg0x1_wdt_reset_ctrl                            0x8
#define set_PMU_Reg0x1_wdt_reset_ctrl(val)                      addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x8)) | ((val) << 3))
#define setf_PMU_Reg0x1_wdt_reset_ctrl                          addPMU_Reg0x1 |= 0x8
#define clrf_PMU_Reg0x1_wdt_reset_ctrl                          addPMU_Reg0x1 &= ~0x8
#define get_PMU_Reg0x1_wdt_reset_ctrl                           ((addPMU_Reg0x1 & 0x8) >> 3)

#define posPMU_Reg0x1_boot_rom_en                               2
#define bitPMU_Reg0x1_boot_rom_en                               0x4
#define set_PMU_Reg0x1_boot_rom_en(val)                         addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x4)) | ((val) << 2))
#define setf_PMU_Reg0x1_boot_rom_en                             addPMU_Reg0x1 |= 0x4
#define clrf_PMU_Reg0x1_boot_rom_en                             addPMU_Reg0x1 &= ~0x4
#define get_PMU_Reg0x1_boot_rom_en                              ((addPMU_Reg0x1 & 0x4) >> 2)

#define posPMU_Reg0x1_mchk_bypass                               1
#define bitPMU_Reg0x1_mchk_bypass                               0x2
#define set_PMU_Reg0x1_mchk_bypass(val)                         addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x2)) | ((val) << 1))
#define setf_PMU_Reg0x1_mchk_bypass                             addPMU_Reg0x1 |= 0x2
#define clrf_PMU_Reg0x1_mchk_bypass                             addPMU_Reg0x1 &= ~0x2
#define get_PMU_Reg0x1_mchk_bypass                              ((addPMU_Reg0x1 & 0x2) >> 1)

#define posPMU_Reg0x1_fast_boot                                 0
#define bitPMU_Reg0x1_fast_boot                                 0x1
#define set_PMU_Reg0x1_fast_boot(val)                           addPMU_Reg0x1 = ((addPMU_Reg0x1 & (~0x1)) | ((val) << 0))
#define setf_PMU_Reg0x1_fast_boot                               addPMU_Reg0x1 |= 0x1
#define clrf_PMU_Reg0x1_fast_boot                               addPMU_Reg0x1 &= ~0x1
#define get_PMU_Reg0x1_fast_boot                                (addPMU_Reg0x1 & 0x1)

//addPMU_Reg0x2
#define addPMU_Reg0x2                                           *((volatile unsigned long *) (0x00800800+0x2*4))

//addPMU_Reg0x3
#define addPMU_Reg0x3                                           *((volatile unsigned long *) (0x00800800+0x3*4))

//addPMU_Reg0x4
#define addPMU_Reg0x4                                           *((volatile unsigned long *) (0x00800800+0x4*4))
#define posPMU_Reg0x4_gotosleep                                 16
#define bitPMU_Reg0x4_gotosleep                                 0xFFFF0000
#define set_PMU_Reg0x4_gotosleep(val)                           addPMU_Reg0x4 = ((addPMU_Reg0x4 & (~0xFFFF0000)) | ((val) << 16))
#define get_PMU_Reg0x4_gotosleep                                ((addPMU_Reg0x4 & 0xFFFF0000) >> 16)

#define posPMU_Reg0x4_waken_by_timer                            8
#define bitPMU_Reg0x4_waken_by_timer                            0x100
#define set_PMU_Reg0x4_waken_by_timer(val)                      addPMU_Reg0x4 = ((addPMU_Reg0x4 & (~0x100)) | ((val) << 8))
#define setf_PMU_Reg0x4_waken_by_timer                          addPMU_Reg0x4 |= 0x100
#define clrf_PMU_Reg0x4_waken_by_timer                          addPMU_Reg0x4 &= ~0x100
#define get_PMU_Reg0x4_waken_by_timer                           ((addPMU_Reg0x4 & 0x100) >> 8)

#define posPMU_Reg0x4_waken_by_GPIOE                            0
#define bitPMU_Reg0x4_waken_by_GPIOE                            0xFF
#define set_PMU_Reg0x4_waken_by_GPIOE(val)                      addPMU_Reg0x4 = ((addPMU_Reg0x4 & (~0xFF)) | ((val) << 0))
#define get_PMU_Reg0x4_waken_by_GPIOE                           (addPMU_Reg0x4 & 0xFF)

//addPMU_Reg0x5
#define addPMU_Reg0x5                                           *((volatile unsigned long *) (0x00800800+0x5*4))

#define posPMU_Reg0x5_deep_wake_by_timer                        28
#define bitPMU_Reg0x5_deep_wake_by_timer                        0x10000000
#define set_PMU_Reg0x5_deep_wake_by_timer(val)                  addPMU_Reg0x5 = ((addPMU_Reg0x5 & (~0x10000000)) | ((val) << 28))
#define setf_PMU_Reg0x5_deep_wake_by_timer                      addPMU_Reg0x5 |= 0x10000000
#define clrf_PMU_Reg0x5_deep_wake_by_timer                      addPMU_Reg0x5 &= ~0x10000000
#define get_PMU_Reg0x5_deep_wake_by_timer                       ((addPMU_Reg0x5 & 0x10000000) >> 28)

#define posPMU_Reg0x5_deep_wake_by_gpio                         27
#define bitPMU_Reg0x5_deep_wake_by_gpio                         0x8000000
#define set_PMU_Reg0x5_deep_wake_by_gpio(val)                   addPMU_Reg0x5 = ((addPMU_Reg0x5 & (~0x8000000)) | ((val) << 27))
#define setf_PMU_Reg0x5_deep_wake_by_gpio                       addPMU_Reg0x5 |= 0x8000000
#define clrf_PMU_Reg0x5_deep_wake_by_gpio                       addPMU_Reg0x5 &= ~0x8000000
#define get_PMU_Reg0x5_deep_wake_by_gpio                        ((addPMU_Reg0x5 & 0x8000000) >> 27)

//addPMU_Reg0x6
#define addPMU_Reg0x6                                           *((volatile unsigned long *) (0x00800800+0x6*4))

//addPMU_Reg0x7
#define addPMU_Reg0x7                                           *((volatile unsigned long *) (0x00800800+0x7*4))

//addPMU_Reg0x8
#define addPMU_Reg0x8                                           *((volatile unsigned long *) (0x00800800+0x8*4))

//addPMU_Reg0x10
#define addPMU_Reg0x10                                          *((volatile unsigned long *) (0x00800800+0x10*4))

//addPMU_Reg0x11
#define addPMU_Reg0x11                                          *((volatile unsigned long *) (0x00800800+0x11*4))

//addPMU_Reg0x12
#define addPMU_Reg0x12                                          *((volatile unsigned long *) (0x00800800+0x12*4))

//addPMU_Reg0x13
#define addPMU_Reg0x13                                          *((volatile unsigned long *) (0x00800800+0x13*4))

//addPMU_Reg0x14
#define addPMU_Reg0x14                                          *((volatile unsigned long *) (0x00800800+0x14*4))
#define posPMU_Reg0x14_sleep_sel                                16
#define bitPMU_Reg0x14_sleep_sel                                0x10000
#define set_PMU_Reg0x14_sleep_sel(val)                          addPMU_Reg0x14 = ((addPMU_Reg0x14 & (~0x10000)) | ((val) << 16))
#define setf_PMU_Reg0x14_sleep_sel                              addPMU_Reg0x14 |= 0x10000
#define clrf_PMU_Reg0x14_sleep_sel                              addPMU_Reg0x14 &= ~0x10000
#define get_PMU_Reg0x14_sleep_sel                               ((addPMU_Reg0x14 & 0x10000) >> 16)

#define posPMU_Reg0x14_voltage_ctrl_work_aon                    12
#define bitPMU_Reg0x14_voltage_ctrl_work_aon                    0xF000
#define set_PMU_Reg0x14_voltage_ctrl_work_aon(val)              addPMU_Reg0x14 = ((addPMU_Reg0x14 & (~0xF000)) | ((val) << 12))
#define get_PMU_Reg0x14_voltage_ctrl_work_aon                   ((addPMU_Reg0x14 & 0xF000) >> 12)

#define posPMU_Reg0x14_voltage_ctrl_sleep_aon                   8
#define bitPMU_Reg0x14_voltage_ctrl_sleep_aon                   0xF00
#define set_PMU_Reg0x14_voltage_ctrl_sleep_aon(val)             addPMU_Reg0x14 = ((addPMU_Reg0x14 & (~0xF00)) | ((val) << 8))
#define get_PMU_Reg0x14_voltage_ctrl_sleep_aon                  ((addPMU_Reg0x14 & 0xF00) >> 8)

#define posPMU_Reg0x14_voltage_ctrl_work_core                   4
#define bitPMU_Reg0x14_voltage_ctrl_work_core                   0xF0
#define set_PMU_Reg0x14_voltage_ctrl_work_core(val)             addPMU_Reg0x14 = ((addPMU_Reg0x14 & (~0xF0)) | ((val) << 4))
#define get_PMU_Reg0x14_voltage_ctrl_work_core                  ((addPMU_Reg0x14 & 0xF0) >> 4)

#define posPMU_Reg0x14_voltage_ctrl_sleep_core                  0
#define bitPMU_Reg0x14_voltage_ctrl_sleep_core                  0xF
#define set_PMU_Reg0x14_voltage_ctrl_sleep_core(val)            addPMU_Reg0x14 = ((addPMU_Reg0x14 & (~0xF)) | ((val) << 0))
#define get_PMU_Reg0x14_voltage_ctrl_sleep_core                 (addPMU_Reg0x14 & 0xF)

//addPMU_Reg0x15
#define addPMU_Reg0x15                                          *((volatile unsigned long *) (0x00800800+0x15*4))
#define posPMU_Reg0x15_flash_gpio_pull                          0
#define bitPMU_Reg0x15_flash_gpio_pull                          0xFFF
#define set_PMU_Reg0x15_flash_gpio_pull(val)                    addPMU_Reg0x15 = ((addPMU_Reg0x15 & (~0xFFF)) | ((val) << 0))
#define get_PMU_Reg0x15_flash_gpio_pull                         (addPMU_Reg0x15 & 0xFFF)

#define posPMU_Reg0x15_clk_gate_dis                             14
#define bitPMU_Reg0x15_clk_gate_dis                             0x4000
#define set_PMU_Reg0x15_clk_gate_dis(val)                       addPMU_Reg0x15 = ((addPMU_Reg0x15 & (~0x4000)) | ((val) << 14))
#define setf_PMU_Reg0x15_clk_gate_dis                           addPMU_Reg0x15 |= 0x4000
#define clrf_PMU_Reg0x15_clk_gate_dis                           addPMU_Reg0x15 &= ~0x4000
#define get_PMU_Reg0x15_clk_gate_dis                            ((addPMU_Reg0x15 & 0x4000) >> 14)

#define posPMU_Reg0x15_pll_gate_dis                             15
#define bitPMU_Reg0x15_pll_gate_dis                             0x8000
#define set_PMU_Reg0x15_pll_gate_dis(val)                       addPMU_Reg0x15 = ((addPMU_Reg0x15 & (~0x8000)) | ((val) << 15))
#define setf_PMU_Reg0x15_pll_gate_dis                           addPMU_Reg0x15 |= 0x8000
#define clrf_PMU_Reg0x15_pll_gate_dis                           addPMU_Reg0x15 &= ~0x8000
#define get_PMU_Reg0x15_pll_gate_dis                            ((addPMU_Reg0x15 & 0x8000) >> 15)

#define posPMU_Reg0x15_clk_gate_time                            16
#define bitPMU_Reg0x15_clk_gate_time                            0xFF0000
#define set_PMU_Reg0x15_clk_gate_time(val)                      addPMU_Reg0x15 = ((addPMU_Reg0x15 & (~0xFF0000)) | ((val) << 16))
#define get_PMU_Reg0x15_clk_gate_time                           ((addPMU_Reg0x15 & 0xFF0000) >> 16)

#define posPMU_Reg0x15_pll_gate_time                            24
#define bitPMU_Reg0x15_pll_gate_time                            0xFF000000
#define set_PMU_Reg0x15_pll_gate_time(val)                      addPMU_Reg0x15 = ((addPMU_Reg0x15 & (~0xFF000000)) | ((val) << 24))
#define get_PMU_Reg0x15_pll_gate_time                           ((addPMU_Reg0x15 & 0xFF000000) >> 24)


//************************************************************//
//rtc_aon
//************************************************************//
#define BASEADDR_rtc_aon                                        0x00800900
//addrtc_aon_Reg0x0
#define addrtc_aon_Reg0x0                                       *((volatile unsigned long *) (0x00800900+0x0*4))
#define posrtc_aon_Reg0x0_rtc_clk_en                            6
#define bitrtc_aon_Reg0x0_rtc_clk_en                            0x40
#define set_rtc_aon_Reg0x0_rtc_clk_en(val)                      addrtc_aon_Reg0x0 = ((addrtc_aon_Reg0x0 & (~0x40)) | ((val) << 6))
#define setf_rtc_aon_Reg0x0_rtc_clk_en                          addrtc_aon_Reg0x0 |= 0x40
#define clrf_rtc_aon_Reg0x0_rtc_clk_en                          addrtc_aon_Reg0x0 &= ~0x40
#define get_rtc_aon_Reg0x0_rtc_clk_en                           ((addrtc_aon_Reg0x0 & 0x40) >> 6)

#define posrtc_aon_Reg0x0_rtc_tick_int                          5
#define bitrtc_aon_Reg0x0_rtc_tick_int                          0x20
#define set_rtc_aon_Reg0x0_rtc_tick_int(val)                    addrtc_aon_Reg0x0 = ((addrtc_aon_Reg0x0 & (~0x20)) | ((val) << 5))
#define setf_rtc_aon_Reg0x0_rtc_tick_int                        addrtc_aon_Reg0x0 |= 0x20
#define clrf_rtc_aon_Reg0x0_rtc_tick_int                        addrtc_aon_Reg0x0 &= ~0x20
#define get_rtc_aon_Reg0x0_rtc_tick_int                         ((addrtc_aon_Reg0x0 & 0x20) >> 5)

#define posrtc_aon_Reg0x0_rtc_aon_int                           4
#define bitrtc_aon_Reg0x0_rtc_aon_int                           0x10
#define set_rtc_aon_Reg0x0_rtc_aon_int(val)                     addrtc_aon_Reg0x0 = ((addrtc_aon_Reg0x0 & (~0x10)) | ((val) << 4))
#define setf_rtc_aon_Reg0x0_rtc_aon_int                         addrtc_aon_Reg0x0 |= 0x10
#define clrf_rtc_aon_Reg0x0_rtc_aon_int                         addrtc_aon_Reg0x0 &= ~0x10
#define get_rtc_aon_Reg0x0_rtc_aon_int                          ((addrtc_aon_Reg0x0 & 0x10) >> 4)

#define posrtc_aon_Reg0x0_rtc_tick_int_en                       3
#define bitrtc_aon_Reg0x0_rtc_tick_int_en                       0x8
#define set_rtc_aon_Reg0x0_rtc_tick_int_en(val)                 addrtc_aon_Reg0x0 = ((addrtc_aon_Reg0x0 & (~0x8)) | ((val) << 3))
#define setf_rtc_aon_Reg0x0_rtc_tick_int_en                     addrtc_aon_Reg0x0 |= 0x8
#define clrf_rtc_aon_Reg0x0_rtc_tick_int_en                     addrtc_aon_Reg0x0 &= ~0x8
#define get_rtc_aon_Reg0x0_rtc_tick_int_en                      ((addrtc_aon_Reg0x0 & 0x8) >> 3)

#define posrtc_aon_Reg0x0_rtc_aon_int_en                        2
#define bitrtc_aon_Reg0x0_rtc_aon_int_en                        0x4
#define set_rtc_aon_Reg0x0_rtc_aon_int_en(val)                  addrtc_aon_Reg0x0 = ((addrtc_aon_Reg0x0 & (~0x4)) | ((val) << 2))
#define setf_rtc_aon_Reg0x0_rtc_aon_int_en                      addrtc_aon_Reg0x0 |= 0x4
#define clrf_rtc_aon_Reg0x0_rtc_aon_int_en                      addrtc_aon_Reg0x0 &= ~0x4
#define get_rtc_aon_Reg0x0_rtc_aon_int_en                       ((addrtc_aon_Reg0x0 & 0x4) >> 2)

#define posrtc_aon_Reg0x0_rtc_cnt_stop                          1
#define bitrtc_aon_Reg0x0_rtc_cnt_stop                          0x2
#define set_rtc_aon_Reg0x0_rtc_cnt_stop(val)                    addrtc_aon_Reg0x0 = ((addrtc_aon_Reg0x0 & (~0x2)) | ((val) << 1))
#define setf_rtc_aon_Reg0x0_rtc_cnt_stop                        addrtc_aon_Reg0x0 |= 0x2
#define clrf_rtc_aon_Reg0x0_rtc_cnt_stop                        addrtc_aon_Reg0x0 &= ~0x2
#define get_rtc_aon_Reg0x0_rtc_cnt_stop                         ((addrtc_aon_Reg0x0 & 0x2) >> 1)

#define posrtc_aon_Reg0x0_rtc_cnt_reset                         0
#define bitrtc_aon_Reg0x0_rtc_cnt_reset                         0x1
#define set_rtc_aon_Reg0x0_rtc_cnt_reset(val)                   addrtc_aon_Reg0x0 = ((addrtc_aon_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_rtc_aon_Reg0x0_rtc_cnt_reset                       addrtc_aon_Reg0x0 |= 0x1
#define clrf_rtc_aon_Reg0x0_rtc_cnt_reset                       addrtc_aon_Reg0x0 &= ~0x1
#define get_rtc_aon_Reg0x0_rtc_cnt_reset                        (addrtc_aon_Reg0x0 & 0x1)

//addrtc_aon_Reg0x1
#define addrtc_aon_Reg0x1                                       *((volatile unsigned long *) (0x00800900+0x1*4))

//addrtc_aon_Reg0x2
#define addrtc_aon_Reg0x2                                       *((volatile unsigned long *) (0x00800900+0x2*4))

//addrtc_aon_Reg0x3
#define addrtc_aon_Reg0x3                                       *((volatile unsigned long *) (0x00800900+0x3*4))


//************************************************************//
//AON_GPIO
//************************************************************//
#define BASEADDR_AON_GPIO                                       0x00800A00
//addAON_GPIO_Reg0x0
#define addAON_GPIO_Reg0x0                                      *((volatile unsigned long *) (0x00800A00+0x0*4))
#define posAON_GPIO_Reg0x0_GPIO0_Config                         0
#define bitAON_GPIO_Reg0x0_GPIO0_Config                         0x3FF
#define set_AON_GPIO_Reg0x0_GPIO0_Config(val)                   addAON_GPIO_Reg0x0 = ((addAON_GPIO_Reg0x0 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x0_GPIO0_Config                        (addAON_GPIO_Reg0x0 & 0x3FF)

#define posAON_GPIO_Reg0x0_GPIO_Input                           0
#define bitAON_GPIO_Reg0x0_GPIO_Input                           0x1
#define get_AON_GPIO_Reg0x0_GPIO_Input                          (addAON_GPIO_Reg0x0 & 0x1)

#define posAON_GPIO_Reg0x0_GPIO_Output                          1
#define bitAON_GPIO_Reg0x0_GPIO_Output                          0x2
#define set_AON_GPIO_Reg0x0_GPIO_Output(val)                    addAON_GPIO_Reg0x0 = ((addAON_GPIO_Reg0x0 & (~0x2)) | ((val) << 1))
#define setf_AON_GPIO_Reg0x0_GPIO_Output                        addAON_GPIO_Reg0x0 |= 0x2
#define clrf_AON_GPIO_Reg0x0_GPIO_Output                        addAON_GPIO_Reg0x0 &= ~0x2
#define get_AON_GPIO_Reg0x0_GPIO_Output                         ((addAON_GPIO_Reg0x0 & 0x2) >> 1)

#define posAON_GPIO_Reg0x0_GPIO_Input_Ena                       2
#define bitAON_GPIO_Reg0x0_GPIO_Input_Ena                       0x4
#define set_AON_GPIO_Reg0x0_GPIO_Input_Ena(val)                 addAON_GPIO_Reg0x0 = ((addAON_GPIO_Reg0x0 & (~0x4)) | ((val) << 2))
#define setf_AON_GPIO_Reg0x0_GPIO_Input_Ena                     addAON_GPIO_Reg0x0 |= 0x4
#define clrf_AON_GPIO_Reg0x0_GPIO_Input_Ena                     addAON_GPIO_Reg0x0 &= ~0x4
#define get_AON_GPIO_Reg0x0_GPIO_Input_Ena                      ((addAON_GPIO_Reg0x0 & 0x4) >> 2)

#define posAON_GPIO_Reg0x0_GPIO_Output_Ena                      3
#define bitAON_GPIO_Reg0x0_GPIO_Output_Ena                      0x8
#define set_AON_GPIO_Reg0x0_GPIO_Output_Ena(val)                addAON_GPIO_Reg0x0 = ((addAON_GPIO_Reg0x0 & (~0x8)) | ((val) << 3))
#define setf_AON_GPIO_Reg0x0_GPIO_Output_Ena                    addAON_GPIO_Reg0x0 |= 0x8
#define clrf_AON_GPIO_Reg0x0_GPIO_Output_Ena                    addAON_GPIO_Reg0x0 &= ~0x8
#define get_AON_GPIO_Reg0x0_GPIO_Output_Ena                     ((addAON_GPIO_Reg0x0 & 0x8) >> 3)

#define posAON_GPIO_Reg0x0_GPIO_Pull_Mode                       4
#define bitAON_GPIO_Reg0x0_GPIO_Pull_Mode                       0x10
#define set_AON_GPIO_Reg0x0_GPIO_Pull_Mode(val)                 addAON_GPIO_Reg0x0 = ((addAON_GPIO_Reg0x0 & (~0x10)) | ((val) << 4))
#define setf_AON_GPIO_Reg0x0_GPIO_Pull_Mode                     addAON_GPIO_Reg0x0 |= 0x10
#define clrf_AON_GPIO_Reg0x0_GPIO_Pull_Mode                     addAON_GPIO_Reg0x0 &= ~0x10
#define get_AON_GPIO_Reg0x0_GPIO_Pull_Mode                      ((addAON_GPIO_Reg0x0 & 0x10) >> 4)

#define posAON_GPIO_Reg0x0_GPIO_Pull_Ena                        5
#define bitAON_GPIO_Reg0x0_GPIO_Pull_Ena                        0x20
#define set_AON_GPIO_Reg0x0_GPIO_Pull_Ena(val)                  addAON_GPIO_Reg0x0 = ((addAON_GPIO_Reg0x0 & (~0x20)) | ((val) << 5))
#define setf_AON_GPIO_Reg0x0_GPIO_Pull_Ena                      addAON_GPIO_Reg0x0 |= 0x20
#define clrf_AON_GPIO_Reg0x0_GPIO_Pull_Ena                      addAON_GPIO_Reg0x0 &= ~0x20
#define get_AON_GPIO_Reg0x0_GPIO_Pull_Ena                       ((addAON_GPIO_Reg0x0 & 0x20) >> 5)

#define posAON_GPIO_Reg0x0_GPIO_Fun_Ena                         6
#define bitAON_GPIO_Reg0x0_GPIO_Fun_Ena                         0x40
#define set_AON_GPIO_Reg0x0_GPIO_Fun_Ena(val)                   addAON_GPIO_Reg0x0 = ((addAON_GPIO_Reg0x0 & (~0x40)) | ((val) << 6))
#define setf_AON_GPIO_Reg0x0_GPIO_Fun_Ena                       addAON_GPIO_Reg0x0 |= 0x40
#define clrf_AON_GPIO_Reg0x0_GPIO_Fun_Ena                       addAON_GPIO_Reg0x0 &= ~0x40
#define get_AON_GPIO_Reg0x0_GPIO_Fun_Ena                        ((addAON_GPIO_Reg0x0 & 0x40) >> 6)

#define posAON_GPIO_Reg0x0_Input_Monitor                        7
#define bitAON_GPIO_Reg0x0_Input_Monitor                        0x80
#define set_AON_GPIO_Reg0x0_Input_Monitor(val)                  addAON_GPIO_Reg0x0 = ((addAON_GPIO_Reg0x0 & (~0x80)) | ((val) << 7))
#define setf_AON_GPIO_Reg0x0_Input_Monitor                      addAON_GPIO_Reg0x0 |= 0x80
#define clrf_AON_GPIO_Reg0x0_Input_Monitor                      addAON_GPIO_Reg0x0 &= ~0x80
#define get_AON_GPIO_Reg0x0_Input_Monitor                       ((addAON_GPIO_Reg0x0 & 0x80) >> 7)

#define posAON_GPIO_Reg0x0_GPIO_Capacity                        8
#define bitAON_GPIO_Reg0x0_GPIO_Capacity                        0x300
#define set_AON_GPIO_Reg0x0_GPIO_Capacity(val)                  addAON_GPIO_Reg0x0 = ((addAON_GPIO_Reg0x0 & (~0x300)) | ((val) << 8))
#define get_AON_GPIO_Reg0x0_GPIO_Capacity                       ((addAON_GPIO_Reg0x0 & 0x300) >> 8)

//addAON_GPIO_Reg0x1
#define addAON_GPIO_Reg0x1                                      *((volatile unsigned long *) (0x00800A00+0x1*4))
#define posAON_GPIO_Reg0x1_GPIO1_Config                         0
#define bitAON_GPIO_Reg0x1_GPIO1_Config                         0x3FF
#define set_AON_GPIO_Reg0x1_GPIO1_Config(val)                   addAON_GPIO_Reg0x1 = ((addAON_GPIO_Reg0x1 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x1_GPIO1_Config                        (addAON_GPIO_Reg0x1 & 0x3FF)

//addAON_GPIO_Reg0x2
#define addAON_GPIO_Reg0x2                                      *((volatile unsigned long *) (0x00800A00+0x2*4))
#define posAON_GPIO_Reg0x2_GPIO2_Config                         0
#define bitAON_GPIO_Reg0x2_GPIO2_Config                         0x3FF
#define set_AON_GPIO_Reg0x2_GPIO2_Config(val)                   addAON_GPIO_Reg0x2 = ((addAON_GPIO_Reg0x2 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x2_GPIO2_Config                        (addAON_GPIO_Reg0x2 & 0x3FF)

//addAON_GPIO_Reg0x3
#define addAON_GPIO_Reg0x3                                      *((volatile unsigned long *) (0x00800A00+0x3*4))
#define posAON_GPIO_Reg0x3_GPIO3_Config                         0
#define bitAON_GPIO_Reg0x3_GPIO3_Config                         0x3FF
#define set_AON_GPIO_Reg0x3_GPIO3_Config(val)                   addAON_GPIO_Reg0x3 = ((addAON_GPIO_Reg0x3 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x3_GPIO3_Config                        (addAON_GPIO_Reg0x3 & 0x3FF)

//addAON_GPIO_Reg0x4
#define addAON_GPIO_Reg0x4                                      *((volatile unsigned long *) (0x00800A00+0x4*4))
#define posAON_GPIO_Reg0x4_GPIO4_Config                         0
#define bitAON_GPIO_Reg0x4_GPIO4_Config                         0x3FF
#define set_AON_GPIO_Reg0x4_GPIO4_Config(val)                   addAON_GPIO_Reg0x4 = ((addAON_GPIO_Reg0x4 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x4_GPIO4_Config                        (addAON_GPIO_Reg0x4 & 0x3FF)

//addAON_GPIO_Reg0x5
#define addAON_GPIO_Reg0x5                                      *((volatile unsigned long *) (0x00800A00+0x5*4))
#define posAON_GPIO_Reg0x5_GPIO5_Config                         0
#define bitAON_GPIO_Reg0x5_GPIO5_Config                         0x3FF
#define set_AON_GPIO_Reg0x5_GPIO5_Config(val)                   addAON_GPIO_Reg0x5 = ((addAON_GPIO_Reg0x5 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x5_GPIO5_Config                        (addAON_GPIO_Reg0x5 & 0x3FF)

//addAON_GPIO_Reg0x6
#define addAON_GPIO_Reg0x6                                      *((volatile unsigned long *) (0x00800A00+0x6*4))
#define posAON_GPIO_Reg0x6_GPIO6_Config                         0
#define bitAON_GPIO_Reg0x6_GPIO6_Config                         0x3FF
#define set_AON_GPIO_Reg0x6_GPIO6_Config(val)                   addAON_GPIO_Reg0x6 = ((addAON_GPIO_Reg0x6 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x6_GPIO6_Config                        (addAON_GPIO_Reg0x6 & 0x3FF)

//addAON_GPIO_Reg0x7
#define addAON_GPIO_Reg0x7                                      *((volatile unsigned long *) (0x00800A00+0x7*4))
#define posAON_GPIO_Reg0x7_GPIO7_Config                         0
#define bitAON_GPIO_Reg0x7_GPIO7_Config                         0x3FF
#define set_AON_GPIO_Reg0x7_GPIO7_Config(val)                   addAON_GPIO_Reg0x7 = ((addAON_GPIO_Reg0x7 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x7_GPIO7_Config                        (addAON_GPIO_Reg0x7 & 0x3FF)

//addAON_GPIO_Reg0x8
#define addAON_GPIO_Reg0x8                                      *((volatile unsigned long *) (0x00800A00+0x8*4))
#define posAON_GPIO_Reg0x8_GPIO8_Config                         0
#define bitAON_GPIO_Reg0x8_GPIO8_Config                         0x3FF
#define set_AON_GPIO_Reg0x8_GPIO8_Config(val)                   addAON_GPIO_Reg0x8 = ((addAON_GPIO_Reg0x8 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x8_GPIO8_Config                        (addAON_GPIO_Reg0x8 & 0x3FF)

//addAON_GPIO_Reg0x9
#define addAON_GPIO_Reg0x9                                      *((volatile unsigned long *) (0x00800A00+0x9*4))
#define posAON_GPIO_Reg0x9_GPIO9_Config                         0
#define bitAON_GPIO_Reg0x9_GPIO9_Config                         0x3FF
#define set_AON_GPIO_Reg0x9_GPIO9_Config(val)                   addAON_GPIO_Reg0x9 = ((addAON_GPIO_Reg0x9 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x9_GPIO9_Config                        (addAON_GPIO_Reg0x9 & 0x3FF)

//addAON_GPIO_Reg0xa
#define addAON_GPIO_Reg0xa                                      *((volatile unsigned long *) (0x00800A00+0xa*4))
#define posAON_GPIO_Reg0xa_GPIO10_Config                        0
#define bitAON_GPIO_Reg0xa_GPIO10_Config                        0x3FF
#define set_AON_GPIO_Reg0xa_GPIO10_Config(val)                  addAON_GPIO_Reg0xa = ((addAON_GPIO_Reg0xa & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0xa_GPIO10_Config                       (addAON_GPIO_Reg0xa & 0x3FF)

//addAON_GPIO_Reg0xb
#define addAON_GPIO_Reg0xb                                      *((volatile unsigned long *) (0x00800A00+0xb*4))
#define posAON_GPIO_Reg0xb_GPIO11_Config                        0
#define bitAON_GPIO_Reg0xb_GPIO11_Config                        0x3FF
#define set_AON_GPIO_Reg0xb_GPIO11_Config(val)                  addAON_GPIO_Reg0xb = ((addAON_GPIO_Reg0xb & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0xb_GPIO11_Config                       (addAON_GPIO_Reg0xb & 0x3FF)

//addAON_GPIO_Reg0xc
#define addAON_GPIO_Reg0xc                                      *((volatile unsigned long *) (0x00800A00+0xc*4))
#define posAON_GPIO_Reg0xc_GPIO12_Config                        0
#define bitAON_GPIO_Reg0xc_GPIO12_Config                        0x3FF
#define set_AON_GPIO_Reg0xc_GPIO12_Config(val)                  addAON_GPIO_Reg0xc = ((addAON_GPIO_Reg0xc & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0xc_GPIO12_Config                       (addAON_GPIO_Reg0xc & 0x3FF)

//addAON_GPIO_Reg0xd
#define addAON_GPIO_Reg0xd                                      *((volatile unsigned long *) (0x00800A00+0xd*4))
#define posAON_GPIO_Reg0xd_GPIO13_Config                        0
#define bitAON_GPIO_Reg0xd_GPIO13_Config                        0x3FF
#define set_AON_GPIO_Reg0xd_GPIO13_Config(val)                  addAON_GPIO_Reg0xd = ((addAON_GPIO_Reg0xd & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0xd_GPIO13_Config                       (addAON_GPIO_Reg0xd & 0x3FF)

//addAON_GPIO_Reg0xe
#define addAON_GPIO_Reg0xe                                      *((volatile unsigned long *) (0x00800A00+0xe*4))
#define posAON_GPIO_Reg0xe_GPIO14_Config                        0
#define bitAON_GPIO_Reg0xe_GPIO14_Config                        0x3FF
#define set_AON_GPIO_Reg0xe_GPIO14_Config(val)                  addAON_GPIO_Reg0xe = ((addAON_GPIO_Reg0xe & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0xe_GPIO14_Config                       (addAON_GPIO_Reg0xe & 0x3FF)

//addAON_GPIO_Reg0xf
#define addAON_GPIO_Reg0xf                                      *((volatile unsigned long *) (0x00800A00+0xf*4))
#define posAON_GPIO_Reg0xf_GPIO15_Config                        0
#define bitAON_GPIO_Reg0xf_GPIO15_Config                        0x3FF
#define set_AON_GPIO_Reg0xf_GPIO15_Config(val)                  addAON_GPIO_Reg0xf = ((addAON_GPIO_Reg0xf & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0xf_GPIO15_Config                       (addAON_GPIO_Reg0xf & 0x3FF)

//addAON_GPIO_Reg0x10
#define addAON_GPIO_Reg0x10                                     *((volatile unsigned long *) (0x00800A00+0x10*4))
#define posAON_GPIO_Reg0x10_GPIO16_Config                       0
#define bitAON_GPIO_Reg0x10_GPIO16_Config                       0x3FF
#define set_AON_GPIO_Reg0x10_GPIO16_Config(val)                 addAON_GPIO_Reg0x10 = ((addAON_GPIO_Reg0x10 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x10_GPIO16_Config                      (addAON_GPIO_Reg0x10 & 0x3FF)

//addAON_GPIO_Reg0x11
#define addAON_GPIO_Reg0x11                                     *((volatile unsigned long *) (0x00800A00+0x11*4))
#define posAON_GPIO_Reg0x11_GPIO17_Config                       0
#define bitAON_GPIO_Reg0x11_GPIO17_Config                       0x3FF
#define set_AON_GPIO_Reg0x11_GPIO17_Config(val)                 addAON_GPIO_Reg0x11 = ((addAON_GPIO_Reg0x11 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x11_GPIO17_Config                      (addAON_GPIO_Reg0x11 & 0x3FF)

//addAON_GPIO_Reg0x12
#define addAON_GPIO_Reg0x12                                     *((volatile unsigned long *) (0x00800A00+0x12*4))
#define posAON_GPIO_Reg0x12_GPIO18_Config                       0
#define bitAON_GPIO_Reg0x12_GPIO18_Config                       0x3FF
#define set_AON_GPIO_Reg0x12_GPIO18_Config(val)                 addAON_GPIO_Reg0x12 = ((addAON_GPIO_Reg0x12 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x12_GPIO18_Config                      (addAON_GPIO_Reg0x12 & 0x3FF)

//addAON_GPIO_Reg0x13
#define addAON_GPIO_Reg0x13                                     *((volatile unsigned long *) (0x00800A00+0x13*4))
#define posAON_GPIO_Reg0x13_GPIO19_Config                       0
#define bitAON_GPIO_Reg0x13_GPIO19_Config                       0x3FF
#define set_AON_GPIO_Reg0x13_GPIO19_Config(val)                 addAON_GPIO_Reg0x13 = ((addAON_GPIO_Reg0x13 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x13_GPIO19_Config                      (addAON_GPIO_Reg0x13 & 0x3FF)

//addAON_GPIO_Reg0x14
#define addAON_GPIO_Reg0x14                                     *((volatile unsigned long *) (0x00800A00+0x14*4))
#define posAON_GPIO_Reg0x14_GPIO20_Config                       0
#define bitAON_GPIO_Reg0x14_GPIO20_Config                       0x3FF
#define set_AON_GPIO_Reg0x14_GPIO20_Config(val)                 addAON_GPIO_Reg0x14 = ((addAON_GPIO_Reg0x14 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x14_GPIO20_Config                      (addAON_GPIO_Reg0x14 & 0x3FF)

//addAON_GPIO_Reg0x15
#define addAON_GPIO_Reg0x15                                     *((volatile unsigned long *) (0x00800A00+0x15*4))
#define posAON_GPIO_Reg0x15_GPIO21_Config                       0
#define bitAON_GPIO_Reg0x15_GPIO21_Config                       0x3FF
#define set_AON_GPIO_Reg0x15_GPIO21_Config(val)                 addAON_GPIO_Reg0x15 = ((addAON_GPIO_Reg0x15 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x15_GPIO21_Config                      (addAON_GPIO_Reg0x15 & 0x3FF)

//addAON_GPIO_Reg0x16
#define addAON_GPIO_Reg0x16                                     *((volatile unsigned long *) (0x00800A00+0x16*4))
#define posAON_GPIO_Reg0x16_GPIO22_Config                       0
#define bitAON_GPIO_Reg0x16_GPIO22_Config                       0x3FF
#define set_AON_GPIO_Reg0x16_GPIO22_Config(val)                 addAON_GPIO_Reg0x16 = ((addAON_GPIO_Reg0x16 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x16_GPIO22_Config                      (addAON_GPIO_Reg0x16 & 0x3FF)

//addAON_GPIO_Reg0x17
#define addAON_GPIO_Reg0x17                                     *((volatile unsigned long *) (0x00800A00+0x17*4))
#define posAON_GPIO_Reg0x17_GPIO23_Config                       0
#define bitAON_GPIO_Reg0x17_GPIO23_Config                       0x3FF
#define set_AON_GPIO_Reg0x17_GPIO23_Config(val)                 addAON_GPIO_Reg0x17 = ((addAON_GPIO_Reg0x17 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x17_GPIO23_Config                      (addAON_GPIO_Reg0x17 & 0x3FF)

//addAON_GPIO_Reg0x18
#define addAON_GPIO_Reg0x18                                     *((volatile unsigned long *) (0x00800A00+0x18*4))
#define posAON_GPIO_Reg0x18_GPIO24_Config                       0
#define bitAON_GPIO_Reg0x18_GPIO24_Config                       0x3FF
#define set_AON_GPIO_Reg0x18_GPIO24_Config(val)                 addAON_GPIO_Reg0x18 = ((addAON_GPIO_Reg0x18 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x18_GPIO24_Config                      (addAON_GPIO_Reg0x18 & 0x3FF)

//addAON_GPIO_Reg0x19
#define addAON_GPIO_Reg0x19                                     *((volatile unsigned long *) (0x00800A00+0x19*4))
#define posAON_GPIO_Reg0x19_GPIO25_Config                       0
#define bitAON_GPIO_Reg0x19_GPIO25_Config                       0x3FF
#define set_AON_GPIO_Reg0x19_GPIO25_Config(val)                 addAON_GPIO_Reg0x19 = ((addAON_GPIO_Reg0x19 & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x19_GPIO25_Config                      (addAON_GPIO_Reg0x19 & 0x3FF)

//addAON_GPIO_Reg0x1a
#define addAON_GPIO_Reg0x1a                                     *((volatile unsigned long *) (0x00800A00+0x1a*4))
#define posAON_GPIO_Reg0x1a_GPIO26_Config                       0
#define bitAON_GPIO_Reg0x1a_GPIO26_Config                       0x3FF
#define set_AON_GPIO_Reg0x1a_GPIO26_Config(val)                 addAON_GPIO_Reg0x1a = ((addAON_GPIO_Reg0x1a & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x1a_GPIO26_Config                      (addAON_GPIO_Reg0x1a & 0x3FF)

//addAON_GPIO_Reg0x1b
#define addAON_GPIO_Reg0x1b                                     *((volatile unsigned long *) (0x00800A00+0x1b*4))
#define posAON_GPIO_Reg0x1b_GPIO27_Config                       0
#define bitAON_GPIO_Reg0x1b_GPIO27_Config                       0x3FF
#define set_AON_GPIO_Reg0x1b_GPIO27_Config(val)                 addAON_GPIO_Reg0x1b = ((addAON_GPIO_Reg0x1b & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x1b_GPIO27_Config                      (addAON_GPIO_Reg0x1b & 0x3FF)

//addAON_GPIO_Reg0x1c
#define addAON_GPIO_Reg0x1c                                     *((volatile unsigned long *) (0x00800A00+0x1c*4))
#define posAON_GPIO_Reg0x1c_GPIO28_Config                       0
#define bitAON_GPIO_Reg0x1c_GPIO28_Config                       0x3FF
#define set_AON_GPIO_Reg0x1c_GPIO28_Config(val)                 addAON_GPIO_Reg0x1c = ((addAON_GPIO_Reg0x1c & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x1c_GPIO28_Config                      (addAON_GPIO_Reg0x1c & 0x3FF)

//addAON_GPIO_Reg0x1d
#define addAON_GPIO_Reg0x1d                                     *((volatile unsigned long *) (0x00800A00+0x1d*4))
#define posAON_GPIO_Reg0x1d_GPIO29_Config                       0
#define bitAON_GPIO_Reg0x1d_GPIO29_Config                       0x3FF
#define set_AON_GPIO_Reg0x1d_GPIO29_Config(val)                 addAON_GPIO_Reg0x1d = ((addAON_GPIO_Reg0x1d & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x1d_GPIO29_Config                      (addAON_GPIO_Reg0x1d & 0x3FF)

//addAON_GPIO_Reg0x1e
#define addAON_GPIO_Reg0x1e                                     *((volatile unsigned long *) (0x00800A00+0x1e*4))
#define posAON_GPIO_Reg0x1e_GPIO30_Config                       0
#define bitAON_GPIO_Reg0x1e_GPIO30_Config                       0x3FF
#define set_AON_GPIO_Reg0x1e_GPIO30_Config(val)                 addAON_GPIO_Reg0x1e = ((addAON_GPIO_Reg0x1e & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x1e_GPIO30_Config                      (addAON_GPIO_Reg0x1e & 0x3FF)

//addAON_GPIO_Reg0x1f
#define addAON_GPIO_Reg0x1f                                     *((volatile unsigned long *) (0x00800A00+0x1f*4))
#define posAON_GPIO_Reg0x1f_GPIO31_Config                       0
#define bitAON_GPIO_Reg0x1f_GPIO31_Config                       0x3FF
#define set_AON_GPIO_Reg0x1f_GPIO31_Config(val)                 addAON_GPIO_Reg0x1f = ((addAON_GPIO_Reg0x1f & (~0x3FF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x1f_GPIO31_Config                      (addAON_GPIO_Reg0x1f & 0x3FF)

//addAON_GPIO_Reg0x30
#define addAON_GPIO_Reg0x30                                     *((volatile unsigned long *) (0x00800A00+0x30*4))

//addAON_GPIO_Reg0x31
#define addAON_GPIO_Reg0x31                                     *((volatile unsigned long *) (0x00800A00+0x31*4))

//addAON_GPIO_Reg0x32
#define addAON_GPIO_Reg0x32                                     *((volatile unsigned long *) (0x00800A00+0x32*4))

#define posAON_GPIO_Reg0x32_int_type3                           0
#define bitAON_GPIO_Reg0x32_int_type3                           0xFFFF
#define set_AON_GPIO_Reg0x32_int_type3(val)                     addAON_GPIO_Reg0x32 = ((addAON_GPIO_Reg0x32 & (~0xFFFF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x32_int_type3                          (addAON_GPIO_Reg0x32 & 0xFFFF)

//addAON_GPIO_Reg0x33
#define addAON_GPIO_Reg0x33                                     *((volatile unsigned long *) (0x00800A00+0x33*4))

//addAON_GPIO_Reg0x34
#define addAON_GPIO_Reg0x34                                     *((volatile unsigned long *) (0x00800A00+0x34*4))

#define posAON_GPIO_Reg0x34_int_en2                             0
#define bitAON_GPIO_Reg0x34_int_en2                             0xFF
#define set_AON_GPIO_Reg0x34_int_en2(val)                       addAON_GPIO_Reg0x34 = ((addAON_GPIO_Reg0x34 & (~0xFF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x34_int_en2                            (addAON_GPIO_Reg0x34 & 0xFF)

//addAON_GPIO_Reg0x35
#define addAON_GPIO_Reg0x35                                     *((volatile unsigned long *) (0x00800A00+0x35*4))

//addAON_GPIO_Reg0x36
#define addAON_GPIO_Reg0x36                                     *((volatile unsigned long *) (0x00800A00+0x36*4))

#define posAON_GPIO_Reg0x36_intsta2                             0
#define bitAON_GPIO_Reg0x36_intsta2                             0xFF
#define set_AON_GPIO_Reg0x36_intsta2(val)                       addAON_GPIO_Reg0x36 = ((addAON_GPIO_Reg0x36 & (~0xFF)) | ((val) << 0))
#define get_AON_GPIO_Reg0x36_intsta2                            (addAON_GPIO_Reg0x36 & 0xFF)


//************************************************************//
//AON_WDT
//************************************************************//
#define BASEADDR_AON_WDT                                        0x00800c00
//addAON_WDT_Reg0x0
#define addAON_WDT_Reg0x0                                       *((volatile unsigned long *) (0x00800c00+0x0*4))





#define posAON_WDT_Reg0x0_deep_enable                           1
#define bitAON_WDT_Reg0x0_deep_enable                           0x2
#define set_AON_WDT_Reg0x0_deep_enable(val)                     addAON_WDT_Reg0x0 = ((addAON_WDT_Reg0x0 & (~0x2)) | ((val) << 1))
#define setf_AON_WDT_Reg0x0_deep_enable                         addAON_WDT_Reg0x0 |= 0x2
#define clrf_AON_WDT_Reg0x0_deep_enable                         addAON_WDT_Reg0x0 &= ~0x2
#define get_AON_WDT_Reg0x0_deep_enable                          ((addAON_WDT_Reg0x0 & 0x2) >> 1)

#define posAON_WDT_Reg0x0_idle_enable                           0
#define bitAON_WDT_Reg0x0_idle_enable                           0x1
#define set_AON_WDT_Reg0x0_idle_enable(val)                     addAON_WDT_Reg0x0 = ((addAON_WDT_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_AON_WDT_Reg0x0_idle_enable                         addAON_WDT_Reg0x0 |= 0x1
#define clrf_AON_WDT_Reg0x0_idle_enable                         addAON_WDT_Reg0x0 &= ~0x1
#define get_AON_WDT_Reg0x0_idle_enable                          (addAON_WDT_Reg0x0 & 0x1)

//addAON_WDT_Reg0x1
#define addAON_WDT_Reg0x1                                       *((volatile unsigned long *) (0x00800c00+0x1*4))
#define posAON_WDT_Reg0x1_aon_wdt_feed                          0
#define bitAON_WDT_Reg0x1_aon_wdt_feed                          0xFF
#define set_AON_WDT_Reg0x1_aon_wdt_feed(val)                    addAON_WDT_Reg0x1 = ((addAON_WDT_Reg0x1 & (~0xFF)) | ((val) << 0))
#define get_AON_WDT_Reg0x1_aon_wdt_feed                         (addAON_WDT_Reg0x1 & 0xFF)

//addAON_WDT_Reg0x2
#define addAON_WDT_Reg0x2                                       *((volatile unsigned long *) (0x00800c00+0x2*4))
#define posAON_WDT_Reg0x2_aon_wdt_period                        0
#define bitAON_WDT_Reg0x2_aon_wdt_period                        0xFFFFFF
#define set_AON_WDT_Reg0x2_aon_wdt_period(val)                  addAON_WDT_Reg0x2 = ((addAON_WDT_Reg0x2 & (~0xFFFFFF)) | ((val) << 0))
#define get_AON_WDT_Reg0x2_aon_wdt_period                       (addAON_WDT_Reg0x2 & 0xFFFFFF)

//************************************************************//
//CLK_EST
//************************************************************//
#define BASEADDR_CLK_EST                                        0x00800d00
//addCLK_EST_Reg0x0
#define addCLK_EST_Reg0x0                                       *((volatile unsigned long *) (0x00800d00+0x0*4))
#define posCLK_EST_Reg0x0_ckes_enable                           0
#define bitCLK_EST_Reg0x0_ckes_enable                           0x1
#define set_CLK_EST_Reg0x0_ckes_enable(val)                     addCLK_EST_Reg0x0 = ((addCLK_EST_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_CLK_EST_Reg0x0_ckes_enable                         addCLK_EST_Reg0x0 |= 0x1
#define clrf_CLK_EST_Reg0x0_ckes_enable                         addCLK_EST_Reg0x0 &= ~0x1
#define get_CLK_EST_Reg0x0_ckes_enable                          (addCLK_EST_Reg0x0 & 0x1)

//addCLK_EST_Reg0x1
#define addCLK_EST_Reg0x1                                       *((volatile unsigned long *) (0x00800d00+0x1*4))
#define posCLK_EST_Reg0x1_intr_mask                             12
#define bitCLK_EST_Reg0x1_intr_mask                             0x1000
#define set_CLK_EST_Reg0x1_intr_mask(val)                       addCLK_EST_Reg0x1 = ((addCLK_EST_Reg0x1 & (~0x1000)) | ((val) << 12))
#define setf_CLK_EST_Reg0x1_intr_mask                           addCLK_EST_Reg0x1 |= 0x1000
#define clrf_CLK_EST_Reg0x1_intr_mask                           addCLK_EST_Reg0x1 &= ~0x1000
#define get_CLK_EST_Reg0x1_intr_mask                            ((addCLK_EST_Reg0x1 & 0x1000) >> 12)

#define posCLK_EST_Reg0x1_ckes_config                           0
#define bitCLK_EST_Reg0x1_ckes_config                           0x3FF
#define set_CLK_EST_Reg0x1_ckes_config(val)                     addCLK_EST_Reg0x1 = ((addCLK_EST_Reg0x1 & (~0x3FF)) | ((val) << 0))
#define get_CLK_EST_Reg0x1_ckes_config                          (addCLK_EST_Reg0x1 & 0x3FF)

//addCLK_EST_Reg0x2
#define addCLK_EST_Reg0x2                                       *((volatile unsigned long *) (0x00800d00+0x2*4))
#define posCLK_EST_Reg0x2_intr_status                           0
#define bitCLK_EST_Reg0x2_intr_status                           0x1
#define set_CLK_EST_Reg0x2_intr_status(val)                     addCLK_EST_Reg0x2 = ((addCLK_EST_Reg0x2 & (~0x1)) | ((val) << 0))
#define setf_CLK_EST_Reg0x2_intr_status                         addCLK_EST_Reg0x2 |= 0x1
#define clrf_CLK_EST_Reg0x2_intr_status                         addCLK_EST_Reg0x2 &= ~0x1
#define get_CLK_EST_Reg0x2_intr_status                          (addCLK_EST_Reg0x2 & 0x1)

//addCLK_EST_Reg0x3
#define addCLK_EST_Reg0x3                                       *((volatile unsigned long *) (0x00800d00+0x3*4))
#define posCLK_EST_Reg0x3_ckes_number                           0
#define bitCLK_EST_Reg0x3_ckes_number                           0xFFFFF
#define set_CLK_EST_Reg0x3_ckes_number(val)                     addCLK_EST_Reg0x3 = ((addCLK_EST_Reg0x3 & (~0xFFFFF)) | ((val) << 0))
#define get_CLK_EST_Reg0x3_ckes_number                          (addCLK_EST_Reg0x3 & 0xFFFFF)

//************************************************************//
//FLASH
//************************************************************//
#define BASEADDR_FLASH                                          0x00802000
//addFLASH_Reg0x0
#define addFLASH_Reg0x0                                         *((volatile unsigned long *) (0x00802000+0x0*4))
#define posFLASH_Reg0x0_addr_sw_reg                             0
#define bitFLASH_Reg0x0_addr_sw_reg                             0xFFFFFF
#define set_FLASH_Reg0x0_addr_sw_reg(val)                       addFLASH_Reg0x0 = ((addFLASH_Reg0x0 & (~0xFFFFFF)) | ((val) << 0))
#define get_FLASH_Reg0x0_addr_sw_reg                            (addFLASH_Reg0x0 & 0xFFFFFF)

#define posFLASH_Reg0x0_op_type_sw                              24
#define bitFLASH_Reg0x0_op_type_sw                              0x1F000000
#define set_FLASH_Reg0x0_op_type_sw(val)                        addFLASH_Reg0x0 = ((addFLASH_Reg0x0 & (~0x1F000000)) | ((val) << 24))
#define get_FLASH_Reg0x0_op_type_sw                             ((addFLASH_Reg0x0 & 0x1F000000) >> 24)

#define posFLASH_Reg0x0_op_sw                                   29
#define bitFLASH_Reg0x0_op_sw                                   0x20000000
#define set_FLASH_Reg0x0_op_sw(val)                             addFLASH_Reg0x0 = ((addFLASH_Reg0x0 & (~0x20000000)) | ((val) << 29))
#define setf_FLASH_Reg0x0_op_sw                                 addFLASH_Reg0x0 |= 0x20000000
#define clrf_FLASH_Reg0x0_op_sw                                 addFLASH_Reg0x0 &= ~0x20000000
#define get_FLASH_Reg0x0_op_sw                                  ((addFLASH_Reg0x0 & 0x20000000) >> 29)

#define posFLASH_Reg0x0_wp_value                                30
#define bitFLASH_Reg0x0_wp_value                                0x40000000
#define set_FLASH_Reg0x0_wp_value(val)                          addFLASH_Reg0x0 = ((addFLASH_Reg0x0 & (~0x40000000)) | ((val) << 30))
#define setf_FLASH_Reg0x0_wp_value                              addFLASH_Reg0x0 |= 0x40000000
#define clrf_FLASH_Reg0x0_wp_value                              addFLASH_Reg0x0 &= ~0x40000000
#define get_FLASH_Reg0x0_wp_value                               ((addFLASH_Reg0x0 & 0x40000000) >> 30)

#define posFLASH_Reg0x0_busy_sw                                 31
#define bitFLASH_Reg0x0_busy_sw                                 0x80000000
#define get_FLASH_Reg0x0_busy_sw                                ((addFLASH_Reg0x0 & 0x80000000) >> 31)

//addFLASH_Reg0x1
#define addFLASH_Reg0x1                                         *((volatile unsigned long *) (0x00802000+0x1*4))

//addFLASH_Reg0x2
#define addFLASH_Reg0x2                                         *((volatile unsigned long *) (0x00802000+0x2*4))

//addFLASH_Reg0x3
#define addFLASH_Reg0x3                                         *((volatile unsigned long *) (0x00802000+0x3*4))

//addFLASH_Reg0x4
#define addFLASH_Reg0x4                                         *((volatile unsigned long *) (0x00802000+0x4*4))

//addFLASH_Reg0x5
#define addFLASH_Reg0x5                                         *((volatile unsigned long *) (0x00802000+0x5*4))
#define posFLASH_Reg0x5_sr_data_flash                           0
#define bitFLASH_Reg0x5_sr_data_flash                           0xFF
#define get_FLASH_Reg0x5_sr_data_flash                          (addFLASH_Reg0x5 & 0xFF)

#define posFLASH_Reg0x5_crc_err_counter                         8
#define bitFLASH_Reg0x5_crc_err_counter                         0xFF00
#define get_FLASH_Reg0x5_crc_err_counter                        ((addFLASH_Reg0x5 & 0xFF00) >> 8)

#define posFLASH_Reg0x5_data_flash_sw_sel                       16
#define bitFLASH_Reg0x5_data_flash_sw_sel                       0x70000
#define get_FLASH_Reg0x5_data_flash_sw_sel                      ((addFLASH_Reg0x5 & 0x70000) >> 16)

#define posFLASH_Reg0x5_data_sw_flash_sel                       19
#define bitFLASH_Reg0x5_data_sw_flash_sel                       0x380000
#define get_FLASH_Reg0x5_data_sw_flash_sel                      ((addFLASH_Reg0x5 & 0x380000) >> 19)

#define posFLASH_Reg0x5_m_value                                 22
#define bitFLASH_Reg0x5_m_value                                 0x3FC00000
#define set_FLASH_Reg0x5_m_value(val)                           addFLASH_Reg0x5 = ((addFLASH_Reg0x5 & (~0x3FC00000)) | ((val) << 22))
#define get_FLASH_Reg0x5_m_value                                ((addFLASH_Reg0x5 & 0x3FC00000) >> 22)

#define posFLASH_Reg0x5_pw_write                                30
#define bitFLASH_Reg0x5_pw_write                                0x40000000
#define set_FLASH_Reg0x5_pw_write(val)                          addFLASH_Reg0x5 = ((addFLASH_Reg0x5 & (~0x40000000)) | ((val) << 30))
#define setf_FLASH_Reg0x5_pw_write                              addFLASH_Reg0x5 |= 0x40000000
#define clrf_FLASH_Reg0x5_pw_write                              addFLASH_Reg0x5 &= ~0x40000000
#define get_FLASH_Reg0x5_pw_write                               ((addFLASH_Reg0x5 & 0x40000000) >> 30)

//addFLASH_Reg0x6
#define addFLASH_Reg0x6                                         *((volatile unsigned long *) (0x00802000+0x6*4))

//addFLASH_Reg0x7
#define addFLASH_Reg0x7                                         *((volatile unsigned long *) (0x00802000+0x7*4))
#define posFLASH_Reg0x7_flash_clk_conf                          0
#define bitFLASH_Reg0x7_flash_clk_conf                          0xF
#define set_FLASH_Reg0x7_flash_clk_conf(val)                    addFLASH_Reg0x7 = ((addFLASH_Reg0x7 & (~0xF)) | ((val) << 0))
#define get_FLASH_Reg0x7_flash_clk_conf                         (addFLASH_Reg0x7 & 0xF)

#define posFLASH_Reg0x7_mode_sel                                4
#define bitFLASH_Reg0x7_mode_sel                                0x1F0
#define set_FLASH_Reg0x7_mode_sel(val)                          addFLASH_Reg0x7 = ((addFLASH_Reg0x7 & (~0x1F0)) | ((val) << 4))
#define get_FLASH_Reg0x7_mode_sel                               ((addFLASH_Reg0x7 & 0x1F0) >> 4)

#define posFLASH_Reg0x7_fwren_flash_cpu                         9
#define bitFLASH_Reg0x7_fwren_flash_cpu                         0x200
#define set_FLASH_Reg0x7_fwren_flash_cpu(val)                   addFLASH_Reg0x7 = ((addFLASH_Reg0x7 & (~0x200)) | ((val) << 9))
#define setf_FLASH_Reg0x7_fwren_flash_cpu                       addFLASH_Reg0x7 |= 0x200
#define clrf_FLASH_Reg0x7_fwren_flash_cpu                       addFLASH_Reg0x7 &= ~0x200
#define get_FLASH_Reg0x7_fwren_flash_cpu                        ((addFLASH_Reg0x7 & 0x200) >> 9)

#define posFLASH_Reg0x7_wrsr_data                               10
#define bitFLASH_Reg0x7_wrsr_data                               0x3FFFC00
#define set_FLASH_Reg0x7_wrsr_data(val)                         addFLASH_Reg0x7 = ((addFLASH_Reg0x7 & (~0x3FFFC00)) | ((val) << 10))
#define get_FLASH_Reg0x7_wrsr_data                              ((addFLASH_Reg0x7 & 0x3FFFC00) >> 10)

#define posFLASH_Reg0x7_crc_en                                  26
#define bitFLASH_Reg0x7_crc_en                                  0x4000000
#define set_FLASH_Reg0x7_crc_en(val)                            addFLASH_Reg0x7 = ((addFLASH_Reg0x7 & (~0x4000000)) | ((val) << 26))
#define setf_FLASH_Reg0x7_crc_en                                addFLASH_Reg0x7 |= 0x4000000
#define clrf_FLASH_Reg0x7_crc_en                                addFLASH_Reg0x7 &= ~0x4000000
#define get_FLASH_Reg0x7_crc_en                                 ((addFLASH_Reg0x7 & 0x4000000) >> 26)

//addFLASH_Reg0x8
#define addFLASH_Reg0x8                                         *((volatile unsigned long *) (0x00802000+0x8*4))
#define posFLASH_Reg0x8_dpd_fbd                                 24
#define bitFLASH_Reg0x8_dpd_fbd                                 0x1000000
#define set_FLASH_Reg0x8_dpd_fbd(val)                           addFLASH_Reg0x8 = ((addFLASH_Reg0x8 & (~0x1000000)) | ((val) << 24))
#define setf_FLASH_Reg0x8_dpd_fbd                               addFLASH_Reg0x8 |= 0x1000000
#define clrf_FLASH_Reg0x8_dpd_fbd                               addFLASH_Reg0x8 &= ~0x1000000
#define get_FLASH_Reg0x8_dpd_fbd                                ((addFLASH_Reg0x8 & 0x1000000) >> 24)

#define posFLASH_Reg0x8_tdp_tdpdd_delay_cnt                     12
#define bitFLASH_Reg0x8_tdp_tdpdd_delay_cnt                     0xFFF000
#define set_FLASH_Reg0x8_tdp_tdpdd_delay_cnt(val)               addFLASH_Reg0x8 = ((addFLASH_Reg0x8 & (~0xFFF000)) | ((val) << 12))
#define get_FLASH_Reg0x8_tdp_tdpdd_delay_cnt                    ((addFLASH_Reg0x8 & 0xFFF000) >> 12)

#define posFLASH_Reg0x8_tres1_trdp_delay_cnt                    0
#define bitFLASH_Reg0x8_tres1_trdp_delay_cnt                    0xFFF
#define set_FLASH_Reg0x8_tres1_trdp_delay_cnt(val)              addFLASH_Reg0x8 = ((addFLASH_Reg0x8 & (~0xFFF)) | ((val) << 0))
#define get_FLASH_Reg0x8_tres1_trdp_delay_cnt                   (addFLASH_Reg0x8 & 0xFFF)

//addFLASH_Reg0x9
#define addFLASH_Reg0x9                                         *((volatile unsigned long *) (0x00802000+0x9*4))
#define posFLASH_Reg0x9_mem_addr_clr                            31
#define bitFLASH_Reg0x9_mem_addr_clr                            0x80000000
#define set_FLASH_Reg0x9_mem_addr_clr(val)                      addFLASH_Reg0x9 = ((addFLASH_Reg0x9 & (~0x80000000)) | ((val) << 31))
#define setf_FLASH_Reg0x9_mem_addr_clr                          addFLASH_Reg0x9 |= 0x80000000
#define clrf_FLASH_Reg0x9_mem_addr_clr                          addFLASH_Reg0x9 &= ~0x80000000
#define get_FLASH_Reg0x9_mem_addr_clr                           ((addFLASH_Reg0x9 & 0x80000000) >> 31)

#define posFLASH_Reg0x9_mem_data                                0
#define bitFLASH_Reg0x9_mem_data                                0xFF
#define set_FLASH_Reg0x9_mem_data(val)                          addFLASH_Reg0x9 = ((addFLASH_Reg0x9 & (~0xFF)) | ((val) << 0))
#define get_FLASH_Reg0x9_mem_data                               (addFLASH_Reg0x9 & 0xFF)


//************************************************************//
//GENER_DMA
//************************************************************//
#define BASEADDR_GENER_DMA                                      0x00803000
//addGENER_DMA_Reg0x0
#define addGENER_DMA_Reg0x0                                     *((volatile unsigned long *) (0x00803000+0x0*4))
#define posGENER_DMA_Reg0x0_trans_len                           16
#define bitGENER_DMA_Reg0x0_trans_len                           0xFFFF0000
#define set_GENER_DMA_Reg0x0_trans_len(val)                     addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0xFFFF0000)) | ((val) << 16))
#define get_GENER_DMA_Reg0x0_trans_len                          ((addGENER_DMA_Reg0x0 & 0xFFFF0000) >> 16)


#define posGENER_DMA_Reg0x0_chn_prioprity                       12
#define bitGENER_DMA_Reg0x0_chn_prioprity                       0x7000
#define set_GENER_DMA_Reg0x0_chn_prioprity(val)                 addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0x7000)) | ((val) << 12))
#define get_GENER_DMA_Reg0x0_chn_prioprity                      ((addGENER_DMA_Reg0x0 & 0x7000) >> 12)

#define posGENER_DMA_Reg0x0_dest_addr_loop                      11
#define bitGENER_DMA_Reg0x0_dest_addr_loop                      0x800
#define set_GENER_DMA_Reg0x0_dest_addr_loop(val)                addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0x800)) | ((val) << 11))
#define setf_GENER_DMA_Reg0x0_dest_addr_loop                    addGENER_DMA_Reg0x0 |= 0x800
#define clrf_GENER_DMA_Reg0x0_dest_addr_loop                    addGENER_DMA_Reg0x0 &= ~0x800
#define get_GENER_DMA_Reg0x0_dest_addr_loop                     ((addGENER_DMA_Reg0x0 & 0x800) >> 11)

#define posGENER_DMA_Reg0x0_src_addr_loop                       10
#define bitGENER_DMA_Reg0x0_src_addr_loop                       0x400
#define set_GENER_DMA_Reg0x0_src_addr_loop(val)                 addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0x400)) | ((val) << 10))
#define setf_GENER_DMA_Reg0x0_src_addr_loop                     addGENER_DMA_Reg0x0 |= 0x400
#define clrf_GENER_DMA_Reg0x0_src_addr_loop                     addGENER_DMA_Reg0x0 &= ~0x400
#define get_GENER_DMA_Reg0x0_src_addr_loop                      ((addGENER_DMA_Reg0x0 & 0x400) >> 10)

#define posGENER_DMA_Reg0x0_dest_addr_inc                       9
#define bitGENER_DMA_Reg0x0_dest_addr_inc                       0x200
#define set_GENER_DMA_Reg0x0_dest_addr_inc(val)                 addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0x200)) | ((val) << 9))
#define setf_GENER_DMA_Reg0x0_dest_addr_inc                     addGENER_DMA_Reg0x0 |= 0x200
#define clrf_GENER_DMA_Reg0x0_dest_addr_inc                     addGENER_DMA_Reg0x0 &= ~0x200
#define get_GENER_DMA_Reg0x0_dest_addr_inc                      ((addGENER_DMA_Reg0x0 & 0x200) >> 9)

#define posGENER_DMA_Reg0x0_src_addr_inc                        8
#define bitGENER_DMA_Reg0x0_src_addr_inc                        0x100
#define set_GENER_DMA_Reg0x0_src_addr_inc(val)                  addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0x100)) | ((val) << 8))
#define setf_GENER_DMA_Reg0x0_src_addr_inc                      addGENER_DMA_Reg0x0 |= 0x100
#define clrf_GENER_DMA_Reg0x0_src_addr_inc                      addGENER_DMA_Reg0x0 &= ~0x100
#define get_GENER_DMA_Reg0x0_src_addr_inc                       ((addGENER_DMA_Reg0x0 & 0x100) >> 8)

#define posGENER_DMA_Reg0x0_dest_data_width                     6
#define bitGENER_DMA_Reg0x0_dest_data_width                     0xC0
#define set_GENER_DMA_Reg0x0_dest_data_width(val)               addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0xC0)) | ((val) << 6))
#define get_GENER_DMA_Reg0x0_dest_data_width                    ((addGENER_DMA_Reg0x0 & 0xC0) >> 6)

#define posGENER_DMA_Reg0x0_src_data_width                      4
#define bitGENER_DMA_Reg0x0_src_data_width                      0x30
#define set_GENER_DMA_Reg0x0_src_data_width(val)                addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0x30)) | ((val) << 4))
#define get_GENER_DMA_Reg0x0_src_data_width                     ((addGENER_DMA_Reg0x0 & 0x30) >> 4)

#define posGENER_DMA_Reg0x0_dma_mode                            3
#define bitGENER_DMA_Reg0x0_dma_mode                            0x8
#define set_GENER_DMA_Reg0x0_dma_mode(val)                      addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0x8)) | ((val) << 3))
#define setf_GENER_DMA_Reg0x0_dma_mode                          addGENER_DMA_Reg0x0 |= 0x8
#define clrf_GENER_DMA_Reg0x0_dma_mode                          addGENER_DMA_Reg0x0 &= ~0x8
#define get_GENER_DMA_Reg0x0_dma_mode                           ((addGENER_DMA_Reg0x0 & 0x8) >> 3)

#define posGENER_DMA_Reg0x0_half_finish_inten                   2
#define bitGENER_DMA_Reg0x0_half_finish_inten                   0x4
#define set_GENER_DMA_Reg0x0_half_finish_inten(val)             addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0x4)) | ((val) << 2))
#define setf_GENER_DMA_Reg0x0_half_finish_inten                 addGENER_DMA_Reg0x0 |= 0x4
#define clrf_GENER_DMA_Reg0x0_half_finish_inten                 addGENER_DMA_Reg0x0 &= ~0x4
#define get_GENER_DMA_Reg0x0_half_finish_inten                  ((addGENER_DMA_Reg0x0 & 0x4) >> 2)

#define posGENER_DMA_Reg0x0_finish_inten                        1
#define bitGENER_DMA_Reg0x0_finish_inten                        0x2
#define set_GENER_DMA_Reg0x0_finish_inten(val)                  addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0x2)) | ((val) << 1))
#define setf_GENER_DMA_Reg0x0_finish_inten                      addGENER_DMA_Reg0x0 |= 0x2
#define clrf_GENER_DMA_Reg0x0_finish_inten                      addGENER_DMA_Reg0x0 &= ~0x2
#define get_GENER_DMA_Reg0x0_finish_inten                       ((addGENER_DMA_Reg0x0 & 0x2) >> 1)

#define posGENER_DMA_Reg0x0_dma_en                              0
#define bitGENER_DMA_Reg0x0_dma_en                              0x1
#define set_GENER_DMA_Reg0x0_dma_en(val)                        addGENER_DMA_Reg0x0 = ((addGENER_DMA_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_GENER_DMA_Reg0x0_dma_en                            addGENER_DMA_Reg0x0 |= 0x1
#define clrf_GENER_DMA_Reg0x0_dma_en                            addGENER_DMA_Reg0x0 &= ~0x1
#define get_GENER_DMA_Reg0x0_dma_en                             (addGENER_DMA_Reg0x0 & 0x1)

//addGENER_DMA_Reg0x1
#define addGENER_DMA_Reg0x1                                     *((volatile unsigned long *) (0x00803000+0x1*4))

//addGENER_DMA_Reg0x2
#define addGENER_DMA_Reg0x2                                     *((volatile unsigned long *) (0x00803000+0x2*4))

//addGENER_DMA_Reg0x3
#define addGENER_DMA_Reg0x3                                     *((volatile unsigned long *) (0x00803000+0x3*4))

//addGENER_DMA_Reg0x4
#define addGENER_DMA_Reg0x4                                     *((volatile unsigned long *) (0x00803000+0x4*4))

//addGENER_DMA_Reg0x5
#define addGENER_DMA_Reg0x5                                     *((volatile unsigned long *) (0x00803000+0x5*4))

//addGENER_DMA_Reg0x6
#define addGENER_DMA_Reg0x6                                     *((volatile unsigned long *) (0x00803000+0x6*4))

//addGENER_DMA_Reg0x7
#define addGENER_DMA_Reg0x7                                     *((volatile unsigned long *) (0x00803000+0x7*4))

#define posGENER_DMA_Reg0x7_dest_wr_intlv                       16
#define bitGENER_DMA_Reg0x7_dest_wr_intlv                       0xF0000
#define set_GENER_DMA_Reg0x7_dest_wr_intlv(val)                 addGENER_DMA_Reg0x7 = ((addGENER_DMA_Reg0x7 & (~0xF0000)) | ((val) << 16))
#define get_GENER_DMA_Reg0x7_dest_wr_intlv                      ((addGENER_DMA_Reg0x7 & 0xF0000) >> 16)

#define posGENER_DMA_Reg0x7_src_rd_intlv                        12
#define bitGENER_DMA_Reg0x7_src_rd_intlv                        0xF000
#define set_GENER_DMA_Reg0x7_src_rd_intlv(val)                  addGENER_DMA_Reg0x7 = ((addGENER_DMA_Reg0x7 & (~0xF000)) | ((val) << 12))
#define get_GENER_DMA_Reg0x7_src_rd_intlv                       ((addGENER_DMA_Reg0x7 & 0xF000) >> 12)


#define posGENER_DMA_Reg0x7_dest_req_mux                        5
#define bitGENER_DMA_Reg0x7_dest_req_mux                        0x3E0
#define set_GENER_DMA_Reg0x7_dest_req_mux(val)                  addGENER_DMA_Reg0x7 = ((addGENER_DMA_Reg0x7 & (~0x3E0)) | ((val) << 5))
#define get_GENER_DMA_Reg0x7_dest_req_mux                       ((addGENER_DMA_Reg0x7 & 0x3E0) >> 5)

#define posGENER_DMA_Reg0x7_src_req_mux                         0
#define bitGENER_DMA_Reg0x7_src_req_mux                         0x1F
#define set_GENER_DMA_Reg0x7_src_req_mux(val)                   addGENER_DMA_Reg0x7 = ((addGENER_DMA_Reg0x7 & (~0x1F)) | ((val) << 0))
#define get_GENER_DMA_Reg0x7_src_req_mux                        (addGENER_DMA_Reg0x7 & 0x1F)

//addGENER_DMA_Reg0x8
#define addGENER_DMA_Reg0x8                                     *((volatile unsigned long *) (0x00803000+0x8*4))

//addGENER_DMA_Reg0x9
#define addGENER_DMA_Reg0x9                                     *((volatile unsigned long *) (0x00803000+0x9*4))

//addGENER_DMA_Reg0xa
#define addGENER_DMA_Reg0xa                                     *((volatile unsigned long *) (0x00803000+0xa*4))

//addGENER_DMA_Reg0xb
#define addGENER_DMA_Reg0xb                                     *((volatile unsigned long *) (0x00803000+0xb*4))

//addGENER_DMA_Reg0xc
#define addGENER_DMA_Reg0xc                                     *((volatile unsigned long *) (0x00803000+0xc*4))

//addGENER_DMA_Reg0xd
#define addGENER_DMA_Reg0xd                                     *((volatile unsigned long *) (0x00803000+0xd*4))

//addGENER_DMA_Reg0xe
#define addGENER_DMA_Reg0xe                                     *((volatile unsigned long *) (0x00803000+0xe*4))

//addGENER_DMA_Reg0xf
#define addGENER_DMA_Reg0xf                                     *((volatile unsigned long *) (0x00803000+0xf*4))

//addGENER_DMA_Reg0x10
#define addGENER_DMA_Reg0x10                                    *((volatile unsigned long *) (0x00803000+0x10*4))

//addGENER_DMA_Reg0x11
#define addGENER_DMA_Reg0x11                                    *((volatile unsigned long *) (0x00803000+0x11*4))

//addGENER_DMA_Reg0x12
#define addGENER_DMA_Reg0x12                                    *((volatile unsigned long *) (0x00803000+0x12*4))

//addGENER_DMA_Reg0x13
#define addGENER_DMA_Reg0x13                                    *((volatile unsigned long *) (0x00803000+0x13*4))

//addGENER_DMA_Reg0x14
#define addGENER_DMA_Reg0x14                                    *((volatile unsigned long *) (0x00803000+0x14*4))

//addGENER_DMA_Reg0x15
#define addGENER_DMA_Reg0x15                                    *((volatile unsigned long *) (0x00803000+0x15*4))

//addGENER_DMA_Reg0x16
#define addGENER_DMA_Reg0x16                                    *((volatile unsigned long *) (0x00803000+0x16*4))

//addGENER_DMA_Reg0x17
#define addGENER_DMA_Reg0x17                                    *((volatile unsigned long *) (0x00803000+0x17*4))

//addGENER_DMA_Reg0x18
#define addGENER_DMA_Reg0x18                                    *((volatile unsigned long *) (0x00803000+0x18*4))

//addGENER_DMA_Reg0x19
#define addGENER_DMA_Reg0x19                                    *((volatile unsigned long *) (0x00803000+0x19*4))

//addGENER_DMA_Reg0x1a
#define addGENER_DMA_Reg0x1a                                    *((volatile unsigned long *) (0x00803000+0x1a*4))

//addGENER_DMA_Reg0x1b
#define addGENER_DMA_Reg0x1b                                    *((volatile unsigned long *) (0x00803000+0x1b*4))

//addGENER_DMA_Reg0x1c
#define addGENER_DMA_Reg0x1c                                    *((volatile unsigned long *) (0x00803000+0x1c*4))

//addGENER_DMA_Reg0x1d
#define addGENER_DMA_Reg0x1d                                    *((volatile unsigned long *) (0x00803000+0x1d*4))

//addGENER_DMA_Reg0x1e
#define addGENER_DMA_Reg0x1e                                    *((volatile unsigned long *) (0x00803000+0x1e*4))

//addGENER_DMA_Reg0x1f
#define addGENER_DMA_Reg0x1f                                    *((volatile unsigned long *) (0x00803000+0x1f*4))

//addGENER_DMA_Reg0x20
#define addGENER_DMA_Reg0x20                                    *((volatile unsigned long *) (0x00803000+0x20*4))

//addGENER_DMA_Reg0x21
#define addGENER_DMA_Reg0x21                                    *((volatile unsigned long *) (0x00803000+0x21*4))

//addGENER_DMA_Reg0x22
#define addGENER_DMA_Reg0x22                                    *((volatile unsigned long *) (0x00803000+0x22*4))

//addGENER_DMA_Reg0x23
#define addGENER_DMA_Reg0x23                                    *((volatile unsigned long *) (0x00803000+0x23*4))

//addGENER_DMA_Reg0x24
#define addGENER_DMA_Reg0x24                                    *((volatile unsigned long *) (0x00803000+0x24*4))

//addGENER_DMA_Reg0x25
#define addGENER_DMA_Reg0x25                                    *((volatile unsigned long *) (0x00803000+0x25*4))

//addGENER_DMA_Reg0x26
#define addGENER_DMA_Reg0x26                                    *((volatile unsigned long *) (0x00803000+0x26*4))

//addGENER_DMA_Reg0x27
#define addGENER_DMA_Reg0x27                                    *((volatile unsigned long *) (0x00803000+0x27*4))

//addGENER_DMA_Reg0x28
#define addGENER_DMA_Reg0x28                                    *((volatile unsigned long *) (0x00803000+0x28*4))

//addGENER_DMA_Reg0x29
#define addGENER_DMA_Reg0x29                                    *((volatile unsigned long *) (0x00803000+0x29*4))

//addGENER_DMA_Reg0x2a
#define addGENER_DMA_Reg0x2a                                    *((volatile unsigned long *) (0x00803000+0x2a*4))

//addGENER_DMA_Reg0x2b
#define addGENER_DMA_Reg0x2b                                    *((volatile unsigned long *) (0x00803000+0x2b*4))

//addGENER_DMA_Reg0x2c
#define addGENER_DMA_Reg0x2c                                    *((volatile unsigned long *) (0x00803000+0x2c*4))

//addGENER_DMA_Reg0x2d
#define addGENER_DMA_Reg0x2d                                    *((volatile unsigned long *) (0x00803000+0x2d*4))

//addGENER_DMA_Reg0x2e
#define addGENER_DMA_Reg0x2e                                    *((volatile unsigned long *) (0x00803000+0x2e*4))

//addGENER_DMA_Reg0x2f
#define addGENER_DMA_Reg0x2f                                    *((volatile unsigned long *) (0x00803000+0x2f*4))

//addGENER_DMA_Reg0x30
#define addGENER_DMA_Reg0x30                                    *((volatile unsigned long *) (0x00803000+0x30*4))

//addGENER_DMA_Reg0x31
#define addGENER_DMA_Reg0x31                                    *((volatile unsigned long *) (0x00803000+0x31*4))

//addGENER_DMA_Reg0x32
#define addGENER_DMA_Reg0x32                                    *((volatile unsigned long *) (0x00803000+0x32*4))

//addGENER_DMA_Reg0x33
#define addGENER_DMA_Reg0x33                                    *((volatile unsigned long *) (0x00803000+0x33*4))

//addGENER_DMA_Reg0x34
#define addGENER_DMA_Reg0x34                                    *((volatile unsigned long *) (0x00803000+0x34*4))

//addGENER_DMA_Reg0x35
#define addGENER_DMA_Reg0x35                                    *((volatile unsigned long *) (0x00803000+0x35*4))

//addGENER_DMA_Reg0x36
#define addGENER_DMA_Reg0x36                                    *((volatile unsigned long *) (0x00803000+0x36*4))

//addGENER_DMA_Reg0x37
#define addGENER_DMA_Reg0x37                                    *((volatile unsigned long *) (0x00803000+0x37*4))

//addGENER_DMA_Reg0x38
#define addGENER_DMA_Reg0x38                                    *((volatile unsigned long *) (0x00803000+0x38*4))

//addGENER_DMA_Reg0x39
#define addGENER_DMA_Reg0x39                                    *((volatile unsigned long *) (0x00803000+0x39*4))

//addGENER_DMA_Reg0x3a
#define addGENER_DMA_Reg0x3a                                    *((volatile unsigned long *) (0x00803000+0x3a*4))

//addGENER_DMA_Reg0x3b
#define addGENER_DMA_Reg0x3b                                    *((volatile unsigned long *) (0x00803000+0x3b*4))

//addGENER_DMA_Reg0x3c
#define addGENER_DMA_Reg0x3c                                    *((volatile unsigned long *) (0x00803000+0x3c*4))

//addGENER_DMA_Reg0x3d
#define addGENER_DMA_Reg0x3d                                    *((volatile unsigned long *) (0x00803000+0x3d*4))

//addGENER_DMA_Reg0x3e
#define addGENER_DMA_Reg0x3e                                    *((volatile unsigned long *) (0x00803000+0x3e*4))

//addGENER_DMA_Reg0x3f
#define addGENER_DMA_Reg0x3f                                    *((volatile unsigned long *) (0x00803000+0x3f*4))

//addGENER_DMA_Reg0x40
#define addGENER_DMA_Reg0x40                                    *((volatile unsigned long *) (0x00803000+0x40*4))

//addGENER_DMA_Reg0x41
#define addGENER_DMA_Reg0x41                                    *((volatile unsigned long *) (0x00803000+0x41*4))

//addGENER_DMA_Reg0x42
#define addGENER_DMA_Reg0x42                                    *((volatile unsigned long *) (0x00803000+0x42*4))

//addGENER_DMA_Reg0x43
#define addGENER_DMA_Reg0x43                                    *((volatile unsigned long *) (0x00803000+0x43*4))

//addGENER_DMA_Reg0x44
#define addGENER_DMA_Reg0x44                                    *((volatile unsigned long *) (0x00803000+0x44*4))

//addGENER_DMA_Reg0x45
#define addGENER_DMA_Reg0x45                                    *((volatile unsigned long *) (0x00803000+0x45*4))

//addGENER_DMA_Reg0x46
#define addGENER_DMA_Reg0x46                                    *((volatile unsigned long *) (0x00803000+0x46*4))

//addGENER_DMA_Reg0x47
#define addGENER_DMA_Reg0x47                                    *((volatile unsigned long *) (0x00803000+0x47*4))

//addGENER_DMA_Reg0x48
#define addGENER_DMA_Reg0x48                                    *((volatile unsigned long *) (0x00803000+0x48*4))

//addGENER_DMA_Reg0x49
#define addGENER_DMA_Reg0x49                                    *((volatile unsigned long *) (0x00803000+0x49*4))

//addGENER_DMA_Reg0x4a
#define addGENER_DMA_Reg0x4a                                    *((volatile unsigned long *) (0x00803000+0x4a*4))

//addGENER_DMA_Reg0x4b
#define addGENER_DMA_Reg0x4b                                    *((volatile unsigned long *) (0x00803000+0x4b*4))

//addGENER_DMA_Reg0x4c
#define addGENER_DMA_Reg0x4c                                    *((volatile unsigned long *) (0x00803000+0x4c*4))

//addGENER_DMA_Reg0x4d
#define addGENER_DMA_Reg0x4d                                    *((volatile unsigned long *) (0x00803000+0x4d*4))

//addGENER_DMA_Reg0x4e
#define addGENER_DMA_Reg0x4e                                    *((volatile unsigned long *) (0x00803000+0x4e*4))

//addGENER_DMA_Reg0x4f
#define addGENER_DMA_Reg0x4f                                    *((volatile unsigned long *) (0x00803000+0x4f*4))

//addGENER_DMA_Reg0x50
#define addGENER_DMA_Reg0x50                                    *((volatile unsigned long *) (0x00803000+0x50*4))

//addGENER_DMA_Reg0x51
#define addGENER_DMA_Reg0x51                                    *((volatile unsigned long *) (0x00803000+0x51*4))

//addGENER_DMA_Reg0x52
#define addGENER_DMA_Reg0x52                                    *((volatile unsigned long *) (0x00803000+0x52*4))

//addGENER_DMA_Reg0x53
#define addGENER_DMA_Reg0x53                                    *((volatile unsigned long *) (0x00803000+0x53*4))

//addGENER_DMA_Reg0x54
#define addGENER_DMA_Reg0x54                                    *((volatile unsigned long *) (0x00803000+0x54*4))

//addGENER_DMA_Reg0x55
#define addGENER_DMA_Reg0x55                                    *((volatile unsigned long *) (0x00803000+0x55*4))

//addGENER_DMA_Reg0x56
#define addGENER_DMA_Reg0x56                                    *((volatile unsigned long *) (0x00803000+0x56*4))

//addGENER_DMA_Reg0x57
#define addGENER_DMA_Reg0x57                                    *((volatile unsigned long *) (0x00803000+0x57*4))

//addGENER_DMA_Reg0x58
#define addGENER_DMA_Reg0x58                                    *((volatile unsigned long *) (0x00803000+0x58*4))

//addGENER_DMA_Reg0x59
#define addGENER_DMA_Reg0x59                                    *((volatile unsigned long *) (0x00803000+0x59*4))

//addGENER_DMA_Reg0x5a
#define addGENER_DMA_Reg0x5a                                    *((volatile unsigned long *) (0x00803000+0x5a*4))

//addGENER_DMA_Reg0x5b
#define addGENER_DMA_Reg0x5b                                    *((volatile unsigned long *) (0x00803000+0x5b*4))

//addGENER_DMA_Reg0x5c
#define addGENER_DMA_Reg0x5c                                    *((volatile unsigned long *) (0x00803000+0x5c*4))

//addGENER_DMA_Reg0x5d
#define addGENER_DMA_Reg0x5d                                    *((volatile unsigned long *) (0x00803000+0x5d*4))

//addGENER_DMA_Reg0x5e
#define addGENER_DMA_Reg0x5e                                    *((volatile unsigned long *) (0x00803000+0x5e*4))

//addGENER_DMA_Reg0x5f
#define addGENER_DMA_Reg0x5f                                    *((volatile unsigned long *) (0x00803000+0x5f*4))

//addGENER_DMA_Reg0x60
#define addGENER_DMA_Reg0x60                                    *((volatile unsigned long *) (0x00803000+0x60*4))

//addGENER_DMA_Reg0x61
#define addGENER_DMA_Reg0x61                                    *((volatile unsigned long *) (0x00803000+0x61*4))

//addGENER_DMA_Reg0x62
#define addGENER_DMA_Reg0x62                                    *((volatile unsigned long *) (0x00803000+0x62*4))

//addGENER_DMA_Reg0x63
#define addGENER_DMA_Reg0x63                                    *((volatile unsigned long *) (0x00803000+0x63*4))

//addGENER_DMA_Reg0x64
#define addGENER_DMA_Reg0x64                                    *((volatile unsigned long *) (0x00803000+0x64*4))

//addGENER_DMA_Reg0x65
#define addGENER_DMA_Reg0x65                                    *((volatile unsigned long *) (0x00803000+0x65*4))

//addGENER_DMA_Reg0x66
#define addGENER_DMA_Reg0x66                                    *((volatile unsigned long *) (0x00803000+0x66*4))

//addGENER_DMA_Reg0x67
#define addGENER_DMA_Reg0x67                                    *((volatile unsigned long *) (0x00803000+0x67*4))

//addGENER_DMA_Reg0x68
#define addGENER_DMA_Reg0x68                                    *((volatile unsigned long *) (0x00803000+0x68*4))

//addGENER_DMA_Reg0x69
#define addGENER_DMA_Reg0x69                                    *((volatile unsigned long *) (0x00803000+0x69*4))

//addGENER_DMA_Reg0x6a
#define addGENER_DMA_Reg0x6a                                    *((volatile unsigned long *) (0x00803000+0x6a*4))

//addGENER_DMA_Reg0x6b
#define addGENER_DMA_Reg0x6b                                    *((volatile unsigned long *) (0x00803000+0x6b*4))

//addGENER_DMA_Reg0x6c
#define addGENER_DMA_Reg0x6c                                    *((volatile unsigned long *) (0x00803000+0x6c*4))

//addGENER_DMA_Reg0x6d
#define addGENER_DMA_Reg0x6d                                    *((volatile unsigned long *) (0x00803000+0x6d*4))

//addGENER_DMA_Reg0x6e
#define addGENER_DMA_Reg0x6e                                    *((volatile unsigned long *) (0x00803000+0x6e*4))

//addGENER_DMA_Reg0x6f
#define addGENER_DMA_Reg0x6f                                    *((volatile unsigned long *) (0x00803000+0x6f*4))

//addGENER_DMA_Reg0x70
#define addGENER_DMA_Reg0x70                                    *((volatile unsigned long *) (0x00803000+0x70*4))

//addGENER_DMA_Reg0x71
#define addGENER_DMA_Reg0x71                                    *((volatile unsigned long *) (0x00803000+0x71*4))

//addGENER_DMA_Reg0x72
#define addGENER_DMA_Reg0x72                                    *((volatile unsigned long *) (0x00803000+0x72*4))

//addGENER_DMA_Reg0x73
#define addGENER_DMA_Reg0x73                                    *((volatile unsigned long *) (0x00803000+0x73*4))

//addGENER_DMA_Reg0x74
#define addGENER_DMA_Reg0x74                                    *((volatile unsigned long *) (0x00803000+0x74*4))

//addGENER_DMA_Reg0x75
#define addGENER_DMA_Reg0x75                                    *((volatile unsigned long *) (0x00803000+0x75*4))

//addGENER_DMA_Reg0x76
#define addGENER_DMA_Reg0x76                                    *((volatile unsigned long *) (0x00803000+0x76*4))

//addGENER_DMA_Reg0x77
#define addGENER_DMA_Reg0x77                                    *((volatile unsigned long *) (0x00803000+0x77*4))

//addGENER_DMA_Reg0x78
#define addGENER_DMA_Reg0x78                                    *((volatile unsigned long *) (0x00803000+0x78*4))

//addGENER_DMA_Reg0x79
#define addGENER_DMA_Reg0x79                                    *((volatile unsigned long *) (0x00803000+0x79*4))

//addGENER_DMA_Reg0x7a
#define addGENER_DMA_Reg0x7a                                    *((volatile unsigned long *) (0x00803000+0x7a*4))

//addGENER_DMA_Reg0x7b
#define addGENER_DMA_Reg0x7b                                    *((volatile unsigned long *) (0x00803000+0x7b*4))

//addGENER_DMA_Reg0x7c
#define addGENER_DMA_Reg0x7c                                    *((volatile unsigned long *) (0x00803000+0x7c*4))

//addGENER_DMA_Reg0x7d
#define addGENER_DMA_Reg0x7d                                    *((volatile unsigned long *) (0x00803000+0x7d*4))

//addGENER_DMA_Reg0x7e
#define addGENER_DMA_Reg0x7e                                    *((volatile unsigned long *) (0x00803000+0x7e*4))

//addGENER_DMA_Reg0x7f
#define addGENER_DMA_Reg0x7f                                    *((volatile unsigned long *) (0x00803000+0x7f*4))

//addGENER_DMA_Reg0x80
#define addGENER_DMA_Reg0x80                                    *((volatile unsigned long *) (0x00803000+0x80*4))

//addGENER_DMA_Reg0x81
#define addGENER_DMA_Reg0x81                                    *((volatile unsigned long *) (0x00803000+0x81*4))

//addGENER_DMA_Reg0x82
#define addGENER_DMA_Reg0x82                                    *((volatile unsigned long *) (0x00803000+0x82*4))

//addGENER_DMA_Reg0x83
#define addGENER_DMA_Reg0x83                                    *((volatile unsigned long *) (0x00803000+0x83*4))

//addGENER_DMA_Reg0x84
#define addGENER_DMA_Reg0x84                                    *((volatile unsigned long *) (0x00803000+0x84*4))

//addGENER_DMA_Reg0x85
#define addGENER_DMA_Reg0x85                                    *((volatile unsigned long *) (0x00803000+0x85*4))

//addGENER_DMA_Reg0x86
#define addGENER_DMA_Reg0x86                                    *((volatile unsigned long *) (0x00803000+0x86*4))

//addGENER_DMA_Reg0x87
#define addGENER_DMA_Reg0x87                                    *((volatile unsigned long *) (0x00803000+0x87*4))

//addGENER_DMA_Reg0x88
#define addGENER_DMA_Reg0x88                                    *((volatile unsigned long *) (0x00803000+0x88*4))

//addGENER_DMA_Reg0x89
#define addGENER_DMA_Reg0x89                                    *((volatile unsigned long *) (0x00803000+0x89*4))

//addGENER_DMA_Reg0x8a
#define addGENER_DMA_Reg0x8a                                    *((volatile unsigned long *) (0x00803000+0x8a*4))

//addGENER_DMA_Reg0x8b
#define addGENER_DMA_Reg0x8b                                    *((volatile unsigned long *) (0x00803000+0x8b*4))

//addGENER_DMA_Reg0x8c
#define addGENER_DMA_Reg0x8c                                    *((volatile unsigned long *) (0x00803000+0x8c*4))

//addGENER_DMA_Reg0x8d
#define addGENER_DMA_Reg0x8d                                    *((volatile unsigned long *) (0x00803000+0x8d*4))

//addGENER_DMA_Reg0x8e
#define addGENER_DMA_Reg0x8e                                    *((volatile unsigned long *) (0x00803000+0x8e*4))

//addGENER_DMA_Reg0x8f
#define addGENER_DMA_Reg0x8f                                    *((volatile unsigned long *) (0x00803000+0x8f*4))

//addGENER_DMA_Reg0x90
#define addGENER_DMA_Reg0x90                                    *((volatile unsigned long *) (0x00803000+0x90*4))

//addGENER_DMA_Reg0x91
#define addGENER_DMA_Reg0x91                                    *((volatile unsigned long *) (0x00803000+0x91*4))

//addGENER_DMA_Reg0x92
#define addGENER_DMA_Reg0x92                                    *((volatile unsigned long *) (0x00803000+0x92*4))

//addGENER_DMA_Reg0x93
#define addGENER_DMA_Reg0x93                                    *((volatile unsigned long *) (0x00803000+0x93*4))

//addGENER_DMA_Reg0x94
#define addGENER_DMA_Reg0x94                                    *((volatile unsigned long *) (0x00803000+0x94*4))

//addGENER_DMA_Reg0x95
#define addGENER_DMA_Reg0x95                                    *((volatile unsigned long *) (0x00803000+0x95*4))

//addGENER_DMA_Reg0x96
#define addGENER_DMA_Reg0x96                                    *((volatile unsigned long *) (0x00803000+0x96*4))

//addGENER_DMA_Reg0x97
#define addGENER_DMA_Reg0x97                                    *((volatile unsigned long *) (0x00803000+0x97*4))

//addGENER_DMA_Reg0x98
#define addGENER_DMA_Reg0x98                                    *((volatile unsigned long *) (0x00803000+0x98*4))

//addGENER_DMA_Reg0x99
#define addGENER_DMA_Reg0x99                                    *((volatile unsigned long *) (0x00803000+0x99*4))

//addGENER_DMA_Reg0x9a
#define addGENER_DMA_Reg0x9a                                    *((volatile unsigned long *) (0x00803000+0x9a*4))

//addGENER_DMA_Reg0x9b
#define addGENER_DMA_Reg0x9b                                    *((volatile unsigned long *) (0x00803000+0x9b*4))

//addGENER_DMA_Reg0x9c
#define addGENER_DMA_Reg0x9c                                    *((volatile unsigned long *) (0x00803000+0x9c*4))

//addGENER_DMA_Reg0x9d
#define addGENER_DMA_Reg0x9d                                    *((volatile unsigned long *) (0x00803000+0x9d*4))

//addGENER_DMA_Reg0x9e
#define addGENER_DMA_Reg0x9e                                    *((volatile unsigned long *) (0x00803000+0x9e*4))

//addGENER_DMA_Reg0x9f
#define addGENER_DMA_Reg0x9f                                    *((volatile unsigned long *) (0x00803000+0x9f*4))

//addGENER_DMA_Reg0xa0
#define addGENER_DMA_Reg0xa0                                    *((volatile unsigned long *) (0x00803000+0xa0*4))

//addGENER_DMA_Reg0xa1
#define addGENER_DMA_Reg0xa1                                    *((volatile unsigned long *) (0x00803000+0xa1*4))

//addGENER_DMA_Reg0xa2
#define addGENER_DMA_Reg0xa2                                    *((volatile unsigned long *) (0x00803000+0xa2*4))

//addGENER_DMA_Reg0xa3
#define addGENER_DMA_Reg0xa3                                    *((volatile unsigned long *) (0x00803000+0xa3*4))

//addGENER_DMA_Reg0xa4
#define addGENER_DMA_Reg0xa4                                    *((volatile unsigned long *) (0x00803000+0xa4*4))

//addGENER_DMA_Reg0xa5
#define addGENER_DMA_Reg0xa5                                    *((volatile unsigned long *) (0x00803000+0xa5*4))

//addGENER_DMA_Reg0xa6
#define addGENER_DMA_Reg0xa6                                    *((volatile unsigned long *) (0x00803000+0xa6*4))

//addGENER_DMA_Reg0xa7
#define addGENER_DMA_Reg0xa7                                    *((volatile unsigned long *) (0x00803000+0xa7*4))

//addGENER_DMA_Reg0xa8
#define addGENER_DMA_Reg0xa8                                    *((volatile unsigned long *) (0x00803000+0xa8*4))

//addGENER_DMA_Reg0xa9
#define addGENER_DMA_Reg0xa9                                    *((volatile unsigned long *) (0x00803000+0xa9*4))

//addGENER_DMA_Reg0xaa
#define addGENER_DMA_Reg0xaa                                    *((volatile unsigned long *) (0x00803000+0xaa*4))

//addGENER_DMA_Reg0xab
#define addGENER_DMA_Reg0xab                                    *((volatile unsigned long *) (0x00803000+0xab*4))

//addGENER_DMA_Reg0xac
#define addGENER_DMA_Reg0xac                                    *((volatile unsigned long *) (0x00803000+0xac*4))

//addGENER_DMA_Reg0xad
#define addGENER_DMA_Reg0xad                                    *((volatile unsigned long *) (0x00803000+0xad*4))

//addGENER_DMA_Reg0xae
#define addGENER_DMA_Reg0xae                                    *((volatile unsigned long *) (0x00803000+0xae*4))

//addGENER_DMA_Reg0xaf
#define addGENER_DMA_Reg0xaf                                    *((volatile unsigned long *) (0x00803000+0xaf*4))

//addGENER_DMA_Reg0xb0
#define addGENER_DMA_Reg0xb0                                    *((volatile unsigned long *) (0x00803000+0xb0*4))

//addGENER_DMA_Reg0xb1
#define addGENER_DMA_Reg0xb1                                    *((volatile unsigned long *) (0x00803000+0xb1*4))

//addGENER_DMA_Reg0xb2
#define addGENER_DMA_Reg0xb2                                    *((volatile unsigned long *) (0x00803000+0xb2*4))

//addGENER_DMA_Reg0xb3
#define addGENER_DMA_Reg0xb3                                    *((volatile unsigned long *) (0x00803000+0xb3*4))

//addGENER_DMA_Reg0xb4
#define addGENER_DMA_Reg0xb4                                    *((volatile unsigned long *) (0x00803000+0xb4*4))

//addGENER_DMA_Reg0xb5
#define addGENER_DMA_Reg0xb5                                    *((volatile unsigned long *) (0x00803000+0xb5*4))

//addGENER_DMA_Reg0xb6
#define addGENER_DMA_Reg0xb6                                    *((volatile unsigned long *) (0x00803000+0xb6*4))

//addGENER_DMA_Reg0xb7
#define addGENER_DMA_Reg0xb7                                    *((volatile unsigned long *) (0x00803000+0xb7*4))

//addGENER_DMA_Reg0xb8
#define addGENER_DMA_Reg0xb8                                    *((volatile unsigned long *) (0x00803000+0xb8*4))

//addGENER_DMA_Reg0xb9
#define addGENER_DMA_Reg0xb9                                    *((volatile unsigned long *) (0x00803000+0xb9*4))

//addGENER_DMA_Reg0xba
#define addGENER_DMA_Reg0xba                                    *((volatile unsigned long *) (0x00803000+0xba*4))

//addGENER_DMA_Reg0xbb
#define addGENER_DMA_Reg0xbb                                    *((volatile unsigned long *) (0x00803000+0xbb*4))

//addGENER_DMA_Reg0xbc
#define addGENER_DMA_Reg0xbc                                    *((volatile unsigned long *) (0x00803000+0xbc*4))

//addGENER_DMA_Reg0xbd
#define addGENER_DMA_Reg0xbd                                    *((volatile unsigned long *) (0x00803000+0xbd*4))

//addGENER_DMA_Reg0xbe
#define addGENER_DMA_Reg0xbe                                    *((volatile unsigned long *) (0x00803000+0xbe*4))

//addGENER_DMA_Reg0xbf
#define addGENER_DMA_Reg0xbf                                    *((volatile unsigned long *) (0x00803000+0xbf*4))

//addGENER_DMA_Reg0xc0
#define addGENER_DMA_Reg0xc0                                    *((volatile unsigned long *) (0x00803000+0xc0*4))
#define posGENER_DMA_Reg0xc0_intcnt_half_finish                 28
#define bitGENER_DMA_Reg0xc0_intcnt_half_finish                 0xF0000000
#define get_GENER_DMA_Reg0xc0_intcnt_half_finish                ((addGENER_DMA_Reg0xc0 & 0xF0000000) >> 28)

#define posGENER_DMA_Reg0xc0_intcnt_finish                      24
#define bitGENER_DMA_Reg0xc0_intcnt_finish                      0xF000000
#define get_GENER_DMA_Reg0xc0_intcnt_finish                     ((addGENER_DMA_Reg0xc0 & 0xF000000) >> 24)


#define posGENER_DMA_Reg0xc0_flush_src_buff                     17
#define bitGENER_DMA_Reg0xc0_flush_src_buff                     0x20000
#define set_GENER_DMA_Reg0xc0_flush_src_buff(val)               addGENER_DMA_Reg0xc0 = ((addGENER_DMA_Reg0xc0 & (~0x20000)) | ((val) << 17))
#define setf_GENER_DMA_Reg0xc0_flush_src_buff                   addGENER_DMA_Reg0xc0 |= 0x20000
#define clrf_GENER_DMA_Reg0xc0_flush_src_buff                   addGENER_DMA_Reg0xc0 &= ~0x20000
#define get_GENER_DMA_Reg0xc0_flush_src_buff                    ((addGENER_DMA_Reg0xc0 & 0x20000) >> 17)

#define posGENER_DMA_Reg0xc0_dma0_remain_len                    0
#define bitGENER_DMA_Reg0xc0_dma0_remain_len                    0x1FFFF
#define get_GENER_DMA_Reg0xc0_dma0_remain_len                   (addGENER_DMA_Reg0xc0 & 0x1FFFF)

//addGENER_DMA_Reg0xc1
#define addGENER_DMA_Reg0xc1                                    *((volatile unsigned long *) (0x00803000+0xc1*4))

//addGENER_DMA_Reg0xc2
#define addGENER_DMA_Reg0xc2                                    *((volatile unsigned long *) (0x00803000+0xc2*4))

//addGENER_DMA_Reg0xc3
#define addGENER_DMA_Reg0xc3                                    *((volatile unsigned long *) (0x00803000+0xc3*4))

//addGENER_DMA_Reg0xc4
#define addGENER_DMA_Reg0xc4                                    *((volatile unsigned long *) (0x00803000+0xc4*4))

//addGENER_DMA_Reg0xc5
#define addGENER_DMA_Reg0xc5                                    *((volatile unsigned long *) (0x00803000+0xc5*4))

//addGENER_DMA_Reg0xc6
#define addGENER_DMA_Reg0xc6                                    *((volatile unsigned long *) (0x00803000+0xc6*4))

//addGENER_DMA_Reg0xc7
#define addGENER_DMA_Reg0xc7                                    *((volatile unsigned long *) (0x00803000+0xc7*4))

//addGENER_DMA_Reg0xc8
#define addGENER_DMA_Reg0xc8                                    *((volatile unsigned long *) (0x00803000+0xc8*4))

//addGENER_DMA_Reg0xc9
#define addGENER_DMA_Reg0xc9                                    *((volatile unsigned long *) (0x00803000+0xc9*4))

//addGENER_DMA_Reg0xca
#define addGENER_DMA_Reg0xca                                    *((volatile unsigned long *) (0x00803000+0xca*4))

//addGENER_DMA_Reg0xcb
#define addGENER_DMA_Reg0xcb                                    *((volatile unsigned long *) (0x00803000+0xcb*4))

//addGENER_DMA_Reg0xcc
#define addGENER_DMA_Reg0xcc                                    *((volatile unsigned long *) (0x00803000+0xcc*4))

//addGENER_DMA_Reg0xcd
#define addGENER_DMA_Reg0xcd                                    *((volatile unsigned long *) (0x00803000+0xcd*4))

//addGENER_DMA_Reg0xce
#define addGENER_DMA_Reg0xce                                    *((volatile unsigned long *) (0x00803000+0xce*4))

//addGENER_DMA_Reg0xcf
#define addGENER_DMA_Reg0xcf                                    *((volatile unsigned long *) (0x00803000+0xcf*4))

//addGENER_DMA_Reg0xd0
#define addGENER_DMA_Reg0xd0                                    *((volatile unsigned long *) (0x00803000+0xd0*4))

#define posGENER_DMA_Reg0xd0_prio_mode                          0
#define bitGENER_DMA_Reg0xd0_prio_mode                          0x1
#define set_GENER_DMA_Reg0xd0_prio_mode(val)                    addGENER_DMA_Reg0xd0 = ((addGENER_DMA_Reg0xd0 & (~0x1)) | ((val) << 0))
#define setf_GENER_DMA_Reg0xd0_prio_mode                        addGENER_DMA_Reg0xd0 |= 0x1
#define clrf_GENER_DMA_Reg0xd0_prio_mode                        addGENER_DMA_Reg0xd0 &= ~0x1
#define get_GENER_DMA_Reg0xd0_prio_mode                         (addGENER_DMA_Reg0xd0 & 0x1)

//addGENER_DMA_Reg0xd1
#define addGENER_DMA_Reg0xd1                                    *((volatile unsigned long *) (0x00803000+0xd1*4))
#define posGENER_DMA_Reg0xd1_int_half_finish                    16
#define bitGENER_DMA_Reg0xd1_int_half_finish                    0xFFFF0000
#define set_GENER_DMA_Reg0xd1_int_half_finish(val)              addGENER_DMA_Reg0xd1 = ((addGENER_DMA_Reg0xd1 & (~0xFFFF0000)) | ((val) << 16))
#define get_GENER_DMA_Reg0xd1_int_half_finish                   ((addGENER_DMA_Reg0xd1 & 0xFFFF0000) >> 16)

#define posGENER_DMA_Reg0xd1_int_finish                         0
#define bitGENER_DMA_Reg0xd1_int_finish                         0xFFFF
#define set_GENER_DMA_Reg0xd1_int_finish(val)                   addGENER_DMA_Reg0xd1 = ((addGENER_DMA_Reg0xd1 & (~0xFFFF)) | ((val) << 0))
#define get_GENER_DMA_Reg0xd1_int_finish                        (addGENER_DMA_Reg0xd1 & 0xFFFF)


//************************************************************//
//WDT
//************************************************************//
#define BASEADDR_WDT                                            0x00806000
//addWDT_Reg0x0
#define addWDT_Reg0x0                                           *((volatile unsigned long *) (0x00806000+0x0*4))
#define posWDT_Reg0x0_WDKEY                                     16
#define bitWDT_Reg0x0_WDKEY                                     0xFF0000
#define set_WDT_Reg0x0_WDKEY(val)                               addWDT_Reg0x0 = ((addWDT_Reg0x0 & (~0xFF0000)) | ((val) << 16))
#define get_WDT_Reg0x0_WDKEY                                    ((addWDT_Reg0x0 & 0xFF0000) >> 16)

#define posWDT_Reg0x0_WD_PERIOD                                 0
#define bitWDT_Reg0x0_WD_PERIOD                                 0xFFFF
#define set_WDT_Reg0x0_WD_PERIOD(val)                           addWDT_Reg0x0 = ((addWDT_Reg0x0 & (~0xFFFF)) | ((val) << 0))
#define get_WDT_Reg0x0_WD_PERIOD                                (addWDT_Reg0x0 & 0xFFFF)


//************************************************************//
//SPI0
//************************************************************//
#define BASEADDR_SPI0                                           0x00806200
//addSPI0_Reg0x0
#define addSPI0_Reg0x0                                          *((volatile unsigned long *) (0x00806200+0x0*4))

#define posSPI0_Reg0x0_BYTE_INTLVAL                             24
#define bitSPI0_Reg0x0_BYTE_INTLVAL                             0x3F000000
#define set_SPI0_Reg0x0_BYTE_INTLVAL(val)                       addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x3F000000)) | ((val) << 24))
#define get_SPI0_Reg0x0_BYTE_INTLVAL                            ((addSPI0_Reg0x0 & 0x3F000000) >> 24)

#define posSPI0_Reg0x0_SPIEN                                    23
#define bitSPI0_Reg0x0_SPIEN                                    0x800000
#define set_SPI0_Reg0x0_SPIEN(val)                              addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x800000)) | ((val) << 23))
#define setf_SPI0_Reg0x0_SPIEN                                  addSPI0_Reg0x0 |= 0x800000
#define clrf_SPI0_Reg0x0_SPIEN                                  addSPI0_Reg0x0 &= ~0x800000
#define get_SPI0_Reg0x0_SPIEN                                   ((addSPI0_Reg0x0 & 0x800000) >> 23)

#define posSPI0_Reg0x0_MSTEN                                    22
#define bitSPI0_Reg0x0_MSTEN                                    0x400000
#define set_SPI0_Reg0x0_MSTEN(val)                              addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x400000)) | ((val) << 22))
#define setf_SPI0_Reg0x0_MSTEN                                  addSPI0_Reg0x0 |= 0x400000
#define clrf_SPI0_Reg0x0_MSTEN                                  addSPI0_Reg0x0 &= ~0x400000
#define get_SPI0_Reg0x0_MSTEN                                   ((addSPI0_Reg0x0 & 0x400000) >> 22)

#define posSPI0_Reg0x0_CKPHA                                    21
#define bitSPI0_Reg0x0_CKPHA                                    0x200000
#define set_SPI0_Reg0x0_CKPHA(val)                              addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x200000)) | ((val) << 21))
#define setf_SPI0_Reg0x0_CKPHA                                  addSPI0_Reg0x0 |= 0x200000
#define clrf_SPI0_Reg0x0_CKPHA                                  addSPI0_Reg0x0 &= ~0x200000
#define get_SPI0_Reg0x0_CKPHA                                   ((addSPI0_Reg0x0 & 0x200000) >> 21)

#define posSPI0_Reg0x0_CKPOL                                    20
#define bitSPI0_Reg0x0_CKPOL                                    0x100000
#define set_SPI0_Reg0x0_CKPOL(val)                              addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x100000)) | ((val) << 20))
#define setf_SPI0_Reg0x0_CKPOL                                  addSPI0_Reg0x0 |= 0x100000
#define clrf_SPI0_Reg0x0_CKPOL                                  addSPI0_Reg0x0 &= ~0x100000
#define get_SPI0_Reg0x0_CKPOL                                   ((addSPI0_Reg0x0 & 0x100000) >> 20)

#define posSPI0_Reg0x0_LSB_FIRST                                19
#define bitSPI0_Reg0x0_LSB_FIRST                                0x80000
#define set_SPI0_Reg0x0_LSB_FIRST(val)                          addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x80000)) | ((val) << 19))
#define setf_SPI0_Reg0x0_LSB_FIRST                              addSPI0_Reg0x0 |= 0x80000
#define clrf_SPI0_Reg0x0_LSB_FIRST                              addSPI0_Reg0x0 &= ~0x80000
#define get_SPI0_Reg0x0_LSB_FIRST                               ((addSPI0_Reg0x0 & 0x80000) >> 19)

#define posSPI0_Reg0x0_BIT_WDTH                                 18
#define bitSPI0_Reg0x0_BIT_WDTH                                 0x40000
#define set_SPI0_Reg0x0_BIT_WDTH(val)                           addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x40000)) | ((val) << 18))
#define setf_SPI0_Reg0x0_BIT_WDTH                               addSPI0_Reg0x0 |= 0x40000
#define clrf_SPI0_Reg0x0_BIT_WDTH                               addSPI0_Reg0x0 &= ~0x40000
#define get_SPI0_Reg0x0_BIT_WDTH                                ((addSPI0_Reg0x0 & 0x40000) >> 18)

#define posSPI0_Reg0x0_WIRE3_EN                                 17
#define bitSPI0_Reg0x0_WIRE3_EN                                 0x20000
#define set_SPI0_Reg0x0_WIRE3_EN(val)                           addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x20000)) | ((val) << 17))
#define setf_SPI0_Reg0x0_WIRE3_EN                               addSPI0_Reg0x0 |= 0x20000
#define clrf_SPI0_Reg0x0_WIRE3_EN                               addSPI0_Reg0x0 &= ~0x20000
#define get_SPI0_Reg0x0_WIRE3_EN                                ((addSPI0_Reg0x0 & 0x20000) >> 17)

#define posSPI0_Reg0x0_SLV_RELEASE_INTEN                        16
#define bitSPI0_Reg0x0_SLV_RELEASE_INTEN                        0x10000
#define set_SPI0_Reg0x0_SLV_RELEASE_INTEN(val)                  addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x10000)) | ((val) << 16))
#define setf_SPI0_Reg0x0_SLV_RELEASE_INTEN                      addSPI0_Reg0x0 |= 0x10000
#define clrf_SPI0_Reg0x0_SLV_RELEASE_INTEN                      addSPI0_Reg0x0 &= ~0x10000
#define get_SPI0_Reg0x0_SLV_RELEASE_INTEN                       ((addSPI0_Reg0x0 & 0x10000) >> 16)

#define posSPI0_Reg0x0_SPI_CKR                                  8
#define bitSPI0_Reg0x0_SPI_CKR                                  0xFF00
#define set_SPI0_Reg0x0_SPI_CKR(val)                            addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0xFF00)) | ((val) << 8))
#define get_SPI0_Reg0x0_SPI_CKR                                 ((addSPI0_Reg0x0 & 0xFF00) >> 8)

#define posSPI0_Reg0x0_RXFIFO_INT_EN                            7
#define bitSPI0_Reg0x0_RXFIFO_INT_EN                            0x80
#define set_SPI0_Reg0x0_RXFIFO_INT_EN(val)                      addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x80)) | ((val) << 7))
#define setf_SPI0_Reg0x0_RXFIFO_INT_EN                          addSPI0_Reg0x0 |= 0x80
#define clrf_SPI0_Reg0x0_RXFIFO_INT_EN                          addSPI0_Reg0x0 &= ~0x80
#define get_SPI0_Reg0x0_RXFIFO_INT_EN                           ((addSPI0_Reg0x0 & 0x80) >> 7)

#define posSPI0_Reg0x0_TXFIFO_INT_EN                            6
#define bitSPI0_Reg0x0_TXFIFO_INT_EN                            0x40
#define set_SPI0_Reg0x0_TXFIFO_INT_EN(val)                      addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x40)) | ((val) << 6))
#define setf_SPI0_Reg0x0_TXFIFO_INT_EN                          addSPI0_Reg0x0 |= 0x40
#define clrf_SPI0_Reg0x0_TXFIFO_INT_EN                          addSPI0_Reg0x0 &= ~0x40
#define get_SPI0_Reg0x0_TXFIFO_INT_EN                           ((addSPI0_Reg0x0 & 0x40) >> 6)

#define posSPI0_Reg0x0_RXOVF_EN                                 5
#define bitSPI0_Reg0x0_RXOVF_EN                                 0x20
#define set_SPI0_Reg0x0_RXOVF_EN(val)                           addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x20)) | ((val) << 5))
#define setf_SPI0_Reg0x0_RXOVF_EN                               addSPI0_Reg0x0 |= 0x20
#define clrf_SPI0_Reg0x0_RXOVF_EN                               addSPI0_Reg0x0 &= ~0x20
#define get_SPI0_Reg0x0_RXOVF_EN                                ((addSPI0_Reg0x0 & 0x20) >> 5)

#define posSPI0_Reg0x0_TXUDF_EN                                 4
#define bitSPI0_Reg0x0_TXUDF_EN                                 0x10
#define set_SPI0_Reg0x0_TXUDF_EN(val)                           addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x10)) | ((val) << 4))
#define setf_SPI0_Reg0x0_TXUDF_EN                               addSPI0_Reg0x0 |= 0x10
#define clrf_SPI0_Reg0x0_TXUDF_EN                               addSPI0_Reg0x0 &= ~0x10
#define get_SPI0_Reg0x0_TXUDF_EN                                ((addSPI0_Reg0x0 & 0x10) >> 4)

#define posSPI0_Reg0x0_RXFIFO_INT_LEVEL                         2
#define bitSPI0_Reg0x0_RXFIFO_INT_LEVEL                         0xC
#define set_SPI0_Reg0x0_RXFIFO_INT_LEVEL(val)                   addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0xC)) | ((val) << 2))
#define get_SPI0_Reg0x0_RXFIFO_INT_LEVEL                        ((addSPI0_Reg0x0 & 0xC) >> 2)

#define posSPI0_Reg0x0_TXFIFO_INT_LEVEL                         0
#define bitSPI0_Reg0x0_TXFIFO_INT_LEVEL                         0x3
#define set_SPI0_Reg0x0_TXFIFO_INT_LEVEL(val)                   addSPI0_Reg0x0 = ((addSPI0_Reg0x0 & (~0x3)) | ((val) << 0))
#define get_SPI0_Reg0x0_TXFIFO_INT_LEVEL                        (addSPI0_Reg0x0 & 0x3)

//addSPI0_Reg0x1
#define addSPI0_Reg0x1                                          *((volatile unsigned long *) (0x00806200+0x1*4))
#define posSPI0_Reg0x1_RX_TRANS_LEN                             20
#define bitSPI0_Reg0x1_RX_TRANS_LEN                             0xFFF00000
#define set_SPI0_Reg0x1_RX_TRANS_LEN(val)                       addSPI0_Reg0x1 = ((addSPI0_Reg0x1 & (~0xFFF00000)) | ((val) << 20))
#define get_SPI0_Reg0x1_RX_TRANS_LEN                            ((addSPI0_Reg0x1 & 0xFFF00000) >> 20)

#define posSPI0_Reg0x1_TX_TRANS_LEN                             8
#define bitSPI0_Reg0x1_TX_TRANS_LEN                             0xFFF00
#define set_SPI0_Reg0x1_TX_TRANS_LEN(val)                       addSPI0_Reg0x1 = ((addSPI0_Reg0x1 & (~0xFFF00)) | ((val) << 8))
#define get_SPI0_Reg0x1_TX_TRANS_LEN                            ((addSPI0_Reg0x1 & 0xFFF00) >> 8)


#define posSPI0_Reg0x1_RX_FINISH_INT_EN                         3
#define bitSPI0_Reg0x1_RX_FINISH_INT_EN                         0x8
#define set_SPI0_Reg0x1_RX_FINISH_INT_EN(val)                   addSPI0_Reg0x1 = ((addSPI0_Reg0x1 & (~0x8)) | ((val) << 3))
#define setf_SPI0_Reg0x1_RX_FINISH_INT_EN                       addSPI0_Reg0x1 |= 0x8
#define clrf_SPI0_Reg0x1_RX_FINISH_INT_EN                       addSPI0_Reg0x1 &= ~0x8
#define get_SPI0_Reg0x1_RX_FINISH_INT_EN                        ((addSPI0_Reg0x1 & 0x8) >> 3)

#define posSPI0_Reg0x1_TX_FINISH_INT_EN                         2
#define bitSPI0_Reg0x1_TX_FINISH_INT_EN                         0x4
#define set_SPI0_Reg0x1_TX_FINISH_INT_EN(val)                   addSPI0_Reg0x1 = ((addSPI0_Reg0x1 & (~0x4)) | ((val) << 2))
#define setf_SPI0_Reg0x1_TX_FINISH_INT_EN                       addSPI0_Reg0x1 |= 0x4
#define clrf_SPI0_Reg0x1_TX_FINISH_INT_EN                       addSPI0_Reg0x1 &= ~0x4
#define get_SPI0_Reg0x1_TX_FINISH_INT_EN                        ((addSPI0_Reg0x1 & 0x4) >> 2)

#define posSPI0_Reg0x1_RX_EN                                    1
#define bitSPI0_Reg0x1_RX_EN                                    0x2
#define set_SPI0_Reg0x1_RX_EN(val)                              addSPI0_Reg0x1 = ((addSPI0_Reg0x1 & (~0x2)) | ((val) << 1))
#define setf_SPI0_Reg0x1_RX_EN                                  addSPI0_Reg0x1 |= 0x2
#define clrf_SPI0_Reg0x1_RX_EN                                  addSPI0_Reg0x1 &= ~0x2
#define get_SPI0_Reg0x1_RX_EN                                   ((addSPI0_Reg0x1 & 0x2) >> 1)

#define posSPI0_Reg0x1_TX_EN                                    0
#define bitSPI0_Reg0x1_TX_EN                                    0x1
#define set_SPI0_Reg0x1_TX_EN(val)                              addSPI0_Reg0x1 = ((addSPI0_Reg0x1 & (~0x1)) | ((val) << 0))
#define setf_SPI0_Reg0x1_TX_EN                                  addSPI0_Reg0x1 |= 0x1
#define clrf_SPI0_Reg0x1_TX_EN                                  addSPI0_Reg0x1 &= ~0x1
#define get_SPI0_Reg0x1_TX_EN                                   (addSPI0_Reg0x1 & 0x1)

//addSPI0_Reg0x2
#define addSPI0_Reg0x2                                          *((volatile unsigned long *) (0x00806200+0x2*4))

#define posSPI0_Reg0x2_RXFIFO_CLR                               17
#define bitSPI0_Reg0x2_RXFIFO_CLR                               0x20000
#define set_SPI0_Reg0x2_RXFIFO_CLR(val)                         addSPI0_Reg0x2 = ((addSPI0_Reg0x2 & (~0x20000)) | ((val) << 17))
#define setf_SPI0_Reg0x2_RXFIFO_CLR                             addSPI0_Reg0x2 |= 0x20000
#define clrf_SPI0_Reg0x2_RXFIFO_CLR                             addSPI0_Reg0x2 &= ~0x20000
#define get_SPI0_Reg0x2_RXFIFO_CLR                              ((addSPI0_Reg0x2 & 0x20000) >> 17)

#define posSPI0_Reg0x2_TXFIFO_CLR                               16
#define bitSPI0_Reg0x2_TXFIFO_CLR                               0x10000
#define set_SPI0_Reg0x2_TXFIFO_CLR(val)                         addSPI0_Reg0x2 = ((addSPI0_Reg0x2 & (~0x10000)) | ((val) << 16))
#define setf_SPI0_Reg0x2_TXFIFO_CLR                             addSPI0_Reg0x2 |= 0x10000
#define clrf_SPI0_Reg0x2_TXFIFO_CLR                             addSPI0_Reg0x2 &= ~0x10000
#define get_SPI0_Reg0x2_TXFIFO_CLR                              ((addSPI0_Reg0x2 & 0x10000) >> 16)


#define posSPI0_Reg0x2_RX_FINISH_INT                            14
#define bitSPI0_Reg0x2_RX_FINISH_INT                            0x4000
#define get_SPI0_Reg0x2_RX_FINISH_INT                           ((addSPI0_Reg0x2 & 0x4000) >> 14)

#define posSPI0_Reg0x2_TX_FINISH_INT                            13
#define bitSPI0_Reg0x2_TX_FINISH_INT                            0x2000
#define set_SPI0_Reg0x2_TX_FINISH_INT(val)                      addSPI0_Reg0x2 = ((addSPI0_Reg0x2 & (~0x2000)) | ((val) << 13))
#define setf_SPI0_Reg0x2_TX_FINISH_INT                          addSPI0_Reg0x2 |= 0x2000
#define clrf_SPI0_Reg0x2_TX_FINISH_INT                          addSPI0_Reg0x2 &= ~0x2000
#define get_SPI0_Reg0x2_TX_FINISH_INT                           ((addSPI0_Reg0x2 & 0x2000) >> 13)

#define posSPI0_Reg0x2_RXOVF                                    12
#define bitSPI0_Reg0x2_RXOVF                                    0x1000
#define set_SPI0_Reg0x2_RXOVF(val)                              addSPI0_Reg0x2 = ((addSPI0_Reg0x2 & (~0x1000)) | ((val) << 12))
#define setf_SPI0_Reg0x2_RXOVF                                  addSPI0_Reg0x2 |= 0x1000
#define clrf_SPI0_Reg0x2_RXOVF                                  addSPI0_Reg0x2 &= ~0x1000
#define get_SPI0_Reg0x2_RXOVF                                   ((addSPI0_Reg0x2 & 0x1000) >> 12)

#define posSPI0_Reg0x2_TXUDF                                    11
#define bitSPI0_Reg0x2_TXUDF                                    0x800
#define set_SPI0_Reg0x2_TXUDF(val)                              addSPI0_Reg0x2 = ((addSPI0_Reg0x2 & (~0x800)) | ((val) << 11))
#define setf_SPI0_Reg0x2_TXUDF                                  addSPI0_Reg0x2 |= 0x800
#define clrf_SPI0_Reg0x2_TXUDF                                  addSPI0_Reg0x2 &= ~0x800
#define get_SPI0_Reg0x2_TXUDF                                   ((addSPI0_Reg0x2 & 0x800) >> 11)

#define posSPI0_Reg0x2_SLV_RELEASE_INT                          10
#define bitSPI0_Reg0x2_SLV_RELEASE_INT                          0x400
#define set_SPI0_Reg0x2_SLV_RELEASE_INT(val)                    addSPI0_Reg0x2 = ((addSPI0_Reg0x2 & (~0x400)) | ((val) << 10))
#define setf_SPI0_Reg0x2_SLV_RELEASE_INT                        addSPI0_Reg0x2 |= 0x400
#define clrf_SPI0_Reg0x2_SLV_RELEASE_INT                        addSPI0_Reg0x2 &= ~0x400
#define get_SPI0_Reg0x2_SLV_RELEASE_INT                         ((addSPI0_Reg0x2 & 0x400) >> 10)

#define posSPI0_Reg0x2_RXFIFO_INT                               9
#define bitSPI0_Reg0x2_RXFIFO_INT                               0x200
#define set_SPI0_Reg0x2_RXFIFO_INT(val)                         addSPI0_Reg0x2 = ((addSPI0_Reg0x2 & (~0x200)) | ((val) << 9))
#define setf_SPI0_Reg0x2_RXFIFO_INT                             addSPI0_Reg0x2 |= 0x200
#define clrf_SPI0_Reg0x2_RXFIFO_INT                             addSPI0_Reg0x2 &= ~0x200
#define get_SPI0_Reg0x2_RXFIFO_INT                              ((addSPI0_Reg0x2 & 0x200) >> 9)

#define posSPI0_Reg0x2_TXFIFO_INT                               8
#define bitSPI0_Reg0x2_TXFIFO_INT                               0x100
#define set_SPI0_Reg0x2_TXFIFO_INT(val)                         addSPI0_Reg0x2 = ((addSPI0_Reg0x2 & (~0x100)) | ((val) << 8))
#define setf_SPI0_Reg0x2_TXFIFO_INT                             addSPI0_Reg0x2 |= 0x100
#define clrf_SPI0_Reg0x2_TXFIFO_INT                             addSPI0_Reg0x2 &= ~0x100
#define get_SPI0_Reg0x2_TXFIFO_INT                              ((addSPI0_Reg0x2 & 0x100) >> 8)



#define posSPI0_Reg0x2_RXFIFO_RD_READY                          2
#define bitSPI0_Reg0x2_RXFIFO_RD_READY                          0x4
#define get_SPI0_Reg0x2_RXFIFO_RD_READY                         ((addSPI0_Reg0x2 & 0x4) >> 2)

#define posSPI0_Reg0x2_TXFIFO_WR_READY                          1
#define bitSPI0_Reg0x2_TXFIFO_WR_READY                          0x2
#define get_SPI0_Reg0x2_TXFIFO_WR_READY                         ((addSPI0_Reg0x2 & 0x2) >> 1)


//addSPI0_Reg0x3
#define addSPI0_Reg0x3                                          *((volatile unsigned long *) (0x00806200+0x3*4))

#define posSPI0_Reg0x3_SPI_DAT                                  0
#define bitSPI0_Reg0x3_SPI_DAT                                  0xFFFF
#define set_SPI0_Reg0x3_SPI_DAT(val)                            addSPI0_Reg0x3 = ((addSPI0_Reg0x3 & (~0xFFFF)) | ((val) << 0))
#define get_SPI0_Reg0x3_SPI_DAT                                 (addSPI0_Reg0x3 & 0xFFFF)


//************************************************************//
//UART0
//************************************************************//
#define BASEADDR_UART0                                          0x00806300
//addUART0_Reg0x0
#define addUART0_Reg0x0                                         *((volatile unsigned long *) (0x00806300+0x0*4))
#define posUART0_Reg0x0_UART_TX_ENABLE                          0
#define bitUART0_Reg0x0_UART_TX_ENABLE                          0x1
#define set_UART0_Reg0x0_UART_TX_ENABLE(val)                    addUART0_Reg0x0 = ((addUART0_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_UART0_Reg0x0_UART_TX_ENABLE                        addUART0_Reg0x0 |= 0x1
#define clrf_UART0_Reg0x0_UART_TX_ENABLE                        addUART0_Reg0x0 &= ~0x1
#define get_UART0_Reg0x0_UART_TX_ENABLE                         (addUART0_Reg0x0 & 0x1)

#define posUART0_Reg0x0_UART_RX_ENABLE                          1
#define bitUART0_Reg0x0_UART_RX_ENABLE                          0x2
#define set_UART0_Reg0x0_UART_RX_ENABLE(val)                    addUART0_Reg0x0 = ((addUART0_Reg0x0 & (~0x2)) | ((val) << 1))
#define setf_UART0_Reg0x0_UART_RX_ENABLE                        addUART0_Reg0x0 |= 0x2
#define clrf_UART0_Reg0x0_UART_RX_ENABLE                        addUART0_Reg0x0 &= ~0x2
#define get_UART0_Reg0x0_UART_RX_ENABLE                         ((addUART0_Reg0x0 & 0x2) >> 1)

#define posUART0_Reg0x0_UART_IRDA                               2
#define bitUART0_Reg0x0_UART_IRDA                               0x4
#define set_UART0_Reg0x0_UART_IRDA(val)                         addUART0_Reg0x0 = ((addUART0_Reg0x0 & (~0x4)) | ((val) << 2))
#define setf_UART0_Reg0x0_UART_IRDA                             addUART0_Reg0x0 |= 0x4
#define clrf_UART0_Reg0x0_UART_IRDA                             addUART0_Reg0x0 &= ~0x4
#define get_UART0_Reg0x0_UART_IRDA                              ((addUART0_Reg0x0 & 0x4) >> 2)

#define posUART0_Reg0x0_UART_LEN                                3
#define bitUART0_Reg0x0_UART_LEN                                0x18
#define set_UART0_Reg0x0_UART_LEN(val)                          addUART0_Reg0x0 = ((addUART0_Reg0x0 & (~0x18)) | ((val) << 3))
#define get_UART0_Reg0x0_UART_LEN                               ((addUART0_Reg0x0 & 0x18) >> 3)

#define posUART0_Reg0x0_UART_PAR_EN                             5
#define bitUART0_Reg0x0_UART_PAR_EN                             0x20
#define set_UART0_Reg0x0_UART_PAR_EN(val)                       addUART0_Reg0x0 = ((addUART0_Reg0x0 & (~0x20)) | ((val) << 5))
#define setf_UART0_Reg0x0_UART_PAR_EN                           addUART0_Reg0x0 |= 0x20
#define clrf_UART0_Reg0x0_UART_PAR_EN                           addUART0_Reg0x0 &= ~0x20
#define get_UART0_Reg0x0_UART_PAR_EN                            ((addUART0_Reg0x0 & 0x20) >> 5)

#define posUART0_Reg0x0_UART_PAR_MODE                           6
#define bitUART0_Reg0x0_UART_PAR_MODE                           0x40
#define set_UART0_Reg0x0_UART_PAR_MODE(val)                     addUART0_Reg0x0 = ((addUART0_Reg0x0 & (~0x40)) | ((val) << 6))
#define setf_UART0_Reg0x0_UART_PAR_MODE                         addUART0_Reg0x0 |= 0x40
#define clrf_UART0_Reg0x0_UART_PAR_MODE                         addUART0_Reg0x0 &= ~0x40
#define get_UART0_Reg0x0_UART_PAR_MODE                          ((addUART0_Reg0x0 & 0x40) >> 6)

#define posUART0_Reg0x0_UART_STOP_LEN                           7
#define bitUART0_Reg0x0_UART_STOP_LEN                           0x80
#define set_UART0_Reg0x0_UART_STOP_LEN(val)                     addUART0_Reg0x0 = ((addUART0_Reg0x0 & (~0x80)) | ((val) << 7))
#define setf_UART0_Reg0x0_UART_STOP_LEN                         addUART0_Reg0x0 |= 0x80
#define clrf_UART0_Reg0x0_UART_STOP_LEN                         addUART0_Reg0x0 &= ~0x80
#define get_UART0_Reg0x0_UART_STOP_LEN                          ((addUART0_Reg0x0 & 0x80) >> 7)

#define posUART0_Reg0x0_UART_CLK_DIVID                          8
#define bitUART0_Reg0x0_UART_CLK_DIVID                          0x1FFF00
#define set_UART0_Reg0x0_UART_CLK_DIVID(val)                    addUART0_Reg0x0 = ((addUART0_Reg0x0 & (~0x1FFF00)) | ((val) << 8))
#define get_UART0_Reg0x0_UART_CLK_DIVID                         ((addUART0_Reg0x0 & 0x1FFF00) >> 8)

//addUART0_Reg0x1
#define addUART0_Reg0x1                                         *((volatile unsigned long *) (0x00806300+0x1*4))
#define posUART0_Reg0x1_TX_FIFO_THRESHOLD                       0
#define bitUART0_Reg0x1_TX_FIFO_THRESHOLD                       0xFF
#define set_UART0_Reg0x1_TX_FIFO_THRESHOLD(val)                 addUART0_Reg0x1 = ((addUART0_Reg0x1 & (~0xFF)) | ((val) << 0))
#define get_UART0_Reg0x1_TX_FIFO_THRESHOLD                      (addUART0_Reg0x1 & 0xFF)

#define posUART0_Reg0x1_RX_FIFO_THRESHOLD                       8
#define bitUART0_Reg0x1_RX_FIFO_THRESHOLD                       0xFF00
#define set_UART0_Reg0x1_RX_FIFO_THRESHOLD(val)                 addUART0_Reg0x1 = ((addUART0_Reg0x1 & (~0xFF00)) | ((val) << 8))
#define get_UART0_Reg0x1_RX_FIFO_THRESHOLD                      ((addUART0_Reg0x1 & 0xFF00) >> 8)

#define posUART0_Reg0x1_RX_STOP_DETECT_TIME                     16
#define bitUART0_Reg0x1_RX_STOP_DETECT_TIME                     0x30000
#define set_UART0_Reg0x1_RX_STOP_DETECT_TIME(val)               addUART0_Reg0x1 = ((addUART0_Reg0x1 & (~0x30000)) | ((val) << 16))
#define get_UART0_Reg0x1_RX_STOP_DETECT_TIME                    ((addUART0_Reg0x1 & 0x30000) >> 16)

//addUART0_Reg0x2
#define addUART0_Reg0x2                                         *((volatile unsigned long *) (0x00806300+0x2*4))
#define posUART0_Reg0x2_TX_FIFO_COUNT                           0
#define bitUART0_Reg0x2_TX_FIFO_COUNT                           0xFF
#define get_UART0_Reg0x2_TX_FIFO_COUNT                          (addUART0_Reg0x2 & 0xFF)

#define posUART0_Reg0x2_RX_FIFO_COUNT                           8
#define bitUART0_Reg0x2_RX_FIFO_COUNT                           0xFF00
#define get_UART0_Reg0x2_RX_FIFO_COUNT                          ((addUART0_Reg0x2 & 0xFF00) >> 8)

#define posUART0_Reg0x2_TX_FIFO_FULL                            16
#define bitUART0_Reg0x2_TX_FIFO_FULL                            0x10000
#define get_UART0_Reg0x2_TX_FIFO_FULL                           ((addUART0_Reg0x2 & 0x10000) >> 16)

#define posUART0_Reg0x2_TX_FIFO_EMPTY                           17
#define bitUART0_Reg0x2_TX_FIFO_EMPTY                           0x20000
#define get_UART0_Reg0x2_TX_FIFO_EMPTY                          ((addUART0_Reg0x2 & 0x20000) >> 17)

#define posUART0_Reg0x2_RX_FIFO_FULL                            18
#define bitUART0_Reg0x2_RX_FIFO_FULL                            0x40000
#define get_UART0_Reg0x2_RX_FIFO_FULL                           ((addUART0_Reg0x2 & 0x40000) >> 18)

#define posUART0_Reg0x2_RX_FIFO_EMPTY                           19
#define bitUART0_Reg0x2_RX_FIFO_EMPTY                           0x80000
#define get_UART0_Reg0x2_RX_FIFO_EMPTY                          ((addUART0_Reg0x2 & 0x80000) >> 19)

#define posUART0_Reg0x2_FIFO_WR_READY                           20
#define bitUART0_Reg0x2_FIFO_WR_READY                           0x100000
#define get_UART0_Reg0x2_FIFO_WR_READY                          ((addUART0_Reg0x2 & 0x100000) >> 20)

#define posUART0_Reg0x2_FIFO_RD_READY                           21
#define bitUART0_Reg0x2_FIFO_RD_READY                           0x200000
#define get_UART0_Reg0x2_FIFO_RD_READY                          ((addUART0_Reg0x2 & 0x200000) >> 21)

//addUART0_Reg0x3
#define addUART0_Reg0x3                                         *((volatile unsigned long *) (0x00806300+0x3*4))
#define posUART0_Reg0x3_UART_TX_FIFO_DIN                        0
#define bitUART0_Reg0x3_UART_TX_FIFO_DIN                        0xFF
#define set_UART0_Reg0x3_UART_TX_FIFO_DIN(val)                  addUART0_Reg0x3 = ((addUART0_Reg0x3 & (~0xFF)) | ((val) << 0))
#define get_UART0_Reg0x3_UART_TX_FIFO_DIN                       (addUART0_Reg0x3 & 0xFF)

#define posUART0_Reg0x3_UART_RX_FIFO_DOUT                       8
#define bitUART0_Reg0x3_UART_RX_FIFO_DOUT                       0xFF00
#define get_UART0_Reg0x3_UART_RX_FIFO_DOUT                      ((addUART0_Reg0x3 & 0xFF00) >> 8)

//addUART0_Reg0x4
#define addUART0_Reg0x4                                         *((volatile unsigned long *) (0x00806300+0x4*4))
#define posUART0_Reg0x4_TX_FIFO_NEED_WRITE_MASK                 0
#define bitUART0_Reg0x4_TX_FIFO_NEED_WRITE_MASK                 0x1
#define set_UART0_Reg0x4_TX_FIFO_NEED_WRITE_MASK(val)           addUART0_Reg0x4 = ((addUART0_Reg0x4 & (~0x1)) | ((val) << 0))
#define setf_UART0_Reg0x4_TX_FIFO_NEED_WRITE_MASK               addUART0_Reg0x4 |= 0x1
#define clrf_UART0_Reg0x4_TX_FIFO_NEED_WRITE_MASK               addUART0_Reg0x4 &= ~0x1
#define get_UART0_Reg0x4_TX_FIFO_NEED_WRITE_MASK                (addUART0_Reg0x4 & 0x1)

#define posUART0_Reg0x4_RX_FIFO_NEED_READ_MASK                  1
#define bitUART0_Reg0x4_RX_FIFO_NEED_READ_MASK                  0x2
#define set_UART0_Reg0x4_RX_FIFO_NEED_READ_MASK(val)            addUART0_Reg0x4 = ((addUART0_Reg0x4 & (~0x2)) | ((val) << 1))
#define setf_UART0_Reg0x4_RX_FIFO_NEED_READ_MASK                addUART0_Reg0x4 |= 0x2
#define clrf_UART0_Reg0x4_RX_FIFO_NEED_READ_MASK                addUART0_Reg0x4 &= ~0x2
#define get_UART0_Reg0x4_RX_FIFO_NEED_READ_MASK                 ((addUART0_Reg0x4 & 0x2) >> 1)

#define posUART0_Reg0x4_RX_FIFO_OVER_FLOW_MASK                  2
#define bitUART0_Reg0x4_RX_FIFO_OVER_FLOW_MASK                  0x4
#define set_UART0_Reg0x4_RX_FIFO_OVER_FLOW_MASK(val)            addUART0_Reg0x4 = ((addUART0_Reg0x4 & (~0x4)) | ((val) << 2))
#define setf_UART0_Reg0x4_RX_FIFO_OVER_FLOW_MASK                addUART0_Reg0x4 |= 0x4
#define clrf_UART0_Reg0x4_RX_FIFO_OVER_FLOW_MASK                addUART0_Reg0x4 &= ~0x4
#define get_UART0_Reg0x4_RX_FIFO_OVER_FLOW_MASK                 ((addUART0_Reg0x4 & 0x4) >> 2)

#define posUART0_Reg0x4_UART_RX_PARITY_ERR_MASK                 3
#define bitUART0_Reg0x4_UART_RX_PARITY_ERR_MASK                 0x8
#define set_UART0_Reg0x4_UART_RX_PARITY_ERR_MASK(val)           addUART0_Reg0x4 = ((addUART0_Reg0x4 & (~0x8)) | ((val) << 3))
#define setf_UART0_Reg0x4_UART_RX_PARITY_ERR_MASK               addUART0_Reg0x4 |= 0x8
#define clrf_UART0_Reg0x4_UART_RX_PARITY_ERR_MASK               addUART0_Reg0x4 &= ~0x8
#define get_UART0_Reg0x4_UART_RX_PARITY_ERR_MASK                ((addUART0_Reg0x4 & 0x8) >> 3)

#define posUART0_Reg0x4_UART_RX_STOP_ERR_MASK                   4
#define bitUART0_Reg0x4_UART_RX_STOP_ERR_MASK                   0x10
#define set_UART0_Reg0x4_UART_RX_STOP_ERR_MASK(val)             addUART0_Reg0x4 = ((addUART0_Reg0x4 & (~0x10)) | ((val) << 4))
#define setf_UART0_Reg0x4_UART_RX_STOP_ERR_MASK                 addUART0_Reg0x4 |= 0x10
#define clrf_UART0_Reg0x4_UART_RX_STOP_ERR_MASK                 addUART0_Reg0x4 &= ~0x10
#define get_UART0_Reg0x4_UART_RX_STOP_ERR_MASK                  ((addUART0_Reg0x4 & 0x10) >> 4)

#define posUART0_Reg0x4_UART_TX_STOP_END_MASK                   5
#define bitUART0_Reg0x4_UART_TX_STOP_END_MASK                   0x20
#define set_UART0_Reg0x4_UART_TX_STOP_END_MASK(val)             addUART0_Reg0x4 = ((addUART0_Reg0x4 & (~0x20)) | ((val) << 5))
#define setf_UART0_Reg0x4_UART_TX_STOP_END_MASK                 addUART0_Reg0x4 |= 0x20
#define clrf_UART0_Reg0x4_UART_TX_STOP_END_MASK                 addUART0_Reg0x4 &= ~0x20
#define get_UART0_Reg0x4_UART_TX_STOP_END_MASK                  ((addUART0_Reg0x4 & 0x20) >> 5)

#define posUART0_Reg0x4_UART_RX_STOP_END_MASK                   6
#define bitUART0_Reg0x4_UART_RX_STOP_END_MASK                   0x40
#define set_UART0_Reg0x4_UART_RX_STOP_END_MASK(val)             addUART0_Reg0x4 = ((addUART0_Reg0x4 & (~0x40)) | ((val) << 6))
#define setf_UART0_Reg0x4_UART_RX_STOP_END_MASK                 addUART0_Reg0x4 |= 0x40
#define clrf_UART0_Reg0x4_UART_RX_STOP_END_MASK                 addUART0_Reg0x4 &= ~0x40
#define get_UART0_Reg0x4_UART_RX_STOP_END_MASK                  ((addUART0_Reg0x4 & 0x40) >> 6)

#define posUART0_Reg0x4_UART_RXD_WAKEUP_MASK                    7
#define bitUART0_Reg0x4_UART_RXD_WAKEUP_MASK                    0x80
#define set_UART0_Reg0x4_UART_RXD_WAKEUP_MASK(val)              addUART0_Reg0x4 = ((addUART0_Reg0x4 & (~0x80)) | ((val) << 7))
#define setf_UART0_Reg0x4_UART_RXD_WAKEUP_MASK                  addUART0_Reg0x4 |= 0x80
#define clrf_UART0_Reg0x4_UART_RXD_WAKEUP_MASK                  addUART0_Reg0x4 &= ~0x80
#define get_UART0_Reg0x4_UART_RXD_WAKEUP_MASK                   ((addUART0_Reg0x4 & 0x80) >> 7)

//addUART0_Reg0x5
#define addUART0_Reg0x5                                         *((volatile unsigned long *) (0x00806300+0x5*4))
#define posUART0_Reg0x5_TX_FIFO_NEED_WRITE                      0
#define bitUART0_Reg0x5_TX_FIFO_NEED_WRITE                      0x1
#define get_UART0_Reg0x5_TX_FIFO_NEED_WRITE                     (addUART0_Reg0x5 & 0x1)

#define posUART0_Reg0x5_RX_FIFO_NEED_READ                       1
#define bitUART0_Reg0x5_RX_FIFO_NEED_READ                       0x2
#define get_UART0_Reg0x5_RX_FIFO_NEED_READ                      ((addUART0_Reg0x5 & 0x2) >> 1)

#define posUART0_Reg0x5_RX_FIFO_OVER_FLOW                       2
#define bitUART0_Reg0x5_RX_FIFO_OVER_FLOW                       0x4
#define set_UART0_Reg0x5_RX_FIFO_OVER_FLOW(val)                 addUART0_Reg0x5 = ((addUART0_Reg0x5 & (~0x4)) | ((val) << 2))
#define setf_UART0_Reg0x5_RX_FIFO_OVER_FLOW                     addUART0_Reg0x5 |= 0x4
#define clrf_UART0_Reg0x5_RX_FIFO_OVER_FLOW                     addUART0_Reg0x5 &= ~0x4
#define get_UART0_Reg0x5_RX_FIFO_OVER_FLOW                      ((addUART0_Reg0x5 & 0x4) >> 2)

#define posUART0_Reg0x5_UART_RX_PARITY_ERROR                    3
#define bitUART0_Reg0x5_UART_RX_PARITY_ERROR                    0x8
#define set_UART0_Reg0x5_UART_RX_PARITY_ERROR(val)              addUART0_Reg0x5 = ((addUART0_Reg0x5 & (~0x8)) | ((val) << 3))
#define setf_UART0_Reg0x5_UART_RX_PARITY_ERROR                  addUART0_Reg0x5 |= 0x8
#define clrf_UART0_Reg0x5_UART_RX_PARITY_ERROR                  addUART0_Reg0x5 &= ~0x8
#define get_UART0_Reg0x5_UART_RX_PARITY_ERROR                   ((addUART0_Reg0x5 & 0x8) >> 3)

#define posUART0_Reg0x5_UART_RX_STOP_ERROR                      4
#define bitUART0_Reg0x5_UART_RX_STOP_ERROR                      0x10
#define set_UART0_Reg0x5_UART_RX_STOP_ERROR(val)                addUART0_Reg0x5 = ((addUART0_Reg0x5 & (~0x10)) | ((val) << 4))
#define setf_UART0_Reg0x5_UART_RX_STOP_ERROR                    addUART0_Reg0x5 |= 0x10
#define clrf_UART0_Reg0x5_UART_RX_STOP_ERROR                    addUART0_Reg0x5 &= ~0x10
#define get_UART0_Reg0x5_UART_RX_STOP_ERROR                     ((addUART0_Reg0x5 & 0x10) >> 4)

#define posUART0_Reg0x5_UART_TX_STOP_END                        5
#define bitUART0_Reg0x5_UART_TX_STOP_END                        0x20
#define set_UART0_Reg0x5_UART_TX_STOP_END(val)                  addUART0_Reg0x5 = ((addUART0_Reg0x5 & (~0x20)) | ((val) << 5))
#define setf_UART0_Reg0x5_UART_TX_STOP_END                      addUART0_Reg0x5 |= 0x20
#define clrf_UART0_Reg0x5_UART_TX_STOP_END                      addUART0_Reg0x5 &= ~0x20
#define get_UART0_Reg0x5_UART_TX_STOP_END                       ((addUART0_Reg0x5 & 0x20) >> 5)

#define posUART0_Reg0x5_UART_RX_STOP_END                        6
#define bitUART0_Reg0x5_UART_RX_STOP_END                        0x40
#define set_UART0_Reg0x5_UART_RX_STOP_END(val)                  addUART0_Reg0x5 = ((addUART0_Reg0x5 & (~0x40)) | ((val) << 6))
#define setf_UART0_Reg0x5_UART_RX_STOP_END                      addUART0_Reg0x5 |= 0x40
#define clrf_UART0_Reg0x5_UART_RX_STOP_END                      addUART0_Reg0x5 &= ~0x40
#define get_UART0_Reg0x5_UART_RX_STOP_END                       ((addUART0_Reg0x5 & 0x40) >> 6)

#define posUART0_Reg0x5_UART_RXD_WAKEUP                         7
#define bitUART0_Reg0x5_UART_RXD_WAKEUP                         0x80
#define set_UART0_Reg0x5_UART_RXD_WAKEUP(val)                   addUART0_Reg0x5 = ((addUART0_Reg0x5 & (~0x80)) | ((val) << 7))
#define setf_UART0_Reg0x5_UART_RXD_WAKEUP                       addUART0_Reg0x5 |= 0x80
#define clrf_UART0_Reg0x5_UART_RXD_WAKEUP                       addUART0_Reg0x5 &= ~0x80
#define get_UART0_Reg0x5_UART_RXD_WAKEUP                        ((addUART0_Reg0x5 & 0x80) >> 7)

//addUART0_Reg0x6
#define addUART0_Reg0x6                                         *((volatile unsigned long *) (0x00806300+0x6*4))
#define posUART0_Reg0x6_FLOW_CTL_LOW_CNT                        0
#define bitUART0_Reg0x6_FLOW_CTL_LOW_CNT                        0xFF
#define set_UART0_Reg0x6_FLOW_CTL_LOW_CNT(val)                  addUART0_Reg0x6 = ((addUART0_Reg0x6 & (~0xFF)) | ((val) << 0))
#define get_UART0_Reg0x6_FLOW_CTL_LOW_CNT                       (addUART0_Reg0x6 & 0xFF)

#define posUART0_Reg0x6_FLOW_CTL_HIGH_CNT                       8
#define bitUART0_Reg0x6_FLOW_CTL_HIGH_CNT                       0xFF00
#define set_UART0_Reg0x6_FLOW_CTL_HIGH_CNT(val)                 addUART0_Reg0x6 = ((addUART0_Reg0x6 & (~0xFF00)) | ((val) << 8))
#define get_UART0_Reg0x6_FLOW_CTL_HIGH_CNT                      ((addUART0_Reg0x6 & 0xFF00) >> 8)

#define posUART0_Reg0x6_FLOW_CONTROL_ENA                        16
#define bitUART0_Reg0x6_FLOW_CONTROL_ENA                        0x10000
#define set_UART0_Reg0x6_FLOW_CONTROL_ENA(val)                  addUART0_Reg0x6 = ((addUART0_Reg0x6 & (~0x10000)) | ((val) << 16))
#define setf_UART0_Reg0x6_FLOW_CONTROL_ENA                      addUART0_Reg0x6 |= 0x10000
#define clrf_UART0_Reg0x6_FLOW_CONTROL_ENA                      addUART0_Reg0x6 &= ~0x10000
#define get_UART0_Reg0x6_FLOW_CONTROL_ENA                       ((addUART0_Reg0x6 & 0x10000) >> 16)

#define posUART0_Reg0x6_RTS_POLARITY_SEL                        17
#define bitUART0_Reg0x6_RTS_POLARITY_SEL                        0x20000
#define set_UART0_Reg0x6_RTS_POLARITY_SEL(val)                  addUART0_Reg0x6 = ((addUART0_Reg0x6 & (~0x20000)) | ((val) << 17))
#define setf_UART0_Reg0x6_RTS_POLARITY_SEL                      addUART0_Reg0x6 |= 0x20000
#define clrf_UART0_Reg0x6_RTS_POLARITY_SEL                      addUART0_Reg0x6 &= ~0x20000
#define get_UART0_Reg0x6_RTS_POLARITY_SEL                       ((addUART0_Reg0x6 & 0x20000) >> 17)

#define posUART0_Reg0x6_CTS_POLARITY_SEL                        18
#define bitUART0_Reg0x6_CTS_POLARITY_SEL                        0x40000
#define set_UART0_Reg0x6_CTS_POLARITY_SEL(val)                  addUART0_Reg0x6 = ((addUART0_Reg0x6 & (~0x40000)) | ((val) << 18))
#define setf_UART0_Reg0x6_CTS_POLARITY_SEL                      addUART0_Reg0x6 |= 0x40000
#define clrf_UART0_Reg0x6_CTS_POLARITY_SEL                      addUART0_Reg0x6 &= ~0x40000
#define get_UART0_Reg0x6_CTS_POLARITY_SEL                       ((addUART0_Reg0x6 & 0x40000) >> 18)

//addUART0_Reg0x7
#define addUART0_Reg0x7                                         *((volatile unsigned long *) (0x00806300+0x7*4))
#define posUART0_Reg0x7_UART_WAKE_COUNT                         0
#define bitUART0_Reg0x7_UART_WAKE_COUNT                         0x3FF
#define set_UART0_Reg0x7_UART_WAKE_COUNT(val)                   addUART0_Reg0x7 = ((addUART0_Reg0x7 & (~0x3FF)) | ((val) << 0))
#define get_UART0_Reg0x7_UART_WAKE_COUNT                        (addUART0_Reg0x7 & 0x3FF)

#define posUART0_Reg0x7_UART_TXD_WAIT_CNT                       10
#define bitUART0_Reg0x7_UART_TXD_WAIT_CNT                       0xFFC00
#define set_UART0_Reg0x7_UART_TXD_WAIT_CNT(val)                 addUART0_Reg0x7 = ((addUART0_Reg0x7 & (~0xFFC00)) | ((val) << 10))
#define get_UART0_Reg0x7_UART_TXD_WAIT_CNT                      ((addUART0_Reg0x7 & 0xFFC00) >> 10)

#define posUART0_Reg0x7_UART_RXD_WAKE_EN                        20
#define bitUART0_Reg0x7_UART_RXD_WAKE_EN                        0x100000
#define set_UART0_Reg0x7_UART_RXD_WAKE_EN(val)                  addUART0_Reg0x7 = ((addUART0_Reg0x7 & (~0x100000)) | ((val) << 20))
#define setf_UART0_Reg0x7_UART_RXD_WAKE_EN                      addUART0_Reg0x7 |= 0x100000
#define clrf_UART0_Reg0x7_UART_RXD_WAKE_EN                      addUART0_Reg0x7 &= ~0x100000
#define get_UART0_Reg0x7_UART_RXD_WAKE_EN                       ((addUART0_Reg0x7 & 0x100000) >> 20)

#define posUART0_Reg0x7_UART_TXD_WAKE_EN                        21
#define bitUART0_Reg0x7_UART_TXD_WAKE_EN                        0x200000
#define set_UART0_Reg0x7_UART_TXD_WAKE_EN(val)                  addUART0_Reg0x7 = ((addUART0_Reg0x7 & (~0x200000)) | ((val) << 21))
#define setf_UART0_Reg0x7_UART_TXD_WAKE_EN                      addUART0_Reg0x7 |= 0x200000
#define clrf_UART0_Reg0x7_UART_TXD_WAKE_EN                      addUART0_Reg0x7 &= ~0x200000
#define get_UART0_Reg0x7_UART_TXD_WAKE_EN                       ((addUART0_Reg0x7 & 0x200000) >> 21)

#define posUART0_Reg0x7_RXD_NEGEDGE_WAKE_EN                     22
#define bitUART0_Reg0x7_RXD_NEGEDGE_WAKE_EN                     0x400000
#define set_UART0_Reg0x7_RXD_NEGEDGE_WAKE_EN(val)               addUART0_Reg0x7 = ((addUART0_Reg0x7 & (~0x400000)) | ((val) << 22))
#define setf_UART0_Reg0x7_RXD_NEGEDGE_WAKE_EN                   addUART0_Reg0x7 |= 0x400000
#define clrf_UART0_Reg0x7_RXD_NEGEDGE_WAKE_EN                   addUART0_Reg0x7 &= ~0x400000
#define get_UART0_Reg0x7_RXD_NEGEDGE_WAKE_EN                    ((addUART0_Reg0x7 & 0x400000) >> 22)


//************************************************************//
//UART1
//************************************************************//
#define BASEADDR_UART1                                          0x00806a00
//addUART1_Reg0x0
#define addUART1_Reg0x0                                         *((volatile unsigned long *) (0x00806a00+0x0*4))
#define posUART1_Reg0x0_UART_TX_ENABLE                          0
#define bitUART1_Reg0x0_UART_TX_ENABLE                          0x1
#define set_UART1_Reg0x0_UART_TX_ENABLE(val)                    addUART1_Reg0x0 = ((addUART1_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_UART1_Reg0x0_UART_TX_ENABLE                        addUART1_Reg0x0 |= 0x1
#define clrf_UART1_Reg0x0_UART_TX_ENABLE                        addUART1_Reg0x0 &= ~0x1
#define get_UART1_Reg0x0_UART_TX_ENABLE                         (addUART1_Reg0x0 & 0x1)

#define posUART1_Reg0x0_UART_RX_ENABLE                          1
#define bitUART1_Reg0x0_UART_RX_ENABLE                          0x2
#define set_UART1_Reg0x0_UART_RX_ENABLE(val)                    addUART1_Reg0x0 = ((addUART1_Reg0x0 & (~0x2)) | ((val) << 1))
#define setf_UART1_Reg0x0_UART_RX_ENABLE                        addUART1_Reg0x0 |= 0x2
#define clrf_UART1_Reg0x0_UART_RX_ENABLE                        addUART1_Reg0x0 &= ~0x2
#define get_UART1_Reg0x0_UART_RX_ENABLE                         ((addUART1_Reg0x0 & 0x2) >> 1)

#define posUART1_Reg0x0_UART_IRDA                               2
#define bitUART1_Reg0x0_UART_IRDA                               0x4
#define set_UART1_Reg0x0_UART_IRDA(val)                         addUART1_Reg0x0 = ((addUART1_Reg0x0 & (~0x4)) | ((val) << 2))
#define setf_UART1_Reg0x0_UART_IRDA                             addUART1_Reg0x0 |= 0x4
#define clrf_UART1_Reg0x0_UART_IRDA                             addUART1_Reg0x0 &= ~0x4
#define get_UART1_Reg0x0_UART_IRDA                              ((addUART1_Reg0x0 & 0x4) >> 2)

#define posUART1_Reg0x0_UART_LEN                                3
#define bitUART1_Reg0x0_UART_LEN                                0x18
#define set_UART1_Reg0x0_UART_LEN(val)                          addUART1_Reg0x0 = ((addUART1_Reg0x0 & (~0x18)) | ((val) << 3))
#define get_UART1_Reg0x0_UART_LEN                               ((addUART1_Reg0x0 & 0x18) >> 3)

#define posUART1_Reg0x0_UART_PAR_EN                             5
#define bitUART1_Reg0x0_UART_PAR_EN                             0x20
#define set_UART1_Reg0x0_UART_PAR_EN(val)                       addUART1_Reg0x0 = ((addUART1_Reg0x0 & (~0x20)) | ((val) << 5))
#define setf_UART1_Reg0x0_UART_PAR_EN                           addUART1_Reg0x0 |= 0x20
#define clrf_UART1_Reg0x0_UART_PAR_EN                           addUART1_Reg0x0 &= ~0x20
#define get_UART1_Reg0x0_UART_PAR_EN                            ((addUART1_Reg0x0 & 0x20) >> 5)

#define posUART1_Reg0x0_UART_PAR_MODE                           6
#define bitUART1_Reg0x0_UART_PAR_MODE                           0x40
#define set_UART1_Reg0x0_UART_PAR_MODE(val)                     addUART1_Reg0x0 = ((addUART1_Reg0x0 & (~0x40)) | ((val) << 6))
#define setf_UART1_Reg0x0_UART_PAR_MODE                         addUART1_Reg0x0 |= 0x40
#define clrf_UART1_Reg0x0_UART_PAR_MODE                         addUART1_Reg0x0 &= ~0x40
#define get_UART1_Reg0x0_UART_PAR_MODE                          ((addUART1_Reg0x0 & 0x40) >> 6)

#define posUART1_Reg0x0_UART_STOP_LEN                           7
#define bitUART1_Reg0x0_UART_STOP_LEN                           0x80
#define set_UART1_Reg0x0_UART_STOP_LEN(val)                     addUART1_Reg0x0 = ((addUART1_Reg0x0 & (~0x80)) | ((val) << 7))
#define setf_UART1_Reg0x0_UART_STOP_LEN                         addUART1_Reg0x0 |= 0x80
#define clrf_UART1_Reg0x0_UART_STOP_LEN                         addUART1_Reg0x0 &= ~0x80
#define get_UART1_Reg0x0_UART_STOP_LEN                          ((addUART1_Reg0x0 & 0x80) >> 7)

#define posUART1_Reg0x0_UART_CLK_DIVID                          8
#define bitUART1_Reg0x0_UART_CLK_DIVID                          0x1FFF00
#define set_UART1_Reg0x0_UART_CLK_DIVID(val)                    addUART1_Reg0x0 = ((addUART1_Reg0x0 & (~0x1FFF00)) | ((val) << 8))
#define get_UART1_Reg0x0_UART_CLK_DIVID                         ((addUART1_Reg0x0 & 0x1FFF00) >> 8)

//addUART1_Reg0x1
#define addUART1_Reg0x1                                         *((volatile unsigned long *) (0x00806a00+0x1*4))
#define posUART1_Reg0x1_TX_FIFO_THRESHOLD                       0
#define bitUART1_Reg0x1_TX_FIFO_THRESHOLD                       0xFF
#define set_UART1_Reg0x1_TX_FIFO_THRESHOLD(val)                 addUART1_Reg0x1 = ((addUART1_Reg0x1 & (~0xFF)) | ((val) << 0))
#define get_UART1_Reg0x1_TX_FIFO_THRESHOLD                      (addUART1_Reg0x1 & 0xFF)

#define posUART1_Reg0x1_RX_FIFO_THRESHOLD                       8
#define bitUART1_Reg0x1_RX_FIFO_THRESHOLD                       0xFF00
#define set_UART1_Reg0x1_RX_FIFO_THRESHOLD(val)                 addUART1_Reg0x1 = ((addUART1_Reg0x1 & (~0xFF00)) | ((val) << 8))
#define get_UART1_Reg0x1_RX_FIFO_THRESHOLD                      ((addUART1_Reg0x1 & 0xFF00) >> 8)

#define posUART1_Reg0x1_RX_STOP_DETECT_TIME                     16
#define bitUART1_Reg0x1_RX_STOP_DETECT_TIME                     0x30000
#define set_UART1_Reg0x1_RX_STOP_DETECT_TIME(val)               addUART1_Reg0x1 = ((addUART1_Reg0x1 & (~0x30000)) | ((val) << 16))
#define get_UART1_Reg0x1_RX_STOP_DETECT_TIME                    ((addUART1_Reg0x1 & 0x30000) >> 16)

//addUART1_Reg0x2
#define addUART1_Reg0x2                                         *((volatile unsigned long *) (0x00806a00+0x2*4))
#define posUART1_Reg0x2_TX_FIFO_COUNT                           0
#define bitUART1_Reg0x2_TX_FIFO_COUNT                           0xFF
#define get_UART1_Reg0x2_TX_FIFO_COUNT                          (addUART1_Reg0x2 & 0xFF)

#define posUART1_Reg0x2_RX_FIFO_COUNT                           8
#define bitUART1_Reg0x2_RX_FIFO_COUNT                           0xFF00
#define get_UART1_Reg0x2_RX_FIFO_COUNT                          ((addUART1_Reg0x2 & 0xFF00) >> 8)

#define posUART1_Reg0x2_TX_FIFO_FULL                            16
#define bitUART1_Reg0x2_TX_FIFO_FULL                            0x10000
#define get_UART1_Reg0x2_TX_FIFO_FULL                           ((addUART1_Reg0x2 & 0x10000) >> 16)

#define posUART1_Reg0x2_TX_FIFO_EMPTY                           17
#define bitUART1_Reg0x2_TX_FIFO_EMPTY                           0x20000
#define get_UART1_Reg0x2_TX_FIFO_EMPTY                          ((addUART1_Reg0x2 & 0x20000) >> 17)

#define posUART1_Reg0x2_RX_FIFO_FULL                            18
#define bitUART1_Reg0x2_RX_FIFO_FULL                            0x40000
#define get_UART1_Reg0x2_RX_FIFO_FULL                           ((addUART1_Reg0x2 & 0x40000) >> 18)

#define posUART1_Reg0x2_RX_FIFO_EMPTY                           19
#define bitUART1_Reg0x2_RX_FIFO_EMPTY                           0x80000
#define get_UART1_Reg0x2_RX_FIFO_EMPTY                          ((addUART1_Reg0x2 & 0x80000) >> 19)

#define posUART1_Reg0x2_FIFO_WR_READY                           20
#define bitUART1_Reg0x2_FIFO_WR_READY                           0x100000
#define get_UART1_Reg0x2_FIFO_WR_READY                          ((addUART1_Reg0x2 & 0x100000) >> 20)

#define posUART1_Reg0x2_FIFO_RD_READY                           21
#define bitUART1_Reg0x2_FIFO_RD_READY                           0x200000
#define get_UART1_Reg0x2_FIFO_RD_READY                          ((addUART1_Reg0x2 & 0x200000) >> 21)

//addUART1_Reg0x3
#define addUART1_Reg0x3                                         *((volatile unsigned long *) (0x00806a00+0x3*4))
#define posUART1_Reg0x3_UART_TX_FIFO_DIN                        0
#define bitUART1_Reg0x3_UART_TX_FIFO_DIN                        0xFF
#define set_UART1_Reg0x3_UART_TX_FIFO_DIN(val)                  addUART1_Reg0x3 = ((addUART1_Reg0x3 & (~0xFF)) | ((val) << 0))
#define get_UART1_Reg0x3_UART_TX_FIFO_DIN                       (addUART1_Reg0x3 & 0xFF)

#define posUART1_Reg0x3_UART_RX_FIFO_DOUT                       8
#define bitUART1_Reg0x3_UART_RX_FIFO_DOUT                       0xFF00
#define get_UART1_Reg0x3_UART_RX_FIFO_DOUT                      ((addUART1_Reg0x3 & 0xFF00) >> 8)

//addUART1_Reg0x4
#define addUART1_Reg0x4                                         *((volatile unsigned long *) (0x00806a00+0x4*4))
#define posUART1_Reg0x4_TX_FIFO_NEED_WRITE_MASK                 0
#define bitUART1_Reg0x4_TX_FIFO_NEED_WRITE_MASK                 0x1
#define set_UART1_Reg0x4_TX_FIFO_NEED_WRITE_MASK(val)           addUART1_Reg0x4 = ((addUART1_Reg0x4 & (~0x1)) | ((val) << 0))
#define setf_UART1_Reg0x4_TX_FIFO_NEED_WRITE_MASK               addUART1_Reg0x4 |= 0x1
#define clrf_UART1_Reg0x4_TX_FIFO_NEED_WRITE_MASK               addUART1_Reg0x4 &= ~0x1
#define get_UART1_Reg0x4_TX_FIFO_NEED_WRITE_MASK                (addUART1_Reg0x4 & 0x1)

#define posUART1_Reg0x4_RX_FIFO_NEED_READ_MASK                  1
#define bitUART1_Reg0x4_RX_FIFO_NEED_READ_MASK                  0x2
#define set_UART1_Reg0x4_RX_FIFO_NEED_READ_MASK(val)            addUART1_Reg0x4 = ((addUART1_Reg0x4 & (~0x2)) | ((val) << 1))
#define setf_UART1_Reg0x4_RX_FIFO_NEED_READ_MASK                addUART1_Reg0x4 |= 0x2
#define clrf_UART1_Reg0x4_RX_FIFO_NEED_READ_MASK                addUART1_Reg0x4 &= ~0x2
#define get_UART1_Reg0x4_RX_FIFO_NEED_READ_MASK                 ((addUART1_Reg0x4 & 0x2) >> 1)

#define posUART1_Reg0x4_RX_FIFO_OVER_FLOW_MASK                  2
#define bitUART1_Reg0x4_RX_FIFO_OVER_FLOW_MASK                  0x4
#define set_UART1_Reg0x4_RX_FIFO_OVER_FLOW_MASK(val)            addUART1_Reg0x4 = ((addUART1_Reg0x4 & (~0x4)) | ((val) << 2))
#define setf_UART1_Reg0x4_RX_FIFO_OVER_FLOW_MASK                addUART1_Reg0x4 |= 0x4
#define clrf_UART1_Reg0x4_RX_FIFO_OVER_FLOW_MASK                addUART1_Reg0x4 &= ~0x4
#define get_UART1_Reg0x4_RX_FIFO_OVER_FLOW_MASK                 ((addUART1_Reg0x4 & 0x4) >> 2)

#define posUART1_Reg0x4_UART_RX_PARITY_ERR_MASK                 3
#define bitUART1_Reg0x4_UART_RX_PARITY_ERR_MASK                 0x8
#define set_UART1_Reg0x4_UART_RX_PARITY_ERR_MASK(val)           addUART1_Reg0x4 = ((addUART1_Reg0x4 & (~0x8)) | ((val) << 3))
#define setf_UART1_Reg0x4_UART_RX_PARITY_ERR_MASK               addUART1_Reg0x4 |= 0x8
#define clrf_UART1_Reg0x4_UART_RX_PARITY_ERR_MASK               addUART1_Reg0x4 &= ~0x8
#define get_UART1_Reg0x4_UART_RX_PARITY_ERR_MASK                ((addUART1_Reg0x4 & 0x8) >> 3)

#define posUART1_Reg0x4_UART_RX_STOP_ERR_MASK                   4
#define bitUART1_Reg0x4_UART_RX_STOP_ERR_MASK                   0x10
#define set_UART1_Reg0x4_UART_RX_STOP_ERR_MASK(val)             addUART1_Reg0x4 = ((addUART1_Reg0x4 & (~0x10)) | ((val) << 4))
#define setf_UART1_Reg0x4_UART_RX_STOP_ERR_MASK                 addUART1_Reg0x4 |= 0x10
#define clrf_UART1_Reg0x4_UART_RX_STOP_ERR_MASK                 addUART1_Reg0x4 &= ~0x10
#define get_UART1_Reg0x4_UART_RX_STOP_ERR_MASK                  ((addUART1_Reg0x4 & 0x10) >> 4)

#define posUART1_Reg0x4_UART_TX_STOP_END_MASK                   5
#define bitUART1_Reg0x4_UART_TX_STOP_END_MASK                   0x20
#define set_UART1_Reg0x4_UART_TX_STOP_END_MASK(val)             addUART1_Reg0x4 = ((addUART1_Reg0x4 & (~0x20)) | ((val) << 5))
#define setf_UART1_Reg0x4_UART_TX_STOP_END_MASK                 addUART1_Reg0x4 |= 0x20
#define clrf_UART1_Reg0x4_UART_TX_STOP_END_MASK                 addUART1_Reg0x4 &= ~0x20
#define get_UART1_Reg0x4_UART_TX_STOP_END_MASK                  ((addUART1_Reg0x4 & 0x20) >> 5)

#define posUART1_Reg0x4_UART_RX_STOP_END_MASK                   6
#define bitUART1_Reg0x4_UART_RX_STOP_END_MASK                   0x40
#define set_UART1_Reg0x4_UART_RX_STOP_END_MASK(val)             addUART1_Reg0x4 = ((addUART1_Reg0x4 & (~0x40)) | ((val) << 6))
#define setf_UART1_Reg0x4_UART_RX_STOP_END_MASK                 addUART1_Reg0x4 |= 0x40
#define clrf_UART1_Reg0x4_UART_RX_STOP_END_MASK                 addUART1_Reg0x4 &= ~0x40
#define get_UART1_Reg0x4_UART_RX_STOP_END_MASK                  ((addUART1_Reg0x4 & 0x40) >> 6)

#define posUART1_Reg0x4_UART_RXD_WAKEUP_MASK                    7
#define bitUART1_Reg0x4_UART_RXD_WAKEUP_MASK                    0x80
#define set_UART1_Reg0x4_UART_RXD_WAKEUP_MASK(val)              addUART1_Reg0x4 = ((addUART1_Reg0x4 & (~0x80)) | ((val) << 7))
#define setf_UART1_Reg0x4_UART_RXD_WAKEUP_MASK                  addUART1_Reg0x4 |= 0x80
#define clrf_UART1_Reg0x4_UART_RXD_WAKEUP_MASK                  addUART1_Reg0x4 &= ~0x80
#define get_UART1_Reg0x4_UART_RXD_WAKEUP_MASK                   ((addUART1_Reg0x4 & 0x80) >> 7)

//addUART1_Reg0x5
#define addUART1_Reg0x5                                         *((volatile unsigned long *) (0x00806a00+0x5*4))
#define posUART1_Reg0x5_TX_FIFO_NEED_WRITE                      0
#define bitUART1_Reg0x5_TX_FIFO_NEED_WRITE                      0x1
#define get_UART1_Reg0x5_TX_FIFO_NEED_WRITE                     (addUART1_Reg0x5 & 0x1)

#define posUART1_Reg0x5_RX_FIFO_NEED_READ                       1
#define bitUART1_Reg0x5_RX_FIFO_NEED_READ                       0x2
#define get_UART1_Reg0x5_RX_FIFO_NEED_READ                      ((addUART1_Reg0x5 & 0x2) >> 1)

#define posUART1_Reg0x5_RX_FIFO_OVER_FLOW                       2
#define bitUART1_Reg0x5_RX_FIFO_OVER_FLOW                       0x4
#define set_UART1_Reg0x5_RX_FIFO_OVER_FLOW(val)                 addUART1_Reg0x5 = ((addUART1_Reg0x5 & (~0x4)) | ((val) << 2))
#define setf_UART1_Reg0x5_RX_FIFO_OVER_FLOW                     addUART1_Reg0x5 |= 0x4
#define clrf_UART1_Reg0x5_RX_FIFO_OVER_FLOW                     addUART1_Reg0x5 &= ~0x4
#define get_UART1_Reg0x5_RX_FIFO_OVER_FLOW                      ((addUART1_Reg0x5 & 0x4) >> 2)

#define posUART1_Reg0x5_UART_RX_PARITY_ERROR                    3
#define bitUART1_Reg0x5_UART_RX_PARITY_ERROR                    0x8
#define set_UART1_Reg0x5_UART_RX_PARITY_ERROR(val)              addUART1_Reg0x5 = ((addUART1_Reg0x5 & (~0x8)) | ((val) << 3))
#define setf_UART1_Reg0x5_UART_RX_PARITY_ERROR                  addUART1_Reg0x5 |= 0x8
#define clrf_UART1_Reg0x5_UART_RX_PARITY_ERROR                  addUART1_Reg0x5 &= ~0x8
#define get_UART1_Reg0x5_UART_RX_PARITY_ERROR                   ((addUART1_Reg0x5 & 0x8) >> 3)

#define posUART1_Reg0x5_UART_RX_STOP_ERROR                      4
#define bitUART1_Reg0x5_UART_RX_STOP_ERROR                      0x10
#define set_UART1_Reg0x5_UART_RX_STOP_ERROR(val)                addUART1_Reg0x5 = ((addUART1_Reg0x5 & (~0x10)) | ((val) << 4))
#define setf_UART1_Reg0x5_UART_RX_STOP_ERROR                    addUART1_Reg0x5 |= 0x10
#define clrf_UART1_Reg0x5_UART_RX_STOP_ERROR                    addUART1_Reg0x5 &= ~0x10
#define get_UART1_Reg0x5_UART_RX_STOP_ERROR                     ((addUART1_Reg0x5 & 0x10) >> 4)

#define posUART1_Reg0x5_UART_TX_STOP_END                        5
#define bitUART1_Reg0x5_UART_TX_STOP_END                        0x20
#define set_UART1_Reg0x5_UART_TX_STOP_END(val)                  addUART1_Reg0x5 = ((addUART1_Reg0x5 & (~0x20)) | ((val) << 5))
#define setf_UART1_Reg0x5_UART_TX_STOP_END                      addUART1_Reg0x5 |= 0x20
#define clrf_UART1_Reg0x5_UART_TX_STOP_END                      addUART1_Reg0x5 &= ~0x20
#define get_UART1_Reg0x5_UART_TX_STOP_END                       ((addUART1_Reg0x5 & 0x20) >> 5)

#define posUART1_Reg0x5_UART_RX_STOP_END                        6
#define bitUART1_Reg0x5_UART_RX_STOP_END                        0x40
#define set_UART1_Reg0x5_UART_RX_STOP_END(val)                  addUART1_Reg0x5 = ((addUART1_Reg0x5 & (~0x40)) | ((val) << 6))
#define setf_UART1_Reg0x5_UART_RX_STOP_END                      addUART1_Reg0x5 |= 0x40
#define clrf_UART1_Reg0x5_UART_RX_STOP_END                      addUART1_Reg0x5 &= ~0x40
#define get_UART1_Reg0x5_UART_RX_STOP_END                       ((addUART1_Reg0x5 & 0x40) >> 6)

#define posUART1_Reg0x5_UART_RXD_WAKEUP                         7
#define bitUART1_Reg0x5_UART_RXD_WAKEUP                         0x80
#define set_UART1_Reg0x5_UART_RXD_WAKEUP(val)                   addUART1_Reg0x5 = ((addUART1_Reg0x5 & (~0x80)) | ((val) << 7))
#define setf_UART1_Reg0x5_UART_RXD_WAKEUP                       addUART1_Reg0x5 |= 0x80
#define clrf_UART1_Reg0x5_UART_RXD_WAKEUP                       addUART1_Reg0x5 &= ~0x80
#define get_UART1_Reg0x5_UART_RXD_WAKEUP                        ((addUART1_Reg0x5 & 0x80) >> 7)

//addUART1_Reg0x6
#define addUART1_Reg0x6                                         *((volatile unsigned long *) (0x00806a00+0x6*4))
#define posUART1_Reg0x6_FLOW_CTL_LOW_CNT                        0
#define bitUART1_Reg0x6_FLOW_CTL_LOW_CNT                        0xFF
#define set_UART1_Reg0x6_FLOW_CTL_LOW_CNT(val)                  addUART1_Reg0x6 = ((addUART1_Reg0x6 & (~0xFF)) | ((val) << 0))
#define get_UART1_Reg0x6_FLOW_CTL_LOW_CNT                       (addUART1_Reg0x6 & 0xFF)

#define posUART1_Reg0x6_FLOW_CTL_HIGH_CNT                       8
#define bitUART1_Reg0x6_FLOW_CTL_HIGH_CNT                       0xFF00
#define set_UART1_Reg0x6_FLOW_CTL_HIGH_CNT(val)                 addUART1_Reg0x6 = ((addUART1_Reg0x6 & (~0xFF00)) | ((val) << 8))
#define get_UART1_Reg0x6_FLOW_CTL_HIGH_CNT                      ((addUART1_Reg0x6 & 0xFF00) >> 8)

#define posUART1_Reg0x6_FLOW_CONTROL_ENA                        16
#define bitUART1_Reg0x6_FLOW_CONTROL_ENA                        0x10000
#define set_UART1_Reg0x6_FLOW_CONTROL_ENA(val)                  addUART1_Reg0x6 = ((addUART1_Reg0x6 & (~0x10000)) | ((val) << 16))
#define setf_UART1_Reg0x6_FLOW_CONTROL_ENA                      addUART1_Reg0x6 |= 0x10000
#define clrf_UART1_Reg0x6_FLOW_CONTROL_ENA                      addUART1_Reg0x6 &= ~0x10000
#define get_UART1_Reg0x6_FLOW_CONTROL_ENA                       ((addUART1_Reg0x6 & 0x10000) >> 16)

#define posUART1_Reg0x6_RTS_POLARITY_SEL                        17
#define bitUART1_Reg0x6_RTS_POLARITY_SEL                        0x20000
#define set_UART1_Reg0x6_RTS_POLARITY_SEL(val)                  addUART1_Reg0x6 = ((addUART1_Reg0x6 & (~0x20000)) | ((val) << 17))
#define setf_UART1_Reg0x6_RTS_POLARITY_SEL                      addUART1_Reg0x6 |= 0x20000
#define clrf_UART1_Reg0x6_RTS_POLARITY_SEL                      addUART1_Reg0x6 &= ~0x20000
#define get_UART1_Reg0x6_RTS_POLARITY_SEL                       ((addUART1_Reg0x6 & 0x20000) >> 17)

#define posUART1_Reg0x6_CTS_POLARITY_SEL                        18
#define bitUART1_Reg0x6_CTS_POLARITY_SEL                        0x40000
#define set_UART1_Reg0x6_CTS_POLARITY_SEL(val)                  addUART1_Reg0x6 = ((addUART1_Reg0x6 & (~0x40000)) | ((val) << 18))
#define setf_UART1_Reg0x6_CTS_POLARITY_SEL                      addUART1_Reg0x6 |= 0x40000
#define clrf_UART1_Reg0x6_CTS_POLARITY_SEL                      addUART1_Reg0x6 &= ~0x40000
#define get_UART1_Reg0x6_CTS_POLARITY_SEL                       ((addUART1_Reg0x6 & 0x40000) >> 18)

//addUART1_Reg0x7
#define addUART1_Reg0x7                                         *((volatile unsigned long *) (0x00806a00+0x7*4))
#define posUART1_Reg0x7_UART_WAKE_COUNT                         0
#define bitUART1_Reg0x7_UART_WAKE_COUNT                         0x3FF
#define set_UART1_Reg0x7_UART_WAKE_COUNT(val)                   addUART1_Reg0x7 = ((addUART1_Reg0x7 & (~0x3FF)) | ((val) << 0))
#define get_UART1_Reg0x7_UART_WAKE_COUNT                        (addUART1_Reg0x7 & 0x3FF)

#define posUART1_Reg0x7_UART_TXD_WAIT_CNT                       10
#define bitUART1_Reg0x7_UART_TXD_WAIT_CNT                       0xFFC00
#define set_UART1_Reg0x7_UART_TXD_WAIT_CNT(val)                 addUART1_Reg0x7 = ((addUART1_Reg0x7 & (~0xFFC00)) | ((val) << 10))
#define get_UART1_Reg0x7_UART_TXD_WAIT_CNT                      ((addUART1_Reg0x7 & 0xFFC00) >> 10)

#define posUART1_Reg0x7_UART_RXD_WAKE_EN                        20
#define bitUART1_Reg0x7_UART_RXD_WAKE_EN                        0x100000
#define set_UART1_Reg0x7_UART_RXD_WAKE_EN(val)                  addUART1_Reg0x7 = ((addUART1_Reg0x7 & (~0x100000)) | ((val) << 20))
#define setf_UART1_Reg0x7_UART_RXD_WAKE_EN                      addUART1_Reg0x7 |= 0x100000
#define clrf_UART1_Reg0x7_UART_RXD_WAKE_EN                      addUART1_Reg0x7 &= ~0x100000
#define get_UART1_Reg0x7_UART_RXD_WAKE_EN                       ((addUART1_Reg0x7 & 0x100000) >> 20)

#define posUART1_Reg0x7_UART_TXD_WAKE_EN                        21
#define bitUART1_Reg0x7_UART_TXD_WAKE_EN                        0x200000
#define set_UART1_Reg0x7_UART_TXD_WAKE_EN(val)                  addUART1_Reg0x7 = ((addUART1_Reg0x7 & (~0x200000)) | ((val) << 21))
#define setf_UART1_Reg0x7_UART_TXD_WAKE_EN                      addUART1_Reg0x7 |= 0x200000
#define clrf_UART1_Reg0x7_UART_TXD_WAKE_EN                      addUART1_Reg0x7 &= ~0x200000
#define get_UART1_Reg0x7_UART_TXD_WAKE_EN                       ((addUART1_Reg0x7 & 0x200000) >> 21)

#define posUART1_Reg0x7_RXD_NEGEDGE_WAKE_EN                     22
#define bitUART1_Reg0x7_RXD_NEGEDGE_WAKE_EN                     0x400000
#define set_UART1_Reg0x7_RXD_NEGEDGE_WAKE_EN(val)               addUART1_Reg0x7 = ((addUART1_Reg0x7 & (~0x400000)) | ((val) << 22))
#define setf_UART1_Reg0x7_RXD_NEGEDGE_WAKE_EN                   addUART1_Reg0x7 |= 0x400000
#define clrf_UART1_Reg0x7_RXD_NEGEDGE_WAKE_EN                   addUART1_Reg0x7 &= ~0x400000
#define get_UART1_Reg0x7_RXD_NEGEDGE_WAKE_EN                    ((addUART1_Reg0x7 & 0x400000) >> 22)


//************************************************************//
//I2C0
//************************************************************//
#define BASEADDR_I2C0                                           0x00806400
//addI2C0_Reg0x0
#define addI2C0_Reg0x0                                          *((volatile unsigned long *) (0x00806400+0x0*4))
#define posI2C0_Reg0x0_ENSMB                                    31
#define bitI2C0_Reg0x0_ENSMB                                    0x80000000
#define set_I2C0_Reg0x0_ENSMB(val)                              addI2C0_Reg0x0 = ((addI2C0_Reg0x0 & (~0x80000000)) | ((val) << 31))
#define setf_I2C0_Reg0x0_ENSMB                                  addI2C0_Reg0x0 |= 0x80000000
#define clrf_I2C0_Reg0x0_ENSMB                                  addI2C0_Reg0x0 &= ~0x80000000
#define get_I2C0_Reg0x0_ENSMB                                   ((addI2C0_Reg0x0 & 0x80000000) >> 31)

#define posI2C0_Reg0x0_INH                                      30
#define bitI2C0_Reg0x0_INH                                      0x40000000
#define set_I2C0_Reg0x0_INH(val)                                addI2C0_Reg0x0 = ((addI2C0_Reg0x0 & (~0x40000000)) | ((val) << 30))
#define setf_I2C0_Reg0x0_INH                                    addI2C0_Reg0x0 |= 0x40000000
#define clrf_I2C0_Reg0x0_INH                                    addI2C0_Reg0x0 &= ~0x40000000
#define get_I2C0_Reg0x0_INH                                     ((addI2C0_Reg0x0 & 0x40000000) >> 30)

#define posI2C0_Reg0x0_SMBFTE                                   29
#define bitI2C0_Reg0x0_SMBFTE                                   0x20000000
#define set_I2C0_Reg0x0_SMBFTE(val)                             addI2C0_Reg0x0 = ((addI2C0_Reg0x0 & (~0x20000000)) | ((val) << 29))
#define setf_I2C0_Reg0x0_SMBFTE                                 addI2C0_Reg0x0 |= 0x20000000
#define clrf_I2C0_Reg0x0_SMBFTE                                 addI2C0_Reg0x0 &= ~0x20000000
#define get_I2C0_Reg0x0_SMBFTE                                  ((addI2C0_Reg0x0 & 0x20000000) >> 29)

#define posI2C0_Reg0x0_SMBTOE                                   28
#define bitI2C0_Reg0x0_SMBTOE                                   0x10000000
#define set_I2C0_Reg0x0_SMBTOE(val)                             addI2C0_Reg0x0 = ((addI2C0_Reg0x0 & (~0x10000000)) | ((val) << 28))
#define setf_I2C0_Reg0x0_SMBTOE                                 addI2C0_Reg0x0 |= 0x10000000
#define clrf_I2C0_Reg0x0_SMBTOE                                 addI2C0_Reg0x0 &= ~0x10000000
#define get_I2C0_Reg0x0_SMBTOE                                  ((addI2C0_Reg0x0 & 0x10000000) >> 28)

#define posI2C0_Reg0x0_SMBCS                                    26
#define bitI2C0_Reg0x0_SMBCS                                    0xC000000
#define set_I2C0_Reg0x0_SMBCS(val)                              addI2C0_Reg0x0 = ((addI2C0_Reg0x0 & (~0xC000000)) | ((val) << 26))
#define get_I2C0_Reg0x0_SMBCS                                   ((addI2C0_Reg0x0 & 0xC000000) >> 26)

#define posI2C0_Reg0x0_SLV_ADDR                                 16
#define bitI2C0_Reg0x0_SLV_ADDR                                 0x3FF0000
#define set_I2C0_Reg0x0_SLV_ADDR(val)                           addI2C0_Reg0x0 = ((addI2C0_Reg0x0 & (~0x3FF0000)) | ((val) << 16))
#define get_I2C0_Reg0x0_SLV_ADDR                                ((addI2C0_Reg0x0 & 0x3FF0000) >> 16)

#define posI2C0_Reg0x0_FREQ_DIV                                 6
#define bitI2C0_Reg0x0_FREQ_DIV                                 0xFFC0
#define set_I2C0_Reg0x0_FREQ_DIV(val)                           addI2C0_Reg0x0 = ((addI2C0_Reg0x0 & (~0xFFC0)) | ((val) << 6))
#define get_I2C0_Reg0x0_FREQ_DIV                                ((addI2C0_Reg0x0 & 0xFFC0) >> 6)

#define posI2C0_Reg0x0_SCL_CR                                   3
#define bitI2C0_Reg0x0_SCL_CR                                   0x38
#define set_I2C0_Reg0x0_SCL_CR(val)                             addI2C0_Reg0x0 = ((addI2C0_Reg0x0 & (~0x38)) | ((val) << 3))
#define get_I2C0_Reg0x0_SCL_CR                                  ((addI2C0_Reg0x0 & 0x38) >> 3)

#define posI2C0_Reg0x0_IDLE_CR                                  0
#define bitI2C0_Reg0x0_IDLE_CR                                  0x7
#define set_I2C0_Reg0x0_IDLE_CR(val)                            addI2C0_Reg0x0 = ((addI2C0_Reg0x0 & (~0x7)) | ((val) << 0))
#define get_I2C0_Reg0x0_IDLE_CR                                 (addI2C0_Reg0x0 & 0x7)

//addI2C0_Reg0x1
#define addI2C0_Reg0x1                                          *((volatile unsigned long *) (0x00806400+0x1*4))

#define posI2C0_Reg0x1_BUSY                                     15
#define bitI2C0_Reg0x1_BUSY                                     0x8000
#define get_I2C0_Reg0x1_BUSY                                    ((addI2C0_Reg0x1 & 0x8000) >> 15)

#define posI2C0_Reg0x1_MASTER                                   14
#define bitI2C0_Reg0x1_MASTER                                   0x4000
#define get_I2C0_Reg0x1_MASTER                                  ((addI2C0_Reg0x1 & 0x4000) >> 14)

#define posI2C0_Reg0x1_TXMODE                                   13
#define bitI2C0_Reg0x1_TXMODE                                   0x2000
#define get_I2C0_Reg0x1_TXMODE                                  ((addI2C0_Reg0x1 & 0x2000) >> 13)

#define posI2C0_Reg0x1_ACKRQ                                    12
#define bitI2C0_Reg0x1_ACKRQ                                    0x1000
#define get_I2C0_Reg0x1_ACKRQ                                   ((addI2C0_Reg0x1 & 0x1000) >> 12)

#define posI2C0_Reg0x1_ADDR_MATCH                               11
#define bitI2C0_Reg0x1_ADDR_MATCH                               0x800
#define get_I2C0_Reg0x1_ADDR_MATCH                              ((addI2C0_Reg0x1 & 0x800) >> 11)

#define posI2C0_Reg0x1_STA                                      10
#define bitI2C0_Reg0x1_STA                                      0x400
#define set_I2C0_Reg0x1_STA(val)                                addI2C0_Reg0x1 = ((addI2C0_Reg0x1 & (~0x400)) | ((val) << 10))
#define setf_I2C0_Reg0x1_STA                                    addI2C0_Reg0x1 |= 0x400
#define clrf_I2C0_Reg0x1_STA                                    addI2C0_Reg0x1 &= ~0x400
#define get_I2C0_Reg0x1_STA                                     ((addI2C0_Reg0x1 & 0x400) >> 10)

#define posI2C0_Reg0x1_STO                                      9
#define bitI2C0_Reg0x1_STO                                      0x200
#define set_I2C0_Reg0x1_STO(val)                                addI2C0_Reg0x1 = ((addI2C0_Reg0x1 & (~0x200)) | ((val) << 9))
#define setf_I2C0_Reg0x1_STO                                    addI2C0_Reg0x1 |= 0x200
#define clrf_I2C0_Reg0x1_STO                                    addI2C0_Reg0x1 &= ~0x200
#define get_I2C0_Reg0x1_STO                                     ((addI2C0_Reg0x1 & 0x200) >> 9)

#define posI2C0_Reg0x1_ACK                                      8
#define bitI2C0_Reg0x1_ACK                                      0x100
#define set_I2C0_Reg0x1_ACK(val)                                addI2C0_Reg0x1 = ((addI2C0_Reg0x1 & (~0x100)) | ((val) << 8))
#define setf_I2C0_Reg0x1_ACK                                    addI2C0_Reg0x1 |= 0x100
#define clrf_I2C0_Reg0x1_ACK                                    addI2C0_Reg0x1 &= ~0x100
#define get_I2C0_Reg0x1_ACK                                     ((addI2C0_Reg0x1 & 0x100) >> 8)

#define posI2C0_Reg0x1_INT_MODE                                 6
#define bitI2C0_Reg0x1_INT_MODE                                 0xC0
#define set_I2C0_Reg0x1_INT_MODE(val)                           addI2C0_Reg0x1 = ((addI2C0_Reg0x1 & (~0xC0)) | ((val) << 6))
#define get_I2C0_Reg0x1_INT_MODE                                ((addI2C0_Reg0x1 & 0xC0) >> 6)

#define posI2C0_Reg0x1_TXFIFO_FULL                              5
#define bitI2C0_Reg0x1_TXFIFO_FULL                              0x20
#define get_I2C0_Reg0x1_TXFIFO_FULL                             ((addI2C0_Reg0x1 & 0x20) >> 5)

#define posI2C0_Reg0x1_RXFIFO_EMPTY                             4
#define bitI2C0_Reg0x1_RXFIFO_EMPTY                             0x10
#define get_I2C0_Reg0x1_RXFIFO_EMPTY                            ((addI2C0_Reg0x1 & 0x10) >> 4)

#define posI2C0_Reg0x1_ARBLOST                                  3
#define bitI2C0_Reg0x1_ARBLOST                                  0x8
#define set_I2C0_Reg0x1_ARBLOST(val)                            addI2C0_Reg0x1 = ((addI2C0_Reg0x1 & (~0x8)) | ((val) << 3))
#define setf_I2C0_Reg0x1_ARBLOST                                addI2C0_Reg0x1 |= 0x8
#define clrf_I2C0_Reg0x1_ARBLOST                                addI2C0_Reg0x1 &= ~0x8
#define get_I2C0_Reg0x1_ARBLOST                                 ((addI2C0_Reg0x1 & 0x8) >> 3)


#define posI2C0_Reg0x1_SCL_TMOT                                 1
#define bitI2C0_Reg0x1_SCL_TMOT                                 0x2
#define set_I2C0_Reg0x1_SCL_TMOT(val)                           addI2C0_Reg0x1 = ((addI2C0_Reg0x1 & (~0x2)) | ((val) << 1))
#define setf_I2C0_Reg0x1_SCL_TMOT                               addI2C0_Reg0x1 |= 0x2
#define clrf_I2C0_Reg0x1_SCL_TMOT                               addI2C0_Reg0x1 &= ~0x2
#define get_I2C0_Reg0x1_SCL_TMOT                                ((addI2C0_Reg0x1 & 0x2) >> 1)

#define posI2C0_Reg0x1_SI                                       0
#define bitI2C0_Reg0x1_SI                                       0x1
#define set_I2C0_Reg0x1_SI(val)                                 addI2C0_Reg0x1 = ((addI2C0_Reg0x1 & (~0x1)) | ((val) << 0))
#define setf_I2C0_Reg0x1_SI                                     addI2C0_Reg0x1 |= 0x1
#define clrf_I2C0_Reg0x1_SI                                     addI2C0_Reg0x1 &= ~0x1
#define get_I2C0_Reg0x1_SI                                      (addI2C0_Reg0x1 & 0x1)

//addI2C0_Reg0x2
#define addI2C0_Reg0x2                                          *((volatile unsigned long *) (0x00806400+0x2*4))

#define posI2C0_Reg0x2_SMB_DAT                                  0
#define bitI2C0_Reg0x2_SMB_DAT                                  0xFF
#define set_I2C0_Reg0x2_SMB_DAT(val)                            addI2C0_Reg0x2 = ((addI2C0_Reg0x2 & (~0xFF)) | ((val) << 0))
#define get_I2C0_Reg0x2_SMB_DAT                                 (addI2C0_Reg0x2 & 0xFF)


//************************************************************//
//TIMER0
//************************************************************//
#define BASEADDR_TIMER0                                         0x00806500
//addTIMER0_Reg0x0
#define addTIMER0_Reg0x0                                        *((volatile unsigned long *) (0x00806500+0x0*4))

//addTIMER0_Reg0x1
#define addTIMER0_Reg0x1                                        *((volatile unsigned long *) (0x00806500+0x1*4))

//addTIMER0_Reg0x2
#define addTIMER0_Reg0x2                                        *((volatile unsigned long *) (0x00806500+0x2*4))

//addTIMER0_Reg0x3
#define addTIMER0_Reg0x3                                        *((volatile unsigned long *) (0x00806500+0x3*4))
#define posTIMER0_Reg0x3_timer0_en                              0
#define bitTIMER0_Reg0x3_timer0_en                              0x1
#define set_TIMER0_Reg0x3_timer0_en(val)                        addTIMER0_Reg0x3 = ((addTIMER0_Reg0x3 & (~0x1)) | ((val) << 0))
#define setf_TIMER0_Reg0x3_timer0_en                            addTIMER0_Reg0x3 |= 0x1
#define clrf_TIMER0_Reg0x3_timer0_en                            addTIMER0_Reg0x3 &= ~0x1
#define get_TIMER0_Reg0x3_timer0_en                             (addTIMER0_Reg0x3 & 0x1)

#define posTIMER0_Reg0x3_timer1_en                              1
#define bitTIMER0_Reg0x3_timer1_en                              0x2
#define set_TIMER0_Reg0x3_timer1_en(val)                        addTIMER0_Reg0x3 = ((addTIMER0_Reg0x3 & (~0x2)) | ((val) << 1))
#define setf_TIMER0_Reg0x3_timer1_en                            addTIMER0_Reg0x3 |= 0x2
#define clrf_TIMER0_Reg0x3_timer1_en                            addTIMER0_Reg0x3 &= ~0x2
#define get_TIMER0_Reg0x3_timer1_en                             ((addTIMER0_Reg0x3 & 0x2) >> 1)

#define posTIMER0_Reg0x3_timer2_en                              2
#define bitTIMER0_Reg0x3_timer2_en                              0x4
#define set_TIMER0_Reg0x3_timer2_en(val)                        addTIMER0_Reg0x3 = ((addTIMER0_Reg0x3 & (~0x4)) | ((val) << 2))
#define setf_TIMER0_Reg0x3_timer2_en                            addTIMER0_Reg0x3 |= 0x4
#define clrf_TIMER0_Reg0x3_timer2_en                            addTIMER0_Reg0x3 &= ~0x4
#define get_TIMER0_Reg0x3_timer2_en                             ((addTIMER0_Reg0x3 & 0x4) >> 2)

#define posTIMER0_Reg0x3_clk_div                                3
#define bitTIMER0_Reg0x3_clk_div                                0x78
#define set_TIMER0_Reg0x3_clk_div(val)                          addTIMER0_Reg0x3 = ((addTIMER0_Reg0x3 & (~0x78)) | ((val) << 3))
#define get_TIMER0_Reg0x3_clk_div                               ((addTIMER0_Reg0x3 & 0x78) >> 3)

#define posTIMER0_Reg0x3_timer0_int                             7
#define bitTIMER0_Reg0x3_timer0_int                             0x80
#define set_TIMER0_Reg0x3_timer0_int(val)                       addTIMER0_Reg0x3 = ((addTIMER0_Reg0x3 & (~0x80)) | ((val) << 7))
#define setf_TIMER0_Reg0x3_timer0_int                           addTIMER0_Reg0x3 |= 0x80
#define clrf_TIMER0_Reg0x3_timer0_int                           addTIMER0_Reg0x3 &= ~0x80
#define get_TIMER0_Reg0x3_timer0_int                            ((addTIMER0_Reg0x3 & 0x80) >> 7)

#define posTIMER0_Reg0x3_timer1_int                             8
#define bitTIMER0_Reg0x3_timer1_int                             0x100
#define set_TIMER0_Reg0x3_timer1_int(val)                       addTIMER0_Reg0x3 = ((addTIMER0_Reg0x3 & (~0x100)) | ((val) << 8))
#define setf_TIMER0_Reg0x3_timer1_int                           addTIMER0_Reg0x3 |= 0x100
#define clrf_TIMER0_Reg0x3_timer1_int                           addTIMER0_Reg0x3 &= ~0x100
#define get_TIMER0_Reg0x3_timer1_int                            ((addTIMER0_Reg0x3 & 0x100) >> 8)

#define posTIMER0_Reg0x3_timer2_int                             9
#define bitTIMER0_Reg0x3_timer2_int                             0x200
#define set_TIMER0_Reg0x3_timer2_int(val)                       addTIMER0_Reg0x3 = ((addTIMER0_Reg0x3 & (~0x200)) | ((val) << 9))
#define setf_TIMER0_Reg0x3_timer2_int                           addTIMER0_Reg0x3 |= 0x200
#define clrf_TIMER0_Reg0x3_timer2_int                           addTIMER0_Reg0x3 &= ~0x200
#define get_TIMER0_Reg0x3_timer2_int                            ((addTIMER0_Reg0x3 & 0x200) >> 9)

//addTIMER0_Reg0x4
#define addTIMER0_Reg0x4                                        *((volatile unsigned long *) (0x00806500+0x4*4))

#define posTIMER0_Reg0x4_timerl_index                           2
#define bitTIMER0_Reg0x4_timerl_index                           0xC
#define set_TIMER0_Reg0x4_timerl_index(val)                     addTIMER0_Reg0x4 = ((addTIMER0_Reg0x4 & (~0xC)) | ((val) << 2))
#define get_TIMER0_Reg0x4_timerl_index                          ((addTIMER0_Reg0x4 & 0xC) >> 2)


#define posTIMER0_Reg0x4_timerl_cnt_read                        0
#define bitTIMER0_Reg0x4_timerl_cnt_read                        0x1
#define set_TIMER0_Reg0x4_timerl_cnt_read(val)                  addTIMER0_Reg0x4 = ((addTIMER0_Reg0x4 & (~0x1)) | ((val) << 0))
#define setf_TIMER0_Reg0x4_timerl_cnt_read                      addTIMER0_Reg0x4 |= 0x1
#define clrf_TIMER0_Reg0x4_timerl_cnt_read                      addTIMER0_Reg0x4 &= ~0x1
#define get_TIMER0_Reg0x4_timerl_cnt_read                       (addTIMER0_Reg0x4 & 0x1)

//addTIMER0_Reg0x5
#define addTIMER0_Reg0x5                                        *((volatile unsigned long *) (0x00806500+0x5*4))


//************************************************************//
//PWM_0
//************************************************************//
#define BASEADDR_PWM_0                                          0x00806100
//addPWM_0_Reg0x0
#define addPWM_0_Reg0x0                                         *((volatile unsigned long *) (0x00806100+0x0*4))

//addPWM_0_Reg0x1
#define addPWM_0_Reg0x1                                         *((volatile unsigned long *) (0x00806100+0x1*4))

//addPWM_0_Reg0x2
#define addPWM_0_Reg0x2                                         *((volatile unsigned long *) (0x00806100+0x2*4))
#define posPWM_0_Reg0x2_Soft_Reset                              0
#define bitPWM_0_Reg0x2_Soft_Reset                              0x1
#define set_PWM_0_Reg0x2_Soft_Reset(val)                        addPWM_0_Reg0x2 = ((addPWM_0_Reg0x2 & (~0x1)) | ((val) << 0))
#define setf_PWM_0_Reg0x2_Soft_Reset                            addPWM_0_Reg0x2 |= 0x1
#define clrf_PWM_0_Reg0x2_Soft_Reset                            addPWM_0_Reg0x2 &= ~0x1
#define get_PWM_0_Reg0x2_Soft_Reset                             (addPWM_0_Reg0x2 & 0x1)

#define posPWM_0_Reg0x2_Bps_Clkgate                             1
#define bitPWM_0_Reg0x2_Bps_Clkgate                             0x2
#define set_PWM_0_Reg0x2_Bps_Clkgate(val)                       addPWM_0_Reg0x2 = ((addPWM_0_Reg0x2 & (~0x2)) | ((val) << 1))
#define setf_PWM_0_Reg0x2_Bps_Clkgate                           addPWM_0_Reg0x2 |= 0x2
#define clrf_PWM_0_Reg0x2_Bps_Clkgate                           addPWM_0_Reg0x2 &= ~0x2
#define get_PWM_0_Reg0x2_Bps_Clkgate                            ((addPWM_0_Reg0x2 & 0x2) >> 1)

//addPWM_0_Reg0x3
#define addPWM_0_Reg0x3                                         *((volatile unsigned long *) (0x00806100+0x3*4))

//addPWM_0_Reg0x4
#define addPWM_0_Reg0x4                                         *((volatile unsigned long *) (0x00806100+0x4*4))
#define posPWM_0_Reg0x4_DIR_TIM1                                31
#define bitPWM_0_Reg0x4_DIR_TIM1                                0x80000000
#define set_PWM_0_Reg0x4_DIR_TIM1(val)                          addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x80000000)) | ((val) << 31))
#define setf_PWM_0_Reg0x4_DIR_TIM1                              addPWM_0_Reg0x4 |= 0x80000000
#define clrf_PWM_0_Reg0x4_DIR_TIM1                              addPWM_0_Reg0x4 &= ~0x80000000
#define get_PWM_0_Reg0x4_DIR_TIM1                               ((addPWM_0_Reg0x4 & 0x80000000) >> 31)

#define posPWM_0_Reg0x4_DIR_TIM2                                30
#define bitPWM_0_Reg0x4_DIR_TIM2                                0x40000000
#define set_PWM_0_Reg0x4_DIR_TIM2(val)                          addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x40000000)) | ((val) << 30))
#define setf_PWM_0_Reg0x4_DIR_TIM2                              addPWM_0_Reg0x4 |= 0x40000000
#define clrf_PWM_0_Reg0x4_DIR_TIM2                              addPWM_0_Reg0x4 &= ~0x40000000
#define get_PWM_0_Reg0x4_DIR_TIM2                               ((addPWM_0_Reg0x4 & 0x40000000) >> 30)

#define posPWM_0_Reg0x4_DIR_TIM3                                29
#define bitPWM_0_Reg0x4_DIR_TIM3                                0x20000000
#define set_PWM_0_Reg0x4_DIR_TIM3(val)                          addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x20000000)) | ((val) << 29))
#define setf_PWM_0_Reg0x4_DIR_TIM3                              addPWM_0_Reg0x4 |= 0x20000000
#define clrf_PWM_0_Reg0x4_DIR_TIM3                              addPWM_0_Reg0x4 &= ~0x20000000
#define get_PWM_0_Reg0x4_DIR_TIM3                               ((addPWM_0_Reg0x4 & 0x20000000) >> 29)

#define posPWM_0_Reg0x4_URS1                                    28
#define bitPWM_0_Reg0x4_URS1                                    0x10000000
#define set_PWM_0_Reg0x4_URS1(val)                              addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x10000000)) | ((val) << 28))
#define setf_PWM_0_Reg0x4_URS1                                  addPWM_0_Reg0x4 |= 0x10000000
#define clrf_PWM_0_Reg0x4_URS1                                  addPWM_0_Reg0x4 &= ~0x10000000
#define get_PWM_0_Reg0x4_URS1                                   ((addPWM_0_Reg0x4 & 0x10000000) >> 28)

#define posPWM_0_Reg0x4_URS2                                    27
#define bitPWM_0_Reg0x4_URS2                                    0x8000000
#define set_PWM_0_Reg0x4_URS2(val)                              addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x8000000)) | ((val) << 27))
#define setf_PWM_0_Reg0x4_URS2                                  addPWM_0_Reg0x4 |= 0x8000000
#define clrf_PWM_0_Reg0x4_URS2                                  addPWM_0_Reg0x4 &= ~0x8000000
#define get_PWM_0_Reg0x4_URS2                                   ((addPWM_0_Reg0x4 & 0x8000000) >> 27)

#define posPWM_0_Reg0x4_URS3                                    26
#define bitPWM_0_Reg0x4_URS3                                    0x4000000
#define set_PWM_0_Reg0x4_URS3(val)                              addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x4000000)) | ((val) << 26))
#define setf_PWM_0_Reg0x4_URS3                                  addPWM_0_Reg0x4 |= 0x4000000
#define clrf_PWM_0_Reg0x4_URS3                                  addPWM_0_Reg0x4 &= ~0x4000000
#define get_PWM_0_Reg0x4_URS3                                   ((addPWM_0_Reg0x4 & 0x4000000) >> 26)


#define posPWM_0_Reg0x4_CMS_TIM1                                22
#define bitPWM_0_Reg0x4_CMS_TIM1                                0xC00000
#define set_PWM_0_Reg0x4_CMS_TIM1(val)                          addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0xC00000)) | ((val) << 22))
#define get_PWM_0_Reg0x4_CMS_TIM1                               ((addPWM_0_Reg0x4 & 0xC00000) >> 22)

#define posPWM_0_Reg0x4_CMS_TIM2                                20
#define bitPWM_0_Reg0x4_CMS_TIM2                                0x300000
#define set_PWM_0_Reg0x4_CMS_TIM2(val)                          addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x300000)) | ((val) << 20))
#define get_PWM_0_Reg0x4_CMS_TIM2                               ((addPWM_0_Reg0x4 & 0x300000) >> 20)

#define posPWM_0_Reg0x4_CMS_TIM3                                18
#define bitPWM_0_Reg0x4_CMS_TIM3                                0xC0000
#define set_PWM_0_Reg0x4_CMS_TIM3(val)                          addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0xC0000)) | ((val) << 18))
#define get_PWM_0_Reg0x4_CMS_TIM3                               ((addPWM_0_Reg0x4 & 0xC0000) >> 18)


#define posPWM_0_Reg0x4_OC1PE                                   8
#define bitPWM_0_Reg0x4_OC1PE                                   0x100
#define set_PWM_0_Reg0x4_OC1PE(val)                             addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x100)) | ((val) << 8))
#define setf_PWM_0_Reg0x4_OC1PE                                 addPWM_0_Reg0x4 |= 0x100
#define clrf_PWM_0_Reg0x4_OC1PE                                 addPWM_0_Reg0x4 &= ~0x100
#define get_PWM_0_Reg0x4_OC1PE                                  ((addPWM_0_Reg0x4 & 0x100) >> 8)

#define posPWM_0_Reg0x4_OC2PE                                   7
#define bitPWM_0_Reg0x4_OC2PE                                   0x80
#define set_PWM_0_Reg0x4_OC2PE(val)                             addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x80)) | ((val) << 7))
#define setf_PWM_0_Reg0x4_OC2PE                                 addPWM_0_Reg0x4 |= 0x80
#define clrf_PWM_0_Reg0x4_OC2PE                                 addPWM_0_Reg0x4 &= ~0x80
#define get_PWM_0_Reg0x4_OC2PE                                  ((addPWM_0_Reg0x4 & 0x80) >> 7)

#define posPWM_0_Reg0x4_OC3PE                                   6
#define bitPWM_0_Reg0x4_OC3PE                                   0x40
#define set_PWM_0_Reg0x4_OC3PE(val)                             addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x40)) | ((val) << 6))
#define setf_PWM_0_Reg0x4_OC3PE                                 addPWM_0_Reg0x4 |= 0x40
#define clrf_PWM_0_Reg0x4_OC3PE                                 addPWM_0_Reg0x4 &= ~0x40
#define get_PWM_0_Reg0x4_OC3PE                                  ((addPWM_0_Reg0x4 & 0x40) >> 6)

#define posPWM_0_Reg0x4_ARPE1                                   5
#define bitPWM_0_Reg0x4_ARPE1                                   0x20
#define set_PWM_0_Reg0x4_ARPE1(val)                             addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x20)) | ((val) << 5))
#define setf_PWM_0_Reg0x4_ARPE1                                 addPWM_0_Reg0x4 |= 0x20
#define clrf_PWM_0_Reg0x4_ARPE1                                 addPWM_0_Reg0x4 &= ~0x20
#define get_PWM_0_Reg0x4_ARPE1                                  ((addPWM_0_Reg0x4 & 0x20) >> 5)

#define posPWM_0_Reg0x4_ARPE2                                   4
#define bitPWM_0_Reg0x4_ARPE2                                   0x10
#define set_PWM_0_Reg0x4_ARPE2(val)                             addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x10)) | ((val) << 4))
#define setf_PWM_0_Reg0x4_ARPE2                                 addPWM_0_Reg0x4 |= 0x10
#define clrf_PWM_0_Reg0x4_ARPE2                                 addPWM_0_Reg0x4 &= ~0x10
#define get_PWM_0_Reg0x4_ARPE2                                  ((addPWM_0_Reg0x4 & 0x10) >> 4)

#define posPWM_0_Reg0x4_ARPE3                                   3
#define bitPWM_0_Reg0x4_ARPE3                                   0x8
#define set_PWM_0_Reg0x4_ARPE3(val)                             addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x8)) | ((val) << 3))
#define setf_PWM_0_Reg0x4_ARPE3                                 addPWM_0_Reg0x4 |= 0x8
#define clrf_PWM_0_Reg0x4_ARPE3                                 addPWM_0_Reg0x4 &= ~0x8
#define get_PWM_0_Reg0x4_ARPE3                                  ((addPWM_0_Reg0x4 & 0x8) >> 3)

#define posPWM_0_Reg0x4_CEN1                                    2
#define bitPWM_0_Reg0x4_CEN1                                    0x4
#define set_PWM_0_Reg0x4_CEN1(val)                              addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x4)) | ((val) << 2))
#define setf_PWM_0_Reg0x4_CEN1                                  addPWM_0_Reg0x4 |= 0x4
#define clrf_PWM_0_Reg0x4_CEN1                                  addPWM_0_Reg0x4 &= ~0x4
#define get_PWM_0_Reg0x4_CEN1                                   ((addPWM_0_Reg0x4 & 0x4) >> 2)

#define posPWM_0_Reg0x4_CEN2                                    1
#define bitPWM_0_Reg0x4_CEN2                                    0x2
#define set_PWM_0_Reg0x4_CEN2(val)                              addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x2)) | ((val) << 1))
#define setf_PWM_0_Reg0x4_CEN2                                  addPWM_0_Reg0x4 |= 0x2
#define clrf_PWM_0_Reg0x4_CEN2                                  addPWM_0_Reg0x4 &= ~0x2
#define get_PWM_0_Reg0x4_CEN2                                   ((addPWM_0_Reg0x4 & 0x2) >> 1)

#define posPWM_0_Reg0x4_CEN3                                    0
#define bitPWM_0_Reg0x4_CEN3                                    0x1
#define set_PWM_0_Reg0x4_CEN3(val)                              addPWM_0_Reg0x4 = ((addPWM_0_Reg0x4 & (~0x1)) | ((val) << 0))
#define setf_PWM_0_Reg0x4_CEN3                                  addPWM_0_Reg0x4 |= 0x1
#define clrf_PWM_0_Reg0x4_CEN3                                  addPWM_0_Reg0x4 &= ~0x1
#define get_PWM_0_Reg0x4_CEN3                                   (addPWM_0_Reg0x4 & 0x1)

//addPWM_0_Reg0x5
#define addPWM_0_Reg0x5                                         *((volatile unsigned long *) (0x00806100+0x5*4))
#define posPWM_0_Reg0x5_ADCS1                                   29
#define bitPWM_0_Reg0x5_ADCS1                                   0xE0000000
#define set_PWM_0_Reg0x5_ADCS1(val)                             addPWM_0_Reg0x5 = ((addPWM_0_Reg0x5 & (~0xE0000000)) | ((val) << 29))
#define get_PWM_0_Reg0x5_ADCS1                                  ((addPWM_0_Reg0x5 & 0xE0000000) >> 29)

#define posPWM_0_Reg0x5_TRIOS1                                  26
#define bitPWM_0_Reg0x5_TRIOS1                                  0x1C000000
#define set_PWM_0_Reg0x5_TRIOS1(val)                            addPWM_0_Reg0x5 = ((addPWM_0_Reg0x5 & (~0x1C000000)) | ((val) << 26))
#define get_PWM_0_Reg0x5_TRIOS1                                 ((addPWM_0_Reg0x5 & 0x1C000000) >> 26)


#define posPWM_0_Reg0x5_ADCS2                                   21
#define bitPWM_0_Reg0x5_ADCS2                                   0xE00000
#define set_PWM_0_Reg0x5_ADCS2(val)                             addPWM_0_Reg0x5 = ((addPWM_0_Reg0x5 & (~0xE00000)) | ((val) << 21))
#define get_PWM_0_Reg0x5_ADCS2                                  ((addPWM_0_Reg0x5 & 0xE00000) >> 21)

#define posPWM_0_Reg0x5_TRIOS2                                  18
#define bitPWM_0_Reg0x5_TRIOS2                                  0x1C0000
#define set_PWM_0_Reg0x5_TRIOS2(val)                            addPWM_0_Reg0x5 = ((addPWM_0_Reg0x5 & (~0x1C0000)) | ((val) << 18))
#define get_PWM_0_Reg0x5_TRIOS2                                 ((addPWM_0_Reg0x5 & 0x1C0000) >> 18)

#define posPWM_0_Reg0x5_ccus                                    17
#define bitPWM_0_Reg0x5_ccus                                    0x20000
#define set_PWM_0_Reg0x5_ccus(val)                              addPWM_0_Reg0x5 = ((addPWM_0_Reg0x5 & (~0x20000)) | ((val) << 17))
#define setf_PWM_0_Reg0x5_ccus                                  addPWM_0_Reg0x5 |= 0x20000
#define clrf_PWM_0_Reg0x5_ccus                                  addPWM_0_Reg0x5 &= ~0x20000
#define get_PWM_0_Reg0x5_ccus                                   ((addPWM_0_Reg0x5 & 0x20000) >> 17)


#define posPWM_0_Reg0x5_ADCS3                                   13
#define bitPWM_0_Reg0x5_ADCS3                                   0xE000
#define set_PWM_0_Reg0x5_ADCS3(val)                             addPWM_0_Reg0x5 = ((addPWM_0_Reg0x5 & (~0xE000)) | ((val) << 13))
#define get_PWM_0_Reg0x5_ADCS3                                  ((addPWM_0_Reg0x5 & 0xE000) >> 13)

#define posPWM_0_Reg0x5_TRIOS3                                  10
#define bitPWM_0_Reg0x5_TRIOS3                                  0x1C00
#define set_PWM_0_Reg0x5_TRIOS3(val)                            addPWM_0_Reg0x5 = ((addPWM_0_Reg0x5 & (~0x1C00)) | ((val) << 10))
#define get_PWM_0_Reg0x5_TRIOS3                                 ((addPWM_0_Reg0x5 & 0x1C00) >> 10)

#define posPWM_0_Reg0x5_CCPC                                    9
#define bitPWM_0_Reg0x5_CCPC                                    0x200
#define set_PWM_0_Reg0x5_CCPC(val)                              addPWM_0_Reg0x5 = ((addPWM_0_Reg0x5 & (~0x200)) | ((val) << 9))
#define setf_PWM_0_Reg0x5_CCPC                                  addPWM_0_Reg0x5 |= 0x200
#define clrf_PWM_0_Reg0x5_CCPC                                  addPWM_0_Reg0x5 &= ~0x200
#define get_PWM_0_Reg0x5_CCPC                                   ((addPWM_0_Reg0x5 & 0x200) >> 9)

#define posPWM_0_Reg0x5_TI1S                                    8
#define bitPWM_0_Reg0x5_TI1S                                    0x100
#define set_PWM_0_Reg0x5_TI1S(val)                              addPWM_0_Reg0x5 = ((addPWM_0_Reg0x5 & (~0x100)) | ((val) << 8))
#define setf_PWM_0_Reg0x5_TI1S                                  addPWM_0_Reg0x5 |= 0x100
#define clrf_PWM_0_Reg0x5_TI1S                                  addPWM_0_Reg0x5 &= ~0x100
#define get_PWM_0_Reg0x5_TI1S                                   ((addPWM_0_Reg0x5 & 0x100) >> 8)


//addPWM_0_Reg0x6
#define addPWM_0_Reg0x6                                         *((volatile unsigned long *) (0x00806100+0x6*4))

#define posPWM_0_Reg0x6_TS3                                     19
#define bitPWM_0_Reg0x6_TS3                                     0x380000
#define set_PWM_0_Reg0x6_TS3(val)                               addPWM_0_Reg0x6 = ((addPWM_0_Reg0x6 & (~0x380000)) | ((val) << 19))
#define get_PWM_0_Reg0x6_TS3                                    ((addPWM_0_Reg0x6 & 0x380000) >> 19)

#define posPWM_0_Reg0x6_TS2                                     16
#define bitPWM_0_Reg0x6_TS2                                     0x70000
#define set_PWM_0_Reg0x6_TS2(val)                               addPWM_0_Reg0x6 = ((addPWM_0_Reg0x6 & (~0x70000)) | ((val) << 16))
#define get_PWM_0_Reg0x6_TS2                                    ((addPWM_0_Reg0x6 & 0x70000) >> 16)


#define posPWM_0_Reg0x6_TS1                                     12
#define bitPWM_0_Reg0x6_TS1                                     0x7000
#define set_PWM_0_Reg0x6_TS1(val)                               addPWM_0_Reg0x6 = ((addPWM_0_Reg0x6 & (~0x7000)) | ((val) << 12))
#define get_PWM_0_Reg0x6_TS1                                    ((addPWM_0_Reg0x6 & 0x7000) >> 12)

#define posPWM_0_Reg0x6_SMS3                                    8
#define bitPWM_0_Reg0x6_SMS3                                    0xF00
#define set_PWM_0_Reg0x6_SMS3(val)                              addPWM_0_Reg0x6 = ((addPWM_0_Reg0x6 & (~0xF00)) | ((val) << 8))
#define get_PWM_0_Reg0x6_SMS3                                   ((addPWM_0_Reg0x6 & 0xF00) >> 8)

#define posPWM_0_Reg0x6_SMS2                                    4
#define bitPWM_0_Reg0x6_SMS2                                    0xF0
#define set_PWM_0_Reg0x6_SMS2(val)                              addPWM_0_Reg0x6 = ((addPWM_0_Reg0x6 & (~0xF0)) | ((val) << 4))
#define get_PWM_0_Reg0x6_SMS2                                   ((addPWM_0_Reg0x6 & 0xF0) >> 4)

#define posPWM_0_Reg0x6_SMS1                                    0
#define bitPWM_0_Reg0x6_SMS1                                    0xF
#define set_PWM_0_Reg0x6_SMS1(val)                              addPWM_0_Reg0x6 = ((addPWM_0_Reg0x6 & (~0xF)) | ((val) << 0))
#define get_PWM_0_Reg0x6_SMS1                                   (addPWM_0_Reg0x6 & 0xF)

//addPWM_0_Reg0x7
#define addPWM_0_Reg0x7                                         *((volatile unsigned long *) (0x00806100+0x7*4))
#define posPWM_0_Reg0x7_df_tim3                                 28
#define bitPWM_0_Reg0x7_df_tim3                                 0xF0000000
#define set_PWM_0_Reg0x7_df_tim3(val)                           addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0xF0000000)) | ((val) << 28))
#define get_PWM_0_Reg0x7_df_tim3                                ((addPWM_0_Reg0x7 & 0xF0000000) >> 28)

#define posPWM_0_Reg0x7_df_tim2                                 24
#define bitPWM_0_Reg0x7_df_tim2                                 0xF000000
#define set_PWM_0_Reg0x7_df_tim2(val)                           addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0xF000000)) | ((val) << 24))
#define get_PWM_0_Reg0x7_df_tim2                                ((addPWM_0_Reg0x7 & 0xF000000) >> 24)

#define posPWM_0_Reg0x7_df_tim1                                 20
#define bitPWM_0_Reg0x7_df_tim1                                 0xF00000
#define set_PWM_0_Reg0x7_df_tim1(val)                           addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0xF00000)) | ((val) << 20))
#define get_PWM_0_Reg0x7_df_tim1                                ((addPWM_0_Reg0x7 & 0xF00000) >> 20)


#define posPWM_0_Reg0x7_COMIE                                   15
#define bitPWM_0_Reg0x7_COMIE                                   0x8000
#define set_PWM_0_Reg0x7_COMIE(val)                             addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x8000)) | ((val) << 15))
#define setf_PWM_0_Reg0x7_COMIE                                 addPWM_0_Reg0x7 |= 0x8000
#define clrf_PWM_0_Reg0x7_COMIE                                 addPWM_0_Reg0x7 &= ~0x8000
#define get_PWM_0_Reg0x7_COMIE                                  ((addPWM_0_Reg0x7 & 0x8000) >> 15)

#define posPWM_0_Reg0x7_TIE3                                    14
#define bitPWM_0_Reg0x7_TIE3                                    0x4000
#define set_PWM_0_Reg0x7_TIE3(val)                              addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x4000)) | ((val) << 14))
#define setf_PWM_0_Reg0x7_TIE3                                  addPWM_0_Reg0x7 |= 0x4000
#define clrf_PWM_0_Reg0x7_TIE3                                  addPWM_0_Reg0x7 &= ~0x4000
#define get_PWM_0_Reg0x7_TIE3                                   ((addPWM_0_Reg0x7 & 0x4000) >> 14)

#define posPWM_0_Reg0x7_TIE2                                    13
#define bitPWM_0_Reg0x7_TIE2                                    0x2000
#define set_PWM_0_Reg0x7_TIE2(val)                              addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x2000)) | ((val) << 13))
#define setf_PWM_0_Reg0x7_TIE2                                  addPWM_0_Reg0x7 |= 0x2000
#define clrf_PWM_0_Reg0x7_TIE2                                  addPWM_0_Reg0x7 &= ~0x2000
#define get_PWM_0_Reg0x7_TIE2                                   ((addPWM_0_Reg0x7 & 0x2000) >> 13)

#define posPWM_0_Reg0x7_TIE1                                    12
#define bitPWM_0_Reg0x7_TIE1                                    0x1000
#define set_PWM_0_Reg0x7_TIE1(val)                              addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x1000)) | ((val) << 12))
#define setf_PWM_0_Reg0x7_TIE1                                  addPWM_0_Reg0x7 |= 0x1000
#define clrf_PWM_0_Reg0x7_TIE1                                  addPWM_0_Reg0x7 &= ~0x1000
#define get_PWM_0_Reg0x7_TIE1                                   ((addPWM_0_Reg0x7 & 0x1000) >> 12)

#define posPWM_0_Reg0x7_UIE3                                    11
#define bitPWM_0_Reg0x7_UIE3                                    0x800
#define set_PWM_0_Reg0x7_UIE3(val)                              addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x800)) | ((val) << 11))
#define setf_PWM_0_Reg0x7_UIE3                                  addPWM_0_Reg0x7 |= 0x800
#define clrf_PWM_0_Reg0x7_UIE3                                  addPWM_0_Reg0x7 &= ~0x800
#define get_PWM_0_Reg0x7_UIE3                                   ((addPWM_0_Reg0x7 & 0x800) >> 11)

#define posPWM_0_Reg0x7_UIE2                                    10
#define bitPWM_0_Reg0x7_UIE2                                    0x400
#define set_PWM_0_Reg0x7_UIE2(val)                              addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x400)) | ((val) << 10))
#define setf_PWM_0_Reg0x7_UIE2                                  addPWM_0_Reg0x7 |= 0x400
#define clrf_PWM_0_Reg0x7_UIE2                                  addPWM_0_Reg0x7 &= ~0x400
#define get_PWM_0_Reg0x7_UIE2                                   ((addPWM_0_Reg0x7 & 0x400) >> 10)

#define posPWM_0_Reg0x7_UIE1                                    9
#define bitPWM_0_Reg0x7_UIE1                                    0x200
#define set_PWM_0_Reg0x7_UIE1(val)                              addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x200)) | ((val) << 9))
#define setf_PWM_0_Reg0x7_UIE1                                  addPWM_0_Reg0x7 |= 0x200
#define clrf_PWM_0_Reg0x7_UIE1                                  addPWM_0_Reg0x7 &= ~0x200
#define get_PWM_0_Reg0x7_UIE1                                   ((addPWM_0_Reg0x7 & 0x200) >> 9)

#define posPWM_0_Reg0x7_CC9IE                                   8
#define bitPWM_0_Reg0x7_CC9IE                                   0x100
#define set_PWM_0_Reg0x7_CC9IE(val)                             addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x100)) | ((val) << 8))
#define setf_PWM_0_Reg0x7_CC9IE                                 addPWM_0_Reg0x7 |= 0x100
#define clrf_PWM_0_Reg0x7_CC9IE                                 addPWM_0_Reg0x7 &= ~0x100
#define get_PWM_0_Reg0x7_CC9IE                                  ((addPWM_0_Reg0x7 & 0x100) >> 8)

#define posPWM_0_Reg0x7_CC8IE                                   7
#define bitPWM_0_Reg0x7_CC8IE                                   0x80
#define set_PWM_0_Reg0x7_CC8IE(val)                             addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x80)) | ((val) << 7))
#define setf_PWM_0_Reg0x7_CC8IE                                 addPWM_0_Reg0x7 |= 0x80
#define clrf_PWM_0_Reg0x7_CC8IE                                 addPWM_0_Reg0x7 &= ~0x80
#define get_PWM_0_Reg0x7_CC8IE                                  ((addPWM_0_Reg0x7 & 0x80) >> 7)

#define posPWM_0_Reg0x7_CC7IE                                   6
#define bitPWM_0_Reg0x7_CC7IE                                   0x40
#define set_PWM_0_Reg0x7_CC7IE(val)                             addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x40)) | ((val) << 6))
#define setf_PWM_0_Reg0x7_CC7IE                                 addPWM_0_Reg0x7 |= 0x40
#define clrf_PWM_0_Reg0x7_CC7IE                                 addPWM_0_Reg0x7 &= ~0x40
#define get_PWM_0_Reg0x7_CC7IE                                  ((addPWM_0_Reg0x7 & 0x40) >> 6)

#define posPWM_0_Reg0x7_CC6IE                                   5
#define bitPWM_0_Reg0x7_CC6IE                                   0x20
#define set_PWM_0_Reg0x7_CC6IE(val)                             addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x20)) | ((val) << 5))
#define setf_PWM_0_Reg0x7_CC6IE                                 addPWM_0_Reg0x7 |= 0x20
#define clrf_PWM_0_Reg0x7_CC6IE                                 addPWM_0_Reg0x7 &= ~0x20
#define get_PWM_0_Reg0x7_CC6IE                                  ((addPWM_0_Reg0x7 & 0x20) >> 5)

#define posPWM_0_Reg0x7_CC5IE                                   4
#define bitPWM_0_Reg0x7_CC5IE                                   0x10
#define set_PWM_0_Reg0x7_CC5IE(val)                             addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x10)) | ((val) << 4))
#define setf_PWM_0_Reg0x7_CC5IE                                 addPWM_0_Reg0x7 |= 0x10
#define clrf_PWM_0_Reg0x7_CC5IE                                 addPWM_0_Reg0x7 &= ~0x10
#define get_PWM_0_Reg0x7_CC5IE                                  ((addPWM_0_Reg0x7 & 0x10) >> 4)

#define posPWM_0_Reg0x7_CC4IE                                   3
#define bitPWM_0_Reg0x7_CC4IE                                   0x8
#define set_PWM_0_Reg0x7_CC4IE(val)                             addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x8)) | ((val) << 3))
#define setf_PWM_0_Reg0x7_CC4IE                                 addPWM_0_Reg0x7 |= 0x8
#define clrf_PWM_0_Reg0x7_CC4IE                                 addPWM_0_Reg0x7 &= ~0x8
#define get_PWM_0_Reg0x7_CC4IE                                  ((addPWM_0_Reg0x7 & 0x8) >> 3)

#define posPWM_0_Reg0x7_CC3IE                                   2
#define bitPWM_0_Reg0x7_CC3IE                                   0x4
#define set_PWM_0_Reg0x7_CC3IE(val)                             addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x4)) | ((val) << 2))
#define setf_PWM_0_Reg0x7_CC3IE                                 addPWM_0_Reg0x7 |= 0x4
#define clrf_PWM_0_Reg0x7_CC3IE                                 addPWM_0_Reg0x7 &= ~0x4
#define get_PWM_0_Reg0x7_CC3IE                                  ((addPWM_0_Reg0x7 & 0x4) >> 2)

#define posPWM_0_Reg0x7_CC2IE                                   1
#define bitPWM_0_Reg0x7_CC2IE                                   0x2
#define set_PWM_0_Reg0x7_CC2IE(val)                             addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x2)) | ((val) << 1))
#define setf_PWM_0_Reg0x7_CC2IE                                 addPWM_0_Reg0x7 |= 0x2
#define clrf_PWM_0_Reg0x7_CC2IE                                 addPWM_0_Reg0x7 &= ~0x2
#define get_PWM_0_Reg0x7_CC2IE                                  ((addPWM_0_Reg0x7 & 0x2) >> 1)

#define posPWM_0_Reg0x7_CC1IE                                   0
#define bitPWM_0_Reg0x7_CC1IE                                   0x1
#define set_PWM_0_Reg0x7_CC1IE(val)                             addPWM_0_Reg0x7 = ((addPWM_0_Reg0x7 & (~0x1)) | ((val) << 0))
#define setf_PWM_0_Reg0x7_CC1IE                                 addPWM_0_Reg0x7 |= 0x1
#define clrf_PWM_0_Reg0x7_CC1IE                                 addPWM_0_Reg0x7 &= ~0x1
#define get_PWM_0_Reg0x7_CC1IE                                  (addPWM_0_Reg0x7 & 0x1)

//addPWM_0_Reg0x8
#define addPWM_0_Reg0x8                                         *((volatile unsigned long *) (0x00806100+0x8*4))

#define posPWM_0_Reg0x8_COMIF                                   15
#define bitPWM_0_Reg0x8_COMIF                                   0x8000
#define set_PWM_0_Reg0x8_COMIF(val)                             addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x8000)) | ((val) << 15))
#define setf_PWM_0_Reg0x8_COMIF                                 addPWM_0_Reg0x8 |= 0x8000
#define clrf_PWM_0_Reg0x8_COMIF                                 addPWM_0_Reg0x8 &= ~0x8000
#define get_PWM_0_Reg0x8_COMIF                                  ((addPWM_0_Reg0x8 & 0x8000) >> 15)

#define posPWM_0_Reg0x8_TIF3                                    14
#define bitPWM_0_Reg0x8_TIF3                                    0x4000
#define set_PWM_0_Reg0x8_TIF3(val)                              addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x4000)) | ((val) << 14))
#define setf_PWM_0_Reg0x8_TIF3                                  addPWM_0_Reg0x8 |= 0x4000
#define clrf_PWM_0_Reg0x8_TIF3                                  addPWM_0_Reg0x8 &= ~0x4000
#define get_PWM_0_Reg0x8_TIF3                                   ((addPWM_0_Reg0x8 & 0x4000) >> 14)

#define posPWM_0_Reg0x8_TIF2                                    13
#define bitPWM_0_Reg0x8_TIF2                                    0x2000
#define set_PWM_0_Reg0x8_TIF2(val)                              addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x2000)) | ((val) << 13))
#define setf_PWM_0_Reg0x8_TIF2                                  addPWM_0_Reg0x8 |= 0x2000
#define clrf_PWM_0_Reg0x8_TIF2                                  addPWM_0_Reg0x8 &= ~0x2000
#define get_PWM_0_Reg0x8_TIF2                                   ((addPWM_0_Reg0x8 & 0x2000) >> 13)

#define posPWM_0_Reg0x8_TIF1                                    12
#define bitPWM_0_Reg0x8_TIF1                                    0x1000
#define set_PWM_0_Reg0x8_TIF1(val)                              addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x1000)) | ((val) << 12))
#define setf_PWM_0_Reg0x8_TIF1                                  addPWM_0_Reg0x8 |= 0x1000
#define clrf_PWM_0_Reg0x8_TIF1                                  addPWM_0_Reg0x8 &= ~0x1000
#define get_PWM_0_Reg0x8_TIF1                                   ((addPWM_0_Reg0x8 & 0x1000) >> 12)

#define posPWM_0_Reg0x8_UIF3                                    11
#define bitPWM_0_Reg0x8_UIF3                                    0x800
#define set_PWM_0_Reg0x8_UIF3(val)                              addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x800)) | ((val) << 11))
#define setf_PWM_0_Reg0x8_UIF3                                  addPWM_0_Reg0x8 |= 0x800
#define clrf_PWM_0_Reg0x8_UIF3                                  addPWM_0_Reg0x8 &= ~0x800
#define get_PWM_0_Reg0x8_UIF3                                   ((addPWM_0_Reg0x8 & 0x800) >> 11)

#define posPWM_0_Reg0x8_UIF2                                    10
#define bitPWM_0_Reg0x8_UIF2                                    0x400
#define set_PWM_0_Reg0x8_UIF2(val)                              addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x400)) | ((val) << 10))
#define setf_PWM_0_Reg0x8_UIF2                                  addPWM_0_Reg0x8 |= 0x400
#define clrf_PWM_0_Reg0x8_UIF2                                  addPWM_0_Reg0x8 &= ~0x400
#define get_PWM_0_Reg0x8_UIF2                                   ((addPWM_0_Reg0x8 & 0x400) >> 10)

#define posPWM_0_Reg0x8_UIF1                                    9
#define bitPWM_0_Reg0x8_UIF1                                    0x200
#define set_PWM_0_Reg0x8_UIF1(val)                              addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x200)) | ((val) << 9))
#define setf_PWM_0_Reg0x8_UIF1                                  addPWM_0_Reg0x8 |= 0x200
#define clrf_PWM_0_Reg0x8_UIF1                                  addPWM_0_Reg0x8 &= ~0x200
#define get_PWM_0_Reg0x8_UIF1                                   ((addPWM_0_Reg0x8 & 0x200) >> 9)

#define posPWM_0_Reg0x8_CC9IF                                   8
#define bitPWM_0_Reg0x8_CC9IF                                   0x100
#define set_PWM_0_Reg0x8_CC9IF(val)                             addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x100)) | ((val) << 8))
#define setf_PWM_0_Reg0x8_CC9IF                                 addPWM_0_Reg0x8 |= 0x100
#define clrf_PWM_0_Reg0x8_CC9IF                                 addPWM_0_Reg0x8 &= ~0x100
#define get_PWM_0_Reg0x8_CC9IF                                  ((addPWM_0_Reg0x8 & 0x100) >> 8)

#define posPWM_0_Reg0x8_CC8IF                                   7
#define bitPWM_0_Reg0x8_CC8IF                                   0x80
#define set_PWM_0_Reg0x8_CC8IF(val)                             addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x80)) | ((val) << 7))
#define setf_PWM_0_Reg0x8_CC8IF                                 addPWM_0_Reg0x8 |= 0x80
#define clrf_PWM_0_Reg0x8_CC8IF                                 addPWM_0_Reg0x8 &= ~0x80
#define get_PWM_0_Reg0x8_CC8IF                                  ((addPWM_0_Reg0x8 & 0x80) >> 7)

#define posPWM_0_Reg0x8_CC7IF                                   6
#define bitPWM_0_Reg0x8_CC7IF                                   0x40
#define set_PWM_0_Reg0x8_CC7IF(val)                             addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x40)) | ((val) << 6))
#define setf_PWM_0_Reg0x8_CC7IF                                 addPWM_0_Reg0x8 |= 0x40
#define clrf_PWM_0_Reg0x8_CC7IF                                 addPWM_0_Reg0x8 &= ~0x40
#define get_PWM_0_Reg0x8_CC7IF                                  ((addPWM_0_Reg0x8 & 0x40) >> 6)

#define posPWM_0_Reg0x8_CC6IF                                   5
#define bitPWM_0_Reg0x8_CC6IF                                   0x20
#define set_PWM_0_Reg0x8_CC6IF(val)                             addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x20)) | ((val) << 5))
#define setf_PWM_0_Reg0x8_CC6IF                                 addPWM_0_Reg0x8 |= 0x20
#define clrf_PWM_0_Reg0x8_CC6IF                                 addPWM_0_Reg0x8 &= ~0x20
#define get_PWM_0_Reg0x8_CC6IF                                  ((addPWM_0_Reg0x8 & 0x20) >> 5)

#define posPWM_0_Reg0x8_CC5IF                                   4
#define bitPWM_0_Reg0x8_CC5IF                                   0x10
#define set_PWM_0_Reg0x8_CC5IF(val)                             addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x10)) | ((val) << 4))
#define setf_PWM_0_Reg0x8_CC5IF                                 addPWM_0_Reg0x8 |= 0x10
#define clrf_PWM_0_Reg0x8_CC5IF                                 addPWM_0_Reg0x8 &= ~0x10
#define get_PWM_0_Reg0x8_CC5IF                                  ((addPWM_0_Reg0x8 & 0x10) >> 4)

#define posPWM_0_Reg0x8_CC4IF                                   3
#define bitPWM_0_Reg0x8_CC4IF                                   0x8
#define set_PWM_0_Reg0x8_CC4IF(val)                             addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x8)) | ((val) << 3))
#define setf_PWM_0_Reg0x8_CC4IF                                 addPWM_0_Reg0x8 |= 0x8
#define clrf_PWM_0_Reg0x8_CC4IF                                 addPWM_0_Reg0x8 &= ~0x8
#define get_PWM_0_Reg0x8_CC4IF                                  ((addPWM_0_Reg0x8 & 0x8) >> 3)

#define posPWM_0_Reg0x8_CC3IF                                   2
#define bitPWM_0_Reg0x8_CC3IF                                   0x4
#define set_PWM_0_Reg0x8_CC3IF(val)                             addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x4)) | ((val) << 2))
#define setf_PWM_0_Reg0x8_CC3IF                                 addPWM_0_Reg0x8 |= 0x4
#define clrf_PWM_0_Reg0x8_CC3IF                                 addPWM_0_Reg0x8 &= ~0x4
#define get_PWM_0_Reg0x8_CC3IF                                  ((addPWM_0_Reg0x8 & 0x4) >> 2)

#define posPWM_0_Reg0x8_CC2IF                                   1
#define bitPWM_0_Reg0x8_CC2IF                                   0x2
#define set_PWM_0_Reg0x8_CC2IF(val)                             addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x2)) | ((val) << 1))
#define setf_PWM_0_Reg0x8_CC2IF                                 addPWM_0_Reg0x8 |= 0x2
#define clrf_PWM_0_Reg0x8_CC2IF                                 addPWM_0_Reg0x8 &= ~0x2
#define get_PWM_0_Reg0x8_CC2IF                                  ((addPWM_0_Reg0x8 & 0x2) >> 1)

#define posPWM_0_Reg0x8_CC1IF                                   0
#define bitPWM_0_Reg0x8_CC1IF                                   0x1
#define set_PWM_0_Reg0x8_CC1IF(val)                             addPWM_0_Reg0x8 = ((addPWM_0_Reg0x8 & (~0x1)) | ((val) << 0))
#define setf_PWM_0_Reg0x8_CC1IF                                 addPWM_0_Reg0x8 |= 0x1
#define clrf_PWM_0_Reg0x8_CC1IF                                 addPWM_0_Reg0x8 &= ~0x1
#define get_PWM_0_Reg0x8_CC1IF                                  (addPWM_0_Reg0x8 & 0x1)

//addPWM_0_Reg0x9
#define addPWM_0_Reg0x9                                         *((volatile unsigned long *) (0x00806100+0x9*4))
	
#define posPWM_4_Reg0x9_DTM                                    20
#define bitPWM_4_Reg0x9_DTM                                    0x300000
#define set_PWM_4_Reg0x9_DTM(val)                              addPWM_0_Reg0x9 = ((addPWM_0_Reg0x9 & (~0x300000)) | ((val) << 20))
#define get_PWM_4_Reg0x9_DTM                                   ((addPWM_0_Reg0x9 & 0x300000) >> 20)

#define posPWM_2_Reg0x9_DTM                                    18
#define bitPWM_2_Reg0x9_DTM                                    0xC0000
#define set_PWM_2_Reg0x9_DTM(val)                              addPWM_0_Reg0x9 = ((addPWM_0_Reg0x9 & (~0xC0000)) | ((val) << 18))
#define get_PWM_2_Reg0x9_DTM                                   ((addPWM_0_Reg0x9 & 0xC0000) >> 18)

#define posPWM_0_Reg0x9_DTM                                    16
#define bitPWM_0_Reg0x9_DTM                                    0x30000
#define set_PWM_0_Reg0x9_DTM(val)                              addPWM_0_Reg0x9 = ((addPWM_0_Reg0x9 & (~0x30000)) | ((val) << 16))
#define get_PWM_0_Reg0x9_DTM                                   ((addPWM_0_Reg0x9 & 0x30000) >> 16)

#define posPWM_0_Reg0x9_COMG                                    15
#define bitPWM_0_Reg0x9_COMG                                    0x8000
#define set_PWM_0_Reg0x9_COMG(val)                              addPWM_0_Reg0x9 = ((addPWM_0_Reg0x9 & (~0x8000)) | ((val) << 15))
#define setf_PWM_0_Reg0x9_COMG                                  addPWM_0_Reg0x9 |= 0x8000
#define clrf_PWM_0_Reg0x9_COMG                                  addPWM_0_Reg0x9 &= ~0x8000
#define get_PWM_0_Reg0x9_COMG                                   ((addPWM_0_Reg0x9 & 0x8000) >> 15)

#define posPWM_0_Reg0x9_TG3                                     14
#define bitPWM_0_Reg0x9_TG3                                     0x4000
#define set_PWM_0_Reg0x9_TG3(val)                               addPWM_0_Reg0x9 = ((addPWM_0_Reg0x9 & (~0x4000)) | ((val) << 14))
#define setf_PWM_0_Reg0x9_TG3                                   addPWM_0_Reg0x9 |= 0x4000
#define clrf_PWM_0_Reg0x9_TG3                                   addPWM_0_Reg0x9 &= ~0x4000
#define get_PWM_0_Reg0x9_TG3                                    ((addPWM_0_Reg0x9 & 0x4000) >> 14)

#define posPWM_0_Reg0x9_TG2                                     13
#define bitPWM_0_Reg0x9_TG2                                     0x2000
#define set_PWM_0_Reg0x9_TG2(val)                               addPWM_0_Reg0x9 = ((addPWM_0_Reg0x9 & (~0x2000)) | ((val) << 13))
#define setf_PWM_0_Reg0x9_TG2                                   addPWM_0_Reg0x9 |= 0x2000
#define clrf_PWM_0_Reg0x9_TG2                                   addPWM_0_Reg0x9 &= ~0x2000
#define get_PWM_0_Reg0x9_TG2                                    ((addPWM_0_Reg0x9 & 0x2000) >> 13)

#define posPWM_0_Reg0x9_TG1                                     12
#define bitPWM_0_Reg0x9_TG1                                     0x1000
#define set_PWM_0_Reg0x9_TG1(val)                               addPWM_0_Reg0x9 = ((addPWM_0_Reg0x9 & (~0x1000)) | ((val) << 12))
#define setf_PWM_0_Reg0x9_TG1                                   addPWM_0_Reg0x9 |= 0x1000
#define clrf_PWM_0_Reg0x9_TG1                                   addPWM_0_Reg0x9 &= ~0x1000
#define get_PWM_0_Reg0x9_TG1                                    ((addPWM_0_Reg0x9 & 0x1000) >> 12)

#define posPWM_0_Reg0x9_UG3                                     11
#define bitPWM_0_Reg0x9_UG3                                     0x800
#define set_PWM_0_Reg0x9_UG3(val)                               addPWM_0_Reg0x9 = ((addPWM_0_Reg0x9 & (~0x800)) | ((val) << 11))
#define setf_PWM_0_Reg0x9_UG3                                   addPWM_0_Reg0x9 |= 0x800
#define clrf_PWM_0_Reg0x9_UG3                                   addPWM_0_Reg0x9 &= ~0x800
#define get_PWM_0_Reg0x9_UG3                                    ((addPWM_0_Reg0x9 & 0x800) >> 11)

#define posPWM_0_Reg0x9_UG2                                     10
#define bitPWM_0_Reg0x9_UG2                                     0x400
#define set_PWM_0_Reg0x9_UG2(val)                               addPWM_0_Reg0x9 = ((addPWM_0_Reg0x9 & (~0x400)) | ((val) << 10))
#define setf_PWM_0_Reg0x9_UG2                                   addPWM_0_Reg0x9 |= 0x400
#define clrf_PWM_0_Reg0x9_UG2                                   addPWM_0_Reg0x9 &= ~0x400
#define get_PWM_0_Reg0x9_UG2                                    ((addPWM_0_Reg0x9 & 0x400) >> 10)

#define posPWM_0_Reg0x9_UG1                                     9
#define bitPWM_0_Reg0x9_UG1                                     0x200
#define set_PWM_0_Reg0x9_UG1(val)                               addPWM_0_Reg0x9 = ((addPWM_0_Reg0x9 & (~0x200)) | ((val) << 9))
#define setf_PWM_0_Reg0x9_UG1                                   addPWM_0_Reg0x9 |= 0x200
#define clrf_PWM_0_Reg0x9_UG1                                   addPWM_0_Reg0x9 &= ~0x200
#define get_PWM_0_Reg0x9_UG1                                    ((addPWM_0_Reg0x9 & 0x200) >> 9)


//addPWM_0_Reg0xa
#define addPWM_0_Reg0xa                                         *((volatile unsigned long *) (0x00806100+0xa*4))

#define posPWM_0_Reg0xa_OC3M                                    27
#define bitPWM_0_Reg0xa_OC3M                                    0x38000000
#define set_PWM_0_Reg0xa_OC3M(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x38000000)) | ((val) << 27))
#define get_PWM_0_Reg0xa_OC3M                                   ((addPWM_0_Reg0xa & 0x38000000) >> 27)

#define posPWM_0_Reg0xa_OC2M                                    24
#define bitPWM_0_Reg0xa_OC2M                                    0x7000000
#define set_PWM_0_Reg0xa_OC2M(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x7000000)) | ((val) << 24))
#define get_PWM_0_Reg0xa_OC2M                                   ((addPWM_0_Reg0xa & 0x7000000) >> 24)

#define posPWM_0_Reg0xa_OC1M                                    21
#define bitPWM_0_Reg0xa_OC1M                                    0xE00000
#define set_PWM_0_Reg0xa_OC1M(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0xE00000)) | ((val) << 21))
#define get_PWM_0_Reg0xa_OC1M                                   ((addPWM_0_Reg0xa & 0xE00000) >> 21)

#define posPWM_0_Reg0xa_TIM3CCM                                 20
#define bitPWM_0_Reg0xa_TIM3CCM                                 0x100000
#define set_PWM_0_Reg0xa_TIM3CCM(val)                           addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x100000)) | ((val) << 20))
#define setf_PWM_0_Reg0xa_TIM3CCM                               addPWM_0_Reg0xa |= 0x100000
#define clrf_PWM_0_Reg0xa_TIM3CCM                               addPWM_0_Reg0xa &= ~0x100000
#define get_PWM_0_Reg0xa_TIM3CCM                                ((addPWM_0_Reg0xa & 0x100000) >> 20)

#define posPWM_0_Reg0xa_TIM2CCM                                 19
#define bitPWM_0_Reg0xa_TIM2CCM                                 0x80000
#define set_PWM_0_Reg0xa_TIM2CCM(val)                           addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x80000)) | ((val) << 19))
#define setf_PWM_0_Reg0xa_TIM2CCM                               addPWM_0_Reg0xa |= 0x80000
#define clrf_PWM_0_Reg0xa_TIM2CCM                               addPWM_0_Reg0xa &= ~0x80000
#define get_PWM_0_Reg0xa_TIM2CCM                                ((addPWM_0_Reg0xa & 0x80000) >> 19)

#define posPWM_0_Reg0xa_TIM1CCM                                 18
#define bitPWM_0_Reg0xa_TIM1CCM                                 0x40000
#define set_PWM_0_Reg0xa_TIM1CCM(val)                           addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x40000)) | ((val) << 18))
#define setf_PWM_0_Reg0xa_TIM1CCM                               addPWM_0_Reg0xa |= 0x40000
#define clrf_PWM_0_Reg0xa_TIM1CCM                               addPWM_0_Reg0xa &= ~0x40000
#define get_PWM_0_Reg0xa_TIM1CCM                                ((addPWM_0_Reg0xa & 0x40000) >> 18)

#define posPWM_0_Reg0xa_CH6E                                    17
#define bitPWM_0_Reg0xa_CH6E                                    0x20000
#define set_PWM_0_Reg0xa_CH6E(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x20000)) | ((val) << 17))
#define setf_PWM_0_Reg0xa_CH6E                                  addPWM_0_Reg0xa |= 0x20000
#define clrf_PWM_0_Reg0xa_CH6E                                  addPWM_0_Reg0xa &= ~0x20000
#define get_PWM_0_Reg0xa_CH6E                                   ((addPWM_0_Reg0xa & 0x20000) >> 17)

#define posPWM_0_Reg0xa_CH5E                                    16
#define bitPWM_0_Reg0xa_CH5E                                    0x10000
#define set_PWM_0_Reg0xa_CH5E(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x10000)) | ((val) << 16))
#define setf_PWM_0_Reg0xa_CH5E                                  addPWM_0_Reg0xa |= 0x10000
#define clrf_PWM_0_Reg0xa_CH5E                                  addPWM_0_Reg0xa &= ~0x10000
#define get_PWM_0_Reg0xa_CH5E                                   ((addPWM_0_Reg0xa & 0x10000) >> 16)

#define posPWM_0_Reg0xa_CH4E                                    15
#define bitPWM_0_Reg0xa_CH4E                                    0x8000
#define set_PWM_0_Reg0xa_CH4E(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x8000)) | ((val) << 15))
#define setf_PWM_0_Reg0xa_CH4E                                  addPWM_0_Reg0xa |= 0x8000
#define clrf_PWM_0_Reg0xa_CH4E                                  addPWM_0_Reg0xa &= ~0x8000
#define get_PWM_0_Reg0xa_CH4E                                   ((addPWM_0_Reg0xa & 0x8000) >> 15)

#define posPWM_0_Reg0xa_CH3E                                    14
#define bitPWM_0_Reg0xa_CH3E                                    0x4000
#define set_PWM_0_Reg0xa_CH3E(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x4000)) | ((val) << 14))
#define setf_PWM_0_Reg0xa_CH3E                                  addPWM_0_Reg0xa |= 0x4000
#define clrf_PWM_0_Reg0xa_CH3E                                  addPWM_0_Reg0xa &= ~0x4000
#define get_PWM_0_Reg0xa_CH3E                                   ((addPWM_0_Reg0xa & 0x4000) >> 14)

#define posPWM_0_Reg0xa_CH2E                                    13
#define bitPWM_0_Reg0xa_CH2E                                    0x2000
#define set_PWM_0_Reg0xa_CH2E(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x2000)) | ((val) << 13))
#define setf_PWM_0_Reg0xa_CH2E                                  addPWM_0_Reg0xa |= 0x2000
#define clrf_PWM_0_Reg0xa_CH2E                                  addPWM_0_Reg0xa &= ~0x2000
#define get_PWM_0_Reg0xa_CH2E                                   ((addPWM_0_Reg0xa & 0x2000) >> 13)

#define posPWM_0_Reg0xa_CH1E                                    12
#define bitPWM_0_Reg0xa_CH1E                                    0x1000
#define set_PWM_0_Reg0xa_CH1E(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x1000)) | ((val) << 12))
#define setf_PWM_0_Reg0xa_CH1E                                  addPWM_0_Reg0xa |= 0x1000
#define clrf_PWM_0_Reg0xa_CH1E                                  addPWM_0_Reg0xa &= ~0x1000
#define get_PWM_0_Reg0xa_CH1E                                   ((addPWM_0_Reg0xa & 0x1000) >> 12)

#define posPWM_0_Reg0xa_CH6P                                    10
#define bitPWM_0_Reg0xa_CH6P                                    0xC00
#define set_PWM_0_Reg0xa_CH6P(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0xC00)) | ((val) << 10))
#define get_PWM_0_Reg0xa_CH6P                                   ((addPWM_0_Reg0xa & 0xC00) >> 10)

#define posPWM_0_Reg0xa_CH5P                                    8
#define bitPWM_0_Reg0xa_CH5P                                    0x300
#define set_PWM_0_Reg0xa_CH5P(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x300)) | ((val) << 8))
#define get_PWM_0_Reg0xa_CH5P                                   ((addPWM_0_Reg0xa & 0x300) >> 8)

#define posPWM_0_Reg0xa_CH4P                                    6
#define bitPWM_0_Reg0xa_CH4P                                    0xC0
#define set_PWM_0_Reg0xa_CH4P(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0xC0)) | ((val) << 6))
#define get_PWM_0_Reg0xa_CH4P                                   ((addPWM_0_Reg0xa & 0xC0) >> 6)

#define posPWM_0_Reg0xa_CH3P                                    4
#define bitPWM_0_Reg0xa_CH3P                                    0x30
#define set_PWM_0_Reg0xa_CH3P(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x30)) | ((val) << 4))
#define get_PWM_0_Reg0xa_CH3P                                   ((addPWM_0_Reg0xa & 0x30) >> 4)

#define posPWM_0_Reg0xa_CH2P                                    2
#define bitPWM_0_Reg0xa_CH2P                                    0xC
#define set_PWM_0_Reg0xa_CH2P(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0xC)) | ((val) << 2))
#define get_PWM_0_Reg0xa_CH2P                                   ((addPWM_0_Reg0xa & 0xC) >> 2)

#define posPWM_0_Reg0xa_CH1P                                    0
#define bitPWM_0_Reg0xa_CH1P                                    0x3
#define set_PWM_0_Reg0xa_CH1P(val)                              addPWM_0_Reg0xa = ((addPWM_0_Reg0xa & (~0x3)) | ((val) << 0))
#define get_PWM_0_Reg0xa_CH1P                                   (addPWM_0_Reg0xa & 0x3)

//addPWM_0_Reg0xb
#define addPWM_0_Reg0xb                                         *((volatile unsigned long *) (0x00806100+0xb*4))

//addPWM_0_Reg0xc
#define addPWM_0_Reg0xc                                         *((volatile unsigned long *) (0x00806100+0xc*4))

//addPWM_0_Reg0xd
#define addPWM_0_Reg0xd                                         *((volatile unsigned long *) (0x00806100+0xd*4))

//addPWM_0_Reg0xe
#define addPWM_0_Reg0xe                                         *((volatile unsigned long *) (0x00806100+0xe*4))

#define posPWM_0_Reg0xe_PSC3                                    16
#define bitPWM_0_Reg0xe_PSC3                                    0xFF0000
#define set_PWM_0_Reg0xe_PSC3(val)                              addPWM_0_Reg0xe = ((addPWM_0_Reg0xe & (~0xFF0000)) | ((val) << 16))
#define get_PWM_0_Reg0xe_PSC3                                   ((addPWM_0_Reg0xe & 0xFF0000) >> 16)

#define posPWM_0_Reg0xe_PSC2                                    8
#define bitPWM_0_Reg0xe_PSC2                                    0xFF00
#define set_PWM_0_Reg0xe_PSC2(val)                              addPWM_0_Reg0xe = ((addPWM_0_Reg0xe & (~0xFF00)) | ((val) << 8))
#define get_PWM_0_Reg0xe_PSC2                                   ((addPWM_0_Reg0xe & 0xFF00) >> 8)

#define posPWM_0_Reg0xe_PSC1                                    0
#define bitPWM_0_Reg0xe_PSC1                                    0xFF
#define set_PWM_0_Reg0xe_PSC1(val)                              addPWM_0_Reg0xe = ((addPWM_0_Reg0xe & (~0xFF)) | ((val) << 0))
#define get_PWM_0_Reg0xe_PSC1                                   (addPWM_0_Reg0xe & 0xFF)

//addPWM_0_Reg0xf
#define addPWM_0_Reg0xf                                         *((volatile unsigned long *) (0x00806100+0xf*4))

//addPWM_0_Reg0x10
#define addPWM_0_Reg0x10                                        *((volatile unsigned long *) (0x00806100+0x10*4))

//addPWM_0_Reg0x11
#define addPWM_0_Reg0x11                                        *((volatile unsigned long *) (0x00806100+0x11*4))

//addPWM_0_Reg0x12
#define addPWM_0_Reg0x12                                        *((volatile unsigned long *) (0x00806100+0x12*4))

//addPWM_0_Reg0x13
#define addPWM_0_Reg0x13                                        *((volatile unsigned long *) (0x00806100+0x13*4))

//addPWM_0_Reg0x14
#define addPWM_0_Reg0x14                                        *((volatile unsigned long *) (0x00806100+0x14*4))

//addPWM_0_Reg0x15
#define addPWM_0_Reg0x15                                        *((volatile unsigned long *) (0x00806100+0x15*4))

//addPWM_0_Reg0x16
#define addPWM_0_Reg0x16                                        *((volatile unsigned long *) (0x00806100+0x16*4))

//addPWM_0_Reg0x17
#define addPWM_0_Reg0x17                                        *((volatile unsigned long *) (0x00806100+0x17*4))

//addPWM_0_Reg0x18
#define addPWM_0_Reg0x18                                        *((volatile unsigned long *) (0x00806100+0x18*4))

//addPWM_0_Reg0x19
#define addPWM_0_Reg0x19                                        *((volatile unsigned long *) (0x00806100+0x19*4))

//addPWM_0_Reg0x1a
#define addPWM_0_Reg0x1a                                        *((volatile unsigned long *) (0x00806100+0x1a*4))

//addPWM_0_Reg0x1b
#define addPWM_0_Reg0x1b                                        *((volatile unsigned long *) (0x00806100+0x1b*4))

//addPWM_0_Reg0x1c
#define addPWM_0_Reg0x1c                                        *((volatile unsigned long *) (0x00806100+0x1c*4))

//addPWM_0_Reg0x1d
#define addPWM_0_Reg0x1d                                        *((volatile unsigned long *) (0x00806100+0x1d*4))

//addPWM_0_Reg0x1e
#define addPWM_0_Reg0x1e                                        *((volatile unsigned long *) (0x00806100+0x1e*4))

#define posPWM_0_Reg0x1e_DT3                                    20
#define bitPWM_0_Reg0x1e_DT3                                    0x3FF00000
#define set_PWM_0_Reg0x1e_DT3(val)                              addPWM_0_Reg0x1e = ((addPWM_0_Reg0x1e & (~0x3FF00000)) | ((val) << 20))
#define get_PWM_0_Reg0x1e_DT3                                   ((addPWM_0_Reg0x1e & 0x3FF00000) >> 20)

#define posPWM_0_Reg0x1e_DT2                                    10
#define bitPWM_0_Reg0x1e_DT2                                    0xFFC00
#define set_PWM_0_Reg0x1e_DT2(val)                              addPWM_0_Reg0x1e = ((addPWM_0_Reg0x1e & (~0xFFC00)) | ((val) << 10))
#define get_PWM_0_Reg0x1e_DT2                                   ((addPWM_0_Reg0x1e & 0xFFC00) >> 10)

#define posPWM_0_Reg0x1e_DT1                                    0
#define bitPWM_0_Reg0x1e_DT1                                    0x3FF
#define set_PWM_0_Reg0x1e_DT1(val)                              addPWM_0_Reg0x1e = ((addPWM_0_Reg0x1e & (~0x3FF)) | ((val) << 0))
#define get_PWM_0_Reg0x1e_DT1                                   (addPWM_0_Reg0x1e & 0x3FF)

//addPWM_0_Reg0x1f
#define addPWM_0_Reg0x1f                                        *((volatile unsigned long *) (0x00806100+0x1f*4))

//addPWM_0_Reg0x20
#define addPWM_0_Reg0x20                                        *((volatile unsigned long *) (0x00806100+0x20*4))

//addPWM_0_Reg0x21
#define addPWM_0_Reg0x21                                        *((volatile unsigned long *) (0x00806100+0x21*4))

//addPWM_0_Reg0x22
#define addPWM_0_Reg0x22                                        *((volatile unsigned long *) (0x00806100+0x22*4))

//addPWM_0_Reg0x23
#define addPWM_0_Reg0x23                                        *((volatile unsigned long *) (0x00806100+0x23*4))

//addPWM_0_Reg0x24
#define addPWM_0_Reg0x24                                        *((volatile unsigned long *) (0x00806100+0x24*4))

//addPWM_0_Reg0x25
#define addPWM_0_Reg0x25                                        *((volatile unsigned long *) (0x00806100+0x25*4))

//addPWM_0_Reg0x26
#define addPWM_0_Reg0x26                                        *((volatile unsigned long *) (0x00806100+0x26*4))

//addPWM_0_Reg0x27
#define addPWM_0_Reg0x27                                        *((volatile unsigned long *) (0x00806100+0x27*4))

//addPWM_0_Reg0x28
#define addPWM_0_Reg0x28                                        *((volatile unsigned long *) (0x00806100+0x28*4))

//addPWM_0_Reg0x29
#define addPWM_0_Reg0x29                                        *((volatile unsigned long *) (0x00806100+0x29*4))

//addPWM_0_Reg0x2a
#define addPWM_0_Reg0x2a                                        *((volatile unsigned long *) (0x00806100+0x2a*4))

//addPWM_0_Reg0x2b
#define addPWM_0_Reg0x2b                                        *((volatile unsigned long *) (0x00806100+0x2b*4))

//addPWM_0_Reg0x2c
#define addPWM_0_Reg0x2c                                        *((volatile unsigned long *) (0x00806100+0x2c*4))

//addPWM_0_Reg0x2d
#define addPWM_0_Reg0x2d                                        *((volatile unsigned long *) (0x00806100+0x2d*4))

//addPWM_0_Reg0x2e
#define addPWM_0_Reg0x2e                                        *((volatile unsigned long *) (0x00806100+0x2e*4))

#define posPWM_0_Reg0x2e_oc3m_shad                              12
#define bitPWM_0_Reg0x2e_oc3m_shad                              0x7000
#define set_PWM_0_Reg0x2e_oc3m_shad(val)                        addPWM_0_Reg0x2e = ((addPWM_0_Reg0x2e & (~0x7000)) | ((val) << 12))
#define get_PWM_0_Reg0x2e_oc3m_shad                             ((addPWM_0_Reg0x2e & 0x7000) >> 12)

#define posPWM_0_Reg0x2e_oc2m_shad                              9
#define bitPWM_0_Reg0x2e_oc2m_shad                              0xE00
#define set_PWM_0_Reg0x2e_oc2m_shad(val)                        addPWM_0_Reg0x2e = ((addPWM_0_Reg0x2e & (~0xE00)) | ((val) << 9))
#define get_PWM_0_Reg0x2e_oc2m_shad                             ((addPWM_0_Reg0x2e & 0xE00) >> 9)

#define posPWM_0_Reg0x2e_oc1m_shad                              6
#define bitPWM_0_Reg0x2e_oc1m_shad                              0x1C0
#define set_PWM_0_Reg0x2e_oc1m_shad(val)                        addPWM_0_Reg0x2e = ((addPWM_0_Reg0x2e & (~0x1C0)) | ((val) << 6))
#define get_PWM_0_Reg0x2e_oc1m_shad                             ((addPWM_0_Reg0x2e & 0x1C0) >> 6)

#define posPWM_0_Reg0x2e_CH1e_shad                              5
#define bitPWM_0_Reg0x2e_CH1e_shad                              0x20
#define set_PWM_0_Reg0x2e_CH1e_shad(val)                        addPWM_0_Reg0x2e = ((addPWM_0_Reg0x2e & (~0x20)) | ((val) << 5))
#define setf_PWM_0_Reg0x2e_CH1e_shad                            addPWM_0_Reg0x2e |= 0x20
#define clrf_PWM_0_Reg0x2e_CH1e_shad                            addPWM_0_Reg0x2e &= ~0x20
#define get_PWM_0_Reg0x2e_CH1e_shad                             ((addPWM_0_Reg0x2e & 0x20) >> 5)

#define posPWM_0_Reg0x2e_CH2e_shad                              4
#define bitPWM_0_Reg0x2e_CH2e_shad                              0x10
#define set_PWM_0_Reg0x2e_CH2e_shad(val)                        addPWM_0_Reg0x2e = ((addPWM_0_Reg0x2e & (~0x10)) | ((val) << 4))
#define setf_PWM_0_Reg0x2e_CH2e_shad                            addPWM_0_Reg0x2e |= 0x10
#define clrf_PWM_0_Reg0x2e_CH2e_shad                            addPWM_0_Reg0x2e &= ~0x10
#define get_PWM_0_Reg0x2e_CH2e_shad                             ((addPWM_0_Reg0x2e & 0x10) >> 4)

#define posPWM_0_Reg0x2e_CH3e_shad                              3
#define bitPWM_0_Reg0x2e_CH3e_shad                              0x8
#define set_PWM_0_Reg0x2e_CH3e_shad(val)                        addPWM_0_Reg0x2e = ((addPWM_0_Reg0x2e & (~0x8)) | ((val) << 3))
#define setf_PWM_0_Reg0x2e_CH3e_shad                            addPWM_0_Reg0x2e |= 0x8
#define clrf_PWM_0_Reg0x2e_CH3e_shad                            addPWM_0_Reg0x2e &= ~0x8
#define get_PWM_0_Reg0x2e_CH3e_shad                             ((addPWM_0_Reg0x2e & 0x8) >> 3)

#define posPWM_0_Reg0x2e_CH4e_shad                              2
#define bitPWM_0_Reg0x2e_CH4e_shad                              0x4
#define set_PWM_0_Reg0x2e_CH4e_shad(val)                        addPWM_0_Reg0x2e = ((addPWM_0_Reg0x2e & (~0x4)) | ((val) << 2))
#define setf_PWM_0_Reg0x2e_CH4e_shad                            addPWM_0_Reg0x2e |= 0x4
#define clrf_PWM_0_Reg0x2e_CH4e_shad                            addPWM_0_Reg0x2e &= ~0x4
#define get_PWM_0_Reg0x2e_CH4e_shad                             ((addPWM_0_Reg0x2e & 0x4) >> 2)

#define posPWM_0_Reg0x2e_CH5e_shad                              1
#define bitPWM_0_Reg0x2e_CH5e_shad                              0x2
#define set_PWM_0_Reg0x2e_CH5e_shad(val)                        addPWM_0_Reg0x2e = ((addPWM_0_Reg0x2e & (~0x2)) | ((val) << 1))
#define setf_PWM_0_Reg0x2e_CH5e_shad                            addPWM_0_Reg0x2e |= 0x2
#define clrf_PWM_0_Reg0x2e_CH5e_shad                            addPWM_0_Reg0x2e &= ~0x2
#define get_PWM_0_Reg0x2e_CH5e_shad                             ((addPWM_0_Reg0x2e & 0x2) >> 1)

#define posPWM_0_Reg0x2e_CH6e_shad                              0
#define bitPWM_0_Reg0x2e_CH6e_shad                              0x1
#define set_PWM_0_Reg0x2e_CH6e_shad(val)                        addPWM_0_Reg0x2e = ((addPWM_0_Reg0x2e & (~0x1)) | ((val) << 0))
#define setf_PWM_0_Reg0x2e_CH6e_shad                            addPWM_0_Reg0x2e |= 0x1
#define clrf_PWM_0_Reg0x2e_CH6e_shad                            addPWM_0_Reg0x2e &= ~0x1
#define get_PWM_0_Reg0x2e_CH6e_shad                             (addPWM_0_Reg0x2e & 0x1)


//************************************************************//
//PWM_1
//************************************************************//
#define BASEADDR_PWM_1                                          0x00806b00
//addPWM_1_Reg0x0
#define addPWM_1_Reg0x0                                         *((volatile unsigned long *) (0x00806b00+0x0*4))

//addPWM_1_Reg0x1
#define addPWM_1_Reg0x1                                         *((volatile unsigned long *) (0x00806b00+0x1*4))

//addPWM_1_Reg0x2
#define addPWM_1_Reg0x2                                         *((volatile unsigned long *) (0x00806b00+0x2*4))
#define posPWM_1_Reg0x2_Soft_Reset                              0
#define bitPWM_1_Reg0x2_Soft_Reset                              0x1
#define set_PWM_1_Reg0x2_Soft_Reset(val)                        addPWM_1_Reg0x2 = ((addPWM_1_Reg0x2 & (~0x1)) | ((val) << 0))
#define setf_PWM_1_Reg0x2_Soft_Reset                            addPWM_1_Reg0x2 |= 0x1
#define clrf_PWM_1_Reg0x2_Soft_Reset                            addPWM_1_Reg0x2 &= ~0x1
#define get_PWM_1_Reg0x2_Soft_Reset                             (addPWM_1_Reg0x2 & 0x1)

#define posPWM_1_Reg0x2_Bps_Clkgate                             1
#define bitPWM_1_Reg0x2_Bps_Clkgate                             0x2
#define set_PWM_1_Reg0x2_Bps_Clkgate(val)                       addPWM_1_Reg0x2 = ((addPWM_1_Reg0x2 & (~0x2)) | ((val) << 1))
#define setf_PWM_1_Reg0x2_Bps_Clkgate                           addPWM_1_Reg0x2 |= 0x2
#define clrf_PWM_1_Reg0x2_Bps_Clkgate                           addPWM_1_Reg0x2 &= ~0x2
#define get_PWM_1_Reg0x2_Bps_Clkgate                            ((addPWM_1_Reg0x2 & 0x2) >> 1)

//addPWM_1_Reg0x3
#define addPWM_1_Reg0x3                                         *((volatile unsigned long *) (0x00806b00+0x3*4))

//addPWM_1_Reg0x4
#define addPWM_1_Reg0x4                                         *((volatile unsigned long *) (0x00806b00+0x4*4))
#define posPWM_1_Reg0x4_DIR_TIM1                                31
#define bitPWM_1_Reg0x4_DIR_TIM1                                0x80000000
#define set_PWM_1_Reg0x4_DIR_TIM1(val)                          addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x80000000)) | ((val) << 31))
#define setf_PWM_1_Reg0x4_DIR_TIM1                              addPWM_1_Reg0x4 |= 0x80000000
#define clrf_PWM_1_Reg0x4_DIR_TIM1                              addPWM_1_Reg0x4 &= ~0x80000000
#define get_PWM_1_Reg0x4_DIR_TIM1                               ((addPWM_1_Reg0x4 & 0x80000000) >> 31)

#define posPWM_1_Reg0x4_DIR_TIM2                                30
#define bitPWM_1_Reg0x4_DIR_TIM2                                0x40000000
#define set_PWM_1_Reg0x4_DIR_TIM2(val)                          addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x40000000)) | ((val) << 30))
#define setf_PWM_1_Reg0x4_DIR_TIM2                              addPWM_1_Reg0x4 |= 0x40000000
#define clrf_PWM_1_Reg0x4_DIR_TIM2                              addPWM_1_Reg0x4 &= ~0x40000000
#define get_PWM_1_Reg0x4_DIR_TIM2                               ((addPWM_1_Reg0x4 & 0x40000000) >> 30)

#define posPWM_1_Reg0x4_DIR_TIM3                                29
#define bitPWM_1_Reg0x4_DIR_TIM3                                0x20000000
#define set_PWM_1_Reg0x4_DIR_TIM3(val)                          addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x20000000)) | ((val) << 29))
#define setf_PWM_1_Reg0x4_DIR_TIM3                              addPWM_1_Reg0x4 |= 0x20000000
#define clrf_PWM_1_Reg0x4_DIR_TIM3                              addPWM_1_Reg0x4 &= ~0x20000000
#define get_PWM_1_Reg0x4_DIR_TIM3                               ((addPWM_1_Reg0x4 & 0x20000000) >> 29)

#define posPWM_1_Reg0x4_URS1                                    28
#define bitPWM_1_Reg0x4_URS1                                    0x10000000
#define set_PWM_1_Reg0x4_URS1(val)                              addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x10000000)) | ((val) << 28))
#define setf_PWM_1_Reg0x4_URS1                                  addPWM_1_Reg0x4 |= 0x10000000
#define clrf_PWM_1_Reg0x4_URS1                                  addPWM_1_Reg0x4 &= ~0x10000000
#define get_PWM_1_Reg0x4_URS1                                   ((addPWM_1_Reg0x4 & 0x10000000) >> 28)

#define posPWM_1_Reg0x4_URS2                                    27
#define bitPWM_1_Reg0x4_URS2                                    0x8000000
#define set_PWM_1_Reg0x4_URS2(val)                              addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x8000000)) | ((val) << 27))
#define setf_PWM_1_Reg0x4_URS2                                  addPWM_1_Reg0x4 |= 0x8000000
#define clrf_PWM_1_Reg0x4_URS2                                  addPWM_1_Reg0x4 &= ~0x8000000
#define get_PWM_1_Reg0x4_URS2                                   ((addPWM_1_Reg0x4 & 0x8000000) >> 27)

#define posPWM_1_Reg0x4_URS3                                    26
#define bitPWM_1_Reg0x4_URS3                                    0x4000000
#define set_PWM_1_Reg0x4_URS3(val)                              addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x4000000)) | ((val) << 26))
#define setf_PWM_1_Reg0x4_URS3                                  addPWM_1_Reg0x4 |= 0x4000000
#define clrf_PWM_1_Reg0x4_URS3                                  addPWM_1_Reg0x4 &= ~0x4000000
#define get_PWM_1_Reg0x4_URS3                                   ((addPWM_1_Reg0x4 & 0x4000000) >> 26)


#define posPWM_1_Reg0x4_CMS_TIM1                                22
#define bitPWM_1_Reg0x4_CMS_TIM1                                0xC00000
#define set_PWM_1_Reg0x4_CMS_TIM1(val)                          addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0xC00000)) | ((val) << 22))
#define get_PWM_1_Reg0x4_CMS_TIM1                               ((addPWM_1_Reg0x4 & 0xC00000) >> 22)

#define posPWM_1_Reg0x4_CMS_TIM2                                20
#define bitPWM_1_Reg0x4_CMS_TIM2                                0x300000
#define set_PWM_1_Reg0x4_CMS_TIM2(val)                          addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x300000)) | ((val) << 20))
#define get_PWM_1_Reg0x4_CMS_TIM2                               ((addPWM_1_Reg0x4 & 0x300000) >> 20)

#define posPWM_1_Reg0x4_CMS_TIM3                                18
#define bitPWM_1_Reg0x4_CMS_TIM3                                0xC0000
#define set_PWM_1_Reg0x4_CMS_TIM3(val)                          addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0xC0000)) | ((val) << 18))
#define get_PWM_1_Reg0x4_CMS_TIM3                               ((addPWM_1_Reg0x4 & 0xC0000) >> 18)


#define posPWM_1_Reg0x4_OC1PE                                   8
#define bitPWM_1_Reg0x4_OC1PE                                   0x100
#define set_PWM_1_Reg0x4_OC1PE(val)                             addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x100)) | ((val) << 8))
#define setf_PWM_1_Reg0x4_OC1PE                                 addPWM_1_Reg0x4 |= 0x100
#define clrf_PWM_1_Reg0x4_OC1PE                                 addPWM_1_Reg0x4 &= ~0x100
#define get_PWM_1_Reg0x4_OC1PE                                  ((addPWM_1_Reg0x4 & 0x100) >> 8)

#define posPWM_1_Reg0x4_OC2PE                                   7
#define bitPWM_1_Reg0x4_OC2PE                                   0x80
#define set_PWM_1_Reg0x4_OC2PE(val)                             addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x80)) | ((val) << 7))
#define setf_PWM_1_Reg0x4_OC2PE                                 addPWM_1_Reg0x4 |= 0x80
#define clrf_PWM_1_Reg0x4_OC2PE                                 addPWM_1_Reg0x4 &= ~0x80
#define get_PWM_1_Reg0x4_OC2PE                                  ((addPWM_1_Reg0x4 & 0x80) >> 7)

#define posPWM_1_Reg0x4_OC3PE                                   6
#define bitPWM_1_Reg0x4_OC3PE                                   0x40
#define set_PWM_1_Reg0x4_OC3PE(val)                             addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x40)) | ((val) << 6))
#define setf_PWM_1_Reg0x4_OC3PE                                 addPWM_1_Reg0x4 |= 0x40
#define clrf_PWM_1_Reg0x4_OC3PE                                 addPWM_1_Reg0x4 &= ~0x40
#define get_PWM_1_Reg0x4_OC3PE                                  ((addPWM_1_Reg0x4 & 0x40) >> 6)

#define posPWM_1_Reg0x4_ARPE1                                   5
#define bitPWM_1_Reg0x4_ARPE1                                   0x20
#define set_PWM_1_Reg0x4_ARPE1(val)                             addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x20)) | ((val) << 5))
#define setf_PWM_1_Reg0x4_ARPE1                                 addPWM_1_Reg0x4 |= 0x20
#define clrf_PWM_1_Reg0x4_ARPE1                                 addPWM_1_Reg0x4 &= ~0x20
#define get_PWM_1_Reg0x4_ARPE1                                  ((addPWM_1_Reg0x4 & 0x20) >> 5)

#define posPWM_1_Reg0x4_ARPE2                                   4
#define bitPWM_1_Reg0x4_ARPE2                                   0x10
#define set_PWM_1_Reg0x4_ARPE2(val)                             addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x10)) | ((val) << 4))
#define setf_PWM_1_Reg0x4_ARPE2                                 addPWM_1_Reg0x4 |= 0x10
#define clrf_PWM_1_Reg0x4_ARPE2                                 addPWM_1_Reg0x4 &= ~0x10
#define get_PWM_1_Reg0x4_ARPE2                                  ((addPWM_1_Reg0x4 & 0x10) >> 4)

#define posPWM_1_Reg0x4_ARPE3                                   3
#define bitPWM_1_Reg0x4_ARPE3                                   0x8
#define set_PWM_1_Reg0x4_ARPE3(val)                             addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x8)) | ((val) << 3))
#define setf_PWM_1_Reg0x4_ARPE3                                 addPWM_1_Reg0x4 |= 0x8
#define clrf_PWM_1_Reg0x4_ARPE3                                 addPWM_1_Reg0x4 &= ~0x8
#define get_PWM_1_Reg0x4_ARPE3                                  ((addPWM_1_Reg0x4 & 0x8) >> 3)

#define posPWM_1_Reg0x4_CEN1                                    2
#define bitPWM_1_Reg0x4_CEN1                                    0x4
#define set_PWM_1_Reg0x4_CEN1(val)                              addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x4)) | ((val) << 2))
#define setf_PWM_1_Reg0x4_CEN1                                  addPWM_1_Reg0x4 |= 0x4
#define clrf_PWM_1_Reg0x4_CEN1                                  addPWM_1_Reg0x4 &= ~0x4
#define get_PWM_1_Reg0x4_CEN1                                   ((addPWM_1_Reg0x4 & 0x4) >> 2)

#define posPWM_1_Reg0x4_CEN2                                    1
#define bitPWM_1_Reg0x4_CEN2                                    0x2
#define set_PWM_1_Reg0x4_CEN2(val)                              addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x2)) | ((val) << 1))
#define setf_PWM_1_Reg0x4_CEN2                                  addPWM_1_Reg0x4 |= 0x2
#define clrf_PWM_1_Reg0x4_CEN2                                  addPWM_1_Reg0x4 &= ~0x2
#define get_PWM_1_Reg0x4_CEN2                                   ((addPWM_1_Reg0x4 & 0x2) >> 1)

#define posPWM_1_Reg0x4_CEN3                                    0
#define bitPWM_1_Reg0x4_CEN3                                    0x1
#define set_PWM_1_Reg0x4_CEN3(val)                              addPWM_1_Reg0x4 = ((addPWM_1_Reg0x4 & (~0x1)) | ((val) << 0))
#define setf_PWM_1_Reg0x4_CEN3                                  addPWM_1_Reg0x4 |= 0x1
#define clrf_PWM_1_Reg0x4_CEN3                                  addPWM_1_Reg0x4 &= ~0x1
#define get_PWM_1_Reg0x4_CEN3                                   (addPWM_1_Reg0x4 & 0x1)

//addPWM_1_Reg0x5
#define addPWM_1_Reg0x5                                         *((volatile unsigned long *) (0x00806b00+0x5*4))
#define posPWM_1_Reg0x5_ADCS1                                   29
#define bitPWM_1_Reg0x5_ADCS1                                   0xE0000000
#define set_PWM_1_Reg0x5_ADCS1(val)                             addPWM_1_Reg0x5 = ((addPWM_1_Reg0x5 & (~0xE0000000)) | ((val) << 29))
#define get_PWM_1_Reg0x5_ADCS1                                  ((addPWM_1_Reg0x5 & 0xE0000000) >> 29)

#define posPWM_1_Reg0x5_TRIOS1                                  26
#define bitPWM_1_Reg0x5_TRIOS1                                  0x1C000000
#define set_PWM_1_Reg0x5_TRIOS1(val)                            addPWM_1_Reg0x5 = ((addPWM_1_Reg0x5 & (~0x1C000000)) | ((val) << 26))
#define get_PWM_1_Reg0x5_TRIOS1                                 ((addPWM_1_Reg0x5 & 0x1C000000) >> 26)


#define posPWM_1_Reg0x5_ADCS2                                   21
#define bitPWM_1_Reg0x5_ADCS2                                   0xE00000
#define set_PWM_1_Reg0x5_ADCS2(val)                             addPWM_1_Reg0x5 = ((addPWM_1_Reg0x5 & (~0xE00000)) | ((val) << 21))
#define get_PWM_1_Reg0x5_ADCS2                                  ((addPWM_1_Reg0x5 & 0xE00000) >> 21)

#define posPWM_1_Reg0x5_TRIOS2                                  18
#define bitPWM_1_Reg0x5_TRIOS2                                  0x1C0000
#define set_PWM_1_Reg0x5_TRIOS2(val)                            addPWM_1_Reg0x5 = ((addPWM_1_Reg0x5 & (~0x1C0000)) | ((val) << 18))
#define get_PWM_1_Reg0x5_TRIOS2                                 ((addPWM_1_Reg0x5 & 0x1C0000) >> 18)

#define posPWM_1_Reg0x5_ccus                                    17
#define bitPWM_1_Reg0x5_ccus                                    0x20000
#define set_PWM_1_Reg0x5_ccus(val)                              addPWM_1_Reg0x5 = ((addPWM_1_Reg0x5 & (~0x20000)) | ((val) << 17))
#define setf_PWM_1_Reg0x5_ccus                                  addPWM_1_Reg0x5 |= 0x20000
#define clrf_PWM_1_Reg0x5_ccus                                  addPWM_1_Reg0x5 &= ~0x20000
#define get_PWM_1_Reg0x5_ccus                                   ((addPWM_1_Reg0x5 & 0x20000) >> 17)


#define posPWM_1_Reg0x5_ADCS3                                   13
#define bitPWM_1_Reg0x5_ADCS3                                   0xE000
#define set_PWM_1_Reg0x5_ADCS3(val)                             addPWM_1_Reg0x5 = ((addPWM_1_Reg0x5 & (~0xE000)) | ((val) << 13))
#define get_PWM_1_Reg0x5_ADCS3                                  ((addPWM_1_Reg0x5 & 0xE000) >> 13)

#define posPWM_1_Reg0x5_TRIOS3                                  10
#define bitPWM_1_Reg0x5_TRIOS3                                  0x1C00
#define set_PWM_1_Reg0x5_TRIOS3(val)                            addPWM_1_Reg0x5 = ((addPWM_1_Reg0x5 & (~0x1C00)) | ((val) << 10))
#define get_PWM_1_Reg0x5_TRIOS3                                 ((addPWM_1_Reg0x5 & 0x1C00) >> 10)

#define posPWM_1_Reg0x5_CCPC                                    9
#define bitPWM_1_Reg0x5_CCPC                                    0x200
#define set_PWM_1_Reg0x5_CCPC(val)                              addPWM_1_Reg0x5 = ((addPWM_1_Reg0x5 & (~0x200)) | ((val) << 9))
#define setf_PWM_1_Reg0x5_CCPC                                  addPWM_1_Reg0x5 |= 0x200
#define clrf_PWM_1_Reg0x5_CCPC                                  addPWM_1_Reg0x5 &= ~0x200
#define get_PWM_1_Reg0x5_CCPC                                   ((addPWM_1_Reg0x5 & 0x200) >> 9)

#define posPWM_1_Reg0x5_TI1S                                    8
#define bitPWM_1_Reg0x5_TI1S                                    0x100
#define set_PWM_1_Reg0x5_TI1S(val)                              addPWM_1_Reg0x5 = ((addPWM_1_Reg0x5 & (~0x100)) | ((val) << 8))
#define setf_PWM_1_Reg0x5_TI1S                                  addPWM_1_Reg0x5 |= 0x100
#define clrf_PWM_1_Reg0x5_TI1S                                  addPWM_1_Reg0x5 &= ~0x100
#define get_PWM_1_Reg0x5_TI1S                                   ((addPWM_1_Reg0x5 & 0x100) >> 8)


//addPWM_1_Reg0x6
#define addPWM_1_Reg0x6                                         *((volatile unsigned long *) (0x00806b00+0x6*4))

#define posPWM_1_Reg0x6_TS3                                     19
#define bitPWM_1_Reg0x6_TS3                                     0x380000
#define set_PWM_1_Reg0x6_TS3(val)                               addPWM_1_Reg0x6 = ((addPWM_1_Reg0x6 & (~0x380000)) | ((val) << 19))
#define get_PWM_1_Reg0x6_TS3                                    ((addPWM_1_Reg0x6 & 0x380000) >> 19)

#define posPWM_1_Reg0x6_TS2                                     16
#define bitPWM_1_Reg0x6_TS2                                     0x70000
#define set_PWM_1_Reg0x6_TS2(val)                               addPWM_1_Reg0x6 = ((addPWM_1_Reg0x6 & (~0x70000)) | ((val) << 16))
#define get_PWM_1_Reg0x6_TS2                                    ((addPWM_1_Reg0x6 & 0x70000) >> 16)


#define posPWM_1_Reg0x6_TS1                                     12
#define bitPWM_1_Reg0x6_TS1                                     0x7000
#define set_PWM_1_Reg0x6_TS1(val)                               addPWM_1_Reg0x6 = ((addPWM_1_Reg0x6 & (~0x7000)) | ((val) << 12))
#define get_PWM_1_Reg0x6_TS1                                    ((addPWM_1_Reg0x6 & 0x7000) >> 12)

#define posPWM_1_Reg0x6_SMS3                                    8
#define bitPWM_1_Reg0x6_SMS3                                    0xF00
#define set_PWM_1_Reg0x6_SMS3(val)                              addPWM_1_Reg0x6 = ((addPWM_1_Reg0x6 & (~0xF00)) | ((val) << 8))
#define get_PWM_1_Reg0x6_SMS3                                   ((addPWM_1_Reg0x6 & 0xF00) >> 8)

#define posPWM_1_Reg0x6_SMS2                                    4
#define bitPWM_1_Reg0x6_SMS2                                    0xF0
#define set_PWM_1_Reg0x6_SMS2(val)                              addPWM_1_Reg0x6 = ((addPWM_1_Reg0x6 & (~0xF0)) | ((val) << 4))
#define get_PWM_1_Reg0x6_SMS2                                   ((addPWM_1_Reg0x6 & 0xF0) >> 4)

#define posPWM_1_Reg0x6_SMS1                                    0
#define bitPWM_1_Reg0x6_SMS1                                    0xF
#define set_PWM_1_Reg0x6_SMS1(val)                              addPWM_1_Reg0x6 = ((addPWM_1_Reg0x6 & (~0xF)) | ((val) << 0))
#define get_PWM_1_Reg0x6_SMS1                                   (addPWM_1_Reg0x6 & 0xF)

//addPWM_1_Reg0x7
#define addPWM_1_Reg0x7                                         *((volatile unsigned long *) (0x00806b00+0x7*4))
#define posPWM_1_Reg0x7_df_tim3                                 28
#define bitPWM_1_Reg0x7_df_tim3                                 0xF0000000
#define set_PWM_1_Reg0x7_df_tim3(val)                           addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0xF0000000)) | ((val) << 28))
#define get_PWM_1_Reg0x7_df_tim3                                ((addPWM_1_Reg0x7 & 0xF0000000) >> 28)

#define posPWM_1_Reg0x7_df_tim2                                 24
#define bitPWM_1_Reg0x7_df_tim2                                 0xF000000
#define set_PWM_1_Reg0x7_df_tim2(val)                           addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0xF000000)) | ((val) << 24))
#define get_PWM_1_Reg0x7_df_tim2                                ((addPWM_1_Reg0x7 & 0xF000000) >> 24)

#define posPWM_1_Reg0x7_df_tim1                                 20
#define bitPWM_1_Reg0x7_df_tim1                                 0xF00000
#define set_PWM_1_Reg0x7_df_tim1(val)                           addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0xF00000)) | ((val) << 20))
#define get_PWM_1_Reg0x7_df_tim1                                ((addPWM_1_Reg0x7 & 0xF00000) >> 20)


#define posPWM_1_Reg0x7_COMIE                                   15
#define bitPWM_1_Reg0x7_COMIE                                   0x8000
#define set_PWM_1_Reg0x7_COMIE(val)                             addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x8000)) | ((val) << 15))
#define setf_PWM_1_Reg0x7_COMIE                                 addPWM_1_Reg0x7 |= 0x8000
#define clrf_PWM_1_Reg0x7_COMIE                                 addPWM_1_Reg0x7 &= ~0x8000
#define get_PWM_1_Reg0x7_COMIE                                  ((addPWM_1_Reg0x7 & 0x8000) >> 15)

#define posPWM_1_Reg0x7_TIE3                                    14
#define bitPWM_1_Reg0x7_TIE3                                    0x4000
#define set_PWM_1_Reg0x7_TIE3(val)                              addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x4000)) | ((val) << 14))
#define setf_PWM_1_Reg0x7_TIE3                                  addPWM_1_Reg0x7 |= 0x4000
#define clrf_PWM_1_Reg0x7_TIE3                                  addPWM_1_Reg0x7 &= ~0x4000
#define get_PWM_1_Reg0x7_TIE3                                   ((addPWM_1_Reg0x7 & 0x4000) >> 14)

#define posPWM_1_Reg0x7_TIE2                                    13
#define bitPWM_1_Reg0x7_TIE2                                    0x2000
#define set_PWM_1_Reg0x7_TIE2(val)                              addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x2000)) | ((val) << 13))
#define setf_PWM_1_Reg0x7_TIE2                                  addPWM_1_Reg0x7 |= 0x2000
#define clrf_PWM_1_Reg0x7_TIE2                                  addPWM_1_Reg0x7 &= ~0x2000
#define get_PWM_1_Reg0x7_TIE2                                   ((addPWM_1_Reg0x7 & 0x2000) >> 13)

#define posPWM_1_Reg0x7_TIE1                                    12
#define bitPWM_1_Reg0x7_TIE1                                    0x1000
#define set_PWM_1_Reg0x7_TIE1(val)                              addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x1000)) | ((val) << 12))
#define setf_PWM_1_Reg0x7_TIE1                                  addPWM_1_Reg0x7 |= 0x1000
#define clrf_PWM_1_Reg0x7_TIE1                                  addPWM_1_Reg0x7 &= ~0x1000
#define get_PWM_1_Reg0x7_TIE1                                   ((addPWM_1_Reg0x7 & 0x1000) >> 12)

#define posPWM_1_Reg0x7_UIE3                                    11
#define bitPWM_1_Reg0x7_UIE3                                    0x800
#define set_PWM_1_Reg0x7_UIE3(val)                              addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x800)) | ((val) << 11))
#define setf_PWM_1_Reg0x7_UIE3                                  addPWM_1_Reg0x7 |= 0x800
#define clrf_PWM_1_Reg0x7_UIE3                                  addPWM_1_Reg0x7 &= ~0x800
#define get_PWM_1_Reg0x7_UIE3                                   ((addPWM_1_Reg0x7 & 0x800) >> 11)

#define posPWM_1_Reg0x7_UIE2                                    10
#define bitPWM_1_Reg0x7_UIE2                                    0x400
#define set_PWM_1_Reg0x7_UIE2(val)                              addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x400)) | ((val) << 10))
#define setf_PWM_1_Reg0x7_UIE2                                  addPWM_1_Reg0x7 |= 0x400
#define clrf_PWM_1_Reg0x7_UIE2                                  addPWM_1_Reg0x7 &= ~0x400
#define get_PWM_1_Reg0x7_UIE2                                   ((addPWM_1_Reg0x7 & 0x400) >> 10)

#define posPWM_1_Reg0x7_UIE1                                    9
#define bitPWM_1_Reg0x7_UIE1                                    0x200
#define set_PWM_1_Reg0x7_UIE1(val)                              addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x200)) | ((val) << 9))
#define setf_PWM_1_Reg0x7_UIE1                                  addPWM_1_Reg0x7 |= 0x200
#define clrf_PWM_1_Reg0x7_UIE1                                  addPWM_1_Reg0x7 &= ~0x200
#define get_PWM_1_Reg0x7_UIE1                                   ((addPWM_1_Reg0x7 & 0x200) >> 9)

#define posPWM_1_Reg0x7_CC9IE                                   8
#define bitPWM_1_Reg0x7_CC9IE                                   0x100
#define set_PWM_1_Reg0x7_CC9IE(val)                             addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x100)) | ((val) << 8))
#define setf_PWM_1_Reg0x7_CC9IE                                 addPWM_1_Reg0x7 |= 0x100
#define clrf_PWM_1_Reg0x7_CC9IE                                 addPWM_1_Reg0x7 &= ~0x100
#define get_PWM_1_Reg0x7_CC9IE                                  ((addPWM_1_Reg0x7 & 0x100) >> 8)

#define posPWM_1_Reg0x7_CC8IE                                   7
#define bitPWM_1_Reg0x7_CC8IE                                   0x80
#define set_PWM_1_Reg0x7_CC8IE(val)                             addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x80)) | ((val) << 7))
#define setf_PWM_1_Reg0x7_CC8IE                                 addPWM_1_Reg0x7 |= 0x80
#define clrf_PWM_1_Reg0x7_CC8IE                                 addPWM_1_Reg0x7 &= ~0x80
#define get_PWM_1_Reg0x7_CC8IE                                  ((addPWM_1_Reg0x7 & 0x80) >> 7)

#define posPWM_1_Reg0x7_CC7IE                                   6
#define bitPWM_1_Reg0x7_CC7IE                                   0x40
#define set_PWM_1_Reg0x7_CC7IE(val)                             addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x40)) | ((val) << 6))
#define setf_PWM_1_Reg0x7_CC7IE                                 addPWM_1_Reg0x7 |= 0x40
#define clrf_PWM_1_Reg0x7_CC7IE                                 addPWM_1_Reg0x7 &= ~0x40
#define get_PWM_1_Reg0x7_CC7IE                                  ((addPWM_1_Reg0x7 & 0x40) >> 6)

#define posPWM_1_Reg0x7_CC6IE                                   5
#define bitPWM_1_Reg0x7_CC6IE                                   0x20
#define set_PWM_1_Reg0x7_CC6IE(val)                             addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x20)) | ((val) << 5))
#define setf_PWM_1_Reg0x7_CC6IE                                 addPWM_1_Reg0x7 |= 0x20
#define clrf_PWM_1_Reg0x7_CC6IE                                 addPWM_1_Reg0x7 &= ~0x20
#define get_PWM_1_Reg0x7_CC6IE                                  ((addPWM_1_Reg0x7 & 0x20) >> 5)

#define posPWM_1_Reg0x7_CC5IE                                   4
#define bitPWM_1_Reg0x7_CC5IE                                   0x10
#define set_PWM_1_Reg0x7_CC5IE(val)                             addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x10)) | ((val) << 4))
#define setf_PWM_1_Reg0x7_CC5IE                                 addPWM_1_Reg0x7 |= 0x10
#define clrf_PWM_1_Reg0x7_CC5IE                                 addPWM_1_Reg0x7 &= ~0x10
#define get_PWM_1_Reg0x7_CC5IE                                  ((addPWM_1_Reg0x7 & 0x10) >> 4)

#define posPWM_1_Reg0x7_CC4IE                                   3
#define bitPWM_1_Reg0x7_CC4IE                                   0x8
#define set_PWM_1_Reg0x7_CC4IE(val)                             addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x8)) | ((val) << 3))
#define setf_PWM_1_Reg0x7_CC4IE                                 addPWM_1_Reg0x7 |= 0x8
#define clrf_PWM_1_Reg0x7_CC4IE                                 addPWM_1_Reg0x7 &= ~0x8
#define get_PWM_1_Reg0x7_CC4IE                                  ((addPWM_1_Reg0x7 & 0x8) >> 3)

#define posPWM_1_Reg0x7_CC3IE                                   2
#define bitPWM_1_Reg0x7_CC3IE                                   0x4
#define set_PWM_1_Reg0x7_CC3IE(val)                             addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x4)) | ((val) << 2))
#define setf_PWM_1_Reg0x7_CC3IE                                 addPWM_1_Reg0x7 |= 0x4
#define clrf_PWM_1_Reg0x7_CC3IE                                 addPWM_1_Reg0x7 &= ~0x4
#define get_PWM_1_Reg0x7_CC3IE                                  ((addPWM_1_Reg0x7 & 0x4) >> 2)

#define posPWM_1_Reg0x7_CC2IE                                   1
#define bitPWM_1_Reg0x7_CC2IE                                   0x2
#define set_PWM_1_Reg0x7_CC2IE(val)                             addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x2)) | ((val) << 1))
#define setf_PWM_1_Reg0x7_CC2IE                                 addPWM_1_Reg0x7 |= 0x2
#define clrf_PWM_1_Reg0x7_CC2IE                                 addPWM_1_Reg0x7 &= ~0x2
#define get_PWM_1_Reg0x7_CC2IE                                  ((addPWM_1_Reg0x7 & 0x2) >> 1)

#define posPWM_1_Reg0x7_CC1IE                                   0
#define bitPWM_1_Reg0x7_CC1IE                                   0x1
#define set_PWM_1_Reg0x7_CC1IE(val)                             addPWM_1_Reg0x7 = ((addPWM_1_Reg0x7 & (~0x1)) | ((val) << 0))
#define setf_PWM_1_Reg0x7_CC1IE                                 addPWM_1_Reg0x7 |= 0x1
#define clrf_PWM_1_Reg0x7_CC1IE                                 addPWM_1_Reg0x7 &= ~0x1
#define get_PWM_1_Reg0x7_CC1IE                                  (addPWM_1_Reg0x7 & 0x1)

//addPWM_1_Reg0x8
#define addPWM_1_Reg0x8                                         *((volatile unsigned long *) (0x00806b00+0x8*4))

#define posPWM_1_Reg0x8_COMIF                                   15
#define bitPWM_1_Reg0x8_COMIF                                   0x8000
#define set_PWM_1_Reg0x8_COMIF(val)                             addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x8000)) | ((val) << 15))
#define setf_PWM_1_Reg0x8_COMIF                                 addPWM_1_Reg0x8 |= 0x8000
#define clrf_PWM_1_Reg0x8_COMIF                                 addPWM_1_Reg0x8 &= ~0x8000
#define get_PWM_1_Reg0x8_COMIF                                  ((addPWM_1_Reg0x8 & 0x8000) >> 15)

#define posPWM_1_Reg0x8_TIF3                                    14
#define bitPWM_1_Reg0x8_TIF3                                    0x4000
#define set_PWM_1_Reg0x8_TIF3(val)                              addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x4000)) | ((val) << 14))
#define setf_PWM_1_Reg0x8_TIF3                                  addPWM_1_Reg0x8 |= 0x4000
#define clrf_PWM_1_Reg0x8_TIF3                                  addPWM_1_Reg0x8 &= ~0x4000
#define get_PWM_1_Reg0x8_TIF3                                   ((addPWM_1_Reg0x8 & 0x4000) >> 14)

#define posPWM_1_Reg0x8_TIF2                                    13
#define bitPWM_1_Reg0x8_TIF2                                    0x2000
#define set_PWM_1_Reg0x8_TIF2(val)                              addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x2000)) | ((val) << 13))
#define setf_PWM_1_Reg0x8_TIF2                                  addPWM_1_Reg0x8 |= 0x2000
#define clrf_PWM_1_Reg0x8_TIF2                                  addPWM_1_Reg0x8 &= ~0x2000
#define get_PWM_1_Reg0x8_TIF2                                   ((addPWM_1_Reg0x8 & 0x2000) >> 13)

#define posPWM_1_Reg0x8_TIF1                                    12
#define bitPWM_1_Reg0x8_TIF1                                    0x1000
#define set_PWM_1_Reg0x8_TIF1(val)                              addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x1000)) | ((val) << 12))
#define setf_PWM_1_Reg0x8_TIF1                                  addPWM_1_Reg0x8 |= 0x1000
#define clrf_PWM_1_Reg0x8_TIF1                                  addPWM_1_Reg0x8 &= ~0x1000
#define get_PWM_1_Reg0x8_TIF1                                   ((addPWM_1_Reg0x8 & 0x1000) >> 12)

#define posPWM_1_Reg0x8_UIF3                                    11
#define bitPWM_1_Reg0x8_UIF3                                    0x800
#define set_PWM_1_Reg0x8_UIF3(val)                              addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x800)) | ((val) << 11))
#define setf_PWM_1_Reg0x8_UIF3                                  addPWM_1_Reg0x8 |= 0x800
#define clrf_PWM_1_Reg0x8_UIF3                                  addPWM_1_Reg0x8 &= ~0x800
#define get_PWM_1_Reg0x8_UIF3                                   ((addPWM_1_Reg0x8 & 0x800) >> 11)

#define posPWM_1_Reg0x8_UIF2                                    10
#define bitPWM_1_Reg0x8_UIF2                                    0x400
#define set_PWM_1_Reg0x8_UIF2(val)                              addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x400)) | ((val) << 10))
#define setf_PWM_1_Reg0x8_UIF2                                  addPWM_1_Reg0x8 |= 0x400
#define clrf_PWM_1_Reg0x8_UIF2                                  addPWM_1_Reg0x8 &= ~0x400
#define get_PWM_1_Reg0x8_UIF2                                   ((addPWM_1_Reg0x8 & 0x400) >> 10)

#define posPWM_1_Reg0x8_UIF1                                    9
#define bitPWM_1_Reg0x8_UIF1                                    0x200
#define set_PWM_1_Reg0x8_UIF1(val)                              addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x200)) | ((val) << 9))
#define setf_PWM_1_Reg0x8_UIF1                                  addPWM_1_Reg0x8 |= 0x200
#define clrf_PWM_1_Reg0x8_UIF1                                  addPWM_1_Reg0x8 &= ~0x200
#define get_PWM_1_Reg0x8_UIF1                                   ((addPWM_1_Reg0x8 & 0x200) >> 9)

#define posPWM_1_Reg0x8_CC9IF                                   8
#define bitPWM_1_Reg0x8_CC9IF                                   0x100
#define set_PWM_1_Reg0x8_CC9IF(val)                             addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x100)) | ((val) << 8))
#define setf_PWM_1_Reg0x8_CC9IF                                 addPWM_1_Reg0x8 |= 0x100
#define clrf_PWM_1_Reg0x8_CC9IF                                 addPWM_1_Reg0x8 &= ~0x100
#define get_PWM_1_Reg0x8_CC9IF                                  ((addPWM_1_Reg0x8 & 0x100) >> 8)

#define posPWM_1_Reg0x8_CC8IF                                   7
#define bitPWM_1_Reg0x8_CC8IF                                   0x80
#define set_PWM_1_Reg0x8_CC8IF(val)                             addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x80)) | ((val) << 7))
#define setf_PWM_1_Reg0x8_CC8IF                                 addPWM_1_Reg0x8 |= 0x80
#define clrf_PWM_1_Reg0x8_CC8IF                                 addPWM_1_Reg0x8 &= ~0x80
#define get_PWM_1_Reg0x8_CC8IF                                  ((addPWM_1_Reg0x8 & 0x80) >> 7)

#define posPWM_1_Reg0x8_CC7IF                                   6
#define bitPWM_1_Reg0x8_CC7IF                                   0x40
#define set_PWM_1_Reg0x8_CC7IF(val)                             addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x40)) | ((val) << 6))
#define setf_PWM_1_Reg0x8_CC7IF                                 addPWM_1_Reg0x8 |= 0x40
#define clrf_PWM_1_Reg0x8_CC7IF                                 addPWM_1_Reg0x8 &= ~0x40
#define get_PWM_1_Reg0x8_CC7IF                                  ((addPWM_1_Reg0x8 & 0x40) >> 6)

#define posPWM_1_Reg0x8_CC6IF                                   5
#define bitPWM_1_Reg0x8_CC6IF                                   0x20
#define set_PWM_1_Reg0x8_CC6IF(val)                             addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x20)) | ((val) << 5))
#define setf_PWM_1_Reg0x8_CC6IF                                 addPWM_1_Reg0x8 |= 0x20
#define clrf_PWM_1_Reg0x8_CC6IF                                 addPWM_1_Reg0x8 &= ~0x20
#define get_PWM_1_Reg0x8_CC6IF                                  ((addPWM_1_Reg0x8 & 0x20) >> 5)

#define posPWM_1_Reg0x8_CC5IF                                   4
#define bitPWM_1_Reg0x8_CC5IF                                   0x10
#define set_PWM_1_Reg0x8_CC5IF(val)                             addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x10)) | ((val) << 4))
#define setf_PWM_1_Reg0x8_CC5IF                                 addPWM_1_Reg0x8 |= 0x10
#define clrf_PWM_1_Reg0x8_CC5IF                                 addPWM_1_Reg0x8 &= ~0x10
#define get_PWM_1_Reg0x8_CC5IF                                  ((addPWM_1_Reg0x8 & 0x10) >> 4)

#define posPWM_1_Reg0x8_CC4IF                                   3
#define bitPWM_1_Reg0x8_CC4IF                                   0x8
#define set_PWM_1_Reg0x8_CC4IF(val)                             addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x8)) | ((val) << 3))
#define setf_PWM_1_Reg0x8_CC4IF                                 addPWM_1_Reg0x8 |= 0x8
#define clrf_PWM_1_Reg0x8_CC4IF                                 addPWM_1_Reg0x8 &= ~0x8
#define get_PWM_1_Reg0x8_CC4IF                                  ((addPWM_1_Reg0x8 & 0x8) >> 3)

#define posPWM_1_Reg0x8_CC3IF                                   2
#define bitPWM_1_Reg0x8_CC3IF                                   0x4
#define set_PWM_1_Reg0x8_CC3IF(val)                             addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x4)) | ((val) << 2))
#define setf_PWM_1_Reg0x8_CC3IF                                 addPWM_1_Reg0x8 |= 0x4
#define clrf_PWM_1_Reg0x8_CC3IF                                 addPWM_1_Reg0x8 &= ~0x4
#define get_PWM_1_Reg0x8_CC3IF                                  ((addPWM_1_Reg0x8 & 0x4) >> 2)

#define posPWM_1_Reg0x8_CC2IF                                   1
#define bitPWM_1_Reg0x8_CC2IF                                   0x2
#define set_PWM_1_Reg0x8_CC2IF(val)                             addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x2)) | ((val) << 1))
#define setf_PWM_1_Reg0x8_CC2IF                                 addPWM_1_Reg0x8 |= 0x2
#define clrf_PWM_1_Reg0x8_CC2IF                                 addPWM_1_Reg0x8 &= ~0x2
#define get_PWM_1_Reg0x8_CC2IF                                  ((addPWM_1_Reg0x8 & 0x2) >> 1)

#define posPWM_1_Reg0x8_CC1IF                                   0
#define bitPWM_1_Reg0x8_CC1IF                                   0x1
#define set_PWM_1_Reg0x8_CC1IF(val)                             addPWM_1_Reg0x8 = ((addPWM_1_Reg0x8 & (~0x1)) | ((val) << 0))
#define setf_PWM_1_Reg0x8_CC1IF                                 addPWM_1_Reg0x8 |= 0x1
#define clrf_PWM_1_Reg0x8_CC1IF                                 addPWM_1_Reg0x8 &= ~0x1
#define get_PWM_1_Reg0x8_CC1IF                                  (addPWM_1_Reg0x8 & 0x1)

//addPWM_1_Reg0x9
#define addPWM_1_Reg0x9                                         *((volatile unsigned long *) (0x00806b00+0x9*4))

#define posPWM_1_Reg0x9_COMG                                    15
#define bitPWM_1_Reg0x9_COMG                                    0x8000
#define set_PWM_1_Reg0x9_COMG(val)                              addPWM_1_Reg0x9 = ((addPWM_1_Reg0x9 & (~0x8000)) | ((val) << 15))
#define setf_PWM_1_Reg0x9_COMG                                  addPWM_1_Reg0x9 |= 0x8000
#define clrf_PWM_1_Reg0x9_COMG                                  addPWM_1_Reg0x9 &= ~0x8000
#define get_PWM_1_Reg0x9_COMG                                   ((addPWM_1_Reg0x9 & 0x8000) >> 15)

#define posPWM_1_Reg0x9_TG3                                     14
#define bitPWM_1_Reg0x9_TG3                                     0x4000
#define set_PWM_1_Reg0x9_TG3(val)                               addPWM_1_Reg0x9 = ((addPWM_1_Reg0x9 & (~0x4000)) | ((val) << 14))
#define setf_PWM_1_Reg0x9_TG3                                   addPWM_1_Reg0x9 |= 0x4000
#define clrf_PWM_1_Reg0x9_TG3                                   addPWM_1_Reg0x9 &= ~0x4000
#define get_PWM_1_Reg0x9_TG3                                    ((addPWM_1_Reg0x9 & 0x4000) >> 14)

#define posPWM_1_Reg0x9_TG2                                     13
#define bitPWM_1_Reg0x9_TG2                                     0x2000
#define set_PWM_1_Reg0x9_TG2(val)                               addPWM_1_Reg0x9 = ((addPWM_1_Reg0x9 & (~0x2000)) | ((val) << 13))
#define setf_PWM_1_Reg0x9_TG2                                   addPWM_1_Reg0x9 |= 0x2000
#define clrf_PWM_1_Reg0x9_TG2                                   addPWM_1_Reg0x9 &= ~0x2000
#define get_PWM_1_Reg0x9_TG2                                    ((addPWM_1_Reg0x9 & 0x2000) >> 13)

#define posPWM_1_Reg0x9_TG1                                     12
#define bitPWM_1_Reg0x9_TG1                                     0x1000
#define set_PWM_1_Reg0x9_TG1(val)                               addPWM_1_Reg0x9 = ((addPWM_1_Reg0x9 & (~0x1000)) | ((val) << 12))
#define setf_PWM_1_Reg0x9_TG1                                   addPWM_1_Reg0x9 |= 0x1000
#define clrf_PWM_1_Reg0x9_TG1                                   addPWM_1_Reg0x9 &= ~0x1000
#define get_PWM_1_Reg0x9_TG1                                    ((addPWM_1_Reg0x9 & 0x1000) >> 12)

#define posPWM_1_Reg0x9_UG3                                     11
#define bitPWM_1_Reg0x9_UG3                                     0x800
#define set_PWM_1_Reg0x9_UG3(val)                               addPWM_1_Reg0x9 = ((addPWM_1_Reg0x9 & (~0x800)) | ((val) << 11))
#define setf_PWM_1_Reg0x9_UG3                                   addPWM_1_Reg0x9 |= 0x800
#define clrf_PWM_1_Reg0x9_UG3                                   addPWM_1_Reg0x9 &= ~0x800
#define get_PWM_1_Reg0x9_UG3                                    ((addPWM_1_Reg0x9 & 0x800) >> 11)

#define posPWM_1_Reg0x9_UG2                                     10
#define bitPWM_1_Reg0x9_UG2                                     0x400
#define set_PWM_1_Reg0x9_UG2(val)                               addPWM_1_Reg0x9 = ((addPWM_1_Reg0x9 & (~0x400)) | ((val) << 10))
#define setf_PWM_1_Reg0x9_UG2                                   addPWM_1_Reg0x9 |= 0x400
#define clrf_PWM_1_Reg0x9_UG2                                   addPWM_1_Reg0x9 &= ~0x400
#define get_PWM_1_Reg0x9_UG2                                    ((addPWM_1_Reg0x9 & 0x400) >> 10)

#define posPWM_1_Reg0x9_UG1                                     9
#define bitPWM_1_Reg0x9_UG1                                     0x200
#define set_PWM_1_Reg0x9_UG1(val)                               addPWM_1_Reg0x9 = ((addPWM_1_Reg0x9 & (~0x200)) | ((val) << 9))
#define setf_PWM_1_Reg0x9_UG1                                   addPWM_1_Reg0x9 |= 0x200
#define clrf_PWM_1_Reg0x9_UG1                                   addPWM_1_Reg0x9 &= ~0x200
#define get_PWM_1_Reg0x9_UG1                                    ((addPWM_1_Reg0x9 & 0x200) >> 9)


//addPWM_1_Reg0xa
#define addPWM_1_Reg0xa                                         *((volatile unsigned long *) (0x00806b00+0xa*4))

#define posPWM_1_Reg0xa_OC3M                                    27
#define bitPWM_1_Reg0xa_OC3M                                    0x38000000
#define set_PWM_1_Reg0xa_OC3M(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x38000000)) | ((val) << 27))
#define get_PWM_1_Reg0xa_OC3M                                   ((addPWM_1_Reg0xa & 0x38000000) >> 27)

#define posPWM_1_Reg0xa_OC2M                                    24
#define bitPWM_1_Reg0xa_OC2M                                    0x7000000
#define set_PWM_1_Reg0xa_OC2M(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x7000000)) | ((val) << 24))
#define get_PWM_1_Reg0xa_OC2M                                   ((addPWM_1_Reg0xa & 0x7000000) >> 24)

#define posPWM_1_Reg0xa_OC1M                                    21
#define bitPWM_1_Reg0xa_OC1M                                    0xE00000
#define set_PWM_1_Reg0xa_OC1M(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0xE00000)) | ((val) << 21))
#define get_PWM_1_Reg0xa_OC1M                                   ((addPWM_1_Reg0xa & 0xE00000) >> 21)

#define posPWM_1_Reg0xa_TIM3CCM                                 20
#define bitPWM_1_Reg0xa_TIM3CCM                                 0x100000
#define set_PWM_1_Reg0xa_TIM3CCM(val)                           addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x100000)) | ((val) << 20))
#define setf_PWM_1_Reg0xa_TIM3CCM                               addPWM_1_Reg0xa |= 0x100000
#define clrf_PWM_1_Reg0xa_TIM3CCM                               addPWM_1_Reg0xa &= ~0x100000
#define get_PWM_1_Reg0xa_TIM3CCM                                ((addPWM_1_Reg0xa & 0x100000) >> 20)

#define posPWM_1_Reg0xa_TIM2CCM                                 19
#define bitPWM_1_Reg0xa_TIM2CCM                                 0x80000
#define set_PWM_1_Reg0xa_TIM2CCM(val)                           addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x80000)) | ((val) << 19))
#define setf_PWM_1_Reg0xa_TIM2CCM                               addPWM_1_Reg0xa |= 0x80000
#define clrf_PWM_1_Reg0xa_TIM2CCM                               addPWM_1_Reg0xa &= ~0x80000
#define get_PWM_1_Reg0xa_TIM2CCM                                ((addPWM_1_Reg0xa & 0x80000) >> 19)

#define posPWM_1_Reg0xa_TIM1CCM                                 18
#define bitPWM_1_Reg0xa_TIM1CCM                                 0x40000
#define set_PWM_1_Reg0xa_TIM1CCM(val)                           addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x40000)) | ((val) << 18))
#define setf_PWM_1_Reg0xa_TIM1CCM                               addPWM_1_Reg0xa |= 0x40000
#define clrf_PWM_1_Reg0xa_TIM1CCM                               addPWM_1_Reg0xa &= ~0x40000
#define get_PWM_1_Reg0xa_TIM1CCM                                ((addPWM_1_Reg0xa & 0x40000) >> 18)

#define posPWM_1_Reg0xa_CH6E                                    17
#define bitPWM_1_Reg0xa_CH6E                                    0x20000
#define set_PWM_1_Reg0xa_CH6E(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x20000)) | ((val) << 17))
#define setf_PWM_1_Reg0xa_CH6E                                  addPWM_1_Reg0xa |= 0x20000
#define clrf_PWM_1_Reg0xa_CH6E                                  addPWM_1_Reg0xa &= ~0x20000
#define get_PWM_1_Reg0xa_CH6E                                   ((addPWM_1_Reg0xa & 0x20000) >> 17)

#define posPWM_1_Reg0xa_CH5E                                    16
#define bitPWM_1_Reg0xa_CH5E                                    0x10000
#define set_PWM_1_Reg0xa_CH5E(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x10000)) | ((val) << 16))
#define setf_PWM_1_Reg0xa_CH5E                                  addPWM_1_Reg0xa |= 0x10000
#define clrf_PWM_1_Reg0xa_CH5E                                  addPWM_1_Reg0xa &= ~0x10000
#define get_PWM_1_Reg0xa_CH5E                                   ((addPWM_1_Reg0xa & 0x10000) >> 16)

#define posPWM_1_Reg0xa_CH4E                                    15
#define bitPWM_1_Reg0xa_CH4E                                    0x8000
#define set_PWM_1_Reg0xa_CH4E(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x8000)) | ((val) << 15))
#define setf_PWM_1_Reg0xa_CH4E                                  addPWM_1_Reg0xa |= 0x8000
#define clrf_PWM_1_Reg0xa_CH4E                                  addPWM_1_Reg0xa &= ~0x8000
#define get_PWM_1_Reg0xa_CH4E                                   ((addPWM_1_Reg0xa & 0x8000) >> 15)

#define posPWM_1_Reg0xa_CH3E                                    14
#define bitPWM_1_Reg0xa_CH3E                                    0x4000
#define set_PWM_1_Reg0xa_CH3E(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x4000)) | ((val) << 14))
#define setf_PWM_1_Reg0xa_CH3E                                  addPWM_1_Reg0xa |= 0x4000
#define clrf_PWM_1_Reg0xa_CH3E                                  addPWM_1_Reg0xa &= ~0x4000
#define get_PWM_1_Reg0xa_CH3E                                   ((addPWM_1_Reg0xa & 0x4000) >> 14)

#define posPWM_1_Reg0xa_CH2E                                    13
#define bitPWM_1_Reg0xa_CH2E                                    0x2000
#define set_PWM_1_Reg0xa_CH2E(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x2000)) | ((val) << 13))
#define setf_PWM_1_Reg0xa_CH2E                                  addPWM_1_Reg0xa |= 0x2000
#define clrf_PWM_1_Reg0xa_CH2E                                  addPWM_1_Reg0xa &= ~0x2000
#define get_PWM_1_Reg0xa_CH2E                                   ((addPWM_1_Reg0xa & 0x2000) >> 13)

#define posPWM_1_Reg0xa_CH1E                                    12
#define bitPWM_1_Reg0xa_CH1E                                    0x1000
#define set_PWM_1_Reg0xa_CH1E(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x1000)) | ((val) << 12))
#define setf_PWM_1_Reg0xa_CH1E                                  addPWM_1_Reg0xa |= 0x1000
#define clrf_PWM_1_Reg0xa_CH1E                                  addPWM_1_Reg0xa &= ~0x1000
#define get_PWM_1_Reg0xa_CH1E                                   ((addPWM_1_Reg0xa & 0x1000) >> 12)

#define posPWM_1_Reg0xa_CH6P                                    10
#define bitPWM_1_Reg0xa_CH6P                                    0xC00
#define set_PWM_1_Reg0xa_CH6P(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0xC00)) | ((val) << 10))
#define get_PWM_1_Reg0xa_CH6P                                   ((addPWM_1_Reg0xa & 0xC00) >> 10)

#define posPWM_1_Reg0xa_CH5P                                    8
#define bitPWM_1_Reg0xa_CH5P                                    0x300
#define set_PWM_1_Reg0xa_CH5P(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x300)) | ((val) << 8))
#define get_PWM_1_Reg0xa_CH5P                                   ((addPWM_1_Reg0xa & 0x300) >> 8)

#define posPWM_1_Reg0xa_CH4P                                    6
#define bitPWM_1_Reg0xa_CH4P                                    0xC0
#define set_PWM_1_Reg0xa_CH4P(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0xC0)) | ((val) << 6))
#define get_PWM_1_Reg0xa_CH4P                                   ((addPWM_1_Reg0xa & 0xC0) >> 6)

#define posPWM_1_Reg0xa_CH3P                                    4
#define bitPWM_1_Reg0xa_CH3P                                    0x30
#define set_PWM_1_Reg0xa_CH3P(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x30)) | ((val) << 4))
#define get_PWM_1_Reg0xa_CH3P                                   ((addPWM_1_Reg0xa & 0x30) >> 4)

#define posPWM_1_Reg0xa_CH2P                                    2
#define bitPWM_1_Reg0xa_CH2P                                    0xC
#define set_PWM_1_Reg0xa_CH2P(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0xC)) | ((val) << 2))
#define get_PWM_1_Reg0xa_CH2P                                   ((addPWM_1_Reg0xa & 0xC) >> 2)

#define posPWM_1_Reg0xa_CH1P                                    0
#define bitPWM_1_Reg0xa_CH1P                                    0x3
#define set_PWM_1_Reg0xa_CH1P(val)                              addPWM_1_Reg0xa = ((addPWM_1_Reg0xa & (~0x3)) | ((val) << 0))
#define get_PWM_1_Reg0xa_CH1P                                   (addPWM_1_Reg0xa & 0x3)

//addPWM_1_Reg0xb
#define addPWM_1_Reg0xb                                         *((volatile unsigned long *) (0x00806b00+0xb*4))

//addPWM_1_Reg0xc
#define addPWM_1_Reg0xc                                         *((volatile unsigned long *) (0x00806b00+0xc*4))

//addPWM_1_Reg0xd
#define addPWM_1_Reg0xd                                         *((volatile unsigned long *) (0x00806b00+0xd*4))

//addPWM_1_Reg0xe
#define addPWM_1_Reg0xe                                         *((volatile unsigned long *) (0x00806b00+0xe*4))

#define posPWM_1_Reg0xe_PSC3                                    16
#define bitPWM_1_Reg0xe_PSC3                                    0xFF0000
#define set_PWM_1_Reg0xe_PSC3(val)                              addPWM_1_Reg0xe = ((addPWM_1_Reg0xe & (~0xFF0000)) | ((val) << 16))
#define get_PWM_1_Reg0xe_PSC3                                   ((addPWM_1_Reg0xe & 0xFF0000) >> 16)

#define posPWM_1_Reg0xe_PSC2                                    8
#define bitPWM_1_Reg0xe_PSC2                                    0xFF00
#define set_PWM_1_Reg0xe_PSC2(val)                              addPWM_1_Reg0xe = ((addPWM_1_Reg0xe & (~0xFF00)) | ((val) << 8))
#define get_PWM_1_Reg0xe_PSC2                                   ((addPWM_1_Reg0xe & 0xFF00) >> 8)

#define posPWM_1_Reg0xe_PSC1                                    0
#define bitPWM_1_Reg0xe_PSC1                                    0xFF
#define set_PWM_1_Reg0xe_PSC1(val)                              addPWM_1_Reg0xe = ((addPWM_1_Reg0xe & (~0xFF)) | ((val) << 0))
#define get_PWM_1_Reg0xe_PSC1                                   (addPWM_1_Reg0xe & 0xFF)

//addPWM_1_Reg0xf
#define addPWM_1_Reg0xf                                         *((volatile unsigned long *) (0x00806b00+0xf*4))

//addPWM_1_Reg0x10
#define addPWM_1_Reg0x10                                        *((volatile unsigned long *) (0x00806b00+0x10*4))

//addPWM_1_Reg0x11
#define addPWM_1_Reg0x11                                        *((volatile unsigned long *) (0x00806b00+0x11*4))

//addPWM_1_Reg0x12
#define addPWM_1_Reg0x12                                        *((volatile unsigned long *) (0x00806b00+0x12*4))

//addPWM_1_Reg0x13
#define addPWM_1_Reg0x13                                        *((volatile unsigned long *) (0x00806b00+0x13*4))

//addPWM_1_Reg0x14
#define addPWM_1_Reg0x14                                        *((volatile unsigned long *) (0x00806b00+0x14*4))

//addPWM_1_Reg0x15
#define addPWM_1_Reg0x15                                        *((volatile unsigned long *) (0x00806b00+0x15*4))

//addPWM_1_Reg0x16
#define addPWM_1_Reg0x16                                        *((volatile unsigned long *) (0x00806b00+0x16*4))

//addPWM_1_Reg0x17
#define addPWM_1_Reg0x17                                        *((volatile unsigned long *) (0x00806b00+0x17*4))

//addPWM_1_Reg0x18
#define addPWM_1_Reg0x18                                        *((volatile unsigned long *) (0x00806b00+0x18*4))

//addPWM_1_Reg0x19
#define addPWM_1_Reg0x19                                        *((volatile unsigned long *) (0x00806b00+0x19*4))

//addPWM_1_Reg0x1a
#define addPWM_1_Reg0x1a                                        *((volatile unsigned long *) (0x00806b00+0x1a*4))

//addPWM_1_Reg0x1b
#define addPWM_1_Reg0x1b                                        *((volatile unsigned long *) (0x00806b00+0x1b*4))

//addPWM_1_Reg0x1c
#define addPWM_1_Reg0x1c                                        *((volatile unsigned long *) (0x00806b00+0x1c*4))

//addPWM_1_Reg0x1d
#define addPWM_1_Reg0x1d                                        *((volatile unsigned long *) (0x00806b00+0x1d*4))

//addPWM_1_Reg0x1e
#define addPWM_1_Reg0x1e                                        *((volatile unsigned long *) (0x00806b00+0x1e*4))

#define posPWM_1_Reg0x1e_DT3                                    20
#define bitPWM_1_Reg0x1e_DT3                                    0x3FF00000
#define set_PWM_1_Reg0x1e_DT3(val)                              addPWM_1_Reg0x1e = ((addPWM_1_Reg0x1e & (~0x3FF00000)) | ((val) << 20))
#define get_PWM_1_Reg0x1e_DT3                                   ((addPWM_1_Reg0x1e & 0x3FF00000) >> 20)

#define posPWM_1_Reg0x1e_DT2                                    10
#define bitPWM_1_Reg0x1e_DT2                                    0xFFC00
#define set_PWM_1_Reg0x1e_DT2(val)                              addPWM_1_Reg0x1e = ((addPWM_1_Reg0x1e & (~0xFFC00)) | ((val) << 10))
#define get_PWM_1_Reg0x1e_DT2                                   ((addPWM_1_Reg0x1e & 0xFFC00) >> 10)

#define posPWM_1_Reg0x1e_DT1                                    0
#define bitPWM_1_Reg0x1e_DT1                                    0x3FF
#define set_PWM_1_Reg0x1e_DT1(val)                              addPWM_1_Reg0x1e = ((addPWM_1_Reg0x1e & (~0x3FF)) | ((val) << 0))
#define get_PWM_1_Reg0x1e_DT1                                   (addPWM_1_Reg0x1e & 0x3FF)

//addPWM_1_Reg0x1f
#define addPWM_1_Reg0x1f                                        *((volatile unsigned long *) (0x00806b00+0x1f*4))

//addPWM_1_Reg0x20
#define addPWM_1_Reg0x20                                        *((volatile unsigned long *) (0x00806b00+0x20*4))

//addPWM_1_Reg0x21
#define addPWM_1_Reg0x21                                        *((volatile unsigned long *) (0x00806b00+0x21*4))

//addPWM_1_Reg0x22
#define addPWM_1_Reg0x22                                        *((volatile unsigned long *) (0x00806b00+0x22*4))

//addPWM_1_Reg0x23
#define addPWM_1_Reg0x23                                        *((volatile unsigned long *) (0x00806b00+0x23*4))

//addPWM_1_Reg0x24
#define addPWM_1_Reg0x24                                        *((volatile unsigned long *) (0x00806b00+0x24*4))

//addPWM_1_Reg0x25
#define addPWM_1_Reg0x25                                        *((volatile unsigned long *) (0x00806b00+0x25*4))

//addPWM_1_Reg0x26
#define addPWM_1_Reg0x26                                        *((volatile unsigned long *) (0x00806b00+0x26*4))

//addPWM_1_Reg0x27
#define addPWM_1_Reg0x27                                        *((volatile unsigned long *) (0x00806b00+0x27*4))

//addPWM_1_Reg0x28
#define addPWM_1_Reg0x28                                        *((volatile unsigned long *) (0x00806b00+0x28*4))

//addPWM_1_Reg0x29
#define addPWM_1_Reg0x29                                        *((volatile unsigned long *) (0x00806b00+0x29*4))

//addPWM_1_Reg0x2a
#define addPWM_1_Reg0x2a                                        *((volatile unsigned long *) (0x00806b00+0x2a*4))

//addPWM_1_Reg0x2b
#define addPWM_1_Reg0x2b                                        *((volatile unsigned long *) (0x00806b00+0x2b*4))

//addPWM_1_Reg0x2c
#define addPWM_1_Reg0x2c                                        *((volatile unsigned long *) (0x00806b00+0x2c*4))

//addPWM_1_Reg0x2d
#define addPWM_1_Reg0x2d                                        *((volatile unsigned long *) (0x00806b00+0x2d*4))

//addPWM_1_Reg0x2e
#define addPWM_1_Reg0x2e                                        *((volatile unsigned long *) (0x00806b00+0x2e*4))

#define posPWM_1_Reg0x2e_oc3m_shad                              12
#define bitPWM_1_Reg0x2e_oc3m_shad                              0x7000
#define set_PWM_1_Reg0x2e_oc3m_shad(val)                        addPWM_1_Reg0x2e = ((addPWM_1_Reg0x2e & (~0x7000)) | ((val) << 12))
#define get_PWM_1_Reg0x2e_oc3m_shad                             ((addPWM_1_Reg0x2e & 0x7000) >> 12)

#define posPWM_1_Reg0x2e_oc2m_shad                              9
#define bitPWM_1_Reg0x2e_oc2m_shad                              0xE00
#define set_PWM_1_Reg0x2e_oc2m_shad(val)                        addPWM_1_Reg0x2e = ((addPWM_1_Reg0x2e & (~0xE00)) | ((val) << 9))
#define get_PWM_1_Reg0x2e_oc2m_shad                             ((addPWM_1_Reg0x2e & 0xE00) >> 9)

#define posPWM_1_Reg0x2e_oc1m_shad                              6
#define bitPWM_1_Reg0x2e_oc1m_shad                              0x1C0
#define set_PWM_1_Reg0x2e_oc1m_shad(val)                        addPWM_1_Reg0x2e = ((addPWM_1_Reg0x2e & (~0x1C0)) | ((val) << 6))
#define get_PWM_1_Reg0x2e_oc1m_shad                             ((addPWM_1_Reg0x2e & 0x1C0) >> 6)

#define posPWM_1_Reg0x2e_CH1e_shad                              5
#define bitPWM_1_Reg0x2e_CH1e_shad                              0x20
#define set_PWM_1_Reg0x2e_CH1e_shad(val)                        addPWM_1_Reg0x2e = ((addPWM_1_Reg0x2e & (~0x20)) | ((val) << 5))
#define setf_PWM_1_Reg0x2e_CH1e_shad                            addPWM_1_Reg0x2e |= 0x20
#define clrf_PWM_1_Reg0x2e_CH1e_shad                            addPWM_1_Reg0x2e &= ~0x20
#define get_PWM_1_Reg0x2e_CH1e_shad                             ((addPWM_1_Reg0x2e & 0x20) >> 5)

#define posPWM_1_Reg0x2e_CH2e_shad                              4
#define bitPWM_1_Reg0x2e_CH2e_shad                              0x10
#define set_PWM_1_Reg0x2e_CH2e_shad(val)                        addPWM_1_Reg0x2e = ((addPWM_1_Reg0x2e & (~0x10)) | ((val) << 4))
#define setf_PWM_1_Reg0x2e_CH2e_shad                            addPWM_1_Reg0x2e |= 0x10
#define clrf_PWM_1_Reg0x2e_CH2e_shad                            addPWM_1_Reg0x2e &= ~0x10
#define get_PWM_1_Reg0x2e_CH2e_shad                             ((addPWM_1_Reg0x2e & 0x10) >> 4)

#define posPWM_1_Reg0x2e_CH3e_shad                              3
#define bitPWM_1_Reg0x2e_CH3e_shad                              0x8
#define set_PWM_1_Reg0x2e_CH3e_shad(val)                        addPWM_1_Reg0x2e = ((addPWM_1_Reg0x2e & (~0x8)) | ((val) << 3))
#define setf_PWM_1_Reg0x2e_CH3e_shad                            addPWM_1_Reg0x2e |= 0x8
#define clrf_PWM_1_Reg0x2e_CH3e_shad                            addPWM_1_Reg0x2e &= ~0x8
#define get_PWM_1_Reg0x2e_CH3e_shad                             ((addPWM_1_Reg0x2e & 0x8) >> 3)

#define posPWM_1_Reg0x2e_CH4e_shad                              2
#define bitPWM_1_Reg0x2e_CH4e_shad                              0x4
#define set_PWM_1_Reg0x2e_CH4e_shad(val)                        addPWM_1_Reg0x2e = ((addPWM_1_Reg0x2e & (~0x4)) | ((val) << 2))
#define setf_PWM_1_Reg0x2e_CH4e_shad                            addPWM_1_Reg0x2e |= 0x4
#define clrf_PWM_1_Reg0x2e_CH4e_shad                            addPWM_1_Reg0x2e &= ~0x4
#define get_PWM_1_Reg0x2e_CH4e_shad                             ((addPWM_1_Reg0x2e & 0x4) >> 2)

#define posPWM_1_Reg0x2e_CH5e_shad                              1
#define bitPWM_1_Reg0x2e_CH5e_shad                              0x2
#define set_PWM_1_Reg0x2e_CH5e_shad(val)                        addPWM_1_Reg0x2e = ((addPWM_1_Reg0x2e & (~0x2)) | ((val) << 1))
#define setf_PWM_1_Reg0x2e_CH5e_shad                            addPWM_1_Reg0x2e |= 0x2
#define clrf_PWM_1_Reg0x2e_CH5e_shad                            addPWM_1_Reg0x2e &= ~0x2
#define get_PWM_1_Reg0x2e_CH5e_shad                             ((addPWM_1_Reg0x2e & 0x2) >> 1)

#define posPWM_1_Reg0x2e_CH6e_shad                              0
#define bitPWM_1_Reg0x2e_CH6e_shad                              0x1
#define set_PWM_1_Reg0x2e_CH6e_shad(val)                        addPWM_1_Reg0x2e = ((addPWM_1_Reg0x2e & (~0x1)) | ((val) << 0))
#define setf_PWM_1_Reg0x2e_CH6e_shad                            addPWM_1_Reg0x2e |= 0x1
#define clrf_PWM_1_Reg0x2e_CH6e_shad                            addPWM_1_Reg0x2e &= ~0x1
#define get_PWM_1_Reg0x2e_CH6e_shad                             (addPWM_1_Reg0x2e & 0x1)


//************************************************************//
//TIMER1
//************************************************************//
#define BASEADDR_TIMER1                                         0x00806600
//addTIMER1_Reg0x0
#define addTIMER1_Reg0x0                                        *((volatile unsigned long *) (0x00806600+0x0*4))

//addTIMER1_Reg0x1
#define addTIMER1_Reg0x1                                        *((volatile unsigned long *) (0x00806600+0x1*4))

//addTIMER1_Reg0x2
#define addTIMER1_Reg0x2                                        *((volatile unsigned long *) (0x00806600+0x2*4))

//addTIMER1_Reg0x3
#define addTIMER1_Reg0x3                                        *((volatile unsigned long *) (0x00806600+0x3*4))
#define posTIMER1_Reg0x3_timer0_en                              0
#define bitTIMER1_Reg0x3_timer0_en                              0x1
#define set_TIMER1_Reg0x3_timer0_en(val)                        addTIMER1_Reg0x3 = ((addTIMER1_Reg0x3 & (~0x1)) | ((val) << 0))
#define setf_TIMER1_Reg0x3_timer0_en                            addTIMER1_Reg0x3 |= 0x1
#define clrf_TIMER1_Reg0x3_timer0_en                            addTIMER1_Reg0x3 &= ~0x1
#define get_TIMER1_Reg0x3_timer0_en                             (addTIMER1_Reg0x3 & 0x1)

#define posTIMER1_Reg0x3_timer1_en                              1
#define bitTIMER1_Reg0x3_timer1_en                              0x2
#define set_TIMER1_Reg0x3_timer1_en(val)                        addTIMER1_Reg0x3 = ((addTIMER1_Reg0x3 & (~0x2)) | ((val) << 1))
#define setf_TIMER1_Reg0x3_timer1_en                            addTIMER1_Reg0x3 |= 0x2
#define clrf_TIMER1_Reg0x3_timer1_en                            addTIMER1_Reg0x3 &= ~0x2
#define get_TIMER1_Reg0x3_timer1_en                             ((addTIMER1_Reg0x3 & 0x2) >> 1)

#define posTIMER1_Reg0x3_timer2_en                              2
#define bitTIMER1_Reg0x3_timer2_en                              0x4
#define set_TIMER1_Reg0x3_timer2_en(val)                        addTIMER1_Reg0x3 = ((addTIMER1_Reg0x3 & (~0x4)) | ((val) << 2))
#define setf_TIMER1_Reg0x3_timer2_en                            addTIMER1_Reg0x3 |= 0x4
#define clrf_TIMER1_Reg0x3_timer2_en                            addTIMER1_Reg0x3 &= ~0x4
#define get_TIMER1_Reg0x3_timer2_en                             ((addTIMER1_Reg0x3 & 0x4) >> 2)

#define posTIMER1_Reg0x3_clk_div                                3
#define bitTIMER1_Reg0x3_clk_div                                0x78
#define set_TIMER1_Reg0x3_clk_div(val)                          addTIMER1_Reg0x3 = ((addTIMER1_Reg0x3 & (~0x78)) | ((val) << 3))
#define get_TIMER1_Reg0x3_clk_div                               ((addTIMER1_Reg0x3 & 0x78) >> 3)

#define posTIMER1_Reg0x3_timer0_int                             7
#define bitTIMER1_Reg0x3_timer0_int                             0x80
#define set_TIMER1_Reg0x3_timer0_int(val)                       addTIMER1_Reg0x3 = ((addTIMER1_Reg0x3 & (~0x80)) | ((val) << 7))
#define setf_TIMER1_Reg0x3_timer0_int                           addTIMER1_Reg0x3 |= 0x80
#define clrf_TIMER1_Reg0x3_timer0_int                           addTIMER1_Reg0x3 &= ~0x80
#define get_TIMER1_Reg0x3_timer0_int                            ((addTIMER1_Reg0x3 & 0x80) >> 7)

#define posTIMER1_Reg0x3_timer1_int                             8
#define bitTIMER1_Reg0x3_timer1_int                             0x100
#define set_TIMER1_Reg0x3_timer1_int(val)                       addTIMER1_Reg0x3 = ((addTIMER1_Reg0x3 & (~0x100)) | ((val) << 8))
#define setf_TIMER1_Reg0x3_timer1_int                           addTIMER1_Reg0x3 |= 0x100
#define clrf_TIMER1_Reg0x3_timer1_int                           addTIMER1_Reg0x3 &= ~0x100
#define get_TIMER1_Reg0x3_timer1_int                            ((addTIMER1_Reg0x3 & 0x100) >> 8)

#define posTIMER1_Reg0x3_timer2_int                             9
#define bitTIMER1_Reg0x3_timer2_int                             0x200
#define set_TIMER1_Reg0x3_timer2_int(val)                       addTIMER1_Reg0x3 = ((addTIMER1_Reg0x3 & (~0x200)) | ((val) << 9))
#define setf_TIMER1_Reg0x3_timer2_int                           addTIMER1_Reg0x3 |= 0x200
#define clrf_TIMER1_Reg0x3_timer2_int                           addTIMER1_Reg0x3 &= ~0x200
#define get_TIMER1_Reg0x3_timer2_int                            ((addTIMER1_Reg0x3 & 0x200) >> 9)

//addTIMER1_Reg0x4
#define addTIMER1_Reg0x4                                        *((volatile unsigned long *) (0x00806600+0x4*4))

#define posTIMER1_Reg0x4_timerl_index                           2
#define bitTIMER1_Reg0x4_timerl_index                           0xC
#define set_TIMER1_Reg0x4_timerl_index(val)                     addTIMER1_Reg0x4 = ((addTIMER1_Reg0x4 & (~0xC)) | ((val) << 2))
#define get_TIMER1_Reg0x4_timerl_index                          ((addTIMER1_Reg0x4 & 0xC) >> 2)


#define posTIMER1_Reg0x4_timerl_cnt_read                        0
#define bitTIMER1_Reg0x4_timerl_cnt_read                        0x1
#define set_TIMER1_Reg0x4_timerl_cnt_read(val)                  addTIMER1_Reg0x4 = ((addTIMER1_Reg0x4 & (~0x1)) | ((val) << 0))
#define setf_TIMER1_Reg0x4_timerl_cnt_read                      addTIMER1_Reg0x4 |= 0x1
#define clrf_TIMER1_Reg0x4_timerl_cnt_read                      addTIMER1_Reg0x4 &= ~0x1
#define get_TIMER1_Reg0x4_timerl_cnt_read                       (addTIMER1_Reg0x4 & 0x1)

//addTIMER1_Reg0x5
#define addTIMER1_Reg0x5                                        *((volatile unsigned long *) (0x00806600+0x5*4))


//************************************************************//
//PWM1
//************************************************************//
#define BASEADDR_PWM1                                           0x00806b00
//addPWM1_Reg0x0
#define addPWM1_Reg0x0                                          *((volatile unsigned long *) (0x00806b00+0x0*4))
#define posPWM1_Reg0x0_pwm0_en                                  0
#define bitPWM1_Reg0x0_pwm0_en                                  0x1
#define set_PWM1_Reg0x0_pwm0_en(val)                            addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_PWM1_Reg0x0_pwm0_en                                addPWM1_Reg0x0 |= 0x1
#define clrf_PWM1_Reg0x0_pwm0_en                                addPWM1_Reg0x0 &= ~0x1
#define get_PWM1_Reg0x0_pwm0_en                                 (addPWM1_Reg0x0 & 0x1)

#define posPWM1_Reg0x0_pwm0_int_en                              1
#define bitPWM1_Reg0x0_pwm0_int_en                              0x2
#define set_PWM1_Reg0x0_pwm0_int_en(val)                        addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x2)) | ((val) << 1))
#define setf_PWM1_Reg0x0_pwm0_int_en                            addPWM1_Reg0x0 |= 0x2
#define clrf_PWM1_Reg0x0_pwm0_int_en                            addPWM1_Reg0x0 &= ~0x2
#define get_PWM1_Reg0x0_pwm0_int_en                             ((addPWM1_Reg0x0 & 0x2) >> 1)

#define posPWM1_Reg0x0_pwm0_mode                                2
#define bitPWM1_Reg0x0_pwm0_mode                                0x1C
#define set_PWM1_Reg0x0_pwm0_mode(val)                          addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x1C)) | ((val) << 2))
#define get_PWM1_Reg0x0_pwm0_mode                               ((addPWM1_Reg0x0 & 0x1C) >> 2)

#define posPWM1_Reg0x0_pwm1_en                                  5
#define bitPWM1_Reg0x0_pwm1_en                                  0x20
#define set_PWM1_Reg0x0_pwm1_en(val)                            addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x20)) | ((val) << 5))
#define setf_PWM1_Reg0x0_pwm1_en                                addPWM1_Reg0x0 |= 0x20
#define clrf_PWM1_Reg0x0_pwm1_en                                addPWM1_Reg0x0 &= ~0x20
#define get_PWM1_Reg0x0_pwm1_en                                 ((addPWM1_Reg0x0 & 0x20) >> 5)

#define posPWM1_Reg0x0_pwm1_int_en                              6
#define bitPWM1_Reg0x0_pwm1_int_en                              0x40
#define set_PWM1_Reg0x0_pwm1_int_en(val)                        addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x40)) | ((val) << 6))
#define setf_PWM1_Reg0x0_pwm1_int_en                            addPWM1_Reg0x0 |= 0x40
#define clrf_PWM1_Reg0x0_pwm1_int_en                            addPWM1_Reg0x0 &= ~0x40
#define get_PWM1_Reg0x0_pwm1_int_en                             ((addPWM1_Reg0x0 & 0x40) >> 6)

#define posPWM1_Reg0x0_pwm1_mode                                7
#define bitPWM1_Reg0x0_pwm1_mode                                0x380
#define set_PWM1_Reg0x0_pwm1_mode(val)                          addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x380)) | ((val) << 7))
#define get_PWM1_Reg0x0_pwm1_mode                               ((addPWM1_Reg0x0 & 0x380) >> 7)

#define posPWM1_Reg0x0_pwm2_en                                  10
#define bitPWM1_Reg0x0_pwm2_en                                  0x400
#define set_PWM1_Reg0x0_pwm2_en(val)                            addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x400)) | ((val) << 10))
#define setf_PWM1_Reg0x0_pwm2_en                                addPWM1_Reg0x0 |= 0x400
#define clrf_PWM1_Reg0x0_pwm2_en                                addPWM1_Reg0x0 &= ~0x400
#define get_PWM1_Reg0x0_pwm2_en                                 ((addPWM1_Reg0x0 & 0x400) >> 10)

#define posPWM1_Reg0x0_pwm2_int_en                              11
#define bitPWM1_Reg0x0_pwm2_int_en                              0x800
#define set_PWM1_Reg0x0_pwm2_int_en(val)                        addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x800)) | ((val) << 11))
#define setf_PWM1_Reg0x0_pwm2_int_en                            addPWM1_Reg0x0 |= 0x800
#define clrf_PWM1_Reg0x0_pwm2_int_en                            addPWM1_Reg0x0 &= ~0x800
#define get_PWM1_Reg0x0_pwm2_int_en                             ((addPWM1_Reg0x0 & 0x800) >> 11)

#define posPWM1_Reg0x0_pwm2_mode                                12
#define bitPWM1_Reg0x0_pwm2_mode                                0x7000
#define set_PWM1_Reg0x0_pwm2_mode(val)                          addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x7000)) | ((val) << 12))
#define get_PWM1_Reg0x0_pwm2_mode                               ((addPWM1_Reg0x0 & 0x7000) >> 12)

#define posPWM1_Reg0x0_rfu                                      15
#define bitPWM1_Reg0x0_rfu                                      0x8000
#define set_PWM1_Reg0x0_rfu(val)                                addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x8000)) | ((val) << 15))
#define setf_PWM1_Reg0x0_rfu                                    addPWM1_Reg0x0 |= 0x8000
#define clrf_PWM1_Reg0x0_rfu                                    addPWM1_Reg0x0 &= ~0x8000
#define get_PWM1_Reg0x0_rfu                                     ((addPWM1_Reg0x0 & 0x8000) >> 15)

#define posPWM1_Reg0x0_pre_div                                  16
#define bitPWM1_Reg0x0_pre_div                                  0xF0000
#define set_PWM1_Reg0x0_pre_div(val)                            addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0xF0000)) | ((val) << 16))
#define get_PWM1_Reg0x0_pre_div                                 ((addPWM1_Reg0x0 & 0xF0000) >> 16)

#define posPWM1_Reg0x0_pwm0_cpedg_sel                           20
#define bitPWM1_Reg0x0_pwm0_cpedg_sel                           0x300000
#define set_PWM1_Reg0x0_pwm0_cpedg_sel(val)                     addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x300000)) | ((val) << 20))
#define get_PWM1_Reg0x0_pwm0_cpedg_sel                          ((addPWM1_Reg0x0 & 0x300000) >> 20)

#define posPWM1_Reg0x0_pwm1_cpedg_sel                           22
#define bitPWM1_Reg0x0_pwm1_cpedg_sel                           0xC00000
#define set_PWM1_Reg0x0_pwm1_cpedg_sel(val)                     addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0xC00000)) | ((val) << 22))
#define get_PWM1_Reg0x0_pwm1_cpedg_sel                          ((addPWM1_Reg0x0 & 0xC00000) >> 22)

#define posPWM1_Reg0x0_pwm2_cpedg_sel                           24
#define bitPWM1_Reg0x0_pwm2_cpedg_sel                           0x3000000
#define set_PWM1_Reg0x0_pwm2_cpedg_sel(val)                     addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x3000000)) | ((val) << 24))
#define get_PWM1_Reg0x0_pwm2_cpedg_sel                          ((addPWM1_Reg0x0 & 0x3000000) >> 24)

#define posPWM1_Reg0x0_pwm0_ctnu_mod                            26
#define bitPWM1_Reg0x0_pwm0_ctnu_mod                            0x4000000
#define set_PWM1_Reg0x0_pwm0_ctnu_mod(val)                      addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x4000000)) | ((val) << 26))
#define setf_PWM1_Reg0x0_pwm0_ctnu_mod                          addPWM1_Reg0x0 |= 0x4000000
#define clrf_PWM1_Reg0x0_pwm0_ctnu_mod                          addPWM1_Reg0x0 &= ~0x4000000
#define get_PWM1_Reg0x0_pwm0_ctnu_mod                           ((addPWM1_Reg0x0 & 0x4000000) >> 26)

#define posPWM1_Reg0x0_pwm1_ctnu_mod                            27
#define bitPWM1_Reg0x0_pwm1_ctnu_mod                            0x8000000
#define set_PWM1_Reg0x0_pwm1_ctnu_mod(val)                      addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x8000000)) | ((val) << 27))
#define setf_PWM1_Reg0x0_pwm1_ctnu_mod                          addPWM1_Reg0x0 |= 0x8000000
#define clrf_PWM1_Reg0x0_pwm1_ctnu_mod                          addPWM1_Reg0x0 &= ~0x8000000
#define get_PWM1_Reg0x0_pwm1_ctnu_mod                           ((addPWM1_Reg0x0 & 0x8000000) >> 27)

#define posPWM1_Reg0x0_pwm2_ctnu_mod                            28
#define bitPWM1_Reg0x0_pwm2_ctnu_mod                            0x10000000
#define set_PWM1_Reg0x0_pwm2_ctnu_mod(val)                      addPWM1_Reg0x0 = ((addPWM1_Reg0x0 & (~0x10000000)) | ((val) << 28))
#define setf_PWM1_Reg0x0_pwm2_ctnu_mod                          addPWM1_Reg0x0 |= 0x10000000
#define clrf_PWM1_Reg0x0_pwm2_ctnu_mod                          addPWM1_Reg0x0 &= ~0x10000000
#define get_PWM1_Reg0x0_pwm2_ctnu_mod                           ((addPWM1_Reg0x0 & 0x10000000) >> 28)

//addPWM1_Reg0x1
#define addPWM1_Reg0x1                                          *((volatile unsigned long *) (0x00806b00+0x1*4))
#define posPWM1_Reg0x1_pwm0_int                                 0
#define bitPWM1_Reg0x1_pwm0_int                                 0x1
#define set_PWM1_Reg0x1_pwm0_int(val)                           addPWM1_Reg0x1 = ((addPWM1_Reg0x1 & (~0x1)) | ((val) << 0))
#define setf_PWM1_Reg0x1_pwm0_int                               addPWM1_Reg0x1 |= 0x1
#define clrf_PWM1_Reg0x1_pwm0_int                               addPWM1_Reg0x1 &= ~0x1
#define get_PWM1_Reg0x1_pwm0_int                                (addPWM1_Reg0x1 & 0x1)

#define posPWM1_Reg0x1_pwm1_int                                 1
#define bitPWM1_Reg0x1_pwm1_int                                 0x2
#define set_PWM1_Reg0x1_pwm1_int(val)                           addPWM1_Reg0x1 = ((addPWM1_Reg0x1 & (~0x2)) | ((val) << 1))
#define setf_PWM1_Reg0x1_pwm1_int                               addPWM1_Reg0x1 |= 0x2
#define clrf_PWM1_Reg0x1_pwm1_int                               addPWM1_Reg0x1 &= ~0x2
#define get_PWM1_Reg0x1_pwm1_int                                ((addPWM1_Reg0x1 & 0x2) >> 1)

#define posPWM1_Reg0x1_pwm2_int                                 2
#define bitPWM1_Reg0x1_pwm2_int                                 0x4
#define set_PWM1_Reg0x1_pwm2_int(val)                           addPWM1_Reg0x1 = ((addPWM1_Reg0x1 & (~0x4)) | ((val) << 2))
#define setf_PWM1_Reg0x1_pwm2_int                               addPWM1_Reg0x1 |= 0x4
#define clrf_PWM1_Reg0x1_pwm2_int                               addPWM1_Reg0x1 &= ~0x4
#define get_PWM1_Reg0x1_pwm2_int                                ((addPWM1_Reg0x1 & 0x4) >> 2)


//addPWM1_Reg0x2
#define addPWM1_Reg0x2                                          *((volatile unsigned long *) (0x00806b00+0x2*4))

//addPWM1_Reg0x3
#define addPWM1_Reg0x3                                          *((volatile unsigned long *) (0x00806b00+0x3*4))

//addPWM1_Reg0x4
#define addPWM1_Reg0x4                                          *((volatile unsigned long *) (0x00806b00+0x4*4))

//addPWM1_Reg0x5
#define addPWM1_Reg0x5                                          *((volatile unsigned long *) (0x00806b00+0x5*4))

//addPWM1_Reg0x6
#define addPWM1_Reg0x6                                          *((volatile unsigned long *) (0x00806b00+0x6*4))

//addPWM1_Reg0x7
#define addPWM1_Reg0x7                                          *((volatile unsigned long *) (0x00806b00+0x7*4))

//addPWM1_Reg0x8
#define addPWM1_Reg0x8                                          *((volatile unsigned long *) (0x00806b00+0x8*4))

//addPWM1_Reg0x9
#define addPWM1_Reg0x9                                          *((volatile unsigned long *) (0x00806b00+0x9*4))

//addPWM1_Reg0xa
#define addPWM1_Reg0xa                                          *((volatile unsigned long *) (0x00806b00+0xa*4))

//addPWM1_Reg0xb
#define addPWM1_Reg0xb                                          *((volatile unsigned long *) (0x00806b00+0xb*4))
#define posPWM1_Reg0xb_pwm0_update                              0
#define bitPWM1_Reg0xb_pwm0_update                              0x1
#define set_PWM1_Reg0xb_pwm0_update(val)                        addPWM1_Reg0xb = ((addPWM1_Reg0xb & (~0x1)) | ((val) << 0))
#define setf_PWM1_Reg0xb_pwm0_update                            addPWM1_Reg0xb |= 0x1
#define clrf_PWM1_Reg0xb_pwm0_update                            addPWM1_Reg0xb &= ~0x1
#define get_PWM1_Reg0xb_pwm0_update                             (addPWM1_Reg0xb & 0x1)


//addPWM1_Reg0xc
#define addPWM1_Reg0xc                                          *((volatile unsigned long *) (0x00806b00+0xc*4))
#define posPWM1_Reg0xc_pwm1_update                              0
#define bitPWM1_Reg0xc_pwm1_update                              0x1
#define set_PWM1_Reg0xc_pwm1_update(val)                        addPWM1_Reg0xc = ((addPWM1_Reg0xc & (~0x1)) | ((val) << 0))
#define setf_PWM1_Reg0xc_pwm1_update                            addPWM1_Reg0xc |= 0x1
#define clrf_PWM1_Reg0xc_pwm1_update                            addPWM1_Reg0xc &= ~0x1
#define get_PWM1_Reg0xc_pwm1_update                             (addPWM1_Reg0xc & 0x1)


//addPWM1_Reg0xd
#define addPWM1_Reg0xd                                          *((volatile unsigned long *) (0x00806b00+0xd*4))
#define posPWM1_Reg0xd_pwm2_update                              0
#define bitPWM1_Reg0xd_pwm2_update                              0x1
#define set_PWM1_Reg0xd_pwm2_update(val)                        addPWM1_Reg0xd = ((addPWM1_Reg0xd & (~0x1)) | ((val) << 0))
#define setf_PWM1_Reg0xd_pwm2_update                            addPWM1_Reg0xd |= 0x1
#define clrf_PWM1_Reg0xd_pwm2_update                            addPWM1_Reg0xd &= ~0x1
#define get_PWM1_Reg0xd_pwm2_update                             (addPWM1_Reg0xd & 0x1)


//addPWM1_Reg0xe
#define addPWM1_Reg0xe                                          *((volatile unsigned long *) (0x00806b00+0xe*4))

#define posPWM1_Reg0xe_pwms_index                               1
#define bitPWM1_Reg0xe_pwms_index                               0xE
#define set_PWM1_Reg0xe_pwms_index(val)                         addPWM1_Reg0xe = ((addPWM1_Reg0xe & (~0xE)) | ((val) << 1))
#define get_PWM1_Reg0xe_pwms_index                              ((addPWM1_Reg0xe & 0xE) >> 1)

#define posPWM1_Reg0xe_pwms_cnt_read                            0
#define bitPWM1_Reg0xe_pwms_cnt_read                            0x1
#define set_PWM1_Reg0xe_pwms_cnt_read(val)                      addPWM1_Reg0xe = ((addPWM1_Reg0xe & (~0x1)) | ((val) << 0))
#define setf_PWM1_Reg0xe_pwms_cnt_read                          addPWM1_Reg0xe |= 0x1
#define clrf_PWM1_Reg0xe_pwms_cnt_read                          addPWM1_Reg0xe &= ~0x1
#define get_PWM1_Reg0xe_pwms_cnt_read                           (addPWM1_Reg0xe & 0x1)

//addPWM1_Reg0xf
#define addPWM1_Reg0xf                                          *((volatile unsigned long *) (0x00806b00+0xf*4))

#if 0
//************************************************************//
//SADC
//************************************************************//
#define BASEADDR_SADC                                           0x00806700
//addSADC_Reg0x0
#define addSADC_Reg0x0                                          *((volatile unsigned long *) (0x00806700+0x0*4))
#define posSADC_Reg0x0_ADC_MODE                                 0
#define bitSADC_Reg0x0_ADC_MODE                                 0x3
#define set_SADC_Reg0x0_ADC_MODE(val)                           addSADC_Reg0x0 = ((addSADC_Reg0x0 & (~0x3)) | ((val) << 0))
#define get_SADC_Reg0x0_ADC_MODE                                (addSADC_Reg0x0 & 0x3)

#define posSADC_Reg0x0_ADC_EN                                   2
#define bitSADC_Reg0x0_ADC_EN                                   0x4
#define set_SADC_Reg0x0_ADC_EN(val)                             addSADC_Reg0x0 = ((addSADC_Reg0x0 & (~0x4)) | ((val) << 2))
#define setf_SADC_Reg0x0_ADC_EN                                 addSADC_Reg0x0 |= 0x4
#define clrf_SADC_Reg0x0_ADC_EN                                 addSADC_Reg0x0 &= ~0x4
#define get_SADC_Reg0x0_ADC_EN                                  ((addSADC_Reg0x0 & 0x4) >> 2)

#define posSADC_Reg0x0_ADC_CHNL                                 3
#define bitSADC_Reg0x0_ADC_CHNL                                 0x78
#define set_SADC_Reg0x0_ADC_CHNL(val)                           addSADC_Reg0x0 = ((addSADC_Reg0x0 & (~0x78)) | ((val) << 3))
#define get_SADC_Reg0x0_ADC_CHNL                                ((addSADC_Reg0x0 & 0x78) >> 3)

#define posSADC_Reg0x0_adc_setting                              7
#define bitSADC_Reg0x0_adc_setting                              0x80
#define set_SADC_Reg0x0_adc_setting(val)                        addSADC_Reg0x0 = ((addSADC_Reg0x0 & (~0x80)) | ((val) << 7))
#define setf_SADC_Reg0x0_adc_setting                            addSADC_Reg0x0 |= 0x80
#define clrf_SADC_Reg0x0_adc_setting                            addSADC_Reg0x0 &= ~0x80
#define get_SADC_Reg0x0_adc_setting                             ((addSADC_Reg0x0 & 0x80) >> 7)

#define posSADC_Reg0x0_adc_int_clear                            8
#define bitSADC_Reg0x0_adc_int_clear                            0x100
#define set_SADC_Reg0x0_adc_int_clear(val)                      addSADC_Reg0x0 = ((addSADC_Reg0x0 & (~0x100)) | ((val) << 8))
#define setf_SADC_Reg0x0_adc_int_clear                          addSADC_Reg0x0 |= 0x100
#define clrf_SADC_Reg0x0_adc_int_clear                          addSADC_Reg0x0 &= ~0x100
#define get_SADC_Reg0x0_adc_int_clear                           ((addSADC_Reg0x0 & 0x100) >> 8)

#define posSADC_Reg0x0_pre_div                                  9
#define bitSADC_Reg0x0_pre_div                                  0x7E00
#define set_SADC_Reg0x0_pre_div(val)                            addSADC_Reg0x0 = ((addSADC_Reg0x0 & (~0x7E00)) | ((val) << 9))
#define get_SADC_Reg0x0_pre_div                                 ((addSADC_Reg0x0 & 0x7E00) >> 9)

#define posSADC_Reg0x0_32m_mode                                 15
#define bitSADC_Reg0x0_32m_mode                                 0x8000
#define set_SADC_Reg0x0_32m_mode(val)                           addSADC_Reg0x0 = ((addSADC_Reg0x0 & (~0x8000)) | ((val) << 15))
#define setf_SADC_Reg0x0_32m_mode                               addSADC_Reg0x0 |= 0x8000
#define clrf_SADC_Reg0x0_32m_mode                               addSADC_Reg0x0 &= ~0x8000
#define get_SADC_Reg0x0_32m_mode                                ((addSADC_Reg0x0 & 0x8000) >> 15)

#define posSADC_Reg0x0_samp_rate                                16
#define bitSADC_Reg0x0_samp_rate                                0x3F0000
#define set_SADC_Reg0x0_samp_rate(val)                          addSADC_Reg0x0 = ((addSADC_Reg0x0 & (~0x3F0000)) | ((val) << 16))
#define get_SADC_Reg0x0_samp_rate                               ((addSADC_Reg0x0 & 0x3F0000) >> 16)

#define posSADC_Reg0x0_adc_filter                               22
#define bitSADC_Reg0x0_adc_filter                               0x1FC00000
#define set_SADC_Reg0x0_adc_filter(val)                         addSADC_Reg0x0 = ((addSADC_Reg0x0 & (~0x1FC00000)) | ((val) << 22))
#define get_SADC_Reg0x0_adc_filter                              ((addSADC_Reg0x0 & 0x1FC00000) >> 22)

#define posSADC_Reg0x0_adc_busy                                 29
#define bitSADC_Reg0x0_adc_busy                                 0x20000000
#define get_SADC_Reg0x0_adc_busy                                ((addSADC_Reg0x0 & 0x20000000) >> 29)

#define posSADC_Reg0x0_fifo_empty                               30
#define bitSADC_Reg0x0_fifo_empty                               0x40000000
#define get_SADC_Reg0x0_fifo_empty                              ((addSADC_Reg0x0 & 0x40000000) >> 30)

#define posSADC_Reg0x0_fifo_full                                31
#define bitSADC_Reg0x0_fifo_full                                0x80000000
#define get_SADC_Reg0x0_fifo_full                               ((addSADC_Reg0x0 & 0x80000000) >> 31)

//addSADC_Reg0x1
#define addSADC_Reg0x1                                          *((volatile unsigned long *) (0x00806700+0x1*4))

//addSADC_Reg0x2
#define addSADC_Reg0x2                                          *((volatile unsigned long *) (0x00806700+0x2*4))
#define posSADC_Reg0x2_channel_expand                           16
#define bitSADC_Reg0x2_channel_expand                           0x10000
#define set_SADC_Reg0x2_channel_expand(val)                     addSADC_Reg0x2 = ((addSADC_Reg0x2 & (~0x10000)) | ((val) << 16))
#define setf_SADC_Reg0x2_channel_expand                         addSADC_Reg0x2 |= 0x10000
#define clrf_SADC_Reg0x2_channel_expand                         addSADC_Reg0x2 &= ~0x10000
#define get_SADC_Reg0x2_channel_expand                          ((addSADC_Reg0x2 & 0x10000) >> 16)

#define posSADC_Reg0x2_steady_ctrl                              5
#define bitSADC_Reg0x2_steady_ctrl                              0xE0
#define set_SADC_Reg0x2_steady_ctrl(val)                        addSADC_Reg0x2 = ((addSADC_Reg0x2 & (~0xE0)) | ((val) << 5))
#define get_SADC_Reg0x2_steady_ctrl                             ((addSADC_Reg0x2 & 0xE0) >> 5)

#define posSADC_Reg0x2_Almost_cfg                               0
#define bitSADC_Reg0x2_Almost_cfg                               0x1F
#define set_SADC_Reg0x2_Almost_cfg(val)                         addSADC_Reg0x2 = ((addSADC_Reg0x2 & (~0x1F)) | ((val) << 0))
#define get_SADC_Reg0x2_Almost_cfg                              (addSADC_Reg0x2 & 0x1F)

//addSADC_Reg0x3
#define addSADC_Reg0x3                                          *((volatile unsigned long *) (0x00806700+0x3*4))
#define posSADC_Reg0x3_over_flow                                3
#define bitSADC_Reg0x3_over_flow                                0x8
#define get_SADC_Reg0x3_over_flow                               ((addSADC_Reg0x3 & 0x8) >> 3)

#define posSADC_Reg0x3_sat_enable                               2
#define bitSADC_Reg0x3_sat_enable                               0x4
#define set_SADC_Reg0x3_sat_enable(val)                         addSADC_Reg0x3 = ((addSADC_Reg0x3 & (~0x4)) | ((val) << 2))
#define setf_SADC_Reg0x3_sat_enable                             addSADC_Reg0x3 |= 0x4
#define clrf_SADC_Reg0x3_sat_enable                             addSADC_Reg0x3 &= ~0x4
#define get_SADC_Reg0x3_sat_enable                              ((addSADC_Reg0x3 & 0x4) >> 2)

#define posSADC_Reg0x3_sat_ctrl                                 0
#define bitSADC_Reg0x3_sat_ctrl                                 0x3
#define set_SADC_Reg0x3_sat_ctrl(val)                           addSADC_Reg0x3 = ((addSADC_Reg0x3 & (~0x3)) | ((val) << 0))
#define get_SADC_Reg0x3_sat_ctrl                                (addSADC_Reg0x3 & 0x3)

//addSADC_Reg0x4
#define addSADC_Reg0x4                                          *((volatile unsigned long *) (0x00806700+0x4*4))
#define posSADC_Reg0x4_ADC_DATA_16                              0
#define bitSADC_Reg0x4_ADC_DATA_16                              0xFFFF
#define get_SADC_Reg0x4_ADC_DATA_16                             (addSADC_Reg0x4 & 0xFFFF)
#endif

#if 1
//************************************************************//
//SADC
//************************************************************//
#define BASEADDR_SADC                                           0x00806700
//************************************************************//
//SDMADC
//************************************************************//
#define BASEADDR_SDMADC                                         0x00806700
//addSDMADC_Reg0x0
#define addSDMADC_Reg0x0                                        *((volatile unsigned long *) (0x00806700+0x0*4))

//addSDMADC_Reg0x1
#define addSDMADC_Reg0x1                                        *((volatile unsigned long *) (0x00806700+0x1*4))

//addSDMADC_Reg0x2
#define addSDMADC_Reg0x2                                        *((volatile unsigned long *) (0x00806700+0x2*4))
#define posSDMADC_Reg0x2_soft_rst                               0
#define bitSDMADC_Reg0x2_soft_rst                               0x1
#define set_SDMADC_Reg0x2_soft_rst(val)                         addSDMADC_Reg0x2 = ((addSDMADC_Reg0x2 & (~0x1)) | ((val) << 0))
#define setf_SDMADC_Reg0x2_soft_rst                             addSDMADC_Reg0x2 |= 0x1
#define clrf_SDMADC_Reg0x2_soft_rst                             addSDMADC_Reg0x2 &= ~0x1
#define get_SDMADC_Reg0x2_soft_rst                              (addSDMADC_Reg0x2 & 0x1)

#define posSDMADC_Reg0x2_bypass_ckg                             1
#define bitSDMADC_Reg0x2_bypass_ckg                             0x2
#define set_SDMADC_Reg0x2_bypass_ckg(val)                       addSDMADC_Reg0x2 = ((addSDMADC_Reg0x2 & (~0x2)) | ((val) << 1))
#define setf_SDMADC_Reg0x2_bypass_ckg                           addSDMADC_Reg0x2 |= 0x2
#define clrf_SDMADC_Reg0x2_bypass_ckg                           addSDMADC_Reg0x2 &= ~0x2
#define get_SDMADC_Reg0x2_bypass_ckg                            ((addSDMADC_Reg0x2 & 0x2) >> 1)

//addSDMADC_Reg0x3
#define addSDMADC_Reg0x3                                        *((volatile unsigned long *) (0x00806700+0x3*4))

//addSDMADC_Reg0x4
#define addSDMADC_Reg0x4                                        *((volatile unsigned long *) (0x00806700+0x4*4))
#define posSDMADC_Reg0x4_Sample_Enable                          0
#define bitSDMADC_Reg0x4_Sample_Enable                          0x1
#define set_SDMADC_Reg0x4_Sample_Enable(val)                    addSDMADC_Reg0x4 = ((addSDMADC_Reg0x4 & (~0x1)) | ((val) << 0))
#define setf_SDMADC_Reg0x4_Sample_Enable                        addSDMADC_Reg0x4 |= 0x1
#define clrf_SDMADC_Reg0x4_Sample_Enable                        addSDMADC_Reg0x4 &= ~0x1
#define get_SDMADC_Reg0x4_Sample_Enable                         (addSDMADC_Reg0x4 & 0x1)

//addSDMADC_Reg0x5
#define addSDMADC_Reg0x5                                        *((volatile unsigned long *) (0x00806700+0x5*4))
#define posSDMADC_Reg0x5_Sample_Mode                            0
#define bitSDMADC_Reg0x5_Sample_Mode                            0x1
#define set_SDMADC_Reg0x5_Sample_Mode(val)                      addSDMADC_Reg0x5 = ((addSDMADC_Reg0x5 & (~0x1)) | ((val) << 0))
#define setf_SDMADC_Reg0x5_Sample_Mode                          addSDMADC_Reg0x5 |= 0x1
#define clrf_SDMADC_Reg0x5_Sample_Mode                          addSDMADC_Reg0x5 &= ~0x1
#define get_SDMADC_Reg0x5_Sample_Mode                           (addSDMADC_Reg0x5 & 0x1)

#define posSDMADC_Reg0x5_Sample_Numb                            1
#define bitSDMADC_Reg0x5_Sample_Numb                            0x6
#define set_SDMADC_Reg0x5_Sample_Numb(val)                      addSDMADC_Reg0x5 = ((addSDMADC_Reg0x5 & (~0x6)) | ((val) << 1))
#define get_SDMADC_Reg0x5_Sample_Numb                           ((addSDMADC_Reg0x5 & 0x6) >> 1)

#define posSDMADC_Reg0x5_Sample_Chsel                           3
#define bitSDMADC_Reg0x5_Sample_Chsel                           0x78
#define set_SDMADC_Reg0x5_Sample_Chsel(val)                     addSDMADC_Reg0x5 = ((addSDMADC_Reg0x5 & (~0x78)) | ((val) << 3))
#define get_SDMADC_Reg0x5_Sample_Chsel                          ((addSDMADC_Reg0x5 & 0x78) >> 3)

#define posSDMADC_Reg0x5_Cic2_Bypass                            7
#define bitSDMADC_Reg0x5_Cic2_Bypass                            0x80
#define set_SDMADC_Reg0x5_Cic2_Bypass(val)                      addSDMADC_Reg0x5 = ((addSDMADC_Reg0x5 & (~0x80)) | ((val) << 7))
#define setf_SDMADC_Reg0x5_Cic2_Bypass                          addSDMADC_Reg0x5 |= 0x80
#define clrf_SDMADC_Reg0x5_Cic2_Bypass                          addSDMADC_Reg0x5 &= ~0x80
#define get_SDMADC_Reg0x5_Cic2_Bypass                           ((addSDMADC_Reg0x5 & 0x80) >> 7)

#define posSDMADC_Reg0x5_Comp_Bypass                            8
#define bitSDMADC_Reg0x5_Comp_Bypass                            0x100
#define set_SDMADC_Reg0x5_Comp_Bypass(val)                      addSDMADC_Reg0x5 = ((addSDMADC_Reg0x5 & (~0x100)) | ((val) << 8))
#define setf_SDMADC_Reg0x5_Comp_Bypass                          addSDMADC_Reg0x5 |= 0x100
#define clrf_SDMADC_Reg0x5_Comp_Bypass                          addSDMADC_Reg0x5 &= ~0x100
#define get_SDMADC_Reg0x5_Comp_Bypass                           ((addSDMADC_Reg0x5 & 0x100) >> 8)

#define posSDMADC_Reg0x5_Cic2_Gains                             9
#define bitSDMADC_Reg0x5_Cic2_Gains                             0x7E00
#define set_SDMADC_Reg0x5_Cic2_Gains(val)                       addSDMADC_Reg0x5 = ((addSDMADC_Reg0x5 & (~0x7E00)) | ((val) << 9))
#define get_SDMADC_Reg0x5_Cic2_Gains                            ((addSDMADC_Reg0x5 & 0x7E00) >> 9)

#define posSDMADC_Reg0x5_Intr_Enable                            15
#define bitSDMADC_Reg0x5_Intr_Enable                            0xF8000
#define set_SDMADC_Reg0x5_Intr_Enable(val)                      addSDMADC_Reg0x5 = ((addSDMADC_Reg0x5 & (~0xF8000)) | ((val) << 15))
#define get_SDMADC_Reg0x5_Intr_Enable                           ((addSDMADC_Reg0x5 & 0xF8000) >> 15)

//addSDMADC_Reg0x6
#define addSDMADC_Reg0x6                                        *((volatile unsigned long *) (0x00806700+0x6*4))
#define posSDMADC_Reg0x6_Cali_Offset                            0
#define bitSDMADC_Reg0x6_Cali_Offset                            0xFFFF
#define set_SDMADC_Reg0x6_Cali_Offset(val)                      addSDMADC_Reg0x6 = ((addSDMADC_Reg0x6 & (~0xFFFF)) | ((val) << 0))
#define get_SDMADC_Reg0x6_Cali_Offset                           (addSDMADC_Reg0x6 & 0xFFFF)

#define posSDMADC_Reg0x6_Cali_Gain                              16
#define bitSDMADC_Reg0x6_Cali_Gain                              0x1FFF0000
#define set_SDMADC_Reg0x6_Cali_Gain(val)                        addSDMADC_Reg0x6 = ((addSDMADC_Reg0x6 & (~0x1FFF0000)) | ((val) << 16))
#define get_SDMADC_Reg0x6_Cali_Gain                             ((addSDMADC_Reg0x6 & 0x1FFF0000) >> 16)

//addSDMADC_Reg0x7
#define addSDMADC_Reg0x7                                        *((volatile unsigned long *) (0x00806700+0x7*4))
#define posSDMADC_Reg0x7_Sadc_Status                            0
#define bitSDMADC_Reg0x7_Sadc_Status                            0x1F
#define get_SDMADC_Reg0x7_Sadc_Status                           (addSDMADC_Reg0x7 & 0x1F)

//addSDMADC_Reg0x8
#define SDMADC_REG8_ADDR                                        (0x00806700+0x8*4))
#define addSDMADC_Reg0x8                                        *((volatile unsigned long *) (0x00806700+0x8*4))
#define posSDMADC_Reg0x8_Fifo_Data                              0
#define bitSDMADC_Reg0x8_Fifo_Data                              0xFFFF
#define get_SDMADC_Reg0x8_Fifo_Data                             (addSDMADC_Reg0x8 & 0xFFFF)

#endif

//************************************************************//
//I2S0
//************************************************************//
#define BASEADDR_I2S0                                           0x00806800
//addI2S0_Reg0x0
#define addI2S0_Reg0x0                                          *((volatile unsigned long *) (0x00806800+0x0*4))
#define posI2S0_Reg0x0_I2SPCMEN                                 31
#define bitI2S0_Reg0x0_I2SPCMEN                                 0x80000000
#define set_I2S0_Reg0x0_I2SPCMEN(val)                           addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0x80000000)) | ((val) << 31))
#define setf_I2S0_Reg0x0_I2SPCMEN                               addI2S0_Reg0x0 |= 0x80000000
#define clrf_I2S0_Reg0x0_I2SPCMEN                               addI2S0_Reg0x0 &= ~0x80000000
#define get_I2S0_Reg0x0_I2SPCMEN                                ((addI2S0_Reg0x0 & 0x80000000) >> 31)

#define posI2S0_Reg0x0_MSTEN                                    30
#define bitI2S0_Reg0x0_MSTEN                                    0x40000000
#define set_I2S0_Reg0x0_MSTEN(val)                              addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0x40000000)) | ((val) << 30))
#define setf_I2S0_Reg0x0_MSTEN                                  addI2S0_Reg0x0 |= 0x40000000
#define clrf_I2S0_Reg0x0_MSTEN                                  addI2S0_Reg0x0 &= ~0x40000000
#define get_I2S0_Reg0x0_MSTEN                                   ((addI2S0_Reg0x0 & 0x40000000) >> 30)

#define posI2S0_Reg0x0_MODESEL                                  27
#define bitI2S0_Reg0x0_MODESEL                                  0x38000000
#define set_I2S0_Reg0x0_MODESEL(val)                            addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0x38000000)) | ((val) << 27))
#define get_I2S0_Reg0x0_MODESEL                                 ((addI2S0_Reg0x0 & 0x38000000) >> 27)

#define posI2S0_Reg0x0_LRCKRP                                   26
#define bitI2S0_Reg0x0_LRCKRP                                   0x4000000
#define set_I2S0_Reg0x0_LRCKRP(val)                             addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0x4000000)) | ((val) << 26))
#define setf_I2S0_Reg0x0_LRCKRP                                 addI2S0_Reg0x0 |= 0x4000000
#define clrf_I2S0_Reg0x0_LRCKRP                                 addI2S0_Reg0x0 &= ~0x4000000
#define get_I2S0_Reg0x0_LRCKRP                                  ((addI2S0_Reg0x0 & 0x4000000) >> 26)

#define posI2S0_Reg0x0_SCLKINV                                  25
#define bitI2S0_Reg0x0_SCLKINV                                  0x2000000
#define set_I2S0_Reg0x0_SCLKINV(val)                            addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0x2000000)) | ((val) << 25))
#define setf_I2S0_Reg0x0_SCLKINV                                addI2S0_Reg0x0 |= 0x2000000
#define clrf_I2S0_Reg0x0_SCLKINV                                addI2S0_Reg0x0 &= ~0x2000000
#define get_I2S0_Reg0x0_SCLKINV                                 ((addI2S0_Reg0x0 & 0x2000000) >> 25)

#define posI2S0_Reg0x0_LSBFIRST                                 24
#define bitI2S0_Reg0x0_LSBFIRST                                 0x1000000
#define set_I2S0_Reg0x0_LSBFIRST(val)                           addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0x1000000)) | ((val) << 24))
#define setf_I2S0_Reg0x0_LSBFIRST                               addI2S0_Reg0x0 |= 0x1000000
#define clrf_I2S0_Reg0x0_LSBFIRST                               addI2S0_Reg0x0 &= ~0x1000000
#define get_I2S0_Reg0x0_LSBFIRST                                ((addI2S0_Reg0x0 & 0x1000000) >> 24)

#define posI2S0_Reg0x0_SYNCLEN                                  21
#define bitI2S0_Reg0x0_SYNCLEN                                  0xE00000
#define set_I2S0_Reg0x0_SYNCLEN(val)                            addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0xE00000)) | ((val) << 21))
#define get_I2S0_Reg0x0_SYNCLEN                                 ((addI2S0_Reg0x0 & 0xE00000) >> 21)

#define posI2S0_Reg0x0_DATALEN                                  16
#define bitI2S0_Reg0x0_DATALEN                                  0x1F0000
#define set_I2S0_Reg0x0_DATALEN(val)                            addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0x1F0000)) | ((val) << 16))
#define get_I2S0_Reg0x0_DATALEN                                 ((addI2S0_Reg0x0 & 0x1F0000) >> 16)

#define posI2S0_Reg0x0_PCM_DLEN                                 13
#define bitI2S0_Reg0x0_PCM_DLEN                                 0xE000
#define set_I2S0_Reg0x0_PCM_DLEN(val)                           addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0xE000)) | ((val) << 13))
#define get_I2S0_Reg0x0_PCM_DLEN                                ((addI2S0_Reg0x0 & 0xE000) >> 13)

#define posI2S0_Reg0x0_SMPRATIO                                 8
#define bitI2S0_Reg0x0_SMPRATIO                                 0x1F00
#define set_I2S0_Reg0x0_SMPRATIO(val)                           addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0x1F00)) | ((val) << 8))
#define get_I2S0_Reg0x0_SMPRATIO                                ((addI2S0_Reg0x0 & 0x1F00) >> 8)

#define posI2S0_Reg0x0_BITRATIO                                 0
#define bitI2S0_Reg0x0_BITRATIO                                 0xFF
#define set_I2S0_Reg0x0_BITRATIO(val)                           addI2S0_Reg0x0 = ((addI2S0_Reg0x0 & (~0xFF)) | ((val) << 0))
#define get_I2S0_Reg0x0_BITRATIO                                (addI2S0_Reg0x0 & 0xFF)

//addI2S0_Reg0x1
#define addI2S0_Reg0x1                                          *((volatile unsigned long *) (0x00806800+0x1*4))

#define posI2S0_Reg0x1_PARALLEL_EN                              17
#define bitI2S0_Reg0x1_PARALLEL_EN                              0x20000
#define set_I2S0_Reg0x1_PARALLEL_EN(val)                        addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0x20000)) | ((val) << 17))
#define setf_I2S0_Reg0x1_PARALLEL_EN                            addI2S0_Reg0x1 |= 0x20000
#define clrf_I2S0_Reg0x1_PARALLEL_EN                            addI2S0_Reg0x1 &= ~0x20000
#define get_I2S0_Reg0x1_PARALLEL_EN                             ((addI2S0_Reg0x1 & 0x20000) >> 17)

#define posI2S0_Reg0x1_LRCOM_STORE                              16
#define bitI2S0_Reg0x1_LRCOM_STORE                              0x10000
#define set_I2S0_Reg0x1_LRCOM_STORE(val)                        addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0x10000)) | ((val) << 16))
#define setf_I2S0_Reg0x1_LRCOM_STORE                            addI2S0_Reg0x1 |= 0x10000
#define clrf_I2S0_Reg0x1_LRCOM_STORE                            addI2S0_Reg0x1 &= ~0x10000
#define get_I2S0_Reg0x1_LRCOM_STORE                             ((addI2S0_Reg0x1 & 0x10000) >> 16)

#define posI2S0_Reg0x1_BITRATIO_H4B                             12
#define bitI2S0_Reg0x1_BITRATIO_H4B                             0xF000
#define set_I2S0_Reg0x1_BITRATIO_H4B(val)                       addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0xF000)) | ((val) << 12))
#define get_I2S0_Reg0x1_BITRATIO_H4B                            ((addI2S0_Reg0x1 & 0xF000) >> 12)

#define posI2S0_Reg0x1_SMPRATIO_H2B                             10
#define bitI2S0_Reg0x1_SMPRATIO_H2B                             0xC00
#define set_I2S0_Reg0x1_SMPRATIO_H2B(val)                       addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0xC00)) | ((val) << 10))
#define get_I2S0_Reg0x1_SMPRATIO_H2B                            ((addI2S0_Reg0x1 & 0xC00) >> 10)

#define posI2S0_Reg0x1_RXFIFO_CLR                               9
#define bitI2S0_Reg0x1_RXFIFO_CLR                               0x200
#define set_I2S0_Reg0x1_RXFIFO_CLR(val)                         addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0x200)) | ((val) << 9))
#define setf_I2S0_Reg0x1_RXFIFO_CLR                             addI2S0_Reg0x1 |= 0x200
#define clrf_I2S0_Reg0x1_RXFIFO_CLR                             addI2S0_Reg0x1 &= ~0x200
#define get_I2S0_Reg0x1_RXFIFO_CLR                              ((addI2S0_Reg0x1 & 0x200) >> 9)

#define posI2S0_Reg0x1_TXFIFO_CLR                               8
#define bitI2S0_Reg0x1_TXFIFO_CLR                               0x100
#define set_I2S0_Reg0x1_TXFIFO_CLR(val)                         addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0x100)) | ((val) << 8))
#define setf_I2S0_Reg0x1_TXFIFO_CLR                             addI2S0_Reg0x1 |= 0x100
#define clrf_I2S0_Reg0x1_TXFIFO_CLR                             addI2S0_Reg0x1 &= ~0x100
#define get_I2S0_Reg0x1_TXFIFO_CLR                              ((addI2S0_Reg0x1 & 0x100) >> 8)

#define posI2S0_Reg0x1_TXINT_LEVEL                              6
#define bitI2S0_Reg0x1_TXINT_LEVEL                              0xC0
#define set_I2S0_Reg0x1_TXINT_LEVEL(val)                        addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0xC0)) | ((val) << 6))
#define get_I2S0_Reg0x1_TXINT_LEVEL                             ((addI2S0_Reg0x1 & 0xC0) >> 6)

#define posI2S0_Reg0x1_RXINT_LEVEL                              4
#define bitI2S0_Reg0x1_RXINT_LEVEL                              0x30
#define set_I2S0_Reg0x1_RXINT_LEVEL(val)                        addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0x30)) | ((val) << 4))
#define get_I2S0_Reg0x1_RXINT_LEVEL                             ((addI2S0_Reg0x1 & 0x30) >> 4)

#define posI2S0_Reg0x1_TXUDF_EN                                 3
#define bitI2S0_Reg0x1_TXUDF_EN                                 0x8
#define set_I2S0_Reg0x1_TXUDF_EN(val)                           addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0x8)) | ((val) << 3))
#define setf_I2S0_Reg0x1_TXUDF_EN                               addI2S0_Reg0x1 |= 0x8
#define clrf_I2S0_Reg0x1_TXUDF_EN                               addI2S0_Reg0x1 &= ~0x8
#define get_I2S0_Reg0x1_TXUDF_EN                                ((addI2S0_Reg0x1 & 0x8) >> 3)

#define posI2S0_Reg0x1_RXOVF_EN                                 2
#define bitI2S0_Reg0x1_RXOVF_EN                                 0x4
#define set_I2S0_Reg0x1_RXOVF_EN(val)                           addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0x4)) | ((val) << 2))
#define setf_I2S0_Reg0x1_RXOVF_EN                               addI2S0_Reg0x1 |= 0x4
#define clrf_I2S0_Reg0x1_RXOVF_EN                               addI2S0_Reg0x1 &= ~0x4
#define get_I2S0_Reg0x1_RXOVF_EN                                ((addI2S0_Reg0x1 & 0x4) >> 2)

#define posI2S0_Reg0x1_TXINT_EN                                 1
#define bitI2S0_Reg0x1_TXINT_EN                                 0x2
#define set_I2S0_Reg0x1_TXINT_EN(val)                           addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0x2)) | ((val) << 1))
#define setf_I2S0_Reg0x1_TXINT_EN                               addI2S0_Reg0x1 |= 0x2
#define clrf_I2S0_Reg0x1_TXINT_EN                               addI2S0_Reg0x1 &= ~0x2
#define get_I2S0_Reg0x1_TXINT_EN                                ((addI2S0_Reg0x1 & 0x2) >> 1)

#define posI2S0_Reg0x1_RXINT_EN                                 0
#define bitI2S0_Reg0x1_RXINT_EN                                 0x1
#define set_I2S0_Reg0x1_RXINT_EN(val)                           addI2S0_Reg0x1 = ((addI2S0_Reg0x1 & (~0x1)) | ((val) << 0))
#define setf_I2S0_Reg0x1_RXINT_EN                               addI2S0_Reg0x1 |= 0x1
#define clrf_I2S0_Reg0x1_RXINT_EN                               addI2S0_Reg0x1 &= ~0x1
#define get_I2S0_Reg0x1_RXINT_EN                                (addI2S0_Reg0x1 & 0x1)

//addI2S0_Reg0x2
#define addI2S0_Reg0x2                                          *((volatile unsigned long *) (0x00806800+0x2*4))

#define posI2S0_Reg0x2_TXFIFO_WR_READY                          5
#define bitI2S0_Reg0x2_TXFIFO_WR_READY                          0x20
#define get_I2S0_Reg0x2_TXFIFO_WR_READY                         ((addI2S0_Reg0x2 & 0x20) >> 5)

#define posI2S0_Reg0x2_RXFIFO_RD_READY                          4
#define bitI2S0_Reg0x2_RXFIFO_RD_READY                          0x10
#define get_I2S0_Reg0x2_RXFIFO_RD_READY                         ((addI2S0_Reg0x2 & 0x10) >> 4)

#define posI2S0_Reg0x2_TXUDF                                    3
#define bitI2S0_Reg0x2_TXUDF                                    0x8
#define set_I2S0_Reg0x2_TXUDF(val)                              addI2S0_Reg0x2 = ((addI2S0_Reg0x2 & (~0x8)) | ((val) << 3))
#define setf_I2S0_Reg0x2_TXUDF                                  addI2S0_Reg0x2 |= 0x8
#define clrf_I2S0_Reg0x2_TXUDF                                  addI2S0_Reg0x2 &= ~0x8
#define get_I2S0_Reg0x2_TXUDF                                   ((addI2S0_Reg0x2 & 0x8) >> 3)

#define posI2S0_Reg0x2_RXOVF                                    2
#define bitI2S0_Reg0x2_RXOVF                                    0x4
#define set_I2S0_Reg0x2_RXOVF(val)                              addI2S0_Reg0x2 = ((addI2S0_Reg0x2 & (~0x4)) | ((val) << 2))
#define setf_I2S0_Reg0x2_RXOVF                                  addI2S0_Reg0x2 |= 0x4
#define clrf_I2S0_Reg0x2_RXOVF                                  addI2S0_Reg0x2 &= ~0x4
#define get_I2S0_Reg0x2_RXOVF                                   ((addI2S0_Reg0x2 & 0x4) >> 2)

#define posI2S0_Reg0x2_TXINT                                    1
#define bitI2S0_Reg0x2_TXINT                                    0x2
#define get_I2S0_Reg0x2_TXINT                                   ((addI2S0_Reg0x2 & 0x2) >> 1)

#define posI2S0_Reg0x2_RXINT                                    0
#define bitI2S0_Reg0x2_RXINT                                    0x1
#define get_I2S0_Reg0x2_RXINT                                   (addI2S0_Reg0x2 & 0x1)

//addI2S0_Reg0x3
#define addI2S0_Reg0x3                                          *((volatile unsigned long *) (0x00806800+0x3*4))

//addI2S0_Reg0x4
#define addI2S0_Reg0x4                                          *((volatile unsigned long *) (0x00806800+0x4*4))

#define posI2S0_Reg0x4_TX4UDF_EN                                11
#define bitI2S0_Reg0x4_TX4UDF_EN                                0x800
#define set_I2S0_Reg0x4_TX4UDF_EN(val)                          addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x800)) | ((val) << 11))
#define setf_I2S0_Reg0x4_TX4UDF_EN                              addI2S0_Reg0x4 |= 0x800
#define clrf_I2S0_Reg0x4_TX4UDF_EN                              addI2S0_Reg0x4 &= ~0x800
#define get_I2S0_Reg0x4_TX4UDF_EN                               ((addI2S0_Reg0x4 & 0x800) >> 11)

#define posI2S0_Reg0x4_RX4OVF_EN                                10
#define bitI2S0_Reg0x4_RX4OVF_EN                                0x400
#define set_I2S0_Reg0x4_RX4OVF_EN(val)                          addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x400)) | ((val) << 10))
#define setf_I2S0_Reg0x4_RX4OVF_EN                              addI2S0_Reg0x4 |= 0x400
#define clrf_I2S0_Reg0x4_RX4OVF_EN                              addI2S0_Reg0x4 &= ~0x400
#define get_I2S0_Reg0x4_RX4OVF_EN                               ((addI2S0_Reg0x4 & 0x400) >> 10)

#define posI2S0_Reg0x4_TX4NT_EN                                 9
#define bitI2S0_Reg0x4_TX4NT_EN                                 0x200
#define set_I2S0_Reg0x4_TX4NT_EN(val)                           addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x200)) | ((val) << 9))
#define setf_I2S0_Reg0x4_TX4NT_EN                               addI2S0_Reg0x4 |= 0x200
#define clrf_I2S0_Reg0x4_TX4NT_EN                               addI2S0_Reg0x4 &= ~0x200
#define get_I2S0_Reg0x4_TX4NT_EN                                ((addI2S0_Reg0x4 & 0x200) >> 9)

#define posI2S0_Reg0x4_RX4INT_EN                                8
#define bitI2S0_Reg0x4_RX4INT_EN                                0x100
#define set_I2S0_Reg0x4_RX4INT_EN(val)                          addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x100)) | ((val) << 8))
#define setf_I2S0_Reg0x4_RX4INT_EN                              addI2S0_Reg0x4 |= 0x100
#define clrf_I2S0_Reg0x4_RX4INT_EN                              addI2S0_Reg0x4 &= ~0x100
#define get_I2S0_Reg0x4_RX4INT_EN                               ((addI2S0_Reg0x4 & 0x100) >> 8)

#define posI2S0_Reg0x4_TX3UDF_EN                                7
#define bitI2S0_Reg0x4_TX3UDF_EN                                0x80
#define set_I2S0_Reg0x4_TX3UDF_EN(val)                          addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x80)) | ((val) << 7))
#define setf_I2S0_Reg0x4_TX3UDF_EN                              addI2S0_Reg0x4 |= 0x80
#define clrf_I2S0_Reg0x4_TX3UDF_EN                              addI2S0_Reg0x4 &= ~0x80
#define get_I2S0_Reg0x4_TX3UDF_EN                               ((addI2S0_Reg0x4 & 0x80) >> 7)

#define posI2S0_Reg0x4_RX3OVF_EN                                6
#define bitI2S0_Reg0x4_RX3OVF_EN                                0x40
#define set_I2S0_Reg0x4_RX3OVF_EN(val)                          addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x40)) | ((val) << 6))
#define setf_I2S0_Reg0x4_RX3OVF_EN                              addI2S0_Reg0x4 |= 0x40
#define clrf_I2S0_Reg0x4_RX3OVF_EN                              addI2S0_Reg0x4 &= ~0x40
#define get_I2S0_Reg0x4_RX3OVF_EN                               ((addI2S0_Reg0x4 & 0x40) >> 6)

#define posI2S0_Reg0x4_TX3NT_EN                                 5
#define bitI2S0_Reg0x4_TX3NT_EN                                 0x20
#define set_I2S0_Reg0x4_TX3NT_EN(val)                           addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x20)) | ((val) << 5))
#define setf_I2S0_Reg0x4_TX3NT_EN                               addI2S0_Reg0x4 |= 0x20
#define clrf_I2S0_Reg0x4_TX3NT_EN                               addI2S0_Reg0x4 &= ~0x20
#define get_I2S0_Reg0x4_TX3NT_EN                                ((addI2S0_Reg0x4 & 0x20) >> 5)

#define posI2S0_Reg0x4_RX3INT_EN                                4
#define bitI2S0_Reg0x4_RX3INT_EN                                0x10
#define set_I2S0_Reg0x4_RX3INT_EN(val)                          addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x10)) | ((val) << 4))
#define setf_I2S0_Reg0x4_RX3INT_EN                              addI2S0_Reg0x4 |= 0x10
#define clrf_I2S0_Reg0x4_RX3INT_EN                              addI2S0_Reg0x4 &= ~0x10
#define get_I2S0_Reg0x4_RX3INT_EN                               ((addI2S0_Reg0x4 & 0x10) >> 4)

#define posI2S0_Reg0x4_TX2UDF_EN                                3
#define bitI2S0_Reg0x4_TX2UDF_EN                                0x8
#define set_I2S0_Reg0x4_TX2UDF_EN(val)                          addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x8)) | ((val) << 3))
#define setf_I2S0_Reg0x4_TX2UDF_EN                              addI2S0_Reg0x4 |= 0x8
#define clrf_I2S0_Reg0x4_TX2UDF_EN                              addI2S0_Reg0x4 &= ~0x8
#define get_I2S0_Reg0x4_TX2UDF_EN                               ((addI2S0_Reg0x4 & 0x8) >> 3)

#define posI2S0_Reg0x4_RX2OVF_EN                                2
#define bitI2S0_Reg0x4_RX2OVF_EN                                0x4
#define set_I2S0_Reg0x4_RX2OVF_EN(val)                          addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x4)) | ((val) << 2))
#define setf_I2S0_Reg0x4_RX2OVF_EN                              addI2S0_Reg0x4 |= 0x4
#define clrf_I2S0_Reg0x4_RX2OVF_EN                              addI2S0_Reg0x4 &= ~0x4
#define get_I2S0_Reg0x4_RX2OVF_EN                               ((addI2S0_Reg0x4 & 0x4) >> 2)

#define posI2S0_Reg0x4_TX2INT_EN                                1
#define bitI2S0_Reg0x4_TX2INT_EN                                0x2
#define set_I2S0_Reg0x4_TX2INT_EN(val)                          addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x2)) | ((val) << 1))
#define setf_I2S0_Reg0x4_TX2INT_EN                              addI2S0_Reg0x4 |= 0x2
#define clrf_I2S0_Reg0x4_TX2INT_EN                              addI2S0_Reg0x4 &= ~0x2
#define get_I2S0_Reg0x4_TX2INT_EN                               ((addI2S0_Reg0x4 & 0x2) >> 1)

#define posI2S0_Reg0x4_RX2INT_EN                                0
#define bitI2S0_Reg0x4_RX2INT_EN                                0x1
#define set_I2S0_Reg0x4_RX2INT_EN(val)                          addI2S0_Reg0x4 = ((addI2S0_Reg0x4 & (~0x1)) | ((val) << 0))
#define setf_I2S0_Reg0x4_RX2INT_EN                              addI2S0_Reg0x4 |= 0x1
#define clrf_I2S0_Reg0x4_RX2INT_EN                              addI2S0_Reg0x4 &= ~0x1
#define get_I2S0_Reg0x4_RX2INT_EN                               (addI2S0_Reg0x4 & 0x1)

//addI2S0_Reg0x5
#define addI2S0_Reg0x5                                          *((volatile unsigned long *) (0x00806800+0x5*4))

#define posI2S0_Reg0x5_TX4UDF                                   11
#define bitI2S0_Reg0x5_TX4UDF                                   0x800
#define set_I2S0_Reg0x5_TX4UDF(val)                             addI2S0_Reg0x5 = ((addI2S0_Reg0x5 & (~0x800)) | ((val) << 11))
#define setf_I2S0_Reg0x5_TX4UDF                                 addI2S0_Reg0x5 |= 0x800
#define clrf_I2S0_Reg0x5_TX4UDF                                 addI2S0_Reg0x5 &= ~0x800
#define get_I2S0_Reg0x5_TX4UDF                                  ((addI2S0_Reg0x5 & 0x800) >> 11)

#define posI2S0_Reg0x5_RX4OVF                                   10
#define bitI2S0_Reg0x5_RX4OVF                                   0x400
#define set_I2S0_Reg0x5_RX4OVF(val)                             addI2S0_Reg0x5 = ((addI2S0_Reg0x5 & (~0x400)) | ((val) << 10))
#define setf_I2S0_Reg0x5_RX4OVF                                 addI2S0_Reg0x5 |= 0x400
#define clrf_I2S0_Reg0x5_RX4OVF                                 addI2S0_Reg0x5 &= ~0x400
#define get_I2S0_Reg0x5_RX4OVF                                  ((addI2S0_Reg0x5 & 0x400) >> 10)

#define posI2S0_Reg0x5_TX4INT                                   9
#define bitI2S0_Reg0x5_TX4INT                                   0x200
#define get_I2S0_Reg0x5_TX4INT                                  ((addI2S0_Reg0x5 & 0x200) >> 9)

#define posI2S0_Reg0x5_RX4INT                                   8
#define bitI2S0_Reg0x5_RX4INT                                   0x100
#define get_I2S0_Reg0x5_RX4INT                                  ((addI2S0_Reg0x5 & 0x100) >> 8)

#define posI2S0_Reg0x5_TX3UDF                                   3
#define bitI2S0_Reg0x5_TX3UDF                                   0x8
#define set_I2S0_Reg0x5_TX3UDF(val)                             addI2S0_Reg0x5 = ((addI2S0_Reg0x5 & (~0x8)) | ((val) << 3))
#define setf_I2S0_Reg0x5_TX3UDF                                 addI2S0_Reg0x5 |= 0x8
#define clrf_I2S0_Reg0x5_TX3UDF                                 addI2S0_Reg0x5 &= ~0x8
#define get_I2S0_Reg0x5_TX3UDF                                  ((addI2S0_Reg0x5 & 0x8) >> 3)

#define posI2S0_Reg0x5_RX3OVF                                   6
#define bitI2S0_Reg0x5_RX3OVF                                   0x40
#define set_I2S0_Reg0x5_RX3OVF(val)                             addI2S0_Reg0x5 = ((addI2S0_Reg0x5 & (~0x40)) | ((val) << 6))
#define setf_I2S0_Reg0x5_RX3OVF                                 addI2S0_Reg0x5 |= 0x40
#define clrf_I2S0_Reg0x5_RX3OVF                                 addI2S0_Reg0x5 &= ~0x40
#define get_I2S0_Reg0x5_RX3OVF                                  ((addI2S0_Reg0x5 & 0x40) >> 6)

#define posI2S0_Reg0x5_TX3INT                                   5
#define bitI2S0_Reg0x5_TX3INT                                   0x20
#define get_I2S0_Reg0x5_TX3INT                                  ((addI2S0_Reg0x5 & 0x20) >> 5)

#define posI2S0_Reg0x5_RX3INT                                   4
#define bitI2S0_Reg0x5_RX3INT                                   0x10
#define get_I2S0_Reg0x5_RX3INT                                  ((addI2S0_Reg0x5 & 0x10) >> 4)

#define posI2S0_Reg0x5_TX2UDF                                   3
#define bitI2S0_Reg0x5_TX2UDF                                   0x8
#define set_I2S0_Reg0x5_TX2UDF(val)                             addI2S0_Reg0x5 = ((addI2S0_Reg0x5 & (~0x8)) | ((val) << 3))
#define setf_I2S0_Reg0x5_TX2UDF                                 addI2S0_Reg0x5 |= 0x8
#define clrf_I2S0_Reg0x5_TX2UDF                                 addI2S0_Reg0x5 &= ~0x8
#define get_I2S0_Reg0x5_TX2UDF                                  ((addI2S0_Reg0x5 & 0x8) >> 3)

#define posI2S0_Reg0x5_RX2OVF                                   2
#define bitI2S0_Reg0x5_RX2OVF                                   0x4
#define set_I2S0_Reg0x5_RX2OVF(val)                             addI2S0_Reg0x5 = ((addI2S0_Reg0x5 & (~0x4)) | ((val) << 2))
#define setf_I2S0_Reg0x5_RX2OVF                                 addI2S0_Reg0x5 |= 0x4
#define clrf_I2S0_Reg0x5_RX2OVF                                 addI2S0_Reg0x5 &= ~0x4
#define get_I2S0_Reg0x5_RX2OVF                                  ((addI2S0_Reg0x5 & 0x4) >> 2)

#define posI2S0_Reg0x5_TX2INT                                   1
#define bitI2S0_Reg0x5_TX2INT                                   0x2
#define get_I2S0_Reg0x5_TX2INT                                  ((addI2S0_Reg0x5 & 0x2) >> 1)

#define posI2S0_Reg0x5_RX2INT                                   0
#define bitI2S0_Reg0x5_RX2INT                                   0x1
#define get_I2S0_Reg0x5_RX2INT                                  (addI2S0_Reg0x5 & 0x1)

//addI2S0_Reg0x6
#define addI2S0_Reg0x6                                          *((volatile unsigned long *) (0x00806800+0x6*4))

//addI2S0_Reg0x7
#define addI2S0_Reg0x7                                          *((volatile unsigned long *) (0x00806800+0x7*4))

//addI2S0_Reg0x8
#define addI2S0_Reg0x8                                          *((volatile unsigned long *) (0x00806800+0x8*4))

//************************************************************//
//IRDA
//************************************************************//
#define BASEADDR_IRDA                                           0x00806900
//addIRDA_Reg0x0
#define addIRDA_Reg0x0                                          *((volatile unsigned long *) (0x00806900+0x0*4))
#define posIRDA_Reg0x0_txdata_num                               16
#define bitIRDA_Reg0x0_txdata_num                               0x3FF0000
#define set_IRDA_Reg0x0_txdata_num(val)                         addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x3FF0000)) | ((val) << 16))
#define get_IRDA_Reg0x0_txdata_num                              ((addIRDA_Reg0x0 & 0x3FF0000) >> 16)

#define posIRDA_Reg0x0_RSTN                                     15
#define bitIRDA_Reg0x0_RSTN                                     0x8000
#define set_IRDA_Reg0x0_RSTN(val)                               addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x8000)) | ((val) << 15))
#define setf_IRDA_Reg0x0_RSTN                                   addIRDA_Reg0x0 |= 0x8000
#define clrf_IRDA_Reg0x0_RSTN                                   addIRDA_Reg0x0 &= ~0x8000
#define get_IRDA_Reg0x0_RSTN                                    ((addIRDA_Reg0x0 & 0x8000) >> 15)

#define posIRDA_Reg0x0_RFU9                                     14
#define bitIRDA_Reg0x0_RFU9                                     0x4000
#define set_IRDA_Reg0x0_RFU9(val)                               addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x4000)) | ((val) << 14))
#define setf_IRDA_Reg0x0_RFU9                                   addIRDA_Reg0x0 |= 0x4000
#define clrf_IRDA_Reg0x0_RFU9                                   addIRDA_Reg0x0 &= ~0x4000
#define get_IRDA_Reg0x0_RFU9                                    ((addIRDA_Reg0x0 & 0x4000) >> 14)

#define posIRDA_Reg0x0_RFU8                                     13
#define bitIRDA_Reg0x0_RFU8                                     0x2000
#define set_IRDA_Reg0x0_RFU8(val)                               addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x2000)) | ((val) << 13))
#define setf_IRDA_Reg0x0_RFU8                                   addIRDA_Reg0x0 |= 0x2000
#define clrf_IRDA_Reg0x0_RFU8                                   addIRDA_Reg0x0 &= ~0x2000
#define get_IRDA_Reg0x0_RFU8                                    ((addIRDA_Reg0x0 & 0x2000) >> 13)

#define posIRDA_Reg0x0_clk_freq_in                              8
#define bitIRDA_Reg0x0_clk_freq_in                              0x1F00
#define set_IRDA_Reg0x0_clk_freq_in(val)                        addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x1F00)) | ((val) << 8))
#define get_IRDA_Reg0x0_clk_freq_in                             ((addIRDA_Reg0x0 & 0x1F00) >> 8)

#define posIRDA_Reg0x0_RFU7                                     6
#define bitIRDA_Reg0x0_RFU7                                     0xC0
#define set_IRDA_Reg0x0_RFU7(val)                               addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0xC0)) | ((val) << 6))
#define get_IRDA_Reg0x0_RFU7                                    ((addIRDA_Reg0x0 & 0xC0) >> 6)

#define posIRDA_Reg0x0_irda_pwr                                 5
#define bitIRDA_Reg0x0_irda_pwr                                 0x20
#define set_IRDA_Reg0x0_irda_pwr(val)                           addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x20)) | ((val) << 5))
#define setf_IRDA_Reg0x0_irda_pwr                               addIRDA_Reg0x0 |= 0x20
#define clrf_IRDA_Reg0x0_irda_pwr                               addIRDA_Reg0x0 &= ~0x20
#define get_IRDA_Reg0x0_irda_pwr                                ((addIRDA_Reg0x0 & 0x20) >> 5)

#define posIRDA_Reg0x0_tx_start                                 4
#define bitIRDA_Reg0x0_tx_start                                 0x10
#define set_IRDA_Reg0x0_tx_start(val)                           addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x10)) | ((val) << 4))
#define setf_IRDA_Reg0x0_tx_start                               addIRDA_Reg0x0 |= 0x10
#define clrf_IRDA_Reg0x0_tx_start                               addIRDA_Reg0x0 &= ~0x10
#define get_IRDA_Reg0x0_tx_start                                ((addIRDA_Reg0x0 & 0x10) >> 4)

#define posIRDA_Reg0x0_tx_initial_level                         3
#define bitIRDA_Reg0x0_tx_initial_level                         0x8
#define set_IRDA_Reg0x0_tx_initial_level(val)                   addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x8)) | ((val) << 3))
#define setf_IRDA_Reg0x0_tx_initial_level                       addIRDA_Reg0x0 |= 0x8
#define clrf_IRDA_Reg0x0_tx_initial_level                       addIRDA_Reg0x0 &= ~0x8
#define get_IRDA_Reg0x0_tx_initial_level                        ((addIRDA_Reg0x0 & 0x8) >> 3)

#define posIRDA_Reg0x0_txenable                                 2
#define bitIRDA_Reg0x0_txenable                                 0x4
#define set_IRDA_Reg0x0_txenable(val)                           addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x4)) | ((val) << 2))
#define setf_IRDA_Reg0x0_txenable                               addIRDA_Reg0x0 |= 0x4
#define clrf_IRDA_Reg0x0_txenable                               addIRDA_Reg0x0 &= ~0x4
#define get_IRDA_Reg0x0_txenable                                ((addIRDA_Reg0x0 & 0x4) >> 2)

#define posIRDA_Reg0x0_rx_initial_level                         1
#define bitIRDA_Reg0x0_rx_initial_level                         0x2
#define set_IRDA_Reg0x0_rx_initial_level(val)                   addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x2)) | ((val) << 1))
#define setf_IRDA_Reg0x0_rx_initial_level                       addIRDA_Reg0x0 |= 0x2
#define clrf_IRDA_Reg0x0_rx_initial_level                       addIRDA_Reg0x0 &= ~0x2
#define get_IRDA_Reg0x0_rx_initial_level                        ((addIRDA_Reg0x0 & 0x2) >> 1)

#define posIRDA_Reg0x0_rxenable                                 0
#define bitIRDA_Reg0x0_rxenable                                 0x1
#define set_IRDA_Reg0x0_rxenable(val)                           addIRDA_Reg0x0 = ((addIRDA_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_IRDA_Reg0x0_rxenable                               addIRDA_Reg0x0 |= 0x1
#define clrf_IRDA_Reg0x0_rxenable                               addIRDA_Reg0x0 &= ~0x1
#define get_IRDA_Reg0x0_rxenable                                (addIRDA_Reg0x0 & 0x1)

//addIRDA_Reg0x1
#define addIRDA_Reg0x1                                          *((volatile unsigned long *) (0x00806900+0x1*4))
#define posIRDA_Reg0x1_rx_timeout_cnt                           16
#define bitIRDA_Reg0x1_rx_timeout_cnt                           0xFFFF0000
#define set_IRDA_Reg0x1_rx_timeout_cnt(val)                     addIRDA_Reg0x1 = ((addIRDA_Reg0x1 & (~0xFFFF0000)) | ((val) << 16))
#define get_IRDA_Reg0x1_rx_timeout_cnt                          ((addIRDA_Reg0x1 & 0xFFFF0000) >> 16)

#define posIRDA_Reg0x1_RX_FIFO_THRESHOLD                        8
#define bitIRDA_Reg0x1_RX_FIFO_THRESHOLD                        0xFF00
#define set_IRDA_Reg0x1_RX_FIFO_THRESHOLD(val)                  addIRDA_Reg0x1 = ((addIRDA_Reg0x1 & (~0xFF00)) | ((val) << 8))
#define get_IRDA_Reg0x1_RX_FIFO_THRESHOLD                       ((addIRDA_Reg0x1 & 0xFF00) >> 8)

#define posIRDA_Reg0x1_TX_FIFO_THRESHOLD                        0
#define bitIRDA_Reg0x1_TX_FIFO_THRESHOLD                        0xFF
#define set_IRDA_Reg0x1_TX_FIFO_THRESHOLD(val)                  addIRDA_Reg0x1 = ((addIRDA_Reg0x1 & (~0xFF)) | ((val) << 0))
#define get_IRDA_Reg0x1_TX_FIFO_THRESHOLD                       (addIRDA_Reg0x1 & 0xFF)

//addIRDA_Reg0x2
#define addIRDA_Reg0x2                                          *((volatile unsigned long *) (0x00806900+0x2*4))
#define posIRDA_Reg0x2_TX_FIFO_COUNT                            0
#define bitIRDA_Reg0x2_TX_FIFO_COUNT                            0xFF
#define get_IRDA_Reg0x2_TX_FIFO_COUNT                           (addIRDA_Reg0x2 & 0xFF)

#define posIRDA_Reg0x2_RX_FIFO_COUNT                            8
#define bitIRDA_Reg0x2_RX_FIFO_COUNT                            0xFF00
#define get_IRDA_Reg0x2_RX_FIFO_COUNT                           ((addIRDA_Reg0x2 & 0xFF00) >> 8)

#define posIRDA_Reg0x2_TX_FIFO_FULL                             16
#define bitIRDA_Reg0x2_TX_FIFO_FULL                             0x10000
#define get_IRDA_Reg0x2_TX_FIFO_FULL                            ((addIRDA_Reg0x2 & 0x10000) >> 16)

#define posIRDA_Reg0x2_TX_FIFO_EMPTY                            17
#define bitIRDA_Reg0x2_TX_FIFO_EMPTY                            0x20000
#define get_IRDA_Reg0x2_TX_FIFO_EMPTY                           ((addIRDA_Reg0x2 & 0x20000) >> 17)

#define posIRDA_Reg0x2_RX_FIFO_FULL                             18
#define bitIRDA_Reg0x2_RX_FIFO_FULL                             0x40000
#define get_IRDA_Reg0x2_RX_FIFO_FULL                            ((addIRDA_Reg0x2 & 0x40000) >> 18)

#define posIRDA_Reg0x2_RX_FIFO_EMPTY                            19
#define bitIRDA_Reg0x2_RX_FIFO_EMPTY                            0x80000
#define get_IRDA_Reg0x2_RX_FIFO_EMPTY                           ((addIRDA_Reg0x2 & 0x80000) >> 19)

#define posIRDA_Reg0x2_FIFO_WR_READY                            20
#define bitIRDA_Reg0x2_FIFO_WR_READY                            0x100000
#define get_IRDA_Reg0x2_FIFO_WR_READY                           ((addIRDA_Reg0x2 & 0x100000) >> 20)

#define posIRDA_Reg0x2_FIFO_RD_READY                            21
#define bitIRDA_Reg0x2_FIFO_RD_READY                            0x200000
#define get_IRDA_Reg0x2_FIFO_RD_READY                           ((addIRDA_Reg0x2 & 0x200000) >> 21)

#define posIRDA_Reg0x2_rxdata_num                               22
#define bitIRDA_Reg0x2_rxdata_num                               0xFFC00000
#define get_IRDA_Reg0x2_rxdata_num                              ((addIRDA_Reg0x2 & 0xFFC00000) >> 22)

//addIRDA_Reg0x3
#define addIRDA_Reg0x3                                          *((volatile unsigned long *) (0x00806900+0x3*4))
#define posIRDA_Reg0x3_fifo_data_tx                             16
#define bitIRDA_Reg0x3_fifo_data_tx                             0xFFFF0000
#define set_IRDA_Reg0x3_fifo_data_tx(val)                       addIRDA_Reg0x3 = ((addIRDA_Reg0x3 & (~0xFFFF0000)) | ((val) << 16))
#define get_IRDA_Reg0x3_fifo_data_tx                            ((addIRDA_Reg0x3 & 0xFFFF0000) >> 16)

#define posIRDA_Reg0x3_fifo_data_rx                             0
#define bitIRDA_Reg0x3_fifo_data_rx                             0xFFFF
#define set_IRDA_Reg0x3_fifo_data_rx(val)                       addIRDA_Reg0x3 = ((addIRDA_Reg0x3 & (~0xFFFF)) | ((val) << 0))
#define get_IRDA_Reg0x3_fifo_data_rx                            (addIRDA_Reg0x3 & 0xFFFF)

//addIRDA_Reg0x4
#define addIRDA_Reg0x4                                          *((volatile unsigned long *) (0x00806900+0x4*4))
#define posIRDA_Reg0x4_RFU6                                     5
#define bitIRDA_Reg0x4_RFU6                                     0xFFFFFFE0
#define set_IRDA_Reg0x4_RFU6(val)                               addIRDA_Reg0x4 = ((addIRDA_Reg0x4 & (~0xFFFFFFE0)) | ((val) << 5))
#define get_IRDA_Reg0x4_RFU6                                    ((addIRDA_Reg0x4 & 0xFFFFFFE0) >> 5)

#define posIRDA_Reg0x4_rx_overflow_status                       4
#define bitIRDA_Reg0x4_rx_overflow_status                       0x10
#define set_IRDA_Reg0x4_rx_overflow_status(val)                 addIRDA_Reg0x4 = ((addIRDA_Reg0x4 & (~0x10)) | ((val) << 4))
#define setf_IRDA_Reg0x4_rx_overflow_status                     addIRDA_Reg0x4 |= 0x10
#define clrf_IRDA_Reg0x4_rx_overflow_status                     addIRDA_Reg0x4 &= ~0x10
#define get_IRDA_Reg0x4_rx_overflow_status                      ((addIRDA_Reg0x4 & 0x10) >> 4)

#define posIRDA_Reg0x4_rx_timeout_mask                          3
#define bitIRDA_Reg0x4_rx_timeout_mask                          0x8
#define set_IRDA_Reg0x4_rx_timeout_mask(val)                    addIRDA_Reg0x4 = ((addIRDA_Reg0x4 & (~0x8)) | ((val) << 3))
#define setf_IRDA_Reg0x4_rx_timeout_mask                        addIRDA_Reg0x4 |= 0x8
#define clrf_IRDA_Reg0x4_rx_timeout_mask                        addIRDA_Reg0x4 &= ~0x8
#define get_IRDA_Reg0x4_rx_timeout_mask                         ((addIRDA_Reg0x4 & 0x8) >> 3)

#define posIRDA_Reg0x4_tx_done_mask                             2
#define bitIRDA_Reg0x4_tx_done_mask                             0x4
#define set_IRDA_Reg0x4_tx_done_mask(val)                       addIRDA_Reg0x4 = ((addIRDA_Reg0x4 & (~0x4)) | ((val) << 2))
#define setf_IRDA_Reg0x4_tx_done_mask                           addIRDA_Reg0x4 |= 0x4
#define clrf_IRDA_Reg0x4_tx_done_mask                           addIRDA_Reg0x4 &= ~0x4
#define get_IRDA_Reg0x4_tx_done_mask                            ((addIRDA_Reg0x4 & 0x4) >> 2)

#define posIRDA_Reg0x4_rx_need_rd_mask                          1
#define bitIRDA_Reg0x4_rx_need_rd_mask                          0x2
#define set_IRDA_Reg0x4_rx_need_rd_mask(val)                    addIRDA_Reg0x4 = ((addIRDA_Reg0x4 & (~0x2)) | ((val) << 1))
#define setf_IRDA_Reg0x4_rx_need_rd_mask                        addIRDA_Reg0x4 |= 0x2
#define clrf_IRDA_Reg0x4_rx_need_rd_mask                        addIRDA_Reg0x4 &= ~0x2
#define get_IRDA_Reg0x4_rx_need_rd_mask                         ((addIRDA_Reg0x4 & 0x2) >> 1)

#define posIRDA_Reg0x4_tx_need_wr_mask                          0
#define bitIRDA_Reg0x4_tx_need_wr_mask                          0x1
#define set_IRDA_Reg0x4_tx_need_wr_mask(val)                    addIRDA_Reg0x4 = ((addIRDA_Reg0x4 & (~0x1)) | ((val) << 0))
#define setf_IRDA_Reg0x4_tx_need_wr_mask                        addIRDA_Reg0x4 |= 0x1
#define clrf_IRDA_Reg0x4_tx_need_wr_mask                        addIRDA_Reg0x4 &= ~0x1
#define get_IRDA_Reg0x4_tx_need_wr_mask                         (addIRDA_Reg0x4 & 0x1)

//addIRDA_Reg0x5
#define addIRDA_Reg0x5                                          *((volatile unsigned long *) (0x00806900+0x5*4))
#define posIRDA_Reg0x5_RFU5                                     5
#define bitIRDA_Reg0x5_RFU5                                     0xFFFFFFE0
#define set_IRDA_Reg0x5_RFU5(val)                               addIRDA_Reg0x5 = ((addIRDA_Reg0x5 & (~0xFFFFFFE0)) | ((val) << 5))
#define get_IRDA_Reg0x5_RFU5                                    ((addIRDA_Reg0x5 & 0xFFFFFFE0) >> 5)

#define posIRDA_Reg0x5_rx_overflow_status                       4
#define bitIRDA_Reg0x5_rx_overflow_status                       0x10
#define set_IRDA_Reg0x5_rx_overflow_status(val)                 addIRDA_Reg0x5 = ((addIRDA_Reg0x5 & (~0x10)) | ((val) << 4))
#define setf_IRDA_Reg0x5_rx_overflow_status                     addIRDA_Reg0x5 |= 0x10
#define clrf_IRDA_Reg0x5_rx_overflow_status                     addIRDA_Reg0x5 &= ~0x10
#define get_IRDA_Reg0x5_rx_overflow_status                      ((addIRDA_Reg0x5 & 0x10) >> 4)

#define posIRDA_Reg0x5_rx_done_status                           3
#define bitIRDA_Reg0x5_rx_done_status                           0x8
#define set_IRDA_Reg0x5_rx_done_status(val)                     addIRDA_Reg0x5 = ((addIRDA_Reg0x5 & (~0x8)) | ((val) << 3))
#define setf_IRDA_Reg0x5_rx_done_status                         addIRDA_Reg0x5 |= 0x8
#define clrf_IRDA_Reg0x5_rx_done_status                         addIRDA_Reg0x5 &= ~0x8
#define get_IRDA_Reg0x5_rx_done_status                          ((addIRDA_Reg0x5 & 0x8) >> 3)

#define posIRDA_Reg0x5_tx_done                                  2
#define bitIRDA_Reg0x5_tx_done                                  0x4
#define set_IRDA_Reg0x5_tx_done(val)                            addIRDA_Reg0x5 = ((addIRDA_Reg0x5 & (~0x4)) | ((val) << 2))
#define setf_IRDA_Reg0x5_tx_done                                addIRDA_Reg0x5 |= 0x4
#define clrf_IRDA_Reg0x5_tx_done                                addIRDA_Reg0x5 &= ~0x4
#define get_IRDA_Reg0x5_tx_done                                 ((addIRDA_Reg0x5 & 0x4) >> 2)

#define posIRDA_Reg0x5_rx_need_rd_state                         1
#define bitIRDA_Reg0x5_rx_need_rd_state                         0x2
#define set_IRDA_Reg0x5_rx_need_rd_state(val)                   addIRDA_Reg0x5 = ((addIRDA_Reg0x5 & (~0x2)) | ((val) << 1))
#define setf_IRDA_Reg0x5_rx_need_rd_state                       addIRDA_Reg0x5 |= 0x2
#define clrf_IRDA_Reg0x5_rx_need_rd_state                       addIRDA_Reg0x5 &= ~0x2
#define get_IRDA_Reg0x5_rx_need_rd_state                        ((addIRDA_Reg0x5 & 0x2) >> 1)

#define posIRDA_Reg0x5_tx_need_wr_state                         0
#define bitIRDA_Reg0x5_tx_need_wr_state                         0x1
#define set_IRDA_Reg0x5_tx_need_wr_state(val)                   addIRDA_Reg0x5 = ((addIRDA_Reg0x5 & (~0x1)) | ((val) << 0))
#define setf_IRDA_Reg0x5_tx_need_wr_state                       addIRDA_Reg0x5 |= 0x1
#define clrf_IRDA_Reg0x5_tx_need_wr_state                       addIRDA_Reg0x5 &= ~0x1
#define get_IRDA_Reg0x5_tx_need_wr_state                        (addIRDA_Reg0x5 & 0x1)

//addIRDA_Reg0x6
#define addIRDA_Reg0x6                                          *((volatile unsigned long *) (0x00806900+0x6*4))
#define posIRDA_Reg0x6_rx_start_thr                             20
#define bitIRDA_Reg0x6_rx_start_thr                             0xFFF00000
#define set_IRDA_Reg0x6_rx_start_thr(val)                       addIRDA_Reg0x6 = ((addIRDA_Reg0x6 & (~0xFFF00000)) | ((val) << 20))
#define get_IRDA_Reg0x6_rx_start_thr                            ((addIRDA_Reg0x6 & 0xFFF00000) >> 20)

#define posIRDA_Reg0x6_RFU4                                     18
#define bitIRDA_Reg0x6_RFU4                                     0xC0000
#define set_IRDA_Reg0x6_RFU4(val)                               addIRDA_Reg0x6 = ((addIRDA_Reg0x6 & (~0xC0000)) | ((val) << 18))
#define get_IRDA_Reg0x6_RFU4                                    ((addIRDA_Reg0x6 & 0xC0000) >> 18)

#define posIRDA_Reg0x6_carrier_enable                           17
#define bitIRDA_Reg0x6_carrier_enable                           0x20000
#define set_IRDA_Reg0x6_carrier_enable(val)                     addIRDA_Reg0x6 = ((addIRDA_Reg0x6 & (~0x20000)) | ((val) << 17))
#define setf_IRDA_Reg0x6_carrier_enable                         addIRDA_Reg0x6 |= 0x20000
#define clrf_IRDA_Reg0x6_carrier_enable                         addIRDA_Reg0x6 &= ~0x20000
#define get_IRDA_Reg0x6_carrier_enable                          ((addIRDA_Reg0x6 & 0x20000) >> 17)

#define posIRDA_Reg0x6_carrier_polarity                         16
#define bitIRDA_Reg0x6_carrier_polarity                         0x10000
#define set_IRDA_Reg0x6_carrier_polarity(val)                   addIRDA_Reg0x6 = ((addIRDA_Reg0x6 & (~0x10000)) | ((val) << 16))
#define setf_IRDA_Reg0x6_carrier_polarity                       addIRDA_Reg0x6 |= 0x10000
#define clrf_IRDA_Reg0x6_carrier_polarity                       addIRDA_Reg0x6 &= ~0x10000
#define get_IRDA_Reg0x6_carrier_polarity                        ((addIRDA_Reg0x6 & 0x10000) >> 16)

#define posIRDA_Reg0x6_carrier_duty                             8
#define bitIRDA_Reg0x6_carrier_duty                             0xFF00
#define set_IRDA_Reg0x6_carrier_duty(val)                       addIRDA_Reg0x6 = ((addIRDA_Reg0x6 & (~0xFF00)) | ((val) << 8))
#define get_IRDA_Reg0x6_carrier_duty                            ((addIRDA_Reg0x6 & 0xFF00) >> 8)

#define posIRDA_Reg0x6_carrier_period                           0
#define bitIRDA_Reg0x6_carrier_period                           0xFF
#define set_IRDA_Reg0x6_carrier_period(val)                     addIRDA_Reg0x6 = ((addIRDA_Reg0x6 & (~0xFF)) | ((val) << 0))
#define get_IRDA_Reg0x6_carrier_period                          (addIRDA_Reg0x6 & 0xFF)

//addIRDA_Reg0x7
#define addIRDA_Reg0x7                                          *((volatile unsigned long *) (0x00806900+0x7*4))
#define posIRDA_Reg0x7_RFU3                                     5
#define bitIRDA_Reg0x7_RFU3                                     0xFFFFFFE0
#define set_IRDA_Reg0x7_RFU3(val)                               addIRDA_Reg0x7 = ((addIRDA_Reg0x7 & (~0xFFFFFFE0)) | ((val) << 5))
#define get_IRDA_Reg0x7_RFU3                                    ((addIRDA_Reg0x7 & 0xFFFFFFE0) >> 5)

#define posIRDA_Reg0x7_glitch_thr                               16
#define bitIRDA_Reg0x7_glitch_thr                               0xFFF0000
#define set_IRDA_Reg0x7_glitch_thr(val)                         addIRDA_Reg0x7 = ((addIRDA_Reg0x7 & (~0xFFF0000)) | ((val) << 16))
#define get_IRDA_Reg0x7_glitch_thr                              ((addIRDA_Reg0x7 & 0xFFF0000) >> 16)

#define posIRDA_Reg0x7_RFU2                                     3
#define bitIRDA_Reg0x7_RFU2                                     0xFFF8
#define set_IRDA_Reg0x7_RFU2(val)                               addIRDA_Reg0x7 = ((addIRDA_Reg0x7 & (~0xFFF8)) | ((val) << 3))
#define get_IRDA_Reg0x7_RFU2                                    ((addIRDA_Reg0x7 & 0xFFF8) >> 3)

#define posIRDA_Reg0x7_RFU1                                     2
#define bitIRDA_Reg0x7_RFU1                                     0x4
#define set_IRDA_Reg0x7_RFU1(val)                               addIRDA_Reg0x7 = ((addIRDA_Reg0x7 & (~0x4)) | ((val) << 2))
#define setf_IRDA_Reg0x7_RFU1                                   addIRDA_Reg0x7 |= 0x4
#define clrf_IRDA_Reg0x7_RFU1                                   addIRDA_Reg0x7 &= ~0x4
#define get_IRDA_Reg0x7_RFU1                                    ((addIRDA_Reg0x7 & 0x4) >> 2)

#define posIRDA_Reg0x7_RFU0                                     1
#define bitIRDA_Reg0x7_RFU0                                     0x2
#define set_IRDA_Reg0x7_RFU0(val)                               addIRDA_Reg0x7 = ((addIRDA_Reg0x7 & (~0x2)) | ((val) << 1))
#define setf_IRDA_Reg0x7_RFU0                                   addIRDA_Reg0x7 |= 0x2
#define clrf_IRDA_Reg0x7_RFU0                                   addIRDA_Reg0x7 &= ~0x2
#define get_IRDA_Reg0x7_RFU0                                    ((addIRDA_Reg0x7 & 0x2) >> 1)

#define posIRDA_Reg0x7_glitch_enable                            0
#define bitIRDA_Reg0x7_glitch_enable                            0x1
#define set_IRDA_Reg0x7_glitch_enable(val)                      addIRDA_Reg0x7 = ((addIRDA_Reg0x7 & (~0x1)) | ((val) << 0))
#define setf_IRDA_Reg0x7_glitch_enable                          addIRDA_Reg0x7 |= 0x1
#define clrf_IRDA_Reg0x7_glitch_enable                          addIRDA_Reg0x7 &= ~0x1
#define get_IRDA_Reg0x7_glitch_enable                           (addIRDA_Reg0x7 & 0x1)


//************************************************************//
//RTC
//************************************************************//
#define BASEADDR_RTC                                            0x00806D00
//addRTC_Reg0x0
#define addRTC_Reg0x0                                           *((volatile unsigned long *) (0x00806D00+0x0*4))
#define posRTC_Reg0x0_RTC_ENABLE                                0
#define bitRTC_Reg0x0_RTC_ENABLE                                0x1
#define set_RTC_Reg0x0_RTC_ENABLE(val)                          addRTC_Reg0x0 = ((addRTC_Reg0x0 & (~0x1)) | ((val) << 0))
#define setf_RTC_Reg0x0_RTC_ENABLE                              addRTC_Reg0x0 |= 0x1
#define clrf_RTC_Reg0x0_RTC_ENABLE                              addRTC_Reg0x0 &= ~0x1
#define get_RTC_Reg0x0_RTC_ENABLE                               (addRTC_Reg0x0 & 0x1)

#define posRTC_Reg0x0_RTC_CLEAR                                 1
#define bitRTC_Reg0x0_RTC_CLEAR                                 0x2
#define set_RTC_Reg0x0_RTC_CLEAR(val)                           addRTC_Reg0x0 = ((addRTC_Reg0x0 & (~0x2)) | ((val) << 1))
#define setf_RTC_Reg0x0_RTC_CLEAR                               addRTC_Reg0x0 |= 0x2
#define clrf_RTC_Reg0x0_RTC_CLEAR                               addRTC_Reg0x0 &= ~0x2
#define get_RTC_Reg0x0_RTC_CLEAR                                ((addRTC_Reg0x0 & 0x2) >> 1)

#define posRTC_Reg0x0_RTC_ALARM_EN                              2
#define bitRTC_Reg0x0_RTC_ALARM_EN                              0x4
#define set_RTC_Reg0x0_RTC_ALARM_EN(val)                        addRTC_Reg0x0 = ((addRTC_Reg0x0 & (~0x4)) | ((val) << 2))
#define setf_RTC_Reg0x0_RTC_ALARM_EN                            addRTC_Reg0x0 |= 0x4
#define clrf_RTC_Reg0x0_RTC_ALARM_EN                            addRTC_Reg0x0 &= ~0x4
#define get_RTC_Reg0x0_RTC_ALARM_EN                             ((addRTC_Reg0x0 & 0x4) >> 2)

#define posRTC_Reg0x0_RTC_ALARM_MODE                            3
#define bitRTC_Reg0x0_RTC_ALARM_MODE                            0x8
#define set_RTC_Reg0x0_RTC_ALARM_MODE(val)                      addRTC_Reg0x0 = ((addRTC_Reg0x0 & (~0x8)) | ((val) << 3))
#define setf_RTC_Reg0x0_RTC_ALARM_MODE                          addRTC_Reg0x0 |= 0x8
#define clrf_RTC_Reg0x0_RTC_ALARM_MODE                          addRTC_Reg0x0 &= ~0x8
#define get_RTC_Reg0x0_RTC_ALARM_MODE                           ((addRTC_Reg0x0 & 0x8) >> 3)

//addRTC_Reg0x1
#define addRTC_Reg0x1                                           *((volatile unsigned long *) (0x00806D00+0x1*4))
#define posRTC_Reg0x1_RTC_DIV                                   0
#define bitRTC_Reg0x1_RTC_DIV                                   0x3
#define set_RTC_Reg0x1_RTC_DIV(val)                             addRTC_Reg0x1 = ((addRTC_Reg0x1 & (~0x3)) | ((val) << 0))
#define get_RTC_Reg0x1_RTC_DIV                                  (addRTC_Reg0x1 & 0x3)

#define posRTC_Reg0x1_RTC_MSUNIT                                2
#define bitRTC_Reg0x1_RTC_MSUNIT                                0xFC
#define set_RTC_Reg0x1_RTC_MSUNIT(val)                          addRTC_Reg0x1 = ((addRTC_Reg0x1 & (~0xFC)) | ((val) << 2))
#define get_RTC_Reg0x1_RTC_MSUNIT                               ((addRTC_Reg0x1 & 0xFC) >> 2)

#define posRTC_Reg0x1_RTC_SUNIT                                 8
#define bitRTC_Reg0x1_RTC_SUNIT                                 0xFFFF00
#define set_RTC_Reg0x1_RTC_SUNIT(val)                           addRTC_Reg0x1 = ((addRTC_Reg0x1 & (~0xFFFF00)) | ((val) << 8))
#define get_RTC_Reg0x1_RTC_SUNIT                                ((addRTC_Reg0x1 & 0xFFFF00) >> 8)

//addRTC_Reg0x2
#define addRTC_Reg0x2                                           *((volatile unsigned long *) (0x00806D00+0x2*4))
#define posRTC_Reg0x2_RTC_S                                     0
#define bitRTC_Reg0x2_RTC_S                                     0x3F
#define set_RTC_Reg0x2_RTC_S(val)                               addRTC_Reg0x2 = ((addRTC_Reg0x2 & (~0x3F)) | ((val) << 0))
#define get_RTC_Reg0x2_RTC_S                                    (addRTC_Reg0x2 & 0x3F)

#define posRTC_Reg0x2_RTC_M                                     6
#define bitRTC_Reg0x2_RTC_M                                     0xFC0
#define set_RTC_Reg0x2_RTC_M(val)                               addRTC_Reg0x2 = ((addRTC_Reg0x2 & (~0xFC0)) | ((val) << 6))
#define get_RTC_Reg0x2_RTC_M                                    ((addRTC_Reg0x2 & 0xFC0) >> 6)

#define posRTC_Reg0x2_RTC_H                                     12
#define bitRTC_Reg0x2_RTC_H                                     0x1F000
#define set_RTC_Reg0x2_RTC_H(val)                               addRTC_Reg0x2 = ((addRTC_Reg0x2 & (~0x1F000)) | ((val) << 12))
#define get_RTC_Reg0x2_RTC_H                                    ((addRTC_Reg0x2 & 0x1F000) >> 12)

#define posRTC_Reg0x2_RTC_W                                     17
#define bitRTC_Reg0x2_RTC_W                                     0xE0000
#define set_RTC_Reg0x2_RTC_W(val)                               addRTC_Reg0x2 = ((addRTC_Reg0x2 & (~0xE0000)) | ((val) << 17))
#define get_RTC_Reg0x2_RTC_W                                    ((addRTC_Reg0x2 & 0xE0000) >> 17)

//addRTC_Reg0x3
#define addRTC_Reg0x3                                           *((volatile unsigned long *) (0x00806D00+0x3*4))
#define posRTC_Reg0x3_RTC_ALARM_S                               0
#define bitRTC_Reg0x3_RTC_ALARM_S                               0x3F
#define set_RTC_Reg0x3_RTC_ALARM_S(val)                         addRTC_Reg0x3 = ((addRTC_Reg0x3 & (~0x3F)) | ((val) << 0))
#define get_RTC_Reg0x3_RTC_ALARM_S                              (addRTC_Reg0x3 & 0x3F)

#define posRTC_Reg0x3_RTC_ALARM_M                               6
#define bitRTC_Reg0x3_RTC_ALARM_M                               0xFC0
#define set_RTC_Reg0x3_RTC_ALARM_M(val)                         addRTC_Reg0x3 = ((addRTC_Reg0x3 & (~0xFC0)) | ((val) << 6))
#define get_RTC_Reg0x3_RTC_ALARM_M                              ((addRTC_Reg0x3 & 0xFC0) >> 6)

#define posRTC_Reg0x3_RTC_ALARM_H                               12
#define bitRTC_Reg0x3_RTC_ALARM_H                               0x1F000
#define set_RTC_Reg0x3_RTC_ALARM_H(val)                         addRTC_Reg0x3 = ((addRTC_Reg0x3 & (~0x1F000)) | ((val) << 12))
#define get_RTC_Reg0x3_RTC_ALARM_H                              ((addRTC_Reg0x3 & 0x1F000) >> 12)

#define posRTC_Reg0x3_RTC_ALARM_MS                              17
#define bitRTC_Reg0x3_RTC_ALARM_MS                              0x7FE0000
#define set_RTC_Reg0x3_RTC_ALARM_MS(val)                        addRTC_Reg0x3 = ((addRTC_Reg0x3 & (~0x7FE0000)) | ((val) << 17))
#define get_RTC_Reg0x3_RTC_ALARM_MS                             ((addRTC_Reg0x3 & 0x7FE0000) >> 17)

//addRTC_Reg0x4
#define addRTC_Reg0x4                                           *((volatile unsigned long *) (0x00806D00+0x4*4))
#define posRTC_Reg0x4_RTC_ALARM_FLAG                            0
#define bitRTC_Reg0x4_RTC_ALARM_FLAG                            0x1
#define set_RTC_Reg0x4_RTC_ALARM_FLAG(val)                      addRTC_Reg0x4 = ((addRTC_Reg0x4 & (~0x1)) | ((val) << 0))
#define setf_RTC_Reg0x4_RTC_ALARM_FLAG                          addRTC_Reg0x4 |= 0x1
#define clrf_RTC_Reg0x4_RTC_ALARM_FLAG                          addRTC_Reg0x4 &= ~0x1
#define get_RTC_Reg0x4_RTC_ALARM_FLAG                           (addRTC_Reg0x4 & 0x1)


//************************************************************//
//XVR
//************************************************************//
#define BASEADDR_XVR                                            0x00806E00
//addXVR_Reg0x0
#define addXVR_Reg0x0                                           *((volatile unsigned long *) (0x00806E00+0x0*4))
#define posXVR_Reg0x0_Nrsten                                    31
#define bitXVR_Reg0x0_Nrsten                                    0x80000000
#define set_XVR_Reg0x0_Nrsten(val)                              addXVR_Reg0x0 = ((addXVR_Reg0x0 & (~0x80000000)) | ((val) << 31))
#define setf_XVR_Reg0x0_Nrsten                                  addXVR_Reg0x0 |= 0x80000000
#define clrf_XVR_Reg0x0_Nrsten                                  addXVR_Reg0x0 &= ~0x80000000
#define get_XVR_Reg0x0_Nrsten                                   ((addXVR_Reg0x0 & 0x80000000) >> 31)

#define posXVR_Reg0x0_pfddelaysel                               29
#define bitXVR_Reg0x0_pfddelaysel                               0x60000000
#define set_XVR_Reg0x0_pfddelaysel(val)                         addXVR_Reg0x0 = ((addXVR_Reg0x0 & (~0x60000000)) | ((val) << 29))
#define get_XVR_Reg0x0_pfddelaysel                              ((addXVR_Reg0x0 & 0x60000000) >> 29)

#define posXVR_Reg0x0_Nint                                      19
#define bitXVR_Reg0x0_Nint                                      0x1FF80000
#define set_XVR_Reg0x0_Nint(val)                                addXVR_Reg0x0 = ((addXVR_Reg0x0 & (~0x1FF80000)) | ((val) << 19))
#define get_XVR_Reg0x0_Nint                                     ((addXVR_Reg0x0 & 0x1FF80000) >> 19)

#define posXVR_Reg0x0_R                                         13
#define bitXVR_Reg0x0_R                                         0x7E000
#define set_XVR_Reg0x0_R(val)                                   addXVR_Reg0x0 = ((addXVR_Reg0x0 & (~0x7E000)) | ((val) << 13))
#define get_XVR_Reg0x0_R                                        ((addXVR_Reg0x0 & 0x7E000) >> 13)

#define posXVR_Reg0x0_NWMODp                                    10
#define bitXVR_Reg0x0_NWMODp                                    0x1C00
#define set_XVR_Reg0x0_NWMODp(val)                              addXVR_Reg0x0 = ((addXVR_Reg0x0 & (~0x1C00)) | ((val) << 10))
#define get_XVR_Reg0x0_NWMODp                                   ((addXVR_Reg0x0 & 0x1C00) >> 10)

#define posXVR_Reg0x0_NWMODn                                    7
#define bitXVR_Reg0x0_NWMODn                                    0x380
#define set_XVR_Reg0x0_NWMODn(val)                              addXVR_Reg0x0 = ((addXVR_Reg0x0 & (~0x380)) | ((val) << 7))
#define get_XVR_Reg0x0_NWMODn                                   ((addXVR_Reg0x0 & 0x380) >> 7)


#define posXVR_Reg0x0_ampctrl_manual                            5
#define bitXVR_Reg0x0_ampctrl_manual                            0x20
#define set_XVR_Reg0x0_ampctrl_manual(val)                      addXVR_Reg0x0 = ((addXVR_Reg0x0 & (~0x20)) | ((val) << 5))
#define setf_XVR_Reg0x0_ampctrl_manual                          addXVR_Reg0x0 |= 0x20
#define clrf_XVR_Reg0x0_ampctrl_manual                          addXVR_Reg0x0 &= ~0x20
#define get_XVR_Reg0x0_ampctrl_manual                           ((addXVR_Reg0x0 & 0x20) >> 5)

#define posXVR_Reg0x0_Itune_vco_spi                             0
#define bitXVR_Reg0x0_Itune_vco_spi                             0x1F
#define set_XVR_Reg0x0_Itune_vco_spi(val)                       addXVR_Reg0x0 = ((addXVR_Reg0x0 & (~0x1F)) | ((val) << 0))
#define get_XVR_Reg0x0_Itune_vco_spi                            (addXVR_Reg0x0 & 0x1F)

//addXVR_Reg0x1
#define addXVR_Reg0x1                                           *((volatile unsigned long *) (0x00806E00+0x1*4))
#define posXVR_Reg0x1_bwsw_tsel                                 28
#define bitXVR_Reg0x1_bwsw_tsel                                 0xF0000000
#define set_XVR_Reg0x1_bwsw_tsel(val)                           addXVR_Reg0x1 = ((addXVR_Reg0x1 & (~0xF0000000)) | ((val) << 28))
#define get_XVR_Reg0x1_bwsw_tsel                                ((addXVR_Reg0x1 & 0xF0000000) >> 28)

#define posXVR_Reg0x1_bwsw_en                                   27
#define bitXVR_Reg0x1_bwsw_en                                   0x8000000
#define set_XVR_Reg0x1_bwsw_en(val)                             addXVR_Reg0x1 = ((addXVR_Reg0x1 & (~0x8000000)) | ((val) << 27))
#define setf_XVR_Reg0x1_bwsw_en                                 addXVR_Reg0x1 |= 0x8000000
#define clrf_XVR_Reg0x1_bwsw_en                                 addXVR_Reg0x1 &= ~0x8000000
#define get_XVR_Reg0x1_bwsw_en                                  ((addXVR_Reg0x1 & 0x8000000) >> 27)

#define posXVR_Reg0x1_loopRz_w                                  22
#define bitXVR_Reg0x1_loopRz_w                                  0x7C00000
#define set_XVR_Reg0x1_loopRz_w(val)                            addXVR_Reg0x1 = ((addXVR_Reg0x1 & (~0x7C00000)) | ((val) << 22))
#define get_XVR_Reg0x1_loopRz_w                                 ((addXVR_Reg0x1 & 0x7C00000) >> 22)

#define posXVR_Reg0x1_loopRz_n                                  17
#define bitXVR_Reg0x1_loopRz_n                                  0x3E0000
#define set_XVR_Reg0x1_loopRz_n(val)                            addXVR_Reg0x1 = ((addXVR_Reg0x1 & (~0x3E0000)) | ((val) << 17))
#define get_XVR_Reg0x1_loopRz_n                                 ((addXVR_Reg0x1 & 0x3E0000) >> 17)

#define posXVR_Reg0x1_Icp_core_w                                12
#define bitXVR_Reg0x1_Icp_core_w                                0x1F000
#define set_XVR_Reg0x1_Icp_core_w(val)                          addXVR_Reg0x1 = ((addXVR_Reg0x1 & (~0x1F000)) | ((val) << 12))
#define get_XVR_Reg0x1_Icp_core_w                               ((addXVR_Reg0x1 & 0x1F000) >> 12)

#define posXVR_Reg0x1_Icp_core_n                                7
#define bitXVR_Reg0x1_Icp_core_n                                0xF80
#define set_XVR_Reg0x1_Icp_core_n(val)                          addXVR_Reg0x1 = ((addXVR_Reg0x1 & (~0xF80)) | ((val) << 7))
#define get_XVR_Reg0x1_Icp_core_n                               ((addXVR_Reg0x1 & 0xF80) >> 7)

#define posXVR_Reg0x1_Icp_core_offset                           3
#define bitXVR_Reg0x1_Icp_core_offset                           0x78
#define set_XVR_Reg0x1_Icp_core_offset(val)                     addXVR_Reg0x1 = ((addXVR_Reg0x1 & (~0x78)) | ((val) << 3))
#define get_XVR_Reg0x1_Icp_core_offset                          ((addXVR_Reg0x1 & 0x78) >> 3)

#define posXVR_Reg0x1_Nclken_spi                                2
#define bitXVR_Reg0x1_Nclken_spi                                0x4
#define set_XVR_Reg0x1_Nclken_spi(val)                          addXVR_Reg0x1 = ((addXVR_Reg0x1 & (~0x4)) | ((val) << 2))
#define setf_XVR_Reg0x1_Nclken_spi                              addXVR_Reg0x1 |= 0x4
#define clrf_XVR_Reg0x1_Nclken_spi                              addXVR_Reg0x1 &= ~0x4
#define get_XVR_Reg0x1_Nclken_spi                               ((addXVR_Reg0x1 & 0x4) >> 2)

#define posXVR_Reg0x1_selvcopol                                 1
#define bitXVR_Reg0x1_selvcopol                                 0x2
#define set_XVR_Reg0x1_selvcopol(val)                           addXVR_Reg0x1 = ((addXVR_Reg0x1 & (~0x2)) | ((val) << 1))
#define setf_XVR_Reg0x1_selvcopol                               addXVR_Reg0x1 |= 0x2
#define clrf_XVR_Reg0x1_selvcopol                               addXVR_Reg0x1 &= ~0x2
#define get_XVR_Reg0x1_selvcopol                                ((addXVR_Reg0x1 & 0x2) >> 1)

#define posXVR_Reg0x1_tristate_spi                              0
#define bitXVR_Reg0x1_tristate_spi                              0x1
#define set_XVR_Reg0x1_tristate_spi(val)                        addXVR_Reg0x1 = ((addXVR_Reg0x1 & (~0x1)) | ((val) << 0))
#define setf_XVR_Reg0x1_tristate_spi                            addXVR_Reg0x1 |= 0x1
#define clrf_XVR_Reg0x1_tristate_spi                            addXVR_Reg0x1 &= ~0x1
#define get_XVR_Reg0x1_tristate_spi                             (addXVR_Reg0x1 & 0x1)

//addXVR_Reg0x2
#define addXVR_Reg0x2                                           *((volatile unsigned long *) (0x00806E00+0x2*4))
#define posXVR_Reg0x2_spi_trigger                               31
#define bitXVR_Reg0x2_spi_trigger                               0x80000000
#define set_XVR_Reg0x2_spi_trigger(val)                         addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x80000000)) | ((val) << 31))
#define setf_XVR_Reg0x2_spi_trigger                             addXVR_Reg0x2 |= 0x80000000
#define clrf_XVR_Reg0x2_spi_trigger                             addXVR_Reg0x2 &= ~0x80000000
#define get_XVR_Reg0x2_spi_trigger                              ((addXVR_Reg0x2 & 0x80000000) >> 31)

#define posXVR_Reg0x2_reset_spi                                 30
#define bitXVR_Reg0x2_reset_spi                                 0x40000000
#define set_XVR_Reg0x2_reset_spi(val)                           addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x40000000)) | ((val) << 30))
#define setf_XVR_Reg0x2_reset_spi                               addXVR_Reg0x2 |= 0x40000000
#define clrf_XVR_Reg0x2_reset_spi                               addXVR_Reg0x2 &= ~0x40000000
#define get_XVR_Reg0x2_reset_spi                                ((addXVR_Reg0x2 & 0x40000000) >> 30)

#define posXVR_Reg0x2_Icpmis_en_n                               29
#define bitXVR_Reg0x2_Icpmis_en_n                               0x20000000
#define set_XVR_Reg0x2_Icpmis_en_n(val)                         addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x20000000)) | ((val) << 29))
#define setf_XVR_Reg0x2_Icpmis_en_n                             addXVR_Reg0x2 |= 0x20000000
#define clrf_XVR_Reg0x2_Icpmis_en_n                             addXVR_Reg0x2 &= ~0x20000000
#define get_XVR_Reg0x2_Icpmis_en_n                              ((addXVR_Reg0x2 & 0x20000000) >> 29)

#define posXVR_Reg0x2_Icpmis_en_w                               28
#define bitXVR_Reg0x2_Icpmis_en_w                               0x10000000
#define set_XVR_Reg0x2_Icpmis_en_w(val)                         addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x10000000)) | ((val) << 28))
#define setf_XVR_Reg0x2_Icpmis_en_w                             addXVR_Reg0x2 |= 0x10000000
#define clrf_XVR_Reg0x2_Icpmis_en_w                             addXVR_Reg0x2 &= ~0x10000000
#define get_XVR_Reg0x2_Icpmis_en_w                              ((addXVR_Reg0x2 & 0x10000000) >> 28)

#define posXVR_Reg0x2_pwd_lockdet_spi                           27
#define bitXVR_Reg0x2_pwd_lockdet_spi                           0x8000000
#define set_XVR_Reg0x2_pwd_lockdet_spi(val)                     addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x8000000)) | ((val) << 27))
#define setf_XVR_Reg0x2_pwd_lockdet_spi                         addXVR_Reg0x2 |= 0x8000000
#define clrf_XVR_Reg0x2_pwd_lockdet_spi                         addXVR_Reg0x2 &= ~0x8000000
#define get_XVR_Reg0x2_pwd_lockdet_spi                          ((addXVR_Reg0x2 & 0x8000000) >> 27)

#define posXVR_Reg0x2_Icp_bias_w                                24
#define bitXVR_Reg0x2_Icp_bias_w                                0x7000000
#define set_XVR_Reg0x2_Icp_bias_w(val)                          addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x7000000)) | ((val) << 24))
#define get_XVR_Reg0x2_Icp_bias_w                               ((addXVR_Reg0x2 & 0x7000000) >> 24)

#define posXVR_Reg0x2_Icp_bias_n                                21
#define bitXVR_Reg0x2_Icp_bias_n                                0xE00000
#define set_XVR_Reg0x2_Icp_bias_n(val)                          addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0xE00000)) | ((val) << 21))
#define get_XVR_Reg0x2_Icp_bias_n                               ((addXVR_Reg0x2 & 0xE00000) >> 21)

#define posXVR_Reg0x2_openloop                                  20
#define bitXVR_Reg0x2_openloop                                  0x100000
#define set_XVR_Reg0x2_openloop(val)                            addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x100000)) | ((val) << 20))
#define setf_XVR_Reg0x2_openloop                                addXVR_Reg0x2 |= 0x100000
#define clrf_XVR_Reg0x2_openloop                                addXVR_Reg0x2 &= ~0x100000
#define get_XVR_Reg0x2_openloop                                 ((addXVR_Reg0x2 & 0x100000) >> 20)

#define posXVR_Reg0x2_int_mod                                   19
#define bitXVR_Reg0x2_int_mod                                   0x80000
#define set_XVR_Reg0x2_int_mod(val)                             addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x80000)) | ((val) << 19))
#define setf_XVR_Reg0x2_int_mod                                 addXVR_Reg0x2 |= 0x80000
#define clrf_XVR_Reg0x2_int_mod                                 addXVR_Reg0x2 &= ~0x80000
#define get_XVR_Reg0x2_int_mod                                  ((addXVR_Reg0x2 & 0x80000) >> 19)

#define posXVR_Reg0x2_lvref                                     17
#define bitXVR_Reg0x2_lvref                                     0x60000
#define set_XVR_Reg0x2_lvref(val)                               addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x60000)) | ((val) << 17))
#define get_XVR_Reg0x2_lvref                                    ((addXVR_Reg0x2 & 0x60000) >> 17)

#define posXVR_Reg0x2_hvref                                     15
#define bitXVR_Reg0x2_hvref                                     0x18000
#define set_XVR_Reg0x2_hvref(val)                               addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x18000)) | ((val) << 15))
#define get_XVR_Reg0x2_hvref                                    ((addXVR_Reg0x2 & 0x18000) >> 15)

#define posXVR_Reg0x2_errdet_spien                              14
#define bitXVR_Reg0x2_errdet_spien                              0x4000
#define set_XVR_Reg0x2_errdet_spien(val)                        addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x4000)) | ((val) << 14))
#define setf_XVR_Reg0x2_errdet_spien                            addXVR_Reg0x2 |= 0x4000
#define clrf_XVR_Reg0x2_errdet_spien                            addXVR_Reg0x2 &= ~0x4000
#define get_XVR_Reg0x2_errdet_spien                             ((addXVR_Reg0x2 & 0x4000) >> 14)

#define posXVR_Reg0x2_bandcal_spi                               4
#define bitXVR_Reg0x2_bandcal_spi                               0x3FF0
#define set_XVR_Reg0x2_bandcal_spi(val)                         addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x3FF0)) | ((val) << 4))
#define get_XVR_Reg0x2_bandcal_spi                              ((addXVR_Reg0x2 & 0x3FF0) >> 4)

#define posXVR_Reg0x2_manual_band                               3
#define bitXVR_Reg0x2_manual_band                               0x8
#define set_XVR_Reg0x2_manual_band(val)                         addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x8)) | ((val) << 3))
#define setf_XVR_Reg0x2_manual_band                             addXVR_Reg0x2 |= 0x8
#define clrf_XVR_Reg0x2_manual_band                             addXVR_Reg0x2 &= ~0x8
#define get_XVR_Reg0x2_manual_band                              ((addXVR_Reg0x2 & 0x8) >> 3)

#define posXVR_Reg0x2_cphalf_spi                                2
#define bitXVR_Reg0x2_cphalf_spi                                0x4
#define set_XVR_Reg0x2_cphalf_spi(val)                          addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x4)) | ((val) << 2))
#define setf_XVR_Reg0x2_cphalf_spi                              addXVR_Reg0x2 |= 0x4
#define clrf_XVR_Reg0x2_cphalf_spi                              addXVR_Reg0x2 &= ~0x4
#define get_XVR_Reg0x2_cphalf_spi                               ((addXVR_Reg0x2 & 0x4) >> 2)

#define posXVR_Reg0x2_pllen_spi_manual                          1
#define bitXVR_Reg0x2_pllen_spi_manual                          0x2
#define set_XVR_Reg0x2_pllen_spi_manual(val)                    addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x2)) | ((val) << 1))
#define setf_XVR_Reg0x2_pllen_spi_manual                        addXVR_Reg0x2 |= 0x2
#define clrf_XVR_Reg0x2_pllen_spi_manual                        addXVR_Reg0x2 &= ~0x2
#define get_XVR_Reg0x2_pllen_spi_manual                         ((addXVR_Reg0x2 & 0x2) >> 1)

#define posXVR_Reg0x2_pllen_spi                                 0
#define bitXVR_Reg0x2_pllen_spi                                 0x1
#define set_XVR_Reg0x2_pllen_spi(val)                           addXVR_Reg0x2 = ((addXVR_Reg0x2 & (~0x1)) | ((val) << 0))
#define setf_XVR_Reg0x2_pllen_spi                               addXVR_Reg0x2 |= 0x1
#define clrf_XVR_Reg0x2_pllen_spi                               addXVR_Reg0x2 &= ~0x1
#define get_XVR_Reg0x2_pllen_spi                                (addXVR_Reg0x2 & 0x1)

//addXVR_Reg0x3
#define addXVR_Reg0x3                                           *((volatile unsigned long *) (0x00806E00+0x3*4))

#define posXVR_Reg0x3_ampsel                                    8
#define bitXVR_Reg0x3_ampsel                                    0x700
#define set_XVR_Reg0x3_ampsel(val)                              addXVR_Reg0x3 = ((addXVR_Reg0x3 & (~0x700)) | ((val) << 8))
#define get_XVR_Reg0x3_ampsel                                   ((addXVR_Reg0x3 & 0x700) >> 8)

#define posXVR_Reg0x3_bandcal_bypass                            7
#define bitXVR_Reg0x3_bandcal_bypass                            0x80
#define set_XVR_Reg0x3_bandcal_bypass(val)                      addXVR_Reg0x3 = ((addXVR_Reg0x3 & (~0x80)) | ((val) << 7))
#define setf_XVR_Reg0x3_bandcal_bypass                          addXVR_Reg0x3 |= 0x80
#define clrf_XVR_Reg0x3_bandcal_bypass                          addXVR_Reg0x3 &= ~0x80
#define get_XVR_Reg0x3_bandcal_bypass                           ((addXVR_Reg0x3 & 0x80) >> 7)

#define posXVR_Reg0x3_caldone_spi                               6
#define bitXVR_Reg0x3_caldone_spi                               0x40
#define set_XVR_Reg0x3_caldone_spi(val)                         addXVR_Reg0x3 = ((addXVR_Reg0x3 & (~0x40)) | ((val) << 6))
#define setf_XVR_Reg0x3_caldone_spi                             addXVR_Reg0x3 |= 0x40
#define clrf_XVR_Reg0x3_caldone_spi                             addXVR_Reg0x3 &= ~0x40
#define get_XVR_Reg0x3_caldone_spi                              ((addXVR_Reg0x3 & 0x40) >> 6)

#define posXVR_Reg0x3_rxvcoen_spi                               5
#define bitXVR_Reg0x3_rxvcoen_spi                               0x20
#define set_XVR_Reg0x3_rxvcoen_spi(val)                         addXVR_Reg0x3 = ((addXVR_Reg0x3 & (~0x20)) | ((val) << 5))
#define setf_XVR_Reg0x3_rxvcoen_spi                             addXVR_Reg0x3 |= 0x20
#define clrf_XVR_Reg0x3_rxvcoen_spi                             addXVR_Reg0x3 &= ~0x20
#define get_XVR_Reg0x3_rxvcoen_spi                              ((addXVR_Reg0x3 & 0x20) >> 5)

#define posXVR_Reg0x3_rxvcoen_manual                            4
#define bitXVR_Reg0x3_rxvcoen_manual                            0x10
#define set_XVR_Reg0x3_rxvcoen_manual(val)                      addXVR_Reg0x3 = ((addXVR_Reg0x3 & (~0x10)) | ((val) << 4))
#define setf_XVR_Reg0x3_rxvcoen_manual                          addXVR_Reg0x3 |= 0x10
#define clrf_XVR_Reg0x3_rxvcoen_manual                          addXVR_Reg0x3 &= ~0x10
#define get_XVR_Reg0x3_rxvcoen_manual                           ((addXVR_Reg0x3 & 0x10) >> 4)

#define posXVR_Reg0x3_vbiasctrl                                 3
#define bitXVR_Reg0x3_vbiasctrl                                 0x8
#define set_XVR_Reg0x3_vbiasctrl(val)                           addXVR_Reg0x3 = ((addXVR_Reg0x3 & (~0x8)) | ((val) << 3))
#define setf_XVR_Reg0x3_vbiasctrl                               addXVR_Reg0x3 |= 0x8
#define clrf_XVR_Reg0x3_vbiasctrl                               addXVR_Reg0x3 &= ~0x8
#define get_XVR_Reg0x3_vbiasctrl                                ((addXVR_Reg0x3 & 0x8) >> 3)

#define posXVR_Reg0x3_bypass_opt                                2
#define bitXVR_Reg0x3_bypass_opt                                0x4
#define set_XVR_Reg0x3_bypass_opt(val)                          addXVR_Reg0x3 = ((addXVR_Reg0x3 & (~0x4)) | ((val) << 2))
#define setf_XVR_Reg0x3_bypass_opt                              addXVR_Reg0x3 |= 0x4
#define clrf_XVR_Reg0x3_bypass_opt                              addXVR_Reg0x3 &= ~0x4
#define get_XVR_Reg0x3_bypass_opt                               ((addXVR_Reg0x3 & 0x4) >> 2)

#define posXVR_Reg0x3_ampautocal                                1
#define bitXVR_Reg0x3_ampautocal                                0x2
#define set_XVR_Reg0x3_ampautocal(val)                          addXVR_Reg0x3 = ((addXVR_Reg0x3 & (~0x2)) | ((val) << 1))
#define setf_XVR_Reg0x3_ampautocal                              addXVR_Reg0x3 |= 0x2
#define clrf_XVR_Reg0x3_ampautocal                              addXVR_Reg0x3 &= ~0x2
#define get_XVR_Reg0x3_ampautocal                               ((addXVR_Reg0x3 & 0x2) >> 1)

#define posXVR_Reg0x3_amptrigger                                0
#define bitXVR_Reg0x3_amptrigger                                0x1
#define set_XVR_Reg0x3_amptrigger(val)                          addXVR_Reg0x3 = ((addXVR_Reg0x3 & (~0x1)) | ((val) << 0))
#define setf_XVR_Reg0x3_amptrigger                              addXVR_Reg0x3 |= 0x1
#define clrf_XVR_Reg0x3_amptrigger                              addXVR_Reg0x3 &= ~0x1
#define get_XVR_Reg0x3_amptrigger                               (addXVR_Reg0x3 & 0x1)

//addXVR_Reg0x4
#define addXVR_Reg0x4                                           *((volatile unsigned long *) (0x00806E00+0x4*4))
#define posXVR_Reg0x4_PABufRampEn                               31
#define bitXVR_Reg0x4_PABufRampEn                               0x80000000
#define set_XVR_Reg0x4_PABufRampEn(val)                         addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x80000000)) | ((val) << 31))
#define setf_XVR_Reg0x4_PABufRampEn                             addXVR_Reg0x4 |= 0x80000000
#define clrf_XVR_Reg0x4_PABufRampEn                             addXVR_Reg0x4 &= ~0x80000000
#define get_XVR_Reg0x4_PABufRampEn                              ((addXVR_Reg0x4 & 0x80000000) >> 31)

#define posXVR_Reg0x4_gPAbuf                                    30
#define bitXVR_Reg0x4_gPAbuf                                    0x40000000
#define set_XVR_Reg0x4_gPAbuf(val)                              addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x40000000)) | ((val) << 30))
#define setf_XVR_Reg0x4_gPAbuf                                  addXVR_Reg0x4 |= 0x40000000
#define clrf_XVR_Reg0x4_gPAbuf                                  addXVR_Reg0x4 &= ~0x40000000
#define get_XVR_Reg0x4_gPAbuf                                   ((addXVR_Reg0x4 & 0x40000000) >> 30)

#define posXVR_Reg0x4_gPAdspEn                                  29
#define bitXVR_Reg0x4_gPAdspEn                                  0x20000000
#define set_XVR_Reg0x4_gPAdspEn(val)                            addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x20000000)) | ((val) << 29))
#define setf_XVR_Reg0x4_gPAdspEn                                addXVR_Reg0x4 |= 0x20000000
#define clrf_XVR_Reg0x4_gPAdspEn                                addXVR_Reg0x4 &= ~0x20000000
#define get_XVR_Reg0x4_gPAdspEn                                 ((addXVR_Reg0x4 & 0x20000000) >> 29)

#define posXVR_Reg0x4_gPAspi                                    24
#define bitXVR_Reg0x4_gPAspi                                    0x1F000000
#define set_XVR_Reg0x4_gPAspi(val)                              addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x1F000000)) | ((val) << 24))
#define get_XVR_Reg0x4_gPAspi                                   ((addXVR_Reg0x4 & 0x1F000000) >> 24)

#define posXVR_Reg0x4_PAvbpSel                                  21
#define bitXVR_Reg0x4_PAvbpSel                                  0xE00000
#define set_XVR_Reg0x4_PAvbpSel(val)                            addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0xE00000)) | ((val) << 21))
#define get_XVR_Reg0x4_PAvbpSel                                 ((addXVR_Reg0x4 & 0xE00000) >> 21)

#define posXVR_Reg0x4_PAvbnSel                                  18
#define bitXVR_Reg0x4_PAvbnSel                                  0x1C0000
#define set_XVR_Reg0x4_PAvbnSel(val)                            addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x1C0000)) | ((val) << 18))
#define get_XVR_Reg0x4_PAvbnSel                                 ((addXVR_Reg0x4 & 0x1C0000) >> 18)

#define posXVR_Reg0x4_PAldoVsel                                 16
#define bitXVR_Reg0x4_PAldoVsel                                 0x30000
#define set_XVR_Reg0x4_PAldoVsel(val)                           addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x30000)) | ((val) << 16))
#define get_XVR_Reg0x4_PAldoVsel                                ((addXVR_Reg0x4 & 0x30000) >> 16)

#define posXVR_Reg0x4_PAbufldoVsel                              14
#define bitXVR_Reg0x4_PAbufldoVsel                              0xC000
#define set_XVR_Reg0x4_PAbufldoVsel(val)                        addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0xC000)) | ((val) << 14))
#define get_XVR_Reg0x4_PAbufldoVsel                             ((addXVR_Reg0x4 & 0xC000) >> 14)

#define posXVR_Reg0x4_TrxVcoldoVsel                             12
#define bitXVR_Reg0x4_TrxVcoldoVsel                             0x3000
#define set_XVR_Reg0x4_TrxVcoldoVsel(val)                       addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x3000)) | ((val) << 12))
#define get_XVR_Reg0x4_TrxVcoldoVsel                            ((addXVR_Reg0x4 & 0x3000) >> 12)

#define posXVR_Reg0x4_TrxLOVldoVsel                             10
#define bitXVR_Reg0x4_TrxLOVldoVsel                             0xC00
#define set_XVR_Reg0x4_TrxLOVldoVsel(val)                       addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0xC00)) | ((val) << 10))
#define get_XVR_Reg0x4_TrxLOVldoVsel                            ((addXVR_Reg0x4 & 0xC00) >> 10)

#define posXVR_Reg0x4_ForeceOnTxLObuf                           9
#define bitXVR_Reg0x4_ForeceOnTxLObuf                           0x200
#define set_XVR_Reg0x4_ForeceOnTxLObuf(val)                     addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x200)) | ((val) << 9))
#define setf_XVR_Reg0x4_ForeceOnTxLObuf                         addXVR_Reg0x4 |= 0x200
#define clrf_XVR_Reg0x4_ForeceOnTxLObuf                         addXVR_Reg0x4 &= ~0x200
#define get_XVR_Reg0x4_ForeceOnTxLObuf                          ((addXVR_Reg0x4 & 0x200) >> 9)

#define posXVR_Reg0x4_pwd_bgbuf_dc                              8
#define bitXVR_Reg0x4_pwd_bgbuf_dc                              0x100
#define set_XVR_Reg0x4_pwd_bgbuf_dc(val)                        addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x100)) | ((val) << 8))
#define setf_XVR_Reg0x4_pwd_bgbuf_dc                            addXVR_Reg0x4 |= 0x100
#define clrf_XVR_Reg0x4_pwd_bgbuf_dc                            addXVR_Reg0x4 &= ~0x100
#define get_XVR_Reg0x4_pwd_bgbuf_dc                             ((addXVR_Reg0x4 & 0x100) >> 8)

#define posXVR_Reg0x4_pwd_bg_dc                                 7
#define bitXVR_Reg0x4_pwd_bg_dc                                 0x80
#define set_XVR_Reg0x4_pwd_bg_dc(val)                           addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x80)) | ((val) << 7))
#define setf_XVR_Reg0x4_pwd_bg_dc                               addXVR_Reg0x4 |= 0x80
#define clrf_XVR_Reg0x4_pwd_bg_dc                               addXVR_Reg0x4 &= ~0x80
#define get_XVR_Reg0x4_pwd_bg_dc                                ((addXVR_Reg0x4 & 0x80) >> 7)

#define posXVR_Reg0x4_TxIFldoVsel                               5
#define bitXVR_Reg0x4_TxIFldoVsel                               0x60
#define set_XVR_Reg0x4_TxIFldoVsel(val)                         addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x60)) | ((val) << 5))
#define get_XVR_Reg0x4_TxIFldoVsel                              ((addXVR_Reg0x4 & 0x60) >> 5)

#define posXVR_Reg0x4_RxAGCspi                                  2
#define bitXVR_Reg0x4_RxAGCspi                                  0x1C
#define set_XVR_Reg0x4_RxAGCspi(val)                            addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x1C)) | ((val) << 2))
#define get_XVR_Reg0x4_RxAGCspi                                 ((addXVR_Reg0x4 & 0x1C) >> 2)

#define posXVR_Reg0x4_ctune_pa                                  0
#define bitXVR_Reg0x4_ctune_pa                                  0x3
#define set_XVR_Reg0x4_ctune_pa(val)                            addXVR_Reg0x4 = ((addXVR_Reg0x4 & (~0x3)) | ((val) << 0))
#define get_XVR_Reg0x4_ctune_pa                                 (addXVR_Reg0x4 & 0x3)

//addXVR_Reg0x5
#define addXVR_Reg0x5                                           *((volatile unsigned long *) (0x00806E00+0x5*4))
#define posXVR_Reg0x5_txif_atsten                               31
#define bitXVR_Reg0x5_txif_atsten                               0x80000000
#define set_XVR_Reg0x5_txif_atsten(val)                         addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x80000000)) | ((val) << 31))
#define setf_XVR_Reg0x5_txif_atsten                             addXVR_Reg0x5 |= 0x80000000
#define clrf_XVR_Reg0x5_txif_atsten                             addXVR_Reg0x5 &= ~0x80000000
#define get_XVR_Reg0x5_txif_atsten                              ((addXVR_Reg0x5 & 0x80000000) >> 31)

#define posXVR_Reg0x5_txif_modinv                               30
#define bitXVR_Reg0x5_txif_modinv                               0x40000000
#define set_XVR_Reg0x5_txif_modinv(val)                         addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x40000000)) | ((val) << 30))
#define setf_XVR_Reg0x5_txif_modinv                             addXVR_Reg0x5 |= 0x40000000
#define clrf_XVR_Reg0x5_txif_modinv                             addXVR_Reg0x5 &= ~0x40000000
#define get_XVR_Reg0x5_txif_modinv                              ((addXVR_Reg0x5 & 0x40000000) >> 30)

#define posXVR_Reg0x5_txif_modTen                               29
#define bitXVR_Reg0x5_txif_modTen                               0x20000000
#define set_XVR_Reg0x5_txif_modTen(val)                         addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x20000000)) | ((val) << 29))
#define setf_XVR_Reg0x5_txif_modTen                             addXVR_Reg0x5 |= 0x20000000
#define clrf_XVR_Reg0x5_txif_modTen                             addXVR_Reg0x5 &= ~0x20000000
#define get_XVR_Reg0x5_txif_modTen                              ((addXVR_Reg0x5 & 0x20000000) >> 29)

#define posXVR_Reg0x5_txif_modT10                               28
#define bitXVR_Reg0x5_txif_modT10                               0x10000000
#define set_XVR_Reg0x5_txif_modT10(val)                         addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x10000000)) | ((val) << 28))
#define setf_XVR_Reg0x5_txif_modT10                             addXVR_Reg0x5 |= 0x10000000
#define clrf_XVR_Reg0x5_txif_modT10                             addXVR_Reg0x5 &= ~0x10000000
#define get_XVR_Reg0x5_txif_modT10                              ((addXVR_Reg0x5 & 0x10000000) >> 28)

#define posXVR_Reg0x5_txif_modCtr                               24
#define bitXVR_Reg0x5_txif_modCtr                               0xF000000
#define set_XVR_Reg0x5_txif_modCtr(val)                         addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0xF000000)) | ((val) << 24))
#define get_XVR_Reg0x5_txif_modCtr                              ((addXVR_Reg0x5 & 0xF000000) >> 24)

#define posXVR_Reg0x5_txif_vcm                                  21
#define bitXVR_Reg0x5_txif_vcm                                  0xE00000
#define set_XVR_Reg0x5_txif_vcm(val)                            addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0xE00000)) | ((val) << 21))
#define get_XVR_Reg0x5_txif_vcm                                 ((addXVR_Reg0x5 & 0xE00000) >> 21)

#define posXVR_Reg0x5_bypass_txflt                              20
#define bitXVR_Reg0x5_bypass_txflt                              0xF00000
#define set_XVR_Reg0x5_bypass_txflt(val)                        addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0xF00000)) | ((val) << 20))
#define get_XVR_Reg0x5_bypass_txflt                             ((addXVR_Reg0x5 & 0xF00000) >> 20)

#define posXVR_Reg0x5_done_delay                                17
#define bitXVR_Reg0x5_done_delay                                0xE0000
#define set_XVR_Reg0x5_done_delay(val)                          addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0xE0000)) | ((val) << 17))
#define get_XVR_Reg0x5_done_delay                               ((addXVR_Reg0x5 & 0xE0000) >> 17)

#define posXVR_Reg0x5_gspien                                    16
#define bitXVR_Reg0x5_gspien                                    0x10000
#define set_XVR_Reg0x5_gspien(val)                              addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x10000)) | ((val) << 16))
#define setf_XVR_Reg0x5_gspien                                  addXVR_Reg0x5 |= 0x10000
#define clrf_XVR_Reg0x5_gspien                                  addXVR_Reg0x5 &= ~0x10000
#define get_XVR_Reg0x5_gspien                                   ((addXVR_Reg0x5 & 0x10000) >> 16)

#define posXVR_Reg0x5_en_lim                                    15
#define bitXVR_Reg0x5_en_lim                                    0x8000
#define set_XVR_Reg0x5_en_lim(val)                              addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x8000)) | ((val) << 15))
#define setf_XVR_Reg0x5_en_lim                                  addXVR_Reg0x5 |= 0x8000
#define clrf_XVR_Reg0x5_en_lim                                  addXVR_Reg0x5 &= ~0x8000
#define get_XVR_Reg0x5_en_lim                                   ((addXVR_Reg0x5 & 0x8000) >> 15)


#define posXVR_Reg0x5_LNAldoVsel                                12
#define bitXVR_Reg0x5_LNAldoVsel                                0x3000
#define set_XVR_Reg0x5_LNAldoVsel(val)                          addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x3000)) | ((val) << 12))
#define get_XVR_Reg0x5_LNAldoVsel                               ((addXVR_Reg0x5 & 0x3000) >> 12)

#define posXVR_Reg0x5_dLoopldoVsel                              10
#define bitXVR_Reg0x5_dLoopldoVsel                              0xC00
#define set_XVR_Reg0x5_dLoopldoVsel(val)                        addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0xC00)) | ((val) << 10))
#define get_XVR_Reg0x5_dLoopldoVsel                             ((addXVR_Reg0x5 & 0xC00) >> 10)

#define posXVR_Reg0x5_aLoopldoVsel                              8
#define bitXVR_Reg0x5_aLoopldoVsel                              0x300
#define set_XVR_Reg0x5_aLoopldoVsel(val)                        addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x300)) | ((val) << 8))
#define get_XVR_Reg0x5_aLoopldoVsel                             ((addXVR_Reg0x5 & 0x300) >> 8)

#define posXVR_Reg0x5_Gcpga                                     4
#define bitXVR_Reg0x5_Gcpga                                     0xF0
#define set_XVR_Reg0x5_Gcpga(val)                               addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0xF0)) | ((val) << 4))
#define get_XVR_Reg0x5_Gcpga                                    ((addXVR_Reg0x5 & 0xF0) >> 4)

#define posXVR_Reg0x5_pwdIFADC1V_I_spi                          3
#define bitXVR_Reg0x5_pwdIFADC1V_I_spi                          0x8
#define set_XVR_Reg0x5_pwdIFADC1V_I_spi(val)                    addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x8)) | ((val) << 3))
#define setf_XVR_Reg0x5_pwdIFADC1V_I_spi                        addXVR_Reg0x5 |= 0x8
#define clrf_XVR_Reg0x5_pwdIFADC1V_I_spi                        addXVR_Reg0x5 &= ~0x8
#define get_XVR_Reg0x5_pwdIFADC1V_I_spi                         ((addXVR_Reg0x5 & 0x8) >> 3)

#define posXVR_Reg0x5_pwdIFADC1V_Q_spi                          2
#define bitXVR_Reg0x5_pwdIFADC1V_Q_spi                          0x4
#define set_XVR_Reg0x5_pwdIFADC1V_Q_spi(val)                    addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x4)) | ((val) << 2))
#define setf_XVR_Reg0x5_pwdIFADC1V_Q_spi                        addXVR_Reg0x5 |= 0x4
#define clrf_XVR_Reg0x5_pwdIFADC1V_Q_spi                        addXVR_Reg0x5 &= ~0x4
#define get_XVR_Reg0x5_pwdIFADC1V_Q_spi                         ((addXVR_Reg0x5 & 0x4) >> 2)

#define posXVR_Reg0x5_ifadcpwd_bypass_I                         1
#define bitXVR_Reg0x5_ifadcpwd_bypass_I                         0x2
#define set_XVR_Reg0x5_ifadcpwd_bypass_I(val)                   addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x2)) | ((val) << 1))
#define setf_XVR_Reg0x5_ifadcpwd_bypass_I                       addXVR_Reg0x5 |= 0x2
#define clrf_XVR_Reg0x5_ifadcpwd_bypass_I                       addXVR_Reg0x5 &= ~0x2
#define get_XVR_Reg0x5_ifadcpwd_bypass_I                        ((addXVR_Reg0x5 & 0x2) >> 1)

#define posXVR_Reg0x5_ifadcpwd_bypass_Q                         0
#define bitXVR_Reg0x5_ifadcpwd_bypass_Q                         0x1
#define set_XVR_Reg0x5_ifadcpwd_bypass_Q(val)                   addXVR_Reg0x5 = ((addXVR_Reg0x5 & (~0x1)) | ((val) << 0))
#define setf_XVR_Reg0x5_ifadcpwd_bypass_Q                       addXVR_Reg0x5 |= 0x1
#define clrf_XVR_Reg0x5_ifadcpwd_bypass_Q                       addXVR_Reg0x5 &= ~0x1
#define get_XVR_Reg0x5_ifadcpwd_bypass_Q                        (addXVR_Reg0x5 & 0x1)

//addXVR_Reg0x6
#define addXVR_Reg0x6                                           *((volatile unsigned long *) (0x00806E00+0x6*4))
#define posXVR_Reg0x6_ictrlm_lna                                29
#define bitXVR_Reg0x6_ictrlm_lna                                0xE0000000
#define set_XVR_Reg0x6_ictrlm_lna(val)                          addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0xE0000000)) | ((val) << 29))
#define get_XVR_Reg0x6_ictrlm_lna                               ((addXVR_Reg0x6 & 0xE0000000) >> 29)

#define posXVR_Reg0x6_RxFE_tsten                                28
#define bitXVR_Reg0x6_RxFE_tsten                                0x10000000
#define set_XVR_Reg0x6_RxFE_tsten(val)                          addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0x10000000)) | ((val) << 28))
#define setf_XVR_Reg0x6_RxFE_tsten                              addXVR_Reg0x6 |= 0x10000000
#define clrf_XVR_Reg0x6_RxFE_tsten                              addXVR_Reg0x6 &= ~0x10000000
#define get_XVR_Reg0x6_RxFE_tsten                               ((addXVR_Reg0x6 & 0x10000000) >> 28)

#define posXVR_Reg0x6_ctune_lna                                 25
#define bitXVR_Reg0x6_ctune_lna                                 0xE000000
#define set_XVR_Reg0x6_ctune_lna(val)                           addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0xE000000)) | ((val) << 25))
#define get_XVR_Reg0x6_ctune_lna                                ((addXVR_Reg0x6 & 0xE000000) >> 25)

#define posXVR_Reg0x6_ictrl_lna                                 22
#define bitXVR_Reg0x6_ictrl_lna                                 0x1C00000
#define set_XVR_Reg0x6_ictrl_lna(val)                           addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0x1C00000)) | ((val) << 22))
#define get_XVR_Reg0x6_ictrl_lna                                ((addXVR_Reg0x6 & 0x1C00000) >> 22)

#define posXVR_Reg0x6_ictrl_mix                                 20
#define bitXVR_Reg0x6_ictrl_mix                                 0x300000
#define set_XVR_Reg0x6_ictrl_mix(val)                           addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0x300000)) | ((val) << 20))
#define get_XVR_Reg0x6_ictrl_mix                                ((addXVR_Reg0x6 & 0x300000) >> 20)

#define posXVR_Reg0x6_ictrl_i2v                                 18
#define bitXVR_Reg0x6_ictrl_i2v                                 0xC0000
#define set_XVR_Reg0x6_ictrl_i2v(val)                           addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0xC0000)) | ((val) << 18))
#define get_XVR_Reg0x6_ictrl_i2v                                ((addXVR_Reg0x6 & 0xC0000) >> 18)

#define posXVR_Reg0x6_gctrl_i2v                                 16
#define bitXVR_Reg0x6_gctrl_i2v                                 0x30000
#define set_XVR_Reg0x6_gctrl_i2v(val)                           addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0x30000)) | ((val) << 16))
#define get_XVR_Reg0x6_gctrl_i2v                                ((addXVR_Reg0x6 & 0x30000) >> 16)

#define posXVR_Reg0x6_vgsel_mix                                 14
#define bitXVR_Reg0x6_vgsel_mix                                 0xC000
#define set_XVR_Reg0x6_vgsel_mix(val)                           addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0xC000)) | ((val) << 14))
#define get_XVR_Reg0x6_vgsel_mix                                ((addXVR_Reg0x6 & 0xC000) >> 14)

#define posXVR_Reg0x6_DVthH_RSSIRF                              11
#define bitXVR_Reg0x6_DVthH_RSSIRF                              0x3800
#define set_XVR_Reg0x6_DVthH_RSSIRF(val)                        addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0x3800)) | ((val) << 11))
#define get_XVR_Reg0x6_DVthH_RSSIRF                             ((addXVR_Reg0x6 & 0x3800) >> 11)

#define posXVR_Reg0x6_DVthL_RSSIRF                              8
#define bitXVR_Reg0x6_DVthL_RSSIRF                              0x700
#define set_XVR_Reg0x6_DVthL_RSSIRF(val)                        addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0x700)) | ((val) << 8))
#define get_XVR_Reg0x6_DVthL_RSSIRF                             ((addXVR_Reg0x6 & 0x700) >> 8)

#define posXVR_Reg0x6_gadc_tstsel                               5
#define bitXVR_Reg0x6_gadc_tstsel                               0xE0
#define set_XVR_Reg0x6_gadc_tstsel(val)                         addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0xE0)) | ((val) << 5))
#define get_XVR_Reg0x6_gadc_tstsel                              ((addXVR_Reg0x6 & 0xE0) >> 5)

#define posXVR_Reg0x6_gadc_vbgsw                                4
#define bitXVR_Reg0x6_gadc_vbgsw                                0x10
#define set_XVR_Reg0x6_gadc_vbgsw(val)                          addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0x10)) | ((val) << 4))
#define setf_XVR_Reg0x6_gadc_vbgsw                              addXVR_Reg0x6 |= 0x10
#define clrf_XVR_Reg0x6_gadc_vbgsw                              addXVR_Reg0x6 &= ~0x10
#define get_XVR_Reg0x6_gadc_vbgsw                               ((addXVR_Reg0x6 & 0x10) >> 4)

#define posXVR_Reg0x6_gadc_dc_calen                             3
#define bitXVR_Reg0x6_gadc_dc_calen                             0x8
#define set_XVR_Reg0x6_gadc_dc_calen(val)                       addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0x8)) | ((val) << 3))
#define setf_XVR_Reg0x6_gadc_dc_calen                           addXVR_Reg0x6 |= 0x8
#define clrf_XVR_Reg0x6_gadc_dc_calen                           addXVR_Reg0x6 &= ~0x8
#define get_XVR_Reg0x6_gadc_dc_calen                            ((addXVR_Reg0x6 & 0x8) >> 3)

#define posXVR_Reg0x6_EnAtt                                     2
#define bitXVR_Reg0x6_EnAtt                                     0x4
#define set_XVR_Reg0x6_EnAtt(val)                               addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0x4)) | ((val) << 2))
#define setf_XVR_Reg0x6_EnAtt                                   addXVR_Reg0x6 |= 0x4
#define clrf_XVR_Reg0x6_EnAtt                                   addXVR_Reg0x6 &= ~0x4
#define get_XVR_Reg0x6_EnAtt                                    ((addXVR_Reg0x6 & 0x4) >> 2)

#define posXVR_Reg0x6_tsten_gadc                                1
#define bitXVR_Reg0x6_tsten_gadc                                0x2
#define set_XVR_Reg0x6_tsten_gadc(val)                          addXVR_Reg0x6 = ((addXVR_Reg0x6 & (~0x2)) | ((val) << 1))
#define setf_XVR_Reg0x6_tsten_gadc                              addXVR_Reg0x6 |= 0x2
#define clrf_XVR_Reg0x6_tsten_gadc                              addXVR_Reg0x6 &= ~0x2
#define get_XVR_Reg0x6_tsten_gadc                               ((addXVR_Reg0x6 & 0x2) >> 1)


//addXVR_Reg0x7
#define addXVR_Reg0x7                                           *((volatile unsigned long *) (0x00806E00+0x7*4))
#define posXVR_Reg0x7_digtstEn                                  31
#define bitXVR_Reg0x7_digtstEn                                  0x80000000
#define set_XVR_Reg0x7_digtstEn(val)                            addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x80000000)) | ((val) << 31))
#define setf_XVR_Reg0x7_digtstEn                                addXVR_Reg0x7 |= 0x80000000
#define clrf_XVR_Reg0x7_digtstEn                                addXVR_Reg0x7 &= ~0x80000000
#define get_XVR_Reg0x7_digtstEn                                 ((addXVR_Reg0x7 & 0x80000000) >> 31)

#define posXVR_Reg0x7_dittstSel                                 30
#define bitXVR_Reg0x7_dittstSel                                 0x40000000
#define set_XVR_Reg0x7_dittstSel(val)                           addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x40000000)) | ((val) << 30))
#define setf_XVR_Reg0x7_dittstSel                               addXVR_Reg0x7 |= 0x40000000
#define clrf_XVR_Reg0x7_dittstSel                               addXVR_Reg0x7 &= ~0x40000000
#define get_XVR_Reg0x7_dittstSel                                ((addXVR_Reg0x7 & 0x40000000) >> 30)

#define posXVR_Reg0x7_atSel                                     27
#define bitXVR_Reg0x7_atSel                                     0x38000000
#define set_XVR_Reg0x7_atSel(val)                               addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x38000000)) | ((val) << 27))
#define get_XVR_Reg0x7_atSel                                    ((addXVR_Reg0x7 & 0x38000000) >> 27)

#define posXVR_Reg0x7_reftsten                                  26
#define bitXVR_Reg0x7_reftsten                                  0x4000000
#define set_XVR_Reg0x7_reftsten(val)                            addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x4000000)) | ((val) << 26))
#define setf_XVR_Reg0x7_reftsten                                addXVR_Reg0x7 |= 0x4000000
#define clrf_XVR_Reg0x7_reftsten                                addXVR_Reg0x7 &= ~0x4000000
#define get_XVR_Reg0x7_reftsten                                 ((addXVR_Reg0x7 & 0x4000000) >> 26)

#define posXVR_Reg0x7_fCaliPwd                                  25
#define bitXVR_Reg0x7_fCaliPwd                                  0x2000000
#define set_XVR_Reg0x7_fCaliPwd(val)                            addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x2000000)) | ((val) << 25))
#define setf_XVR_Reg0x7_fCaliPwd                                addXVR_Reg0x7 |= 0x2000000
#define clrf_XVR_Reg0x7_fCaliPwd                                addXVR_Reg0x7 &= ~0x2000000
#define get_XVR_Reg0x7_fCaliPwd                                 ((addXVR_Reg0x7 & 0x2000000) >> 25)

#define posXVR_Reg0x7_fTrimMode                                 24
#define bitXVR_Reg0x7_fTrimMode                                 0x1000000
#define set_XVR_Reg0x7_fTrimMode(val)                           addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x1000000)) | ((val) << 24))
#define setf_XVR_Reg0x7_fTrimMode                               addXVR_Reg0x7 |= 0x1000000
#define clrf_XVR_Reg0x7_fTrimMode                               addXVR_Reg0x7 &= ~0x1000000
#define get_XVR_Reg0x7_fTrimMode                                ((addXVR_Reg0x7 & 0x1000000) >> 24)

#define posXVR_Reg0x7_trim                                      19
#define bitXVR_Reg0x7_trim                                      0xF80000
#define set_XVR_Reg0x7_trim(val)                                addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0xF80000)) | ((val) << 19))
#define get_XVR_Reg0x7_trim                                     ((addXVR_Reg0x7 & 0xF80000) >> 19)

#define posXVR_Reg0x7_pwdfCaliEn                                18
#define bitXVR_Reg0x7_pwdfCaliEn                                0x40000
#define set_XVR_Reg0x7_pwdfCaliEn(val)                          addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x40000)) | ((val) << 18))
#define setf_XVR_Reg0x7_pwdfCaliEn                              addXVR_Reg0x7 |= 0x40000
#define clrf_XVR_Reg0x7_pwdfCaliEn                              addXVR_Reg0x7 &= ~0x40000
#define get_XVR_Reg0x7_pwdfCaliEn                               ((addXVR_Reg0x7 & 0x40000) >> 18)

#define posXVR_Reg0x7_xtal16M_captune                           14
#define bitXVR_Reg0x7_xtal16M_captune                           0x3C000
#define set_XVR_Reg0x7_xtal16M_captune(val)                     addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x3C000)) | ((val) << 14))
#define get_XVR_Reg0x7_xtal16M_captune                          ((addXVR_Reg0x7 & 0x3C000) >> 14)

#define posXVR_Reg0x7_xtal16M_amptune                           10
#define bitXVR_Reg0x7_xtal16M_amptune                           0x3C00
#define set_XVR_Reg0x7_xtal16M_amptune(val)                     addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x3C00)) | ((val) << 10))
#define get_XVR_Reg0x7_xtal16M_amptune                          ((addXVR_Reg0x7 & 0x3C00) >> 10)

#define posXVR_Reg0x7_bypassb_ckdig_enb                         9
#define bitXVR_Reg0x7_bypassb_ckdig_enb                         0x200
#define set_XVR_Reg0x7_bypassb_ckdig_enb(val)                   addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x200)) | ((val) << 9))
#define setf_XVR_Reg0x7_bypassb_ckdig_enb                       addXVR_Reg0x7 |= 0x200
#define clrf_XVR_Reg0x7_bypassb_ckdig_enb                       addXVR_Reg0x7 &= ~0x200
#define get_XVR_Reg0x7_bypassb_ckdig_enb                        ((addXVR_Reg0x7 & 0x200) >> 9)

#define posXVR_Reg0x7_XtalAmp                                   6
#define bitXVR_Reg0x7_XtalAmp                                   0x1C0
#define set_XVR_Reg0x7_XtalAmp(val)                             addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x1C0)) | ((val) << 6))
#define get_XVR_Reg0x7_XtalAmp                                  ((addXVR_Reg0x7 & 0x1C0) >> 6)

#define posXVR_Reg0x7_Xtal16MEn2                                5
#define bitXVR_Reg0x7_Xtal16MEn2                                0x20
#define set_XVR_Reg0x7_Xtal16MEn2(val)                          addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x20)) | ((val) << 5))
#define setf_XVR_Reg0x7_Xtal16MEn2                              addXVR_Reg0x7 |= 0x20
#define clrf_XVR_Reg0x7_Xtal16MEn2                              addXVR_Reg0x7 &= ~0x20
#define get_XVR_Reg0x7_Xtal16MEn2                               ((addXVR_Reg0x7 & 0x20) >> 5)

#define posXVR_Reg0x7_SpipwdCKpllbuf                            4
#define bitXVR_Reg0x7_SpipwdCKpllbuf                            0x10
#define set_XVR_Reg0x7_SpipwdCKpllbuf(val)                      addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x10)) | ((val) << 4))
#define setf_XVR_Reg0x7_SpipwdCKpllbuf                          addXVR_Reg0x7 |= 0x10
#define clrf_XVR_Reg0x7_SpipwdCKpllbuf                          addXVR_Reg0x7 &= ~0x10
#define get_XVR_Reg0x7_SpipwdCKpllbuf                           ((addXVR_Reg0x7 & 0x10) >> 4)

#define posXVR_Reg0x7_AutopwdCKpllbuf                           3
#define bitXVR_Reg0x7_AutopwdCKpllbuf                           0x8
#define set_XVR_Reg0x7_AutopwdCKpllbuf(val)                     addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x8)) | ((val) << 3))
#define setf_XVR_Reg0x7_AutopwdCKpllbuf                         addXVR_Reg0x7 |= 0x8
#define clrf_XVR_Reg0x7_AutopwdCKpllbuf                         addXVR_Reg0x7 &= ~0x8
#define get_XVR_Reg0x7_AutopwdCKpllbuf                          ((addXVR_Reg0x7 & 0x8) >> 3)

#define posXVR_Reg0x7_ifIQswap                                  2
#define bitXVR_Reg0x7_ifIQswap                                  0x4
#define set_XVR_Reg0x7_ifIQswap(val)                            addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x4)) | ((val) << 2))
#define setf_XVR_Reg0x7_ifIQswap                                addXVR_Reg0x7 |= 0x4
#define clrf_XVR_Reg0x7_ifIQswap                                addXVR_Reg0x7 &= ~0x4
#define get_XVR_Reg0x7_ifIQswap                                 ((addXVR_Reg0x7 & 0x4) >> 2)

#define posXVR_Reg0x7_TstldoVsel                                0
#define bitXVR_Reg0x7_TstldoVsel                                0x3
#define set_XVR_Reg0x7_TstldoVsel(val)                          addXVR_Reg0x7 = ((addXVR_Reg0x7 & (~0x3)) | ((val) << 0))
#define get_XVR_Reg0x7_TstldoVsel                               (addXVR_Reg0x7 & 0x3)

//addXVR_Reg0x8
#define addXVR_Reg0x8                                           *((volatile unsigned long *) (0x00806E00+0x8*4))
#define posXVR_Reg0x8_rxiftsten                                 31
#define bitXVR_Reg0x8_rxiftsten                                 0x80000000
#define set_XVR_Reg0x8_rxiftsten(val)                           addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x80000000)) | ((val) << 31))
#define setf_XVR_Reg0x8_rxiftsten                               addXVR_Reg0x8 |= 0x80000000
#define clrf_XVR_Reg0x8_rxiftsten                               addXVR_Reg0x8 &= ~0x80000000
#define get_XVR_Reg0x8_rxiftsten                                ((addXVR_Reg0x8 & 0x80000000) >> 31)

#define posXVR_Reg0x8_rxifTstSel                                30
#define bitXVR_Reg0x8_rxifTstSel                                0x40000000
#define set_XVR_Reg0x8_rxifTstSel(val)                          addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x40000000)) | ((val) << 30))
#define setf_XVR_Reg0x8_rxifTstSel                              addXVR_Reg0x8 |= 0x40000000
#define clrf_XVR_Reg0x8_rxifTstSel                              addXVR_Reg0x8 &= ~0x40000000
#define get_XVR_Reg0x8_rxifTstSel                               ((addXVR_Reg0x8 & 0x40000000) >> 30)

#define posXVR_Reg0x8_pwddcoc                                   29
#define bitXVR_Reg0x8_pwddcoc                                   0x20000000
#define set_XVR_Reg0x8_pwddcoc(val)                             addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x20000000)) | ((val) << 29))
#define setf_XVR_Reg0x8_pwddcoc                                 addXVR_Reg0x8 |= 0x20000000
#define clrf_XVR_Reg0x8_pwddcoc                                 addXVR_Reg0x8 &= ~0x20000000
#define get_XVR_Reg0x8_pwddcoc                                  ((addXVR_Reg0x8 & 0x20000000) >> 29)

#define posXVR_Reg0x8_RxIFAGCEn                                 28
#define bitXVR_Reg0x8_RxIFAGCEn                                 0x10000000
#define set_XVR_Reg0x8_RxIFAGCEn(val)                           addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x10000000)) | ((val) << 28))
#define setf_XVR_Reg0x8_RxIFAGCEn                               addXVR_Reg0x8 |= 0x10000000
#define clrf_XVR_Reg0x8_RxIFAGCEn                               addXVR_Reg0x8 &= ~0x10000000
#define get_XVR_Reg0x8_RxIFAGCEn                                ((addXVR_Reg0x8 & 0x10000000) >> 28)

#define posXVR_Reg0x8_en5rd                                     27
#define bitXVR_Reg0x8_en5rd                                     0x8000000
#define set_XVR_Reg0x8_en5rd(val)                               addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x8000000)) | ((val) << 27))
#define setf_XVR_Reg0x8_en5rd                                   addXVR_Reg0x8 |= 0x8000000
#define clrf_XVR_Reg0x8_en5rd                                   addXVR_Reg0x8 &= ~0x8000000
#define get_XVR_Reg0x8_en5rd                                    ((addXVR_Reg0x8 & 0x8000000) >> 27)

#define posXVR_Reg0x8_g0Flt1                                    26
#define bitXVR_Reg0x8_g0Flt1                                    0x4000000
#define set_XVR_Reg0x8_g0Flt1(val)                              addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x4000000)) | ((val) << 26))
#define setf_XVR_Reg0x8_g0Flt1                                  addXVR_Reg0x8 |= 0x4000000
#define clrf_XVR_Reg0x8_g0Flt1                                  addXVR_Reg0x8 &= ~0x4000000
#define get_XVR_Reg0x8_g0Flt1                                   ((addXVR_Reg0x8 & 0x4000000) >> 26)

#define posXVR_Reg0x8_g1Flt1                                    25
#define bitXVR_Reg0x8_g1Flt1                                    0x2000000
#define set_XVR_Reg0x8_g1Flt1(val)                              addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x2000000)) | ((val) << 25))
#define setf_XVR_Reg0x8_g1Flt1                                  addXVR_Reg0x8 |= 0x2000000
#define clrf_XVR_Reg0x8_g1Flt1                                  addXVR_Reg0x8 &= ~0x2000000
#define get_XVR_Reg0x8_g1Flt1                                   ((addXVR_Reg0x8 & 0x2000000) >> 25)

#define posXVR_Reg0x8_g2Flt2                                    24
#define bitXVR_Reg0x8_g2Flt2                                    0x1000000
#define set_XVR_Reg0x8_g2Flt2(val)                              addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x1000000)) | ((val) << 24))
#define setf_XVR_Reg0x8_g2Flt2                                  addXVR_Reg0x8 |= 0x1000000
#define clrf_XVR_Reg0x8_g2Flt2                                  addXVR_Reg0x8 &= ~0x1000000
#define get_XVR_Reg0x8_g2Flt2                                   ((addXVR_Reg0x8 & 0x1000000) >> 24)

#define posXVR_Reg0x8_g3Flt2                                    23
#define bitXVR_Reg0x8_g3Flt2                                    0x800000
#define set_XVR_Reg0x8_g3Flt2(val)                              addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x800000)) | ((val) << 23))
#define setf_XVR_Reg0x8_g3Flt2                                  addXVR_Reg0x8 |= 0x800000
#define clrf_XVR_Reg0x8_g3Flt2                                  addXVR_Reg0x8 &= ~0x800000
#define get_XVR_Reg0x8_g3Flt2                                   ((addXVR_Reg0x8 & 0x800000) >> 23)

#define posXVR_Reg0x8_g4Flt2                                    22
#define bitXVR_Reg0x8_g4Flt2                                    0x400000
#define set_XVR_Reg0x8_g4Flt2(val)                              addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x400000)) | ((val) << 22))
#define setf_XVR_Reg0x8_g4Flt2                                  addXVR_Reg0x8 |= 0x400000
#define clrf_XVR_Reg0x8_g4Flt2                                  addXVR_Reg0x8 &= ~0x400000
#define get_XVR_Reg0x8_g4Flt2                                   ((addXVR_Reg0x8 & 0x400000) >> 22)

#define posXVR_Reg0x8_gPGA                                      20
#define bitXVR_Reg0x8_gPGA                                      0x300000
#define set_XVR_Reg0x8_gPGA(val)                                addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x300000)) | ((val) << 20))
#define get_XVR_Reg0x8_gPGA                                     ((addXVR_Reg0x8 & 0x300000) >> 20)

#define posXVR_Reg0x8_vcmRxIF                                   17
#define bitXVR_Reg0x8_vcmRxIF                                   0xE0000
#define set_XVR_Reg0x8_vcmRxIF(val)                             addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0xE0000)) | ((val) << 17))
#define get_XVR_Reg0x8_vcmRxIF                                  ((addXVR_Reg0x8 & 0xE0000) >> 17)

#define posXVR_Reg0x8_rxfltit                                   14
#define bitXVR_Reg0x8_rxfltit                                   0x1C000
#define set_XVR_Reg0x8_rxfltit(val)                             addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x1C000)) | ((val) << 14))
#define get_XVR_Reg0x8_rxfltit                                  ((addXVR_Reg0x8 & 0x1C000) >> 14)

#define posXVR_Reg0x8_biast                                     4
#define bitXVR_Reg0x8_biast                                     0x3FF0
#define set_XVR_Reg0x8_biast(val)                               addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x3FF0)) | ((val) << 4))
#define get_XVR_Reg0x8_biast                                    ((addXVR_Reg0x8 & 0x3FF0) >> 4)

#define posXVR_Reg0x8_TrxIFldoVsel                              2
#define bitXVR_Reg0x8_TrxIFldoVsel                              0xC
#define set_XVR_Reg0x8_TrxIFldoVsel(val)                        addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0xC)) | ((val) << 2))
#define get_XVR_Reg0x8_TrxIFldoVsel                             ((addXVR_Reg0x8 & 0xC) >> 2)

#define posXVR_Reg0x8_IFADCldoVsel                              0
#define bitXVR_Reg0x8_IFADCldoVsel                              0x3
#define set_XVR_Reg0x8_IFADCldoVsel(val)                        addXVR_Reg0x8 = ((addXVR_Reg0x8 & (~0x3)) | ((val) << 0))
#define get_XVR_Reg0x8_IFADCldoVsel                             (addXVR_Reg0x8 & 0x3)

//addXVR_Reg0x9
#define addXVR_Reg0x9                                           *((volatile unsigned long *) (0x00806E00+0x9*4))
#define posXVR_Reg0x9_ib32kXtal                                 28
#define bitXVR_Reg0x9_ib32kXtal                                 0xF0000000
#define set_XVR_Reg0x9_ib32kXtal(val)                           addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0xF0000000)) | ((val) << 28))
#define get_XVR_Reg0x9_ib32kXtal                                ((addXVR_Reg0x9 & 0xF0000000) >> 28)

#define posXVR_Reg0x9_pwd32kXtalspi                             27
#define bitXVR_Reg0x9_pwd32kXtalspi                             0x8000000
#define set_XVR_Reg0x9_pwd32kXtalspi(val)                       addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x8000000)) | ((val) << 27))
#define setf_XVR_Reg0x9_pwd32kXtalspi                           addXVR_Reg0x9 |= 0x8000000
#define clrf_XVR_Reg0x9_pwd32kXtalspi                           addXVR_Reg0x9 &= ~0x8000000
#define get_XVR_Reg0x9_pwd32kXtalspi                            ((addXVR_Reg0x9 & 0x8000000) >> 27)

#define posXVR_Reg0x9_clk32kSel                                 26
#define bitXVR_Reg0x9_clk32kSel                                 0x4000000
#define set_XVR_Reg0x9_clk32kSel(val)                           addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x4000000)) | ((val) << 26))
#define setf_XVR_Reg0x9_clk32kSel                               addXVR_Reg0x9 |= 0x4000000
#define clrf_XVR_Reg0x9_clk32kSel                               addXVR_Reg0x9 &= ~0x4000000
#define get_XVR_Reg0x9_clk32kSel                                ((addXVR_Reg0x9 & 0x4000000) >> 26)

#define posXVR_Reg0x9_tsten32kXtal                              25
#define bitXVR_Reg0x9_tsten32kXtal                              0x2000000
#define set_XVR_Reg0x9_tsten32kXtal(val)                        addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x2000000)) | ((val) << 25))
#define setf_XVR_Reg0x9_tsten32kXtal                            addXVR_Reg0x9 |= 0x2000000
#define clrf_XVR_Reg0x9_tsten32kXtal                            addXVR_Reg0x9 &= ~0x2000000
#define get_XVR_Reg0x9_tsten32kXtal                             ((addXVR_Reg0x9 & 0x2000000) >> 25)

#define posXVR_Reg0x9_tsten32kRC                                24
#define bitXVR_Reg0x9_tsten32kRC                                0x1000000
#define set_XVR_Reg0x9_tsten32kRC(val)                          addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x1000000)) | ((val) << 24))
#define setf_XVR_Reg0x9_tsten32kRC                              addXVR_Reg0x9 |= 0x1000000
#define clrf_XVR_Reg0x9_tsten32kRC                              addXVR_Reg0x9 &= ~0x1000000
#define get_XVR_Reg0x9_tsten32kRC                               ((addXVR_Reg0x9 & 0x1000000) >> 24)


#define posXVR_Reg0x9_ck48MtstEn                                22
#define bitXVR_Reg0x9_ck48MtstEn                                0x400000
#define set_XVR_Reg0x9_ck48MtstEn(val)                          addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x400000)) | ((val) << 22))
#define setf_XVR_Reg0x9_ck48MtstEn                              addXVR_Reg0x9 |= 0x400000
#define clrf_XVR_Reg0x9_ck48MtstEn                              addXVR_Reg0x9 &= ~0x400000
#define get_XVR_Reg0x9_ck48MtstEn                               ((addXVR_Reg0x9 & 0x400000) >> 22)

#define posXVR_Reg0x9_digpll_R1_pr                              19
#define bitXVR_Reg0x9_digpll_R1_pr                              0x380000
#define set_XVR_Reg0x9_digpll_R1_pr(val)                        addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x380000)) | ((val) << 19))
#define get_XVR_Reg0x9_digpll_R1_pr                             ((addXVR_Reg0x9 & 0x380000) >> 19)

#define posXVR_Reg0x9_digpll_cp                                 17
#define bitXVR_Reg0x9_digpll_cp                                 0x60000
#define set_XVR_Reg0x9_digpll_cp(val)                           addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x60000)) | ((val) << 17))
#define get_XVR_Reg0x9_digpll_cp                                ((addXVR_Reg0x9 & 0x60000) >> 17)

#define posXVR_Reg0x9_digpll_ictrcp                             13
#define bitXVR_Reg0x9_digpll_ictrcp                             0x1E000
#define set_XVR_Reg0x9_digpll_ictrcp(val)                       addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x1E000)) | ((val) << 13))
#define get_XVR_Reg0x9_digpll_ictrcp                            ((addXVR_Reg0x9 & 0x1E000) >> 13)

#define posXVR_Reg0x9_pwd_digpll_vco                            12
#define bitXVR_Reg0x9_pwd_digpll_vco                            0x1000
#define set_XVR_Reg0x9_pwd_digpll_vco(val)                      addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x1000)) | ((val) << 12))
#define setf_XVR_Reg0x9_pwd_digpll_vco                          addXVR_Reg0x9 |= 0x1000
#define clrf_XVR_Reg0x9_pwd_digpll_vco                          addXVR_Reg0x9 &= ~0x1000
#define get_XVR_Reg0x9_pwd_digpll_vco                           ((addXVR_Reg0x9 & 0x1000) >> 12)

#define posXVR_Reg0x9_pwd_digpll_cp                             11
#define bitXVR_Reg0x9_pwd_digpll_cp                             0x800
#define set_XVR_Reg0x9_pwd_digpll_cp(val)                       addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x800)) | ((val) << 11))
#define setf_XVR_Reg0x9_pwd_digpll_cp                           addXVR_Reg0x9 |= 0x800
#define clrf_XVR_Reg0x9_pwd_digpll_cp                           addXVR_Reg0x9 &= ~0x800
#define get_XVR_Reg0x9_pwd_digpll_cp                            ((addXVR_Reg0x9 & 0x800) >> 11)

#define posXVR_Reg0x9_pwd_digpll_pfd                            10
#define bitXVR_Reg0x9_pwd_digpll_pfd                            0x400
#define set_XVR_Reg0x9_pwd_digpll_pfd(val)                      addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x400)) | ((val) << 10))
#define setf_XVR_Reg0x9_pwd_digpll_pfd                          addXVR_Reg0x9 |= 0x400
#define clrf_XVR_Reg0x9_pwd_digpll_pfd                          addXVR_Reg0x9 &= ~0x400
#define get_XVR_Reg0x9_pwd_digpll_pfd                           ((addXVR_Reg0x9 & 0x400) >> 10)

#define posXVR_Reg0x9_digpll_pwd_spi                            9
#define bitXVR_Reg0x9_digpll_pwd_spi                            0x200
#define set_XVR_Reg0x9_digpll_pwd_spi(val)                      addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x200)) | ((val) << 9))
#define setf_XVR_Reg0x9_digpll_pwd_spi                          addXVR_Reg0x9 |= 0x200
#define clrf_XVR_Reg0x9_digpll_pwd_spi                          addXVR_Reg0x9 &= ~0x200
#define get_XVR_Reg0x9_digpll_pwd_spi                           ((addXVR_Reg0x9 & 0x200) >> 9)

#define posXVR_Reg0x9_bypass_digpll                             8
#define bitXVR_Reg0x9_bypass_digpll                             0x100
#define set_XVR_Reg0x9_bypass_digpll(val)                       addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x100)) | ((val) << 8))
#define setf_XVR_Reg0x9_bypass_digpll                           addXVR_Reg0x9 |= 0x100
#define clrf_XVR_Reg0x9_bypass_digpll                           addXVR_Reg0x9 &= ~0x100
#define get_XVR_Reg0x9_bypass_digpll                            ((addXVR_Reg0x9 & 0x100) >> 8)

#define posXVR_Reg0x9_openloop_digpll_en                        7
#define bitXVR_Reg0x9_openloop_digpll_en                        0x80
#define set_XVR_Reg0x9_openloop_digpll_en(val)                  addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x80)) | ((val) << 7))
#define setf_XVR_Reg0x9_openloop_digpll_en                      addXVR_Reg0x9 |= 0x80
#define clrf_XVR_Reg0x9_openloop_digpll_en                      addXVR_Reg0x9 &= ~0x80
#define get_XVR_Reg0x9_openloop_digpll_en                       ((addXVR_Reg0x9 & 0x80) >> 7)

#define posXVR_Reg0x9_no_use                                    0
#define bitXVR_Reg0x9_no_use                                    0x7F
#define set_XVR_Reg0x9_no_use(val)                              addXVR_Reg0x9 = ((addXVR_Reg0x9 & (~0x7F)) | ((val) << 0))
#define get_XVR_Reg0x9_no_use                                   (addXVR_Reg0x9 & 0x7F)

//addXVR_Reg0xa
#define addXVR_Reg0xa                                           *((volatile unsigned long *) (0x00806E00+0xa*4))
#define posXVR_Reg0xa_hysctrl_dc                                31
#define bitXVR_Reg0xa_hysctrl_dc                                0x80000000
#define set_XVR_Reg0xa_hysctrl_dc(val)                          addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x80000000)) | ((val) << 31))
#define setf_XVR_Reg0xa_hysctrl_dc                              addXVR_Reg0xa |= 0x80000000
#define clrf_XVR_Reg0xa_hysctrl_dc                              addXVR_Reg0xa &= ~0x80000000
#define get_XVR_Reg0xa_hysctrl_dc                               ((addXVR_Reg0xa & 0x80000000) >> 31)

#define posXVR_Reg0xa_selburs_dc_                               28
#define bitXVR_Reg0xa_selburs_dc_                               0x70000000
#define set_XVR_Reg0xa_selburs_dc_(val)                         addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x70000000)) | ((val) << 28))
#define get_XVR_Reg0xa_selburs_dc_                              ((addXVR_Reg0xa & 0x70000000) >> 28)

#define posXVR_Reg0xa_vsel_digldo                               25
#define bitXVR_Reg0xa_vsel_digldo                               0xE000000
#define set_XVR_Reg0xa_vsel_digldo(val)                         addXVR_Reg0xa = ((addXVR_Reg0xa & (~0xE000000)) | ((val) << 25))
#define get_XVR_Reg0xa_vsel_digldo                              ((addXVR_Reg0xa & 0xE000000) >> 25)

#define posXVR_Reg0xa_pwrctrl_vdddsp                            24
#define bitXVR_Reg0xa_pwrctrl_vdddsp                            0x1000000
#define set_XVR_Reg0xa_pwrctrl_vdddsp(val)                      addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x1000000)) | ((val) << 24))
#define setf_XVR_Reg0xa_pwrctrl_vdddsp                          addXVR_Reg0xa |= 0x1000000
#define clrf_XVR_Reg0xa_pwrctrl_vdddsp                          addXVR_Reg0xa &= ~0x1000000
#define get_XVR_Reg0xa_pwrctrl_vdddsp                           ((addXVR_Reg0xa & 0x1000000) >> 24)

#define posXVR_Reg0xa_pwrctrl_vddspi                            23
#define bitXVR_Reg0xa_pwrctrl_vddspi                            0x800000
#define set_XVR_Reg0xa_pwrctrl_vddspi(val)                      addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x800000)) | ((val) << 23))
#define setf_XVR_Reg0xa_pwrctrl_vddspi                          addXVR_Reg0xa |= 0x800000
#define clrf_XVR_Reg0xa_pwrctrl_vddspi                          addXVR_Reg0xa &= ~0x800000
#define get_XVR_Reg0xa_pwrctrl_vddspi                           ((addXVR_Reg0xa & 0x800000) >> 23)

#define posXVR_Reg0xa_nonoverp_dcdc                             21
#define bitXVR_Reg0xa_nonoverp_dcdc                             0x600000
#define set_XVR_Reg0xa_nonoverp_dcdc(val)                       addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x600000)) | ((val) << 21))
#define get_XVR_Reg0xa_nonoverp_dcdc                            ((addXVR_Reg0xa & 0x600000) >> 21)

#define posXVR_Reg0xa_nonovern_dcdc                             19
#define bitXVR_Reg0xa_nonovern_dcdc                             0x180000
#define set_XVR_Reg0xa_nonovern_dcdc(val)                       addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x180000)) | ((val) << 19))
#define get_XVR_Reg0xa_nonovern_dcdc                            ((addXVR_Reg0xa & 0x180000) >> 19)

#define posXVR_Reg0xa_boostsel                                  16
#define bitXVR_Reg0xa_boostsel                                  0x70000
#define set_XVR_Reg0xa_boostsel(val)                            addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x70000)) | ((val) << 16))
#define get_XVR_Reg0xa_boostsel                                 ((addXVR_Reg0xa & 0x70000) >> 16)

#define posXVR_Reg0xa_limsel_dcdc                               14
#define bitXVR_Reg0xa_limsel_dcdc                               0xC000
#define set_XVR_Reg0xa_limsel_dcdc(val)                         addXVR_Reg0xa = ((addXVR_Reg0xa & (~0xC000)) | ((val) << 14))
#define get_XVR_Reg0xa_limsel_dcdc                              ((addXVR_Reg0xa & 0xC000) >> 14)

#define posXVR_Reg0xa_clksel_dcdc                               10
#define bitXVR_Reg0xa_clksel_dcdc                               0x3C00
#define set_XVR_Reg0xa_clksel_dcdc(val)                         addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x3C00)) | ((val) << 10))
#define get_XVR_Reg0xa_clksel_dcdc                              ((addXVR_Reg0xa & 0x3C00) >> 10)


#define posXVR_Reg0xa_vsel_digldo_spien                         8
#define bitXVR_Reg0xa_vsel_digldo_spien                         0x100
#define set_XVR_Reg0xa_vsel_digldo_spien(val)                   addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x100)) | ((val) << 8))
#define setf_XVR_Reg0xa_vsel_digldo_spien                       addXVR_Reg0xa |= 0x100
#define clrf_XVR_Reg0xa_vsel_digldo_spien                       addXVR_Reg0xa &= ~0x100
#define get_XVR_Reg0xa_vsel_digldo_spien                        ((addXVR_Reg0xa & 0x100) >> 8)

#define posXVR_Reg0xa_BiasCtrl_digldo                           6
#define bitXVR_Reg0xa_BiasCtrl_digldo                           0xC0
#define set_XVR_Reg0xa_BiasCtrl_digldo(val)                     addXVR_Reg0xa = ((addXVR_Reg0xa & (~0xC0)) | ((val) << 6))
#define get_XVR_Reg0xa_BiasCtrl_digldo                          ((addXVR_Reg0xa & 0xC0) >> 6)

#define posXVR_Reg0xa_spildosel                                 4
#define bitXVR_Reg0xa_spildosel                                 0x30
#define set_XVR_Reg0xa_spildosel(val)                           addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x30)) | ((val) << 4))
#define get_XVR_Reg0xa_spildosel                                ((addXVR_Reg0xa & 0x30) >> 4)

#define posXVR_Reg0xa_pgaldoVsel                                2
#define bitXVR_Reg0xa_pgaldoVsel                                0xC
#define set_XVR_Reg0xa_pgaldoVsel(val)                          addXVR_Reg0xa = ((addXVR_Reg0xa & (~0xC)) | ((val) << 2))
#define get_XVR_Reg0xa_pgaldoVsel                               ((addXVR_Reg0xa & 0xC) >> 2)

#define posXVR_Reg0xa_SARADCldoVsel                             0
#define bitXVR_Reg0xa_SARADCldoVsel                             0x3
#define set_XVR_Reg0xa_SARADCldoVsel(val)                       addXVR_Reg0xa = ((addXVR_Reg0xa & (~0x3)) | ((val) << 0))
#define get_XVR_Reg0xa_SARADCldoVsel                            (addXVR_Reg0xa & 0x3)

//addXVR_Reg0xb
#define addXVR_Reg0xb                                           *((volatile unsigned long *) (0x00806E00+0xb*4))

#define posXVR_Reg0xb_bucksel                                   23
#define bitXVR_Reg0xb_bucksel                                   0x3800000
#define set_XVR_Reg0xb_bucksel(val)                             addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x3800000)) | ((val) << 23))
#define get_XVR_Reg0xb_bucksel                                  ((addXVR_Reg0xb & 0x3800000) >> 23)

#define posXVR_Reg0xb_pwddigldobuf                              22
#define bitXVR_Reg0xb_pwddigldobuf                              0x400000
#define set_XVR_Reg0xb_pwddigldobuf(val)                        addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x400000)) | ((val) << 22))
#define setf_XVR_Reg0xb_pwddigldobuf                            addXVR_Reg0xb |= 0x400000
#define clrf_XVR_Reg0xb_pwddigldobuf                            addXVR_Reg0xb &= ~0x400000
#define get_XVR_Reg0xb_pwddigldobuf                             ((addXVR_Reg0xb & 0x400000) >> 22)

#define posXVR_Reg0xb_pwd_sysldo                                21
#define bitXVR_Reg0xb_pwd_sysldo                                0x200000
#define set_XVR_Reg0xb_pwd_sysldo(val)                          addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x200000)) | ((val) << 21))
#define setf_XVR_Reg0xb_pwd_sysldo                              addXVR_Reg0xb |= 0x200000
#define clrf_XVR_Reg0xb_pwd_sysldo                              addXVR_Reg0xb &= ~0x200000
#define get_XVR_Reg0xb_pwd_sysldo                               ((addXVR_Reg0xb & 0x200000) >> 21)

#define posXVR_Reg0xb_sysldo_vctrl                              19
#define bitXVR_Reg0xb_sysldo_vctrl                              0x180000
#define set_XVR_Reg0xb_sysldo_vctrl(val)                        addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x180000)) | ((val) << 19))
#define get_XVR_Reg0xb_sysldo_vctrl                             ((addXVR_Reg0xb & 0x180000) >> 19)

#define posXVR_Reg0xb_gadcictrl_buf                             17
#define bitXVR_Reg0xb_gadcictrl_buf                             0x60000
#define set_XVR_Reg0xb_gadcictrl_buf(val)                       addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x60000)) | ((val) << 17))
#define get_XVR_Reg0xb_gadcictrl_buf                            ((addXVR_Reg0xb & 0x60000) >> 17)

#define posXVR_Reg0xb_gadcictrl_cmp                             15
#define bitXVR_Reg0xb_gadcictrl_cmp                             0x18000
#define set_XVR_Reg0xb_gadcictrl_cmp(val)                       addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x18000)) | ((val) << 15))
#define get_XVR_Reg0xb_gadcictrl_cmp                            ((addXVR_Reg0xb & 0x18000) >> 15)

#define posXVR_Reg0xb_invsel                                    13
#define bitXVR_Reg0xb_invsel                                    0x6000
#define set_XVR_Reg0xb_invsel(val)                              addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x6000)) | ((val) << 13))
#define get_XVR_Reg0xb_invsel                                   ((addXVR_Reg0xb & 0x6000) >> 13)

#define posXVR_Reg0xb_fsel                                      12
#define bitXVR_Reg0xb_fsel                                      0x1000
#define set_XVR_Reg0xb_fsel(val)                                addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x1000)) | ((val) << 12))
#define setf_XVR_Reg0xb_fsel                                    addXVR_Reg0xb |= 0x1000
#define clrf_XVR_Reg0xb_fsel                                    addXVR_Reg0xb &= ~0x1000
#define get_XVR_Reg0xb_fsel                                     ((addXVR_Reg0xb & 0x1000) >> 12)

#define posXVR_Reg0xb_ckadc_en                                  11
#define bitXVR_Reg0xb_ckadc_en                                  0x800
#define set_XVR_Reg0xb_ckadc_en(val)                            addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x800)) | ((val) << 11))
#define setf_XVR_Reg0xb_ckadc_en                                addXVR_Reg0xb |= 0x800
#define clrf_XVR_Reg0xb_ckadc_en                                addXVR_Reg0xb &= ~0x800
#define get_XVR_Reg0xb_ckadc_en                                 ((addXVR_Reg0xb & 0x800) >> 11)

#define posXVR_Reg0xb_outvsel                                   9
#define bitXVR_Reg0xb_outvsel                                   0x600
#define set_XVR_Reg0xb_outvsel(val)                             addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x600)) | ((val) << 9))
#define get_XVR_Reg0xb_outvsel                                  ((addXVR_Reg0xb & 0x600) >> 9)

#define posXVR_Reg0xb_ictrl_mode                                8
#define bitXVR_Reg0xb_ictrl_mode                                0x100
#define set_XVR_Reg0xb_ictrl_mode(val)                          addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x100)) | ((val) << 8))
#define setf_XVR_Reg0xb_ictrl_mode                              addXVR_Reg0xb |= 0x100
#define clrf_XVR_Reg0xb_ictrl_mode                              addXVR_Reg0xb &= ~0x100
#define get_XVR_Reg0xb_ictrl_mode                               ((addXVR_Reg0xb & 0x100) >> 8)

#define posXVR_Reg0xb_bias_sel                                  7
#define bitXVR_Reg0xb_bias_sel                                  0x80
#define set_XVR_Reg0xb_bias_sel(val)                            addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x80)) | ((val) << 7))
#define setf_XVR_Reg0xb_bias_sel                                addXVR_Reg0xb |= 0x80
#define clrf_XVR_Reg0xb_bias_sel                                addXVR_Reg0xb &= ~0x80
#define get_XVR_Reg0xb_bias_sel                                 ((addXVR_Reg0xb & 0x80) >> 7)

#define posXVR_Reg0xb_cal_en                                    6
#define bitXVR_Reg0xb_cal_en                                    0x40
#define set_XVR_Reg0xb_cal_en(val)                              addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x40)) | ((val) << 6))
#define setf_XVR_Reg0xb_cal_en                                  addXVR_Reg0xb |= 0x40
#define clrf_XVR_Reg0xb_cal_en                                  addXVR_Reg0xb &= ~0x40
#define get_XVR_Reg0xb_cal_en                                   ((addXVR_Reg0xb & 0x40) >> 6)

#define posXVR_Reg0xb_dlatch                                    5
#define bitXVR_Reg0xb_dlatch                                    0x20
#define set_XVR_Reg0xb_dlatch(val)                              addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x20)) | ((val) << 5))
#define setf_XVR_Reg0xb_dlatch                                  addXVR_Reg0xb |= 0x20
#define clrf_XVR_Reg0xb_dlatch                                  addXVR_Reg0xb &= ~0x20
#define get_XVR_Reg0xb_dlatch                                   ((addXVR_Reg0xb & 0x20) >> 5)

#define posXVR_Reg0xb_ictrl_mix2                                3
#define bitXVR_Reg0xb_ictrl_mix2                                0x18
#define set_XVR_Reg0xb_ictrl_mix2(val)                          addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x18)) | ((val) << 3))
#define get_XVR_Reg0xb_ictrl_mix2                               ((addXVR_Reg0xb & 0x18) >> 3)

#define posXVR_Reg0xb_cmtune_lna                                0
#define bitXVR_Reg0xb_cmtune_lna                                0x7
#define set_XVR_Reg0xb_cmtune_lna(val)                          addXVR_Reg0xb = ((addXVR_Reg0xb & (~0x7)) | ((val) << 0))
#define get_XVR_Reg0xb_cmtune_lna                               (addXVR_Reg0xb & 0x7)

//addXVR_Reg0xc
#define addXVR_Reg0xc                                           *((volatile unsigned long *) (0x00806E00+0xc*4))

//addXVR_Reg0xd
#define addXVR_Reg0xd                                           *((volatile unsigned long *) (0x00806E00+0xd*4))

//addXVR_Reg0xe
#define addXVR_Reg0xe                                           *((volatile unsigned long *) (0x00806E00+0xe*4))
//addXVR_Reg0xf
#define addXVR_Reg0xf                                           *((volatile unsigned long *) (0x00806E00+0xf*4))

//addXVR_Reg0x10
#define addXVR_Reg0x10                                          *((volatile unsigned long *) (0x00806E00+0x10*4))

#define posXVR_Reg0x10_fcalicap                                 16
#define bitXVR_Reg0x10_fcalicap                                 0x1F0000
#define get_XVR_Reg0x10_fcalicap                                ((addXVR_Reg0x10 & 0x1F0000) >> 16)

#define posXVR_Reg0x10_chip_id                                  0
#define bitXVR_Reg0x10_chip_id                                  0xFFFF
#define get_XVR_Reg0x10_chip_id                                 (addXVR_Reg0x10 & 0xFFFF)

//addXVR_Reg0x11
#define addXVR_Reg0x11                                          *((volatile unsigned long *) (0x00806E00+0x11*4))

//addXVR_Reg0x12
#define addXVR_Reg0x12                                          *((volatile unsigned long *) (0x00806E00+0x12*4))
#define posXVR_Reg0x12_lna_rssi                                 31
#define bitXVR_Reg0x12_lna_rssi                                 0x80000000
#define get_XVR_Reg0x12_lna_rssi                                ((addXVR_Reg0x12 & 0x80000000) >> 31)

#define posXVR_Reg0x12_adc_rssi_vlid                            30
#define bitXVR_Reg0x12_adc_rssi_vlid                            0x40000000
#define get_XVR_Reg0x12_adc_rssi_vlid                           ((addXVR_Reg0x12 & 0x40000000) >> 30)


#define posXVR_Reg0x12_vco_kcal_out                             16
#define bitXVR_Reg0x12_vco_kcal_out                             0x1FFF0000
#define get_XVR_Reg0x12_vco_kcal_out                            ((addXVR_Reg0x12 & 0x1FFF0000) >> 16)


#define posXVR_Reg0x12_adc_rssi_o                               8
#define bitXVR_Reg0x12_adc_rssi_o                               0x1F00
#define get_XVR_Reg0x12_adc_rssi_o                              ((addXVR_Reg0x12 & 0x1F00) >> 8)

#define posXVR_Reg0x12_rssi_o                                   0
#define bitXVR_Reg0x12_rssi_o                                   0xFF
#define get_XVR_Reg0x12_rssi_o                                  (addXVR_Reg0x12 & 0xFF)

//addXVR_Reg0x13
#define addXVR_Reg0x13                                          *((volatile unsigned long *) (0x00806E00+0x13*4))
#define posXVR_Reg0x13_rssi_ind                                 24
#define bitXVR_Reg0x13_rssi_ind                                 0xFF000000
#define get_XVR_Reg0x13_rssi_ind                                ((addXVR_Reg0x13 & 0xFF000000) >> 24)


#define posXVR_Reg0x13_match_phase_num                          16
#define bitXVR_Reg0x13_match_phase_num                          0x1FFF0000
#define get_XVR_Reg0x13_match_phase_num                         ((addXVR_Reg0x13 & 0x1FFF0000) >> 16)


#define posXVR_Reg0x13_pre_dc_o                                 0
#define bitXVR_Reg0x13_pre_dc_o                                 0xFFF
#define get_XVR_Reg0x13_pre_dc_o                                (addXVR_Reg0x13 & 0xFFF)

//addXVR_Reg0x14
#define addXVR_Reg0x14                                          *((volatile unsigned long *) (0x00806E00+0x14*4))

#define posXVR_Reg0x14_unlock_status                            26
#define bitXVR_Reg0x14_unlock_status                            0x4000000
#define get_XVR_Reg0x14_unlock_status                           ((addXVR_Reg0x14 & 0x4000000) >> 26)


#define posXVR_Reg0x14_match_phase_gfsk                         24
#define bitXVR_Reg0x14_match_phase_gfsk                         0x1000000
#define get_XVR_Reg0x14_match_phase_gfsk                        ((addXVR_Reg0x14 & 0x1000000) >> 24)


#define posXVR_Reg0x14_cdyn_val                                 16
#define bitXVR_Reg0x14_cdyn_val                                 0xF0000
#define get_XVR_Reg0x14_cdyn_val                                ((addXVR_Reg0x14 & 0xF0000) >> 16)


//addXVR_Reg0x15
#define addXVR_Reg0x15                                          *((volatile unsigned long *) (0x00806E00+0x15*4))

//addXVR_Reg0x16
#define addXVR_Reg0x16                                          *((volatile unsigned long *) (0x00806E00+0x16*4))

//addXVR_Reg0x17
#define addXVR_Reg0x17                                          *((volatile unsigned long *) (0x00806E00+0x17*4))

//addXVR_Reg0x18
#define addXVR_Reg0x18                                          *((volatile unsigned long *) (0x00806E00+0x18*4))

#define posXVR_Reg0x18_rx_gain                                  0
#define bitXVR_Reg0x18_rx_gain                                  0x1FF
#define get_XVR_Reg0x18_rx_gain                                 (addXVR_Reg0x18 & 0x1FF)

//addXVR_Reg0x19
#define addXVR_Reg0x19                                          *((volatile unsigned long *) (0x00806E00+0x19*4))

#define posXVR_Reg0x19_lr_sum1_max                              19
#define bitXVR_Reg0x19_lr_sum1_max                              0x1F80000
#define get_XVR_Reg0x19_lr_sum1_max                             ((addXVR_Reg0x19 & 0x1F80000) >> 19)

#define posXVR_Reg0x19_match_phase_num_lr                       16
#define bitXVR_Reg0x19_match_phase_num_lr                       0x70000
#define get_XVR_Reg0x19_match_phase_num_lr                      ((addXVR_Reg0x19 & 0x70000) >> 16)


#define posXVR_Reg0x19_pre_dc_o_lr                              0
#define bitXVR_Reg0x19_pre_dc_o_lr                              0xFFF
#define get_XVR_Reg0x19_pre_dc_o_lr                             (addXVR_Reg0x19 & 0xFFF)

//addXVR_Reg0x1a
#define addXVR_Reg0x1a                                          *((volatile unsigned long *) (0x00806E00+0x1a*4))

//addXVR_Reg0x1b
#define addXVR_Reg0x1b                                          *((volatile unsigned long *) (0x00806E00+0x1b*4))

//addXVR_Reg0x1c
#define addXVR_Reg0x1c                                          *((volatile unsigned long *) (0x00806E00+0x1c*4))

//addXVR_Reg0x1d
#define addXVR_Reg0x1d                                          *((volatile unsigned long *) (0x00806E00+0x1d*4))

//addXVR_Reg0x1e
#define addXVR_Reg0x1e                                          *((volatile unsigned long *) (0x00806E00+0x1e*4))

//addXVR_Reg0x1f
#define addXVR_Reg0x1f                                          *((volatile unsigned long *) (0x00806E00+0x1f*4))

//addXVR_Reg0x20
#define addXVR_Reg0x20                                          *((volatile unsigned long *) (0x00806E00+0x20*4))

//addXVR_Reg0x21
#define addXVR_Reg0x21                                          *((volatile unsigned long *) (0x00806E00+0x21*4))

//addXVR_Reg0x22
#define addXVR_Reg0x22                                          *((volatile unsigned long *) (0x00806E00+0x22*4))

//addXVR_Reg0x23
#define addXVR_Reg0x23                                          *((volatile unsigned long *) (0x00806E00+0x23*4))

//addXVR_Reg0x24
#define addXVR_Reg0x24                                          *((volatile unsigned long *) (0x00806E00+0x24*4))
#define posXVR_Reg0x24_rf_dr_reg                                31
#define bitXVR_Reg0x24_rf_dr_reg                                0x80000000
#define set_XVR_Reg0x24_rf_dr_reg(val)                          addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0x80000000)) | ((val) << 31))
#define setf_XVR_Reg0x24_rf_dr_reg                              addXVR_Reg0x24 |= 0x80000000
#define clrf_XVR_Reg0x24_rf_dr_reg                              addXVR_Reg0x24 &= ~0x80000000
#define get_XVR_Reg0x24_rf_dr_reg                               ((addXVR_Reg0x24 & 0x80000000) >> 31)

#define posXVR_Reg0x24_rf_dr_sel                                30
#define bitXVR_Reg0x24_rf_dr_sel                                0x40000000
#define set_XVR_Reg0x24_rf_dr_sel(val)                          addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0x40000000)) | ((val) << 30))
#define setf_XVR_Reg0x24_rf_dr_sel                              addXVR_Reg0x24 |= 0x40000000
#define clrf_XVR_Reg0x24_rf_dr_sel                              addXVR_Reg0x24 &= ~0x40000000
#define get_XVR_Reg0x24_rf_dr_sel                               ((addXVR_Reg0x24 & 0x40000000) >> 30)

#define posXVR_Reg0x24_en_250k                                  29
#define bitXVR_Reg0x24_en_250k                                  0x20000000
#define set_XVR_Reg0x24_en_250k(val)                            addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0x20000000)) | ((val) << 29))
#define setf_XVR_Reg0x24_en_250k                                addXVR_Reg0x24 |= 0x20000000
#define clrf_XVR_Reg0x24_en_250k                                addXVR_Reg0x24 &= ~0x20000000
#define get_XVR_Reg0x24_en_250k                                 ((addXVR_Reg0x24 & 0x20000000) >> 29)


#define posXVR_Reg0x24_auto_txpwr                               20
#define bitXVR_Reg0x24_auto_txpwr                               0x100000
#define set_XVR_Reg0x24_auto_txpwr(val)                         addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0x100000)) | ((val) << 20))
#define setf_XVR_Reg0x24_auto_txpwr                             addXVR_Reg0x24 |= 0x100000
#define clrf_XVR_Reg0x24_auto_txpwr                             addXVR_Reg0x24 &= ~0x100000
#define get_XVR_Reg0x24_auto_txpwr                              ((addXVR_Reg0x24 & 0x100000) >> 20)

#define posXVR_Reg0x24_auto_syncwd                              19
#define bitXVR_Reg0x24_auto_syncwd                              0x80000
#define set_XVR_Reg0x24_auto_syncwd(val)                        addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0x80000)) | ((val) << 19))
#define setf_XVR_Reg0x24_auto_syncwd                            addXVR_Reg0x24 |= 0x80000
#define clrf_XVR_Reg0x24_auto_syncwd                            addXVR_Reg0x24 &= ~0x80000
#define get_XVR_Reg0x24_auto_syncwd                             ((addXVR_Reg0x24 & 0x80000) >> 19)

#define posXVR_Reg0x24_auto_syncwin                             18
#define bitXVR_Reg0x24_auto_syncwin                             0x40000
#define set_XVR_Reg0x24_auto_syncwin(val)                       addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0x40000)) | ((val) << 18))
#define setf_XVR_Reg0x24_auto_syncwin                           addXVR_Reg0x24 |= 0x40000
#define clrf_XVR_Reg0x24_auto_syncwin                           addXVR_Reg0x24 &= ~0x40000
#define get_XVR_Reg0x24_auto_syncwin                            ((addXVR_Reg0x24 & 0x40000) >> 18)

#define posXVR_Reg0x24_auto_chnn                                17
#define bitXVR_Reg0x24_auto_chnn                                0x20000
#define set_XVR_Reg0x24_auto_chnn(val)                          addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0x20000)) | ((val) << 17))
#define setf_XVR_Reg0x24_auto_chnn                              addXVR_Reg0x24 |= 0x20000
#define clrf_XVR_Reg0x24_auto_chnn                              addXVR_Reg0x24 &= ~0x20000
#define get_XVR_Reg0x24_auto_chnn                               ((addXVR_Reg0x24 & 0x20000) >> 17)

#define posXVR_Reg0x24_cur_cfg_agc                              16
#define bitXVR_Reg0x24_cur_cfg_agc                              0x10000
#define set_XVR_Reg0x24_cur_cfg_agc(val)                        addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0x10000)) | ((val) << 16))
#define setf_XVR_Reg0x24_cur_cfg_agc                            addXVR_Reg0x24 |= 0x10000
#define clrf_XVR_Reg0x24_cur_cfg_agc                            addXVR_Reg0x24 &= ~0x10000
#define get_XVR_Reg0x24_cur_cfg_agc                             ((addXVR_Reg0x24 & 0x10000) >> 16)

#define posXVR_Reg0x24_cur_cfg_win                              11
#define bitXVR_Reg0x24_cur_cfg_win                              0xF800
#define set_XVR_Reg0x24_cur_cfg_win(val)                        addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0xF800)) | ((val) << 11))
#define get_XVR_Reg0x24_cur_cfg_win                             ((addXVR_Reg0x24 & 0xF800) >> 11)

#define posXVR_Reg0x24_cur_cfg_pwr                              7
#define bitXVR_Reg0x24_cur_cfg_pwr                              0x780
#define set_XVR_Reg0x24_cur_cfg_pwr(val)                        addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0x780)) | ((val) << 7))
#define get_XVR_Reg0x24_cur_cfg_pwr                             ((addXVR_Reg0x24 & 0x780) >> 7)

#define posXVR_Reg0x24_cur_cfg_chn                              0
#define bitXVR_Reg0x24_cur_cfg_chn                              0x7F
#define set_XVR_Reg0x24_cur_cfg_chn(val)                        addXVR_Reg0x24 = ((addXVR_Reg0x24 & (~0x7F)) | ((val) << 0))
#define get_XVR_Reg0x24_cur_cfg_chn                             (addXVR_Reg0x24 & 0x7F)

//addXVR_Reg0x25
#define addXVR_Reg0x25                                          *((volatile unsigned long *) (0x00806E00+0x25*4))

#define posXVR_Reg0x25_vco_kcal_en                              16
#define bitXVR_Reg0x25_vco_kcal_en                              0x10000
#define set_XVR_Reg0x25_vco_kcal_en(val)                        addXVR_Reg0x25 = ((addXVR_Reg0x25 & (~0x10000)) | ((val) << 16))
#define setf_XVR_Reg0x25_vco_kcal_en                            addXVR_Reg0x25 |= 0x10000
#define clrf_XVR_Reg0x25_vco_kcal_en                            addXVR_Reg0x25 &= ~0x10000
#define get_XVR_Reg0x25_vco_kcal_en                             ((addXVR_Reg0x25 & 0x10000) >> 16)


#define posXVR_Reg0x25_test_radio                               13
#define bitXVR_Reg0x25_test_radio                               0x2000
#define set_XVR_Reg0x25_test_radio(val)                         addXVR_Reg0x25 = ((addXVR_Reg0x25 & (~0x2000)) | ((val) << 13))
#define setf_XVR_Reg0x25_test_radio                             addXVR_Reg0x25 |= 0x2000
#define clrf_XVR_Reg0x25_test_radio                             addXVR_Reg0x25 &= ~0x2000
#define get_XVR_Reg0x25_test_radio                              ((addXVR_Reg0x25 & 0x2000) >> 13)

#define posXVR_Reg0x25_test_tmode                               12
#define bitXVR_Reg0x25_test_tmode                               0x1000
#define set_XVR_Reg0x25_test_tmode(val)                         addXVR_Reg0x25 = ((addXVR_Reg0x25 & (~0x1000)) | ((val) << 12))
#define setf_XVR_Reg0x25_test_tmode                             addXVR_Reg0x25 |= 0x1000
#define clrf_XVR_Reg0x25_test_tmode                             addXVR_Reg0x25 &= ~0x1000
#define get_XVR_Reg0x25_test_tmode                              ((addXVR_Reg0x25 & 0x1000) >> 12)

#define posXVR_Reg0x25_pn9_send_en                              11
#define bitXVR_Reg0x25_pn9_send_en                              0x800
#define set_XVR_Reg0x25_pn9_send_en(val)                        addXVR_Reg0x25 = ((addXVR_Reg0x25 & (~0x800)) | ((val) << 11))
#define setf_XVR_Reg0x25_pn9_send_en                            addXVR_Reg0x25 |= 0x800
#define clrf_XVR_Reg0x25_pn9_send_en                            addXVR_Reg0x25 &= ~0x800
#define get_XVR_Reg0x25_pn9_send_en                             ((addXVR_Reg0x25 & 0x800) >> 11)

#define posXVR_Reg0x25_pn9_recv_en                              10
#define bitXVR_Reg0x25_pn9_recv_en                              0x400
#define set_XVR_Reg0x25_pn9_recv_en(val)                        addXVR_Reg0x25 = ((addXVR_Reg0x25 & (~0x400)) | ((val) << 10))
#define setf_XVR_Reg0x25_pn9_recv_en                            addXVR_Reg0x25 |= 0x400
#define clrf_XVR_Reg0x25_pn9_recv_en                            addXVR_Reg0x25 &= ~0x400
#define get_XVR_Reg0x25_pn9_recv_en                             ((addXVR_Reg0x25 & 0x400) >> 10)

#define posXVR_Reg0x25_pn9_hold_en                              9
#define bitXVR_Reg0x25_pn9_hold_en                              0x200
#define set_XVR_Reg0x25_pn9_hold_en(val)                        addXVR_Reg0x25 = ((addXVR_Reg0x25 & (~0x200)) | ((val) << 9))
#define setf_XVR_Reg0x25_pn9_hold_en                            addXVR_Reg0x25 |= 0x200
#define clrf_XVR_Reg0x25_pn9_hold_en                            addXVR_Reg0x25 &= ~0x200
#define get_XVR_Reg0x25_pn9_hold_en                             ((addXVR_Reg0x25 & 0x200) >> 9)

#define posXVR_Reg0x25_pat_send_en                              8
#define bitXVR_Reg0x25_pat_send_en                              0x100
#define set_XVR_Reg0x25_pat_send_en(val)                        addXVR_Reg0x25 = ((addXVR_Reg0x25 & (~0x100)) | ((val) << 8))
#define setf_XVR_Reg0x25_pat_send_en                            addXVR_Reg0x25 |= 0x100
#define clrf_XVR_Reg0x25_pat_send_en                            addXVR_Reg0x25 &= ~0x100
#define get_XVR_Reg0x25_pat_send_en                             ((addXVR_Reg0x25 & 0x100) >> 8)

#define posXVR_Reg0x25_test_pattern                             0
#define bitXVR_Reg0x25_test_pattern                             0xFF
#define set_XVR_Reg0x25_test_pattern(val)                       addXVR_Reg0x25 = ((addXVR_Reg0x25 & (~0xFF)) | ((val) << 0))
#define get_XVR_Reg0x25_test_pattern                            (addXVR_Reg0x25 & 0xFF)

//addXVR_Reg0x26
#define addXVR_Reg0x26                                          *((volatile unsigned long *) (0x00806E00+0x26*4))

#define posXVR_Reg0x26_mod_coefficient                          16
#define bitXVR_Reg0x26_mod_coefficient                          0x1FFF0000
#define set_XVR_Reg0x26_mod_coefficient(val)                    addXVR_Reg0x26 = ((addXVR_Reg0x26 & (~0x1FFF0000)) | ((val) << 16))
#define get_XVR_Reg0x26_mod_coefficient                         ((addXVR_Reg0x26 & 0x1FFF0000) >> 16)



#define posXVR_Reg0x26_txb_reverse                              13
#define bitXVR_Reg0x26_txb_reverse                              0x2000
#define set_XVR_Reg0x26_txb_reverse(val)                        addXVR_Reg0x26 = ((addXVR_Reg0x26 & (~0x2000)) | ((val) << 13))
#define setf_XVR_Reg0x26_txb_reverse                            addXVR_Reg0x26 |= 0x2000
#define clrf_XVR_Reg0x26_txb_reverse                            addXVR_Reg0x26 &= ~0x2000
#define get_XVR_Reg0x26_txb_reverse                             ((addXVR_Reg0x26 & 0x2000) >> 13)

#define posXVR_Reg0x26_pn25ena_cfg                              12
#define bitXVR_Reg0x26_pn25ena_cfg                              0x1000
#define set_XVR_Reg0x26_pn25ena_cfg(val)                        addXVR_Reg0x26 = ((addXVR_Reg0x26 & (~0x1000)) | ((val) << 12))
#define setf_XVR_Reg0x26_pn25ena_cfg                            addXVR_Reg0x26 |= 0x1000
#define clrf_XVR_Reg0x26_pn25ena_cfg                            addXVR_Reg0x26 &= ~0x1000
#define get_XVR_Reg0x26_pn25ena_cfg                             ((addXVR_Reg0x26 & 0x1000) >> 12)

#define posXVR_Reg0x26_open_loop_en                             11
#define bitXVR_Reg0x26_open_loop_en                             0x800
#define set_XVR_Reg0x26_open_loop_en(val)                       addXVR_Reg0x26 = ((addXVR_Reg0x26 & (~0x800)) | ((val) << 11))
#define setf_XVR_Reg0x26_open_loop_en                           addXVR_Reg0x26 |= 0x800
#define clrf_XVR_Reg0x26_open_loop_en                           addXVR_Reg0x26 &= ~0x800
#define get_XVR_Reg0x26_open_loop_en                            ((addXVR_Reg0x26 & 0x800) >> 11)

#define posXVR_Reg0x26_rx_if_select                             10
#define bitXVR_Reg0x26_rx_if_select                             0x400
#define set_XVR_Reg0x26_rx_if_select(val)                       addXVR_Reg0x26 = ((addXVR_Reg0x26 & (~0x400)) | ((val) << 10))
#define setf_XVR_Reg0x26_rx_if_select                           addXVR_Reg0x26 |= 0x400
#define clrf_XVR_Reg0x26_rx_if_select                           addXVR_Reg0x26 &= ~0x400
#define get_XVR_Reg0x26_rx_if_select                            ((addXVR_Reg0x26 & 0x400) >> 10)

#define posXVR_Reg0x26_clksel_cfg                               9
#define bitXVR_Reg0x26_clksel_cfg                               0x200
#define set_XVR_Reg0x26_clksel_cfg(val)                         addXVR_Reg0x26 = ((addXVR_Reg0x26 & (~0x200)) | ((val) << 9))
#define setf_XVR_Reg0x26_clksel_cfg                             addXVR_Reg0x26 |= 0x200
#define clrf_XVR_Reg0x26_clksel_cfg                             addXVR_Reg0x26 &= ~0x200
#define get_XVR_Reg0x26_clksel_cfg                              ((addXVR_Reg0x26 & 0x200) >> 9)

#define posXVR_Reg0x26_sdm3bit_cfg                              8
#define bitXVR_Reg0x26_sdm3bit_cfg                              0x100
#define set_XVR_Reg0x26_sdm3bit_cfg(val)                        addXVR_Reg0x26 = ((addXVR_Reg0x26 & (~0x100)) | ((val) << 8))
#define setf_XVR_Reg0x26_sdm3bit_cfg                            addXVR_Reg0x26 |= 0x100
#define clrf_XVR_Reg0x26_sdm3bit_cfg                            addXVR_Reg0x26 &= ~0x100
#define get_XVR_Reg0x26_sdm3bit_cfg                             ((addXVR_Reg0x26 & 0x100) >> 8)

#define posXVR_Reg0x26_mod2sdm_delay                            4
#define bitXVR_Reg0x26_mod2sdm_delay                            0xF0
#define set_XVR_Reg0x26_mod2sdm_delay(val)                      addXVR_Reg0x26 = ((addXVR_Reg0x26 & (~0xF0)) | ((val) << 4))
#define get_XVR_Reg0x26_mod2sdm_delay                           ((addXVR_Reg0x26 & 0xF0) >> 4)

#define posXVR_Reg0x26_mod2dac_delay                            0
#define bitXVR_Reg0x26_mod2dac_delay                            0xF
#define set_XVR_Reg0x26_mod2dac_delay(val)                      addXVR_Reg0x26 = ((addXVR_Reg0x26 & (~0xF)) | ((val) << 0))
#define get_XVR_Reg0x26_mod2dac_delay                           (addXVR_Reg0x26 & 0xF)

//addXVR_Reg0x27
#define addXVR_Reg0x27                                          *((volatile unsigned long *) (0x00806E00+0x27*4))

#define posXVR_Reg0x27_tbfalcon_reset                           20
#define bitXVR_Reg0x27_tbfalcon_reset                           0x100000
#define set_XVR_Reg0x27_tbfalcon_reset(val)                     addXVR_Reg0x27 = ((addXVR_Reg0x27 & (~0x100000)) | ((val) << 20))
#define setf_XVR_Reg0x27_tbfalcon_reset                         addXVR_Reg0x27 |= 0x100000
#define clrf_XVR_Reg0x27_tbfalcon_reset                         addXVR_Reg0x27 &= ~0x100000
#define get_XVR_Reg0x27_tbfalcon_reset                          ((addXVR_Reg0x27 & 0x100000) >> 20)


//addXVR_Reg0x28
#define addXVR_Reg0x28                                          *((volatile unsigned long *) (0x00806E00+0x28*4))
#define posXVR_Reg0x28_tdly_vcoen                               24
#define bitXVR_Reg0x28_tdly_vcoen                               0xFF000000
#define set_XVR_Reg0x28_tdly_vcoen(val)                         addXVR_Reg0x28 = ((addXVR_Reg0x28 & (~0xFF000000)) | ((val) << 24))
#define get_XVR_Reg0x28_tdly_vcoen                              ((addXVR_Reg0x28 & 0xFF000000) >> 24)

#define posXVR_Reg0x28_tdly_pllen                               16
#define bitXVR_Reg0x28_tdly_pllen                               0xFF0000
#define set_XVR_Reg0x28_tdly_pllen(val)                         addXVR_Reg0x28 = ((addXVR_Reg0x28 & (~0xFF0000)) | ((val) << 16))
#define get_XVR_Reg0x28_tdly_pllen                              ((addXVR_Reg0x28 & 0xFF0000) >> 16)

#define posXVR_Reg0x28_tdly_pllfs                               8
#define bitXVR_Reg0x28_tdly_pllfs                               0xFF00
#define set_XVR_Reg0x28_tdly_pllfs(val)                         addXVR_Reg0x28 = ((addXVR_Reg0x28 & (~0xFF00)) | ((val) << 8))
#define get_XVR_Reg0x28_tdly_pllfs                              ((addXVR_Reg0x28 & 0xFF00) >> 8)

#define posXVR_Reg0x28_tdly_pllms                               0
#define bitXVR_Reg0x28_tdly_pllms                               0xFF
#define set_XVR_Reg0x28_tdly_pllms(val)                         addXVR_Reg0x28 = ((addXVR_Reg0x28 & (~0xFF)) | ((val) << 0))
#define get_XVR_Reg0x28_tdly_pllms                              (addXVR_Reg0x28 & 0xFF)

//addXVR_Reg0x29
#define addXVR_Reg0x29                                          *((volatile unsigned long *) (0x00806E00+0x29*4))

#define posXVR_Reg0x29_tdly_openlp                              15
#define bitXVR_Reg0x29_tdly_openlp                              0x1F8000
#define set_XVR_Reg0x29_tdly_openlp(val)                        addXVR_Reg0x29 = ((addXVR_Reg0x29 & (~0x1F8000)) | ((val) << 15))
#define get_XVR_Reg0x29_tdly_openlp                             ((addXVR_Reg0x29 & 0x1F8000) >> 15)

#define posXVR_Reg0x29_tdly_errdet                              9
#define bitXVR_Reg0x29_tdly_errdet                              0x7E00
#define set_XVR_Reg0x29_tdly_errdet(val)                        addXVR_Reg0x29 = ((addXVR_Reg0x29 & (~0x7E00)) | ((val) << 9))
#define get_XVR_Reg0x29_tdly_errdet                             ((addXVR_Reg0x29 & 0x7E00) >> 9)

#define posXVR_Reg0x29_state_index                              0
#define bitXVR_Reg0x29_state_index                              0x1FF
#define set_XVR_Reg0x29_state_index(val)                        addXVR_Reg0x29 = ((addXVR_Reg0x29 & (~0x1FF)) | ((val) << 0))
#define get_XVR_Reg0x29_state_index                             (addXVR_Reg0x29 & 0x1FF)

//addXVR_Reg0x2a
#define addXVR_Reg0x2a                                          *((volatile unsigned long *) (0x00806E00+0x2a*4))
#define posXVR_Reg0x2a_rf_tx_delay                              24
#define bitXVR_Reg0x2a_rf_tx_delay                              0xFF000000
#define set_XVR_Reg0x2a_rf_tx_delay(val)                        addXVR_Reg0x2a = ((addXVR_Reg0x2a & (~0xFF000000)) | ((val) << 24))
#define get_XVR_Reg0x2a_rf_tx_delay                             ((addXVR_Reg0x2a & 0xFF000000) >> 24)

#define posXVR_Reg0x2a_rf_rx_delay                              16
#define bitXVR_Reg0x2a_rf_rx_delay                              0xFF0000
#define set_XVR_Reg0x2a_rf_rx_delay(val)                        addXVR_Reg0x2a = ((addXVR_Reg0x2a & (~0xFF0000)) | ((val) << 16))
#define get_XVR_Reg0x2a_rf_rx_delay                             ((addXVR_Reg0x2a & 0xFF0000) >> 16)

#define posXVR_Reg0x2a_txslot_time                              8
#define bitXVR_Reg0x2a_txslot_time                              0xFF00
#define set_XVR_Reg0x2a_txslot_time(val)                        addXVR_Reg0x2a = ((addXVR_Reg0x2a & (~0xFF00)) | ((val) << 8))
#define get_XVR_Reg0x2a_txslot_time                             ((addXVR_Reg0x2a & 0xFF00) >> 8)

#define posXVR_Reg0x2a_rxslot_time                              0
#define bitXVR_Reg0x2a_rxslot_time                              0xFF
#define set_XVR_Reg0x2a_rxslot_time(val)                        addXVR_Reg0x2a = ((addXVR_Reg0x2a & (~0xFF)) | ((val) << 0))
#define get_XVR_Reg0x2a_rxslot_time                             (addXVR_Reg0x2a & 0xFF)

//addXVR_Reg0x2b
#define addXVR_Reg0x2b                                          *((volatile unsigned long *) (0x00806E00+0x2b*4))
#define posXVR_Reg0x2b_rf_tx_delay_2m                           8
#define bitXVR_Reg0x2b_rf_tx_delay_2m                           0xFF00
#define set_XVR_Reg0x2b_rf_tx_delay_2m(val)                     addXVR_Reg0x2b = ((addXVR_Reg0x2b & (~0xFF00)) | ((val) << 8))
#define get_XVR_Reg0x2b_rf_tx_delay_2m                          ((addXVR_Reg0x2b & 0xFF00) >> 8)

#define posXVR_Reg0x2b_rf_rx_delay_2m                           0
#define bitXVR_Reg0x2b_rf_rx_delay_2m                           0xFF
#define set_XVR_Reg0x2b_rf_rx_delay_2m(val)                     addXVR_Reg0x2b = ((addXVR_Reg0x2b & (~0xFF)) | ((val) << 0))
#define get_XVR_Reg0x2b_rf_rx_delay_2m                          (addXVR_Reg0x2b & 0xFF)

//addXVR_Reg0x2c
#define addXVR_Reg0x2c                                          *((volatile unsigned long *) (0x00806E00+0x2c*4))
#define posXVR_Reg0x2c_radion_time_bk24                         24
#define bitXVR_Reg0x2c_radion_time_bk24                         0x7F000000
#define set_XVR_Reg0x2c_radion_time_bk24(val)                   addXVR_Reg0x2c = ((addXVR_Reg0x2c & (~0x7F000000)) | ((val) << 24))
#define get_XVR_Reg0x2c_radion_time_bk24                        ((addXVR_Reg0x2c & 0x7F000000) >> 24)


#define posXVR_Reg0x2c_txslot_time_bk24                         8
#define bitXVR_Reg0x2c_txslot_time_bk24                         0x3FFFF00
#define set_XVR_Reg0x2c_txslot_time_bk24(val)                   addXVR_Reg0x2c = ((addXVR_Reg0x2c & (~0x3FFFF00)) | ((val) << 8))
#define get_XVR_Reg0x2c_txslot_time_bk24                        ((addXVR_Reg0x2c & 0x3FFFF00) >> 8)

#define posXVR_Reg0x2c_rxslot_time_bk24                         0
#define bitXVR_Reg0x2c_rxslot_time_bk24                         0xFF
#define set_XVR_Reg0x2c_rxslot_time_bk24(val)                   addXVR_Reg0x2c = ((addXVR_Reg0x2c & (~0xFF)) | ((val) << 0))
#define get_XVR_Reg0x2c_rxslot_time_bk24                        (addXVR_Reg0x2c & 0xFF)

//addXVR_Reg0x2d
#define addXVR_Reg0x2d                                          *((volatile unsigned long *) (0x00806E00+0x2d*4))

#define posXVR_Reg0x2d_tdly_pa0on                               21
#define bitXVR_Reg0x2d_tdly_pa0on                               0x3E00000
#define set_XVR_Reg0x2d_tdly_pa0on(val)                         addXVR_Reg0x2d = ((addXVR_Reg0x2d & (~0x3E00000)) | ((val) << 21))
#define get_XVR_Reg0x2d_tdly_pa0on                              ((addXVR_Reg0x2d & 0x3E00000) >> 21)

#define posXVR_Reg0x2d_tdly_pa0off                              16
#define bitXVR_Reg0x2d_tdly_pa0off                              0x1F0000
#define set_XVR_Reg0x2d_tdly_pa0off(val)                        addXVR_Reg0x2d = ((addXVR_Reg0x2d & (~0x1F0000)) | ((val) << 16))
#define get_XVR_Reg0x2d_tdly_pa0off                             ((addXVR_Reg0x2d & 0x1F0000) >> 16)

#define posXVR_Reg0x2d_pa0_upslope                              13
#define bitXVR_Reg0x2d_pa0_upslope                              0xE000
#define set_XVR_Reg0x2d_pa0_upslope(val)                        addXVR_Reg0x2d = ((addXVR_Reg0x2d & (~0xE000)) | ((val) << 13))
#define get_XVR_Reg0x2d_pa0_upslope                             ((addXVR_Reg0x2d & 0xE000) >> 13)

#define posXVR_Reg0x2d_pa0_dnslope                              10
#define bitXVR_Reg0x2d_pa0_dnslope                              0x1C00
#define set_XVR_Reg0x2d_pa0_dnslope(val)                        addXVR_Reg0x2d = ((addXVR_Reg0x2d & (~0x1C00)) | ((val) << 10))
#define get_XVR_Reg0x2d_pa0_dnslope                             ((addXVR_Reg0x2d & 0x1C00) >> 10)

#define posXVR_Reg0x2d_tdly_pa0rup                              5
#define bitXVR_Reg0x2d_tdly_pa0rup                              0x3E0
#define set_XVR_Reg0x2d_tdly_pa0rup(val)                        addXVR_Reg0x2d = ((addXVR_Reg0x2d & (~0x3E0)) | ((val) << 5))
#define get_XVR_Reg0x2d_tdly_pa0rup                             ((addXVR_Reg0x2d & 0x3E0) >> 5)

#define posXVR_Reg0x2d_tdly_pa0fdn                              0
#define bitXVR_Reg0x2d_tdly_pa0fdn                              0x1F
#define set_XVR_Reg0x2d_tdly_pa0fdn(val)                        addXVR_Reg0x2d = ((addXVR_Reg0x2d & (~0x1F)) | ((val) << 0))
#define get_XVR_Reg0x2d_tdly_pa0fdn                             (addXVR_Reg0x2d & 0x1F)

//addXVR_Reg0x2e
#define addXVR_Reg0x2e                                          *((volatile unsigned long *) (0x00806E00+0x2e*4))

#define posXVR_Reg0x2e_tx_dev_tune                              0
#define bitXVR_Reg0x2e_tx_dev_tune                              0xFF
#define set_XVR_Reg0x2e_tx_dev_tune(val)                        addXVR_Reg0x2e = ((addXVR_Reg0x2e & (~0xFF)) | ((val) << 0))
#define get_XVR_Reg0x2e_tx_dev_tune                             (addXVR_Reg0x2e & 0xFF)

//addXVR_Reg0x2f
#define addXVR_Reg0x2f                                          *((volatile unsigned long *) (0x00806E00+0x2f*4))

//addXVR_Reg0x30
#define addXVR_Reg0x30                                          *((volatile unsigned long *) (0x00806E00+0x30*4))

#define posXVR_Reg0x30_kmod_comp_set                            20
#define bitXVR_Reg0x30_kmod_comp_set                            0x1FF00000
#define set_XVR_Reg0x30_kmod_comp_set(val)                      addXVR_Reg0x30 = ((addXVR_Reg0x30 & (~0x1FF00000)) | ((val) << 20))
#define get_XVR_Reg0x30_kmod_comp_set                           ((addXVR_Reg0x30 & 0x1FF00000) >> 20)


#define posXVR_Reg0x30_fm_gain                                  8
#define bitXVR_Reg0x30_fm_gain                                  0x1FF00
#define set_XVR_Reg0x30_fm_gain(val)                            addXVR_Reg0x30 = ((addXVR_Reg0x30 & (~0x1FF00)) | ((val) << 8))
#define get_XVR_Reg0x30_fm_gain                                 ((addXVR_Reg0x30 & 0x1FF00) >> 8)


#define posXVR_Reg0x30_moddata_d                                4
#define bitXVR_Reg0x30_moddata_d                                0x10
#define set_XVR_Reg0x30_moddata_d(val)                          addXVR_Reg0x30 = ((addXVR_Reg0x30 & (~0x10)) | ((val) << 4))
#define setf_XVR_Reg0x30_moddata_d                              addXVR_Reg0x30 |= 0x10
#define clrf_XVR_Reg0x30_moddata_d                              addXVR_Reg0x30 &= ~0x10
#define get_XVR_Reg0x30_moddata_d                               ((addXVR_Reg0x30 & 0x10) >> 4)

#define posXVR_Reg0x30_bp_kmod_ch_comp                          3
#define bitXVR_Reg0x30_bp_kmod_ch_comp                          0x8
#define set_XVR_Reg0x30_bp_kmod_ch_comp(val)                    addXVR_Reg0x30 = ((addXVR_Reg0x30 & (~0x8)) | ((val) << 3))
#define setf_XVR_Reg0x30_bp_kmod_ch_comp                        addXVR_Reg0x30 |= 0x8
#define clrf_XVR_Reg0x30_bp_kmod_ch_comp                        addXVR_Reg0x30 &= ~0x8
#define get_XVR_Reg0x30_bp_kmod_ch_comp                         ((addXVR_Reg0x30 & 0x8) >> 3)

#define posXVR_Reg0x30_gauss_freq_dir                           2
#define bitXVR_Reg0x30_gauss_freq_dir                           0x4
#define set_XVR_Reg0x30_gauss_freq_dir(val)                     addXVR_Reg0x30 = ((addXVR_Reg0x30 & (~0x4)) | ((val) << 2))
#define setf_XVR_Reg0x30_gauss_freq_dir                         addXVR_Reg0x30 |= 0x4
#define clrf_XVR_Reg0x30_gauss_freq_dir                         addXVR_Reg0x30 &= ~0x4
#define get_XVR_Reg0x30_gauss_freq_dir                          ((addXVR_Reg0x30 & 0x4) >> 2)

#define posXVR_Reg0x30_gauss_bt                                 0
#define bitXVR_Reg0x30_gauss_bt                                 0x3
#define set_XVR_Reg0x30_gauss_bt(val)                           addXVR_Reg0x30 = ((addXVR_Reg0x30 & (~0x3)) | ((val) << 0))
#define get_XVR_Reg0x30_gauss_bt                                (addXVR_Reg0x30 & 0x3)

//addXVR_Reg0x31
#define addXVR_Reg0x31                                          *((volatile unsigned long *) (0x00806E00+0x31*4))

//addXVR_Reg0x32
#define addXVR_Reg0x32                                          *((volatile unsigned long *) (0x00806E00+0x32*4))

//addXVR_Reg0x33
#define addXVR_Reg0x33                                          *((volatile unsigned long *) (0x00806E00+0x33*4))

//addXVR_Reg0x34
#define addXVR_Reg0x34                                          *((volatile unsigned long *) (0x00806E00+0x34*4))

//addXVR_Reg0x35
#define addXVR_Reg0x35                                          *((volatile unsigned long *) (0x00806E00+0x35*4))

//addXVR_Reg0x36
#define addXVR_Reg0x36                                          *((volatile unsigned long *) (0x00806E00+0x36*4))

//addXVR_Reg0x37
#define addXVR_Reg0x37                                          *((volatile unsigned long *) (0x00806E00+0x37*4))

//addXVR_Reg0x38
#define addXVR_Reg0x38                                          *((volatile unsigned long *) (0x00806E00+0x38*4))

//addXVR_Reg0x39
#define addXVR_Reg0x39                                          *((volatile unsigned long *) (0x00806E00+0x39*4))

//addXVR_Reg0x3a
#define addXVR_Reg0x3a                                          *((volatile unsigned long *) (0x00806E00+0x3a*4))

#define posXVR_Reg0x3a_filt_160k                                27
#define bitXVR_Reg0x3a_filt_160k                                0x8000000
#define set_XVR_Reg0x3a_filt_160k(val)                          addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x8000000)) | ((val) << 27))
#define setf_XVR_Reg0x3a_filt_160k                              addXVR_Reg0x3a |= 0x8000000
#define clrf_XVR_Reg0x3a_filt_160k                              addXVR_Reg0x3a &= ~0x8000000
#define get_XVR_Reg0x3a_filt_160k                               ((addXVR_Reg0x3a & 0x8000000) >> 27)

#define posXVR_Reg0x3a_set_adci_0                               26
#define bitXVR_Reg0x3a_set_adci_0                               0x4000000
#define set_XVR_Reg0x3a_set_adci_0(val)                         addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x4000000)) | ((val) << 26))
#define setf_XVR_Reg0x3a_set_adci_0                             addXVR_Reg0x3a |= 0x4000000
#define clrf_XVR_Reg0x3a_set_adci_0                             addXVR_Reg0x3a &= ~0x4000000
#define get_XVR_Reg0x3a_set_adci_0                              ((addXVR_Reg0x3a & 0x4000000) >> 26)

#define posXVR_Reg0x3a_set_adcq_0                               25
#define bitXVR_Reg0x3a_set_adcq_0                               0x2000000
#define set_XVR_Reg0x3a_set_adcq_0(val)                         addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x2000000)) | ((val) << 25))
#define setf_XVR_Reg0x3a_set_adcq_0                             addXVR_Reg0x3a |= 0x2000000
#define clrf_XVR_Reg0x3a_set_adcq_0                             addXVR_Reg0x3a &= ~0x2000000
#define get_XVR_Reg0x3a_set_adcq_0                              ((addXVR_Reg0x3a & 0x2000000) >> 25)

#define posXVR_Reg0x3a_rx_filter1_sel                           24
#define bitXVR_Reg0x3a_rx_filter1_sel                           0x1000000
#define set_XVR_Reg0x3a_rx_filter1_sel(val)                     addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x1000000)) | ((val) << 24))
#define setf_XVR_Reg0x3a_rx_filter1_sel                         addXVR_Reg0x3a |= 0x1000000
#define clrf_XVR_Reg0x3a_rx_filter1_sel                         addXVR_Reg0x3a &= ~0x1000000
#define get_XVR_Reg0x3a_rx_filter1_sel                          ((addXVR_Reg0x3a & 0x1000000) >> 24)

#define posXVR_Reg0x3a_rx_filter2_sel                           23
#define bitXVR_Reg0x3a_rx_filter2_sel                           0x800000
#define set_XVR_Reg0x3a_rx_filter2_sel(val)                     addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x800000)) | ((val) << 23))
#define setf_XVR_Reg0x3a_rx_filter2_sel                         addXVR_Reg0x3a |= 0x800000
#define clrf_XVR_Reg0x3a_rx_filter2_sel                         addXVR_Reg0x3a &= ~0x800000
#define get_XVR_Reg0x3a_rx_filter2_sel                          ((addXVR_Reg0x3a & 0x800000) >> 23)

#define posXVR_Reg0x3a_iq_reverse                               22
#define bitXVR_Reg0x3a_iq_reverse                               0x400000
#define set_XVR_Reg0x3a_iq_reverse(val)                         addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x400000)) | ((val) << 22))
#define setf_XVR_Reg0x3a_iq_reverse                             addXVR_Reg0x3a |= 0x400000
#define clrf_XVR_Reg0x3a_iq_reverse                             addXVR_Reg0x3a &= ~0x400000
#define get_XVR_Reg0x3a_iq_reverse                              ((addXVR_Reg0x3a & 0x400000) >> 22)

#define posXVR_Reg0x3a_bit_reverse                              21
#define bitXVR_Reg0x3a_bit_reverse                              0x200000
#define set_XVR_Reg0x3a_bit_reverse(val)                        addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x200000)) | ((val) << 21))
#define setf_XVR_Reg0x3a_bit_reverse                            addXVR_Reg0x3a |= 0x200000
#define clrf_XVR_Reg0x3a_bit_reverse                            addXVR_Reg0x3a &= ~0x200000
#define get_XVR_Reg0x3a_bit_reverse                             ((addXVR_Reg0x3a & 0x200000) >> 21)

#define posXVR_Reg0x3a_freq_dir                                 20
#define bitXVR_Reg0x3a_freq_dir                                 0x100000
#define set_XVR_Reg0x3a_freq_dir(val)                           addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x100000)) | ((val) << 20))
#define setf_XVR_Reg0x3a_freq_dir                               addXVR_Reg0x3a |= 0x100000
#define clrf_XVR_Reg0x3a_freq_dir                               addXVR_Reg0x3a &= ~0x100000
#define get_XVR_Reg0x3a_freq_dir                                ((addXVR_Reg0x3a & 0x100000) >> 20)

#define posXVR_Reg0x3a_bp_dcflt                                 19
#define bitXVR_Reg0x3a_bp_dcflt                                 0x80000
#define set_XVR_Reg0x3a_bp_dcflt(val)                           addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x80000)) | ((val) << 19))
#define setf_XVR_Reg0x3a_bp_dcflt                               addXVR_Reg0x3a |= 0x80000
#define clrf_XVR_Reg0x3a_bp_dcflt                               addXVR_Reg0x3a &= ~0x80000
#define get_XVR_Reg0x3a_bp_dcflt                                ((addXVR_Reg0x3a & 0x80000) >> 19)

#define posXVR_Reg0x3a_adc_gain                                 16
#define bitXVR_Reg0x3a_adc_gain                                 0x70000
#define set_XVR_Reg0x3a_adc_gain(val)                           addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x70000)) | ((val) << 16))
#define get_XVR_Reg0x3a_adc_gain                                ((addXVR_Reg0x3a & 0x70000) >> 16)

#define posXVR_Reg0x3a_bps_track_en                             14
#define bitXVR_Reg0x3a_bps_track_en                             0x4000
#define set_XVR_Reg0x3a_bps_track_en(val)                       addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x4000)) | ((val) << 14))
#define setf_XVR_Reg0x3a_bps_track_en                           addXVR_Reg0x3a |= 0x4000
#define clrf_XVR_Reg0x3a_bps_track_en                           addXVR_Reg0x3a &= ~0x4000
#define get_XVR_Reg0x3a_bps_track_en                            ((addXVR_Reg0x3a & 0x4000) >> 14)

#define posXVR_Reg0x3a_pre_dc_bps                               13
#define bitXVR_Reg0x3a_pre_dc_bps                               0x2000
#define set_XVR_Reg0x3a_pre_dc_bps(val)                         addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x2000)) | ((val) << 13))
#define setf_XVR_Reg0x3a_pre_dc_bps                             addXVR_Reg0x3a |= 0x2000
#define clrf_XVR_Reg0x3a_pre_dc_bps                             addXVR_Reg0x3a &= ~0x2000
#define get_XVR_Reg0x3a_pre_dc_bps                              ((addXVR_Reg0x3a & 0x2000) >> 13)

#define posXVR_Reg0x3a_pre_dc_manual                            12
#define bitXVR_Reg0x3a_pre_dc_manual                            0x1000
#define set_XVR_Reg0x3a_pre_dc_manual(val)                      addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0x1000)) | ((val) << 12))
#define setf_XVR_Reg0x3a_pre_dc_manual                          addXVR_Reg0x3a |= 0x1000
#define clrf_XVR_Reg0x3a_pre_dc_manual                          addXVR_Reg0x3a &= ~0x1000
#define get_XVR_Reg0x3a_pre_dc_manual                           ((addXVR_Reg0x3a & 0x1000) >> 12)

#define posXVR_Reg0x3a_pre_dc_in                                0
#define bitXVR_Reg0x3a_pre_dc_in                                0xFFF
#define set_XVR_Reg0x3a_pre_dc_in(val)                          addXVR_Reg0x3a = ((addXVR_Reg0x3a & (~0xFFF)) | ((val) << 0))
#define get_XVR_Reg0x3a_pre_dc_in                               (addXVR_Reg0x3a & 0xFFF)

//addXVR_Reg0x3b
#define addXVR_Reg0x3b                                          *((volatile unsigned long *) (0x00806E00+0x3b*4))
#define posXVR_Reg0x3b_test_bus_ena                             31
#define bitXVR_Reg0x3b_test_bus_ena                             0x80000000
#define set_XVR_Reg0x3b_test_bus_ena(val)                       addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0x80000000)) | ((val) << 31))
#define setf_XVR_Reg0x3b_test_bus_ena                           addXVR_Reg0x3b |= 0x80000000
#define clrf_XVR_Reg0x3b_test_bus_ena                           addXVR_Reg0x3b &= ~0x80000000
#define get_XVR_Reg0x3b_test_bus_ena                            ((addXVR_Reg0x3b & 0x80000000) >> 31)

#define posXVR_Reg0x3b_samp_sel                                 30
#define bitXVR_Reg0x3b_samp_sel                                 0x40000000
#define set_XVR_Reg0x3b_samp_sel(val)                           addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0x40000000)) | ((val) << 30))
#define setf_XVR_Reg0x3b_samp_sel                               addXVR_Reg0x3b |= 0x40000000
#define clrf_XVR_Reg0x3b_samp_sel                               addXVR_Reg0x3b &= ~0x40000000
#define get_XVR_Reg0x3b_samp_sel                                ((addXVR_Reg0x3b & 0x40000000) >> 30)


#define posXVR_Reg0x3b_slot_delay                               24
#define bitXVR_Reg0x3b_slot_delay                               0x1F000000
#define set_XVR_Reg0x3b_slot_delay(val)                         addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0x1F000000)) | ((val) << 24))
#define get_XVR_Reg0x3b_slot_delay                              ((addXVR_Reg0x3b & 0x1F000000) >> 24)

#define posXVR_Reg0x3b_sync_err_thrd                            20
#define bitXVR_Reg0x3b_sync_err_thrd                            0xF00000
#define set_XVR_Reg0x3b_sync_err_thrd(val)                      addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0xF00000)) | ((val) << 20))
#define get_XVR_Reg0x3b_sync_err_thrd                           ((addXVR_Reg0x3b & 0xF00000) >> 20)


#define posXVR_Reg0x3b_bps_demod                                15
#define bitXVR_Reg0x3b_bps_demod                                0x8000
#define set_XVR_Reg0x3b_bps_demod(val)                          addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0x8000)) | ((val) << 15))
#define setf_XVR_Reg0x3b_bps_demod                              addXVR_Reg0x3b |= 0x8000
#define clrf_XVR_Reg0x3b_bps_demod                              addXVR_Reg0x3b &= ~0x8000
#define get_XVR_Reg0x3b_bps_demod                               ((addXVR_Reg0x3b & 0x8000) >> 15)


#define posXVR_Reg0x3b_syncwd_order                             13
#define bitXVR_Reg0x3b_syncwd_order                             0x2000
#define set_XVR_Reg0x3b_syncwd_order(val)                       addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0x2000)) | ((val) << 13))
#define setf_XVR_Reg0x3b_syncwd_order                           addXVR_Reg0x3b |= 0x2000
#define clrf_XVR_Reg0x3b_syncwd_order                           addXVR_Reg0x3b &= ~0x2000
#define get_XVR_Reg0x3b_syncwd_order                            ((addXVR_Reg0x3b & 0x2000) >> 13)

#define posXVR_Reg0x3b_m_mode                                   12
#define bitXVR_Reg0x3b_m_mode                                   0x1000
#define set_XVR_Reg0x3b_m_mode(val)                             addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0x1000)) | ((val) << 12))
#define setf_XVR_Reg0x3b_m_mode                                 addXVR_Reg0x3b |= 0x1000
#define clrf_XVR_Reg0x3b_m_mode                                 addXVR_Reg0x3b &= ~0x1000
#define get_XVR_Reg0x3b_m_mode                                  ((addXVR_Reg0x3b & 0x1000) >> 12)

#define posXVR_Reg0x3b_m0_bits_thrd                             9
#define bitXVR_Reg0x3b_m0_bits_thrd                             0xE00
#define set_XVR_Reg0x3b_m0_bits_thrd(val)                       addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0xE00)) | ((val) << 9))
#define get_XVR_Reg0x3b_m0_bits_thrd                            ((addXVR_Reg0x3b & 0xE00) >> 9)

#define posXVR_Reg0x3b_m0_phase_thrd                            6
#define bitXVR_Reg0x3b_m0_phase_thrd                            0x1C0
#define set_XVR_Reg0x3b_m0_phase_thrd(val)                      addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0x1C0)) | ((val) << 6))
#define get_XVR_Reg0x3b_m0_phase_thrd                           ((addXVR_Reg0x3b & 0x1C0) >> 6)

#define posXVR_Reg0x3b_bp_eq                                    4
#define bitXVR_Reg0x3b_bp_eq                                    0x10
#define set_XVR_Reg0x3b_bp_eq(val)                              addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0x10)) | ((val) << 4))
#define setf_XVR_Reg0x3b_bp_eq                                  addXVR_Reg0x3b |= 0x10
#define clrf_XVR_Reg0x3b_bp_eq                                  addXVR_Reg0x3b &= ~0x10
#define get_XVR_Reg0x3b_bp_eq                                   ((addXVR_Reg0x3b & 0x10) >> 4)

#define posXVR_Reg0x3b_pre_dc_num                               2
#define bitXVR_Reg0x3b_pre_dc_num                               0xC
#define set_XVR_Reg0x3b_pre_dc_num(val)                         addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0xC)) | ((val) << 2))
#define get_XVR_Reg0x3b_pre_dc_num                              ((addXVR_Reg0x3b & 0xC) >> 2)

#define posXVR_Reg0x3b_no_eq_set                                1
#define bitXVR_Reg0x3b_no_eq_set                                0x2
#define set_XVR_Reg0x3b_no_eq_set(val)                          addXVR_Reg0x3b = ((addXVR_Reg0x3b & (~0x2)) | ((val) << 1))
#define setf_XVR_Reg0x3b_no_eq_set                              addXVR_Reg0x3b |= 0x2
#define clrf_XVR_Reg0x3b_no_eq_set                              addXVR_Reg0x3b &= ~0x2
#define get_XVR_Reg0x3b_no_eq_set                               ((addXVR_Reg0x3b & 0x2) >> 1)

//addXVR_Reg0x3c
#define addXVR_Reg0x3c                                          *((volatile unsigned long *) (0x00806E00+0x3c*4))
#define posXVR_Reg0x3c_bp_agc                                   31
#define bitXVR_Reg0x3c_bp_agc                                   0x80000000
#define set_XVR_Reg0x3c_bp_agc(val)                             addXVR_Reg0x3c = ((addXVR_Reg0x3c & (~0x80000000)) | ((val) << 31))
#define setf_XVR_Reg0x3c_bp_agc                                 addXVR_Reg0x3c |= 0x80000000
#define clrf_XVR_Reg0x3c_bp_agc                                 addXVR_Reg0x3c &= ~0x80000000
#define get_XVR_Reg0x3c_bp_agc                                  ((addXVR_Reg0x3c & 0x80000000) >> 31)


#define posXVR_Reg0x3c_init_rx_gain                             16
#define bitXVR_Reg0x3c_init_rx_gain                             0x1FF0000
#define set_XVR_Reg0x3c_init_rx_gain(val)                       addXVR_Reg0x3c = ((addXVR_Reg0x3c & (~0x1FF0000)) | ((val) << 16))
#define get_XVR_Reg0x3c_init_rx_gain                            ((addXVR_Reg0x3c & 0x1FF0000) >> 16)

#define posXVR_Reg0x3c_rssi_thrd                                8
#define bitXVR_Reg0x3c_rssi_thrd                                0xFF00
#define set_XVR_Reg0x3c_rssi_thrd(val)                          addXVR_Reg0x3c = ((addXVR_Reg0x3c & (~0xFF00)) | ((val) << 8))
#define get_XVR_Reg0x3c_rssi_thrd                               ((addXVR_Reg0x3c & 0xFF00) >> 8)

#define posXVR_Reg0x3c_adc_rssi_flt                             7
#define bitXVR_Reg0x3c_adc_rssi_flt                             0x80
#define set_XVR_Reg0x3c_adc_rssi_flt(val)                       addXVR_Reg0x3c = ((addXVR_Reg0x3c & (~0x80)) | ((val) << 7))
#define setf_XVR_Reg0x3c_adc_rssi_flt                           addXVR_Reg0x3c |= 0x80
#define clrf_XVR_Reg0x3c_adc_rssi_flt                           addXVR_Reg0x3c &= ~0x80
#define get_XVR_Reg0x3c_adc_rssi_flt                            ((addXVR_Reg0x3c & 0x80) >> 7)


//addXVR_Reg0x3d
#define addXVR_Reg0x3d                                          *((volatile unsigned long *) (0x00806E00+0x3d*4))

#define posXVR_Reg0x3d_force_telink                             14
#define bitXVR_Reg0x3d_force_telink                             0x4000
#define set_XVR_Reg0x3d_force_telink(val)                       addXVR_Reg0x3d = ((addXVR_Reg0x3d & (~0x4000)) | ((val) << 14))
#define setf_XVR_Reg0x3d_force_telink                           addXVR_Reg0x3d |= 0x4000
#define clrf_XVR_Reg0x3d_force_telink                           addXVR_Reg0x3d &= ~0x4000
#define get_XVR_Reg0x3d_force_telink                            ((addXVR_Reg0x3d & 0x4000) >> 14)

#define posXVR_Reg0x3d_telink_pos                               11
#define bitXVR_Reg0x3d_telink_pos                               0x3800
#define set_XVR_Reg0x3d_telink_pos(val)                         addXVR_Reg0x3d = ((addXVR_Reg0x3d & (~0x3800)) | ((val) << 11))
#define get_XVR_Reg0x3d_telink_pos                              ((addXVR_Reg0x3d & 0x3800) >> 11)

#define posXVR_Reg0x3d_eq_coef_set                              10
#define bitXVR_Reg0x3d_eq_coef_set                              0x400
#define set_XVR_Reg0x3d_eq_coef_set(val)                        addXVR_Reg0x3d = ((addXVR_Reg0x3d & (~0x400)) | ((val) << 10))
#define setf_XVR_Reg0x3d_eq_coef_set                            addXVR_Reg0x3d |= 0x400
#define clrf_XVR_Reg0x3d_eq_coef_set                            addXVR_Reg0x3d &= ~0x400
#define get_XVR_Reg0x3d_eq_coef_set                             ((addXVR_Reg0x3d & 0x400) >> 10)

#define posXVR_Reg0x3d_eq_coef_ini                              0
#define bitXVR_Reg0x3d_eq_coef_ini                              0x3FF
#define set_XVR_Reg0x3d_eq_coef_ini(val)                        addXVR_Reg0x3d = ((addXVR_Reg0x3d & (~0x3FF)) | ((val) << 0))
#define get_XVR_Reg0x3d_eq_coef_ini                             (addXVR_Reg0x3d & 0x3FF)

//addXVR_Reg0x3e
#define addXVR_Reg0x3e                                          *((volatile unsigned long *) (0x00806E00+0x3e*4))

#define posXVR_Reg0x3e_lr_win_dc_bps                            22
#define bitXVR_Reg0x3e_lr_win_dc_bps                            0x400000
#define set_XVR_Reg0x3e_lr_win_dc_bps(val)                      addXVR_Reg0x3e = ((addXVR_Reg0x3e & (~0x400000)) | ((val) << 22))
#define setf_XVR_Reg0x3e_lr_win_dc_bps                          addXVR_Reg0x3e |= 0x400000
#define clrf_XVR_Reg0x3e_lr_win_dc_bps                          addXVR_Reg0x3e &= ~0x400000
#define get_XVR_Reg0x3e_lr_win_dc_bps                           ((addXVR_Reg0x3e & 0x400000) >> 22)

#define posXVR_Reg0x3e_sum1_max_thrd                            16
#define bitXVR_Reg0x3e_sum1_max_thrd                            0x3F0000
#define set_XVR_Reg0x3e_sum1_max_thrd(val)                      addXVR_Reg0x3e = ((addXVR_Reg0x3e & (~0x3F0000)) | ((val) << 16))
#define get_XVR_Reg0x3e_sum1_max_thrd                           ((addXVR_Reg0x3e & 0x3F0000) >> 16)

#define posXVR_Reg0x3e_lr_win_en                                15
#define bitXVR_Reg0x3e_lr_win_en                                0x8000
#define set_XVR_Reg0x3e_lr_win_en(val)                          addXVR_Reg0x3e = ((addXVR_Reg0x3e & (~0x8000)) | ((val) << 15))
#define setf_XVR_Reg0x3e_lr_win_en                              addXVR_Reg0x3e |= 0x8000
#define clrf_XVR_Reg0x3e_lr_win_en                              addXVR_Reg0x3e &= ~0x8000
#define get_XVR_Reg0x3e_lr_win_en                               ((addXVR_Reg0x3e & 0x8000) >> 15)

#define posXVR_Reg0x3e_lr_win_thrd                              12
#define bitXVR_Reg0x3e_lr_win_thrd                              0x7000
#define set_XVR_Reg0x3e_lr_win_thrd(val)                        addXVR_Reg0x3e = ((addXVR_Reg0x3e & (~0x7000)) | ((val) << 12))
#define get_XVR_Reg0x3e_lr_win_thrd                             ((addXVR_Reg0x3e & 0x7000) >> 12)


#define posXVR_Reg0x3e_m0_phase_thrd_lr                         8
#define bitXVR_Reg0x3e_m0_phase_thrd_lr                         0x700
#define set_XVR_Reg0x3e_m0_phase_thrd_lr(val)                   addXVR_Reg0x3e = ((addXVR_Reg0x3e & (~0x700)) | ((val) << 8))
#define get_XVR_Reg0x3e_m0_phase_thrd_lr                        ((addXVR_Reg0x3e & 0x700) >> 8)

#define posXVR_Reg0x3e_bb_lr_sel                                7
#define bitXVR_Reg0x3e_bb_lr_sel                                0x80
#define set_XVR_Reg0x3e_bb_lr_sel(val)                          addXVR_Reg0x3e = ((addXVR_Reg0x3e & (~0x80)) | ((val) << 7))
#define setf_XVR_Reg0x3e_bb_lr_sel                              addXVR_Reg0x3e |= 0x80
#define clrf_XVR_Reg0x3e_bb_lr_sel                              addXVR_Reg0x3e &= ~0x80
#define get_XVR_Reg0x3e_bb_lr_sel                               ((addXVR_Reg0x3e & 0x80) >> 7)

#define posXVR_Reg0x3e_lr_sync_comp_en                          6
#define bitXVR_Reg0x3e_lr_sync_comp_en                          0x40
#define set_XVR_Reg0x3e_lr_sync_comp_en(val)                    addXVR_Reg0x3e = ((addXVR_Reg0x3e & (~0x40)) | ((val) << 6))
#define setf_XVR_Reg0x3e_lr_sync_comp_en                        addXVR_Reg0x3e |= 0x40
#define clrf_XVR_Reg0x3e_lr_sync_comp_en                        addXVR_Reg0x3e &= ~0x40
#define get_XVR_Reg0x3e_lr_sync_comp_en                         ((addXVR_Reg0x3e & 0x40) >> 6)

#define posXVR_Reg0x3e_m0_bits_thrd_lr                          3
#define bitXVR_Reg0x3e_m0_bits_thrd_lr                          0x38
#define set_XVR_Reg0x3e_m0_bits_thrd_lr(val)                    addXVR_Reg0x3e = ((addXVR_Reg0x3e & (~0x38)) | ((val) << 3))
#define get_XVR_Reg0x3e_m0_bits_thrd_lr                         ((addXVR_Reg0x3e & 0x38) >> 3)

#define posXVR_Reg0x3e_rsync_bits_thrd_lr                       0
#define bitXVR_Reg0x3e_rsync_bits_thrd_lr                       0x7
#define set_XVR_Reg0x3e_rsync_bits_thrd_lr(val)                 addXVR_Reg0x3e = ((addXVR_Reg0x3e & (~0x7)) | ((val) << 0))
#define get_XVR_Reg0x3e_rsync_bits_thrd_lr                      (addXVR_Reg0x3e & 0x7)

//addXVR_Reg0x3f
#define addXVR_Reg0x3f                                          *((volatile unsigned long *) (0x00806E00+0x3f*4))

//addXVR_Reg0x40
#define addXVR_Reg0x40                                          *((volatile unsigned long *) (0x00806E00+0x40*4))

//addXVR_Reg0x41
#define addXVR_Reg0x41                                          *((volatile unsigned long *) (0x00806E00+0x41*4))

//addXVR_Reg0x42
#define addXVR_Reg0x42                                          *((volatile unsigned long *) (0x00806E00+0x42*4))

//addXVR_Reg0x43
#define addXVR_Reg0x43                                          *((volatile unsigned long *) (0x00806E00+0x43*4))

//addXVR_Reg0x44
#define addXVR_Reg0x44                                          *((volatile unsigned long *) (0x00806E00+0x44*4))

//addXVR_Reg0x45
#define addXVR_Reg0x45                                          *((volatile unsigned long *) (0x00806E00+0x45*4))

//addXVR_Reg0x46
#define addXVR_Reg0x46                                          *((volatile unsigned long *) (0x00806E00+0x46*4))

//addXVR_Reg0x47
#define addXVR_Reg0x47                                          *((volatile unsigned long *) (0x00806E00+0x47*4))

//addXVR_Reg0x48
#define addXVR_Reg0x48                                          *((volatile unsigned long *) (0x00806E00+0x48*4))

//addXVR_Reg0x49
#define addXVR_Reg0x49                                          *((volatile unsigned long *) (0x00806E00+0x49*4))

//addXVR_Reg0x4a
#define addXVR_Reg0x4a                                          *((volatile unsigned long *) (0x00806E00+0x4a*4))

//addXVR_Reg0x4b
#define addXVR_Reg0x4b                                          *((volatile unsigned long *) (0x00806E00+0x4b*4))

//addXVR_Reg0x4c
#define addXVR_Reg0x4c                                          *((volatile unsigned long *) (0x00806E00+0x4c*4))

//addXVR_Reg0x4d
#define addXVR_Reg0x4d                                          *((volatile unsigned long *) (0x00806E00+0x4d*4))

//addXVR_Reg0x4e
#define addXVR_Reg0x4e                                          *((volatile unsigned long *) (0x00806E00+0x4e*4))

//addXVR_Reg0x4f
#define addXVR_Reg0x4f                                          *((volatile unsigned long *) (0x00806E00+0x4f*4))


#endif

