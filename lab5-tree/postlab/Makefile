#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: Makefile-pizza
#Date: 10/16/18

CXX= clang++
CXXFLAGS= -Wall -o2

OFILES= AVLPathTest.o AVLNode.o AVLTree.o

.SUFFIXES: .o .cpp

avl: 	$(OFILES)
	$(CXX) $(OFILES) -o a.out
	@echo "AVL is ready"

clean:
	-rm -f *.o *~ bst

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
