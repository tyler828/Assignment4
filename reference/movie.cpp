#include "movie.h"

// --------------------------Parametrized Constructor--------------------------
// Description: The parametrized constructor creates a movie object based on
// the given title, director, release year, and maximum stock.
//
// Pre: The given information must correctly represent the movie.
//
// Post: A movie object that has the given title, director, release year, and
// maximum stock exists. The current stock is initialized to the maximum stock.
//
// Param: title, the title of the movie.
//
// Param: director, the director of the movie.
//
// Param: releaseYear, the year when the movie was released.
//
// Param: max, the maximum stock of the movie.
Movie::Movie(std::string title, std::string director, std::string releaseYear, int max) {
    this->title = title;
    this->director = director;
    this->releaseYear = releaseYear;
    this->max = max;
    this->stock = max;
}

// ---------------------------------operator<----------------------------------
// Description: The method operator< overloads the operator <, comparing this
// movie, which is on the left-hand side of the operator <, with the movie
// object on the right-hand side.
//
// Post: These two movie objects do not change.
//
// Param: rhs, which is the movie object on the right-hand side.
//
// Return: True if this movie is less than the movie on the right-hand side;
// false otherwise.
bool Movie::operator<(const Movie& rhs) const
{
    return this->stock < rhs.stock;
}

// ---------------------------------operator>----------------------------------
// Description: The method operator> overloads the operator >, comparing this
// movie, which is on the left-hand side of the operator >, with the movie
// object on the right-hand side.
//
// Post: These two movie objects do not change.
//
// Param: rhs, which is the movie object on the right-hand side.
//
// Return: True if this movie is greater than the movie on the right-hand side;
// false otherwise.
bool Movie::operator>(const Movie& rhs) const
{
    return this->stock > rhs.stock;
}
