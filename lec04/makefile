CC=g++
CFLAGS=-std=c++11

default: main

balance: balance.o
	$(CC) $(CFLAGS) -o balance balance.o

balance.o: balance.cpp
	$(CC) $(CFLAGS) -c balance.cpp

main: main.o Item.o Queue.o Stack.o QueueAr.o QueueLi.o StackAr.o StackLi.o 
	$(CC) $(CFLAGS) -o program main.o QueueAr.o QueueLi.o StackAr.o StackLi.o Queue.o Stack.o Item.o

main.o: main.cpp 
	$(CC) -c $(CFLAGS) main.cpp

QueueAr.o: QueueAr.cpp
	$(CC) -c $(CFLAGS) QueueAr.cpp

QueueLi.o: QueueLi.cpp
	$(CC) -c $(CFLAGS) QueueLi.cpp

StackAr.o: StackAr.cpp
	$(CC) -c $(CFLAGS) StackAr.cpp

StackLi.o: StackLi.cpp
	$(CC) -c $(CFLAGS) StackLi.cpp

Queue.o: Queue.cpp
	$(CC) -c $(CFLAGS) Queue.cpp

Stack.o: Stack.cpp
	$(CC) -c $(CFLAGS) Stack.cpp

Item.o: Item.cpp
	$(CC) -c $(CFLAGS) Item.cpp

clean: 
	rm -rf ./*.o 
	rm -rf ./program
