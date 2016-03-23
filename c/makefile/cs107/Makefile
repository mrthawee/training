# A simple makefile

CC = gcc
CFLAGS = -g -I./inc -I./src
LDFLAGS = -L -l

PROG = main
HDRS = util.h node.h 
SRCS = main.c node.c util.c

# This incantation says that the object files
# have the same name as the .c files, but with .o
OBJS = $(SRCS:.c=.o)

# This is the first rule (the default)
# Build the same name as the .c files, but with .o
$(PROG) : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(PROG)

# Rules for the source files -- these do not have 
# second build rule lines, so they will use the
# default build rule to compile X.x to make X.o
main.o : main.c node.h util.h

node.o : node.c node.h

util.o : util.c util.h

# Remove all the compilation and debugging files
clean:
	rm -f core $(PROG) $(OBJS)

# Build tags for these sources
TAGS : $(SRCS) $(HDRS)
	tags -t $(SRCS) $(HDRS)
