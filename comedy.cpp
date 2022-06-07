#include <iostream>
#include <iomanip>
#include "comedy.h"


Comedy::Comedy(std::string title, std::string director, std::string releaseYear, int max) :
Movie(title, director, releaseYear, max) {

}

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

std::ostream& operator<<(std::ostream& output, const Comedy& rhs) {
	std::cout << "Title: " << rhs.getTitle()
              << " Year: " << rhs.getYear() << std::endl;
    return output;
}