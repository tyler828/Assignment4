#include "movie_collection.h"

// --------------------------- movie_collection.cpp ---------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 5/28/2022
// Date of Last Modification:
//
// Purpose: This file is the implementation file of the MovieCollection class.
// The MovieCollection class contains a certain category of movie. The client
// can insert a certain category of movie into a MovieCollection object,
// retrieve a movie in the movie collection, and display all movies in the
// movie collection.
// ----------------------------------------------------------------------------


// ------------------------------Default Constructor---------------------------
// Description: The default constructor creates an empty movie collection.
//
// Post: An empty movie collection exists. That is, a movie collection object
// whose root pointer is a null pointer exists.
MovieCollection::MovieCollection() : root(nullptr)
{

} // end of the default constructor

// ---------------------------------Destructor---------------------------------
// Description: The destructor deletes this movie collection, freeing all the
// memory that was dynamically allocated to this movie collection.
//
// Post: This movie collection does not exist, and the dynamically allocated
// memory is free.
MovieCollection::~MovieCollection()
{

}