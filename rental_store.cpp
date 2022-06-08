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
    std::string originalCommand;
    std::string line;

    //command fields in order they appear
    std::string commandType;
    int customerID;
    std::string mediaType;

    getline(input, originalCommand);
    line = originalCommand;

    while(!input.eof())     //not end of file
    {
        if(line.empty())        //empty final line
        {
            return;
        }

        //extract command type
        commandType = line[0];

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
                    std::cout << "Invalid customer ID found in command: " << originalCommand << std::endl;
                    break;
                }

                if(!mediaTable.exist(mediaType[0]))  //media collection not in mediaTable
                {
                    std::cout << "Invalid media type found in command: " << originalCommand << std::endl;
                    break;
                }

                if(mediaTable[mediaType[0]].borrowItem(line))   //attempt to borrow item from collection
                {
                    customerTable[customerID].addHistory(originalCommand);
                }

            case('R'):
                line = line.substr(line.find(" ") + 1);

                //extract customer ID
                customerID = std::stoi(line.substr(0, line.find(" ")));
                line = line.substr(line.find(" ") + 1);

                //extract media collection
                mediaType = line.substr(0, line.find(" "));
                line = line.substr(line.find(" ") + 1);

                if(!customerTable.exist(customerID)) //customer ID not registered
                {
                    std::cout << "Invalid customer ID found in command >> " << originalCommand << std::endl;
                    break;
                }

                if(!mediaTable.exist(mediaType[0]))  //media collection not in mediaTable
                {
                    std::cout << "Invalid media type found in command >> " << originalCommand << std::endl;
                    break;
                }

                if(mediaTable[mediaType[0]].returnItem(line))   //attempt to borrow item from collection
                {
                    customerTable[customerID].addHistory(originalCommand);
                }

            case('H'):
                line = line.substr(line.find(" ") + 1);

                //extract customer ID
                customerID = std::stoi(line.substr(0, line.find(" ")));
                line = line.substr(line.find(" ") + 1);

                if(!customerTable.exist(customerID)) //customer ID not registered
                {
                    std::cout << "Invalid customer ID found in command >> " << originalCommand << std::endl;
                    break;
                }

                std::cout << customerTable[customerID] << std::endl;

            case('I'):
                mediaTable['D'].displayAllItems();

            default:
                std::cout << "Invalid action code found in command >> "  << originalCommand << std::endl;
        }

        getline(input, line);           //get next line
    }
}
