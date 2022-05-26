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
template <class T1, T2>
class MyTable
{
public:
    // ------------------------------Default Constructor---------------------------
    // Description: The default constructor creates an empty hash table.
    //
    // Post: An empty hash table exists. Specifically, each bucket of this hash
    // table stores a null pointer.
    MyTable();

private:
    // My table uses open hashing. The Node struct represents a node that
    // stores a value in the bucket.
    struct Node
    {
        Node* next;
        T2 value;

        Node() : next(nullptr)
        {

        }
    };

    // An array that has 100 buckets to store the values.
    Node* buckets[100];
};