# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/152/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/152/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/phuc/CLionProjects/feature_extraction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/phuc/CLionProjects/feature_extraction/cmake-build-debug

# Include any dependencies generated for this target.
include unit_test/CMakeFiles/unit_test_run.dir/depend.make

# Include the progress variables for this target.
include unit_test/CMakeFiles/unit_test_run.dir/progress.make

# Include the compile flags for this target's objects.
include unit_test/CMakeFiles/unit_test_run.dir/flags.make

unit_test/CMakeFiles/unit_test_run.dir/Test.cpp.o: unit_test/CMakeFiles/unit_test_run.dir/flags.make
unit_test/CMakeFiles/unit_test_run.dir/Test.cpp.o: ../unit_test/Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unit_test/CMakeFiles/unit_test_run.dir/Test.cpp.o"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/unit_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_test_run.dir/Test.cpp.o -c /home/phuc/CLionProjects/feature_extraction/unit_test/Test.cpp

unit_test/CMakeFiles/unit_test_run.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test_run.dir/Test.cpp.i"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/unit_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phuc/CLionProjects/feature_extraction/unit_test/Test.cpp > CMakeFiles/unit_test_run.dir/Test.cpp.i

unit_test/CMakeFiles/unit_test_run.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test_run.dir/Test.cpp.s"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/unit_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phuc/CLionProjects/feature_extraction/unit_test/Test.cpp -o CMakeFiles/unit_test_run.dir/Test.cpp.s

# Object files for target unit_test_run
unit_test_run_OBJECTS = \
"CMakeFiles/unit_test_run.dir/Test.cpp.o"

# External object files for target unit_test_run
unit_test_run_EXTERNAL_OBJECTS =

unit_test/unit_test_run: unit_test/CMakeFiles/unit_test_run.dir/Test.cpp.o
unit_test/unit_test_run: unit_test/CMakeFiles/unit_test_run.dir/build.make
unit_test/unit_test_run: bezier/libbezier.a
unit_test/unit_test_run: unit_test/CMakeFiles/unit_test_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unit_test_run"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/unit_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_test_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unit_test/CMakeFiles/unit_test_run.dir/build: unit_test/unit_test_run

.PHONY : unit_test/CMakeFiles/unit_test_run.dir/build

unit_test/CMakeFiles/unit_test_run.dir/clean:
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/unit_test && $(CMAKE_COMMAND) -P CMakeFiles/unit_test_run.dir/cmake_clean.cmake
.PHONY : unit_test/CMakeFiles/unit_test_run.dir/clean

unit_test/CMakeFiles/unit_test_run.dir/depend:
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phuc/CLionProjects/feature_extraction /home/phuc/CLionProjects/feature_extraction/unit_test /home/phuc/CLionProjects/feature_extraction/cmake-build-debug /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/unit_test /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/unit_test/CMakeFiles/unit_test_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unit_test/CMakeFiles/unit_test_run.dir/depend
