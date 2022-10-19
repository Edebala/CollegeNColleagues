all: build

build: 
	g++ -Lsrc test.cpp -o Program -Iinclude
 
clear:
	rm Program
