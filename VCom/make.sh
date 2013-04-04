#!/bin/sh
mkdir -p build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../arm.cmake .. $@
make
