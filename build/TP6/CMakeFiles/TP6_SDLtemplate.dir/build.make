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
include TP6/CMakeFiles/TP6_SDLtemplate.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include TP6/CMakeFiles/TP6_SDLtemplate.dir/compiler_depend.make

# Include the progress variables for this target.
include TP6/CMakeFiles/TP6_SDLtemplate.dir/progress.make

# Include the compile flags for this target's objects.
include TP6/CMakeFiles/TP6_SDLtemplate.dir/flags.make

TP6/CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.o: TP6/CMakeFiles/TP6_SDLtemplate.dir/flags.make
TP6/CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.o: ../TP6/SDLtemplate.cpp
TP6/CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.o: TP6/CMakeFiles/TP6_SDLtemplate.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/semag/Desktop/GLImac-Template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP6/CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.o"
	cd /home/semag/Desktop/GLImac-Template/build/TP6 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT TP6/CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.o -MF CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.o.d -o CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.o -c /home/semag/Desktop/GLImac-Template/TP6/SDLtemplate.cpp

TP6/CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.i"
	cd /home/semag/Desktop/GLImac-Template/build/TP6 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/semag/Desktop/GLImac-Template/TP6/SDLtemplate.cpp > CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.i

TP6/CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.s"
	cd /home/semag/Desktop/GLImac-Template/build/TP6 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/semag/Desktop/GLImac-Template/TP6/SDLtemplate.cpp -o CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.s

# Object files for target TP6_SDLtemplate
TP6_SDLtemplate_OBJECTS = \
"CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.o"

# External object files for target TP6_SDLtemplate
TP6_SDLtemplate_EXTERNAL_OBJECTS =

TP6/TP6_SDLtemplate: TP6/CMakeFiles/TP6_SDLtemplate.dir/SDLtemplate.cpp.o
TP6/TP6_SDLtemplate: TP6/CMakeFiles/TP6_SDLtemplate.dir/build.make
TP6/TP6_SDLtemplate: glimac/libglimac.a
TP6/TP6_SDLtemplate: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP6/TP6_SDLtemplate: /usr/lib/x86_64-linux-gnu/libSDL.so
TP6/TP6_SDLtemplate: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP6/TP6_SDLtemplate: ../third-party/libGLEW.a
TP6/TP6_SDLtemplate: TP6/CMakeFiles/TP6_SDLtemplate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/semag/Desktop/GLImac-Template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP6_SDLtemplate"
	cd /home/semag/Desktop/GLImac-Template/build/TP6 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP6_SDLtemplate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP6/CMakeFiles/TP6_SDLtemplate.dir/build: TP6/TP6_SDLtemplate
.PHONY : TP6/CMakeFiles/TP6_SDLtemplate.dir/build

TP6/CMakeFiles/TP6_SDLtemplate.dir/clean:
	cd /home/semag/Desktop/GLImac-Template/build/TP6 && $(CMAKE_COMMAND) -P CMakeFiles/TP6_SDLtemplate.dir/cmake_clean.cmake
.PHONY : TP6/CMakeFiles/TP6_SDLtemplate.dir/clean

TP6/CMakeFiles/TP6_SDLtemplate.dir/depend:
	cd /home/semag/Desktop/GLImac-Template/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/semag/Desktop/GLImac-Template /home/semag/Desktop/GLImac-Template/TP6 /home/semag/Desktop/GLImac-Template/build /home/semag/Desktop/GLImac-Template/build/TP6 /home/semag/Desktop/GLImac-Template/build/TP6/CMakeFiles/TP6_SDLtemplate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP6/CMakeFiles/TP6_SDLtemplate.dir/depend

