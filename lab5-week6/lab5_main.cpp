#include "lab5.h"

int main(int argc, char** argv){
    if(argc != 2){
        std::cout << "Usage: ./lab5_main <filename>" << std::endl;
        return 1;
    }
    std::vector<double_vector> vectors = read_vectors(argv[1]);
    std::vector<pair_vector> pairs = create_vector_pairs(vectors);
    sort_pairwise_vectors(pairs);
    print_double_vectors(pairs);
    print_pair_ordering(pairs);
    return 0;
    

}