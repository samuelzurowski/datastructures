# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Makefile for Unix & Linux Systems #
# using a GNU C++ compiler #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# compiler flags
# -g --Enable debugging
# -Wall --Turn on all warnings
# -D_USE_FIXED_PROTOTYPES_
# --Force the compiler to use the correct headers

## Sorry my first time using makefile.
CC=g++
CFLAGS=-std=c++11 -g
INCLUDE = -I./tools -I./controller -I./moves -I./manager -I./types -I./people

default: main
#Link command
main: main.o ./controller/Runner.o ./moves/AttackOne.o ./moves/AttackTwo.o ./moves/Heal.o ./people/Actor.o ./manager/MoveManager.o
	$(CC) $(CFLAGS) $(INCLUDE) main.o ./controller/Runner.o ./moves/AttackOne.o ./moves/AttackTwo.o ./moves/Heal.o ./people/Actor.o ./manager/MoveManager.o -o Main

#Compilation commands:
main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c main.cpp -o main.o

#Runner
./controller/Runner.o: ./controller/Runner.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c ./controller/Runner.cpp -o ./controller/Runner.o

#ONE
./moves/AttackOne.o: ./moves/AttackOne.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c ./moves/AttackOne.cpp -o ./moves/AttackOne.o

#TWO
./moves/AttackTwo.o: ./moves/AttackTwo.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c ./moves/AttackTwo.cpp -o ./moves/AttackTwo.o

#HEAL
./moves/Heal.o: ./moves/Heal.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c ./moves/Heal.cpp -o ./moves/Heal.o

#Actor
./people/Actor.o: ./people/Actor.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c ./people/Actor.cpp -o ./people/Actor.o

#manager
./manager/MoveManager.o: ./manager/MoveManager.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c ./manager/MoveManager.cpp -o ./manager/MoveManager.o

#make clean
clean:
	rm -f *.o
	rm -f ./controller/*.o
	rm -f ./moves/*.o
	rm -f ./people/*.o
	rm -f ./manager/*.o

