#pragma once

#include <string>
#include <iostream>
#include <math.h>

#include "media.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "movie_collection.h"
#include "table.h"

// ----------------------------------- dvd.h ----------------------------------
// Programmer Name: Tyler Schmale     Course Section Number: CSS 343 B
// Creation Date: 5/21/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the DVD class, a subclass of the
// media class. The DVD class represents the movie DVDs that are available at a
// media rental or retail store. This class allows the client to add new movie
// DVDs to the inventory of the store, update the inventory when a DVD is
// borrowed or returned, and display all the movie DVDs in the inventory of
// the store.

class DVD : public Media
{
public:
    DVD();

    bool addItem(std::string movieToAdd);

    Movie* borrowItem(std::string movieBorrowed);
    
    Movie* returnItem(std::string movieReturned);

    void displayAllItems();

private:
    MyTable<int, MovieCollection> orderedCollection;
    
    MyTable<int, Movie> movieTable;

    int stringToKey(std::string line);
};
