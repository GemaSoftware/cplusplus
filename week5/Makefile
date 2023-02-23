CC = g++
CFLAGS = -Wall -g -std=c++14

all: week5main week5_unit_test

run: week5main week5_unit_test
	./week5_unit_test && ./week5main

test: week5_unit_test
	./week5_unit_test

clean:
	rm -f *.o week5main week5_unit_test

week5main: student.o week5.o week5_main.o
	$(CC) $(CFLAGS) -o week5main week5.o week5_main.o student.o

week5_unit_test: student.o week5.o week5_unit_test.o
	$(CC) $(CFLAGS) -o week5_unit_test week5.o student.o week5_unit_test.o

week5_main.o: week5_main.cpp
	$(CC) $(CFLAGS) -c week5_main.cpp

week5.o: week5.cpp
	$(CC) $(CFLAGS) -c week5.cpp

student.o: student.cpp
	$(CC) $(CFLAGS) -c student.cpp

week5_unit_test.o: week5_unit_test.cpp
	$(CC) $(CFLAGS) -c week5_unit_test.cpp