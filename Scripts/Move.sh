#!/bin/bash

set -e -u

g++ -o CppIsYou CppIsYou.cpp -w -O0 -std=c++11

./CppIsYou "$@"

rm -r CppIsYou
