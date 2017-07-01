OBJ = main.o vector.o
CC = g++
CFLAGS = -w -I.

all : main clean

main : $(OBJ)
	$(CC) $(OBJ) -o main

# so it doesn't conflict with a file named clean
.PHONY: clean

clean : 
	rm *.o
