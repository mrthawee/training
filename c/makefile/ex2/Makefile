## This is a simple Makefile

# Define what compiler to use and the flags
CC=cc
CXX=CC
CCFLAGS= -g -std=c99 -Wall -Werror -I.

# => when running 'make' do these
# 1. rule for hellomake = build ./hellomake
# 2. rule for test = running ./hellomake
all: hellomake test

# Compile all .c files into .o files
# % matches all (like * in a command)
# $< is the source file (.c file)
%.o : %.c
	$(CC) -c $(CCFLAGS) $<

hellomake: hellofunc.o hellomake.o
	$(CC) -o hellomake hellofunc.o hellomake.o

test: hellomake
	./hellomake

clean:
	rm -f core *.o hellomake
