#include <iostream>
#include <iomanip>
#include "movie.h"



Movie::Movie(std::string title, std::string director, std::string releaseYear, int max) {
	this->title = title;
	this->director = director;
	this->releaseYear = releaseYear;
	this->max = max;

}




friend std::ostream& Movie::operator<<(std::ostream& output, const Movie& rhs) {
	rhs.printMovie();       //make virtual print movies in .cpps
	return stream;

}


S