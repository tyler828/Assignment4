#include <iostream>
#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"
#include "movie_collection.h"
#include "table.h"

int main()
{
    Movie test("title", "director", "releaseYear", 20);
    MovieCollection BST;

    // Drama* d1 = new Drama("Good Will Hunting", "Gus Van Sant", "1997", 20);
    // Drama* d2 = new Drama("Eternal Sunshine of the Spotless Mind", "Michel Gondry", "2004", 20);

    // BST.insert(d1);
    // BST.insert(d2);

    MyTable<int, int> table;
    int* i1 = new int(5);
    int* i2 = new int(6);
    int* i3 = new int(7);
    int* i4 = new int(8);
    table.insert(1, i1);
    table.insert(101, i2);
    table.insert(101, i3);
    table.insert(2, i4);
    std::cout << table[101] << std::endl;
    std::cout << table[201] << std::endl;
    std::cout << table[2] << std::endl;
    std::cout << table[3] << std::endl;
    table.remove(101);
    table.remove(3);
}
