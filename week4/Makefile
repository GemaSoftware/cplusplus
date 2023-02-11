CC = g++
CFLAGS = -Wall -g

all: TestWeek4

clean:
	rm -f *.o TestWeek4

TestWeek4: TestWeek4.o week4funcs.o
	$(CC) $(CFLAGS) -o TestWeek4 TestWeek4.o week4funcs.o

TestWeek4.o: TestWeek4.cpp
	$(CC) $(CFLAGS) -c TestWeek4.cpp

week4funcs.o: week4funcs.cpp
	$(CC) $(CFLAGS) -c week4funcs.cpp