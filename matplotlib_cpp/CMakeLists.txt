cmake_minimum_required (VERSION 3.5.1)
project (matplotlibcpp)
set (CMAKE_CXX_STANDARD 14)

find_package (PythonLibs 2.7)

include_directories(include)
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(/usr/include/eigen3)

add_executable(number_plot src/number_plot.cpp)
add_executable(graph src/graph.cpp)
add_executable(synthetic_poses src/synthetic_poses.cpp)
add_executable(relative_edges src/relative_edges.cpp)

target_link_libraries(number_plot ${PYTHON_LIBRARIES})
target_link_libraries(graph ${PYTHON_LIBRARIES})
target_link_libraries(synthetic_poses ${PYTHON_LIBRARIES})
target_link_libraries(relative_edges ${PYTHON_LIBRARIES})