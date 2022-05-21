#pragma once

#include <string>

// ---------------------------------- media.h ---------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
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
    // -----------------------------------addItem----------------------------------
    // Description: The method addItem adds media items to the inventory according
    // to the given string.
    //
    // Pre: The given string must be of a specific format that indicates what
    // media items should be added. The media items to add must be in the category
    // that this media object represents.
    //
    // Post: This method added the media items indicated by the given string to
    // the inventory of the store.
    //
    // Param: itemToAdd, which is the string that indicates what media items to add.
    //
    // Return: True if the media items are successfully added; false otherwise.
    virtual bool addItem(std::string itemToAdd) = 0;

    // ---------------------------------borrowItem---------------------------------
    // Description: The method borrowItem updates the inventory for a media item
    // borrowed by a customer of the store.
    //
    // Pre: The given string must be of a specific format that indicates what
    // media item is borrowed.
    //
    // Post: This method updated the inventory of the store according to the given
    // string.
    //
    // Param: itemBorrowed, which is the string that indicates what media item is
    // borrowed.
    //
    // Return: True if the update is successful and the item is successfully
    // borrowed; false otherwise.
    virtual bool borrowItem(std::string itemBorrowed) = 0;

    // ---------------------------------returnItem---------------------------------
    // Description: The method returnItem updates the inventory for a media item
    // returned to the store by a customer.
    //
    // Pre: The given string must be of a specific format that indicates what
    // media item is returned.
    //
    // Post: This method updated the inventory of the store according to the given
    // string.
    //
    // Param: itemReturned, which is the string that indicates what media item is
    // returned.
    //
    // Return: True if the update is successful and the item is successfully
    // returned; false otherwise.
    virtual bool returnItem(std::string itemReturn) = 0;

    // ------------------------------displayAllItems-------------------------------
    // Description: The method displayAllItems displays the media items that is in
    // the category represented by this media object.
    //
    // Post: This method displayed the media items in this certain category in the
    // inventory of the store through the console. This media object does not
    // change.
    virtual void displayAllItems() const = 0;

private:

};
