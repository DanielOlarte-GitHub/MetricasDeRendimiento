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
CMAKE_SOURCE_DIR = /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Debug

# Include any dependencies generated for this target.
include CMakeFiles/logisticProyect.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/logisticProyect.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/logisticProyect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/logisticProyect.dir/flags.make

CMakeFiles/logisticProyect.dir/main.cpp.o: CMakeFiles/logisticProyect.dir/flags.make
CMakeFiles/logisticProyect.dir/main.cpp.o: ../main.cpp
CMakeFiles/logisticProyect.dir/main.cpp.o: CMakeFiles/logisticProyect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/logisticProyect.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/logisticProyect.dir/main.cpp.o -MF CMakeFiles/logisticProyect.dir/main.cpp.o.d -o CMakeFiles/logisticProyect.dir/main.cpp.o -c /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/main.cpp

CMakeFiles/logisticProyect.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logisticProyect.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/main.cpp > CMakeFiles/logisticProyect.dir/main.cpp.i

CMakeFiles/logisticProyect.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logisticProyect.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/main.cpp -o CMakeFiles/logisticProyect.dir/main.cpp.s

CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.o: CMakeFiles/logisticProyect.dir/flags.make
CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.o: ../Extraccion/extraction.cpp
CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.o: CMakeFiles/logisticProyect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.o -MF CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.o.d -o CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.o -c /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Extraccion/extraction.cpp

CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Extraccion/extraction.cpp > CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.i

CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Extraccion/extraction.cpp -o CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.s

CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.o: CMakeFiles/logisticProyect.dir/flags.make
CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.o: ../ClaseLogistic/regressionlogistic.cpp
CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.o: CMakeFiles/logisticProyect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.o -MF CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.o.d -o CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.o -c /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/ClaseLogistic/regressionlogistic.cpp

CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/ClaseLogistic/regressionlogistic.cpp > CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.i

CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/ClaseLogistic/regressionlogistic.cpp -o CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.s

# Object files for target logisticProyect
logisticProyect_OBJECTS = \
"CMakeFiles/logisticProyect.dir/main.cpp.o" \
"CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.o" \
"CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.o"

# External object files for target logisticProyect
logisticProyect_EXTERNAL_OBJECTS =

logisticProyect: CMakeFiles/logisticProyect.dir/main.cpp.o
logisticProyect: CMakeFiles/logisticProyect.dir/Extraccion/extraction.cpp.o
logisticProyect: CMakeFiles/logisticProyect.dir/ClaseLogistic/regressionlogistic.cpp.o
logisticProyect: CMakeFiles/logisticProyect.dir/build.make
logisticProyect: CMakeFiles/logisticProyect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable logisticProyect"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logisticProyect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/logisticProyect.dir/build: logisticProyect
.PHONY : CMakeFiles/logisticProyect.dir/build

CMakeFiles/logisticProyect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/logisticProyect.dir/cmake_clean.cmake
.PHONY : CMakeFiles/logisticProyect.dir/clean

CMakeFiles/logisticProyect.dir/depend:
	cd /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Debug /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Debug /home/daniel/Escritorio/TrabajosU/Metricas/logisticProyect/Debug/CMakeFiles/logisticProyect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/logisticProyect.dir/depend

