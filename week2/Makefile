CC = g++
CFLAGS = -Wall -g

all: UnitTestSum

clean:
	rm -f PrefixSum UnitTestSum PrefixSum.o UnitTestSum.o

UnitTestSum: PrefixSum.o UnitTestSum.o
	$(CC) $(CFLAGS) -o UnitTestSum UnitTestSum.o PrefixSum.o

PrefixSum.o: PrefixSum.h PrefixSum.cpp
	$(CC) $(CFLAGS) -c PrefixSum.cpp

UnitTestSum.o: PrefixSum.h UnitTestSum.cpp
	$(CC) $(CFLAGS) -c UnitTestSum.cpp