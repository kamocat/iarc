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
include CMakeFiles/rxtx.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rxtx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rxtx.dir/flags.make

CMakeFiles/rxtx.dir/src/threadtest.o: CMakeFiles/rxtx.dir/flags.make
CMakeFiles/rxtx.dir/src/threadtest.o: ../src/threadtest.cpp
CMakeFiles/rxtx.dir/src/threadtest.o: ../manifest.xml
CMakeFiles/rxtx.dir/src/threadtest.o: /opt/ros/fuerte/share/std_msgs/manifest.xml
CMakeFiles/rxtx.dir/src/threadtest.o: /opt/ros/fuerte/share/roslang/manifest.xml
CMakeFiles/rxtx.dir/src/threadtest.o: /opt/ros/fuerte/share/rospy/manifest.xml
CMakeFiles/rxtx.dir/src/threadtest.o: /opt/ros/fuerte/share/roscpp/manifest.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /root/ros_workspace/rxtxserver/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/rxtx.dir/src/threadtest.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/rxtx.dir/src/threadtest.o -c /root/ros_workspace/rxtxserver/src/threadtest.cpp

CMakeFiles/rxtx.dir/src/threadtest.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rxtx.dir/src/threadtest.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /root/ros_workspace/rxtxserver/src/threadtest.cpp > CMakeFiles/rxtx.dir/src/threadtest.i

CMakeFiles/rxtx.dir/src/threadtest.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rxtx.dir/src/threadtest.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /root/ros_workspace/rxtxserver/src/threadtest.cpp -o CMakeFiles/rxtx.dir/src/threadtest.s

CMakeFiles/rxtx.dir/src/threadtest.o.requires:
.PHONY : CMakeFiles/rxtx.dir/src/threadtest.o.requires

CMakeFiles/rxtx.dir/src/threadtest.o.provides: CMakeFiles/rxtx.dir/src/threadtest.o.requires
	$(MAKE) -f CMakeFiles/rxtx.dir/build.make CMakeFiles/rxtx.dir/src/threadtest.o.provides.build
.PHONY : CMakeFiles/rxtx.dir/src/threadtest.o.provides

CMakeFiles/rxtx.dir/src/threadtest.o.provides.build: CMakeFiles/rxtx.dir/src/threadtest.o

# Object files for target rxtx
rxtx_OBJECTS = \
"CMakeFiles/rxtx.dir/src/threadtest.o"

# External object files for target rxtx
rxtx_EXTERNAL_OBJECTS =

../bin/rxtx: CMakeFiles/rxtx.dir/src/threadtest.o
../bin/rxtx: CMakeFiles/rxtx.dir/build.make
../bin/rxtx: CMakeFiles/rxtx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/rxtx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rxtx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rxtx.dir/build: ../bin/rxtx
.PHONY : CMakeFiles/rxtx.dir/build

CMakeFiles/rxtx.dir/requires: CMakeFiles/rxtx.dir/src/threadtest.o.requires
.PHONY : CMakeFiles/rxtx.dir/requires

CMakeFiles/rxtx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rxtx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rxtx.dir/clean

CMakeFiles/rxtx.dir/depend:
	cd /root/ros_workspace/rxtxserver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/ros_workspace/rxtxserver /root/ros_workspace/rxtxserver /root/ros_workspace/rxtxserver/build /root/ros_workspace/rxtxserver/build /root/ros_workspace/rxtxserver/build/CMakeFiles/rxtx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rxtx.dir/depend
