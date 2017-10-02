cmake_minimum_required(VERSION 3.0.0)
project(example_std)

if(WIN32)
    #remove min and max macro declares from windows builds, causes issues with std::min/max
    add_definitions(-DNOMINMAX)
endif()

#example lib
#add_definitions(-DEXAMPLE_STD_EXPORTS)
set(example_std_lib_sources
    example_std_lib.cpp
    example_std.cpp
)

set(example_std_lib_headers
    example_std_lib.h
    example_std.h
)

set(example_std_lib_libraries
    std_wrappers
)

add_library(example_std_lib
    ${example_std_lib_sources}
    ${example_std_lib_headers}
)

target_compile_definitions(example_std_lib PRIVATE -DEXAMPLE_STD_EXPORTS)
target_link_libraries(example_std_lib ${example_std_lib_libraries})
target_include_directories(example_std_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

#example exe
set(example_std_sources
    main.cpp
)

set(example_std_headers
)

set(example_std_libraries
    example_std_lib
)

add_executable(example_std
	${example_std_sources}
	${example_std_headers}
)

target_link_libraries(example_std ${example_std_libraries})

if(WIN32)
    foreach(CONFIG ${CMAKE_CONFIGURATION_TYPES})
        string(TOUPPER ${CONFIG} CONFIGG_UPPER)
        set_target_properties(example_std PROPERTIES LINK_FLAGS_${CONFIGG_UPPER} "/SUBSYSTEM:CONSOLE")
        set_target_properties(example_std PROPERTIES COMPILE_DEFINITIONS_${CONFIGG_UPPER} "_CONSOLE")
    endforeach()
endif(WIN32)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
