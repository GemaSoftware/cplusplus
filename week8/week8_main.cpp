#include "rvector.h"

int main(int argc, char** argv){
    if(argc != 2){
            std::cout << "Usage: ./week8_main <filename>" << std::endl;
            return 1;
    }

    std::vector<std::vector<int>> temp = read_adj_list_file("test.txt");
    print_adjacency_list(temp);
}