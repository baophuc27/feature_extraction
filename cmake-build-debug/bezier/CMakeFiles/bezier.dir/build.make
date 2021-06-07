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
include bezier/CMakeFiles/bezier.dir/depend.make

# Include the progress variables for this target.
include bezier/CMakeFiles/bezier.dir/progress.make

# Include the compile flags for this target's objects.
include bezier/CMakeFiles/bezier.dir/flags.make

bezier/CMakeFiles/bezier.dir/BezierFeatures.cpp.o: bezier/CMakeFiles/bezier.dir/flags.make
bezier/CMakeFiles/bezier.dir/BezierFeatures.cpp.o: ../bezier/BezierFeatures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bezier/CMakeFiles/bezier.dir/BezierFeatures.cpp.o"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bezier.dir/BezierFeatures.cpp.o -c /home/phuc/CLionProjects/feature_extraction/bezier/BezierFeatures.cpp

bezier/CMakeFiles/bezier.dir/BezierFeatures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bezier.dir/BezierFeatures.cpp.i"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phuc/CLionProjects/feature_extraction/bezier/BezierFeatures.cpp > CMakeFiles/bezier.dir/BezierFeatures.cpp.i

bezier/CMakeFiles/bezier.dir/BezierFeatures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bezier.dir/BezierFeatures.cpp.s"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phuc/CLionProjects/feature_extraction/bezier/BezierFeatures.cpp -o CMakeFiles/bezier.dir/BezierFeatures.cpp.s

bezier/CMakeFiles/bezier.dir/BezierPreprocessor.cpp.o: bezier/CMakeFiles/bezier.dir/flags.make
bezier/CMakeFiles/bezier.dir/BezierPreprocessor.cpp.o: ../bezier/BezierPreprocessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object bezier/CMakeFiles/bezier.dir/BezierPreprocessor.cpp.o"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bezier.dir/BezierPreprocessor.cpp.o -c /home/phuc/CLionProjects/feature_extraction/bezier/BezierPreprocessor.cpp

bezier/CMakeFiles/bezier.dir/BezierPreprocessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bezier.dir/BezierPreprocessor.cpp.i"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phuc/CLionProjects/feature_extraction/bezier/BezierPreprocessor.cpp > CMakeFiles/bezier.dir/BezierPreprocessor.cpp.i

bezier/CMakeFiles/bezier.dir/BezierPreprocessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bezier.dir/BezierPreprocessor.cpp.s"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phuc/CLionProjects/feature_extraction/bezier/BezierPreprocessor.cpp -o CMakeFiles/bezier.dir/BezierPreprocessor.cpp.s

bezier/CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.o: bezier/CMakeFiles/bezier.dir/flags.make
bezier/CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.o: ../bezier/ExtractBezierFeatures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object bezier/CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.o"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.o -c /home/phuc/CLionProjects/feature_extraction/bezier/ExtractBezierFeatures.cpp

bezier/CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.i"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phuc/CLionProjects/feature_extraction/bezier/ExtractBezierFeatures.cpp > CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.i

bezier/CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.s"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phuc/CLionProjects/feature_extraction/bezier/ExtractBezierFeatures.cpp -o CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.s

# Object files for target bezier
bezier_OBJECTS = \
"CMakeFiles/bezier.dir/BezierFeatures.cpp.o" \
"CMakeFiles/bezier.dir/BezierPreprocessor.cpp.o" \
"CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.o"

# External object files for target bezier
bezier_EXTERNAL_OBJECTS =

bezier/libbezier.a: bezier/CMakeFiles/bezier.dir/BezierFeatures.cpp.o
bezier/libbezier.a: bezier/CMakeFiles/bezier.dir/BezierPreprocessor.cpp.o
bezier/libbezier.a: bezier/CMakeFiles/bezier.dir/ExtractBezierFeatures.cpp.o
bezier/libbezier.a: bezier/CMakeFiles/bezier.dir/build.make
bezier/libbezier.a: bezier/CMakeFiles/bezier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libbezier.a"
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && $(CMAKE_COMMAND) -P CMakeFiles/bezier.dir/cmake_clean_target.cmake
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bezier.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bezier/CMakeFiles/bezier.dir/build: bezier/libbezier.a

.PHONY : bezier/CMakeFiles/bezier.dir/build

bezier/CMakeFiles/bezier.dir/clean:
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier && $(CMAKE_COMMAND) -P CMakeFiles/bezier.dir/cmake_clean.cmake
.PHONY : bezier/CMakeFiles/bezier.dir/clean

bezier/CMakeFiles/bezier.dir/depend:
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phuc/CLionProjects/feature_extraction /home/phuc/CLionProjects/feature_extraction/bezier /home/phuc/CLionProjects/feature_extraction/cmake-build-debug /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/bezier/CMakeFiles/bezier.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bezier/CMakeFiles/bezier.dir/depend
