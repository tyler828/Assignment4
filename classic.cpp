#include <iostream>
#include <iomanip>
#include "classic.h"


Classic::Classic(std::string title, std::string director, std::string releaseYear, std::string releaseMonth, std::string actorName, int max) :
        Movie(title, director, releaseYear, max), actorName(actorName), releaseMonth(releaseMonth) {


}

bool Classic::operator<(const Classic& rhs) const {
	if (this->releaseYear < rhs.releaseYear) {
		return true;
	}

	if (this->releaseYear == rhs.releaseYear) {
        if (this->releaseMonth < rhs.releaseMonth) {
            return true;
        }

        if (this->releaseMonth == rhs.releaseMonth) {
            if (this->actorName < rhs.actorName) {
                return true;
            }
        }
	}

	return false;

}

bool Classic::operator>(const Classic& rhs) const {
    if (this->releaseYear > rhs.releaseYear) {
        return true;
    }

    if (this->releaseYear == rhs.releaseYear) {
        if (this->releaseMonth > rhs.releaseMonth) {
            return true;
        }

        if (this->releaseMonth == rhs.releaseMonth) {
            if (this->actorName > rhs.actorName) {
                return true;
            }
        }
    }

    return false;

}

std::string Classic::getReleaseMoth() const {
	return releaseMonth;
}

std::string Classic::getYear() const {
	return releaseYear;
}

std::string Classic::getMajorActor() const {
	return actorName;
}

std::ostream& operator<<(std::ostream& output, const Classic& rhs) {
	output << "Release Month: " << rhs.getReleaseMoth() << " Year: " << rhs.getYear() << " Major Actor: "
           << rhs.getMajorActor() << std::endl;
    return output;

}