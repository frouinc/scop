# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw

# Include any dependencies generated for this target.
include examples/CMakeFiles/wave.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/wave.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/wave.dir/flags.make

examples/wave.app/Contents/Resources/glfw.icns: examples/glfw.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content examples/wave.app/Contents/Resources/glfw.icns"
	$(CMAKE_COMMAND) -E copy /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples/glfw.icns examples/wave.app/Contents/Resources/glfw.icns

examples/CMakeFiles/wave.dir/wave.c.o: examples/CMakeFiles/wave.dir/flags.make
examples/CMakeFiles/wave.dir/wave.c.o: examples/wave.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/wave.dir/wave.c.o"
	cd /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wave.dir/wave.c.o   -c /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples/wave.c

examples/CMakeFiles/wave.dir/wave.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wave.dir/wave.c.i"
	cd /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples/wave.c > CMakeFiles/wave.dir/wave.c.i

examples/CMakeFiles/wave.dir/wave.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wave.dir/wave.c.s"
	cd /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples/wave.c -o CMakeFiles/wave.dir/wave.c.s

examples/CMakeFiles/wave.dir/__/deps/glad_gl.c.o: examples/CMakeFiles/wave.dir/flags.make
examples/CMakeFiles/wave.dir/__/deps/glad_gl.c.o: deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/CMakeFiles/wave.dir/__/deps/glad_gl.c.o"
	cd /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wave.dir/__/deps/glad_gl.c.o   -c /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/deps/glad_gl.c

examples/CMakeFiles/wave.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wave.dir/__/deps/glad_gl.c.i"
	cd /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/deps/glad_gl.c > CMakeFiles/wave.dir/__/deps/glad_gl.c.i

examples/CMakeFiles/wave.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wave.dir/__/deps/glad_gl.c.s"
	cd /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/deps/glad_gl.c -o CMakeFiles/wave.dir/__/deps/glad_gl.c.s

# Object files for target wave
wave_OBJECTS = \
"CMakeFiles/wave.dir/wave.c.o" \
"CMakeFiles/wave.dir/__/deps/glad_gl.c.o"

# External object files for target wave
wave_EXTERNAL_OBJECTS =

examples/wave.app/Contents/MacOS/wave: examples/CMakeFiles/wave.dir/wave.c.o
examples/wave.app/Contents/MacOS/wave: examples/CMakeFiles/wave.dir/__/deps/glad_gl.c.o
examples/wave.app/Contents/MacOS/wave: examples/CMakeFiles/wave.dir/build.make
examples/wave.app/Contents/MacOS/wave: src/libglfw3.a
examples/wave.app/Contents/MacOS/wave: examples/CMakeFiles/wave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable wave.app/Contents/MacOS/wave"
	cd /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/wave.dir/build: examples/wave.app/Contents/MacOS/wave
examples/CMakeFiles/wave.dir/build: examples/wave.app/Contents/Resources/glfw.icns

.PHONY : examples/CMakeFiles/wave.dir/build

examples/CMakeFiles/wave.dir/clean:
	cd /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/wave.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/wave.dir/clean

examples/CMakeFiles/wave.dir/depend:
	cd /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples /Users/cyrillefrouin/Documents/Work/42/scop/libs/glfw/examples/CMakeFiles/wave.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/wave.dir/depend

