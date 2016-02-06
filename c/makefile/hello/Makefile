## This is a simple Makefile

# Define what compiler to use and the flags
CC=cc
CXX=CC
CCFLAGS= -g -std=c99 -Wall -Werror

all: hello test

# Compile all .c files into .o files
# % matches all (like * in a command)
# $< is the source file (.c file)
%.o : %.c
	$(CC) -c $(CCFLAGS) $<

hello: helloWorld.o
	$(CC) -o helloWorld helloWorld.o

test: hello
	./helloWorld

clean:
	rm -f core *.o helloWorld
