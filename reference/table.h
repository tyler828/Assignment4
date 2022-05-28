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
    // Pre: As for the data type of the keys of a hash table, the specified data
    // type (T1) must be first-class. That is, the keys must support mathematical
    // operators.
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

    // ----------------------------------operator[]--------------------------------
    // Description: The method operator[] overloads the operator [], allowing
    // an array-style access to a value in this hash table through a key.
    //
    // Pre: The given key should be mapped to a value in this hash table, and the
    // given key must match the data type that was specified.
    //
    // Post: The method returns a reference to the value that is mapped to the
    // given key. If the given key is not mapped to any values in this hash table,
    // this method will map the given key to a new value (which may be garbage),
    // add this key-value pair to this hash table, and return the reference to
    // this value.
    //
    // Param: key, the key through which a value could be accessed.
    //
    // Return: A reference to a value in this hash table.
    T2& operator[](const T1& key);

    // -----------------------------------remove-----------------------------------
    // Description: The method remove deletes the given key and the value that is
    // mapped to the given key from this hash table.
    //
    // Pre: The given key should be mapped to a value in this hash table, and the
    // given key must match the data type that was specified.
    //
    // Post: This method removed the given key and the value that is mapped to it
    // from this hash table. If the given key is not mapped to a value, this method
    // does nothing.
    //
    // Param: key, the key of the key-value pair to remove.
    void remove(const T1& key);

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

    // -------------------------------------hash-----------------------------------
    // Description:The method hash computes the hash value with the given key.
    // The hash function that this hash table uses is key % BUCKETS (the number of
    // buckets).
    //
    // Pre: The given key must match the data type that was specified.
    //
    // Post: This method returns the hash value. This hash table does not change.
    //
    // Param: key, the key whose hash value is to be computed.
    //
    // Return: The hash value of the given key.
    int hash(const T1& key) const;
};

#include "table.cpp"