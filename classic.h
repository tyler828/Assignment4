#pragma once

#include <string>
#include "movie.h"

// -------------------------------- classic.h ----------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/19/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the classic class, a subclass of the
// movie class. The classic class overwrites the comparison operators so that
// the comparison of two classic movies is based on their titles, then the years
// they were released.
// ----------------------------------------------------------------------------

class Classic : public Movie
{
public:
    Classic(std::string title, std::string director, std::string releaseYear, int max);

    bool operator<(Classic& rhs) const;

    bool operator>(Classic& rhs) const;
private:
    std:: string actorName;
    
    std:: string releaseMonth;

};
