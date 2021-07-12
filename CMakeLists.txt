cmake_minimum_required(VERSION 3.0)

project(game)

#add_compile_options("-wall -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(./stringtotime)
add_subdirectory(./gp)

include_directories(./stringtotime)
include_directories(./gp)

add_executable(main main.cpp)

target_link_libraries(main time_library)
target_link_libraries(main gp_library)