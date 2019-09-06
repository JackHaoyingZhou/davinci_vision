cmake_minimum_required(VERSION 3.12)
project(cv_stream)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

add_executable(cv_stream main.cpp)
target_link_libraries(cv_stream ${OpenCV_LIBS})