# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/nate/Documents/CS-482/project[1]/helloworld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nate/Documents/CS-482/project[1]/helloworld

# Include any dependencies generated for this target.
include CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello.dir/flags.make

CMakeFiles/hello.dir/helloworld.cpp.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/helloworld.cpp.o: helloworld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nate/Documents/CS-482/project[1]/helloworld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello.dir/helloworld.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello.dir/helloworld.cpp.o -c /home/nate/Documents/CS-482/project[1]/helloworld/helloworld.cpp

CMakeFiles/hello.dir/helloworld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/helloworld.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_PREPROCESSED_SOURCE

CMakeFiles/hello.dir/helloworld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/helloworld.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_ASSEMBLY_SOURCE

CMakeFiles/hello.dir/helloworld.cpp.o.requires:

.PHONY : CMakeFiles/hello.dir/helloworld.cpp.o.requires

CMakeFiles/hello.dir/helloworld.cpp.o.provides: CMakeFiles/hello.dir/helloworld.cpp.o.requires
	$(MAKE) -f CMakeFiles/hello.dir/build.make CMakeFiles/hello.dir/helloworld.cpp.o.provides.build
.PHONY : CMakeFiles/hello.dir/helloworld.cpp.o.provides

CMakeFiles/hello.dir/helloworld.cpp.o.provides.build: CMakeFiles/hello.dir/helloworld.cpp.o


# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/helloworld.cpp.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

hello: CMakeFiles/hello.dir/helloworld.cpp.o
hello: CMakeFiles/hello.dir/build.make
hello: CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nate/Documents/CS-482/project[1]/helloworld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello.dir/build: hello

.PHONY : CMakeFiles/hello.dir/build

CMakeFiles/hello.dir/requires: CMakeFiles/hello.dir/helloworld.cpp.o.requires

.PHONY : CMakeFiles/hello.dir/requires

CMakeFiles/hello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello.dir/clean

CMakeFiles/hello.dir/depend:
	cd /home/nate/Documents/CS-482/project[1]/helloworld && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nate/Documents/CS-482/project[1]/helloworld /home/nate/Documents/CS-482/project[1]/helloworld /home/nate/Documents/CS-482/project[1]/helloworld /home/nate/Documents/CS-482/project[1]/helloworld /home/nate/Documents/CS-482/project[1]/helloworld/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello.dir/depend

