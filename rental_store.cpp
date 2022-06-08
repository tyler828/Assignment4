#include <string>

#include "rental_store.h"

// ------------------------------ rental_store.cpp ----------------------------
// Programmer Name: Tyler Schmale     Course Section Number: CSS 343 B
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
    DVD* dvdCollection = new DVD;              //create DVD object
    mediaTable.insert('D', dvdCollection);     //insert into mediaTable (only type of media in table for this project)
}

void RentalStore::initializeInventory(std::ifstream& input)
{
    std::string line;
    getline(input, line);

    while(!input.eof())     //not end of file
    {
        if(line.empty())        //empty final line
        {
            return;
        }

        mediaTable['D'].addItem(line);  //send line to be parsed by DVD object
        getline(input, line);           //get next line
    }
}


void RentalStore::addCustomers(std::ifstream& input)
{
    std::string line;
    std::string ID;
    getline(input, line);

    while(!input.eof())     //not end of file
    {
        if(line.empty()) //empty final line
        {
            return;
        }

        //create customer object, initialize it's attributes
        int ID = std::stoi(line.substr(0, line.find(" ")));     //extract ID
        line = line.substr(line.find(" ") + 1);                 //remove ID, leaving name only

        Customer* customer = new Customer(line);    
        customerTable.insert(ID, customer);         //insert object into hash table

        //send customer object ot customerTable with key of its key
        getline(input, line);           //get next line
    }
}

void RentalStore::processCommands(std::ifstream& input)
{
    std::string line;

    //command fields in order they appear
    std::string commandType;
    int customerID;
    std::string mediaType;

    getline(input, line);

    while(!input.eof())     //not end of file
    {
        if(line.empty())        //empty final line
        {
            return;
        }

        //extract command type
        commandType = line.substr(0, line.find(" "));

        switch(commandType[0])
        {
            case('B'):
                line = line.substr(line.find(" ") + 1);

                //extract customer ID
                customerID = std::stoi(line.substr(0, line.find(" ")));
                line = line.substr(line.find(" ") + 1);

                //extract media collection
                mediaType = line.substr(0, line.find(" "));
                line = line.substr(line.find(" ") + 1);

                if(!customerTable.exist(customerID)) //customer ID not registered
                {
                    return;
                }

                if(!mediaTable.exist(mediaType[0]))  //media collection not in mediaTable
                {
                    return;
                }

                if(mediaTable[mediaType[0]].borrowItem(line))   //attempt to borrow item from collection
                {

                }
                

            case('R'):
            case('H'):
            case('I'):
            default:
                std::cout << "Invalid action code" << std::endl;
        }

        //switch statement

        getline(input, line);           //get next line
    }
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
