OBJ = main.o bst.o
TEST_OBJ = bst_test.o bst_test_main.o
CC = g++
CFLAGS = -g -Wall -I.

all : compile test clean

test: bst_test.o bst_test_main.o
	$(CC) $(TEST_OBJ) $(CFLAGS) -o tests

compile: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

bst.o : bst.cpp
	$(CC) $(CFLAGS) -c bst.cpp

# so it doesn't conflict with a file named clean
.PHONY: clean

clean : 
	rm -f $(OBJ) $(TEST_OBJ)
