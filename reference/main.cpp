#include <iostream>
#include "table.h"

int main()
{
    MyTable<char, float> test;
    test.insert('5', 0.08);
    test.insert('3', 0.03);
    test.insert('5', 0.05);
    test.insert('h', 6.5187);
    test.insert('H', 561.01);
    test.insert('#', 333.333);
    std::cout << test['5'] << std::endl;
    std::cout << test['3'] << std::endl;
    std::cout << test['h'] << std::endl;
    std::cout << test['H'] << std::endl;
    std::cout << test['#'] << std::endl;
    // std::cout << test['%'] << std::endl;
    return 0;
}
