#pragma once

#include <string>

// --------------------------------- movie.h ----------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/19/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the movie class. The movie class
// stores the title, the director, and the release year of a movie that is
// available at a rental or retail store. Most importantly, the movie class
// stores the maximum stock and the remaining stock of the movie. The movie
// class also overloads the comparison operators for the comparison of two
// movies.
// ----------------------------------------------------------------------------

class Movie
{
public:
    Movie(std::string title, std::string director, std::string releaseYear, int max);

    virtual bool operator<(Movie& rhs) const;

    virtual bool operator>(Movie& rhs) const;
    
    friend std::ostream& operator<<(std::ostream& output, const Movie& rhs);

private:

protected:
    std::string title;

    std::string director;

    std::string releaseYear;

    int max;

    int stock;
    
    friend class DVD;
};
