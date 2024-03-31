cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(PhysProperties)

include(${CMAKE_CURRENT_SOURCE_DIR}/grammar/CMakeLists.txt)

file(GLOB sources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

execute_process(COMMAND sh -c "ls $ENV{HOME} | grep -E 'boost_[0-9]+_[0-9]+_[0-9]' | head -n 1" OUTPUT_VARIABLE BOOST_VERSION)
string(REPLACE "\n" "" BOOST_VERSION ${BOOST_VERSION})

message(STATUS ${ANTLR_OUTPUT_DIRS})

foreach(dir ${ANTLR_OUTPUT_DIRS})
    message(STATUS ${dir})
    include_directories(${dir})
endforeach()
include_directories(${ANTLR_OUTPUT_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/include $ENV{HOME}/${BOOST_VERSION})

add_library(
    PhysProperties STATIC
    ${ANTLR_Parserules_CXX_OUTPUTS}
    ${sources}
)

target_link_libraries(PhysProperties antlr4_static /home/oster/${BOOST_VERSION}/stage/lib/*.lib)
if(MSVC)
    target_compile_options(antlr4_static PRIVATE /W0)
endif()

install(
    TARGETS PhysProperties
    DESTINATION bin
    EXPORT PhysProperties
)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT PhysProperties)