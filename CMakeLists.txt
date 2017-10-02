cmake_minimum_required(VERSION 3.0.0)

project(std_wrappers)

set(std_wrappers_headers
    std_wrappers/string.h
    std_wrappers/vector.h
)

add_library(std_wrappers INTERFACE)

target_include_directories(std_wrappers INTERFACE ${CMAKE_CURRENT_LIST_DIR})

if(STD_WRAPPER_BUILD_EXAMPLE)
add_subdirectory(example)
endif()
