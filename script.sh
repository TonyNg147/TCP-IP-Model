#!/bin/bash
cd build
echo $PWD
cmake ..
make
exec ./main
