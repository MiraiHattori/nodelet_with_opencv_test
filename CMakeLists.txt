cmake_minimum_required(VERSION 2.8.3)
project(nodelet_with_opencv_test)

find_package(catkin REQUIRED COMPONENTS
  nodelet roscpp sensor_msgs cv_bridge
)
catkin_package(CATKIN_DEPENDS
  nodelet roscpp sensor_msgs cv_bridge
)

set(CMAKE_CXX_FLAGS "-std=c++11 -O2 ${CMAKE_CXX_FLAGS}")
find_package(OpenCV)
message("${OpenCV_INCLUDE_DIRS}")
message("${OpenCV_LIBRARIES}")

include_directories(${catkin_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
add_executable(main src/test.cpp)
target_link_libraries(main ${OpenCV_LIBRARIES} ${catkin_LIBRARIES})

add_library(main2 src/test_nodelet.cpp)
target_link_libraries(main2 ${OpenCV_LIBRARIES} ${catkin_LIBRARIES})
