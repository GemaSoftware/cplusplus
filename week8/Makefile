CC = g++
CFLAGS = -Wall -g -std=c++14

all: week8_main week8_test

clean:
	rm -f *.o week8_main week8_test *.o

week8_test: week8_test.o rvector.o
	$(CC) $(CFLAGS) -o week8_test week8_test.o rvector.o

week8_main: week8_main.o rvector.o
	$(CC) $(CFLAGS) -o week8_main week8_main.o rvector.o

week_main.o: week8_main.cpp
	$(CC) $(CFLAGS) -c week8_main.cpp

rvector.o: rvector.cpp
	$(CC) $(CFLAGS) -c rvector.cpp