#pragma once

#include <string>
#include "movie.h"

// -------------------------------- drama.h ----------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/23/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the Drama class, a subclass of the
// Movie class. The Drama class overwrites the comparison operators so that
// the comparison of two Drama movies is based on their directors, and then
// their titles.
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

    // ---------------------------------operator<----------------------------------
    // Description: The method operator< overloads the operator <, comparing this
    // drama movie, which is on the left-hand side of the operator <, with the
    // drama movie object on the right-hand side based on their directors, then
    // their titles.
    //
    // Post: These two drama movie objects do not change.
    //
    // Param: rhs, which is the drama movie object on the right-hand side.
    //
    // Return: This method returns true if the name of the director of this drama
    // movie comes before the name of the director of the drama movie on the
    // right-hand side with an alphabetical order. This method also returns true if
    // these two drama movies have the same director but the title of this drama
    // movie comes before the title of the drama movie on the right-hand side
    // with an alphabetical order. This method returns false otherwise.
    bool operator<(Drama& rhs) const;

    // ---------------------------------operator>----------------------------------
    // Description: The method operator> overloads the operator >, comparing this
    // drama movie, which is on the left-hand side of the operator >, with the
    // drama movie object on the right-hand side based on their directors, then
    // their titles.
    //
    // Post: These two drama movie objects do not change.
    //
    // Param: rhs, which is the drama movie object on the right-hand side.
    //
    // Return: This method returns true if the name of the director of this drama
    // movie comes after the name of the director of the drama movie on the
    // right-hand side with an alphabetical order. This method also returns true if
    // these two drama movies have the same director but the title of this drama
    // movie comes after the title of the drama movie on the right-hand side
    // with an alphabetical order. This method returns false otherwise.
    bool operator>(Drama& rhs) const;

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

    std::string getDirector() const;

    std::string getTitle() const;
private:

};