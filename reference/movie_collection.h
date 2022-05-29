#pragma once

#include "movie.h"

// ---------------------------- movie_collection.h ----------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 5/21/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the MovieCollection class. The
// MovieCollection class contains a certain category of movie. The client can
// insert a certain category of movie into a MovieCollection object, retrieve
// a movie in the movie collection, and display all movies in the movie
// collection.
// ----------------------------------------------------------------------------

class MovieCollection
{
public:
    // ------------------------------Default Constructor---------------------------
    // Description: The default constructor creates an empty movie collection.
    //
    // Post: An empty movie collection exists. That is, a movie collection object
    // whose root pointer is a null pointer exists.
    MovieCollection();

    // ---------------------------------Destructor---------------------------------
    // Description: The destructor deletes this movie collection, freeing all the
    // memory that was dynamically allocated to this movie collection (and its
    // movie objects).
    //
    // Post: This movie collection does not exist, and the dynamically allocated
    // memory is free.
    ~MovieCollection();

    // ------------------------------------empty-----------------------------------
    // Description: The method empty deletes all the movies in this movie
    // collection, freeing all the memory that was dynamically allocated to this
    // movie collection (and the movie objects).
    //
    // Post: This movie collection is empty. The dynamically allocated memory is
    // free.
    void empty();

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
    void insert(Movie* movie);

    // ----------------------------------retrieve-----------------------------------
    // Description: The method retrieve searches this movie collection for the
    // specified movie.
    //
    // Pre: The specified movie and the movies in this movie collection must be of
    // the same category.
    //
    // Post: This movie collection does not change.
    //
    // Param: target, the movie to retrieve.
    //
    // Return: A pointer to the specified movie if the specified movie is retrieved
    // from this movie collection; a null pointer otherwise.
    Movie* retrieve(const Movie& target) const;

    // ------------------------------inOrderTraversal------------------------------
    // Description: The method inOrderTraversal displays the movies in this movie
    // collection with an in-order traversal.
    //
    // Post: This method displayed each of the movies in this movie collection
    // through the console. This movie collection does not change.
    void inOrderTraversal() const;

private:
    // The node struct represents a node in the binary search tree that contains a
    // certain category of movie.
    struct Node
    {
        Node* left;
        Node* right;
        Movie* nodeMovie;

        Node() : left(nullptr), right(nullptr), nodeMovie(nullptr)
        {

        }
    };

    // The pointer to the root of the binary search tree that contains a certain
    // category of movie.
    Node* root;

    // ----------------------------------emptyHelper-------------------------------
    // Description: The method emptyHelper is the helper method of the method
    // empty, deleting the subtree whose root node is the given node.
    //
    // Pre: The given node is a node of the binary search tree that contains the
    // movie objects of this movie collection.
    //
    // Post: This method deleted the subtree whose root node is the given node.
    //
    // Param: root, the root node of the subtree to delete.
    void emptyHelper(Node* root);
};