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
include src/CMakeFiles/lmain.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lmain.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lmain.dir/flags.make

src/CMakeFiles/lmain.dir/hash.c.o: src/CMakeFiles/lmain.dir/flags.make
src/CMakeFiles/lmain.dir/hash.c.o: src/hash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/lmain.dir/hash.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lmain.dir/hash.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/hash.c

src/CMakeFiles/lmain.dir/hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lmain.dir/hash.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/hash.c > CMakeFiles/lmain.dir/hash.c.i

src/CMakeFiles/lmain.dir/hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lmain.dir/hash.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/hash.c -o CMakeFiles/lmain.dir/hash.c.s

src/CMakeFiles/lmain.dir/hash.c.o.requires:

.PHONY : src/CMakeFiles/lmain.dir/hash.c.o.requires

src/CMakeFiles/lmain.dir/hash.c.o.provides: src/CMakeFiles/lmain.dir/hash.c.o.requires
	$(MAKE) -f src/CMakeFiles/lmain.dir/build.make src/CMakeFiles/lmain.dir/hash.c.o.provides.build
.PHONY : src/CMakeFiles/lmain.dir/hash.c.o.provides

src/CMakeFiles/lmain.dir/hash.c.o.provides.build: src/CMakeFiles/lmain.dir/hash.c.o


src/CMakeFiles/lmain.dir/hashmap.c.o: src/CMakeFiles/lmain.dir/flags.make
src/CMakeFiles/lmain.dir/hashmap.c.o: src/hashmap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/lmain.dir/hashmap.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lmain.dir/hashmap.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/hashmap.c

src/CMakeFiles/lmain.dir/hashmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lmain.dir/hashmap.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/hashmap.c > CMakeFiles/lmain.dir/hashmap.c.i

src/CMakeFiles/lmain.dir/hashmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lmain.dir/hashmap.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/hashmap.c -o CMakeFiles/lmain.dir/hashmap.c.s

src/CMakeFiles/lmain.dir/hashmap.c.o.requires:

.PHONY : src/CMakeFiles/lmain.dir/hashmap.c.o.requires

src/CMakeFiles/lmain.dir/hashmap.c.o.provides: src/CMakeFiles/lmain.dir/hashmap.c.o.requires
	$(MAKE) -f src/CMakeFiles/lmain.dir/build.make src/CMakeFiles/lmain.dir/hashmap.c.o.provides.build
.PHONY : src/CMakeFiles/lmain.dir/hashmap.c.o.provides

src/CMakeFiles/lmain.dir/hashmap.c.o.provides.build: src/CMakeFiles/lmain.dir/hashmap.c.o


src/CMakeFiles/lmain.dir/mArray.c.o: src/CMakeFiles/lmain.dir/flags.make
src/CMakeFiles/lmain.dir/mArray.c.o: src/mArray.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/lmain.dir/mArray.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lmain.dir/mArray.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/mArray.c

src/CMakeFiles/lmain.dir/mArray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lmain.dir/mArray.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/mArray.c > CMakeFiles/lmain.dir/mArray.c.i

src/CMakeFiles/lmain.dir/mArray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lmain.dir/mArray.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/mArray.c -o CMakeFiles/lmain.dir/mArray.c.s

src/CMakeFiles/lmain.dir/mArray.c.o.requires:

.PHONY : src/CMakeFiles/lmain.dir/mArray.c.o.requires

src/CMakeFiles/lmain.dir/mArray.c.o.provides: src/CMakeFiles/lmain.dir/mArray.c.o.requires
	$(MAKE) -f src/CMakeFiles/lmain.dir/build.make src/CMakeFiles/lmain.dir/mArray.c.o.provides.build
.PHONY : src/CMakeFiles/lmain.dir/mArray.c.o.provides

src/CMakeFiles/lmain.dir/mArray.c.o.provides.build: src/CMakeFiles/lmain.dir/mArray.c.o


src/CMakeFiles/lmain.dir/main.c.o: src/CMakeFiles/lmain.dir/flags.make
src/CMakeFiles/lmain.dir/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/lmain.dir/main.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lmain.dir/main.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/main.c

src/CMakeFiles/lmain.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lmain.dir/main.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/main.c > CMakeFiles/lmain.dir/main.c.i

src/CMakeFiles/lmain.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lmain.dir/main.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/main.c -o CMakeFiles/lmain.dir/main.c.s

src/CMakeFiles/lmain.dir/main.c.o.requires:

.PHONY : src/CMakeFiles/lmain.dir/main.c.o.requires

src/CMakeFiles/lmain.dir/main.c.o.provides: src/CMakeFiles/lmain.dir/main.c.o.requires
	$(MAKE) -f src/CMakeFiles/lmain.dir/build.make src/CMakeFiles/lmain.dir/main.c.o.provides.build
.PHONY : src/CMakeFiles/lmain.dir/main.c.o.provides

src/CMakeFiles/lmain.dir/main.c.o.provides.build: src/CMakeFiles/lmain.dir/main.c.o


src/CMakeFiles/lmain.dir/nodeTree.c.o: src/CMakeFiles/lmain.dir/flags.make
src/CMakeFiles/lmain.dir/nodeTree.c.o: src/nodeTree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/lmain.dir/nodeTree.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lmain.dir/nodeTree.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/nodeTree.c

src/CMakeFiles/lmain.dir/nodeTree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lmain.dir/nodeTree.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/nodeTree.c > CMakeFiles/lmain.dir/nodeTree.c.i

