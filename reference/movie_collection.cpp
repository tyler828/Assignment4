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
// memory that was dynamically allocated to this movie collection (and its
// movie objects).
//
// Post: This movie collection does not exist, and the dynamically allocated
// memory is free.
MovieCollection::~MovieCollection()
{
    empty();
} // end of the method destructor

// ------------------------------------empty-----------------------------------
// Description: The method empty deletes all the movies in this movie
// collection, freeing all the memory that was dynamically allocated to this
// movie collection (and the movie objects).
//
// Post: This movie collection is empty. The dynamically allocated memory is
// free.
void MovieCollection::empty()
{
    emptyHelper(root);
} // end of the method empty

// ----------------------------------emptyHelper-------------------------------
// Description: The method emptyHelper is the helper method of the method
// empty, deleting the subtree whose root node is the given node.
//
// Pre: The given node should be a node of the binary search tree that contains
// the movie objects of this movie collection.
//
// Post: This method deleted the subtree whose root node is the given node.
//
// Param: root, the root node of the subtree to delete.
void MovieCollection::emptyHelper(Node* root)
{
    // If its root node is not a null pointer, delete this subtree.
    if (root != nullptr)
    {
        emptyHelper(root -> left);
        emptyHelper(root -> right);
        delete root -> nodeMovie;
        delete root;
    }
} // end of the method emptyHelper

// -----------------------------------insert-----------------------------------
// Description: The method insert adds the specified movie into this movie
// collection.
//
// Pre: The specified movie and the movies in this movie collection must be of
// the same category.
//
// Post: This method added the specified movie to this movie collection. The
// binary search tree, the data structure of this movie collection, maintains
// the properties of a binary search tree.
//
// Param: movie, the movie to insert.
void MovieCollection::insert(Movie* movie)
{
    insertHelper(root, movie);
} // end of the method insert

// --------------------------------insertHelper--------------------------------
// Description: The method insertHelper is the helper method of the method
// insert, adding the given movie to the subtree whose root node is the given
// node.
//
// Pre: The given node should be a node of the binary search tree that contains
// the movie objects of this movie collection.
//
// Post: This method added the given movie to the subtree whose root node is
// the given node.
//
// Param: root, the root node of the subtree.
//
// Param: movie, the movie to insert.
void MovieCollection::insertHelper(Node*& root, Movie* movie)
{
    // If the given node is a null pointer, replace the null pointer with a new
    // node that contains the given movie.
    if (root == nullptr)
    {
        root = new Node();
        root -> nodeMovie = movie;
    }
    // If the movie in the given node is greater than the given movie, add the
    // given movie to the left subtree.
    else if (*(root -> nodeMovie) > *movie)
    {
        insertHelper(root -> left, movie);
    }
    // If the movie in the given node is smaller than the given movie, add the
    // given movie to the right subtree.
    else if (*(root -> nodeMovie) < *movie)
    {
        insertHelper(root -> right, movie);
    }
    // If the movie in the given node is the same as the given movie, update the
    // stock of this movie.
    else
    {
        root -> nodeMovie -> max += movie -> max;
        root -> nodeMovie -> stock += movie -> stock;
    }
} // end of the method insertHelper