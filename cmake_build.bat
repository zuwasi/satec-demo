@echo off
reg add HKEY_CURRENT_USER\Console /v QuickEdit /t REG_DWORD /d 00000000 /f

cd /d %~dp0

SET PATH=%PATH%;..\..\..\..\Tools\build_tools\CMake_3.21.2\bin
SET PATH=%PATH%;..\..\..\..\Tools\build_tools\Ninja_build


set /a StartS=%time:~6,2%
set /a StartM=%time:~3,2%


if "%1" equ "clean" (
rd /S /Q build
exit /b 0
echo: 
echo ***************BUILD CLEAN FINISH********************
echo: 
exit /b
)
echo: 
echo ***************BUILD START**************
echo: 
echo -------------- Pre Build -----------------
if not exist build (
    md build
)
cd build
del *.txt *.bin *.map *.dmp *.elf
cmake ../../../ -G "Ninja"
set /a preBuildErr=%errorlevel%
echo:pre build error=%preBuildErr%
if %preBuildErr% neq 0 (
echo -------------- Pre Build Failed ---------
pause
exit /b %preBuildErr%
)

echo:
echo -------------- Main Build ----------------
echo:
cmake --build .
set /a mainBuildErr=%errorlevel%
echo: main build error=%mainBuildErr%
if %mainBuildErr% neq 0 (
echo -------------- Main Build Failed ---------
pause
exit /b %mainBuildErr%
)

for /f %%a in ('dir /b *.elf') do ( @set elf_file=%%~na)
arm-none-eabi-objdump -d     %elf_file%.elf    > %elf_file%.dmp
arm-none-eabi-nm  -S -n      %elf_file%.elf    > %elf_file%.map
arm-none-eabi-readelf       %elf_file%.elf -a > %elf_file%.txt
arm-none-eabi-objcopy -O binary %elf_file%.elf  %elf_file%.bin

if not exist %elf_file%.bin (
echo %elf_file%.bin not exist
goto _BUILD_FAILED
)
arm-none-eabi-size      %elf_file%.elf


set "outputPath=..\output\"
set "appFolder=%outputPath%app"

if not exist "%appFolder%" (
    echo Creating "app" folder...
    mkdir "%appFolder%"
    echo "app" folder created successfully.
) 

copy %elf_file%.bin ..\output\app\%elf_file%.bin
cd ..\
powershell .\output\BinConvert  -oad ./output/boot/BK3437_BIM.bin  ./output/stack/bk3437_stack_gcc.bin ./output/app/%elf_file%.bin -m 0x1000 -l 0x1E200 -v 0x000f -rom_v 0x0004 -e 00000000 00000000 00000000 00000000

echo: 
echo **************BUILD FINISHED**************
set /a EndS=%time:~6,2%
set /a EndM=%time:~3,2%
set /a difftime=(%EndM%*60+%EndS%)-(%StartM%*60+%StartS%)
set /a diffM=%difftime%/60
set /a diffS=%difftime%-(%diffM%*60)
if %diffM% neq 0 (
    echo Compile Time: %diffM%min %diffS%s
) else (
    echo Compile Time: %diffS%s
)
echo ----%time%-----

pause
exit /b


:_BUILD_FAILED
echo: 
echo ***************BUILD ALL.BAT BUILD FAILED********************
echo: 
pause
exit /b


