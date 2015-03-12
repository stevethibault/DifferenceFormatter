# CMake entry point
cmake_minimum_required (VERSION 2.8)
project (DifferenceFomatter)

set(LIB_PATH /usr/lib/x86_64-linux-gnu/ /usr/local/lib/)
set(POCO_INCLUDE_PATH /usr/local/include)


set(POCO_LIBS PocoFoundationd PocoNetd PocoUtild)


set(ALL_LIBS
    ${POCO_LIBS}
)

include_directories(${POCO_INCLUDE_PATH})
link_directories(${LIB_PATH}/lib ${BUILD_DIRECTORY})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -ggdb")

file(GLOB ALL_SOURCES *.cpp)
file(GLOB ALL_HEADERS *.h)
add_executable(${PROJECT_NAME}
    ${ALL_SOURCES} ${ALL_HEADERS}
)

target_link_libraries(${PROJECT_NAME}
    ${ALL_LIBS}
)
