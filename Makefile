all: build

build: 
	g++ -Lsrc main.cpp -o Program -Iinclude
 
clear:
	rm Program
