#include <iostream>
#include <iomanip>
#include "drama.h"

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
Drama::Drama(std::string title, std::string director, std::string releaseYear, int max) :
        Movie(title, director, releaseYear, max) {

}

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
bool Drama::operator<(const Drama& rhs) const {
    if (this->director < rhs.director) {
        return true;
    }

    if (this->director == rhs.director) {
        if (this->title < rhs.title) {
            return true;
        }
    }

    return false;
}

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
bool Drama::operator>(const Drama& rhs) const {
    if (this->director > rhs.director) {
        return true;
    }

    if (this->director == rhs.director) {
        if (this->title > rhs.title) {
            return true;
        }
    }

    return false;
}

std::string Drama::getDirector() const {
    return this->director;

}

std::string Drama::getTitle() const {
    return this->title;
}

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
std::ostream& operator<<(std::ostream& output, const Drama& rhs) {
    output << "Director: " << rhs.getDirector()
           << " Title: " << rhs.getTitle() << std::endl;
    return output;
}