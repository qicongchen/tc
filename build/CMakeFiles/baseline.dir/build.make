# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qicong/tc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qicong/tc/build

# Include any dependencies generated for this target.
include CMakeFiles/baseline.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/baseline.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/baseline.dir/flags.make

CMakeFiles/baseline.dir/tokenize.o: CMakeFiles/baseline.dir/flags.make
CMakeFiles/baseline.dir/tokenize.o: ../tokenize.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qicong/tc/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/baseline.dir/tokenize.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/baseline.dir/tokenize.o -c /home/qicong/tc/tokenize.cpp

CMakeFiles/baseline.dir/tokenize.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseline.dir/tokenize.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qicong/tc/tokenize.cpp > CMakeFiles/baseline.dir/tokenize.i

CMakeFiles/baseline.dir/tokenize.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseline.dir/tokenize.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qicong/tc/tokenize.cpp -o CMakeFiles/baseline.dir/tokenize.s

CMakeFiles/baseline.dir/tokenize.o.requires:
.PHONY : CMakeFiles/baseline.dir/tokenize.o.requires

CMakeFiles/baseline.dir/tokenize.o.provides: CMakeFiles/baseline.dir/tokenize.o.requires
	$(MAKE) -f CMakeFiles/baseline.dir/build.make CMakeFiles/baseline.dir/tokenize.o.provides.build
.PHONY : CMakeFiles/baseline.dir/tokenize.o.provides

CMakeFiles/baseline.dir/tokenize.o.provides.build: CMakeFiles/baseline.dir/tokenize.o

CMakeFiles/baseline.dir/baseline.o: CMakeFiles/baseline.dir/flags.make
CMakeFiles/baseline.dir/baseline.o: ../baseline.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qicong/tc/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/baseline.dir/baseline.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/baseline.dir/baseline.o -c /home/qicong/tc/baseline.cpp

CMakeFiles/baseline.dir/baseline.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseline.dir/baseline.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qicong/tc/baseline.cpp > CMakeFiles/baseline.dir/baseline.i

CMakeFiles/baseline.dir/baseline.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseline.dir/baseline.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qicong/tc/baseline.cpp -o CMakeFiles/baseline.dir/baseline.s

CMakeFiles/baseline.dir/baseline.o.requires:
.PHONY : CMakeFiles/baseline.dir/baseline.o.requires

CMakeFiles/baseline.dir/baseline.o.provides: CMakeFiles/baseline.dir/baseline.o.requires
	$(MAKE) -f CMakeFiles/baseline.dir/build.make CMakeFiles/baseline.dir/baseline.o.provides.build
.PHONY : CMakeFiles/baseline.dir/baseline.o.provides

CMakeFiles/baseline.dir/baseline.o.provides.build: CMakeFiles/baseline.dir/baseline.o

CMakeFiles/baseline.dir/sort.o: CMakeFiles/baseline.dir/flags.make
CMakeFiles/baseline.dir/sort.o: ../sort.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qicong/tc/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/baseline.dir/sort.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/baseline.dir/sort.o -c /home/qicong/tc/sort.cpp

CMakeFiles/baseline.dir/sort.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseline.dir/sort.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qicong/tc/sort.cpp > CMakeFiles/baseline.dir/sort.i

CMakeFiles/baseline.dir/sort.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseline.dir/sort.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qicong/tc/sort.cpp -o CMakeFiles/baseline.dir/sort.s

CMakeFiles/baseline.dir/sort.o.requires:
.PHONY : CMakeFiles/baseline.dir/sort.o.requires

CMakeFiles/baseline.dir/sort.o.provides: CMakeFiles/baseline.dir/sort.o.requires
	$(MAKE) -f CMakeFiles/baseline.dir/build.make CMakeFiles/baseline.dir/sort.o.provides.build
.PHONY : CMakeFiles/baseline.dir/sort.o.provides

CMakeFiles/baseline.dir/sort.o.provides.build: CMakeFiles/baseline.dir/sort.o

# Object files for target baseline
baseline_OBJECTS = \
"CMakeFiles/baseline.dir/tokenize.o" \
"CMakeFiles/baseline.dir/baseline.o" \
"CMakeFiles/baseline.dir/sort.o"

# External object files for target baseline
baseline_EXTERNAL_OBJECTS =

baseline: CMakeFiles/baseline.dir/tokenize.o
baseline: CMakeFiles/baseline.dir/baseline.o
baseline: CMakeFiles/baseline.dir/sort.o
baseline: CMakeFiles/baseline.dir/build.make
baseline: CMakeFiles/baseline.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable baseline"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/baseline.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/baseline.dir/build: baseline
.PHONY : CMakeFiles/baseline.dir/build

CMakeFiles/baseline.dir/requires: CMakeFiles/baseline.dir/tokenize.o.requires
CMakeFiles/baseline.dir/requires: CMakeFiles/baseline.dir/baseline.o.requires
CMakeFiles/baseline.dir/requires: CMakeFiles/baseline.dir/sort.o.requires
.PHONY : CMakeFiles/baseline.dir/requires

CMakeFiles/baseline.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/baseline.dir/cmake_clean.cmake
.PHONY : CMakeFiles/baseline.dir/clean

CMakeFiles/baseline.dir/depend:
	cd /home/qicong/tc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qicong/tc /home/qicong/tc /home/qicong/tc/build /home/qicong/tc/build /home/qicong/tc/build/CMakeFiles/baseline.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/baseline.dir/depend