src/CMakeFiles/lmain.dir/nodeTree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lmain.dir/nodeTree.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/nodeTree.c -o CMakeFiles/lmain.dir/nodeTree.c.s

src/CMakeFiles/lmain.dir/nodeTree.c.o.requires:

.PHONY : src/CMakeFiles/lmain.dir/nodeTree.c.o.requires

src/CMakeFiles/lmain.dir/nodeTree.c.o.provides: src/CMakeFiles/lmain.dir/nodeTree.c.o.requires
	$(MAKE) -f src/CMakeFiles/lmain.dir/build.make src/CMakeFiles/lmain.dir/nodeTree.c.o.provides.build
.PHONY : src/CMakeFiles/lmain.dir/nodeTree.c.o.provides

src/CMakeFiles/lmain.dir/nodeTree.c.o.provides.build: src/CMakeFiles/lmain.dir/nodeTree.c.o


src/CMakeFiles/lmain.dir/sllist.c.o: src/CMakeFiles/lmain.dir/flags.make
src/CMakeFiles/lmain.dir/sllist.c.o: src/sllist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/lmain.dir/sllist.c.o"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lmain.dir/sllist.c.o   -c /home/michael/Documents/CodeSpace/CStructures/src/sllist.c

src/CMakeFiles/lmain.dir/sllist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lmain.dir/sllist.c.i"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/michael/Documents/CodeSpace/CStructures/src/sllist.c > CMakeFiles/lmain.dir/sllist.c.i

src/CMakeFiles/lmain.dir/sllist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lmain.dir/sllist.c.s"
	cd /home/michael/Documents/CodeSpace/CStructures/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/michael/Documents/CodeSpace/CStructures/src/sllist.c -o CMakeFiles/lmain.dir/sllist.c.s

src/CMakeFiles/lmain.dir/sllist.c.o.requires:

.PHONY : src/CMakeFiles/lmain.dir/sllist.c.o.requires

src/CMakeFiles/lmain.dir/sllist.c.o.provides: src/CMakeFiles/lmain.dir/sllist.c.o.requires
	$(MAKE) -f src/CMakeFiles/lmain.dir/build.make src/CMakeFiles/lmain.dir/sllist.c.o.provides.build
.PHONY : src/CMakeFiles/lmain.dir/sllist.c.o.provides

src/CMakeFiles/lmain.dir/sllist.c.o.provides.build: src/CMakeFiles/lmain.dir/sllist.c.o


# Object files for target lmain
lmain_OBJECTS = \
"CMakeFiles/lmain.dir/hash.c.o" \
"CMakeFiles/lmain.dir/hashmap.c.o" \
"CMakeFiles/lmain.dir/mArray.c.o" \
"CMakeFiles/lmain.dir/main.c.o" \
"CMakeFiles/lmain.dir/nodeTree.c.o" \
"CMakeFiles/lmain.dir/sllist.c.o"

# External object files for target lmain
lmain_EXTERNAL_OBJECTS =

bin/Debug/liblmain.a: src/CMakeFiles/lmain.dir/hash.c.o
bin/Debug/liblmain.a: src/CMakeFiles/lmain.dir/hashmap.c.o
bin/Debug/liblmain.a: src/CMakeFiles/lmain.dir/mArray.c.o
bin/Debug/liblmain.a: src/CMakeFiles/lmain.dir/main.c.o
bin/Debug/liblmain.a: src/CMakeFiles/lmain.dir/nodeTree.c.o
bin/Debug/liblmain.a: src/CMakeFiles/lmain.dir/sllist.c.o
bin/Debug/liblmain.a: src/CMakeFiles/lmain.dir/build.make
bin/Debug/liblmain.a: src/CMakeFiles/lmain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michael/Documents/CodeSpace/CStructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library ../bin/Debug/liblmain.a"
	cd /home/michael/Documents/CodeSpace/CStructures/src && $(CMAKE_COMMAND) -P CMakeFiles/lmain.dir/cmake_clean_target.cmake
	cd /home/michael/Documents/CodeSpace/CStructures/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lmain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lmain.dir/build: bin/Debug/liblmain.a

.PHONY : src/CMakeFiles/lmain.dir/build

src/CMakeFiles/lmain.dir/requires: src/CMakeFiles/lmain.dir/hash.c.o.requires
src/CMakeFiles/lmain.dir/requires: src/CMakeFiles/lmain.dir/hashmap.c.o.requires
src/CMakeFiles/lmain.dir/requires: src/CMakeFiles/lmain.dir/mArray.c.o.requires
src/CMakeFiles/lmain.dir/requires: src/CMakeFiles/lmain.dir/main.c.o.requires
src/CMakeFiles/lmain.dir/requires: src/CMakeFiles/lmain.dir/nodeTree.c.o.requires
src/CMakeFiles/lmain.dir/requires: src/CMakeFiles/lmain.dir/sllist.c.o.requires

.PHONY : src/CMakeFiles/lmain.dir/requires

src/CMakeFiles/lmain.dir/clean:
	cd /home/michael/Documents/CodeSpace/CStructures/src && $(CMAKE_COMMAND) -P CMakeFiles/lmain.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lmain.dir/clean

src/CMakeFiles/lmain.dir/depend:
	cd /home/michael/Documents/CodeSpace/CStructures && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michael/Documents/CodeSpace/CStructures /home/michael/Documents/CodeSpace/CStructures/src /home/michael/Documents/CodeSpace/CStructures /home/michael/Documents/CodeSpace/CStructures/src /home/michael/Documents/CodeSpace/CStructures/src/CMakeFiles/lmain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/lmain.dir/depend

