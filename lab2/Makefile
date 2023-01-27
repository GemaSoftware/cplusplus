CC = g++
CFLAGS = -Wall -g

all: Lab2

Lab2: lab2.o prefixSum.o
	$(CC) $(CFLAGS) -o Lab2 lab2.o prefixSum.o

prefixSum.o: PrefixSum.h PrefixSum.cpp
	$(CC) $(CFLAGS) -c PrefixSum.cpp