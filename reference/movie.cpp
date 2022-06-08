#include <string>
#include <iostream>
#include "movie.h"

// ------------------------------Default Constructor---------------------------
// Description: The default constructor creates an empty movie object.
//
// Post: An empty movie object exists.
Movie::Movie()
{

} // end of the default constructor

// --------------------------Parametrized Constructor--------------------------
// Description: The parametrized constructor creates a movie object based on
// the given title, director, release year, and maximum stock.
//
// Pre: The given information must correctly represent the movie.
//
// Post: A movie object that has the given title, director, release year, and
// maximum stock exists. The current stock is initialized to the maximum stock.
//
// Param: title, the title of the movie.
//
// Param: director, the director of the movie.
//
// Param: releaseYear, the year when the movie was released.
//
// Param: max, the maximum stock of the movie.
Movie::Movie(std::string title, std::string director, std::string releaseYear, int max) {
    this->title = title;
    this->director = director;
    this->releaseYear = releaseYear;
    this->max = max;
    this->stock = max;
}

// ---------------------------------operator<----------------------------------
// Description: The method operator< overloads the operator <, comparing this
// movie, which is on the left-hand side of the operator <, with the movie
// object on the right-hand side.
//
// Post: These two movie objects do not change.
//
// Param: rhs, which is the movie object on the right-hand side.
//
// Return: True if this movie is less than the movie on the right-hand side;
// false otherwise.
bool Movie::operator<(const Movie& rhs) const
{
    std::string* thisSorting = getSorting();
    std::string* rhsSorting = rhs.getSorting();
    bool result = false;

    // Compare the first attribute.
    if (thisSorting[0] < rhsSorting[0]) {
        result = true;
    }

    // Compare the second attribute.
    if (thisSorting[0] == rhsSorting[0]) {
        if (thisSorting[1] < rhsSorting[1]) {
            result = true;
        }
    }

    delete[] thisSorting;
    delete[] rhsSorting;

    return result;
}

// ---------------------------------operator>----------------------------------
// Description: The method operator> overloads the operator >, comparing this
// movie, which is on the left-hand side of the operator >, with the movie
// object on the right-hand side.
//
// Post: These two movie objects do not change.
//
// Param: rhs, which is the movie object on the right-hand side.
//
// Return: True if this movie is greater than the movie on the right-hand side;
// false otherwise.
bool Movie::operator>(const Movie& rhs) const
{
    std::string* thisSorting = getSorting();
    std::string* rhsSorting = rhs.getSorting();
    bool result = false;

    // Compare the first attribute.
    if (thisSorting[0] > rhsSorting[0]) {
        result = true;
    }

    // Compare the second attribute.
    if (thisSorting[0] == rhsSorting[0]) {
        if (thisSorting[1] > rhsSorting[1]) {
            result = true;
        }
    }

    delete[] thisSorting;
    delete[] rhsSorting;

    return result;
}

// ---------------------------------operator<<----------------------------------
// Description: The method operator<< overloads the operator <<, displaying the
// movie on the right-hand side of the operator << through the ostream
// object on the left-hand side.
//
// Post: This method displayed the movie through the ostream object.
//
// Param: output, which is the ostream object.
//
// Param: rhs, which is the movie to display.
//
// Return: A reference to the ostream object.
std::ostream& operator<<(std::ostream& output, const Movie& rhs) {
    rhs.print(output);
    return output;
}

// -----------------------------------print------------------------------------
// Description: The method print displays this movie through the given ostream
// object.
//
// Post: This method displayed this movie through the given ostream object;
// this movie does not change.
//
// Param: output, an ostream object
void Movie::print(std::ostream& output) const {
    output << "Title: " << this->title << std::endl;
} // end of the method print

// ---------------------------------getSorting---------------------------------
// Description: The method getSorting gets the sorting attributes of this
// movie.
//
// Post: This movie does not change.
//
// Return: An array that stores the sorting attributes of this movie.
std::string* Movie::getSorting() const
{
    std::string* sorting = new std::string[2];
    sorting[0] = this->max;
    sorting[1] = this->stock;
    return sorting;
} // end of the method getSorting