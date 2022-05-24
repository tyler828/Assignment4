#include <string>

#include "dvd.h"

// --------------------------------- dvd.cpp ----------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/22/2022
// Date of Last Modification:
//
// Purpose: This file is the implementation file of the DVD class, a subclass
// of the Media class. The DVD class represents the movie DVDs that are
// available at a media rental or retail store. This class allows the client to
// add new movie DVDs to the inventory of the store, update the inventory when
// a DVD is borrowed or returned, and display all the movie DVDs in the
// inventory of the store.


// ------------------------------Default Constructor---------------------------
// Description: The default constructor creates an DVD object that contains
// three movie collections: comedy movies, dramas, and classics.
//
// Post: An DVD object that contains three empty collections for comedy movies,
// dramas, and classics exists. The characters F, D, and C are mapped to comedy
// movies, dramas, and classics, respectively.
DVD::DVD()
{

}

// -----------------------------------addItem----------------------------------
// Description: The method addItem adds movie DVDs to the inventory according
// to the given string.
//
// Pre: The given string must be of a specific format that indicates what
// movie DVDs should be added. For comedy movies and drama movies, the format
// must be the following: Character(F or D), Stock, Director, Title, Year it
// released. For classical movies, the format must be the following: C, Stock,
// Director, Title, Major actor(first last) Release date(month year).
//
// Post: This method added the movie DVDs indicated by the given string to
// the inventory of the store. If the given string is invalid, this method
// will not add anything to the inventory and will display an error message
// through the console.
//
// Param: movieToAdd, which is the string that indicates what movie DVDs to
// add.
//
// Return: True if the movie DVDs are successfully added; false otherwise.
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

// ---------------------------------borrowItem---------------------------------
// Description: The method borrowItem updates the inventory for a movie DVD
// borrowed by a customer of the store.
//
// Pre: The given string must be of a specific format that indicates what
// movie DVD is borrowed. For comedy movies, the format must be the following:
// F Title, Year it released. For drama movies, the format must be the
// following: D Director, Title,. For classical movies, the format must be the
// following: C Release date(month year) Major actor(first last). Additionally,
// the movie DVD to borrow cannot be out of stock.
//
// Post: This method updated the inventory of the store according to the given
// string. If the given string is invalid or the movie DVD to borrow is out of
// stock, this method will not update the inventory and will display an error
// message through the console.
//
// Param: movieBorrowed, which is the string that indicates what movie DVD is
// borrowed.
//
// Return: True if the update is successful and the movie DVD is successfully
// borrowed; false otherwise.
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
    //     (Alternatively, access the movie object through the hash table.)
    //
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

// ---------------------------------returnItem---------------------------------
// Description: The method returnItem updates the inventory for a movie DVD
// returned to the store by a customer.
//
// Pre: The given string must be of a specific format that indicates what
// movie DVD is returned. For comedy movies, the format must be the following:
// F Title, Year it released. For drama movies, the format must be the
// following: D Director, Title,. For classical movies, the format must be the
// following: C Release date(month year) Major actor(first last). Additionally,
// returning a movie DVD must not make the number of the same movie DVDs in the
// stock exceed the maximum number.
//
// Post: This method updated the inventory of the store according to the given
// string. If the given string is invalid or returning the movie DVD would make
// the number of the same movie DVDs in the stock exceed the maximum number,
// this method will not update the inventory and will display an error message
// through the console.
//
// Param: movieReturned, which is the string that indicates what movie DVD is
// returned.
//
// Return: True if the update is successful and the movie DVD is successfully
// returned; false otherwise.
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
    //     (Alternatively, access the movie object through the hash table.)
    //
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

// ------------------------------displayAllItems-------------------------------
// Description: The method displayAllItems displays the movie DVDs that are in
// the inventory of the store.
//
// Post: This method displayed the movie DVDs in the inventory of the store
// through the console with the following order: comedy movies, drama movies,
// and then classical movies. This DVD object does not change.
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