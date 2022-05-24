#include <string>

#include "rental_store.h"

// ------------------------------ rental_store.h ------------------------------
// Programmer Name: Team C--     Course Section Number: CSS 343 B
// Creation Date: 5/23/2022
// Date of Last Modification:
//
// Purpose: This is the implementation file of the RentalStore class.
// The RentalStore class represents a rental store from which the customers
// can borrow media items. The RentalStore class can initialize the inventory
// of a rental store with an input file, establish a list of customers with an
// input file, and process the commands in an input file. The commands
// supported by the RentalStore class are the following ones: displaying the
// inventory of the rental store, displaying the transaction history of a
// customer, borrowing a media item, and returning a media item.

RentalStore::RentalStore()
{

}

void RentalStore::initializeInventory(std::ifstream& input)
{
    // Pseudo Code
    //
    // Add an DVD object to the media table.
    // for each line in the input file
    // {
    //     Call the addItem method on the DVD object. Pass each line to the addItem
    //     method as a string.
    // }
}

void RentalStore::addCustomers(std::ifstream& input)
{
    // Pseudo Code
    //
    // for each line in the input file
    // {
    //     Parse the line for the ID and the name of the customer.
    //     Create a customer object that contains the name of the customer.
    //     Add this customer object to the customer table and map this
    //     customer object to the ID of this customer.
    // }
}

void RentalStore::processCommands(std::ifstream& input)
{
    // Pseudo Code
    //
    // for each line in the input file
    // {
    //     Parse the line for the action type.
    //     if action type is I
    //     {
    //         Call the method displayAllItems on the DVD object.
    //     }
    //     else if action type is H
    //     {
    //         Parse the line for the customer ID.
    //         if the customer ID exists in the customer table
    //         {
    //             Call the method displayHistory on the customer object with this
    //             ID.
    //         }
    //         else
    //         {
    //             Display an error message.
    //         }
    //     }
    //     else if action type is B
    //     {
    //         Parse the line for the customer ID and the media type.
    //         if the customer ID exists in the customer table and the media type
    //         exists in the media table
    //         {
    //             Call the method borrowItem on the DVD object. Pass the rest of
    //             the line as the parameter.
    //             if borrowItem returns true
    //             {
    //                 Call the method addHistory on the customer object with this
    //                 ID.
    //             }
    //         }
    //         else
    //         {
    //             Display an error message.
    //         }
    //     }
    //     else if action type is R
    //     {
    //         Parse the line for the customer ID and the media type.
    //         if the customer ID exists in the customer table and the media type
    //         exists in the media table
    //         {
    //             Call the method returnItem on the DVD object. Pass the rest of
    //             the line as the parameter.
    //             if returnItem returns true
    //             {
    //                 Call the method addHistory on the customer object with this
    //                 ID.
    //             }
    //         }
    //         else
    //         {
    //             Display an error message.
    //         }
    //     }
    //     else
    //     {
    //         Display an error message.
    //     }
    // }
}
