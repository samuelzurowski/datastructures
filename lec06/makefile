CC=g++
CFLAGS=-std=c++11 -g

default: Factorial

BinarySearch: BinarySearch.o
	$(CC) $(CFLAGS) -o program BinarySearch.o

BinarySearch.o: BinarySearch.cpp 
	$(CC) -c $(CFLAGS) BinarySearch.cpp

Factorial: Factorial.o
	$(CC) $(CFLAGS) -o program Factorial.o

Factorial.o: Factorial.cpp
	$(CC) -c $(CFLAGS) Factorial.cpp

FindInList: FindInList.o
	$(CC) $(CFLAGS) -o program FindInList.o

FindInList.o: FindInList.cpp
	$(CC) -c $(CFLAGS) FindInList.cpp

Quicksort: Quicksort.o
	$(CC) $(CFLAGS) -o program Quicksort.o

Quicksort.o: Quicksort.cpp
	$(CC) -c $(CFLAGS) Quicksort.cpp

Fibonacci: Fibonacci.o
	$(CC) $(CFLAGS) -o program Fibonacci.o

Fibonacci.o: Fibonacci.cpp
	$(CC) -c $(CFLAGS) Fibonacci.cpp

PrintList: PrintList.o
	$(CC) $(CFLAGS) -o program PrintList.o

PrintList.o: PrintList.cpp
	$(CC) -c $(CFLAGS) PrintList.cpp

clean: 
	rm -rf ./*.o 
	rm -rf ./program
