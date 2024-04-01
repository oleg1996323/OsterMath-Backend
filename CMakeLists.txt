cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(PhysProperties)

include(${CMAKE_CURRENT_SOURCE_DIR}/grammar/CMakeLists.txt)

file(GLOB sources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost not found")
endif()

include_directories(${ANTLR_OUTPUT_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})

add_library(
    PhysProperties STATIC
    ${ANTLR_Parserules_CXX_OUTPUTS}
    ${sources}
)

target_link_libraries(PhysProperties antlr4_static ${Boost_LIBRARIES})
if(MSVC)
    target_compile_options(antlr4_static PRIVATE /W0)
endif()

install(
    TARGETS PhysProperties
    DESTINATION bin
    EXPORT PhysProperties
)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT PhysProperties)