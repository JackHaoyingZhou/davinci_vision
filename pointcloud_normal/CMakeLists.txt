cmake_minimum_required(VERSION 2.8)

project(pointcloud_normal)

find_package(PCL 1.8 REQUIRED)
find_package(Boost REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(pointcloud_normal ${PCL_LIBRARIES})
