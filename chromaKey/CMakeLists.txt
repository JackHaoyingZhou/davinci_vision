cmake_minimum_required(VERSION 3.0.0)
project(chromaKey)

find_package(OpenCV REQUIRED)
find_package(catkin REQUIRED COMPONENTS roscpp cv_bridge image_transport OpenCV)
find_package(Boost REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${catkin_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

add_executable(chromaKey main.cpp)
target_link_libraries(chromaKey ${OpenCV_LIBRARIES} ${catkin_LIBRARIES} ${Boost_LIBS})
