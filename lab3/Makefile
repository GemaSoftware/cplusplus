CC = g++
CFLAGS = -Wall -g
WEEK2 = ../week2
PREFIXSUM = $(WEEK2)/PrefixSum.o

INCLUDEWEEK2 = -I../week2

all: Lab3

clean:
	rm -f lab3.o Lab3

Lab3: lab3.o
	$(CC) $(CFLAGS) -o Lab3 lab3.o $(PREFIXSUM)

#UnitTestLab3: UnitTestLab2.o lab2.o
#	$(CC) $(CFLAGS) -o UnitTestLab2 UnitTestLab2.o lab2.o $(PREFIXSUM)

lab3.o: lab3.cpp
	$(CC) $(CFLAGS) $(INCLUDEWEEK2) -c lab3.cpp

#UnitTestLab2.o: lab2.h UnitTestLab2.cpp
#	$(CC) $(CFLAGS) $(INCLUDEWEEK2) -c UnitTestLab2.cpp


