CC=clang
CFLAGS=-I. -Wall -g

OBJ = main.o linked_list/linked_list.o # stack/stack.o queue/queue.o binary_tree/binary_tree.o

EXECUTABLE=data_structures

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXECUTABLE)

run:
	./$(EXECUTABLE)
