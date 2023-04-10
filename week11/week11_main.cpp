#include "week11.h"

int main(){
    Fraction x = create_fraction(5, 6); // 5/6
    Fraction y = create_fraction(2, 3);// 2/3
    Fraction red = multiply_fraction_pair(x, y); // 10/18

    std::cout << red.fraction.first << std::endl;
    std::cout << red.fraction.second << std::endl;
}

