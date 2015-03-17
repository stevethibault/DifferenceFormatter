# Install script for directory: C:/Projects/DifferenceFormatter/src/sdks/poco-1.5.3

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Projects/DifferenceFormatter/build/sdks/${BUILD_TYPE}")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES
    "C:/Program Files (x86)/Microsoft Visual Studio 12.0/VC/redist/x86/Microsoft.VC120.CRT/msvcp120.dll"
    "C:/Program Files (x86)/Microsoft Visual Studio 12.0/VC/redist/x86/Microsoft.VC120.CRT/msvcr120.dll"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Projects/DifferenceFormatter/src/sdks/poco-1.5.3/Foundation/cmake_install.cmake")
  include("C:/Projects/DifferenceFormatter/src/sdks/poco-1.5.3/XML/cmake_install.cmake")
  include("C:/Projects/DifferenceFormatter/src/sdks/poco-1.5.3/JSON/cmake_install.cmake")
  include("C:/Projects/DifferenceFormatter/src/sdks/poco-1.5.3/MongoDB/cmake_install.cmake")
  include("C:/Projects/DifferenceFormatter/src/sdks/poco-1.5.3/PDF/cmake_install.cmake")
  include("C:/Projects/DifferenceFormatter/src/sdks/poco-1.5.3/Util/cmake_install.cmake")
  include("C:/Projects/DifferenceFormatter/src/sdks/poco-1.5.3/Net/cmake_install.cmake")
  include("C:/Projects/DifferenceFormatter/src/sdks/poco-1.5.3/Data/cmake_install.cmake")
  include("C:/Projects/DifferenceFormatter/src/sdks/poco-1.5.3/Zip/cmake_install.cmake")

endif()

