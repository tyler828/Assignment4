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
    //create the three collections, insert them into hash table
    MovieCollection* Classic = new MovieCollection;
    orderedCollection.insert('C', Classic);

    MovieCollection* Comedy = new MovieCollection;
    orderedCollection.insert('F', Comedy);

    MovieCollection* Drama = new MovieCollection;
    orderedCollection.insert('D', Drama);
}

bool DVD::addItem(std::string movieToAdd)
{
    //common attributes
    std::string movieType;
    std::string director;
    std::string title;
    std::string year;
    int stock;

    //classic attributes
    std::string month;
    std::string actor;

    //extract all common attributes
    movieType = movieToAdd.substr(0, movieToAdd.find(","));     //extract movie type
    movieToAdd = movieToAdd.substr(movieToAdd.find(",") + 2);   //cut processed attribute out of string

    stock =  std::stoi(movieToAdd.substr(0, movieToAdd.find(",")));     //extract stock
    movieToAdd = movieToAdd.substr(movieToAdd.find(",") + 2);           //cut processed attribute out of string
    
    director = movieToAdd.substr(0, movieToAdd.find(","));     //extract director
    movieToAdd = movieToAdd.substr(movieToAdd.find(",") + 2);   //cut processed attribute out of string
    
    title = movieToAdd.substr(0, movieToAdd.find(","));     //extract movie name
    movieToAdd = movieToAdd.substr(movieToAdd.find(",") + 2);   //cut processed attribute out of string

    switch(movieType[0])
    {
        case('C') : //classic

            //parse classic-specific attributes
            actor = movieToAdd.substr(0, (movieToAdd.find(" ") + 1) + movieToAdd.substr(movieToAdd.find(" ") + 1).find(" "));       //extract starring actor
            movieToAdd = movieToAdd.substr((movieToAdd.find(" ") + 1) + movieToAdd.substr(movieToAdd.find(" ") + 1).find(" ") + 1); //cut attribute out of string
            
            month = movieToAdd.substr(0, movieToAdd.find(" "));     //extract release month
            movieToAdd = movieToAdd.substr(movieToAdd.find(" ") + 1);       //cut attribute out of string

            year = movieToAdd;      //process release year

            Classic* movie = new Classic(title, director, year, month, actor, stock);
            if(orderedCollection['C'].insert(movie))        //BST insert was successful (movie not already in BST)
            {
                int key = std::stoi(year) + std::stoi(month);       //create key using month and year
                movieTable.insert(key, movie);
            }
            else    //do nothing.  BST updates stock of movie
            {
                delete movie;
            }

        case('F') : //comedy
            year = movieToAdd; //set year

            Comedy* movie = new Comedy(title, director, year, stock);

            int key = std::stoi(year);
            orderedCollection['F'].insert(movie);       //insert movie into Comedy BST
            movieTable.insert(key, movie);

        case('D') : //drama
            year = movieToAdd; //set year

            Drama* movie = new Drama(title, director, year, stock); //create comedy object

            int key = std::stoi(year);
            orderedCollection['D'].insert(movie);       //insert movie into Drama BST
            movieTable.insert(key, movie);

        default:
            std::cout << "Invalid movie category" << std::endl;
    }
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
