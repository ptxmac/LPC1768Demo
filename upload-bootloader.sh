#!/bin/sh
FILE="$1"
UNAME=`uname`

if [ ! $# == 1 ]; then
    echo "Usage: $0 <binary>"
    exit 1
fi

if [ -f $FILE ]; then
    if [ $UNAME == "Darwin" ]; then
        cp $FILE "/Volumes/CRP DISABLE/firmware.bin"
        diskutil eject "/Volumes/CRP DISABLE"
    elif [ $UNAME == "Linux" ]; then
        echo "Linux"
    fi
else
    echo "File not found!"
    exit 1

fi
