cmake_minimum_required (VERSION 2.8.11)
project(CStuctures_tests)

include(CMakePrintHelpers)

file(GLOB all_src 
    RELATIVE ${PROJECT_SOURCE_DIR}
    "${PROJECT_SOURCE_DIR}/*.c"
)

set(TEMP_OUTPUT_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# add_executable(tests ${all_src})

set(LIBS ${LIBS} ${CMAKE_SOURCE_DIR}/bin/Debug/liblmbStruct.a)

include_directories(${CMAKE_SOURCE_DIR}/libs/check/src)
include_directories(${CMAKE_SOURCE_DIR}/libs/check/)

foreach( tests ${all_src} )
    string( REPLACE ".c" "" testname ${tests} )
    string( REPLACE "./" "" testname ${testname} )

    add_executable( ${testname} ${tests} )
    cmake_print_variables(testname)
    target_link_libraries( ${testname} ${LIBS} )
    add_test( ${testname} ${testname} )
endforeach( tests ${all_src} )

# set(LIBS ${LIBS} ${CMAKE_SOURCE_DIR}/bin/Debug/liblmain.a)
# target_link_libraries(tests ${LIBS})

# add_test(tests tests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TEMP_OUTPUT_DIR})
