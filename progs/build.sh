#!/bin/bash
# to be run as ". progs/build.sh"; without the period, the env variable will not be set

. progs/add_env.sh
progs/cmake_clean.sh

cmake -DCMAKE_BUILD_TYPE=Debug . # or Release
make clean && make
