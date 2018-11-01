cmake_minimum_required (VERSION 3.5.1)
project (multi_directory_test)

include_directories(include)

set(SOURCES src/lib_test.cpp src/myclass.cpp)
# file(GLOB SOURCES "src/*.cpp")


add_executable(sq_root_exe ${SOURCES})
