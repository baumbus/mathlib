# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/baumbus/repos/mathlib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/baumbus/repos/mathlib/build

# Include any dependencies generated for this target.
include src/CMakeFiles/math.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/math.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/math.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/math.dir/flags.make

src/CMakeFiles/math.dir/math.cpp.o: src/CMakeFiles/math.dir/flags.make
src/CMakeFiles/math.dir/math.cpp.o: /home/baumbus/repos/mathlib/src/math.cpp
src/CMakeFiles/math.dir/math.cpp.o: src/CMakeFiles/math.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/baumbus/repos/mathlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/math.dir/math.cpp.o"
	cd /home/baumbus/repos/mathlib/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/math.dir/math.cpp.o -MF CMakeFiles/math.dir/math.cpp.o.d -o CMakeFiles/math.dir/math.cpp.o -c /home/baumbus/repos/mathlib/src/math.cpp

src/CMakeFiles/math.dir/math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/math.cpp.i"
	cd /home/baumbus/repos/mathlib/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/baumbus/repos/mathlib/src/math.cpp > CMakeFiles/math.dir/math.cpp.i

src/CMakeFiles/math.dir/math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/math.cpp.s"
	cd /home/baumbus/repos/mathlib/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/baumbus/repos/mathlib/src/math.cpp -o CMakeFiles/math.dir/math.cpp.s

# Object files for target math
math_OBJECTS = \
"CMakeFiles/math.dir/math.cpp.o"

# External object files for target math
math_EXTERNAL_OBJECTS =

src/libmath.a: src/CMakeFiles/math.dir/math.cpp.o
src/libmath.a: src/CMakeFiles/math.dir/build.make
src/libmath.a: src/CMakeFiles/math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/baumbus/repos/mathlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmath.a"
	cd /home/baumbus/repos/mathlib/build/src && $(CMAKE_COMMAND) -P CMakeFiles/math.dir/cmake_clean_target.cmake
	cd /home/baumbus/repos/mathlib/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/math.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/math.dir/build: src/libmath.a
.PHONY : src/CMakeFiles/math.dir/build

src/CMakeFiles/math.dir/clean:
	cd /home/baumbus/repos/mathlib/build/src && $(CMAKE_COMMAND) -P CMakeFiles/math.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/math.dir/clean

src/CMakeFiles/math.dir/depend:
	cd /home/baumbus/repos/mathlib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/baumbus/repos/mathlib /home/baumbus/repos/mathlib/src /home/baumbus/repos/mathlib/build /home/baumbus/repos/mathlib/build/src /home/baumbus/repos/mathlib/build/src/CMakeFiles/math.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/math.dir/depend

