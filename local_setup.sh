#!/bin/bash

cd /tmp
mkdir -p IOLS
cd IOLS

# get cucumber-cpp headers
git clone https://github.com/cucumber/cucumber-cpp.git
cd cucumber-cpp
git pull
git submodule init
git submodule update
# execute necessary build steps to create missing include file(s)
cmake -E make_directory build
cmake -E chdir build cmake -DCUKE_ENABLE_EXAMPLES=on -DCMAKE_INSTALL_PREFIX=${prefix} ..
cd ..

# get gtest and gmock headers
git clone https://github.com/google/googletest.git
cd googletest
git pull
cd ..
