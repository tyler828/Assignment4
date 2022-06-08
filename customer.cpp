#include "customer.h"
    
void Customer::addHistory(std::string transaction)
{
    history.push_front(transaction);
}

std::ostream& operator<<(std::ostream& output, Customer& rhs) {
    for (std::list<std::string>::iterator it = rhs.history.begin(); it != rhs.history.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    return output;
}