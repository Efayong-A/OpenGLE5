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
include TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/compiler_depend.make

# Include the progress variables for this target.
include TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/progress.make

# Include the compile flags for this target's objects.
include TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/flags.make

TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.o: TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/flags.make
TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.o: ../TP2.5/TriangleAvecTexturesWow.cpp
TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.o: TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/semag/Desktop/GLImac-Template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.o"
	cd /home/semag/Desktop/GLImac-Template/build/TP2.5 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.o -MF CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.o.d -o CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.o -c /home/semag/Desktop/GLImac-Template/TP2.5/TriangleAvecTexturesWow.cpp

TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.i"
	cd /home/semag/Desktop/GLImac-Template/build/TP2.5 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/semag/Desktop/GLImac-Template/TP2.5/TriangleAvecTexturesWow.cpp > CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.i

TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.s"
	cd /home/semag/Desktop/GLImac-Template/build/TP2.5 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/semag/Desktop/GLImac-Template/TP2.5/TriangleAvecTexturesWow.cpp -o CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.s

# Object files for target TP2.5_TriangleAvecTexturesWow
TP2_5_TriangleAvecTexturesWow_OBJECTS = \
"CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.o"

# External object files for target TP2.5_TriangleAvecTexturesWow
TP2_5_TriangleAvecTexturesWow_EXTERNAL_OBJECTS =

TP2.5/TP2.5_TriangleAvecTexturesWow: TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/TriangleAvecTexturesWow.cpp.o
TP2.5/TP2.5_TriangleAvecTexturesWow: TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/build.make
TP2.5/TP2.5_TriangleAvecTexturesWow: glimac/libglimac.a
TP2.5/TP2.5_TriangleAvecTexturesWow: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP2.5/TP2.5_TriangleAvecTexturesWow: /usr/lib/x86_64-linux-gnu/libSDL.so
TP2.5/TP2.5_TriangleAvecTexturesWow: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP2.5/TP2.5_TriangleAvecTexturesWow: ../third-party/libGLEW.a
TP2.5/TP2.5_TriangleAvecTexturesWow: TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/semag/Desktop/GLImac-Template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP2.5_TriangleAvecTexturesWow"
	cd /home/semag/Desktop/GLImac-Template/build/TP2.5 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/build: TP2.5/TP2.5_TriangleAvecTexturesWow
.PHONY : TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/build

TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/clean:
	cd /home/semag/Desktop/GLImac-Template/build/TP2.5 && $(CMAKE_COMMAND) -P CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/cmake_clean.cmake
.PHONY : TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/clean

TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/depend:
	cd /home/semag/Desktop/GLImac-Template/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/semag/Desktop/GLImac-Template /home/semag/Desktop/GLImac-Template/TP2.5 /home/semag/Desktop/GLImac-Template/build /home/semag/Desktop/GLImac-Template/build/TP2.5 /home/semag/Desktop/GLImac-Template/build/TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP2.5/CMakeFiles/TP2.5_TriangleAvecTexturesWow.dir/depend
