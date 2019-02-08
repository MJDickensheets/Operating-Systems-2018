CXX = g++
CXXFLAGS = -Wall -g 

main: main.o Job.o
	$(CXX) $(CXXFLAGS) -o main main.o Job.o

main.o: main.cpp Job.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Job.o: Job.h
