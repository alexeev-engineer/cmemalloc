CC=gcc
CC_FLAGS=-fPIC

SRC_DIR=src
BIN_DIR=bin

SOURCE=$(SRC_DIR)/main.c

OUT=$(BIN_DIR)/cmemalloc

build:
	$(CC) $(SOURCE) $(CC_FLAGS) -o $(OUT)
