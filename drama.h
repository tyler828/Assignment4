#pragma once

#include <string>
#include "movie.h"

// -------------------------------- drama.h ----------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/19/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the drama class, a subclass of the
// movie class. The drama class overwrites the comparison operators so that
// the comparison of two drama movies is based on their titles, then the years
// they were released.
// ----------------------------------------------------------------------------

class Drama : public Movie
{
public:
    Drama(std::string title, std::string director, std::string releaseYear, int max);

    bool operator<(Drama& rhs) const;

    bool operator>(Drama& rhs) const;
private:

};
