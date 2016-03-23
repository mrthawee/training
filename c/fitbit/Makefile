# Define what compiler to use and the flags
CC=cc
CXX=CC
CCFLAGS= -std=c99 -Wall -Werror -g

# define which rule to be executed when running 'make' 
all: build 

%.o : %.c
	$(CC) -c $(CCFLAGS) $<

build: adp.o 
	$(CC) -o adp adp.o

clean:
	rm -f core adp.o adp
