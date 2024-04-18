cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(formula_parsing)
message(STATUS ${CMAKE_CURRENT_LIST_DIR})
include(${CMAKE_CURRENT_LIST_DIR}/grammar/CMakeLists.txt)

file(GLOB sources
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/include/*.h
)

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
include_directories(BEFORE ${CMAKE_CURRENT_LIST_DIR}/src ${CMAKE_CURRENT_LIST_DIR}/include)

set(GRAMMAR_LIB_DIR ${CMAKE_CURRENT_LIST_DIR}/lib)

add_library(
    formula_parsing STATIC
    ${ANTLR_Parserules_CXX_OUTPUTS}
    ${sources}
)

message(STATUS "Boost libs: ${Boost_LIBRARIES}")

target_link_libraries(formula_parsing antlr4_static ${Boost_LIBRARIES})
if(MSVC)
    target_compile_options(antlr4_static PRIVATE /W0)
endif()

install(
    TARGETS formula_parsing
    DESTINATION bin
    EXPORT formula_parsing
)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT formula_parsing)