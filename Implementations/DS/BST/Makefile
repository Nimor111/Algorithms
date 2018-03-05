OBJ = main.o bst.o
CC = g++
CFLAGS = -g -Wall -I.

all : compile clean

compile: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

bst.o : bst.cpp
	$(CC) $(CFLAGS) -c bst.cpp

# so it doesn't conflict with a file named clean
.PHONY: clean

clean : 
	rm -f $(OBJ)
