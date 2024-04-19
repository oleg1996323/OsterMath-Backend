cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(PhysicalProps)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_CURRENT_LIST_DIR}/arithmetictree/CMakeLists.txt)
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB physprop_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(physical_props ${physprop_sources})

message(STATUS ${Boost_LIBRARIES})

message(STATUS ${arithmetictree})
message(STATUS ${arithmetic_tree_INCLUDE_DIR})
#target_include_directories(physical_props PUBLIC ${arithmetic_tree_INCLUDE_DIR})
target_link_libraries(physical_props PUBLIC arithmetictree PRIVATE Boost::boost ${Boost_LIBRARIES})

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})