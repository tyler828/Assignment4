#pragma once

#include <string>
#include "movie.h"

// -------------------------------- drama.h ----------------------------------
// Programmer Name: Austin Schnarre    Course Section Number: CSS 343 B
// Creation Date: 5/23/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the drama class, a subclass of the
// movie class. The drama class overwrites the comparison operators so that
// the comparison of two drama movies is based on their directors, and then
// their titles.
// ----------------------------------------------------------------------------

class Drama : public Movie
{
public:
    Drama(std::string title, std::string director, std::string releaseYear, int max);
    bool operator<(const Drama& rhs) const;
    bool operator>(const Drama& rhs) const;
    friend std::ostream& operator<<(std::ostream& output, const Drama& rhs);

    std::string getDirector() const;
    std::string getTitle() const;
private:
   
};
