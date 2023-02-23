CC = g++
CFLAGS = -std=c++14 -g -Wall
DEPS = set_calculator.h
OBJ = set_calculator.o main_set_calculator.o 

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fibonacci_words: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm main_set_calculator *.o
