## This is a simple Makefile

# Define what compiler to use and the flags
CC=cc
CXX=CC
CCFLAGS= -g -std=c99 -Wall -Werror

all: main test

# Compile all .c files into .o files
# % matches all (like * in a command)
# $< is the source file (.c file)
%.o : %.c
	$(CC) -c $(CCFLAGS) $<

main: main.o mymath.o
	$(CC) -o main main.o mymath.o

test: main
	./main

clean:
	rm -f core *.o main
