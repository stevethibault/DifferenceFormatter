# Install script for directory: C:/Projects/DifferenceFormatter/src/sdks/ctemplate

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
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Projects/DifferenceFormatter/src/sdks/lib/Debug/ctemplate.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Projects/DifferenceFormatter/src/sdks/lib/Release/ctemplate.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Projects/DifferenceFormatter/src/sdks/lib/MinSizeRel/ctemplate.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Projects/DifferenceFormatter/src/sdks/lib/RelWithDebInfo/ctemplate.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ctemplate" TYPE FILE FILES
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/find_ptr.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/per_expand_data.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/str_ref.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template_annotator.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template_cache.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template_dictionary.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template_dictionary_interface.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template_emitter.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template_enums.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template_modifiers.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template_namelist.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template_pathops.h"
    "C:/Projects/DifferenceFormatter/src/sdks/ctemplate/ctemplate/template_string.h"
    )
endif()

