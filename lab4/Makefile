CC = g++
CFLAGS = -Wall -g

all: lab4test

clean:
	rm -f lab4test *.o

lab4test: lab4.o lab4test.o
	$(CC) $(CFLAGS) -o lab4test lab4.o lab4test.o

lab4test.o: lab4test.cpp
	$(CC) $(CFLAGS) -c lab4test.cpp

lab4.o: lab4.cpp
	$(CC) $(CFLAGS) -c lab4.cpp