CC = g++
CFLAGS = -g -Wall
DEPS = nfa_simulation.h
OBJ = nfa_simulation.o main_nfa_simulation.o 

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main_nfa_simulation: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm main_nfa_simulation *.o
