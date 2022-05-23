#pragma once

#include "movie.h"

// ---------------------------- movie_collection.h ----------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/21/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the movie collection class. The
// movie collection class contains a certain category of movie. The client can
// insert a certain category of movie into a movie collection object, retrieve
// a movie in the movie collection, and display all movies in the movie
// collection.
// ----------------------------------------------------------------------------

class MovieCollection
{
public:
    MovieCollection();

    ~MovieCollection();

    void insert(Movie* movie);

    Movie* retrieve(const Movie& target) const;
    
    void inOrderTraversal() const;

private:
    struct Node
    {
        Node* left;
        Node* right;
        Movie* nodeMovie;

        Node() : left(nullptr), right(nullptr), nodeMovie(nullptr)
        {

        }
    };
    
    Node* root;
};
