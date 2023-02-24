#include "week6.h"

std::vector<int_vector> read_vectors(std::string filename) {
    std::vector<int_vector> vectors;
    std::ifstream file(filename);
    int from, to;
    int id = 0;
    //read in two integers from stdin. into from and to.

    //we want to test edge case for if file is empty.
    if(file.peek() == std::ifstream::traits_type::eof()){
        file.close();
        throw std::string("Exception: Input File is Empty.");
    }

    //main while loop, reading vectors in.
    while (file >> from >> to) {
        vectors.push_back(int_vector{id, from, to});
        id++;
    }
    file.close();
    return vectors;
}

void print_reverse_int_vectors(std::vector<int_vector> vectors)
{
    using namespace std;
    for(int i = vectors.size()-1; i >= 0; i--){
        const int_vector test = vectors[i];
        printf("%d: %d %d\n", test.id, test.from, test.to);
    }
}
