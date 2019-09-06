cmake_minimum_required(VERSION 3.12)
project(cloudViewer)

find_package(PCL 1.8 REQUIRED)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(cloudViewer main.cpp)
target_link_libraries(cloudViewer ${PCL_LIBRARIES})