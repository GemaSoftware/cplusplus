CC = g++
CFLAGS = -Wall -g
WEEK2 = ../week2
PREFIXSUM = $(WEEK2)/PrefixSum.o

INCLUDEWEEK2 = -I../week2

all: Lab2

clean:
	rm -f Lab2 lab2.o

Lab2: lab2.o
	$(CC) $(CFLAGS) -o Lab2 lab2.o $(PREFIXSUM)

lab2.o: lab2.cpp
	$(CC) $(CFLAGS) $(INCLUDEWEEK2) -c lab2.cpp


