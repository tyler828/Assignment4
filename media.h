#pragma once

#include <string>

// ---------------------------------- media.h ---------------------------------
// Programmer Name: Tyler Schmale     Course Section Number: CSS 343 B
// Creation Date: 5/21/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the media class. The media class
// represents one category of media item that is available at a media rental or
// retail store. This class allows the client to add new media items to the
// inventory of the store, update the inventory when a media item is borrowed
// or returned, and display all the media items in this certain category in
// the inventory of the store.

class Media
{
public:
    virtual bool addItem(std::string itemToAdd) = 0;

    virtual Movie* borrowItem(std::string itemBorrowed) = 0;
    
    virtual Movie* returnItem(std::string itemReturn) = 0;

    virtual void displayAllItems() const = 0;

private:

};
