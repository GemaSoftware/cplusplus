#ifndef WEEK8_READ_VECTOR_LIST
#define WEEK8_READ_VECTOR_LIST
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>

std::vector<std::vector<int>> read_adj_list_file(const std::string & fileName);

void print_adjacency_list(const std::vector<std::vector<int>> & temp);

#endif