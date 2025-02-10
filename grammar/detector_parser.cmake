cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(detect_type_function)
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

antlr_target(detect_type_function ${CMAKE_CURRENT_LIST_DIR}/detect_type_function.g4 
                                    PARSER
                                    LISTENER
                                    DEPENDS_ANTLR main_lexics
                                    COMPILE_FLAGS -lib ${ANTLR_main_lexics_OUTPUT_DIR})

target_include_directories(antlr4_static INTERFACE ${ANTLR_GENERATED_FILES_DIR} ${ANTLR_detect_type_function_OUTPUT_DIR})

set(WITH_STATIC_CRT OFF CACHE BOOL "Visual C++ static CRT for ANTLR" FORCE)

include_directories(
    ${ANTLR_detect_type_function_OUTPUT_DIR}
)