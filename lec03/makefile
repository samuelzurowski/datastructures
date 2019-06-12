CC=g++
CFLAGS=-std=c++11

default: main

main: main.o Item.o OrderedList.o UnorderedList.o OrderedArrayList.o OrderedLinkedList.o UnorderedArrayList.o UnorderedLinkedList.o 
	$(CC) $(CFLAGS) -o program main.o OrderedArrayList.o OrderedLinkedList.o UnorderedArrayList.o UnorderedLinkedList.o OrderedList.o UnorderedList.o Item.o

main.o: main.cpp 
	$(CC) -c $(CFLAGS) main.cpp

OrderedArrayList.o: OrderedArrayList.cpp
	$(CC) -c $(CFLAGS) OrderedArrayList.cpp

OrderedLinkedList.o: OrderedLinkedList.cpp
	$(CC) -c $(CFLAGS) OrderedLinkedList.cpp

UnorderedArrayList.o: UnorderedArrayList.cpp
	$(CC) -c $(CFLAGS) UnorderedArrayList.cpp

UnorderedLinkedList.o: UnorderedLinkedList.cpp
	$(CC) -c $(CFLAGS) UnorderedLinkedList.cpp

OrderedList.o: OrderedList.cpp
	$(CC) -c $(CFLAGS) OrderedList.cpp

UnorderedList.o: UnorderedList.cpp
	$(CC) -c $(CFLAGS) UnorderedList.cpp

Item.o: Item.cpp
	$(CC) -c $(CFLAGS) Item.cpp

clean: 
	rm -rf ./*.o 
	rm -rf ./program
