CC = g++
CFLAGS = -Wall -ggdb3 -std=c++11

HW06: Homework07.o BinomialTreeModel.o Option08.o
	$(CC) $(CFLAGS) -o Homework07 Homework07.o BinomialTreeModel.o Option08.o

Homework07.o: Homework07.cpp BinomialTreeModel.h Option08.h BinLattice02.h
	$(CC) $(CFLAGS) -c Homework07.cpp

Option08.o: Option08.cpp Option08.h BinomialTreeModel.h BinLattice02.h
	$(CC) $(CFLAGS) -c Option08.cpp

BinomialTreeModel.o: BinomialTreeModel.cpp BinomialTreeModel.h
	$(CC) $(CFLAGS) -c BinomialTreeModel.cpp

clean:
	rm -rf HW07 *.o
