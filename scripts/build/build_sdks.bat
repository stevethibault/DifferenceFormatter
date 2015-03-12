:: Build sdks
:: Usage: build_sdks <BuildType> <VSVersion>
::		BuildType - Debug or Release [default: Debug]
::		VSVersion - vs2013, vs2012 or vs2010 [default: highest installed version]
@echo on

set CURRENT_DIR=%CD%
cd ..\..
set DEVROOT="%CD%"
call %DEVROOT%\scripts\build\setup_vars.bat %*
if %ERRORLEVEL% NEQ 0 goto:eof

set PROJECTROOT=%DEVROOT%\projects\sdks
set BIN_DIRECTORY=%DEVROOT%\build\sdks\%CONFIG%\bin

mkdir %PROJECTROOT%
cd %PROJECTROOT%

call cmake %CMAKE_BUILD_OPTIONS% %DEVROOT%\src\sdks
call cmake --build . --target install --config %CONFIG%


cd %CURRENT_DIR%
