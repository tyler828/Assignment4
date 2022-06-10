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


// ------------------------------Default Constructor---------------------------
// Description: The default constructor creates an empty rental store object.
//
// Post: An empty rental store object exits. This rental store has an empty
// inventory and has no customers at the beginning.
RentalStore::RentalStore()
{
    DVD* dvdCollection = new DVD();              //create DVD object
    mediaTable.insert('D', dvdCollection);     //insert into mediaTable (only type of media in table for this project)
}

RentalStore::~RentalStore()
{

}


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

        if(line.back() == '\r')  //remove end line character
        {
            line.pop_back();
        }

        mediaTable['D'].addItem(line);  //send line to be parsed by DVD object
        getline(input, line);           //get next line
    }
}


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

        if(line.back() == '\r')  //remove end line character
        {
            line.pop_back();
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
void RentalStore::processCommands(std::ifstream& input)
{
    std::string originalCommand;
    std::string line;

    //command fields in order they appear
    std::string commandType;
    int customerID;
    std::string mediaType;

    getline(input, line);
    originalCommand = line;

    while(!input.eof())     //not end of file
    {
        if(line.empty())        //empty final line
        {
            return;
        }

        if(line.back() == '\r')  //remove end line character
        {
            line.pop_back();
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
                }

                else if(!mediaTable.exist(mediaType[0]))  //media collection not in mediaTable
                {
                    std::cout << "Invalid media type found in command: " << originalCommand << std::endl;
                }

                else   //attempt to borrow item from collection
                {
                    Movie* temp = mediaTable[mediaType[0]].borrowItem(line);

                    // add the transaction if the borrow was successful
                    if (temp != nullptr)
                    {
                        std::string transaction = "Borrow\nTitle: ";
                        transaction += temp -> getTitle();
                        transaction += "\nDirector: ";
                        transaction += temp -> getDirector();
                        transaction += "\nRelease Year: ";
                        transaction += temp -> getYear();
                        transaction += "\n";

                        customerTable[customerID].addHistory(transaction);
                    }
                }
                break;

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
                }

                else if(!mediaTable.exist(mediaType[0]))  //media collection not in mediaTable
                {
                    std::cout << "Invalid media type found in command >> " << originalCommand << std::endl;
                }
                else
                {
                    Movie* temp = mediaTable[mediaType[0]].returnItem(line);   //attempt to return item to collection

                    // add the transaction if the return was successful
                    if (temp != nullptr)
                    {
                        std::string transaction = "Return\nTitle: ";
                        transaction += temp -> getTitle();
                        transaction += "\n Director: ";
                        transaction += temp -> getDirector();
                        transaction += "\n Release Year: ";
                        transaction += temp -> getYear();
                        transaction += "\n";

                        customerTable[customerID].addHistory(transaction);
                    }
                }
                break;

            case('H'):
                line = line.substr(line.find(" ") + 1);

                //extract customer ID
                customerID = std::stoi(line);

                if(!customerTable.exist(customerID)) //customer ID not registered
                {
                    std::cout << "Invalid customer ID found in command >> " << originalCommand << std::endl;
                }
                else
                {
                    std::cout << "Customer History - " << line << std::endl;
                    std::cout << customerTable[customerID] << std::endl;
                }
                break;

            case('I'):
                std::cout << std::endl << std::endl
                << "###------------------------Inventory------------------------###" << std::endl << std::endl;
                mediaTable['D'].displayAllItems();
                break;

            default:
                std::cout << "Invalid action code found in command >> "  << originalCommand << std::endl;
                break;
        }
        getline(input, line);           //get next line
        originalCommand = line;
    }
}

