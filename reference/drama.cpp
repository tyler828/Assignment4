#include <iostream>
#include <iomanip>
#include "drama.h"

Drama::Drama(std::string title, std::string director, std::string releaseYear, int max) :
Movie(title, director, releaseYear, max) {

}

bool Drama::operator<(Drama& rhs) const {
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

bool Drama::operator>(Drama& rhs) const {
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

std::ostream& operator<<(std::ostream& output, const Drama& rhs) {
    std::cout << "Director: " << rhs.getDirector()
              << " Title: " << rhs.getTitle() << std::endl;
}