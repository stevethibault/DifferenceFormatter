# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/steve/projects/DifferenceFormatter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/steve/projects/DifferenceFormatter

# Include any dependencies generated for this target.
include CMakeFiles/DifferenceFomatter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DifferenceFomatter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DifferenceFomatter.dir/flags.make

CMakeFiles/DifferenceFomatter.dir/main.cpp.o: CMakeFiles/DifferenceFomatter.dir/flags.make
CMakeFiles/DifferenceFomatter.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/steve/projects/DifferenceFormatter/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DifferenceFomatter.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DifferenceFomatter.dir/main.cpp.o -c /home/steve/projects/DifferenceFormatter/main.cpp

CMakeFiles/DifferenceFomatter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DifferenceFomatter.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/steve/projects/DifferenceFormatter/main.cpp > CMakeFiles/DifferenceFomatter.dir/main.cpp.i

CMakeFiles/DifferenceFomatter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DifferenceFomatter.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/steve/projects/DifferenceFormatter/main.cpp -o CMakeFiles/DifferenceFomatter.dir/main.cpp.s

CMakeFiles/DifferenceFomatter.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/DifferenceFomatter.dir/main.cpp.o.requires

CMakeFiles/DifferenceFomatter.dir/main.cpp.o.provides: CMakeFiles/DifferenceFomatter.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DifferenceFomatter.dir/build.make CMakeFiles/DifferenceFomatter.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DifferenceFomatter.dir/main.cpp.o.provides

CMakeFiles/DifferenceFomatter.dir/main.cpp.o.provides.build: CMakeFiles/DifferenceFomatter.dir/main.cpp.o

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o: CMakeFiles/DifferenceFomatter.dir/flags.make
CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o: DifferenceFormatterApp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/steve/projects/DifferenceFormatter/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o -c /home/steve/projects/DifferenceFormatter/DifferenceFormatterApp.cpp

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/steve/projects/DifferenceFormatter/DifferenceFormatterApp.cpp > CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.i

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/steve/projects/DifferenceFormatter/DifferenceFormatterApp.cpp -o CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.s

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o.requires:
.PHONY : CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o.requires

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o.provides: CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o.requires
	$(MAKE) -f CMakeFiles/DifferenceFomatter.dir/build.make CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o.provides.build
.PHONY : CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o.provides

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o.provides.build: CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o: CMakeFiles/DifferenceFomatter.dir/flags.make
CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o: DifferenceFormatter.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/steve/projects/DifferenceFormatter/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o -c /home/steve/projects/DifferenceFormatter/DifferenceFormatter.cpp

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/steve/projects/DifferenceFormatter/DifferenceFormatter.cpp > CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.i

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/steve/projects/DifferenceFormatter/DifferenceFormatter.cpp -o CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.s

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o.requires:
.PHONY : CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o.requires

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o.provides: CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o.requires
	$(MAKE) -f CMakeFiles/DifferenceFomatter.dir/build.make CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o.provides.build
.PHONY : CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o.provides

CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o.provides.build: CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o

CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o: CMakeFiles/DifferenceFomatter.dir/flags.make
CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o: DifferenceParser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/steve/projects/DifferenceFormatter/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o -c /home/steve/projects/DifferenceFormatter/DifferenceParser.cpp

CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/steve/projects/DifferenceFormatter/DifferenceParser.cpp > CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.i

CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/steve/projects/DifferenceFormatter/DifferenceParser.cpp -o CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.s

CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o.requires:
.PHONY : CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o.requires

CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o.provides: CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/DifferenceFomatter.dir/build.make CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o.provides.build
.PHONY : CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o.provides

CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o.provides.build: CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o

# Object files for target DifferenceFomatter
DifferenceFomatter_OBJECTS = \
"CMakeFiles/DifferenceFomatter.dir/main.cpp.o" \
"CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o" \
"CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o" \
"CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o"

# External object files for target DifferenceFomatter
DifferenceFomatter_EXTERNAL_OBJECTS =

DifferenceFomatter: CMakeFiles/DifferenceFomatter.dir/main.cpp.o
DifferenceFomatter: CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o
DifferenceFomatter: CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o
DifferenceFomatter: CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o
DifferenceFomatter: CMakeFiles/DifferenceFomatter.dir/build.make
DifferenceFomatter: CMakeFiles/DifferenceFomatter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable DifferenceFomatter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DifferenceFomatter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DifferenceFomatter.dir/build: DifferenceFomatter
.PHONY : CMakeFiles/DifferenceFomatter.dir/build

CMakeFiles/DifferenceFomatter.dir/requires: CMakeFiles/DifferenceFomatter.dir/main.cpp.o.requires
CMakeFiles/DifferenceFomatter.dir/requires: CMakeFiles/DifferenceFomatter.dir/DifferenceFormatterApp.cpp.o.requires
CMakeFiles/DifferenceFomatter.dir/requires: CMakeFiles/DifferenceFomatter.dir/DifferenceFormatter.cpp.o.requires
CMakeFiles/DifferenceFomatter.dir/requires: CMakeFiles/DifferenceFomatter.dir/DifferenceParser.cpp.o.requires
.PHONY : CMakeFiles/DifferenceFomatter.dir/requires

CMakeFiles/DifferenceFomatter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DifferenceFomatter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DifferenceFomatter.dir/clean

CMakeFiles/DifferenceFomatter.dir/depend:
	cd /home/steve/projects/DifferenceFormatter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/steve/projects/DifferenceFormatter /home/steve/projects/DifferenceFormatter /home/steve/projects/DifferenceFormatter /home/steve/projects/DifferenceFormatter /home/steve/projects/DifferenceFormatter/CMakeFiles/DifferenceFomatter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DifferenceFomatter.dir/depend

