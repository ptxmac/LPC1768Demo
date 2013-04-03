#!/bin/sh
FILE="$1"


if [ ! $# == 1 ]; then
    echo "Usage: $0 <binary>"
    exit 1
fi

if [ -f $FILE ]; then
    echo "flash write_image erase unlock $FILE 0x0" 
    cp build/libusbtest.bin "/Volumes/CRP DISABLE/firmware.bin"
    diskutil eject "/Volumes/CRP DISABLE"

else
    echo "File not found!"
    exit 1

fi
