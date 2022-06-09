#include <iostream>
#include <iomanip>
#include "classic.h"

// --------------------------Parametrized Constructor--------------------------
// Description: The parametrized constructor creates a classic movie object
// based on the given title, director, release year, release month, actor,
// and maximum stock.
//
// Pre: The given information must correctly represent the classic movie.
//
// Post: A classic movie object that has the given title, director, release
// year, release month, actor, and maximum stock exists. The current stock is
// initialized to the maximum stock.
//
// Param: title, the title of the classic movie.
//
// Param: director, the director of the classic movie.
//
// Param: releaseYear, the year when the classic movie was released.
//
// Param: releaseMonth, the month when the classic movie was released.
//
// Param: actor, the major actor of the classic movie.
//
// Param: max, the maximum stock of the movie.
Classic::Classic(std::string title, std::string director, std::string releaseYear, std::string releaseMonth, std::string actorName, int max) :
        Movie(title, director, releaseYear, max), actorName(actorName), releaseMonth(releaseMonth) {


}

// ---------------------------------operator<----------------------------------
// Description: The method operator< overloads the operator <, comparing this
// classic movie, which is on the left-hand side of the operator <, with the
// classic movie object on the right-hand side based on their release dates,
// then their major actors.
//
// Post: These two classic movie objects do not change.
//
// Param: rhs, which is the classic movie object on the right-hand side.
//
// Return: This method returns true if this classic movie was released before
// the classic movie on the right-hand side. This method also returns true if
// these two classic movies were released at the same time but the name of the
// major actor of this classic movie comes before the name of the major actor
// of the classic movie on the right-hand side with an alphabetical order. This
// method returns false otherwise.
bool Classic::operator<(const Movie& rhs) const {
    std::string* thisSorting = getSorting();
    std::string* rhsSorting = rhs.getSorting();
    bool result = false;

    if (thisSorting[0] < rhsSorting[0]) {
        result = true;
    }

    if (thisSorting[0] == rhsSorting[0]) {
        if (thisSorting[1] < rhsSorting[1]) {
            result = true;
        }

        if (thisSorting[1] == rhsSorting[1]) {
            if (thisSorting[2] < rhsSorting[2]) {
                result = true;
            }
        }
    }

    delete[] thisSorting;
    delete[] rhsSorting;

    return result;

}

// ---------------------------------operator>----------------------------------
// Description: The method operator> overloads the operator >, comparing this
// classic movie, which is on the left-hand side of the operator >, with the
// classic movie object on the right-hand side based on their release dates,
// then their major actors.
//
// Post: These two classic movie objects do not change.
//
// Param: rhs, which is the classic movie object on the right-hand side.
//
// Return: This method returns true if this classic movie was released after
// the classic movie on the right-hand side. This method also returns true if
// these two classic movies were released at the same time but the name of the
// major actor of this classic movie comes after the name of the major actor
// of the classic movie on the right-hand side with an alphabetical order. This
// method returns false otherwise.
bool Classic::operator>(const Movie& rhs) const {
    std::string* thisSorting = getSorting();
    std::string* rhsSorting = rhs.getSorting();
    bool result = false;

    if (thisSorting[0] > rhsSorting[0]) {
        result = true;
    }

    if (thisSorting[0] == rhsSorting[0]) {
        if (thisSorting[1] > rhsSorting[1]) {
            result = true;
        }

        if (thisSorting[1] == rhsSorting[1]) {
            if (thisSorting[2] > rhsSorting[2]) {
                result = true;
            }
        }
    }

    delete[] thisSorting;
    delete[] rhsSorting;

    return result;

}

// ---------------------------------operator<<----------------------------------
// Description: The method operator<< overloads the operator <<, displaying the
// classical movie on the right-hand side of the operator << through the ostream
// object on the left-hand side.
//
// Post: This method displayed the classical movie through the ostream object.
//
// Param: output, which is the ostream object.
//
// Param: rhs, which is the classical movie to display.
//
// Return: A reference to the ostream object.
std::ostream& operator<<(std::ostream& output, const Classic& rhs) {
    rhs.print();
    return output;

}

void Classic::print() const {
    std::cout << stock << " " << director << " " 
              << title << " " << actorName << " "
              << releaseMonth << " " << releaseYear << std::endl;
}

// ---------------------------------getSorting---------------------------------
// Description: The method getSorting gets the sorting attributes of this
// movie.
//
// Post: This movie does not change.
//
// Return: An array that stores the sorting attributes of this movie.
std::string* Classic::getSorting() const
{
    std::string* sorting = new std::string[3];
    sorting[0] = this->releaseYear;
    sorting[1] = this->releaseMonth;
    sorting[2] = this->actorName;
    return sorting;
}

std::string Classic::getReleaseMonth() const {
    return this->releaseMonth;
}

std::string Classic::getMajorActor() const {
    return this->actorName;
}