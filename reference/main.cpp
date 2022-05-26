#include <string>
#include "table.h"

int main()
{
    MyTable<int, char> test;
    test.insert(143, 'A');
    test.insert(43, 'B');
    test.insert(243, 'C');
    test.insert(3, 'D');
    test.insert(2, 'E');
    return 0;
}
