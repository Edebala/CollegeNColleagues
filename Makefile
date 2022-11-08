CPPFLAGS =-Wall -Iinclude
FILES = main.cpp
SOURCES = $(FILES:%.cpp=$(SRC_PATH)/%.cpp)
SRC_PATH=src

OUT_PATH=bin
VPATH=${SRC_PATH}
CC=g++
CFLAGS=-Wall -lSDL2 -lSDL2_image

all: build

build: 
	${CC} ${CFLAGS} -I${SRC_PATH} ${SOURCES} -o Program -lSDL2 -lSDL2_image
 
clear:
	rm Program
