APPLICATION_NAME=driver
CC=g++
CFLAGS=$(CC) -c -Wall -g

all: main.o lib.o turingMachine.o tape.o state.o transition.o
	$(CC) -o $(APPLICATION_NAME) main.o lib.o turingMachine.o tape.o state.o transition.o

main.o: main.cpp
	$(CFLAGS) main.cpp

lib.o: lib.cpp lib.hpp
	$(CFLAGS) lib.cpp lib.hpp

turingMachine.o: turingMachine.cpp turingMachine.hpp
	$(CFLAGS) turingMachine.cpp turingMachine.hpp

tape.o: tape.cpp tape.hpp
	$(CFLAGS) tape.hpp tape.cpp

state.o: state.cpp state.hpp
	$(CFLAGS) state.cpp state.hpp

transition.o: transition.cpp transition.hpp
	$(CFLAGS) transition.cpp transition.hpp

clean:
	rm -f *.o
	rm -f *.gch