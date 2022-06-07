#include <iostream>
#include "drama.h"
#include "comedy.h"

int main()
{
    Comedy test("title", "director", "releaseYear", 20);
    std::cout << test << std::endl;
    return 0;
}
