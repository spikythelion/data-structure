CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f macho64 -g

OFILES = mergeSort.o testMergeSort.o

.SUFFIXES: .o .cpp

.SUFFIXES: .o .s

mathfun: 	$(OFILES)
		$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~
