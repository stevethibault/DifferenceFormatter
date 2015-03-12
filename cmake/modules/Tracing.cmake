include_directories("${CMAKE_CURRENT_BINARY_DIR}/GeneratedTracing")

if (__DISABLED_FOR_NOW_)

function(add_tracing _TraceSources)
	set(TraceSources)
	file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/GeneratedTracing")
	foreach(tracepoint_file ${ARGN})
		get_filename_component(stripped_tracepoint_file ${tracepoint_file} NAME)
		message("Adding tracing for ${stripped_tracepoint_file}")
		set (GeneratedFileBase ${CMAKE_CURRENT_BINARY_DIR}/GeneratedTracing/${stripped_tracepoint_file})
		list(APPEND TraceSources ${GeneratedFileBase}.h ${GeneratedFileBase}.c)
		add_custom_command(
			OUTPUT ${GeneratedFileBase}.h ${GeneratedFileBase}.c
			COMMAND  "${SDKS_DIRECTORY}/lttng-gen-tp"
			ARGS -o ${stripped_tracepoint_file}.h -o ${stripped_tracepoint_file}.c ${CMAKE_CURRENT_SOURCE_DIR}/${tracepoint_file}
			WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/GeneratedTracing
			DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${tracepoint_file}
		)
	endforeach()
	set(${_TraceSources} ${TraceSources} PARENT_SCOPE)
endfunction()

else()

function(add_tracing _TraceSources)
	file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/GeneratedTracing")
	foreach(tracepoint_file ${ARGN})
		get_filename_component(tracepoint_file ${tracepoint_file} NAME)
		set (GeneratedFile ${CMAKE_CURRENT_BINARY_DIR}/GeneratedTracing/${tracepoint_file}.h)
		list(APPEND TraceSources ${GeneratedFile})
		file(WRITE ${GeneratedFile} "#pragma once\n\n")
#		file(APPEND ${GeneratedFile} "extern \"C\" { __declspec(dllimport) void __stdcall OutputDebugStringA(const char* lpOutputString); }\n\n")
		file(APPEND ${GeneratedFile} "#define tracepoint(provider, name, ...)  do { /*OutputDebugStringA(\"trace: \" #provider \":\" #name);*/ } while(0)\n")
	endforeach()
endfunction()

endif()
