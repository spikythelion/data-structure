#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: Makefile
#Date: 11/30/18

CXX= clang++
CC= clang
CXXFLAGS= -Wall

OFILES1= HuffmanNode.o huffmanenc.o AVLTree.o heap.o

.SUFFIXES: 	.o .cpp
		.o .c

all: encoder decoder a.out

encoder:	$(OFILES1)
		$(CXX) $(OFILES1) -o encoder

OFILES2 = huffmandec.o HuffmanTree.o HuffmanNoded.o

decoder: 	$(OFILES2)
		$(CXX) $(OFILES2) -o decoder

a.out:	linkedlist.o
	$(CC) linkedlist.o

clean:
	-rm -f *.o *~ a.out

huffmandec.o: huffmandec.cpp HuffmanTree.h
HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
HuffmanNoded.o: HuffmanNoded.cpp HuffmanNoded.h

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
AVLTree: AVLTree.cpp HuffmanNode.h
heap.o: heap.cpp HuffmanNode.h
huffmanenc.o: huffmanenc.cpp AVLTree.h heap.h

linklist.o: linkedlist.c
