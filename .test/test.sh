#!/bin/bash

# Testing v2 functions
V2_FILES=$(find ../utils -name 'v2*.c')
SRC_FILE=test_v2.c
INCLUDE_FILE=../include
gcc -I $INCLUDE_FILE $SRC_FILE $V2_FILES && ./a.out && rm a.out
