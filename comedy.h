#pragma once

#include <string>
#include "movie.h"

// -------------------------------- comedy.h ----------------------------------
// Programmer Name: Austin Edward Schnarre     Course Section Number: CSS 343 B
// Creation Date: 5/19/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the Comedy class, a subclass of the
// Movie class. The Comedy class overwrites the comparison operators so that
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

    // ---------------------------------operator<<----------------------------------
    // Description: The method operator<< overloads the operator <<, displaying the
    // comedy movie on the right-hand side of the operator << through the ostream
    // object on the left-hand side.
    //
    // Post: This method displayed the comedy movie through the ostream object.
    //
    // Param: output, which is the ostream object.
    //
    // Param: rhs, which is the comedy movie to display.
    //
    // Return: A reference to the ostream object.
    friend std::ostream& operator<<(std::ostream& output, const Comedy& rhs);

    void print(std::ostream& output) const;

    // ---------------------------------getSorting---------------------------------
    // Description: The method getSorting gets the sorting attributes of this
    // movie.
    //
    // Post: This movie does not change.
    //
    // Return: An array that stores the sorting attributes of this movie.
    std::string* getSorting() const;

private:

};
