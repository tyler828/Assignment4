#include <iostream>

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
        delete root;
    }
} // end of the method emptyHelper

// -----------------------------------insert-----------------------------------
// Description: The method insert adds the specified movie into this movie
// collection.
//
// Pre: The specified movie and the movies in this movie collection must be in
// the same category.
//
// Post: This method added the specified movie to this movie collection. The
// binary search tree, the data structure of this movie collection, maintains
// the properties of a binary search tree.
//
// Param: movie, the movie to insert.
//
// Return: True if a new node is inserted into this movie collection for the
// specified movie; false if the specified movie already exits in this movie
// collection and a new node is not inserted.
bool MovieCollection::insert(Movie* movie)
{
    return insertHelper(root, movie);
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
//
// Return: True if a new node is inserted into this subtree for the specified
// movie; false if the specified movie already exits in this subtree and a new
// node is not inserted.
bool MovieCollection::insertHelper(Node*& root, Movie* movie)
{
    // If the given node is a null pointer, replace the null pointer with a new
    // node that contains the given movie.
    if (root == nullptr)
    {
        root = new Node();
        root -> nodeMovie = movie;
        return true;
    }
    // If the movie in the given node is greater than the given movie, add the
    // given movie to the left subtree.
    else if (*(root -> nodeMovie) > *movie)
    {
        return insertHelper(root -> left, movie);
    }
    // If the movie in the given node is smaller than the given movie, add the
    // given movie to the right subtree.
    else if (*(root -> nodeMovie) < *movie)
    {
        return insertHelper(root -> right, movie);
    }
    // If the movie in the given node is the same as the given movie, update the
    // stock of this movie.
    else
    {
        root -> nodeMovie -> max += movie -> max;
        root -> nodeMovie -> stock += movie -> stock;
        return false;
    }
} // end of the method insertHelper

// ----------------------------------retrieve-----------------------------------
// Description: The method retrieve searches this movie collection for the
// specified movie.
//
// Pre: The specified movie and the movies in this movie collection must be in
// the same category.
//
// Post: This movie collection does not change.
//
// Param: target, the movie to retrieve.
//
// Return: A pointer to the specified movie if the specified movie is retrieved
// from this movie collection; a null pointer otherwise.
Movie* MovieCollection::retrieve(const Movie& target) const
{
    return retrieveHelper(root, target);
} // end of the method retrieve

// -------------------------------retrieveHelper-------------------------------
// Description: The method retrieveHelper is the helper method of the method
// retrieve, searching the subtree whose root node is the given node for the
// specified movie.
//
// Pre: The given node should be a node of the binary search tree that contains
// the movie objects of this movie collection. The specified movie and the
// movies in this movie collection must be in the same category.
//
// Post: This subtree does not change.
//
// Param: root, the root node of the subtree to search.
//
// Param: target, the movie to retrieve.
//
// Return: A pointer to the specified movie if the specified movie is retrieved
// from this subtree; a null pointer otherwise.
Movie* MovieCollection::retrieveHelper(Node* root, const Movie& target) const
{
    // If the given node is a null pointer, return a null pointer since the
    // specified movie does not exist in this subtree.
    if (root == nullptr)
    {
        return nullptr;
    }
    // If the movie in the given node is greater than the specified movie,
    // retrieve the specified movie from the left subtree.
    else if (*(root -> nodeMovie) > target)
    {
        return retrieveHelper(root -> left, target);
    }
    // If the movie in the given node is smaller than the specified movie,
    // retrieve the specified movie from the right subtree.
    else if (*(root -> nodeMovie) < target)
    {
        return retrieveHelper(root -> right, target);
    }
    // If the movie in the given node is the same as the specified movie,
    // return the pointer to the movie in the given node.
    else
    {
        return root -> nodeMovie;
    }
} // end of the method retrieveHelper

// ------------------------------inOrderTraversal------------------------------
// Description: The method inOrderTraversal displays the movies in this movie
// collection with an in-order traversal.
//
// Post: This method displayed each of the movies in this movie collection
// through the console. This movie collection does not change.
void MovieCollection::inOrderTraversal() const
{
    inOrderHelper(root);
} // end of the method inOrderTraversal

// --------------------------------inOrderHelper-------------------------------
// Description: The method inOrderHelper is the helper method of the method
// inOrderTraversal, displaying each of the movies in the subtree whose root
// node is the given node with an in-order traversal.
//
// Pre: The given node should be a node of the binary search tree that contains
// the movie objects of this movie collection.
//
// Post: This method displayed each of the movies in the subtree whose root
// node is the given node through the console. This subtree does not change.
//
// Param: root, the root node of the subtree to traverse.
void MovieCollection::inOrderHelper(Node* root) const
{
    // Note: This need to be adjusted for the format of the output.

    if (root != nullptr)
    {
        inOrderHelper(root -> left);
        std::cout << (root -> nodeMovie) << std::endl;
        inOrderHelper(root -> right);
    }
} // end of the method inOrderHelper