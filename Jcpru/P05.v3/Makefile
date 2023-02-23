CC = g++
CFLAGS = -std=c++14 -g -Wall
DEPS = set_class.h
OBJ = set_class.o main_set_class.o 

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main_set_class: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm main_set_class *.o
