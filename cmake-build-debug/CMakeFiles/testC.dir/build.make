# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\testC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\testC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/testC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testC.dir/flags.make

CMakeFiles/testC.dir/testC.cpp.obj: CMakeFiles/testC.dir/flags.make
CMakeFiles/testC.dir/testC.cpp.obj: ../testC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\testC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testC.dir/testC.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\testC.dir\testC.cpp.obj -c F:\testC\testC.cpp

CMakeFiles/testC.dir/testC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testC.dir/testC.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\testC\testC.cpp > CMakeFiles\testC.dir\testC.cpp.i

CMakeFiles/testC.dir/testC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testC.dir/testC.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\testC\testC.cpp -o CMakeFiles\testC.dir\testC.cpp.s

# Object files for target testC
testC_OBJECTS = \
"CMakeFiles/testC.dir/testC.cpp.obj"

# External object files for target testC
testC_EXTERNAL_OBJECTS =

testC.exe: CMakeFiles/testC.dir/testC.cpp.obj
testC.exe: CMakeFiles/testC.dir/build.make
testC.exe: CMakeFiles/testC.dir/linklibs.rsp
testC.exe: CMakeFiles/testC.dir/objects1.rsp
testC.exe: CMakeFiles/testC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\testC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\testC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testC.dir/build: testC.exe

.PHONY : CMakeFiles/testC.dir/build

CMakeFiles/testC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\testC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/testC.dir/clean

CMakeFiles/testC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\testC F:\testC F:\testC\cmake-build-debug F:\testC\cmake-build-debug F:\testC\cmake-build-debug\CMakeFiles\testC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testC.dir/depend

