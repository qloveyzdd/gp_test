set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
set(CMAKE_BUILD_TYPE Debug)

aux_source_directory(. time)

include_directories(.)

add_library(time_library SHARED ${time})

