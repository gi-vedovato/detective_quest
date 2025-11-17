# Makefile for Detective Quest

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = detective_quest
OBJS = main.o binary_tree.o bst.o hash_table.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile main.c
main.o: main.c binary_tree.h bst.h hash_table.h
	$(CC) $(CFLAGS) -c main.c

# Compile binary_tree.c
binary_tree.o: binary_tree.c binary_tree.h
	$(CC) $(CFLAGS) -c binary_tree.c

# Compile bst.c
bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c

# Compile hash_table.c
hash_table.o: hash_table.c hash_table.h
	$(CC) $(CFLAGS) -c hash_table.c

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
