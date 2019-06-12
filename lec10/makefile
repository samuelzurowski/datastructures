CC=g++
CFLAGS=-std=c++11 -g

default: Set

Set: Set.o
	$(CC) $(CFLAGS) -o program Set.o

Set.o: Set.cpp 
	$(CC) -c $(CFLAGS) Set.cpp

Map: Map.o
	$(CC) $(CFLAGS) -o program Map.o

Map.o: Map.cpp 
	$(CC) -c $(CFLAGS) Map.cpp

BitSet: BitSet.o
	$(CC) $(CFLAGS) -o program BitSet.o

BitSet.o: BitSet.cpp 
	$(CC) -c $(CFLAGS) BitSet.cpp

clean: 
	rm -rf ./*.o 
	rm -rf ./program
