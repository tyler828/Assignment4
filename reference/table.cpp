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

// ------------------------------------insert----------------------------------
// Description: The method insert receives a key and a value as its parameters,
// mapping the key to the value. This method then inserts this key-value pair
// into this hash table.
//
// Pre: The given key should be unique; it should be different from the other
// keys in this hash table. Additionally, the given key must be a first class
// object that supports mathematical operators. Finally, the given key and the
// given value must match the data types that were specified when this hash
// table was created.
//
// Post: This method inserted the given key and the given value into this hash
// table. If the given key is not unique, the value that was mapped to this
// key will be overwritten by the given value.
//
// Param: key, the key of the value.
//
// Param: value, the value of the key.
void insert(T1 key, T2 value);
