cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(arithmetictree)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
message(STATUS ${CMAKE_CURRENT_LIST_DIR})
include(${CMAKE_CURRENT_LIST_DIR}/grammar/CMakeLists.txt)

file(GLOB_RECURSE arithmetic_tree_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/**.cpp
    ${CMAKE_CURRENT_LIST_DIR}/include/**.h
)

#message(STATUS ${arithmetic_tree_SOURCES})

set(ARITHM_TREE_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/include/types ${CMAKE_CURRENT_LIST_DIR}/include/exception)
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

file(GLOB_RECURSE ANTLR_GENERATED_SOURCES 
                ${ANTLR_GENERATED_FILES_head_interactor}/**.h
                ${ANTLR_GENERATED_FILES_head_interactor}/**.cpp)

#message(STATUS "${ANTLR_GENERATED_SOURCES}")

set(USER_INTERFACE ON)

add_library(
    bailerror STATIC
    ${ANTLR_head_interactor_CXX_OUTPUTS}
    ${CMAKE_CURRENT_LIST_DIR}/src/exception/bailerror.cpp
)

target_include_directories(bailerror
                    PUBLIC
                        ${CMAKE_CURRENT_LIST_DIR}/include
                        ${CMAKE_CURRENT_LIST_DIR}/include/exception
                        ${ANTLR_head_interactor_OUTPUT_DIR}
                        ${ANTLR_GENERATED_FILES_head_interactor})

set_target_properties(bailerror PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(
    exceptions STATIC
    ${ANTLR_head_interactor_CXX_OUTPUTS}
    ${CMAKE_CURRENT_LIST_DIR}/src/exception/exception.cpp
)

set_target_properties(exceptions PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(exceptions
                    PUBLIC
                        ${CMAKE_CURRENT_LIST_DIR}/include
                        ${CMAKE_CURRENT_LIST_DIR}/include/exception
                        ${ANTLR_head_interactor_OUTPUT_DIR}
                        ${ANTLR_GENERATED_FILES_head_interactor})

add_library(
    arithmetictree STATIC
    ${arithmetic_tree_SOURCES}
    ${ANTLR_head_interactor_CXX_OUTPUTS}
    ${ANTLR_GENERATED_FILES_head_interactor}
)

set_target_properties(arithmetictree PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries(arithmetictree PUBLIC Boost::boost exceptions PRIVATE bailerror head_interactor)
target_compile_definitions(arithmetictree PUBLIC $<$<CONFIG:Debug>:DEBUG>)

target_include_directories(arithmetictree
                    PUBLIC 
                        ${CMAKE_CURRENT_LIST_DIR}/include
                        ${CMAKE_CURRENT_LIST_DIR}/include/types
                        ${ANTLR_head_interactor_OUTPUT_DIR}

                    PRIVATE
                        ${CMAKE_CURRENT_LIST_DIR}/include/exception
                        ${ANTLR_GENERATED_FILES_head_interactor})

message(STATUS ${USER_INTERFACE})

if(NOT USER_INTERFACE)
    set_target_properties(arithmetictree exceptions bailerror
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/uiless/Debug"
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/uiless/Debug"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/uiless/Debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/uiless/Release"
        LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/uiless/Release"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/uiless/Release"
    )
else()
    set_target_properties(arithmetictree exceptions bailerror
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/ui/Debug"
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/ui/Debug"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/ui/Debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/ui/Release"
        LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/ui/Release"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/ui/Release"
    )
    target_compile_definitions(arithmetictree PUBLIC USER_INTERFACE)
endif()

install(
    TARGETS arithmetictree
    LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/lib
    ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/lib
    RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin
    INCLUDES DESTINATION ${CMAKE_CURRENT_LIST_DIR}/include
    EXPORT arithmetictree
)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT arithmetictree)

file(GLOB_RECURSE detector_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/detector/**.cpp
    ${CMAKE_CURRENT_LIST_DIR}/include/detector/**.h
    ${CMAKE_CURRENT_LIST_DIR}/include/types/**.h
)

message(STATUS ${detector_SOURCES})

add_library(
    detector SHARED
    ${detector_SOURCES}
    ${ANTLR_detect_type_function_CXX_OUTPUTS}
    ${ANTLR_GENERATED_FILES_detect_type_function}
)

set_target_properties(detector PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries(detector PRIVATE detect_type_function)
target_compile_definitions(detector PUBLIC $<$<CONFIG:Debug>:DEBUG>)

target_include_directories(detector
                    PUBLIC 
                        ${CMAKE_CURRENT_LIST_DIR}/include/detector
                        ${CMAKE_CURRENT_LIST_DIR}/include/types
                        ${CMAKE_CURRENT_LIST_DIR}/include
                        ${ANTLR_detect_type_function_OUTPUT_DIR}
                    PRIVATE
                        ${ANTLR_GENERATED_FILES_detect_type_function})

message(STATUS ${USER_INTERFACE})

if(NOT USER_INTERFACE)
    set_target_properties(detector exceptions bailerror
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/uiless/Debug"
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/uiless/Debug"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/uiless/Debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/uiless/Release"
        LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/uiless/Release"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/uiless/Release"
    )
else()
    set_target_properties(detector exceptions bailerror
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/ui/Debug"
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/ui/Debug"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/ui/Debug"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/ui/Release"
        LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/ui/Release"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/ui/Release"
    )
    target_compile_definitions(detector PUBLIC USER_INTERFACE)
endif()

install(
    TARGETS detector
    LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/lib
    ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/lib
    RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin
    INCLUDES DESTINATION ${CMAKE_CURRENT_LIST_DIR}/include/detector
    EXPORT detector
)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT detector)