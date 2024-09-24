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

antlr_target(head_interactor ${CMAKE_CURRENT_LIST_DIR}/head_interactor.g4 
                    LEXER
                    PARSER
                    LISTENER)
target_include_directories(antlr4_static INTERFACE ${ANTLR_GENERATED_FILES_DIR})


set_target_properties(antlr4_static
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/shared"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin"
)

include_directories(
    ${ANTLR4_INCLUDE_DIRS}
    ${ANTLR_head_interactor_OUTPUT_DIR}
    ${ANTLR_GENERATED_FILES_DIR}
)