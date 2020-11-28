#!/usr/bin/env bash

path=$1

count_dirs=$(find $path -type d | wc -l | xargs)
echo "There were "$count_dirs "directories."

count_files=$(find $path -type f | wc -l | xargs)
echo "There were "$count_files " regular files."