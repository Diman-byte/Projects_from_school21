#!/bin/bash

cd ..
dir=$1
str=$2
newstr=$3


if [[ -f $dir && $str != "" && $(grep $2 $1) ]]; then
	sed -i '' "s/$str/$newstr/g" $dir
else
	exit
fi

size=$(stat -f %z $dir)
date1=$(date +"%F")
time=$(date +"%R")
shasum1=($(shasum -a 256 $dir))

echo "$dir - $size - $date1 - $time - $shasum1 - sha256" | tee -a src/files.log >/dev/null

