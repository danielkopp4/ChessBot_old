# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary

# Include any dependencies generated for this target.
include CMakeFiles/example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example.dir/flags.make

CMakeFiles/example.dir/src/board.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/src/board.o: src/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example.dir/src/board.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/src/board.o -c /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/board.cpp

CMakeFiles/example.dir/src/board.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/src/board.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/board.cpp > CMakeFiles/example.dir/src/board.i

CMakeFiles/example.dir/src/board.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/src/board.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/board.cpp -o CMakeFiles/example.dir/src/board.s

CMakeFiles/example.dir/src/main.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/src/main.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/example.dir/src/main.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/src/main.o -c /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/main.cpp

CMakeFiles/example.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/src/main.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/main.cpp > CMakeFiles/example.dir/src/main.i

CMakeFiles/example.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/src/main.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/main.cpp -o CMakeFiles/example.dir/src/main.s

CMakeFiles/example.dir/src/move.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/src/move.o: src/move.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/example.dir/src/move.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/src/move.o -c /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/move.cpp

CMakeFiles/example.dir/src/move.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/src/move.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/move.cpp > CMakeFiles/example.dir/src/move.i

CMakeFiles/example.dir/src/move.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/src/move.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/move.cpp -o CMakeFiles/example.dir/src/move.s

CMakeFiles/example.dir/src/piece.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/src/piece.o: src/piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/example.dir/src/piece.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/src/piece.o -c /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/piece.cpp

CMakeFiles/example.dir/src/piece.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/src/piece.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/piece.cpp > CMakeFiles/example.dir/src/piece.i

CMakeFiles/example.dir/src/piece.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/src/piece.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/piece.cpp -o CMakeFiles/example.dir/src/piece.s

CMakeFiles/example.dir/src/utils.o: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/src/utils.o: src/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/example.dir/src/utils.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/src/utils.o -c /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/utils.cpp

CMakeFiles/example.dir/src/utils.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/src/utils.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/utils.cpp > CMakeFiles/example.dir/src/utils.i

CMakeFiles/example.dir/src/utils.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/src/utils.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/src/utils.cpp -o CMakeFiles/example.dir/src/utils.s

# Object files for target example
example_OBJECTS = \
"CMakeFiles/example.dir/src/board.o" \
"CMakeFiles/example.dir/src/main.o" \
"CMakeFiles/example.dir/src/move.o" \
"CMakeFiles/example.dir/src/piece.o" \
"CMakeFiles/example.dir/src/utils.o"

# External object files for target example
example_EXTERNAL_OBJECTS =

example.cpython-37m-darwin.so: CMakeFiles/example.dir/src/board.o
example.cpython-37m-darwin.so: CMakeFiles/example.dir/src/main.o
example.cpython-37m-darwin.so: CMakeFiles/example.dir/src/move.o
example.cpython-37m-darwin.so: CMakeFiles/example.dir/src/piece.o
example.cpython-37m-darwin.so: CMakeFiles/example.dir/src/utils.o
example.cpython-37m-darwin.so: CMakeFiles/example.dir/build.make
example.cpython-37m-darwin.so: CMakeFiles/example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared module example.cpython-37m-darwin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example.dir/build: example.cpython-37m-darwin.so

.PHONY : CMakeFiles/example.dir/build

CMakeFiles/example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example.dir/clean

CMakeFiles/example.dir/depend:
	cd /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary /Users/danielkopp/Documents/projects/2021/new_chess/ChessLibary/CMakeFiles/example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example.dir/depend
