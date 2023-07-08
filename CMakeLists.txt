cmake_minimum_required(VERSION 3.25)
project(DeepV_SLAM)

# set CPP standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# relevant library stuff
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
# set(CMAKE_GENERATOR_PLATFORM x64)
# set(CMAKE_GENERATOR_ARCHITECTURE x64)
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

# define source files
set(SOURCES src/main.cpp src/feature_matching.cpp src/load_image_data.cpp
            src/camera_pose.cpp src.cpp/ src/triangulation.cpp)

# define header files
set(HEADERS include/feature_matching.h include/load_image_data.h
            include/camera_pose.h include/triangulation.h)

# find necessary packages
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS} ${Eigen_INCLUDE_DIRS})

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )
