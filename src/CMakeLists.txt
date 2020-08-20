cmake_minimum_required (VERSION 2.8.11)
project(CStructures_src)

file(GLOB all_src
    "./*.c"
)

add_executable(main ${all_src})
add_library(lmbStruct STATIC ${all_src})
target_link_libraries(main ${LIBS})
