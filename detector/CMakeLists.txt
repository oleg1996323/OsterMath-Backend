cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(detector)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
if(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "Not defined config")
endif()

set(DETECTOR_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${DETECTOR_INCLUDE_DIR})

file(GLOB_RECURSE DETECTOR_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/**.h
        ${CMAKE_CURRENT_LIST_DIR}/src/**.cpp)

add_library(
    detector SHARED
    ${ANTLR_detect_type_function_CXX_OUTPUTS}
    ${DETECTOR_SOURCES}
)
target_link_libraries(detector PRIVATE antlr4_static)
target_compile_definitions(detector PUBLIC $<$<CONFIG:Debug>:DEBUG>)
target_include_directories(detector
                    PUBLIC 
                        ${DETECTOR_INCLUDE_DIR}
                    PRIVATE
                        ${ANTLR_detect_type_function_OUTPUT_DIR}
                        ${ANTLR_main_lexics_OUTPUT_DIR}
                        ${ANTLR_GENERATED_FILES_DIR})
set_target_properties(detector
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${OSTERMATH_BE_DIR}/lib/Debug"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OSTERMATH_BE_DIR}/shared/Debug"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OSTERMATH_BE_DIR}/bin/Debug"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${OSTERMATH_BE_DIR}/lib/Release"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OSTERMATH_BE_DIR}/shared/Release"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OSTERMATH_BE_DIR}/bin/Release"
)

install(
    TARGETS detector
    LIBRARY DESTINATION ${OSTERMATH_BE_DIR}/shared
    ARCHIVE DESTINATION ${OSTERMATH_BE_DIR}/lib
    RUNTIME DESTINATION ${OSTERMATH_BE_DIR}/bin
    INCLUDES DESTINATION ${DETECTOR_INCLUDE_DIR}
    EXPORT detector
)

