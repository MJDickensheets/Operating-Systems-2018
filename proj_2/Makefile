CXX = g++
CXXFLAGS = -Wall -g

main: main.o dllist.o node.o
	$(CXX) $(CXXFLAGS) -pthread -o main main.o dllist.o node.o

main.o: main.cpp dllist.h
	$(CXX) $(CXXFLAGS) -c main.cpp

dllist.o: dllist.cpp node.h
	$(CXX) $(CXXFLAGS) -c dllist.cpp
	
node.o: node.h
