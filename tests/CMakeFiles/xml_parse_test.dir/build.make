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
CMAKE_SOURCE_DIR = /home/coder/project/Documents/CodeSpace/structures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/coder/project/Documents/CodeSpace/structures

# Include any dependencies generated for this target.
include tests/CMakeFiles/xml_parse_test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/xml_parse_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/xml_parse_test.dir/flags.make

tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o: tests/CMakeFiles/xml_parse_test.dir/flags.make
tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o: tests/xml_parse_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/coder/project/Documents/CodeSpace/structures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o"
	cd /home/coder/project/Documents/CodeSpace/structures/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o   -c /home/coder/project/Documents/CodeSpace/structures/tests/xml_parse_test.c

tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xml_parse_test.dir/xml_parse_test.c.i"
	cd /home/coder/project/Documents/CodeSpace/structures/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/coder/project/Documents/CodeSpace/structures/tests/xml_parse_test.c > CMakeFiles/xml_parse_test.dir/xml_parse_test.c.i

tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xml_parse_test.dir/xml_parse_test.c.s"
	cd /home/coder/project/Documents/CodeSpace/structures/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/coder/project/Documents/CodeSpace/structures/tests/xml_parse_test.c -o CMakeFiles/xml_parse_test.dir/xml_parse_test.c.s

tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o.requires:

.PHONY : tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o.requires

tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o.provides: tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o.requires
	$(MAKE) -f tests/CMakeFiles/xml_parse_test.dir/build.make tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o.provides.build
.PHONY : tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o.provides

tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o.provides.build: tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o


# Object files for target xml_parse_test
xml_parse_test_OBJECTS = \
"CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o"

# External object files for target xml_parse_test
xml_parse_test_EXTERNAL_OBJECTS =

tests/xml_parse_test: tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o
tests/xml_parse_test: tests/CMakeFiles/xml_parse_test.dir/build.make
tests/xml_parse_test: libs/check/src/.libs/libcheck.so
tests/xml_parse_test: bin/Debug/liblmain.a
tests/xml_parse_test: tests/CMakeFiles/xml_parse_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/coder/project/Documents/CodeSpace/structures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable xml_parse_test"
	cd /home/coder/project/Documents/CodeSpace/structures/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xml_parse_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/xml_parse_test.dir/build: tests/xml_parse_test

.PHONY : tests/CMakeFiles/xml_parse_test.dir/build

tests/CMakeFiles/xml_parse_test.dir/requires: tests/CMakeFiles/xml_parse_test.dir/xml_parse_test.c.o.requires

.PHONY : tests/CMakeFiles/xml_parse_test.dir/requires

tests/CMakeFiles/xml_parse_test.dir/clean:
	cd /home/coder/project/Documents/CodeSpace/structures/tests && $(CMAKE_COMMAND) -P CMakeFiles/xml_parse_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/xml_parse_test.dir/clean

tests/CMakeFiles/xml_parse_test.dir/depend:
	cd /home/coder/project/Documents/CodeSpace/structures && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/coder/project/Documents/CodeSpace/structures /home/coder/project/Documents/CodeSpace/structures/tests /home/coder/project/Documents/CodeSpace/structures /home/coder/project/Documents/CodeSpace/structures/tests /home/coder/project/Documents/CodeSpace/structures/tests/CMakeFiles/xml_parse_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/xml_parse_test.dir/depend

