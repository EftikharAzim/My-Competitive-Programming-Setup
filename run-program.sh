#!/bin/bash

cpp_file=$1
input_file=$2

# Check if the input_file exists and is empty
if [ ! -s "$input_file" ]; then
    # If the file is empty, get the contents from the clipboard and write it to the input file
    pbpaste > "$input_file"
fi

# Compile and run the C++ program
g++-15 -std=c++20 -O2 -Wall "$cpp_file" -o "${cpp_file%.cpp}" && ./${cpp_file%.cpp} < "$input_file"