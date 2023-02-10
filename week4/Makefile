CC = g++
CFLAGS = -Wall -g

all: TestWeek4

clean:
	rm -f *.o TestWeek4

TestWeek4: TestWeek4.o Week4Funcs.o
	$(CC) $(CFLAGS) -o TestWeek4 TestWeek4.o Week4Funcs.o

TestWeek4.o: TestWeek.cpp
	$(CC) $(CFLAGS) -c TestWeek4.cpp

Week4Funcs.o: Week4Funcs.cpp
	$(CC) $(CFLAGS) -c Week4Funcs.cpp