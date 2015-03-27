cmake_minimum_required( VERSION 2.7 )

if(WIN32)
  install (FILES bin/diff.exe bin/libiconv2.dll bin/libintl3.dll  DESTINATION "bin")
endif()
