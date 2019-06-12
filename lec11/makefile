CC=g++
CFLAGS=-std=c++11 -g

default: Sorts

Sorts: Sorts.o
	$(CC) $(CFLAGS) -o program Sorts.o

Sorts.o: Sorts.cpp 
	$(CC) -c $(CFLAGS) Sorts.cpp

clean: 
	rm -rf ./*.o 
	rm -rf ./program
