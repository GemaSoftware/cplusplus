#include "week4funcs.h"

// Using the STL, write C++ functions for pushing elements to an STL stack of structs and popping these structs.

// Similarly, using the STL, write C++ functions for pushing elements to an STL queue of structs and popping these structs.

// These functions should read from a text file and push the values of the text file as integers on to the stack and queue.

// If the sum of the elements on a stack have a negative sum, then an exception must be thrown. You must
// also catch that exception.
using namespace std;

void pushElementsToStlStack(std::stack<int>& stack, const std::string& filename)
{
    //Check if the file is open.
    std::ifstream file(filename);

    int sum = 0;
    try{
        if(file.is_open()){
        int x = 0;
        //if file open, loop through each value and push into the stack.
        while(file >> x){
            stack.push(int(x));
            sum += (int) x;
        }
        //if sum negative, throw exception.
        if(sum < 0){
                throw std::string("negative sum");
        }
    }
    // close file after reading everything.
    file.close();
    } catch(std::string){ //if exception caught, negative sum , close file.
        //close the file.
        file.close();
        //throw it back to <.>_<.>
        throw;
    }
    
}

int popElementStlStack(std::stack<int>& stack)
{
    if(!stack.empty()){
        int temp =  stack.top();
        stack.pop();
        return temp;
    }
    return 0;
}

void queueElementsStlQueue(std::queue<int>& queue, std::string &filename)
{
    // Will be almost identical to stack. 
    // Check if the file is open.
    std::ifstream file(filename);
    if(file.is_open()){
        int x = 0;
        //if file open, loop through each value and push into the stack.
        while(file >> x){
            queue.push(x);
        }
    }
    // close file after reading everything.
    file.close();
}

int dequeueElementStlQueue(std::queue<int>& queue)
{
     if(!queue.empty()){
        int temp = queue.front();
        queue.pop();
        return temp;
    }
    return 0;
}
