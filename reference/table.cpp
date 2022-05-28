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
    // Note: There may be a problem if we use both hash tables and binary
    // search trees to store pointers to movies.

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
template <class T1, class T2>
void MyTable<T1, T2>::insert(const T1& key, const T2& value)
{
    // Note: This hash table does not support string keys. There are four
    // solutions to this problem:
    // 1. Make the key of this hash table specific.
    // 2. Do not use strings as keys.
    // 3. Do not use this hash table for individual movies.
    // 4. Overload the operator % using a free function.

    // Compute the hash value based on the hash function. The hash function
    // that this hash table uses is key % BUCKETS.
    int hashValue = key % BUCKETS;

    // Locate the bucket based on the hash value. If the bucket is empty,
    // directly put the given value into the bucket.
    if (buckets[hashValue] == nullptr)
    {
        // Create a new node that stores the given key and the given value.
        Node* newNode = new Node();
        newNode -> key = key;
        newNode -> value = value;

        // Put the new node into the bucket.
        buckets[hashValue] = newNode;
    }
    // If the bucket is not empty, travers through the nodes in the bucket
    // before putting the value into the bucket.
    else
    {
        Node* current = buckets[hashValue];
        bool duplicate = false;

        // Find the last node of the linked nodes in the bucket and check
        // whether there are duplicated keys. If there is a duplicated key,
        // replace the original value that was mapped to this key with the
        // given value.
        if (current -> key == key)
        {
            current -> value = value;
            duplicate = true;
        }
        while (!duplicate && current -> next != nullptr)
        {
            current = current -> next;

            if (current -> key == key)
            {
                current -> value = value;
                duplicate = true;
            }
        }

        // If there are not any duplicated keys, insert a new node at the end
        // of the linked nodes.
        if (!duplicate)
        {
            // Create a new node that represents a key-value pair.
            Node* newNode = new Node();
            newNode -> key = key;
            newNode -> value = value;

            // Insert the new node.
            current -> next = newNode;
        }
    }
} // end of the method insert

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
template <class T1, class T2>
T2& MyTable<T1, T2>::operator[](const T1& key)
{
    // Compute the hash value based on the hash function. The hash function
    // that this hash table uses is key % BUCKETS.
    int hashValue = key % BUCKETS;

    // Locate the bucket based on the hash value. If the bucket is not empty,
    // travers through the nodes in the bucket to retrieve the value that is
    // mapped to the given key.
    if (buckets[hashValue] != nullptr)
    {
        Node* current = buckets[hashValue];
        if (current -> key == key)
        {
            return current -> value;
        }
        while (current -> next != nullptr)
        {
            current = current -> next;
            if (current -> key == key)
            {
                return current -> value;
            }
        }

        // If this line of the code is reached, the pointer current points to
        // the last node in the bucket, and the given key is not mapped to a
        // value. Map the given key to a value and add this key-value pair to
        // this hash table.
        Node* newNode = new Node();
        newNode -> key = key;
        current -> next = newNode;
        return newNode -> value;
    }
    // If the bucket is empty, the given key is not mapped to a value. Map the
    // given key to a value and add this key-value pair to this hash table.
    else
    {
        Node* newNode = new Node();
        newNode -> key = key;
        buckets[hashValue] = newNode;
        return newNode -> value;
    }
} // end of the method operator[]