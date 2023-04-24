CC = g++
CFLAGS = -Wall -g -std=c++14

all: lab9_test

clean:
	rm -f *.o lab9_test *.o

lab9_test: lab9_test.o lab9_funs.o
	$(CC) $(CFLAGS) -o lab9_test lab9_test.o lab9_funs.o

lab9_test.o: lab9_test.cpp
	$(CC) $(CFLAGS) -c lab9_test.cpp

lab9_funs.o: lab9_funs.cpp
	$(CC) $(CFLAGS) -c lab9_funs.cpp