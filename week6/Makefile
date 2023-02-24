CC = g++
CFLAGS = -Wall -g -std=c++14

all: week6_vector_main week6_vector_test

run: week6_vector_main week6_vector_test
	./week6_vector_test && ./week6_vector_main

test: week6_vector_test
	./week6_vector_test

clean:
	rm -f *.o week6_vector_main week6_vector_test

week6_vector_main: week6.o week6_vector_main.o
	$(CC) $(CFLAGS) -o week6_vector_main week6_vector_main.o week6.o

week6_vector_test: week6.o week6_vector_test.o
	$(CC) $(CFLAGS) -o week6_vector_test week6.o week6_vector_test.o

week6_vector_main.o: week6_vector_main.cpp
	$(CC) $(CFLAGS) -c week6_vector_main.cpp

week6.o: week6.cpp
	$(CC) $(CFLAGS) -c week6.cpp

week6_vector_test.o: week6_vector_test.cpp
	$(CC) $(CFLAGS) -c week6_vector_test.cpp