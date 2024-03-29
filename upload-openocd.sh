#!/bin/sh

FILE="$1"


if [ ! $# == 1 ]; then
    echo "Usage: $0 <binary>"
    exit 1
fi

if [ -f $FILE ]; then
    if [[ $FILE =~ "elf" ]]; then
        echo "reset init; flash write_image erase unlock $FILE; reset run" | nc localhost 4444
    else
        echo "reset init; flash write_image erase unlock $FILE 0x0; verify_image $FILE; reset run" | nc localhost 4444
    fi

else
    echo "File not found!"
    exit 1

fi
