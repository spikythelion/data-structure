#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: Makefile
#Date: 11/6/18

CXX = clang++ -m64

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g

OFILES = mergeSort.o testMergeSort.o

.SUFFIXES: .o .cpp

.SUFFIXES: .o .s

mathfun: 	$(OFILES)
		$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~
