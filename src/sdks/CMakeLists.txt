cmake_minimum_required(VERSION 2.6)
project(SDKS)

get_filename_component(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../.. ABSOLUTE)

if (CMAKE_SYSTEM MATCHES "Linux" AND NOT ANDROID )
    find_program(symbolizer NAMES llvm-symbolizer llvm-symbolizer-3.4)
    if (symbolizer MATCHES  "symbolizer-NOTFOUND")
        message(WARNING "${symbolizer}")
    else(symbolizer MATCHES  "symbolizer-NOTFOUND")
        message(STATUS "symbolizer = ${symbolizer}")
        set(ENV{ASAN_SYMBOLIZER_PATH} "${symbolizer}")
        set(ENV{ASAN_OPTIONS} "symbolize=1")
        set(symbolizerFlags " -fsanitize=address -fno-omit-frame-pointer")
    endif(symbolizer MATCHES  "symbolizer-NOTFOUND")

    set (linuxCFlags "")
    set (linuxCxxFlags "-std=c++11")
    set (linuxLinkerFlags "${symbolizerFlags}")
    set (linuxCommonFlags "-fPIC")
    if (CMAKE_CXX_FLAGS)
        set(CMAKE_CXX_FLAGS "${linuxCxxFlags} ${linuxCommonFlags}")
    else (CMAKE_CXX_FLAGS)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${linuxCxxFlags} ${linuxCommonFlags}")
    endif (CMAKE_CXX_FLAGS)
    set (linuxCFlags "-fPIC")
    if (CMAKE_C_FLAGS)
        set(CMAKE_C_FLAGS "${linuxCxxFlags}" ${linuxCommonFlags})
    else (CMAKE_C_FLAGS)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${linuxCFlags} ${linuxCommonFlags}")
    endif (CMAKE_C_FLAGS)
    if (CMAKE_EXE_LINKER_FLAGS)
        set(CMAKE_EXE_LINKER_FLAGS "${linuxLinkerFlags} ${linuxCommonFlags}")
    else (CMAKE_EXE_LINKER_FLAGS)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${linuxLinkerFlags} ${linuxCommonFlags}")
    endif (CMAKE_EXE_LINKER_FLAGS)
    if (NOT BUILD_TYPE)
      string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE)
    endif (NOT BUILD_TYPE)

    option(USE_CLANG "Build using clang" Off)

    if (DEFINED USE_CLANG)
        set(debugFlags "-g -O0")
    else (DEFINED USE_CLANG)
        set(debugFlags "-ggdb3 -Og")
    endif (DEFINED USE_CLANG)

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${debugFlags} ${symbolizerFlags}")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG ${debugFlags}" ${symbolizerFlags}")

    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-O3")

    set(CMAKE_INSTALL_PREFIX "/")

else (CMAKE_SYSTEM MATCHES "Linux" AND NOT ANDROID )
  set(CMAKE_INSTALL_PREFIX "${ROOT}/build/sdks/\${BUILD_TYPE}")
endif (CMAKE_SYSTEM MATCHES "Linux" AND NOT ANDROID )

include_directories("${ROOT}/src/sdks/unittest++")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

set(ZMQ_DISABLE_TESTS 1)
set(ZMQ_DISABLE_PERF_TOOLS 1)
set(ZMQ_DISABLE_LIB_RENAME 1)

set(CMAKE_DEBUG_POSTFIX "")
add_subdirectory(unittest++)
if (CMAKE_SYSTEM MATCHES "Linux" AND NOT ANDROID )
    set(BUILD_SHARED_LIBS "On" CACHE BOOL "BUILD_SHARED_LIBS" FORCE  )
endif (CMAKE_SYSTEM MATCHES "Linux" AND NOT ANDROID )
add_subdirectory(poco-1.5.3)
set(CMAKE_DEBUG_POSTFIX "")


add_subdirectory(Test)


