CC = g++
CFLAGS = -Wall -g

all: TestNumbers ECRemoveElement

clean:
	rm -f TestNumbers ECRemoveElement

TestNumbers: TestNumbers.o ECNumbers.o ECCalculator.o
	$(CC) $(CFLAGS) -o TestNumbers TestNumbers.o ECNumbers.o ECCalculator.o

ECRemoveElement: ECRemoveElement.o
	$(CC) $(CFLAGS) -o ECRemoveElement ECRemoveElement.o

ECRemoveElement.o: ECRemoveElement.cpp
	$(CC) $(CFLAGS) -c ECRemoveElement.cpp

TestNumbers.o: TestNumbers.cpp ECNumbers.h ECCalculator.h
	$(CC) $(CFLAGS) -c TestNumbers.cpp

ECNumbers.o: ECNumbers.cpp ECNumbers.h
	$(CC) $(CFLAGS) -c ECNumbers.cpp

ECCalculator.o: ECCalculator.cpp ECCalculator.h
	$(CC) $(CFLAGS) -c ECCalculator.cpp