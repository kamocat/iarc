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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/ros_workspace/rxtxserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/ros_workspace/rxtxserver/build

# Include any dependencies generated for this target.
include CMakeFiles/rxtxtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rxtxtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rxtxtest.dir/flags.make

CMakeFiles/rxtxtest.dir/src/rxtxtest.o: CMakeFiles/rxtxtest.dir/flags.make
CMakeFiles/rxtxtest.dir/src/rxtxtest.o: ../src/rxtxtest.cpp
CMakeFiles/rxtxtest.dir/src/rxtxtest.o: ../manifest.xml
CMakeFiles/rxtxtest.dir/src/rxtxtest.o: /opt/ros/fuerte/share/std_msgs/manifest.xml
CMakeFiles/rxtxtest.dir/src/rxtxtest.o: /opt/ros/fuerte/share/roslang/manifest.xml
CMakeFiles/rxtxtest.dir/src/rxtxtest.o: /opt/ros/fuerte/share/rospy/manifest.xml
CMakeFiles/rxtxtest.dir/src/rxtxtest.o: /opt/ros/fuerte/share/roscpp/manifest.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /root/ros_workspace/rxtxserver/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/rxtxtest.dir/src/rxtxtest.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/rxtxtest.dir/src/rxtxtest.o -c /root/ros_workspace/rxtxserver/src/rxtxtest.cpp

CMakeFiles/rxtxtest.dir/src/rxtxtest.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rxtxtest.dir/src/rxtxtest.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /root/ros_workspace/rxtxserver/src/rxtxtest.cpp > CMakeFiles/rxtxtest.dir/src/rxtxtest.i

CMakeFiles/rxtxtest.dir/src/rxtxtest.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rxtxtest.dir/src/rxtxtest.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /root/ros_workspace/rxtxserver/src/rxtxtest.cpp -o CMakeFiles/rxtxtest.dir/src/rxtxtest.s

CMakeFiles/rxtxtest.dir/src/rxtxtest.o.requires:
.PHONY : CMakeFiles/rxtxtest.dir/src/rxtxtest.o.requires

CMakeFiles/rxtxtest.dir/src/rxtxtest.o.provides: CMakeFiles/rxtxtest.dir/src/rxtxtest.o.requires
	$(MAKE) -f CMakeFiles/rxtxtest.dir/build.make CMakeFiles/rxtxtest.dir/src/rxtxtest.o.provides.build
.PHONY : CMakeFiles/rxtxtest.dir/src/rxtxtest.o.provides

CMakeFiles/rxtxtest.dir/src/rxtxtest.o.provides.build: CMakeFiles/rxtxtest.dir/src/rxtxtest.o

# Object files for target rxtxtest
rxtxtest_OBJECTS = \
"CMakeFiles/rxtxtest.dir/src/rxtxtest.o"

# External object files for target rxtxtest
rxtxtest_EXTERNAL_OBJECTS =

../bin/rxtxtest: CMakeFiles/rxtxtest.dir/src/rxtxtest.o
../bin/rxtxtest: CMakeFiles/rxtxtest.dir/build.make
../bin/rxtxtest: CMakeFiles/rxtxtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/rxtxtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rxtxtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rxtxtest.dir/build: ../bin/rxtxtest
.PHONY : CMakeFiles/rxtxtest.dir/build

CMakeFiles/rxtxtest.dir/requires: CMakeFiles/rxtxtest.dir/src/rxtxtest.o.requires
.PHONY : CMakeFiles/rxtxtest.dir/requires

CMakeFiles/rxtxtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rxtxtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rxtxtest.dir/clean

CMakeFiles/rxtxtest.dir/depend:
	cd /root/ros_workspace/rxtxserver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/ros_workspace/rxtxserver /root/ros_workspace/rxtxserver /root/ros_workspace/rxtxserver/build /root/ros_workspace/rxtxserver/build /root/ros_workspace/rxtxserver/build/CMakeFiles/rxtxtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rxtxtest.dir/depend
