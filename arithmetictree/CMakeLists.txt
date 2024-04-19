cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(arithmetictree)
message(STATUS ${CMAKE_CURRENT_LIST_DIR})
include(${CMAKE_CURRENT_LIST_DIR}/grammar/CMakeLists.txt)

file(GLOB arithmetic_tree_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)

file(GLOB arithmetic_tree_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.82.0 REQUIRED COMPONENTS json)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost not found")
endif()

include_directories(${ANTLR_Parserules_OUTPUT_DIR})

set(arithmetic_tree_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
message(STATUS ${arithmetic_tree_INCLUDE_DIR})
include_directories(BEFORE ${CMAKE_CURRENT_LIST_DIR}/src ${arithmetic_tree_INCLUDE_DIR})

set(GRAMMAR_LIB_DIR ${CMAKE_CURRENT_LIST_DIR}/lib)
message(STATUS ${GRAMMAR_LIB_DIR})
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${GRAMMAR_LIB_DIR})

add_library(
    arithmetictree STATIC
    ${ANTLR_Parserules_CXX_OUTPUTS}
    ${arithmetic_tree_INCLUDES}
    ${arithmetic_tree_SOURCES}
)

message(STATUS "Boost libs: ${Boost_LIBRARIES}")

target_link_libraries(arithmetictree antlr4_static Boost::boost)
if(MSVC)
    target_compile_options(antlr4_static PRIVATE /W0)
endif()

install(
    TARGETS arithmetictree
    DESTINATION bin
    EXPORT arithmetictree
)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT arithmetictree)