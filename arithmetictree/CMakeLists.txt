cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(arithmetictree)

set(CMAKE_CXX_STANDARD 20)
message(STATUS ${CMAKE_CURRENT_LIST_DIR})
include(${CMAKE_CURRENT_LIST_DIR}/grammar/CMakeLists.txt)

file(GLOB arithmetic_tree_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)

file(GLOB arithmetic_tree_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

set(ARITHM_TREE_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(ARITHM_TREE_LIBRARY_DIR ${CMAKE_CURRENT_LIST_DIR}/lib)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.75.0 REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost not found")
endif()

add_library(
    arithmetictree STATIC
    ${ANTLR_Parserules_CXX_OUTPUTS}
    ${arithmetic_tree_SOURCES}
)

target_link_libraries(arithmetictree PUBLIC antlr4_static Boost::boost)
target_compile_definitions(arithmetictree PUBLIC $<$<CONFIG:Debug>:DEBUG>)
if(MSVC)
    target_compile_options(antlr4_static PUBLIC /W0)
endif()

target_include_directories(arithmetictree PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src ${CMAKE_CURRENT_LIST_DIR}/include ${ANTLR_Parserules_OUTPUT_DIR})

set_target_properties(arithmetictree
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin"
)

install(
    TARGETS arithmetictree
    EXPORT arithmetictree
    LIBRARY DESTINATION "${CMAKE_CURRENT_LIST_DIR}/lib"
    ARCHIVE DESTINATION "${CMAKE_CURRENT_LIST_DIR}/lib"
    RUNTIME DESTINATION "${CMAKE_CURRENT_LIST_DIR}/bin"
    INCLUDES DESTINATION "${CMAKE_CURRENT_LIST_DIR}/include"
)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT arithmetictree)