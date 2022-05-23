#include <string>

#include "dvd.h"

// --------------------------------- dvd.cpp ----------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/22/2022
// Date of Last Modification:
//
// Purpose: This file is the implementation file of the DVD class, a subclass
// of the media class. The DVD class represents the movie DVDs that are
// available at a media rental or retail store. This class allows the client to
// add new movie DVDs to the inventory of the store, update the inventory when
// a DVD is borrowed or returned, and display all the movie DVDs in the
// inventory of the store.

DVD::DVD()
{

}

bool DVD::addItem(std::string movieToAdd)
{
    // Pseudo Code
    //
    // Parse the given string and identify the category of the movie to add.
    // if the category is F, D, or C
    // {
    //     Create a movie object based on the given string.
    //     Call the insert method on the movie collection that contains this
    //     category of movie. Pass the movie object as the parameter.
    //     Return true.
    // }
    // else
    // {
    //     Display an error message.
    //     Return false.
    // }
}

bool DVD::borrowItem(std::string movieBorrowed)
{
    // Pseudo Code
    //
    // Parse the given string and identify the category of the movie to borrow.
    // if the category is F, D, or C
    // {
    //     Create a movie object based on the given string.
    //     Call the retrieve method on the movie collection that contains this
    //     category of movie. Pass the movie object as the parameter.
    //     if the pointer returned by the retrieve method is not a null pointer
    //     {
    //         if there is at least one movie DVD in stock
    //         {
    //             Decrease the stock of this movie by one.
    //             Return true.
    //         {
    //         else
    //         {
    //             Display an error message.
    //             Return false.
    //         }
    //     }
    //     else
    //     {
    //         Display an error message.
    //         Return false.
    //     }
    // }
    // else
    // {
    //     Display an error message.
    //     Return false.
    // }
}

bool DVD::returnItem(std::string movieReturned)
{
    // Pseudo Code
    //
    // Parse the given string and identify the category of the movie to return.
    // if the category is F, D, or C
    // {
    //     Create a movie object based on the given string.
    //     Call the retrieve method on the movie collection that contains this
    //     category of movie. Pass the movie object as the parameter.
    //     if the pointer returned by the retrieve method is not a null pointer
    //     {
    //         if the number of the movie DVDs in stock is less than the
    //         maximum number
    //         {
    //             Increase the stock of this movie by one.
    //             Return true.
    //         {
    //         else
    //         {
    //             Display an error message.
    //             Return false.
    //         }
    //     }
    //     else
    //     {
    //         Display an error message.
    //         Return false.
    //     }
    // }
    // else
    // {
    //     Display an error message.
    //     Return false.
    // }
}

void DVD::displayAllItems() const
{
    // Pseudo Code
    //
    // Call the inOrderTraversal method on the movie collection that contains
    // comedy movies.
    // Call the inOrderTraversal method on the movie collection that contains
    // drama movies.
    // Call the inOrderTraversal method on the movie collection that contains
    // classical movies.
}
