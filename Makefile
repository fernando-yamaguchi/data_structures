# Compiler and flags
CC = gcc

ifeq ($(OS),Windows_NT)
    CC = mingw32-gcc
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        CC = clang
    endif
endif

CFLAGS = -Wall -g -Iinclude

# Project directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# Target executable name
TARGET = $(BIN_DIR)/data_structures

# Source files and objects
SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default make target
all: $(TARGET)

# Link objects into the binary
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@

# Compile C sources into objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: 
	@echo "Running the program..."
	@./$(TARGET)

# Clean up the build
clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: all clean run
