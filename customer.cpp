#include "customer.h"
    
void Customer::addHistory(std::string transaction)
{
    history.push_back(transaction);
}

void Customer::displayHistory()
{
    
    for (std::list<std::string>::iterator it = history.begin(); it != history.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}