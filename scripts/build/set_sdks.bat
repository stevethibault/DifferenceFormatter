set CONFIG=%1
if ".%CONFIG%" == "." set CONFIG=%MAKO_DEFAULT_CONFIG%
if ".%CONFIG%" == "." set CONFIG=Debug

set BUILD_SCRIPT_DIR=%CD%
cd ..\..
set DEVROOT="%CD%"
cd %BUILD_SCRIPT_DIR%
set BUILDDIR=%DEVROOT%\build\sdks\%CONFIG%
set COPYCMD=xcopy /y/s

mkdir %DEVROOT%\bin\
mkdir %DEVROOT%\include\sdks
%COPYCMD% %BUILDDIR%\bin\*.* %DEVROOT%\bin\
%COPYCMD% %BUILDDIR%\include\*.* %DEVROOT%\include\sdks
