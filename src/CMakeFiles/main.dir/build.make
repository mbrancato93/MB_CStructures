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
include src/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/hash.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/hash.c.o: src/hash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/main.dir/hash.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/hash.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/hash.c

src/CMakeFiles/main.dir/hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/hash.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/hash.c > CMakeFiles/main.dir/hash.c.i

src/CMakeFiles/main.dir/hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/hash.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/hash.c -o CMakeFiles/main.dir/hash.c.s

src/CMakeFiles/main.dir/hash.c.o.requires:

.PHONY : src/CMakeFiles/main.dir/hash.c.o.requires

src/CMakeFiles/main.dir/hash.c.o.provides: src/CMakeFiles/main.dir/hash.c.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/hash.c.o.provides.build
.PHONY : src/CMakeFiles/main.dir/hash.c.o.provides

src/CMakeFiles/main.dir/hash.c.o.provides.build: src/CMakeFiles/main.dir/hash.c.o


src/CMakeFiles/main.dir/hashmap.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/hashmap.c.o: src/hashmap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/main.dir/hashmap.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/hashmap.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/hashmap.c

src/CMakeFiles/main.dir/hashmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/hashmap.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/hashmap.c > CMakeFiles/main.dir/hashmap.c.i

src/CMakeFiles/main.dir/hashmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/hashmap.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/hashmap.c -o CMakeFiles/main.dir/hashmap.c.s

src/CMakeFiles/main.dir/hashmap.c.o.requires:

.PHONY : src/CMakeFiles/main.dir/hashmap.c.o.requires

src/CMakeFiles/main.dir/hashmap.c.o.provides: src/CMakeFiles/main.dir/hashmap.c.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/hashmap.c.o.provides.build
.PHONY : src/CMakeFiles/main.dir/hashmap.c.o.provides

src/CMakeFiles/main.dir/hashmap.c.o.provides.build: src/CMakeFiles/main.dir/hashmap.c.o


src/CMakeFiles/main.dir/mArray.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/mArray.c.o: src/mArray.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/main.dir/mArray.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/mArray.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/mArray.c

src/CMakeFiles/main.dir/mArray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/mArray.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/mArray.c > CMakeFiles/main.dir/mArray.c.i

src/CMakeFiles/main.dir/mArray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/mArray.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/mArray.c -o CMakeFiles/main.dir/mArray.c.s

src/CMakeFiles/main.dir/mArray.c.o.requires:

.PHONY : src/CMakeFiles/main.dir/mArray.c.o.requires

src/CMakeFiles/main.dir/mArray.c.o.provides: src/CMakeFiles/main.dir/mArray.c.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/mArray.c.o.provides.build
.PHONY : src/CMakeFiles/main.dir/mArray.c.o.provides

src/CMakeFiles/main.dir/mArray.c.o.provides.build: src/CMakeFiles/main.dir/mArray.c.o


src/CMakeFiles/main.dir/main.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/main.dir/main.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/main.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/main.c

src/CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/main.c > CMakeFiles/main.dir/main.c.i

src/CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/main.c -o CMakeFiles/main.dir/main.c.s

src/CMakeFiles/main.dir/main.c.o.requires:

.PHONY : src/CMakeFiles/main.dir/main.c.o.requires

src/CMakeFiles/main.dir/main.c.o.provides: src/CMakeFiles/main.dir/main.c.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/main.c.o.provides.build
.PHONY : src/CMakeFiles/main.dir/main.c.o.provides

src/CMakeFiles/main.dir/main.c.o.provides.build: src/CMakeFiles/main.dir/main.c.o


src/CMakeFiles/main.dir/nodeTree.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/nodeTree.c.o: src/nodeTree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/main.dir/nodeTree.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/nodeTree.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/nodeTree.c

src/CMakeFiles/main.dir/nodeTree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/nodeTree.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/nodeTree.c > CMakeFiles/main.dir/nodeTree.c.i

src/CMakeFiles/main.dir/nodeTree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/nodeTree.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/nodeTree.c -o CMakeFiles/main.dir/nodeTree.c.s

src/CMakeFiles/main.dir/nodeTree.c.o.requires:

.PHONY : src/CMakeFiles/main.dir/nodeTree.c.o.requires

src/CMakeFiles/main.dir/nodeTree.c.o.provides: src/CMakeFiles/main.dir/nodeTree.c.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/nodeTree.c.o.provides.build
.PHONY : src/CMakeFiles/main.dir/nodeTree.c.o.provides

src/CMakeFiles/main.dir/nodeTree.c.o.provides.build: src/CMakeFiles/main.dir/nodeTree.c.o


src/CMakeFiles/main.dir/sllist.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/sllist.c.o: src/sllist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/main.dir/sllist.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/sllist.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/sllist.c

src/CMakeFiles/main.dir/sllist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/sllist.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/sllist.c > CMakeFiles/main.dir/sllist.c.i

src/CMakeFiles/main.dir/sllist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/sllist.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/sllist.c -o CMakeFiles/main.dir/sllist.c.s

src/CMakeFiles/main.dir/sllist.c.o.requires:

.PHONY : src/CMakeFiles/main.dir/sllist.c.o.requires

src/CMakeFiles/main.dir/sllist.c.o.provides: src/CMakeFiles/main.dir/sllist.c.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/sllist.c.o.provides.build
.PHONY : src/CMakeFiles/main.dir/sllist.c.o.provides

src/CMakeFiles/main.dir/sllist.c.o.provides.build: src/CMakeFiles/main.dir/sllist.c.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/hash.c.o" \
"CMakeFiles/main.dir/hashmap.c.o" \
"CMakeFiles/main.dir/mArray.c.o" \
"CMakeFiles/main.dir/main.c.o" \
"CMakeFiles/main.dir/nodeTree.c.o" \
"CMakeFiles/main.dir/sllist.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

bin/Debug/main: src/CMakeFiles/main.dir/hash.c.o
bin/Debug/main: src/CMakeFiles/main.dir/hashmap.c.o
bin/Debug/main: src/CMakeFiles/main.dir/mArray.c.o
bin/Debug/main: src/CMakeFiles/main.dir/main.c.o
bin/Debug/main: src/CMakeFiles/main.dir/nodeTree.c.o
bin/Debug/main: src/CMakeFiles/main.dir/sllist.c.o
bin/Debug/main: src/CMakeFiles/main.dir/build.make
bin/Debug/main: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable ../bin/Debug/main"
	cd /home/michael/Documents/CodeSpace/CStructures/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: bin/Debug/main

.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/hash.c.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/hashmap.c.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/mArray.c.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/main.c.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/nodeTree.c.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/sllist.c.o.requires

.PHONY : src/CMakeFiles/main.dir/requires

src/CMakeFiles/main.dir/clean:
	cd /home/michael/Documents/CodeSpace/CStructures/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd /home/michael/Documents/CodeSpace/CStructures && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michael/Documents/CodeSpace/CStructures /home/michael/Documents/CodeSpace/CStructures/src /home/michael/Documents/CodeSpace/CStructures /home/michael/Documents/CodeSpace/CStructures/src /home/michael/Documents/CodeSpace/CStructures/src/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/main.dir/depend

