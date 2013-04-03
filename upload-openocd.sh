#!/bin/sh

FILE="$1"


if [ ! $# == 1 ]; then
    echo "Usage: $0 <binary>"
    exit 1
fi

if [ -f $FILE ]; then
    echo "halt; flash write_image erase unlock $FILE 0x0; reset run" | nc localhost 4444
else
    echo "File not found!"
    exit 1

fi
