#pragma once

#include <string>

// --------------------------------- movie.h ----------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/19/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the Movie class. The Movie class
// stores the title, the director, and the release year of a movie that is
// available at a rental or retail store. Most importantly, the Movie class
// stores the maximum stock and the remaining stock of the movie. The Movie
// class also overloads the comparison operators for the comparison of two
// movies.
// ----------------------------------------------------------------------------

class Movie
{
public:
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
    Movie(std::string title, std::string director, std::string releaseYear, int max);

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
    virtual bool operator<(const Movie& rhs) const = 0;

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
    virtual bool operator>(const Movie& rhs) const = 0;

    // ---------------------------------operator<<----------------------------------
    // Description: The method operator<< overloads the operator <<, displaying the
    // movie on the right-hand side of the operator << through the ostream object
    // on the left-hand side.
    //
    // Post: This method displayed the movie through the ostream object.
    //
    // Param: output, which is the ostream object.
    //
    // Param: rhs, which is the movie to display.
    //
    // Return: A reference to the ostream object.
    friend std::ostream& operator<<(std::ostream& output, const Movie& rhs);

private:

protected:
    // The title of this movie.
    std::string title;

    // The director of this movie.
    std::string director;

    // The year when this movie was released.
    std::string releaseYear;

    // The maximum stock of this movie.
    int max;

    // The current stock of this movie.
    int stock;

    friend class DVD;

    friend class MovieCollection;
};
