cmake_minimum_required( VERSION 2.7 )

if(WIN32)
  install (FILES diff.exe libiconv2.dll libintl3.dll  DESTINATION "bin")
endif()
