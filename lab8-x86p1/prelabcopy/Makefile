CXX = clang++ -m64

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g

OFILES = mathfun.o mathlib.o

.SUFFIXES: .o .cpp

.SUFFIXES: .o .s

mathfun: 	$(OFILES)
		$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~
