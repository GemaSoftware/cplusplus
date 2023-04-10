CC = g++
CFLAGS = -Wall -g -std=c++14

all: week11_main week11_test

clean:
	rm -f *.o week11_main week11_test *.o

week11_test: week11_test.o week11_funcs.o
	$(CC) $(CFLAGS) -o week11_test week11_test.o week11_funcs.o

week11_main: week11_main.o week11_funcs.o
	$(CC) $(CFLAGS) -o week11_main week11_main.o week11_funcs.o

week11_main.o: week11_main.cpp
	$(CC) $(CFLAGS) -c week11_main.cpp
	
week11_test.o: week11_test.cpp
	$(CC) $(CFLAGS) -c week11_test.cpp

week11_funcs.o: week11_funcs.cpp
	$(CC) $(CFLAGS) -c week11_funcs.cpp