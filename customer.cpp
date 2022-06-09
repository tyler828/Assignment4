#include "customer.h"

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
void Customer::addHistory(std::string transaction)
{
    history.push_front(transaction);
}

// ---------------------------------operator<<-----------------------------
// Description: The method operator<< shows all the transactions of this
// customer with chronological order. The most recent transaction in the
// transaction history is shown first.
//
// Post: This method displays the transaction history with chronological order.
// This costumer object does not change.
std::ostream& operator<<(std::ostream& output, Customer& rhs) {
    output << "Customer: " << rhs.name << std::endl;
    for (std::list<std::string>::iterator it = rhs.history.begin(); it != rhs.history.end(); ++it)
    {
        output << *it << std::endl;
    }
    return output;

}
