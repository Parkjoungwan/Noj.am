#!/bin/bash

echo -e "\033[0;32mMake new One...\033[0m"

num=$1

# make new dir
mkdir $num
 
# cd dir
cd $num

# cp sample
cp ../sample.cpp $num.cpp

