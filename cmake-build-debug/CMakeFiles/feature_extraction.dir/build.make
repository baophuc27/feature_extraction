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
include CMakeFiles/feature_extraction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/feature_extraction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/feature_extraction.dir/flags.make

CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.o: CMakeFiles/feature_extraction.dir/flags.make
CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.o: ../bezier/BezierFeatures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.o -c /home/phuc/CLionProjects/feature_extraction/bezier/BezierFeatures.cpp

CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phuc/CLionProjects/feature_extraction/bezier/BezierFeatures.cpp > CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.i

CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phuc/CLionProjects/feature_extraction/bezier/BezierFeatures.cpp -o CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.s

CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.o: CMakeFiles/feature_extraction.dir/flags.make
CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.o: ../bezier/ExtractBezierFeatures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.o -c /home/phuc/CLionProjects/feature_extraction/bezier/ExtractBezierFeatures.cpp

CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phuc/CLionProjects/feature_extraction/bezier/ExtractBezierFeatures.cpp > CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.i

CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phuc/CLionProjects/feature_extraction/bezier/ExtractBezierFeatures.cpp -o CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.s

CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.o: CMakeFiles/feature_extraction.dir/flags.make
CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.o: ../bezier/BezierPreprocessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.o -c /home/phuc/CLionProjects/feature_extraction/bezier/BezierPreprocessor.cpp

CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phuc/CLionProjects/feature_extraction/bezier/BezierPreprocessor.cpp > CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.i

CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phuc/CLionProjects/feature_extraction/bezier/BezierPreprocessor.cpp -o CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.s

CMakeFiles/feature_extraction.dir/main.cpp.o: CMakeFiles/feature_extraction.dir/flags.make
CMakeFiles/feature_extraction.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/feature_extraction.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/feature_extraction.dir/main.cpp.o -c /home/phuc/CLionProjects/feature_extraction/main.cpp

CMakeFiles/feature_extraction.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feature_extraction.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phuc/CLionProjects/feature_extraction/main.cpp > CMakeFiles/feature_extraction.dir/main.cpp.i

CMakeFiles/feature_extraction.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feature_extraction.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phuc/CLionProjects/feature_extraction/main.cpp -o CMakeFiles/feature_extraction.dir/main.cpp.s

CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.o: CMakeFiles/feature_extraction.dir/flags.make
CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.o: ../test/unit_test/BezierCurveTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.o -c /home/phuc/CLionProjects/feature_extraction/test/unit_test/BezierCurveTest.cpp

CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phuc/CLionProjects/feature_extraction/test/unit_test/BezierCurveTest.cpp > CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.i

CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phuc/CLionProjects/feature_extraction/test/unit_test/BezierCurveTest.cpp -o CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.s

# Object files for target feature_extraction
feature_extraction_OBJECTS = \
"CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.o" \
"CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.o" \
"CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.o" \
"CMakeFiles/feature_extraction.dir/main.cpp.o" \
"CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.o"

# External object files for target feature_extraction
feature_extraction_EXTERNAL_OBJECTS =

feature_extraction: CMakeFiles/feature_extraction.dir/bezier/BezierFeatures.cpp.o
feature_extraction: CMakeFiles/feature_extraction.dir/bezier/ExtractBezierFeatures.cpp.o
feature_extraction: CMakeFiles/feature_extraction.dir/bezier/BezierPreprocessor.cpp.o
feature_extraction: CMakeFiles/feature_extraction.dir/main.cpp.o
feature_extraction: CMakeFiles/feature_extraction.dir/test/unit_test/BezierCurveTest.cpp.o
feature_extraction: CMakeFiles/feature_extraction.dir/build.make
feature_extraction: CMakeFiles/feature_extraction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable feature_extraction"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/feature_extraction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/feature_extraction.dir/build: feature_extraction

.PHONY : CMakeFiles/feature_extraction.dir/build

CMakeFiles/feature_extraction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/feature_extraction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/feature_extraction.dir/clean

CMakeFiles/feature_extraction.dir/depend:
	cd /home/phuc/CLionProjects/feature_extraction/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phuc/CLionProjects/feature_extraction /home/phuc/CLionProjects/feature_extraction /home/phuc/CLionProjects/feature_extraction/cmake-build-debug /home/phuc/CLionProjects/feature_extraction/cmake-build-debug /home/phuc/CLionProjects/feature_extraction/cmake-build-debug/CMakeFiles/feature_extraction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/feature_extraction.dir/depend

