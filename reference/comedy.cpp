#include <iostream>
#include <iomanip>
#include "comedy.h"


Comedy::Comedy(std::string title, std::string director, std::string releaseYear, int max) {
    this->title = title;
    this->director = director;
    this->releaseYear = releaseYear;
    this->max = max;

}

bool Comedy::operator<(Comedy& rhs) const {
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

bool Comedy::operator>(Comedy& rhs) const {
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



std::string Comedy::getTitle() {
    return title;
}

std::string Comedy::getYear() {
    return releaseYear;
}

friend std::ostream& Comedy::operator<<(std::ostream& output, const Comedy& rhs) {
    cout << "Title: " << getTitle() << " Year: " << getYear() << endl;

}
