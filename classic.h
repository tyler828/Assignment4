#pragma once

#include <string>
#include "movie.h"

// -------------------------------- classic.h ----------------------------------
// Programmer Name: Austin Schnarre     Course Section Number: CSS 343 B
// Creation Date: 5/23/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the Classic class, a subclass of the
// Movie class. The Classic class has two more attributes than the Movie class:
// the major actor and the release month. The Classic class overwrites the
// comparison operators so that the comparison of two classic movies is based on
// the dates when they were released and then their major actors.
// ----------------------------------------------------------------------------

class Classic : public Movie
{
public:
    // --------------------------Parametrized Constructor--------------------------
    // Description: The parametrized constructor creates a classic movie object
    // based on the given title, director, release year, release month, actor,
    // and maximum stock.
    //
    // Pre: The given information must correctly represent the classic movie.
    //
    // Post: A classic movie object that has the given title, director, release
    // year, release month, actor, and maximum stock exists. The current stock is
    // initialized to the maximum stock.
    //
    // Param: title, the title of the classic movie.
    //
    // Param: director, the director of the classic movie.
    //
    // Param: releaseYear, the year when the classic movie was released.
    //
    // Param: releaseMonth, the month when the classic movie was released.
    //
    // Param: actor, the major actor of the classic movie.
    //
    // Param: max, the maximum stock of the movie.
    Classic(std::string title, std::string director,
            std::string releaseYear, std::string releaseMonth, std::string actorName, int max);

    // ---------------------------------operator<----------------------------------
    // Description: The method operator< overloads the operator <, comparing this
    // classic movie, which is on the left-hand side of the operator <, with the
    // classic movie object on the right-hand side based on their release dates,
    // then their major actors.
    //
    // Post: These two classic movie objects do not change.
    //
    // Param: rhs, which is the classic movie object on the right-hand side.
    //
    // Return: This method returns true if this classic movie was released before
    // the classic movie on the right-hand side. This method also returns true if
    // these two classic movies were released at the same time but the name of the
    // major actor of this classic movie comes before the name of the major actor
    // of the classic movie on the right-hand side with an alphabetical order. This
    // method returns false otherwise.
    bool operator<(const Movie& rhs) const;

    // ---------------------------------operator>----------------------------------
    // Description: The method operator> overloads the operator >, comparing this
    // classic movie, which is on the left-hand side of the operator >, with the
    // classic movie object on the right-hand side based on their release dates,
    // then their major actors.
    //
    // Post: These two classic movie objects do not change.
    //
    // Param: rhs, which is the classic movie object on the right-hand side.
    //
    // Return: This method returns true if this classic movie was released after
    // the classic movie on the right-hand side. This method also returns true if
    // these two classic movies were released at the same time but the name of the
    // major actor of this classic movie comes after the name of the major actor
    // of the classic movie on the right-hand side with an alphabetical order. This
    // method returns false otherwise.
    bool operator>(const Movie& rhs) const;

    // ---------------------------------operator<<----------------------------------
    // Description: The method operator<< overloads the operator <<, displaying the
    // classical movie on the right-hand side of the operator << through the ostream
    // object on the left-hand side.
    //
    // Post: This method displayed the classical movie through the ostream object.
    //
    // Param: output, which is the ostream object.
    //
    // Param: rhs, which is the classical movie to display.
    //
    // Return: A reference to the ostream object.
    friend std::ostream& operator<<(std::ostream& output, const Classic& rhs);

    std::string getYear() const;

    std::string getReleaseMoth() const;

    std::string getMajorActor() const;

    // ---------------------------------getSorting---------------------------------
    // Description: The method getSorting gets the sorting attributes of this
    // movie.
    //
    // Post: This movie does not change.
    //
    // Return: An array that stores the sorting attributes of this movie.
    std::string* getSorting() const;

private:
    // The name of the major actor; the name should include the first name and
    // the last name, separated by a white space.
    std::string actorName;

    // The month when this movie was released.
    std::string releaseMonth;
};