#ifndef WEEK6_VECTOR_FUNCS
#define WEEK6_VECTOR_FUNCS
#include <iostream>
#include <vector>
#include <fstream>

struct int_vector {
    int id;
    int from;
    int to;

    //default constructor
    int_vector(int x, int y, int z){
        id = x;
        from = y;
        to = z;
    }

    //copy-constructor
    int_vector(const int_vector& other){
        id = other.id;
        from = other.from;
        to = other.to;
    }
};


/// @brief This function will read in vectors from a file.
/// @param filename 
/// @return a vector of int_vectors.
std::vector<int_vector> read_vectors(std::string filename);


/// @brief This function will print to STDout the vectors in reverse order.
/// @param vectors 
void print_reverse_int_vectors(std::vector<int_vector> vectors);



#endif