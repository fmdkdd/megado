#!/bin/bash

# GLFW
pushd deps/glfw/
mkdir build
pushd build
cmake -DBUILD_SHARED_LIBS=ON ../
cmake --build .
popd
popd

# GLEW
pushd deps/glew/
pushd auto
nmake
popd
pushd build
cmake ./cmake
cmake --build .
popd
popd

# cimgui
pushd deps/cimgui/cimgui
nmake
popd

# json-c
pushd deps/json-c
sh autogen.sh
./configure --prefix=$PWD
nmake
nmake install
popd
