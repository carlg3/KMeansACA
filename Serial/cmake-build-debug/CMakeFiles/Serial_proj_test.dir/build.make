# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Serial_proj_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Serial_proj_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Serial_proj_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Serial_proj_test.dir/flags.make

CMakeFiles/Serial_proj_test.dir/Cluster.cpp.o: CMakeFiles/Serial_proj_test.dir/flags.make
CMakeFiles/Serial_proj_test.dir/Cluster.cpp.o: ../Cluster.cpp
CMakeFiles/Serial_proj_test.dir/Cluster.cpp.o: CMakeFiles/Serial_proj_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Serial_proj_test.dir/Cluster.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Serial_proj_test.dir/Cluster.cpp.o -MF CMakeFiles/Serial_proj_test.dir/Cluster.cpp.o.d -o CMakeFiles/Serial_proj_test.dir/Cluster.cpp.o -c /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Cluster.cpp

CMakeFiles/Serial_proj_test.dir/Cluster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Serial_proj_test.dir/Cluster.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Cluster.cpp > CMakeFiles/Serial_proj_test.dir/Cluster.cpp.i

CMakeFiles/Serial_proj_test.dir/Cluster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Serial_proj_test.dir/Cluster.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Cluster.cpp -o CMakeFiles/Serial_proj_test.dir/Cluster.cpp.s

CMakeFiles/Serial_proj_test.dir/Centroid.cpp.o: CMakeFiles/Serial_proj_test.dir/flags.make
CMakeFiles/Serial_proj_test.dir/Centroid.cpp.o: ../Centroid.cpp
CMakeFiles/Serial_proj_test.dir/Centroid.cpp.o: CMakeFiles/Serial_proj_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Serial_proj_test.dir/Centroid.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Serial_proj_test.dir/Centroid.cpp.o -MF CMakeFiles/Serial_proj_test.dir/Centroid.cpp.o.d -o CMakeFiles/Serial_proj_test.dir/Centroid.cpp.o -c /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Centroid.cpp

CMakeFiles/Serial_proj_test.dir/Centroid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Serial_proj_test.dir/Centroid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Centroid.cpp > CMakeFiles/Serial_proj_test.dir/Centroid.cpp.i

CMakeFiles/Serial_proj_test.dir/Centroid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Serial_proj_test.dir/Centroid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Centroid.cpp -o CMakeFiles/Serial_proj_test.dir/Centroid.cpp.s

CMakeFiles/Serial_proj_test.dir/Point.cpp.o: CMakeFiles/Serial_proj_test.dir/flags.make
CMakeFiles/Serial_proj_test.dir/Point.cpp.o: ../Point.cpp
CMakeFiles/Serial_proj_test.dir/Point.cpp.o: CMakeFiles/Serial_proj_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Serial_proj_test.dir/Point.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Serial_proj_test.dir/Point.cpp.o -MF CMakeFiles/Serial_proj_test.dir/Point.cpp.o.d -o CMakeFiles/Serial_proj_test.dir/Point.cpp.o -c /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Point.cpp

CMakeFiles/Serial_proj_test.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Serial_proj_test.dir/Point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Point.cpp > CMakeFiles/Serial_proj_test.dir/Point.cpp.i

CMakeFiles/Serial_proj_test.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Serial_proj_test.dir/Point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Point.cpp -o CMakeFiles/Serial_proj_test.dir/Point.cpp.s

CMakeFiles/Serial_proj_test.dir/Tupla.cpp.o: CMakeFiles/Serial_proj_test.dir/flags.make
CMakeFiles/Serial_proj_test.dir/Tupla.cpp.o: ../Tupla.cpp
CMakeFiles/Serial_proj_test.dir/Tupla.cpp.o: CMakeFiles/Serial_proj_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Serial_proj_test.dir/Tupla.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Serial_proj_test.dir/Tupla.cpp.o -MF CMakeFiles/Serial_proj_test.dir/Tupla.cpp.o.d -o CMakeFiles/Serial_proj_test.dir/Tupla.cpp.o -c /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Tupla.cpp

CMakeFiles/Serial_proj_test.dir/Tupla.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Serial_proj_test.dir/Tupla.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Tupla.cpp > CMakeFiles/Serial_proj_test.dir/Tupla.cpp.i

CMakeFiles/Serial_proj_test.dir/Tupla.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Serial_proj_test.dir/Tupla.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/Tupla.cpp -o CMakeFiles/Serial_proj_test.dir/Tupla.cpp.s

CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.o: CMakeFiles/Serial_proj_test.dir/flags.make
CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.o: ../kmeans_sequential.cpp
CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.o: CMakeFiles/Serial_proj_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.o -MF CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.o.d -o CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.o -c /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/kmeans_sequential.cpp

CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/kmeans_sequential.cpp > CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.i

CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/kmeans_sequential.cpp -o CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.s

# Object files for target Serial_proj_test
Serial_proj_test_OBJECTS = \
"CMakeFiles/Serial_proj_test.dir/Cluster.cpp.o" \
"CMakeFiles/Serial_proj_test.dir/Centroid.cpp.o" \
"CMakeFiles/Serial_proj_test.dir/Point.cpp.o" \
"CMakeFiles/Serial_proj_test.dir/Tupla.cpp.o" \
"CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.o"

# External object files for target Serial_proj_test
Serial_proj_test_EXTERNAL_OBJECTS =

Serial_proj_test: CMakeFiles/Serial_proj_test.dir/Cluster.cpp.o
Serial_proj_test: CMakeFiles/Serial_proj_test.dir/Centroid.cpp.o
Serial_proj_test: CMakeFiles/Serial_proj_test.dir/Point.cpp.o
Serial_proj_test: CMakeFiles/Serial_proj_test.dir/Tupla.cpp.o
Serial_proj_test: CMakeFiles/Serial_proj_test.dir/kmeans_sequential.cpp.o
Serial_proj_test: CMakeFiles/Serial_proj_test.dir/build.make
Serial_proj_test: CMakeFiles/Serial_proj_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Serial_proj_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Serial_proj_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Serial_proj_test.dir/build: Serial_proj_test
.PHONY : CMakeFiles/Serial_proj_test.dir/build

CMakeFiles/Serial_proj_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Serial_proj_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Serial_proj_test.dir/clean

CMakeFiles/Serial_proj_test.dir/depend:
	cd /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug /mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/Serial/cmake-build-debug/CMakeFiles/Serial_proj_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Serial_proj_test.dir/depend

