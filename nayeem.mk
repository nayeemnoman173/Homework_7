# Compiler

CC = g++

# Flags to the compiler

CFLAGS = -Wall

nayeem: nayeem.cpp
	${CC} ${CFLAGS} nayeem.cpp earthquake.cpp station.cpp -o nayeem

clean:
	rm -rf nayeem 

