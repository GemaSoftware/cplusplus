CC = g++
CFLAGS = -Wall -g

INCLUDE = -I../week2

all: Lab2

Lab2: lab2.o PrefixSum.o
	$(CC) $(CFLAGS) -o Lab2 lab2.o PrefixSum.o

lab2.o: lab2.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c lab2.cpp

PrefixSum.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c ../week2/PrefixSum.cpp

