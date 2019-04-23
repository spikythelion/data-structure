#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: Makefile
#Date: 12/4/18

CXX = clang++
CXXFLAGS = -Wall

.SUFFIXES: .o .cpp

a.out: 	travelling.o middleearth.o
	$(CXX) travelling.o middleearth.o
	doxygen

clean:
	rm -f *.o *~ a.out

travelling.o: travelling.cpp middleearth.h
middleearth.o: middleearth.cpp middleearth.h

