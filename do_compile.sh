#!/usr/bin/bash

cd build
cmake -B . -S ../src -DCMAKE_BUILD_TYPE=Debug
cmake --build . --parallel 6

./crow_web

#clear