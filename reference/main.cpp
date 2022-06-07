#include <iostream>
#include "drama.h"

int main()
{
    Drama test("title", "director", "releaseYear", 20);
    std::cout << test << std::endl;
    return 0;
}
