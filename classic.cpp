#include <iostream>
#include <iomanip>
#include "classic.h"


Classic::Classic(std::string title, std::string director, std::string releaseYear, std::string releaseMonth, std::string actorName, int max) {
	this->title = title;
	this->director = director;
	this->releaseYear = releaseYear;
	this->max = max;
	this->releaseMonth = releaseMonth;
	this->actorName = actorName;

}

bool Classic::operator<(Classic& rhs) const {
	if (this->releaseYear < rhs.releaseYear) {
		return true;
	}

	if (this->releaseYear == rhs.releaseYear) {
		if (this->actorName < rhs.actorName) {
			return true;
		}
	}

	return false;

}

bool Classic::operator>(Classic& rhs) const {
	if (this->releaseYear > rhs.releaseYear) {
		return true;
	}

	if (this->releaseYear == rhs.releaseYear) {
		if (this->actorName > rhs.actorName) {
			return true;
		}
	}

	return false;

}

std::string Classic::getReleaseMoth() {
	return releaseMonth;
}

std::string Classic::getYear() {
	return releaseYear;
}

std::string Classic::getMajorActor() {
	return actorName;
}

friend std::ostream& Classic::operator<<(std::ostream& output, const Classic& rhs) {
	cout << "Release Month: " << getReleaseMoth() << " Year: " << getYear() << " Major Actor: " << getMajorActor() << endl;

}