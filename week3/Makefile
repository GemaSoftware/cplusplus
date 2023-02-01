CC = g++
CFLAGS = -Wall -g

all: unitTestLinkedList

clean:
	rm -f week3 week3.o unitTestLinkedList.o unitTestLinkedList

week3: week3.o
	$(CC) $(CFLAGS) -o week3 week3.o

unitTestLinkedList: week3.o unitTestLinkedList.o
	$(CC) $(CFLAGS) -o unitTestLinkedList unitTestLinkedList.o week3.o

week3.o: week3.cpp
	$(CC) $(CFLAGS) -c week3.cpp

unitTestLinkedList.o: unitTestLinkedList.cpp
	$(CC) $(CFLAGS) -c unitTestLinkedList.cpp
