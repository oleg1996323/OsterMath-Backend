cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(PhysicalProps)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
if(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "Not defined config")
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/arithmetictree/CMakeLists.txt)

file(GLOB_RECURSE physprop_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp
)

file(GLOB_RECURSE physprop_INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS        ON)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.75.0 REQUIRED COMPONENTS json)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost not found")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include/types)

add_executable(physical_props ${physprop_SOURCE})

message(STATUS ${ARITHM_TREE_INCLUDE_DIR})
#target_link_directories(physical_props PUBLIC ${ARITHM_TREE_LIBRARY_DIR})
target_link_libraries(physical_props PUBLIC arithmetictree)
target_include_directories(physical_props PUBLIC ${ARITHM_TREE_INCLUDE_DIR})
target_compile_definitions(physical_props PUBLIC $<$<CONFIG:Debug>:DEBUG>)

set_target_properties(physical_props
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/shared"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin"
)

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})