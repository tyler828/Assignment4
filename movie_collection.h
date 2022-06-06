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
    bool insert(Movie* movie);

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
    // Pre: The given node should be a node of the binary search tree that contains
    // the movie objects of this movie collection.
    //
    // Post: This method deleted the subtree whose root node is the given node.
    //
    // Param: root, the root node of the subtree to delete.
    void emptyHelper(Node* root);

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
    bool insertHelper(Node*& root, Movie* movie);

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
    Movie* retrieveHelper(Node* root, const Movie& target) const;

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
    void inOrderHelper(Node* root) const;
};