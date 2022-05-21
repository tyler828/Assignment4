#pragma once

#include <string>
#include "movie.h"

// -------------------------------- comedy.h ----------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/19/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the comedy class, a subclass of the
// movie class. The comedy class overwrites the comparison operators so that
// the comparison of two comedy movies is based on their titles, then the years
// they were released.
// ----------------------------------------------------------------------------

class Comedy : public Movie
{
public:
    // --------------------------Parametrized Constructor--------------------------
    // Description: The parametrized constructor creates a comedy movie object
    // based on the given title, director, release year, and maximum stock.
    //
    // Pre: The given information must correctly represent the comedy movie.
    //
    // Post: A comedy movie object that has the given title, director, release
    // year, and maximum stock exists. The current stock is initialized to the
    // maximum stock.
    //
    // Param: title, the title of the comedy movie.
    //
    // Param: director, the director of the comedy movie.
    //
    // Param: releaseYear, the year when the comedy movie was released.
    //
    // Param: max, the maximum stock of the comedy movie.
    Comedy(std::string title, std::string director, std::string releaseYear, int max);

    // ---------------------------------operator<----------------------------------
    // Description: The method operator< overloads the operator <, comparing this
    // comedy movie, which is on the left-hand side of the operator <, with the
    // comedy movie object on the right-hand side based on their titles, then the
    // years they were released.
    //
    // Post: These two comedy movie objects do not change.
    //
    // Param: rhs, which is the comedy movie object on the right-hand side.
    //
    // Return: This method returns true if the title of this comedy movie comes
    // before the title of the comedy movie on the right-hand side with an
    // alphabetical order. This method also turns true if these two comedy movies
    // have the same title but this comedy movie was released before the other
    // one. This method returns false otherwise.
    bool operator<(Comedy& rhs) const;

    // ---------------------------------operator>----------------------------------
    // Description: The method operator> overloads the operator >, comparing this
    // comedy movie, which is on the left-hand side of the operator >, with the
    // comedy movie object on the right-hand side based on their titles, then the
    // years they were released.
    //
    // Post: These two comedy movie objects do not change.
    //
    // Param: rhs, which is the comedy movie object on the right-hand side.
    //
    // Return: This method returns true if the title of this comedy movie comes
    // after the title of the comedy movie on the right-hand side with an
    // alphabetical order. This method also turns true if these two comedy movies
    // have the same title but this comedy movie was released after the other
    // one. This method returns false otherwise.
    bool operator>(Comedy& rhs) const;
private:

};
