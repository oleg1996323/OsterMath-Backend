cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(PhysicalProps)

file(GLOB physprop_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

include(${CMAKE_CURRENT_SOURCE_DIR}/parsing/CMakeLists.txt)
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(physical_props ${physprop_sources})

message(STATUS ${Boost_LIBRARIES})

target_link_libraries(physical_props STATIC ${Boost_LIBRARIES} formula_parsing)

install(
    TARGETS physical_props
    DESTINATION bin
    EXPORT physical_props
)

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})