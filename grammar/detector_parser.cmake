cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(detector)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 20)
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(
        CMAKE_CXX_FLAGS_DEBUG
        "${CMAKE_CXX_FLAGS_DEBUG} /JMC"
    )
else()
    set(
        CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wno-unused-parameter -Wno-implicit-fallthrough"
    )
endif()

set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_LIST_DIR}/bin)
include(${CMAKE_CURRENT_LIST_DIR}/FindANTLR.cmake)
add_definitions(
    -DANTLR4CPP_STATIC
    -D_SILENCE_ALL_CXX20_DEPRECATION_WARNINGS
)

make_directory(${PROJECT_RUNTIME_ANTLR}/runtime/src)
antlr_target(detect_type_function detect_type_function.g4 
                        PACKAGE detect
                        LEXER
                        PARSER
                        LISTENER)

target_include_directories(antlr4_static INTERFACE ${ANTLR_GENERATED_FILES_DIR})

set_target_properties(antlr4_static
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin"
)
set(WITH_STATIC_CRT OFF CACHE BOOL "Visual C++ static CRT for ANTLR" FORCE)

message(STATUS "detect_type_function_CXX_OUTPUTS: ${ANTLR_detect_type_function_CXX_OUTPUTS}")

add_library(
    antlr_detector SHARED
    ${ANTLR_detect_type_function_CXX_OUTPUTS})

target_link_libraries(antlr_detector PRIVATE antlr4_static)
target_include_directories(antlr_detector 
                            PRIVATE
                            ${ANTLR_GENERATED_FILES_DIR}
                            ${ANTLR_detect_type_function_OUTPUT_DIR})

include_directories(
    ${ANTLR4_INCLUDE_DIRS}
    ${ANTLR_detect_type_function_OUTPUT_DIR}
    ${ANTLR_GENERATED_FILES_DIR}
)