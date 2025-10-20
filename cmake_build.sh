#!/bin/bash
if [[ $1 == clean ]]; then
    rm -rf build
    exit
fi

start=$(date +%s)

echo -e "\n==============BUILD START=================\n"
if ! [ -d "build" ]; then
	mkdir "build"
fi
cd build
rm *.txt *.bin *.map *.dmp *.elf
echo -e "-------------- Pre Build -----------------\n"
cmake ../../..

echo -e "\n-------------- Main Build ----------------\n"
make
ELF_FILE=`find *.elf`
TARGET_NAME=${ELF_FILE%.*}
if ! [ -e "$ELF_FILE" ]; then
	echo -e "-------------- Main Build Failed ---------\n"
	exit
fi
arm-none-eabi-objdump -d $ELF_FILE > $TARGET_NAME.dmp
arm-none-eabi-nm  -S -n $ELF_FILE > $TARGET_NAME.map
arm-none-eabi-objcopy -O binary $ELF_FILE $TARGET_NAME.bin
arm-none-eabi-readelf $ELF_FILE -a > $TARGET_NAME.txt
if ! [ -e "$TARGET_NAME.bin" ]; then
	echo -e "-------------- Gen Bin Failed ---------\n"
	exit
fi
echo -e "\n==============Main Build FINISHED==============\n"


outputPath="../output/"
appFolder="${outputPath}app"

if [ ! -d "$appFolder" ]; then
    echo "Creating 'app' folder..."
    mkdir "$appFolder"
    echo "'app' folder created successfully."
else
    echo "'app' folder already exists."
fi

echo -e "\n-------------- Post Build ----------------\n"
cp -R $TARGET_NAME.bin ../output/app
cd ..
./BinConvert -oad ./output/boot/BK3437_BIM.bin ./output/stack/bk3437_stack_gcc.bin ./output/app/$TARGET_NAME.bin -m 0x1000 -l 0x1E200 -v 0x000f -rom_v 0x0004 -e 00000000 00000000 00000000 00000000

echo -e "\n==============BUILD FINISHED==============\n"
end=$(date +%s)
take=$(( end - start ))
echo It took ${take}s to build.

