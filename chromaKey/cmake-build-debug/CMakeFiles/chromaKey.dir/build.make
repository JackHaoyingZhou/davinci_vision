# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/aimlab3/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/aimlab3/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aimlab3/CLionProjects/chromaKey

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aimlab3/CLionProjects/chromaKey/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/chromaKey.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chromaKey.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chromaKey.dir/flags.make

CMakeFiles/chromaKey.dir/main.cpp.o: CMakeFiles/chromaKey.dir/flags.make
CMakeFiles/chromaKey.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aimlab3/CLionProjects/chromaKey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chromaKey.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chromaKey.dir/main.cpp.o -c /home/aimlab3/CLionProjects/chromaKey/main.cpp

CMakeFiles/chromaKey.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chromaKey.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aimlab3/CLionProjects/chromaKey/main.cpp > CMakeFiles/chromaKey.dir/main.cpp.i

CMakeFiles/chromaKey.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chromaKey.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aimlab3/CLionProjects/chromaKey/main.cpp -o CMakeFiles/chromaKey.dir/main.cpp.s

# Object files for target chromaKey
chromaKey_OBJECTS = \
"CMakeFiles/chromaKey.dir/main.cpp.o"

# External object files for target chromaKey
chromaKey_EXTERNAL_OBJECTS =

chromaKey: CMakeFiles/chromaKey.dir/main.cpp.o
chromaKey: CMakeFiles/chromaKey.dir/build.make
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
chromaKey: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
chromaKey: CMakeFiles/chromaKey.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aimlab3/CLionProjects/chromaKey/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chromaKey"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chromaKey.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chromaKey.dir/build: chromaKey

.PHONY : CMakeFiles/chromaKey.dir/build

CMakeFiles/chromaKey.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chromaKey.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chromaKey.dir/clean

CMakeFiles/chromaKey.dir/depend:
	cd /home/aimlab3/CLionProjects/chromaKey/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aimlab3/CLionProjects/chromaKey /home/aimlab3/CLionProjects/chromaKey /home/aimlab3/CLionProjects/chromaKey/cmake-build-debug /home/aimlab3/CLionProjects/chromaKey/cmake-build-debug /home/aimlab3/CLionProjects/chromaKey/cmake-build-debug/CMakeFiles/chromaKey.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chromaKey.dir/depend

