#include "lab5.h"

std::vector<double_vector> read_vectors(std::string filename) {
    std::vector<double_vector> vectors;
    std::ifstream file(filename);
    double from, to;
    int id = 0;
    //read in two integers from stdin. into from and to.

    //we want to test edge case for if file is empty.
    if(file.peek() == std::ifstream::traits_type::eof()){
        file.close();
        throw std::string("Exception: Input File is Empty.");
    }

    //main while loop, reading vectors in.
    while (file >> from >> to) {
        vectors.push_back(double_vector{id, from, to});
        id++;
    }
    file.close();
    return vectors;
}

double dot_product_vec(const double_vector &iv1, const double_vector &iv2)
{
    //take iv1 and iv2 and multiply their x and y. sum and return dot product
    return (iv1.from * iv2.from) + (iv1.to * iv2.to);
}


double vec_magnitude(const double_vector& vec)
{
    using namespace std;
    double x = vec.from;
    double y = vec.to;
    //calc magnitude of vector
    double vec_mag = sqrt((pow(x, 2) + pow(y, 2)));
    return vec_mag;
}

bool compare_pair_vectors(const pair_vector& p1, const pair_vector& p2)
{
    return p1.cos_dist < p2.cos_dist;
}

double calc_theta_distance(const double_vector& v1, const double_vector& v2)
{
    using namespace std;
    double dot_prod = dot_product_vec(v1, v2);
    double norm_prod = vec_magnitude(v1) * vec_magnitude(v2);
    return acos(dot_prod / norm_prod);
}

void sort_pairwise_vectors(std::vector<pair_vector>& pairwise_list){
    std::sort(pairwise_list.begin(), pairwise_list.end(), compare_pair_vectors);
}

void print_double_vectors(std::vector<pair_vector> pairwise_list){
    for(pair_vector pv : pairwise_list ){
        printf("(v%d)->(v%d) = %.10f\n", pv.v1.id, pv.v2.id, pv.cos_dist);
    }
}

void print_pair_ordering(std::vector<pair_vector> pairwise_list){
    for(pair_vector pv : pairwise_list ){
        printf("(%d, %d), ", pv.v1.id, pv.v2.id);
    }
    printf("\n");
}

std::vector<pair_vector> create_vector_pairs(std::vector<double_vector> listofDoubleVectors)
{
    std::vector<pair_vector> listofPairs;
    int listSize = static_cast<int>(listofDoubleVectors.size());

    for(int i = 0; i < listSize-1; i++){
        for(int j = i+1; j < listSize; j++){
            double_vector x = listofDoubleVectors[i];
            double_vector y = listofDoubleVectors[j];
            listofPairs.push_back(pair_vector{x,y, calc_theta_distance(x,y)});
        }
    }
    return listofPairs;
}
