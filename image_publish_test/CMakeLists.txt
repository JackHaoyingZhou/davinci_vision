cmake_minimum_required(VERSION 3.0.0)

project(image_publish_test)
find_package(catkin REQUIRED COMPONENTS roscpp cv_bridge sensor_msgs std_msgs image_transport)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

INCLUDE_DIRECTORIES(${catkin_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(image_publish_test ${OpenCV_LIBS} ${catkin_LIBRARIES})
