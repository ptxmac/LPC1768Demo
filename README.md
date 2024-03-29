# ArmDemo

How to do some low-level arm development using the Blueboard LPC1768-H

## Compiler

[Compile your own](http://www.arklyffe.com/main/2010/08/29/arm-gcc-toolchain-build/ )


Or use this [binary](https://sourcery.mentor.com/GNUToolchain/package9740/public/arm-none-eabi/arm-2011.09-69-arm-none-eabi-i686-pc-linux-gnu.tar.bz2) version.
And install it somewhere

	tar -zjxf arm-2011.09-69-arm-none-eabi-i686-pc-linux-gnu.tar.bz2
	export PATH=$PATH:/path/tp/arm-2011.09/bin

For more information see [vsdev][vsdev]

## OpenSuse:

Needed packages:

    sudo zypper install libftdi1-devel cmake

Needed patterns:

	sudo zypper install -t pattern devel_C_C++


## OpenOCD:

OpenOCD is a tool for using JTAG. It handles flash and debugging

### Install

	http://downloads.sourceforge.net/project/openocd/openocd/0.6.1/openocd-0.6.1.tar.bz2
	tar -vjxf openocd-0.6.1.tar.bz2
	cd openocd-0.6.1/
	./configure --enable-ft2232_libftdi
	make
	sudo make install

Set permissions for usb device:
create new file: `/etc/udev/rules.d/40-ngx.rules`

with contents:

	ATTRS{idVendor}=="0403",ATTRS{idProduct}=="6010",MODE="0666",GROUP="users"


## Bootloader

upload bootloader.bin

	./upload-openocd.sh bootloader.bin

second file starts at 0x2000

## Blink sample

Create cm3_checksum tool by running `./prepare.sh`

### Compile

    cd Blink

#### Bare Metal version

    ./make.sh

#### Bootloader version

     ./make.sh -DUSE_BOOTLOADER=1

### Upload

#### Bare Metal

Start openocd daemon in another terminal: `openocd -f openocd.cfg` (start in
root dir)
Then upload
      
      ./upload-openocd.sh Blink/build/blink.bin

#### Bootloader version

     ./upload-bootloader.sh Blink/build/blink.bin

## Debugging

Make sure openocd is running.

	arm-none-eabi-gdb ./build/blink.elf
	(gdb) target remote localhost:3333
	
gdb will think the target is paused, but it's actually running, so start by continuing the target:
	
	(gdb) continue

Now you can break the target with Ctrl-C, and use gdb as normal


To expand macros/defines, use "-g3"

### Eclipse

GDB hardware debug.

Launcher: Standard GDB Hardware Debugging Launcher

Set GDB command to arm-none-eabi-gdb

Remote TCP/IP localhost:3333 

Startup command: monitor reset halt

### Other

To use malloc/free from newlib, implement `sbrk`.



[vsdev]: http://dev.frozeneskimo.com/notes/cortex_cmsis/
