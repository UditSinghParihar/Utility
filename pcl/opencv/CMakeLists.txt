cmake_minimum_required(VERSION 2.8)
project(OpenCV)
set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})

include_directories(include)

find_package(PCL 1.7 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set(ALL_LIBS ${OpenCV_LIBS} ${PCL_LIBRARIES})

add_executable(cv_test cv_test.cpp)
add_executable(color2gray color2gray.cpp)
add_executable(sift_icp sift_icp.cpp)
add_executable(cloud_coordinate_axis cloud_coordinate_axis.cpp)
add_executable(orb_test orb_test.cpp)
add_executable(feature_detectors feature_detectors.cpp)
add_executable(generate_point_cloud generate_point_cloud.cpp)
add_executable(generate_gibson_cloud generate_gibson_cloud.cpp)
add_executable(opencv_depthto3d opencv_depthto3d.cpp)

target_link_libraries(cv_test ${ALL_LIBS})
target_link_libraries(color2gray ${ALL_LIBS})
target_link_libraries(sift_icp ${ALL_LIBS})
target_link_libraries(cloud_coordinate_axis ${ALL_LIBS})
target_link_libraries(orb_test ${ALL_LIBS})
target_link_libraries(feature_detectors ${ALL_LIBS})
target_link_libraries(generate_point_cloud ${ALL_LIBS})
target_link_libraries(generate_gibson_cloud ${ALL_LIBS})
target_link_libraries(opencv_depthto3d ${ALL_LIBS})