# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michael/Documents/CodeSpace/CStructures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michael/Documents/CodeSpace/CStructures

# Include any dependencies generated for this target.
include tests/CMakeFiles/slltest.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/slltest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/slltest.dir/flags.make

tests/CMakeFiles/slltest.dir/slltest.c.o: tests/CMakeFiles/slltest.dir/flags.make
tests/CMakeFiles/slltest.dir/slltest.c.o: tests/slltest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/slltest.dir/slltest.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/slltest.dir/slltest.c.o   -c /home/michael/Documents/CodeSpace/CStructures/tests/slltest.c

tests/CMakeFiles/slltest.dir/slltest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/slltest.dir/slltest.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/tests/slltest.c > CMakeFiles/slltest.dir/slltest.c.i

tests/CMakeFiles/slltest.dir/slltest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/slltest.dir/slltest.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/tests/slltest.c -o CMakeFiles/slltest.dir/slltest.c.s

tests/CMakeFiles/slltest.dir/slltest.c.o.requires:

.PHONY : tests/CMakeFiles/slltest.dir/slltest.c.o.requires

tests/CMakeFiles/slltest.dir/slltest.c.o.provides: tests/CMakeFiles/slltest.dir/slltest.c.o.requires
	$(MAKE) -f tests/CMakeFiles/slltest.dir/build.make tests/CMakeFiles/slltest.dir/slltest.c.o.provides.build
.PHONY : tests/CMakeFiles/slltest.dir/slltest.c.o.provides

tests/CMakeFiles/slltest.dir/slltest.c.o.provides.build: tests/CMakeFiles/slltest.dir/slltest.c.o


# Object files for target slltest
slltest_OBJECTS = \
"CMakeFiles/slltest.dir/slltest.c.o"

# External object files for target slltest
slltest_EXTERNAL_OBJECTS =

tests/slltest: tests/CMakeFiles/slltest.dir/slltest.c.o
tests/slltest: tests/CMakeFiles/slltest.dir/build.make
tests/slltest: bin/Debug/liblmbStruct.a
tests/slltest: tests/CMakeFiles/slltest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable slltest"
	cd /home/michael/Documents/CodeSpace/CStructures/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/slltest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/slltest.dir/build: tests/slltest

.PHONY : tests/CMakeFiles/slltest.dir/build

tests/CMakeFiles/slltest.dir/requires: tests/CMakeFiles/slltest.dir/slltest.c.o.requires

.PHONY : tests/CMakeFiles/slltest.dir/requires

tests/CMakeFiles/slltest.dir/clean:
	cd /home/michael/Documents/CodeSpace/CStructures/tests && $(CMAKE_COMMAND) -P CMakeFiles/slltest.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/slltest.dir/clean

tests/CMakeFiles/slltest.dir/depend:
	cd /home/michael/Documents/CodeSpace/CStructures && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michael/Documents/CodeSpace/CStructures /home/michael/Documents/CodeSpace/CStructures/tests /home/michael/Documents/CodeSpace/CStructures /home/michael/Documents/CodeSpace/CStructures/tests /home/michael/Documents/CodeSpace/CStructures/tests/CMakeFiles/slltest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/slltest.dir/depend

