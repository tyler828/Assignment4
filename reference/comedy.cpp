#include <iostream>
#include <iomanip>
#include "comedy.h"

// --------------------------Parametrized Constructor--------------------------
// Description: The parametrized constructor creates a comedy movie object
// based on the given title, director, release year, and maximum stock.
//
// Pre: The given information must correctly represent the comedy movie.
//
// Post: A comedy movie object that has the given title, director, release
// year, and maximum stock exists. The current stock is initialized to the
// maximum stock.
//
// Param: title, the title of the comedy movie.
//
// Param: director, the director of the comedy movie.
//
// Param: releaseYear, the year when the comedy movie was released.
//
// Param: max, the maximum stock of the comedy movie.
Comedy::Comedy(std::string title, std::string director, std::string releaseYear, int max) :
        Movie(title, director, releaseYear, max) {

}

// ---------------------------------operator<----------------------------------
// Description: The method operator< overloads the operator <, comparing this
// comedy movie, which is on the left-hand side of the operator <, with the
// comedy movie object on the right-hand side based on their titles, then the
// years they were released.
//
// Post: These two comedy movie objects do not change.
//
// Param: rhs, which is the comedy movie object on the right-hand side.
//
// Return: This method returns true if the title of this comedy movie comes
// before the title of the comedy movie on the right-hand side with an
// alphabetical order. This method also returns true if these two comedy movies
// have the same title but this comedy movie was released before the other
// one. This method returns false otherwise.
bool Comedy::operator<(const Comedy& rhs) const {
    if (this->title < rhs.title) {
        return true;
    }

    if (this->title == rhs.title) {
        if (this->releaseYear < rhs.releaseYear) {
            return true;
        }
    }

    return false;

}

// ---------------------------------operator>----------------------------------
// Description: The method operator> overloads the operator >, comparing this
// comedy movie, which is on the left-hand side of the operator >, with the
// comedy movie object on the right-hand side based on their titles, then the
// years they were released.
//
// Post: These two comedy movie objects do not change.
//
// Param: rhs, which is the comedy movie object on the right-hand side.
//
// Return: This method returns true if the title of this comedy movie comes
// after the title of the comedy movie on the right-hand side with an
// alphabetical order. This method also returns true if these two comedy movies
// have the same title but this comedy movie was released after the other
// one. This method returns false otherwise.
bool Comedy::operator>(const Comedy& rhs) const {
    if (this->title > rhs.title) {
        return true;
    }

    if (this->title == rhs.title) {
        if (this->releaseYear > rhs.releaseYear) {
            return true;
        }
    }

    return false;

}



std::string Comedy::getTitle() const {
    return title;
}

std::string Comedy::getYear() const {
    return releaseYear;
}

// ---------------------------------operator<<----------------------------------
// Description: The method operator<< overloads the operator <<, displaying the
// comedy movie on the right-hand side of the operator << through the ostream
// object on the left-hand side.
//
// Post: This method displayed the comedy movie through the ostream object.
//
// Param: output, which is the ostream object.
//
// Param: rhs, which is the comedy movie to display.
//
// Return: A reference to the ostream object.
std::ostream& operator<<(std::ostream& output, const Comedy& rhs) {
    std::cout << "Title: " << rhs.getTitle()
              << " Year: " << rhs.getYear() << std::endl;
    return output;
}