#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: Makefile
#Date: 10/22/18

CXX= clang++
CXXFLAGS= -Wall -O2

OFILES= wordPuzzle.o timer.o hashTable.o

.SUFFIXES: .o .cpp

a.out:	$(OFILES)
	$(CXX) $(OFILES)
	@echo "Word puzzle ready"

clean:
	-rm -f *.o *~ a.out

wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
