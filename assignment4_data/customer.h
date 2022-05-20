#pragma once

#include <list>
#include <string>

// -------------------------------- customer.h --------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
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
    // --------------------------Parametrized Constructor--------------------------
    // Description: The parametrized constructor creates a customer object with the
    // given customer name.
    //
    // Pre: The given customer name is correct, including both the first name and
    // the last name.
    //
    // Post: A customer object that stores the given customer name and has an
    // empty transaction history exists.
    //
    // Param: name, the name of the customer.
    Customer(std::string name);

    // -----------------------------------addHistory-------------------------------
    // Description: The method addHistory adds the given transaction, which is a
    // string, into the transaction history of this customer.
    //
    // Pre: The string must correctly represent the transaction to add.
    //
    // Post: The given transaction is at the front of the list that represents
    // the transaction history of this customer.
    //
    // Param: transaction, which is the transaction to add.
    void addHistory(std::string transaction);

    // ---------------------------------displayHistory-----------------------------
    // Description: The method displayHistory shows all the transactions of this
    // customer with chronological order. The most recent transaction in the
    // transaction history is shown first.
    //
    // Post: This method displays the transaction history with chronological order.
    // This costumer object does not change.
    void displayHistory();

private:
    // The name of this customer; the name should include the first name and
    // the last name, separated by a white space.
    std::string name;

    // The list that represents the transaction history of this customer. A
    // transaction is represented by a string. (Alternatively, a transaction can
    // be represented by an object.)
    std::list<std::string> history;
};