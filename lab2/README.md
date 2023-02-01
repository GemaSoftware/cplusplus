# Compiling Instructions
When compiling this lab, please just use the connected Makefile so that it pulls in all necessary libraries from previous folders.
```
make clean
make all
```

# Running Instructions
This program works by taking in 2 inputs from the user.
The first being "n" which is half of the number of elements in the list.
The second is "att" which is the number of iterations to generate and scramble the list in hopes of generating a well balanced list.

As output you will get the number of successful well balanced lists generating in those iterations. See below as an example:
```
Please enter an integer n (-1 to quit): 20
Please enter number of iterations: (-1 to quit): 50000
Number of successes for n=20 and 50000 attempts is 5034
Ratio of Success/Attempts: 0.10068
```

The test cases are apart of the executable. It will run test cases first and then enter the program loop. Keep that in mind as it will as for an integer after the test cases.
```
./Lab2
```
