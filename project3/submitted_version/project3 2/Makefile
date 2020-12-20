# Makefile for project 3
#
# You should not modify this file.

CC		= gcc

CFLAGS		= -g  -Og  -Wall -std=c99

all: problem1 problem2

problem1: given/problem1.o foo.o given/foo.h
	$(CC) $(CFLAGS) -o problem1 given/problem1.o foo.o

problem2: given/problem2.o bar.o given/bar.h
	$(CC) $(CFLAGS) -o problem2 given/problem2.o bar.o  

foo.o: foo.c given/foo.h
	$(CC) $(CFLAGS) -c foo.c

bar.o: bar.c given/bar.h
	$(CC) $(CFLAGS) -c bar.c

run_problem1: problem1
	./problem1 

run_problem2: problem2
	./problem2 

clean:
	rm -f *~ *.o a.out core problem1 problem2
