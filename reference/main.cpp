#include <string>
#include "table.h"

int main()
{
    MyTable<char, std::string> test;
    test.insert('A', "Test A_1");
    test.insert('A', "Test A_2");
    test.insert('<', "Test <_1");
    test.insert(';', "Test;_1");
    return 0;
}
