#include <iostream>
#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"

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

    Classic o1("Metropolis", "Fritz Lang", "1927", "1", "Alfred Abel", 20);
    Classic o2("The Adventures of Robin Hood", "Michael Curtiz", "1938", "5", "Errol Flynn", 20);
    std::cout << (o1 > o2) << std::endl;
    std::cout << (o1 < o2) << std::endl;
    std::cout << o1 << std::endl;
    std::cout << o2 << std::endl;
    return 0;
}
