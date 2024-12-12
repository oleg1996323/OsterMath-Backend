cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(ostermath_be)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

if(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "Not defined config")
endif()

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

set(USER_INTERFACE ON)

set(OSTERMATH_BE_DIR ${CMAKE_CURRENT_LIST_DIR})

include(${CMAKE_CURRENT_LIST_DIR}/grammar/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/detector/CMakeLists.txt)

include_directories(${CMAKE_CURRENT_LIST_DIR})

file(GLOB_RECURSE ostermath_be_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/nodes/**.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)

file(GLOB_RECURSE head_interactor_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/head_interactor/**.cpp
)

set(OSTERMATH_BE_INCLUDE_DIR
                            ${CMAKE_CURRENT_LIST_DIR}/include
                            ${CMAKE_CURRENT_LIST_DIR}/include/core
                            ${CMAKE_CURRENT_LIST_DIR}/include/nodes
                            ${CMAKE_CURRENT_LIST_DIR}/include/nodes/types
                            ${CMAKE_CURRENT_LIST_DIR}/include/head_interactor)
set(OSTERMATH_BE_INCLUDE_DIR_PRIVATE 
                            ${CMAKE_CURRENT_LIST_DIR}/include/events_errors)
set(OSTERMATH_BE_LIBRARY_DIR ${CMAKE_CURRENT_LIST_DIR}/lib)

file(GLOB_RECURSE core_sources
    ${CMAKE_CURRENT_LIST_DIR}/src/core/**.cpp
)

add_library(
    core STATIC
    ${core_sources}
)

target_include_directories(core
                    PRIVATE
                        ${CMAKE_CURRENT_LIST_DIR}/include/core)

add_library(
    bailerror INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/events_errors/bailerror.cpp
)
target_include_directories(bailerror
                    INTERFACE
                        ${CMAKE_CURRENT_LIST_DIR}/include/events_errors)

set_target_properties(bailerror PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(
    abstract_event INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/events_errors/abstract_event.cpp
)

#TYPE is a build choice between shared and static library
get_target_property(abstract_event_type abstract_event TYPE)
if(${abstract_event_type} STREQUAL SHARED_LIBRARY)
    message(STATUS ${abstract_event_type})
    set_target_properties(abstract_event PROPERTIES POSITION_INDEPENDENT_CODE ON)
endif()

target_include_directories(abstract_event
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/include/events_errors
    )

add_library(
    warnings STATIC
    ${CMAKE_CURRENT_LIST_DIR}/src/events_errors/warning.cpp
)

target_link_libraries(warnings PUBLIC abstract_event)

get_target_property(warnings_type warnings TYPE)
if(${warnings_type} STREQUAL SHARED_LIBRARY)
    message(STATUS ${warnings_type})
    set_target_properties(warnings PROPERTIES POSITION_INDEPENDENT_CODE ON)
endif()

target_include_directories(warnings
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include/events_errors)

add_library(
    exceptions STATIC
    ${CMAKE_CURRENT_LIST_DIR}/src/events_errors/exception.cpp
)

target_link_libraries(exceptions INTERFACE abstract_event)

get_target_property(exception_type exceptions TYPE)

if(${exception_type} STREQUAL SHARED_LIBRARY)
    message(STATUS ${exception_type})
    set_target_properties(exceptions PROPERTIES POSITION_INDEPENDENT_CODE ON)
endif()

target_include_directories(exceptions
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include/events_errors)

add_library(
    head_interactor STATIC
    ${head_interactor_SOURCES}
    ${ANTLR_head_interactor_CXX_OUTPUTS}
    ${ANTLR_main_lexics_CXX_OUTPUTS}
)
        
target_link_libraries(head_interactor PUBLIC Boost::boost exceptions warnings PRIVATE antlr4_static)
target_compile_definitions(head_interactor PUBLIC $<$<CONFIG:Debug>:DEBUG>)
        
target_include_directories(head_interactor
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include/head_interactor
        ${CMAKE_CURRENT_LIST_DIR}/include/events_errors
        ${CMAKE_CURRENT_LIST_DIR}/include
    PRIVATE
        ${OSTERMATH_BE_INCLUDE_DIR}
        ${ANTLR_head_interactor_OUTPUT_DIR}
        ${ANTLR_main_lexics_OUTPUT_DIR}
        ${ANTLR_GENERATED_FILES_DIR})

set_target_properties(head_interactor
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/Debug"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/shared/Debug"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/Debug"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/Release"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/shared/Release"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/Release"
)

add_library(
    ostermath_be STATIC
    ${ostermath_be_SOURCES}
)

target_link_libraries(ostermath_be PUBLIC head_interactor PRIVATE core)
target_compile_definitions(ostermath_be PUBLIC $<$<CONFIG:Debug>:DEBUG>)

target_include_directories(ostermath_be
                    PUBLIC 
                        ${OSTERMATH_BE_INCLUDE_DIR}
                        ${ANTLR_main_lexics_OUTPUT_DIR}
                    PRIVATE
                        ${OSTERMATH_BE_INCLUDE_DIR_PRIVATE})

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT ostermath_be)

# file(GLOB_RECURSE detector_SOURCES
#     ${CMAKE_CURRENT_LIST_DIR}/src/detector/**.cpp
# )

set_target_properties(ostermath_be
        PROPERTIES
        POSITION_INDEPENDENT_CODE ON;
)

if(NOT USER_INTERFACE)
    set_target_properties(ostermath_be exceptions warnings core
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/Debug/uiless"
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/shared/Debug/uiless"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/Debug/uiless"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/Release/uiless"
        LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/shared/Release/uiless"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/Release/uiless"
    )
else()
    set_target_properties(ostermath_be exceptions warnings core
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/Debug/ui"
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/shared/Debug/ui"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/Debug/ui"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/Release/ui"
        LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/shared/Release/ui"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/Release/ui"
    )
    target_compile_definitions(ostermath_be PUBLIC USER_INTERFACE)
endif()

install(
    TARGETS ostermath_be
    LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/shared
    ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/lib
    RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin
    INCLUDES DESTINATION ${CMAKE_CURRENT_LIST_DIR}/include
    EXPORT ostermath_be
)

file(GLOB_RECURSE test_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/test/**.cpp
)

find_package(GTest CONFIG REQUIRED)

enable_testing()

include(GoogleTest)
add_executable(nodes_test ${test_SOURCE})

target_link_libraries(nodes_test PUBLIC GTest::gtest ostermath_be detector head_interactor exceptions warnings)
target_include_directories(nodes_test INTERFACE ${OSTERMATH_BE_INCLUDE_DIR} ${DETECTOR_INCLUDE_DIR})
target_compile_definitions(nodes_test PUBLIC $<$<CONFIG:Debug>:DEBUG>)

set_target_properties(nodes_test
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/shared"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin"
)

# gtest_discover_tests(nodes_test)
#add_test(NAME "Nodes" COMMAND nodes_test)