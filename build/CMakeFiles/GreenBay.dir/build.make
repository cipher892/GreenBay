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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chuks/others/GreenBay

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chuks/others/GreenBay/build

# Include any dependencies generated for this target.
include CMakeFiles/GreenBay.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GreenBay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GreenBay.dir/flags.make

CMakeFiles/GreenBay.dir/src/Halo.cpp.o: CMakeFiles/GreenBay.dir/flags.make
CMakeFiles/GreenBay.dir/src/Halo.cpp.o: ../src/Halo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chuks/others/GreenBay/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/GreenBay.dir/src/Halo.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GreenBay.dir/src/Halo.cpp.o -c /home/chuks/others/GreenBay/src/Halo.cpp

CMakeFiles/GreenBay.dir/src/Halo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GreenBay.dir/src/Halo.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chuks/others/GreenBay/src/Halo.cpp > CMakeFiles/GreenBay.dir/src/Halo.cpp.i

CMakeFiles/GreenBay.dir/src/Halo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GreenBay.dir/src/Halo.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chuks/others/GreenBay/src/Halo.cpp -o CMakeFiles/GreenBay.dir/src/Halo.cpp.s

CMakeFiles/GreenBay.dir/src/Halo.cpp.o.requires:
.PHONY : CMakeFiles/GreenBay.dir/src/Halo.cpp.o.requires

CMakeFiles/GreenBay.dir/src/Halo.cpp.o.provides: CMakeFiles/GreenBay.dir/src/Halo.cpp.o.requires
	$(MAKE) -f CMakeFiles/GreenBay.dir/build.make CMakeFiles/GreenBay.dir/src/Halo.cpp.o.provides.build
.PHONY : CMakeFiles/GreenBay.dir/src/Halo.cpp.o.provides

CMakeFiles/GreenBay.dir/src/Halo.cpp.o.provides.build: CMakeFiles/GreenBay.dir/src/Halo.cpp.o

CMakeFiles/GreenBay.dir/src/Game.cpp.o: CMakeFiles/GreenBay.dir/flags.make
CMakeFiles/GreenBay.dir/src/Game.cpp.o: ../src/Game.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chuks/others/GreenBay/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/GreenBay.dir/src/Game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GreenBay.dir/src/Game.cpp.o -c /home/chuks/others/GreenBay/src/Game.cpp

CMakeFiles/GreenBay.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GreenBay.dir/src/Game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chuks/others/GreenBay/src/Game.cpp > CMakeFiles/GreenBay.dir/src/Game.cpp.i

CMakeFiles/GreenBay.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GreenBay.dir/src/Game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chuks/others/GreenBay/src/Game.cpp -o CMakeFiles/GreenBay.dir/src/Game.cpp.s

CMakeFiles/GreenBay.dir/src/Game.cpp.o.requires:
.PHONY : CMakeFiles/GreenBay.dir/src/Game.cpp.o.requires

CMakeFiles/GreenBay.dir/src/Game.cpp.o.provides: CMakeFiles/GreenBay.dir/src/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/GreenBay.dir/build.make CMakeFiles/GreenBay.dir/src/Game.cpp.o.provides.build
.PHONY : CMakeFiles/GreenBay.dir/src/Game.cpp.o.provides

CMakeFiles/GreenBay.dir/src/Game.cpp.o.provides.build: CMakeFiles/GreenBay.dir/src/Game.cpp.o

CMakeFiles/GreenBay.dir/src/Main.cpp.o: CMakeFiles/GreenBay.dir/flags.make
CMakeFiles/GreenBay.dir/src/Main.cpp.o: ../src/Main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chuks/others/GreenBay/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/GreenBay.dir/src/Main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GreenBay.dir/src/Main.cpp.o -c /home/chuks/others/GreenBay/src/Main.cpp

CMakeFiles/GreenBay.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GreenBay.dir/src/Main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chuks/others/GreenBay/src/Main.cpp > CMakeFiles/GreenBay.dir/src/Main.cpp.i

CMakeFiles/GreenBay.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GreenBay.dir/src/Main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chuks/others/GreenBay/src/Main.cpp -o CMakeFiles/GreenBay.dir/src/Main.cpp.s

CMakeFiles/GreenBay.dir/src/Main.cpp.o.requires:
.PHONY : CMakeFiles/GreenBay.dir/src/Main.cpp.o.requires

CMakeFiles/GreenBay.dir/src/Main.cpp.o.provides: CMakeFiles/GreenBay.dir/src/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GreenBay.dir/build.make CMakeFiles/GreenBay.dir/src/Main.cpp.o.provides.build
.PHONY : CMakeFiles/GreenBay.dir/src/Main.cpp.o.provides

CMakeFiles/GreenBay.dir/src/Main.cpp.o.provides.build: CMakeFiles/GreenBay.dir/src/Main.cpp.o

# Object files for target GreenBay
GreenBay_OBJECTS = \
"CMakeFiles/GreenBay.dir/src/Halo.cpp.o" \
"CMakeFiles/GreenBay.dir/src/Game.cpp.o" \
"CMakeFiles/GreenBay.dir/src/Main.cpp.o"

# External object files for target GreenBay
GreenBay_EXTERNAL_OBJECTS =

bin/GreenBay: CMakeFiles/GreenBay.dir/src/Halo.cpp.o
bin/GreenBay: CMakeFiles/GreenBay.dir/src/Game.cpp.o
bin/GreenBay: CMakeFiles/GreenBay.dir/src/Main.cpp.o
bin/GreenBay: CMakeFiles/GreenBay.dir/build.make
bin/GreenBay: /usr/local/lib/libOgreMain.so
bin/GreenBay: /usr/lib/x86_64-linux-gnu/libboost_thread.so
bin/GreenBay: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
bin/GreenBay: /usr/lib/x86_64-linux-gnu/libboost_system.so
bin/GreenBay: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
bin/GreenBay: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
bin/GreenBay: /usr/lib/x86_64-linux-gnu/libpthread.so
bin/GreenBay: /usr/lib/x86_64-linux-gnu/libOIS.so
bin/GreenBay: /usr/local/lib/libOgreOverlay.so
bin/GreenBay: /usr/local/lib/libOgreAL.so.0.0.0
bin/GreenBay: CMakeFiles/GreenBay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/GreenBay"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GreenBay.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GreenBay.dir/build: bin/GreenBay
.PHONY : CMakeFiles/GreenBay.dir/build

CMakeFiles/GreenBay.dir/requires: CMakeFiles/GreenBay.dir/src/Halo.cpp.o.requires
CMakeFiles/GreenBay.dir/requires: CMakeFiles/GreenBay.dir/src/Game.cpp.o.requires
CMakeFiles/GreenBay.dir/requires: CMakeFiles/GreenBay.dir/src/Main.cpp.o.requires
.PHONY : CMakeFiles/GreenBay.dir/requires

CMakeFiles/GreenBay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GreenBay.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GreenBay.dir/clean

CMakeFiles/GreenBay.dir/depend:
	cd /home/chuks/others/GreenBay/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuks/others/GreenBay /home/chuks/others/GreenBay /home/chuks/others/GreenBay/build /home/chuks/others/GreenBay/build /home/chuks/others/GreenBay/build/CMakeFiles/GreenBay.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GreenBay.dir/depend

