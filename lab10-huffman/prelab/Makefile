#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: Makefile
#Date: 11/26/18

CXX= clang++
CXXFLAGS= -Wall

OFILES= HuffmanNode.o huffmanenc.o AVLTree.o heap.o

.SUFFIXES: .o .cpp

a.out:	$(OFILES)
	$(CXX) $(OFILES)
	@echo "Huffman Encode Ready"

clean:
	-rm -f *.o *~ a.out

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
AVLTree: AVLTree.cpp HuffmanNode.h
heap.o: heap.cpp HuffmanNode.h
huffmanenc.o: huffmanenc.cpp AVLTree.h heap.h

