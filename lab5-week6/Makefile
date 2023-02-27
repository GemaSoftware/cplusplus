CC = g++
CFLAGS = -Wall -g -std=c++14

all: lab5_test lab5_main

main: lab5_main
	./lab5_main

test: lab5_test
	./lab5_test

clean:
	rm -f *.o lab5_test lab5_main

lab5_main: lab5.o lab5_main.o
	$(CC) $(CFLAGS) -o lab5_main lab5.o lab5_main.o

lab5_test: lab5_test.o lab5.o
	$(CC) $(CFLAGS) -o lab5_test lab5.o lab5_test.o

lab5_test.o: lab5_test.cpp
	$(CC) $(CFLAGS) -c lab5_test.cpp

lab5_main.o: lab5_main.cpp
	$(CC) $(CFLAGS) -c lab5_main.cpp

lab5.o: lab5.cpp
	$(CC) $(CFLAGS) -c lab5.cpp
