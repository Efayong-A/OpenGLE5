# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/semag/Desktop/GLImac-Template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/semag/Desktop/GLImac-Template/build

# Include any dependencies generated for this target.
include TP_garbage/CMakeFiles/TP_garbage_foo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include TP_garbage/CMakeFiles/TP_garbage_foo.dir/compiler_depend.make

# Include the progress variables for this target.
include TP_garbage/CMakeFiles/TP_garbage_foo.dir/progress.make

# Include the compile flags for this target's objects.
include TP_garbage/CMakeFiles/TP_garbage_foo.dir/flags.make

TP_garbage/CMakeFiles/TP_garbage_foo.dir/foo.cpp.o: TP_garbage/CMakeFiles/TP_garbage_foo.dir/flags.make
TP_garbage/CMakeFiles/TP_garbage_foo.dir/foo.cpp.o: ../TP_garbage/foo.cpp
TP_garbage/CMakeFiles/TP_garbage_foo.dir/foo.cpp.o: TP_garbage/CMakeFiles/TP_garbage_foo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/semag/Desktop/GLImac-Template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP_garbage/CMakeFiles/TP_garbage_foo.dir/foo.cpp.o"
	cd /home/semag/Desktop/GLImac-Template/build/TP_garbage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT TP_garbage/CMakeFiles/TP_garbage_foo.dir/foo.cpp.o -MF CMakeFiles/TP_garbage_foo.dir/foo.cpp.o.d -o CMakeFiles/TP_garbage_foo.dir/foo.cpp.o -c /home/semag/Desktop/GLImac-Template/TP_garbage/foo.cpp

TP_garbage/CMakeFiles/TP_garbage_foo.dir/foo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_garbage_foo.dir/foo.cpp.i"
	cd /home/semag/Desktop/GLImac-Template/build/TP_garbage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/semag/Desktop/GLImac-Template/TP_garbage/foo.cpp > CMakeFiles/TP_garbage_foo.dir/foo.cpp.i

TP_garbage/CMakeFiles/TP_garbage_foo.dir/foo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_garbage_foo.dir/foo.cpp.s"
	cd /home/semag/Desktop/GLImac-Template/build/TP_garbage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/semag/Desktop/GLImac-Template/TP_garbage/foo.cpp -o CMakeFiles/TP_garbage_foo.dir/foo.cpp.s

# Object files for target TP_garbage_foo
TP_garbage_foo_OBJECTS = \
"CMakeFiles/TP_garbage_foo.dir/foo.cpp.o"

# External object files for target TP_garbage_foo
TP_garbage_foo_EXTERNAL_OBJECTS =

TP_garbage/TP_garbage_foo: TP_garbage/CMakeFiles/TP_garbage_foo.dir/foo.cpp.o
TP_garbage/TP_garbage_foo: TP_garbage/CMakeFiles/TP_garbage_foo.dir/build.make
TP_garbage/TP_garbage_foo: glimac/libglimac.a
TP_garbage/TP_garbage_foo: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP_garbage/TP_garbage_foo: /usr/lib/x86_64-linux-gnu/libSDL.so
TP_garbage/TP_garbage_foo: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP_garbage/TP_garbage_foo: ../third-party/libGLEW.a
TP_garbage/TP_garbage_foo: TP_garbage/CMakeFiles/TP_garbage_foo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/semag/Desktop/GLImac-Template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP_garbage_foo"
	cd /home/semag/Desktop/GLImac-Template/build/TP_garbage && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP_garbage_foo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP_garbage/CMakeFiles/TP_garbage_foo.dir/build: TP_garbage/TP_garbage_foo
.PHONY : TP_garbage/CMakeFiles/TP_garbage_foo.dir/build

TP_garbage/CMakeFiles/TP_garbage_foo.dir/clean:
	cd /home/semag/Desktop/GLImac-Template/build/TP_garbage && $(CMAKE_COMMAND) -P CMakeFiles/TP_garbage_foo.dir/cmake_clean.cmake
.PHONY : TP_garbage/CMakeFiles/TP_garbage_foo.dir/clean

TP_garbage/CMakeFiles/TP_garbage_foo.dir/depend:
	cd /home/semag/Desktop/GLImac-Template/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/semag/Desktop/GLImac-Template /home/semag/Desktop/GLImac-Template/TP_garbage /home/semag/Desktop/GLImac-Template/build /home/semag/Desktop/GLImac-Template/build/TP_garbage /home/semag/Desktop/GLImac-Template/build/TP_garbage/CMakeFiles/TP_garbage_foo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP_garbage/CMakeFiles/TP_garbage_foo.dir/depend

