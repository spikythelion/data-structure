#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: Makefile-pizza
#Date: 10/16/18X

CXX= clang++
CXXFLAGS= -Wall -o2

OFILES= BSTPathTest.o BinaryNode.o BinarySearchTree.o

.SUFFIXES: .o .cpp

bst: 	$(OFILES)
	$(CXX) $(OFILES) -o a.out
	@echo "BST is ready"

clean:
	-rm -f *.o *~ bst

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
