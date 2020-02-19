cmake_minimum_required(VERSION 3.0.0)
project(hsv)
find_package( OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 11)

add_executable(hsv main.cpp)
target_link_libraries(hsv ${OpenCV_LIBS})
