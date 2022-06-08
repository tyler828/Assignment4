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

    Drama* d1 = new Drama("Good Will Hunting", "Gus Van Sant", "1997", 20);
    Drama* d2 = new Drama("Eternal Sunshine of the Spotless Mind", "Michel Gondry", "2004", 20);
    Drama* d3 = new Drama("Good Morning Vietnam", "Barry Levinson", "1988", 20);
    Drama* d4 = new Drama("Good Morning Vietnam", "Barry Levinson", "1988", 20);

    /* std::cout << (*d1 < *d2) << std::endl;
    std::cout << (*d1 > *d2) << std::endl;

    Movie* m1 = new Drama("Good Will Hunting", "Gus Van Sant", "1997", 20);
    Movie* m2 = new Drama("Eternal Sunshine of the Spotless Mind", "Michel Gondry", "2004", 20);
    std::cout << (*m1 < *m2) << std::endl;
    std::cout << (*m1 > *m2) << std::endl;

    Comedy* f1 = new Comedy("Sleepless in Seattle", "Nora Ephron", "1993", 20);
    Comedy* f2 = new Comedy("Annie Hall", "Woody Allen", "1977", 20);
    Comedy* f3 = new Comedy("When Harry Met Sally", "Rob Reiner", "1989", 20);
    std::cout << (*f1 < *f2) << std::endl;
    std::cout << (*f1 > *f2) << std::endl;

    Movie* m1 = new Comedy("Sleepless in Seattle", "Nora Ephron", "1993", 20);
    Movie* m2 = new Comedy("Annie Hall", "Woody Allen", "1977", 20);
    std::cout << (*m1 < *m2) << std::endl;
    std::cout << (*m1 > *m2) << std::endl;

    Classic* c1 = new Classic("Casablanca", "Michael Curtiz", "1942", "8", "Ingrid Bergman", 20);
    Classic* c2 = new Classic("The Wizard of Oz", "Victor Fleming", "1939", "7", "Judy Garland", 20);
    Classic* c3 = new Classic("Harold and Maud", "Hal Ashby", "1971", "3", "Ruth Gordon", 20);
    std::cout << (*c1 < *c2) << std::endl;
    std::cout << (*c1 > *c2) << std::endl;

    Movie* m1 = new Classic("Casablanca", "Michael Curtiz", "1942", "8", "Ingrid Bergman", 20);
    Movie* m2 = new Classic("The Wizard of Oz", "Victor Fleming", "1939", "7", "Judy Garland", 20);
    std::cout << (*m1 < *m2) << std::endl;
    std::cout << (*m1 > *m2) << std::endl;

    BST.insert(c1);
    BST.insert(c2);
    BST.insert(c3);
    BST.inOrderTraversal(); */

    MyTable<int, Movie> testTable;
    testTable.insert(1, d1);
    testTable.insert(2, d2);
    testTable.insert(3, d3);
    std::cout << testTable.exist(1) << std::endl;
    std::cout << testTable.exist(4) << std::endl;
    std::cout << testTable[1] << std::endl;
    std::cout << testTable[2] << std::endl;
}
