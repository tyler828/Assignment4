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
    Comedy(std::string title, std::string director, std::string releaseYear, int max);

    bool operator<(Comedy& rhs) const;

    bool operator>(Comedy& rhs) const;
    
    friend std::ostream& operator<<(std::ostream& output, const Comedy& rhs);
private:

};
