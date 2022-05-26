#include "table.h"

// -------------------------------- table.cpp ---------------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 5/26/2022
// Date of Last Modification:
//
// Purpose: This file is the implementation file of MyTable class. MyTable class
// is a class template that represents a hash table, maps a key to a value,
// stores the key-value pairs, and provides efficient access to a value through
// the key.

// ------------------------------Default Constructor---------------------------
// Description: The default constructor creates an empty hash table.
//
// Post: An empty hash table exists. Specifically, each bucket of this hash
// table stores a null pointer.
template <class T1, class T2>
MyTable<T1, T2>::MyTable()
{
    // Initialize the array.
    for (int i = 0; i < BUCKETS; i++)
    {
        buckets[i] = nullptr;
    }
} // end of the default constructor

// ----------------------------------Destructor--------------------------------
// Description: The destructor deletes this hash table, freeing the memory that
// was dynamically allocated to this hash table.
//
// Post: This hash table does not exist. The dynamically allocated memory is
// free.
template <class T1, class T2>
MyTable<T1, T2>::~MyTable()
{
    // For each bucket that is not empty in this hash table, delete all the
    // values in the bucket. In other words, delete the nodes that store the
    // values in the bucket.
    for (int i = 0; i < BUCKETS; i++)
    {
        while (buckets[i] != nullptr)
        {
            // Delete the first node in the bucket.
            Node* temp = buckets[i];
            buckets[i] = buckets[i] -> next;
            delete temp;
            temp = nullptr;
        }
    }
} // end of the destructor
