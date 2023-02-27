#ifndef LAB5_FUNCS
#define LAB5_FUNCS
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

//Instead if importing week6 headers, we need vectors of doubles. Modified double_vector to support double.
struct double_vector {
    int id;
    double from;
    double to;

    //default constructor
    double_vector(int x, double y, double z){
        id = x;
        from = y;
        to = z;
    }

    //copy-constructor
    double_vector(const double_vector& other){
        id = other.id;
        from = other.from;
        to = other.to;
    }
};

struct pair_vector {
    double_vector v1;
    double_vector v2;
    double cos_dist;
};

/// @brief This function will read in vectors from a file.
/// @param filename 
/// @return a vector of double_vectors.
std::vector<double_vector> read_vectors(std::string filename);

/// @brief This function will compute the dot product of the two vectors.
/// @param iv1 
/// @param iv2 
/// @return Returns a double of the two vectors dot product.
double dot_product_vec(const double_vector& iv1, const double_vector& iv2);

/// @brief This function computes the vectors magnitude
/// @param vec the double_vector 
/// @return the vectors magnitude.
double vec_magnitude(const double_vector& vec);

/// @brief Calculates the theta between the two vectors. This number will be in radians, and will be used to compare vectors.
/// @param  v1
/// @param  v2
/// @return return the theta distance between the two vectors in radians.
double calc_theta_distance(const double_vector& v1, const double_vector& v2);

/// @brief This function will compare two vector pairs by their cosign distance (in radians)
/// @param p1
/// @param p2
/// @return a boolean if p1 > p2
bool compare_pair_vectors(const pair_vector& p1, const pair_vector& p2);

/// @brief This function will sort the pairwise_list given.
/// 
void sort_pairwise_vectors(std::vector<pair_vector>& pairwise_list);

/// @brief This function will take a list of double_vectors and create all the different pairs of vectors.
/// @param listofDoubleVectors 
/// @return a vector of pair_vectors
std::vector<pair_vector> create_vector_pairs(std::vector<double_vector> listofDoubleVectors);

/// @brief This function will sort and print the list of pairwise vectors.
/// @param double_vectorList 
void print_double_vectors(std::vector<pair_vector> pairwise_list);

/// @brief This function will just print the pairwise list as shown in slides. (1,2), (1,3), (1,4), etc using the vectors id's
/// @param pairwise_list 
void print_pair_ordering(std::vector<pair_vector> pairwise_list);

#endif