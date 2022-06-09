#include <string>

#include "dvd.h"

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

int DVD::stringToKey(std::string line)
{
    int key = 0;

    for(int i = 0; i < line.length(); ++i)
    {
        key += line[i]*(pow(10, i));
    }
    
    return key;
}


void DVD::addItem(std::string movieToAdd)
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
        {
            //parse classic-specific attributes
            actor = movieToAdd.substr(0, (movieToAdd.find(" ") + 1) + movieToAdd.substr(movieToAdd.find(" ") + 1).find(
                    " "));       //extract starring actor
            movieToAdd = movieToAdd.substr(
                    (movieToAdd.find(" ") + 1) + movieToAdd.substr(movieToAdd.find(" ") + 1).find(" ") +
                    1); //cut attribute out of string

            month = movieToAdd.substr(0, movieToAdd.find(" "));     //extract release month
            movieToAdd = movieToAdd.substr(movieToAdd.find(" ") + 1);       //cut attribute out of string

            year = movieToAdd;      //process release year

            Classic *movie = new Classic(title, director, year, month, actor, stock);
            if (orderedCollection['C'].insert(movie))        //BST insert was successful (movie not already in BST)
            {
                int key = stringToKey(actor + month + year);       //create key using actor + month + year
                movieTable.insert(key, movie);
            } else    //do nothing.  BST updates stock of movie
            {
                delete movie;
            }
        }

        case('F') : //comedy
        {
            year = movieToAdd; //set year

            Comedy *movie = new Comedy(title, director, year, stock);

            int key = stringToKey(title + year);       //create key using title + year
            orderedCollection['F'].insert(movie);       //insert movie into Comedy BST
            movieTable.insert(key, movie);
        }

        case('D') : //drama
        {
            year = movieToAdd; //set year

            Drama *movie = new Drama(title, director, year, stock); //create comedy object

            int key = stringToKey(title + director);        //create key using title + director
            orderedCollection['D'].insert(movie);   //insert movie into Drama BST
            movieTable.insert(key, movie);
        }

        default:
            std::cout << "Invalid movie category" << std::endl;
    }
}

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

void DVD::displayAllItems()
{
    orderedCollection['C'].inOrderTraversal();
    orderedCollection['D'].inOrderTraversal();
    orderedCollection['F'].inOrderTraversal();
}
