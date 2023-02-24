#include "week6.h"

int main(int argc, char** argv){
    if(argc != 2){
        std::cout << "Usage: ./week6_vector_main <filename>" << std::endl;
        return 1;
    }
    std::vector<int_vector> vectors = read_vectors(argv[1]);
    print_reverse_int_vectors(vectors);
    return 0;

}