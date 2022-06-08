#pragma once

#include <list>
#include <string>
#include <iostream>

// -------------------------------- customer.h --------------------------------
// Programmer Name: Tyler Schmale     Course Section Number: CSS 343 B
// Creation Date: 5/19/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of the customer class. The customer
// class stores the name of a customer of a media rental store and the
// transaction history of the customer. When the customer borrows something
// from or returns something to the rental store, this transaction can be added
// to the transaction history of the customer. Finally, this class can display
// the transaction history of the customer.
// ----------------------------------------------------------------------------

class Customer
{
public:
    Customer(std::string input) : name(input) {};
    
    void addHistory(std::string transaction);

    friend std::ostream& operator<<(std::ostream& output, const Customer& rhs);

private:
    std::string name;
    
    std::list<std::string> history;

    void displayHistory();
};

