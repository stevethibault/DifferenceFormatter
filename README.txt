Building DifferenceFormatter

1. Install CMake
2. Install Python 2, not python 3. There were changes in the language that are not backwards compatible.
3. Path into Diff\scripts\build and run build_all.bat.

This should take 20 minuts only the first time as SDKS are built. Then run build_mako for full builds
  not including SDKS

Once built if successfull all binaries should be in diff\bin. And a visual studio project in the
diff\Projects folder should be created. This can be used to build, debug, and test.
