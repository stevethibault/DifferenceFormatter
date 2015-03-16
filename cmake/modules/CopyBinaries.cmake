function(COPY_BINARIES __PROJECT __BASENAME __BIN_DIRECTORY)
    if (NOT EXISTS ${__BIN_DIRECTORY})
        file(MAKE_DIRECTORY ${__BIN_DIRECTORY})
    endif(NOT EXISTS ${__BIN_DIRECTORY})
    foreach(EXTENSION ${ARGN})
        if ("${EXTENSION}" STREQUAL "_")
            set(FILENAME ${__BASENAME})
        else()
            set(FILENAME ${__BASENAME}.${EXTENSION})
        endif()
        set(SOURCE_PATH ${BUILD_DIRECTORY}/${FILENAME})
        set(DESTINATION_PATH ${__BIN_DIRECTORY}/${FILENAME})
#         message(STATUS "Adding copy step ${SOURCE_PATH} -> ${DESTINATION_PATH}")

        if (ALWAYS_RUN_UNIT_TESTS)
            add_custom_target(copy${__PROJECT}
                ALL
                COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SOURCE_PATH} ${DESTINATION_PATH}
                DEPENDS "${__PROJECT}"
                COMMENT "Copying ${SOURCE_PATH} to ${DESTINATION_PATH}"
                VERBATIM
            )
        else(ALWAYS_RUN_UNIT_TESTS)
            add_custom_command(TARGET ${__PROJECT}
                    POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SOURCE_PATH} ${DESTINATION_PATH}
                    COMMENT "Copying ${SOURCE_PATH} to ${DESTINATION_PATH}"
                    VERBATIM
                )
        endif (ALWAYS_RUN_UNIT_TESTS)
    endforeach(EXTENSION)

endfunction(COPY_BINARIES)

function(COPY_LIBRARY __TARGET __BIN_DIRECTORY)
    if (WIN32)
        COPY_BINARIES(${__TARGET} ${__TARGET} ${__BIN_DIRECTORY} dll)
    else (UNIX)
        COPY_BINARIES(${__TARGET} lib${__TARGET} ${__BIN_DIRECTORY} so)
    endif()
endfunction(COPY_LIBRARY)

function(COPY_EXECUTABLE __TARGET __BIN_DIRECTORY)
    if (WIN32)
        COPY_BINARIES(${__TARGET} ${__TARGET} ${__BIN_DIRECTORY} exe)
    else (UNIX)
        COPY_BINARIES(${__TARGET} ${__TARGET} ${__BIN_DIRECTORY} _)
    endif()
endfunction(COPY_EXECUTABLE)
