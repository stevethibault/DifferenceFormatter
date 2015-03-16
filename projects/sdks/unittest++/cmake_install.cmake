# Install script for directory: C:/Projects/DifferenceFormatter/src/sdks/unittest++

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Projects/DifferenceFormatter/projects/sdks/Debug/UnitTest++.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Projects/DifferenceFormatter/projects/sdks/Release/UnitTest++.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Projects/DifferenceFormatter/projects/sdks/MinSizeRel/UnitTest++.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Projects/DifferenceFormatter/projects/sdks/RelWithDebInfo/UnitTest++.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/UnitTest++" TYPE FILE FILES
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/AssertException.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/CheckMacros.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/Checks.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/CompositeTestReporter.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/Config.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/CurrentTest.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/DeferredTestReporter.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/DeferredTestResult.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/ExceptionMacros.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/ExecuteTest.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/HelperMacros.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/MemoryOutStream.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/ReportAssert.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/ReportAssertImpl.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/Test.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/TestDetails.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/TestList.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/TestMacros.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/TestReporter.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/TestReporterStdout.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/TestResults.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/TestRunner.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/TestSuite.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/TimeConstraint.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/TimeHelpers.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/UnitTest++.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/UnitTestPP.h"
    "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/XmlTestReporter.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/UnitTest++/Win32" TYPE FILE FILES "C:/Projects/DifferenceFormatter/src/sdks/unittest++/UnitTest++/Win32/TimeHelpers.h")
endif()

