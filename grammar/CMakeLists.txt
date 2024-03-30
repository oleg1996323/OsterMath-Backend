cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(Electrolisys)

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

#antlr runtime installation
message(STATUS "System name: ${CMAKE_SYSTEM_NAME}")
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/grammar/antlr-4.13.1-complete.jar OR NOT EXISTS $ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4_runtime)
	file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/grammar/antlr-4.13.1-complete.jar)
	execute_process(COMMAND curl -Lo ${CMAKE_CURRENT_SOURCE_DIR}/grammar/antlr-4.13.1-complete.jar https://www.antlr.org/download/antlr-4.13.1-complete.jar	RESULT_VARIABLE CURL_RESULT)
	if(CURL_RESULT)
	    message(FATAL_ERROR "Error loading '${CMAKE_CURRENT_SOURCE_DIR}/grammar/antlr-4.13.1-complete.jar'. Process interrupted.")
	else()
	    message(STATUS "Loading '${CMAKE_CURRENT_SOURCE_DIR}/grammar/antlr-4.13.1-complete.jar' finished.")
	endif()
    if(NOT EXISTS $ENV{HOME}/ANTLR4/${PROJECT_NAME})
        make_directory($ENV{HOME}/ANTLR4/${PROJECT_NAME})
    endif()
	execute_process(COMMAND curl -Lo $ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4-cpp-runtime-4.13.1-source.zip https://www.antlr.org/download/antlr4-cpp-runtime-4.13.1-source.zip	RESULT_VARIABLE CURL_RESULT)
	if(CURL_RESULT)
	    message(FATAL_ERROR "Error loading '$ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4-cpp-runtime-4.13.1-source.zip'. Process interrupted.")
	else()
	    message(STATUS "Loading '$ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4-cpp-runtime-4.13.1-source.zip' finished.")
	endif()
	message(STATUS "Распаковка архива antlr4-cpp-runtime-4.13.1-source.zip в " $ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4_runtime)
	if(NOT EXISTS $ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4_runtime)
		make_directory($ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4_runtime)
	endif()
	execute_process(COMMAND unzip $ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4-cpp-runtime-4.13.1-source.zip -d $ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4_runtime RESULT_VARIABLE UNZIP_RESULT)
	if(UNZIP_RESULT)
	    message(FATAL_ERROR "Error unzipping '$ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4-cpp-runtime-4.13.1-source.zip'. Process interrupted.")
	else()
	    message(STATUS "Unzipping '$ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4-cpp-runtime-4.13.1-source.zip' done.")
	    message(STATUS "Removing '$ENV{HOME}/ANTLR4/${PROJECT_NAME}/grammar/antlr4-cpp-runtime-4.13.1-source.zip'...")
	    execute_process(COMMAND rm $ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4-cpp-runtime-4.13.1-source.zip)
	    message(STATUS "Removing '$ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4-cpp-runtime-4.13.1-source.zip' finished")
	endif()
	message(STATUS "ANTLR4 installation SUCCESS")
else()
	message(STATUS "ANTLR4 already installed")
endif()

set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/grammar/antlr-4.13.1-complete.jar)

include(${CMAKE_CURRENT_LIST_DIR}/FindANTLR.cmake)

add_definitions(
    -DANTLR4CPP_STATIC
    -D_SILENCE_ALL_CXX20_DEPRECATION_WARNINGS
)

set(WITH_STATIC_CRT OFF CACHE BOOL "Visual C++ static CRT for ANTLR" FORCE)

set(PROJECT_RUNTIME_ANTLR $ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4_runtime)

# Создаем цель сборки для внешней директории
add_custom_target(ExternalDirectory
    COMMAND ${CMAKE_COMMAND} -E echo "Building external directory"
    WORKING_DIRECTORY ${PROJECT_RUNTIME_ANTLR}
)
make_directory($ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4_runtime/src)

antlr_target(PROJECT_NAME bound_coefs.g4 regions.g4 LEXER PARSER LISTENER)
string(CONCAT ANTLR_OUTPUT_DIR_GENERATED "ANTLR_" "${PROJECT_NAME}" "_OUTPUT_DIR")

message(STATUS ${ANTLR4_INCLUDE_DIRS} "\n" ${ANTLR_OUTPUT_DIR_GENERATED})

include_directories(
    ${ANTLR4_INCLUDE_DIRS}
    ${ANTLR_OUTPUT_DIR_GENERATED}
    $ENV{HOME}/ANTLR4/${PROJECT_NAME}/antlr4_runtime/src
)
