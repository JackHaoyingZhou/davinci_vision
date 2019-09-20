cmake_minimum_required(VERSION 3.0.0)
project(stereo_matching)
find_package(OpenCV REQUIRED)
find_package(PCL 1.8 REQUIRED COMPONENTS)
find_package(Boost REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set(CMAKE_CXX_STANDARD 11)

add_executable(stereo_matching main.cpp)
target_link_libraries( stereo_matching ${OpenCV_LIBS} ${PCL_LIBRARIES})
