#pragma once

// --------------------------------- table.h ----------------------------------
// Programmer Name: Po-Lin Tu     Course Section Number: CSS 343 B
// Creation Date: 5/26/2022
// Date of Last Modification:
//
// Purpose: This file is the header file of MyTable class. MyTable class is a
// class template that represents a hash table, maps a key to a value, stores
// the key-value pairs, and provides efficient access to a value through the
// key.

// T1 is the type of the key; T2 is the type of the value.
template <class T1, class T2>
class MyTable
{
public:
    // ------------------------------Default Constructor---------------------------
    // Description: The default constructor creates an empty hash table.
    //
    // Post: An empty hash table exists. Specifically, each bucket of this hash
    // table stores a null pointer.
    MyTable();

    // ----------------------------------Destructor--------------------------------
    // Description: The destructor deletes this hash table, freeing the memory that
    // was dynamically allocated to this hash table.
    //
    // Post: This hash table does not exist. The dynamically allocated memory is
    // free.
    ~MyTable();

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
    void insert(const T1& key, const T2& value);

private:
    // My table uses open hashing. The Node struct represents a node in a
    // bucket. The node stores a value and the key of this value.
    struct Node
    {
        Node* next;
        T1 key;
        T2 value;

        Node() : next(nullptr)
        {

        }
    };

    // The number of buckets in the hash table.
    static const int BUCKETS = 100;

    // An array that has 100 buckets to store the values.
    Node* buckets[BUCKETS];
};

#include "table.cpp"