:: Build typhoon
:: Usage: build_typhoon <BuildType> <VSVersion>
::		BuildType - Debug or Release [default: Debug]
::		VSVersion - vs2013, vs2012 or vs2010 [default: highest installed version]
@echo on

set CURRENT_DIR=%CD%
cd ..\..
set DEVROOT="%CD%"
set PROJECTROOT=%DEVROOT%\projects\mako

call %DEVROOT%\scripts\build\setup_vars.bat %*
if %ERRORLEVEL% NEQ 0 goto:eof

mkdir %PROJECTROOT%
cd %PROJECTROOT%

call cmake %CMAKE_BUILD_OPTIONS% %DEVROOT%\src
call cmake --build . --config %CONFIG%

cd %CURRENT_DIR%
