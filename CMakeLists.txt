project(std_wrappers)

set(std_wrappers_headers
    std_wrappers/string.h
    std_wrappers/vector.h
)

add_library(std_wrappers INTERFACE)

target_include_directories(std_wrappers INTERFACE ${CMAKE_CURRENT_LIST_DIR})
