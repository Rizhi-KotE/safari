@echo off
echo 1 >> 1.txt
rm 1.txt
set bl=false
for /f %%i in (animal.h) do  ((@if "%%i"=="private:" ( set bl=true )) & (@if "%%bl%"=="true"  (echo %%i >> 1.txt)))