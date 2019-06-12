CC=g++
CFLAGS=-std=c++11

default: templates

templates: Templates.o
	$(CC) $(CFLAGS) -o program Templates.o

Templates.o: Templates.cpp 
	$(CC) -c $(CFLAGS) templates.cpp

CopyConstructor: CopyConstructor.o
	$(CC) $(CFLAGS) -o program CopyConstructor.o

CopyConstructor.o: CopyConstructor.cpp
	$(CC) -c $(CFLAGS) CopyConstructor.cpp

Polymorphism: Polymorphism.o
	$(CC) $(CFLAGS) -o program Polymorphism.o

Polymorphism.o: Polymorphism.cpp
	$(CC) -c $(CFLAGS) Polymorphism.cpp

RangeBased: RangeBased.o
	$(CC) $(CFLAGS) -o program RangeBased.o

RangeBased.o: RangeBased.cpp
	$(CC) -c $(CFLAGS) RangeBased.cpp

CopyList: CopyList.o
	$(CC) $(CFLAGS) -o program CopyList.o

CopyList.o: CopyList.cpp
	$(CC) -c $(CFLAGS) CopyList.cpp

clean: 
	rm -rf ./*.o 
	rm -rf ./program
