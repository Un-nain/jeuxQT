cmake_minimum_required(VERSION 3.7)
project(tp4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

file (GLOB_RECURSE CIR2_sceneview_src src/*.cpp src/*.h)

add_executable(tp4 ${CIR2_sceneview_src})

target_link_libraries(tp4 Qt5::Widgets)
