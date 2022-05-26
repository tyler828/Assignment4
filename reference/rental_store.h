#pragma once

#include <string>

#include "media.h"
#include "table.h"
#include "customer.h"

// ------------------------------ rental_store.h ------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/22/2022
// Date of Last Modification:
//
// Purpose: This is the header file of the RentalStore class. The RentalStore
// class represents a rental store from which the customers can borrow media
// items. The RentalStore class can initialize the inventory of a rental store
// with an input file, establish a list of customers with an input file, and
// process the commands in an input file. The commands supported by the
// RentalStore class are the following ones: displaying the inventory of the
// rental store, displaying the transaction history of a customer, borrowing
// a media item, and returning a media item.

class RentalStore
{
public:
    // ------------------------------Default Constructor---------------------------
    // Description: The default constructor creates an empty rental store object.
    //
    // Post: An empty rental store object exits. This rental store has an empty
    // inventory and has no customers at the beginning.
    RentalStore();

    // ------------------------------initializeInventory---------------------------
    // Description: The method initializeInventory adds media items to the inventory
    // of this rental store based on the input file.
    //
    // Pre: Each line in the input file must be of a specific format that indicates
    // what media items should be added. For comedy movie DVDs and drama movie
    // DVDs, the format must be the following: Character(F or D), Stock, Director,
    // Title, Year it released. For classical movies, the format must be the
    // following: C, Stock, Director, Title, Major actor(first last) Release
    // date(month year).
    //
    // Post: This method added the media items indicated by the input file to
    // the inventory of this rental store. If a line in the input file is invalid,
    // this method will discard that line and will display an error message through
    // the console. If the inventory is not empty when this method is called,
    // this method will empty the inventory before adding media items to it.
    //
    // Param: input, an ifstream object that is associated with the input file.
    void initializeInventory(std::ifstream& input);

    // ---------------------------------addCustomers-------------------------------
    // Description: The method addCustomers adds customers to this rental store
    // based on the input file.
    //
    // Pre: Each line in the input file must be of a specific format that indicates
    // the information of a customer. The format must be the following:
    // ID(4-digit) Name(last first).
    //
    // Post: This method added the customers indicated by the input file to this
    // rental store. If a line in the input file is invalid, this method will
    // discard that line and will display an error message through the console.
    //
    // Param: input, an ifstream object that is associated with the input file.
    void addCustomers(std::ifstream& input);

    // --------------------------------processCommands-----------------------------
    // Description: The method processCommands reads an input file and processes
    // the commands in the input file.
    //
    // Pre: Each line in the input file must be of a specific format that
    // represents a command. For displaying the inventory of this rental store,
    // the command line must be a single character I. For displaying the
    // transaction history of a customer, the command line must be of the following
    // format: H ID(ID of the customer). For borrowing a media item or returning a
    // media item, the command line must be of the following format:
    // Character(B or R) ID(ID of the customer) Character(media type)
    // Character(movie type) Data(sorting attributes).
    //
    // Post: This method updates the inventory of this rental store and the
    // transaction histories of the customers based on the input file. If a line
    // in the input file is invalid, this method will discard that line and will
    // display an error message through the console.
    //
    // Param: input, an ifstream object that is associated with the input file.
    void processCommands(std::ifstream& input);

private:
    // This hash table contains the media items that are available at this rental
    // store. This hash table also maps each category of media item to a unique
    // character.
    MyTable<char, Media> mediaTable;

    // This hash table contains the customers of this rental store and maps each
    // customer to a unique ID.
    MyTable<int, Customer> customerTable;
};
