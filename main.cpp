#include "rental_store.h"
#include <fstream>


int main() {
    std::ifstream commands("data4commands.txt");
    std::ifstream customers("data4customers.txt");
    std::ifstream movies("data4movies.txt");

    RentalStore Blockbuster;

    Blockbuster.initializeInventory(movies);
    //Blockbuster.addCustomers(customers);
    //Blockbuster.processCommands(commands);

    return 0;
}