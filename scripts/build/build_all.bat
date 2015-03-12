:: Build all sources
:: Usage: build_all <BuildType> <VSVersion>
::		BuildType - Debug or Release [default: Debug]
::		VSVersion - vs2013, vs2012 or vs2010 [default: highest installed version]

@echo on

call build_sdks.bat %*
call set_sdks.bat %*
call build_mako.bat %*
