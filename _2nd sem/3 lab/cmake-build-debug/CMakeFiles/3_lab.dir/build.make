# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "D:\programming\Clion\CLion 2022.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\programming\Clion\CLion 2022.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\programming\labs\_2nd sem\3 lab"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\programming\labs\_2nd sem\3 lab\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/3_lab.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/3_lab.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/3_lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3_lab.dir/flags.make

CMakeFiles/3_lab.dir/clear/3lab.c.obj: CMakeFiles/3_lab.dir/flags.make
CMakeFiles/3_lab.dir/clear/3lab.c.obj: CMakeFiles/3_lab.dir/includes_C.rsp
CMakeFiles/3_lab.dir/clear/3lab.c.obj: D:/programming/labs/_2nd\ sem/3\ lab/clear/3lab.c
CMakeFiles/3_lab.dir/clear/3lab.c.obj: CMakeFiles/3_lab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\programming\labs\_2nd sem\3 lab\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/3_lab.dir/clear/3lab.c.obj"
	D:\programming\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/3_lab.dir/clear/3lab.c.obj -MF CMakeFiles\3_lab.dir\clear\3lab.c.obj.d -o CMakeFiles\3_lab.dir\clear\3lab.c.obj -c "D:\programming\labs\_2nd sem\3 lab\clear\3lab.c"

CMakeFiles/3_lab.dir/clear/3lab.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/3_lab.dir/clear/3lab.c.i"
	D:\programming\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\programming\labs\_2nd sem\3 lab\clear\3lab.c" > CMakeFiles\3_lab.dir\clear\3lab.c.i

CMakeFiles/3_lab.dir/clear/3lab.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/3_lab.dir/clear/3lab.c.s"
	D:\programming\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\programming\labs\_2nd sem\3 lab\clear\3lab.c" -o CMakeFiles\3_lab.dir\clear\3lab.c.s

# Object files for target 3_lab
3_lab_OBJECTS = \
"CMakeFiles/3_lab.dir/clear/3lab.c.obj"

# External object files for target 3_lab
3_lab_EXTERNAL_OBJECTS =

3_lab.exe: CMakeFiles/3_lab.dir/clear/3lab.c.obj
3_lab.exe: CMakeFiles/3_lab.dir/build.make
3_lab.exe: CMakeFiles/3_lab.dir/linklibs.rsp
3_lab.exe: CMakeFiles/3_lab.dir/objects1.rsp
3_lab.exe: CMakeFiles/3_lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\programming\labs\_2nd sem\3 lab\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 3_lab.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\3_lab.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3_lab.dir/build: 3_lab.exe
.PHONY : CMakeFiles/3_lab.dir/build

CMakeFiles/3_lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\3_lab.dir\cmake_clean.cmake
.PHONY : CMakeFiles/3_lab.dir/clean

CMakeFiles/3_lab.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\programming\labs\_2nd sem\3 lab" "D:\programming\labs\_2nd sem\3 lab" "D:\programming\labs\_2nd sem\3 lab\cmake-build-debug" "D:\programming\labs\_2nd sem\3 lab\cmake-build-debug" "D:\programming\labs\_2nd sem\3 lab\cmake-build-debug\CMakeFiles\3_lab.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/3_lab.dir/depend

