set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
set(CMAKE_BUILD_TYPE Debug)

aux_source_directory(. gp)

include_directories(.)

add_library(gp_library SHARED ${gp})

