CC=clang                      # Using clang compiler
CFLAGS=-I. -Wall -g           # Compilation flags, including current directory for headers and enabling all warnings and debugging

# List of object files based on source files
OBJ = main.o

# Name of the executable file
EXECUTABLE=data_structures

# Default target when 'make' is executed without arguments
all: $(EXECUTABLE)

# Rule to create the executable, depending on the object files
$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Generic rule to create an object file from a source file
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

# Target to clean compiled files and executable
clean:
	rm -f $(OBJ) $(EXECUTABLE)

# Target to run the program
run:
	./$(EXECUTABLE)

.PHONY: all clean install run
