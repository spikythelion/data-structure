#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: Makefile
#Date: 12/3/18

CXX= clang++
CXXFLAGS= -Wall

.SUFFIXES: .o .cpp

all: 	a.out Doxygen

a.out:	topological.o
	$(CXX) topological.o

Doxygen: doc/
	doxygen

clean:
	-rm -f *.o *~ a.out

topological.o: topological.cpp
doc/: Doxyfile
