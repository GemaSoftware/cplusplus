CC = g++
CFLAGS = -Wall -g
WEEK2 = ../week2
PREFIXSUM = $(WEEK2)/PrefixSum.o

INCLUDEWEEK2 = -I../week2

all: Lab2

clean:
	rm -f lab2.o UnitTestLab2 UnitTestLab2.o

Lab2: lab2.o
	$(CC) $(CFLAGS) -o Lab2 lab2.o $(PREFIXSUM)

#UnitTestLab2: UnitTestLab2.o lab2.o
#	$(CC) $(CFLAGS) -o UnitTestLab2 UnitTestLab2.o lab2.o $(PREFIXSUM)

lab2.o: lab2.cpp
	$(CC) $(CFLAGS) $(INCLUDEWEEK2) -c lab2.cpp

#UnitTestLab2.o: lab2.h UnitTestLab2.cpp
#	$(CC) $(CFLAGS) $(INCLUDEWEEK2) -c UnitTestLab2.cpp

