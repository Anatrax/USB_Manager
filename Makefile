#----------------------------------------#
# Makefile for USB_Manager Linux version
# Samuel D. Villegas
#----------------------------------------#

all: src/main.cpp
	g++ -std=c++11 src/main.cpp -I src/ -o bin/usb `pkg-config --libs --cflags libusb-1.0`

#----------------------------------------#

clean:
	rm bin/usb

#----------------------------------------#
