CC = g++
CFLAGS = -Wall -g -std=c++14

all: week9_test

clean:
	rm -f *.o week9_test

week9_test: week9_test.o
	$(CC) $(CFLAGS) -o week9_test week9_test.o

week9_test.o: week9_test.cpp
	$(CC) $(CFLAGS) -c week9_test.cpp