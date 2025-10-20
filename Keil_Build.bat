@echo off
set UV=C:\Keil_v5\UV4\UV4.exe
set UV_PRO_PATH=..\stack\prj3437.uvproj
echo Controller buiding ...
echo .>build_log.txt
%UV% -j0 -b %UV_PRO_PATH% -o %cd%\build_log.txt
type build_log.txt
echo Controller build Done.

set UV_PRO_PATH=.\app_3437.uvproj
echo gatt buiding ...
echo .>build_log.txt
%UV% -j0 -b %UV_PRO_PATH% -o %cd%\build_log.txt
type build_log.txt
echo Controller build Done.



