if ( CMAKE_SYSTEM MATCHES "Linux" AND NOT ANDROID )
    if (NOT BUILD_TYPE)
      string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE)
    endif (NOT BUILD_TYPE)

  set(ROOT "${CMAKE_SOURCE_DIR}/..")
  set(BUILD_DIRECTORY "${CMAKE_BINARY_DIR}")
  if (NOT SDKS_DIRECTORY)
    set(SDKS_DIRECTORY "${SDKS_STAGING_DIRECTORY}")
  endif (NOT SDKS_DIRECTORY)
  
else ( CMAKE_SYSTEM MATCHES "Linux" AND NOT ANDROID )
  set(BUILD_DIRECTORY "${ROOT}/build/mako/\$(Configuration)")
  set(SDKS_DIRECTORY "${ROOT}/build/sdks/\$(Configuration)")
endif ( CMAKE_SYSTEM MATCHES "Linux" AND NOT ANDROID )

set(TEST_DIRECTORY "${ROOT}/bin")
set(DESC_DIRECTORY "${ROOT}/webserver/server/message")

# Clear any includes inherited from a parent project.  Really we should switch to use target_include_directories going forward.
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES "")

include_directories("${ROOT}/include")
include_directories("${ROOT}/include/sdks")
include_directories(${SDKS_DIRECTORY}/include)
link_directories(${SDKS_DIRECTORY}/lib ${BUILD_DIRECTORY})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BUILD_DIRECTORY}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIRECTORY}")

foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BUILD_DIRECTORY} )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BUILD_DIRECTORY} )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BUILD_DIRECTORY} )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

if (WIN32)
elseif ((CMAKE_SYSTEM MATCHES "Linux") AND NOT ANDROID )
  if (CMAKE_BUILD_TYPE MATCHES "Debug")
    set(POCO_LIBRARY_SUFFIX "d")
  endif(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(POCO_FOUNDATION_LIB "PocoFoundation${POCO_LIBRARY_SUFFIX}")
  set(POCO_UTIL_LIB "PocoUtil${POCO_LIBRARY_SUFFIX}")
  set(POCO_XML_LIB "PocoXML${POCO_LIBRARY_SUFFIX}")
  set(POCO_NET_LIB "PocoNet${POCO_LIBRARY_SUFFIX}")
  set(UNITTEST_LIB UnitTest++)
  # set(LTTNG_LIB lttng-ust)
  set(THREADS rt pthread dl)
endif()

set(UNITTEST_MAIN "${ROOT}/src/sdks/unittest++/UnitTestMain.cpp")

set(SDKS_LIBS ${POCO_FOUNDATION_LIB} ${POCO_UTIL_LIB} ${POCO_XML_LIB} ${THREADS})


include(CopyInclude)
include(CopyBinaries)

function (enable_code_coverage)
endfunction(enable_code_coverage)

if (WIN32)
	add_definitions(-D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS -DNOMINMAX)
elseif (UNIX)
	execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
	if (GCC_VERSION VERSION_GREATER 4.9 OR GCC_VERSION VERSION_EQUAL 4.9)
		set(CMAKE_CXX_FLAGS -std=c++1y)
	elseif (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
		set(CMAKE_CXX_FLAGS -std=c++11)
	else()
		set(CMAKE_CXX_FLAGS -std=c++0x)
	endif()
endif()
