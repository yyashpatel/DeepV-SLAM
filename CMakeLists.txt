cmake_minimum_required(VERSION 3.25)
project(DeepV_SLAM)

# set CPP standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# relevant library stuff
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_subdirectory(${PROJECT_SOURCE_DIR}/3rdparty/tensorrtbuffer)

find_package(OpenCV 4.2 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(CUDA REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS}
    ${CUDA_INCLUDE_DIRS}
    ${YAML_CPP_INCLUDE_DIR}
)

# set(CMAKE_GENERATOR_PLATFORM x64)
# set(CMAKE_GENERATOR_ARCHITECTURE x64)
set(OpenCV_LIBS
    opencv_core
    opencv_imgproc
    opencv_highgui
    opencv_imgcodecs)

# define header files
set(HEADERS
    include/feature_matching.h
    include/load_image_data.h
    include/camera_pose.h
    include/triangulation.h
    include/bundle_adjustment.h
    include/super_point.h
    include/super_glue.h)

# define source files
set(SOURCES
    src/main.cpp
    src/feature_matching.cpp
    src/load_image_data.cpp
    src/camera_pose.cpp
    src/triangulation.cpp
    src/bundle_adjustment.cpp
    src/super_point.cpp
    src/super_glue.cpp)

# find necessary packages
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(CUDA REQUIRED)
find_package(yaml-cpp REQUIRED)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(
    nvinfer
    nvonnxparser
    ${OpenCV_LIBRARIES}
    ${CUDA_LIBRARIES}
    yaml-cpp
    tensorrtbuffer
)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
