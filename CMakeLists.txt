cmake_minimum_required (VERSION 2.8.11)
project(CStructures)

#[[TURN FOLLOWING OFF TO REMOVE VERBOSE MAKE]]
set(CMAKE_VERBOSE_MAKEFILE OFF)

include_directories(${CMAKE_SOURCE_DIR}/include)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "DEBUG")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Debug)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Debug)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Debug)

    set(GCC_COVERAGE_COMPILE_FLAGS "-g -Wall -O0")
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

    add_subdirectory(src)
    enable_testing()

    find_program(CTEST_MEMORYCHECK_COMMAND
        NAMES valgrind
        HINTS "${CMAKE_SOURCE_DIR}/progs/valgrind-3.16.0/coregrind/"
    )
    set( MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full" )

    find_library(CHECK
        NAMES libcheck check
        HINTS "${CMAKE_SOURCE_DIR}/libs/check/src/.libs"
    )

    INCLUDE(Dart)
    include_directories(${CMAKE_SOURCE_DIR}/check/src)
#    set(LIBS ${LIBS} ${CHECK} efence)
    add_subdirectory(tests)

elseif(CMAKE_BUILD_TYPE MATCHES Release)
    message(STATUS "RELEASE")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Release)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Release)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Release)

    add_subdirectory(src)

else(CMAKE_BUILD_TYPE MATCHES Debug)

    message(FATAL_ERROR "SPECIFY FLAG 'CMAKE_BUILD_TYPE'")

endif(CMAKE_BUILD_TYPE MATCHES Debug)


