#include <iostream>
#include "movie.h"
#include "drama.h"
#include "comedy.h"

int main()
{
    Movie test("title", "director", "releaseYear", 20);

    Drama d1("Good Will Hunting", "Gus Van Sant", "1997", 20);
    Drama d2("Eternal Sunshine of the Spotless Mind", "Michel Gondry", "2004", 20);
    std::cout << (d1 > d2) << std::endl;
    std::cout << (d1 < d2) << std::endl;
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;

    Comedy c1("Ghostbusters", "Ivan Reitman", "1984", 20);
    Comedy c2("The Hangover", "Todd Phillips", "2009", 20);
    std::cout << (c1 > c2) << std::endl;
    std::cout << (c1 < c2) << std::endl;
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    return 0;
}
