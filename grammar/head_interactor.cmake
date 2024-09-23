cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(head_interactor)
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
set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_LIST_DIR}/antlr-4.13.1-complete.jar)
set(PROJECT_RUNTIME_ANTLR ${CMAKE_CURRENT_LIST_DIR}/antlr4_runtime)
message(STATUS ${CMAKE_CURRENT_BINARY_DIR})

include(${CMAKE_CURRENT_LIST_DIR}/FindANTLR.cmake)
add_definitions(
    -DANTLR4CPP_STATIC
    -D_SILENCE_ALL_CXX20_DEPRECATION_WARNINGS
)

antlr_target(head_interactor head_interactor.g4 
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
add_library(
    antlr_head_interactor SHARED
    ${ANTLR_head_interactor_CXX_OUTPUTS}
)
target_link_libraries(antlr_head_interactor PRIVATE antlr4_static)
target_include_directories(antlr_head_interactor 
                            PRIVATE 
                            ${ANTLR_GENERATED_FILES_DIR}
                            ${ANTLR_head_interactor_OUTPUT_DIR})

include_directories(
    ${ANTLR4_INCLUDE_DIRS}
    ${ANTLR_head_interactor_OUTPUT_DIR}
    ${ANTLR_GENERATED_FILES_DIR}
)