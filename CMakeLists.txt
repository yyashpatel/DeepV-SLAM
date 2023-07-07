cmake_minimum_required(VERSION 3.25)
project(DeepV_SLAM)

set(CMAKE_CXX_STANDARD 14)

add_executable(DeepV_SLAM
        feature_matching.cpp
        load_image_data.hpp)

set(ENV{OPENCV_DIR}  "C:/Program Files/opencv/build/x64/vc16/lib")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_GENERATOR_PLATFORM x64)
set(CMAKE_GENERATOR_ARCHITECTURE x64)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(DeepV_SLAM ${OpenCV_LIBS})
