IDIR =./
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=./
LDIR =../lib

LIBS=-lm

_OBJ = sorted_vector_t.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: divide_conquer

$(ODIR)/sorted_vector_t.o: $(ODIR)/sorted_vector_t.cc  
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/main.o: $(ODIR)/main.cc $(IDIR)/sorted_vector_t.h
	$(CC) -c -o $@ $< $(CFLAGS)		

divide_conquer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~