#include "movie.h"

Movie::Movie(std::string title, std::string director, std::string releaseYear, int max) {
	this->title = title;
	this->director = director;
	this->releaseYear = releaseYear;
	this->max = max;

}

bool Movie::operator<(const Movie& rhs) const
{
    return this->stock < rhs.stock;
}

bool Movie::operator>(const Movie& rhs) const
{
    return this->stock > rhs.stock;
}