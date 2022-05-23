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
    RentalStore();

    void initializeInventory(std::ifstream& input);

    void addCustomers(std::ifstream& input);

    void processCommands(std::ifstream& input);

private:
    MyTable<char, Media> mediaTable;
    
    MyTable<std::string, Customer> customerTable;
};
