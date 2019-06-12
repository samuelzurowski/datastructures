CC=g++
CFLAGS=-std=c++11 -g

default: BST

BST: BST.o
	$(CC) $(CFLAGS) -o program BST.o

BST.o: BST.cpp 
	$(CC) -c $(CFLAGS) BST.cpp

clean: 
	rm -rf ./*.o 
	rm -rf ./program
