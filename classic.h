#pragma once

#include <string>
#include "movie.h"

// -------------------------------- classic.h ----------------------------------
// Programmer Name: Austin Schnarre     Course Section Number: CSS 343 B
// Creation Date: 5/23/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the classic class, a subclass of the
// movie class. The classic class overwrites the comparison operators so that
// the comparison of two classic movies is based on the dates when they were
// released and their major actors.
// ----------------------------------------------------------------------------

class Classic : public Movie
{
public:
    Classic(std::string title, std::string director, std::string releaseYear, std::string releaseMonth, std::string actorName, int max);
    bool operator<(const Classic& rhs) const;
    bool operator>(const Classic& rhs) const;
    friend std::ostream& operator<<(std::ostream& output, const Classic& rhs);

    std::string getYear() const;
    std::string getReleaseMoth() const;
    std::string getMajorActor() const;

private:
    std:: string actorName;
    std:: string releaseMonth;
};
