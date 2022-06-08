#pragma once

#include <string>
#include "movie.h"

// -------------------------------- drama.h ----------------------------------
// Programmer Name: Austin Schnarre   Course Section Number: CSS 343 B
// Creation Date: 5/23/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the Drama class, a subclass of the
// Movie class. The Drama class overwrites the method getSoring so that the
// comparison of two Drama movies is based on their directors, and then their
// titles. Additionally, the Drama class overwrites the output operator.
// ----------------------------------------------------------------------------

class Drama : public Movie
{
public:
    // --------------------------Parametrized Constructor--------------------------
    // Description: The parametrized constructor creates a drama movie object
    // based on the given title, director, release year, and maximum stock.
    //
    // Pre: The given information must correctly represent the drama movie.
    //
    // Post: A drama movie object that has the given title, director, release
    // year, and maximum stock exists. The current stock is initialized to the
    // maximum stock.
    //
    // Param: title, the title of the drama movie.
    //
    // Param: director, the director of the drama movie.
    //
    // Param: releaseYear, the year when the drama movie was released.
    //
    // Param: max, the maximum stock of the drama movie.
    Drama(std::string title, std::string director, std::string releaseYear, int max);

    // ---------------------------------operator<<----------------------------------
    // Description: The method operator<< overloads the operator <<, displaying the
    // drama movie on the right-hand side of the operator << through the ostream
    // object on the left-hand side.
    //
    // Post: This method displayed the drama movie through the ostream object.
    //
    // Param: output, which is the ostream object.
    //
    // Param: rhs, which is the drama movie to display.
    //
    // Return: A reference to the ostream object.
    friend std::ostream& operator<<(std::ostream& output, const Drama& rhs);

    void print(std::ostream& output) const;

    // ---------------------------------getSorting---------------------------------
    // Description: The method getSorting gets the sorting attributes of this
    // movie.
    //
    // Post: This movie does not change.
    //
    // Return: An array that stores the sorting attributes of this movie.
    std::string* getSorting() const;

    std::string getDirector() const;

    std::string getTitle() const;
private:

};