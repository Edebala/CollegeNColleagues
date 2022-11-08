FILES = main.cpp
SOURCES = $(FILES:%.cpp=$(SRC_PATH)/%.cpp)
SRC_PATH=src
OUT_PATH=bin
VPATH=${SRC_PATH}
CC=g++
CFLAGS=-Wall

all: build

build: 
	${CC} ${CFLAGS} -I${SRC_PATH} ${SOURCES} -o Program
 
clear:
	rm Program
