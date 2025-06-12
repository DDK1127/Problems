CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: main

main: main.o RBTree.o
	$(CXX) $(CXXFLAGS) -o main main.o RBTree.o

main.o: main.cpp RBTree.h
	$(CXX) $(CXXFLAGS) -c main.cpp

RBTree.o: RBTree.cpp RBTree.h
	$(CXX) $(CXXFLAGS) -c RBTree.cpp

clean:
	rm -f *.o main
