#include <iostream>
#include <iomanip>
#include "drama.h"

Drama::Drama(std::string title, std::string director, std::string releaseYear, int max) {
	this->title = title;
	this->director = director;
	this->releaseYear = releaseYear;
	this->max = max;
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

std::string Drama::getDirector() {
	return director;

}

std::string Drama::getTitle() {
	return title;
}

friend std::ostream& Drama::operator<<(std::ostream& output, const Drama& rhs) {
	cout << "Director: " << Drama::getDirector() << " Title: " << Drama::getTitle() << endl;
}