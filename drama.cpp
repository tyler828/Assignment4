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
    rhs.print(output);
    return output;
}

void Drama::print(std::ostream& output) const {
    output << "Director: " << getDirector()
           << " Title: " << getTitle() << std::endl;
}

// ---------------------------------getSorting---------------------------------
// Description: The method getSorting gets the sorting attributes of this
// movie.
//
// Post: This movie does not change.
//
// Return: An array that stores the sorting attributes of this movie.
std::string* Drama::getSorting() const
{
    std::string* sorting = new std::string[2];
    sorting[0] = this->director;
    sorting[1] = this->title;
    return sorting;
}