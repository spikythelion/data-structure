#Name: Tho Nguyen
#Email ID: tnn7yc
#File name: Makefile
#Date: 11/18/18

CXX	= clang++ -m64

CXXFLAGS	= -Wall -g

AS	= nasm

ASFLAGS	= -f elf64 -g

OFILES	= threexplusone.o threexinput.o timer.o

.SUFFIXES: .o .cpp

.SUFFIXES: .o .s

main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~
