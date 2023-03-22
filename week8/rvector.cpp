#include "rvector.h"

std::vector<std::vector<int>> read_adj_list_file(const std::string &fileName)
{
    //while there are lines in the file left:
    //set the id = the vector that we are looking at. 

    std::ifstream infile(fileName);
    std::string line;

    std::vector<std::vector<int>> res;

    //while there is a line to be read
    while(std::getline(infile, line)){
        std::istringstream stringstream(line);
        int t;
        //for each element in the line
        std::vector<int> temp;
        while(stringstream >> t){
            if (t >= 0){
                temp.push_back(t);
            }
        }
        res.push_back(temp);
    }
    return res;
}

void print_adjacency_list(const std::vector<std::vector<int>> &temp)
{
    int id = 1;
    for(auto x : temp){
        printf("%d: ", id);
        for(auto y : x){
            printf("%d ", y);
        }
        printf("\n");
        id++;
    }
}
