CC = g++
CFLAGS = -std=c++14 -g -Wall
DEPS = set_calculator.h
OBJ = set_calculator.o main_set_calculator.o 

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main_set_calculator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm main_set_calculator *.o
