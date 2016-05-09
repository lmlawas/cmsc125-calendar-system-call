# extract ics-os-master.zip
# also check https://github.com/srg-ics-uplb/ics-os

# install dependencies
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install nasm
sudo apt-get install qemu
sudo apt-get install tcc
sudo apt-get install git

sudo su	# switch to root user
cd ics-os
cd kernel
cp Makefile.Ubuntu_14.04_x86_64 Makefile # copy to make 32 bit ICS-OS compatible with 64 bit Linux
cd ..
cd contrib
cd hello
cp Makefile.Ubuntu_14.04_x86_64 Makefile # copy to make 32 bit ICS-OS compatible with 64 bit Linux

# install hello.exe to app folder
make clean
make
make install

cd ../..
make clean
make
make install

# run ICS OS
qemu-system-i386 -fda ics-os-floppy.img
