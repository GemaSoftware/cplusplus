CC = g++
CFLAGS = -Wall -g -std=c++14

all: lambdaTest

clean:
	rm -f *.o lambdaTest

lambdaTest: lambdaTest.o lambdas.o
	$(CC) $(CFLAGS) -o lambdaTest lambdaTest.o lambdas.o

lambdaTest.o: lambdaTest.cpp
	$(CC) $(CFLAGS) -c lambdaTest.cpp

lambdas.o: lambdas.cpp
	$(CC) $(CFLAGS) -c lambdas.cpp