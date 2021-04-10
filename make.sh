#!/bin/bash

echo -e "\033[0;32mMake new One...\033[0m"

num=$1

# make new di
if test -d "./$num";then
	echo "dir already exist"
else
	mkdir $num
	# cd dir
	cd $num

	# cp sample
	if test -f "./$num.cpp";then
		echo "file already exist"
	else
		cp ../sample.cpp $num.cpp
		echo "make new file"
	fi
fi
