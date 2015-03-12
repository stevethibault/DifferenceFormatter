:: Set up visual studio variables
:: Usage: setup_vars <BuildType> <VSVersion>
::		BuildType - Debug or Release [default: Debug]
::		VSVersion - vs2013, vs2012 or vs2010 [default: highest installed version]


:: Parse BuildType
set CONFIG=%1
if ".%CONFIG%" == "." call:default_config CONFIG

:: Try parsing command line VS version
if "%2" == "vs2013" (
	call "%VS120COMNTOOLS%\vsvars32.bat"
	set CMAKE_BUILD_OPTIONS=-G "Visual Studio 12"
)
if "%2" == "vs2012" (
	call "%VS110COMNTOOLS%\vsvars32.bat"
	set CMAKE_BUILD_OPTIONS=-G "Visual Studio 11"
)
if "%2" == "vs2010" (
	call "%VS100COMNTOOLS%\vsvars32.bat"
	set CMAKE_BUILD_OPTIONS=-G "Visual Studio 10"
)

:: Try get default VS version
if "%DevEnvDir%" == "" (
	call "%VS120COMNTOOLS%\vsvars32.bat"
	set CMAKE_BUILD_OPTIONS=-G "Visual Studio 12"
)
::if "%DevEnvDir%" == "" (
::	call "%VS110COMNTOOLS%\vsvars32.bat"
::	set CMAKE_BUILD_OPTIONS=-G "Visual Studio 11"
::)
if "%DevEnvDir%" == "" (
	call "%VS100COMNTOOLS%\vsvars32.bat"
	set CMAKE_BUILD_OPTIONS=-G "Visual Studio 10"
)

goto:eof

:default_config
SETLOCAL
set CONFIG=%TYPHOON_DEFAULT_CONFIG%
if ".%CONFIG%" == "." set CONFIG=Debug
(ENDLOCAL
	IF "%~1" NEQ "" SET %~1=%CONFIG%
)
goto:eof


:link_error
cd %CURRENT_DIR%
echo Failed to link %DEVROOT%\config directory, build failed (did you disable UAC?)
goto:eof
