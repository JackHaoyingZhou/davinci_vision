cmake_minimum_required(VERSION 3.0.0)

project(image_subscribe_test)

find_package(OpenCV REQUIRED)
find_package(catkin REQUIRED COMPONENTS
                    roscpp
                    std_msgs
                    sensor_msgs
                    cv_bridge
                    image_transport )
find_package(Boost REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${catkin_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(image_subscribe_test ${catkin_LIBRARIES} ${OpenCV_LIBS} ${Boost_LIBRARIES})

