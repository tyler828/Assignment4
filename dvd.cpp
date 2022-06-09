#include <string>

#include "dvd.h"
#include <iomanip>

// --------------------------------- dvd.cpp ----------------------------------
// Programmer Name: Tyler Schmale     Course Section Number: CSS 343 B
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

DVD::~DVD()
{

}

long DVD::stringToKey(std::string line)
{
    long key = 0;

    for(int i = 0; i < line.length(); ++i)
    {
        key += line[i]*(pow(2, i));
    }
    
    return key;
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
void DVD::addItem(std::string movieToAdd)
{
    std::string line = movieToAdd;
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
        {
            //parse classic-specific attributes
            actor = movieToAdd.substr(0,movieToAdd.find(" ") + 1);       //extract starring actor
            movieToAdd = movieToAdd.substr(movieToAdd.find(" ") + 1); //cut attribute out of string
            actor += movieToAdd.substr(0,movieToAdd.find(" "));       //extract starring actor
            movieToAdd = movieToAdd.substr(movieToAdd.find(" ") + 1); //cut attribute out of string

            month = movieToAdd.substr(0, movieToAdd.find(" "));     //extract release month
            movieToAdd = movieToAdd.substr(movieToAdd.find(" ") + 1);       //cut attribute out of string

            year = movieToAdd;      //process release year

            Classic *movie = new Classic(title, director, year, month, actor, stock);
            if (orderedCollection['C'].insert(movie))        //BST insert was successful (movie not already in BST)
            {
                long key = stringToKey(actor + month + year);       //create key using actor + month + year
                movieTable.insert(key, movie);
            } else    //do nothing.  BST updates stock of movie
            {
                delete movie;
            }
            break;

        }

        case('F') : //comedy
        {
            year = movieToAdd; //set year

            Comedy *movie = new Comedy(title, director, year, stock);

            long key = stringToKey(title + year);       //create key using title + year
            orderedCollection['F'].insert(movie);       //insert movie into Comedy BST
            movieTable.insert(key, movie);

            break;
        }

        case('D') : //drama
        {
            year = movieToAdd; //set year

            Drama *movie = new Drama(title, director, year, stock); //create comedy object

            long key = stringToKey(title + director);        //create key using title + director
            orderedCollection['D'].insert(movie);   //insert movie into Drama BST
            movieTable.insert(key, movie);
            break;
        }

        default:
        {
            std::cout << "Invalid movie category in line >> " << line << std::endl;
            break;
        }
    }
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
Movie* DVD::borrowItem(std::string movieBorrowed)
{
    std::string director;
    std::string title;
    std::string year;

    //classic attributes
    std::string month;
    std::string actor;

    Movie* movie;

    switch(movieBorrowed[0])
    {
        case('C'):
            movieBorrowed = movieBorrowed.substr(movieBorrowed.find(" ") + 1);  //cut out movie type

            month = movieBorrowed.substr(0, movieBorrowed.find(" "));       //extract month
            movieBorrowed = movieBorrowed.substr(movieBorrowed.find(" ") + 1);

            year = movieBorrowed.substr(0, movieBorrowed.find(" "));        //extract year
            actor = movieBorrowed.substr(movieBorrowed.find(" ") + 1); //reduce string to only actor

            if(movieTable.exist(stringToKey(actor + month + year))) //check for this classic movie
            {
                movie = &movieTable[stringToKey(actor + month + year)];
                if(movie->stock > 0) //stock not empty
                {
                    movie->stock -= 1;
                    return movie;
                }
                
                std::cout << "No stock available >> " << movie->title << std::endl;
                return nullptr;
            }

            std::cout << "Invalid movie >> " << month << " " << year << " " << actor << std::endl;
            return nullptr;

        case('F'):
            movieBorrowed = movieBorrowed.substr(movieBorrowed.find(" ") + 1);

            title = movieBorrowed.substr(0, movieBorrowed.find(","));       //extract title
            year = movieBorrowed.substr(movieBorrowed.find(",") + 2);      //reduce string to only year

            if(movieTable.exist(stringToKey(title + year))) //check for this comedy movie
            {
                movie = &movieTable[stringToKey(title + year)];
                if(movie->stock > 0) //stock not empty
                {
                    movie->stock -= 1;
                    return movie;
                }
                
                std::cout << "No stock available >> " << movie->title << std::endl;
                return nullptr;
            }

            std::cout << "Invalid movie >> " << title << ", " << year << std::endl;
            return nullptr;

        case('D'):
            movieBorrowed = movieBorrowed.substr(movieBorrowed.find(" ") + 1);

            director = movieBorrowed.substr(0, movieBorrowed.find(","));       //extract director
            movieBorrowed = movieBorrowed.substr(movieBorrowed.find(",") + 2);      //reduce string to only title
            title = movieBorrowed.substr(0, movieBorrowed.find(","));      //remove trailing comma

            if(movieTable.exist(stringToKey(title + director))) //check for this comedy movie
            {
                movie = &movieTable[stringToKey(title + director)];
                if(movie->stock > 0) //stock not empty
                {
                    movie->stock -= 1;
                    return movie;
                }
                
                std::cout << "No stock available >> " << movie->title << std::endl;
                return nullptr;
            }

            std::cout << "Invalid movie >> " << director << ", " << title << std::endl;
            return nullptr;

        default:
            std::cout << "Invalid movie category >> " << movieBorrowed[0] << std::endl;
            return nullptr;
    }
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
Movie* DVD::returnItem(std::string movieReturned)
{
    std::string director;
    std::string title;
    std::string year;

    //classic attributes
    std::string month;
    std::string actor;

    Movie* movie;

    switch(movieReturned[0])
    {
        case('C'):
            movieReturned = movieReturned.substr(movieReturned.find(" ") + 1);  //cut out movie type

            month = movieReturned.substr(0, movieReturned.find(" "));       //extract month
            movieReturned = movieReturned.substr(movieReturned.find(" ") + 1);

            year = movieReturned.substr(0, movieReturned.find(" "));        //extract year
            actor = movieReturned.substr(movieReturned.find(" ") + 1); //reduce string to only actor

            if(movieTable.exist(stringToKey(actor + month + year))) //check for this classic movie
            {
                movie = &movieTable[stringToKey(actor + month + year)];
                if(movie->stock < movie->max) //stock not empty
                {
                    movie->stock += 1;
                    return movie;
                }
                
                std::cout << "No stock available >> " << movie->title << std::endl;
                return nullptr;
            }

            std::cout << "Invalid movie >> " << month << " " << year << " " << actor << std::endl;
            return nullptr;

        case('F'):
            movieReturned = movieReturned.substr(movieReturned.find(" ") + 1);

            title = movieReturned.substr(0, movieReturned.find(","));       //extract title
            year = movieReturned.substr(movieReturned.find(",") + 2);      //reduce string to only year

            if(movieTable.exist(stringToKey(title + year))) //check for this comedy movie
            {
                movie = &movieTable[stringToKey(title + year)];
                if(movie->stock < movie->max) //stock not empty
                {
                    movie->stock += 1;
                    return movie;
                }
                
                std::cout << "No stock available >> " << movie->title << std::endl;
                return nullptr;
            }

            std::cout << "Invalid movie >> " << title << ", " << year << std::endl;
            return nullptr;

        case('D'):
            movieReturned = movieReturned.substr(movieReturned.find(" ") + 1);

            director = movieReturned.substr(0, movieReturned.find(","));       //extract director
            movieReturned = movieReturned.substr(movieReturned.find(",") + 2);      //reduce string to only title
            title = movieReturned.substr(0, movieReturned.find(","));      //remove trailing comma

            if(movieTable.exist(stringToKey(title + director))) //check for this comedy movie
            {
                movie = &movieTable[stringToKey(title + director)];
                if(movie->stock < movie->max) //stock not empty
                {
                    movie->stock += 1;
                    return movie;
                }
                
                std::cout << "No stock available >> " << movie->title << std::endl;
                return nullptr;
            }

            std::cout << "Invalid movie >> " << director << ", " << title << std::endl;
            return nullptr;

        default:
            std::cout << "Invalid movie category >> " << movieReturned[0] << std::endl;
            return nullptr;
    }
}


// ------------------------------displayAllItems-------------------------------
// Description: The method displayAllItems displays the movie DVDs that are in
// the inventory of the store.
//
// Post: This method displayed the movie DVDs in the inventory of the store
// through the console with the following order: comedy movies, drama movies,
// and then classical movies. This DVD object does not change.
void DVD::displayAllItems()
{
    orderedCollection['F'].inOrderTraversal();
    orderedCollection['D'].inOrderTraversal();
    orderedCollection['C'].inOrderTraversal();
}
