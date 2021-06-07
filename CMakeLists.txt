cmake_minimum_required(VERSION 3.19)
project(feature_extraction)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILE main.cpp)
add_executable(bezier_run ${SOURCE_FILE})

include_directories(bezier)
add_subdirectory(bezier)

target_link_libraries(bezier_run bezier)

add_subdirectory(unit_test)