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
                ${ANTLR_GENERATED_FILES}/**.h
                ${ANTLR_GENERATED_FILES}/**.cpp)

#message(STATUS "${ANTLR_GENERATED_SOURCES}")

set(USER_INTERFACE ON)

add_library(
    bailerror STATIC
    ${ANTLR_Parserules_CXX_OUTPUTS}
    ${CMAKE_CURRENT_LIST_DIR}/src/exception/bailerror.cpp
)

target_include_directories(bailerror
                    PUBLIC
                        ${CMAKE_CURRENT_LIST_DIR}/include
                        ${CMAKE_CURRENT_LIST_DIR}/include/exception
                        ${ANTLR_Parserules_OUTPUT_DIR}
                        ${ANTLR_GENERATED_FILES})

add_library(
    exceptions STATIC
    ${ANTLR_Parserules_CXX_OUTPUTS}
    ${CMAKE_CURRENT_LIST_DIR}/src/exception/exception.cpp
)

set_target_properties(exceptions PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(exceptions
                    PUBLIC
                        ${CMAKE_CURRENT_LIST_DIR}/include
                        ${CMAKE_CURRENT_LIST_DIR}/include/exception
                        ${ANTLR_Parserules_OUTPUT_DIR}
                        ${ANTLR_GENERATED_FILES})

add_library(
    arithmetictree STATIC
    ${arithmetic_tree_SOURCES}
    ${ANTLR_Parserules_CXX_OUTPUTS}
    ${ANTLR_GENERATED_FILES}
)


set_target_properties(arithmetictree PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries(arithmetictree PUBLIC Boost::boost exceptions PRIVATE bailerror antlr4_static)
target_compile_definitions(arithmetictree PUBLIC $<$<CONFIG:Debug>:DEBUG>)
if(MSVC)
    target_compile_options(antlr4_static PUBLIC /W0)
endif()

target_include_directories(arithmetictree
                    PUBLIC 
                        ${CMAKE_CURRENT_LIST_DIR}/include
                        ${CMAKE_CURRENT_LIST_DIR}/include/types
                        ${ANTLR_Parserules_OUTPUT_DIR}

                    PRIVATE
                        ${CMAKE_CURRENT_LIST_DIR}/include/exception
                        ${ANTLR_GENERATED_FILES})

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