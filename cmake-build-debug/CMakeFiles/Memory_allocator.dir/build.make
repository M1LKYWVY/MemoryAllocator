# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /cygdrive/c/Users/Dreamer/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Dreamer/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Memory_allocator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Memory_allocator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Memory_allocator.dir/flags.make

CMakeFiles/Memory_allocator.dir/main.c.o: CMakeFiles/Memory_allocator.dir/flags.make
CMakeFiles/Memory_allocator.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Memory_allocator.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Memory_allocator.dir/main.c.o   -c /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/main.c

CMakeFiles/Memory_allocator.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Memory_allocator.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/main.c > CMakeFiles/Memory_allocator.dir/main.c.i

CMakeFiles/Memory_allocator.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Memory_allocator.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/main.c -o CMakeFiles/Memory_allocator.dir/main.c.s

CMakeFiles/Memory_allocator.dir/main.c.o.requires:

.PHONY : CMakeFiles/Memory_allocator.dir/main.c.o.requires

CMakeFiles/Memory_allocator.dir/main.c.o.provides: CMakeFiles/Memory_allocator.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Memory_allocator.dir/build.make CMakeFiles/Memory_allocator.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Memory_allocator.dir/main.c.o.provides

CMakeFiles/Memory_allocator.dir/main.c.o.provides.build: CMakeFiles/Memory_allocator.dir/main.c.o


CMakeFiles/Memory_allocator.dir/mem_debug.c.o: CMakeFiles/Memory_allocator.dir/flags.make
CMakeFiles/Memory_allocator.dir/mem_debug.c.o: ../mem_debug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Memory_allocator.dir/mem_debug.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Memory_allocator.dir/mem_debug.c.o   -c /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/mem_debug.c

CMakeFiles/Memory_allocator.dir/mem_debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Memory_allocator.dir/mem_debug.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/mem_debug.c > CMakeFiles/Memory_allocator.dir/mem_debug.c.i

CMakeFiles/Memory_allocator.dir/mem_debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Memory_allocator.dir/mem_debug.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/mem_debug.c -o CMakeFiles/Memory_allocator.dir/mem_debug.c.s

CMakeFiles/Memory_allocator.dir/mem_debug.c.o.requires:

.PHONY : CMakeFiles/Memory_allocator.dir/mem_debug.c.o.requires

CMakeFiles/Memory_allocator.dir/mem_debug.c.o.provides: CMakeFiles/Memory_allocator.dir/mem_debug.c.o.requires
	$(MAKE) -f CMakeFiles/Memory_allocator.dir/build.make CMakeFiles/Memory_allocator.dir/mem_debug.c.o.provides.build
.PHONY : CMakeFiles/Memory_allocator.dir/mem_debug.c.o.provides

CMakeFiles/Memory_allocator.dir/mem_debug.c.o.provides.build: CMakeFiles/Memory_allocator.dir/mem_debug.c.o


CMakeFiles/Memory_allocator.dir/mem.c.o: CMakeFiles/Memory_allocator.dir/flags.make
CMakeFiles/Memory_allocator.dir/mem.c.o: ../mem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Memory_allocator.dir/mem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Memory_allocator.dir/mem.c.o   -c /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/mem.c

CMakeFiles/Memory_allocator.dir/mem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Memory_allocator.dir/mem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/mem.c > CMakeFiles/Memory_allocator.dir/mem.c.i

CMakeFiles/Memory_allocator.dir/mem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Memory_allocator.dir/mem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/mem.c -o CMakeFiles/Memory_allocator.dir/mem.c.s

CMakeFiles/Memory_allocator.dir/mem.c.o.requires:

.PHONY : CMakeFiles/Memory_allocator.dir/mem.c.o.requires

CMakeFiles/Memory_allocator.dir/mem.c.o.provides: CMakeFiles/Memory_allocator.dir/mem.c.o.requires
	$(MAKE) -f CMakeFiles/Memory_allocator.dir/build.make CMakeFiles/Memory_allocator.dir/mem.c.o.provides.build
.PHONY : CMakeFiles/Memory_allocator.dir/mem.c.o.provides

CMakeFiles/Memory_allocator.dir/mem.c.o.provides.build: CMakeFiles/Memory_allocator.dir/mem.c.o


# Object files for target Memory_allocator
Memory_allocator_OBJECTS = \
"CMakeFiles/Memory_allocator.dir/main.c.o" \
"CMakeFiles/Memory_allocator.dir/mem_debug.c.o" \
"CMakeFiles/Memory_allocator.dir/mem.c.o"

# External object files for target Memory_allocator
Memory_allocator_EXTERNAL_OBJECTS =

Memory_allocator.exe: CMakeFiles/Memory_allocator.dir/main.c.o
Memory_allocator.exe: CMakeFiles/Memory_allocator.dir/mem_debug.c.o
Memory_allocator.exe: CMakeFiles/Memory_allocator.dir/mem.c.o
Memory_allocator.exe: CMakeFiles/Memory_allocator.dir/build.make
Memory_allocator.exe: CMakeFiles/Memory_allocator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Memory_allocator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Memory_allocator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Memory_allocator.dir/build: Memory_allocator.exe

.PHONY : CMakeFiles/Memory_allocator.dir/build

CMakeFiles/Memory_allocator.dir/requires: CMakeFiles/Memory_allocator.dir/main.c.o.requires
CMakeFiles/Memory_allocator.dir/requires: CMakeFiles/Memory_allocator.dir/mem_debug.c.o.requires
CMakeFiles/Memory_allocator.dir/requires: CMakeFiles/Memory_allocator.dir/mem.c.o.requires

.PHONY : CMakeFiles/Memory_allocator.dir/requires

CMakeFiles/Memory_allocator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Memory_allocator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Memory_allocator.dir/clean

CMakeFiles/Memory_allocator.dir/depend:
	cd /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/cmake-build-debug /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/cmake-build-debug /cygdrive/c/Users/Dreamer/Development/CLionProjects/Memory_allocator/cmake-build-debug/CMakeFiles/Memory_allocator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Memory_allocator.dir/depend

