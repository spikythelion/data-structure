#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: Makefile
#Date: 11/27/18

CXX = clang++
CXXFLAGS = -Wall

OFILES = huffmandec.o HuffmanTree.o HuffmanNode.o

.SUFFIXES: .o .cpp

a.out: 	$(OFILES)
	$(CXX) $(OFILES)

clean:
	-rm -f *.o *~ a.out

huffmandec.o: huffmandec.cpp HuffmanTree.h
HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
