IF(NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

SET(OS_BUILD_TAG win)
SET(CONFIG_TAG "")

IF(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
	SET(MACHINE_TAG ix86)
ELSE()
	SET(MACHINE_TAG x86_64)
ENDIF()

SET(BUILD_DIRECTORY "${ROOT}/build/mako/${OS_BUILD_TAG}/${MACHINE_TAG}/${CMAKE_BUILD_TYPE}")
SET(SDKS_DIRECTORY "${ROOT}/build/sdks/${OS_BUILD_TAG}/${MACHINE_TAG}/${CMAKE_BUILD_TYPE}")

INCLUDE_DIRECTORIES("${ROOT}/include")
INCLUDE_DIRECTORIES("${ROOT}/include/sdks")
LINK_DIRECTORIES(${SDKS_DIRECTORY} ${BUILD_DIRECTORY})

SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${ROOT}/build/mako/${OS_BUILD_TAG}/${MACHINE_TAG}/${CONFIG_TAG}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ROOT}/build/mako/${OS_BUILD_TAG}/${MACHINE_TAG}/${CONFIG_TAG}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ROOT}/build/mako/${OS_BUILD_TAG}/${MACHINE_TAG}/${CONFIG_TAG}")


SET(SDKS_LIBS  ${POCO_FOUNDATION_LIB} ${POCO_UTIL_LIB} ${POCO_XML_LIB} ${THREADS})
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /subsystem:windows")

INCLUDE(CopyInclude)
INCLUDE(CopyBinaries)
INCLUDE(Tracing)

add_definitions(-D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS -D_AFXDLL)