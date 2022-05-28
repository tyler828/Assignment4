#include <iostream>
#include "table.h"

int main()
{
    MyTable<int, float> test;
    test.insert(6, 0.08);
    test.insert(606, 0.03);
    test.insert(81006, 0.05);
    test.insert(2, 6.5187);
    test.insert(3, 561.01);
    test.insert(5, 333.333);
    std::cout << test[6] << std::endl;
    std::cout << test[606] << std::endl;
    std::cout << test[81006] << std::endl;
    std::cout << test[2] << std::endl;
    std::cout << test[3] << std::endl;
    std::cout << test[5] << std::endl;
    test.remove(606);
    test.remove(2306);
    test.remove(1);
    return 0;
}
