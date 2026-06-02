CC = g++
CFLAGS = -Wall -ggdb3 -std=c++11

Main02: Function02.o Main02.o
	$(CC) $(CFLAGS) -o Main02 Function02.o Main02.o

Main02.o: Function02.h NonLinearSolver02.h Main02.cpp
	$(CC) $(CFLAGS) -c Main02.cpp

Function02.o: Function02.h Function02.cpp
	$(CC) $(CFLAGS) -c Function02.cpp

Main02: Function02.o NonLinearSolver02.o Main02.o
	$(CC) $(CFLAGS) -o Main02 Function02.o NonLinearSolver02.o Main02.o

NonLinearSolver02.o: NonLinearSolver02.h NonLinearSolver02.cpp
	$(CC) $(CFLAGS) -c NonLinearSolver02.cpp


clean:
	rm -rf Main02 *.o
