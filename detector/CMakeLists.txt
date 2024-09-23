cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(detector)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# message(STATUS "CurrentSourceDir: "${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Parent Dir: ${OSTERMATH_BE_DIR}")
# include(${OSTERMATH_BE_DIR}/grammar/CMakeLists.txt)

# message(STATUS "ANTLR_OUTPUT_DIR: ${ANTLR_detect_type_function_OUTPUT_DIR}")
# #message(STATUS "ANTLR_OUTPUT_DIR: ${ANTLR_detector_SOURCE}")


include_directories(
    ${ANTLR4_INCLUDE_DIRS}
    ${ANTLR_detect_type_function_OUTPUT_DIR}
)

message(STATUS ${detector_SOURCES})

add_library(
    detector SHARED
    ${ANTLR_detect_type_function_CXX_OUTPUTS}
)

set_target_properties(detector PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries(detector PRIVATE detect_type_function)
target_compile_definitions(detector PUBLIC $<$<CONFIG:Debug>:DEBUG>)

target_include_directories(detector
                    PUBLIC 
                        ${CMAKE_CURRENT_LIST_DIR}/include/detector
                    PRIVATE
                        ${ANTLR_detector_SOURCE})

set_target_properties(detector
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${OSTERMATH_BE_DIR}/lib/Debug"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OSTERMATH_BE_DIR}/lib/Debug"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OSTERMATH_BE_DIR}/bin/Debug"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${OSTERMATH_BE_DIR}/lib/Release"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OSTERMATH_BE_DIR}/lib/Release"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OSTERMATH_BE_DIR}/bin/Release"
)

install(
    TARGETS detector
    LIBRARY DESTINATION ${OSTERMATH_BE_DIR}/lib
    ARCHIVE DESTINATION ${OSTERMATH_BE_DIR}/lib
    RUNTIME DESTINATION ${OSTERMATH_BE_DIR}/bin
    INCLUDES DESTINATION ${OSTERMATH_BE_DIR}/include/detector
    EXPORT detector
)

if(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "Not defined config")
endif()

include_directories(${OSTERMATH_BE_DIR}/include ${OSTERMATH_BE_DIR}/include/types)