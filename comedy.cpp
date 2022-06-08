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

// ---------------------------------getSorting---------------------------------
// Description: The method getSorting gets the sorting attributes of this
// movie.
//
// Post: This movie does not change.
//
// Return: An array that stores the sorting attributes of this movie.
std::string* Comedy::getSorting() const
{
    std::string* sorting = new std::string[2];
    sorting[0] = this->title;
    sorting[1] = this->releaseYear;
    return sorting;
}