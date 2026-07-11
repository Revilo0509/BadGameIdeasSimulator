cmake_minimum_required(VERSION 3.20)
project(BadGameIdeaSimulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(BUILD_EXAMPLES OFF)

add_subdirectory(extern/Shirag)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/extern/Shirag/include") 

# Sources
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_executable(BadGameIdeaSimulator ${SOURCES})
target_link_libraries(BadGameIdeaSimulator PRIVATE Shirag)

target_compile_options(BadGameIdeaSimulator PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>
    $<$<COMPILE_LANGUAGE:CXX>:-fpermissive>
    $<$<COMPILE_LANGUAGE:CXX>:-Wno-shift-count-overflow>
)

if (WIN32)

    target_link_options(BadGameIdeaSimulator PRIVATE
        -static-libgcc
        -static-libstdc++
    )

endif()

# optimization
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Add optimization flags
    target_compile_options(BadGameIdeaSimulator PRIVATE -O3)
    
    # strip symbols to reduce binary size
    if (NOT WIN32)
        target_link_options(BadGameIdeaSimulator PRIVATE -s)
    endif()
endif()