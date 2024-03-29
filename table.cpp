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
// Pre: As for the data type of the keys of a hash table, the specified data
// type (T1) must be first-class. That is, the keys must support mathematical
// operators.
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
            delete temp -> value;
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
void MyTable<T1, T2>::insert(const T1& key, T2* value)
{
    // Note: This hash table does not support string keys. There are four
    // solutions to this problem:
    // 1. Make the key of this hash table specific.
    // 2. Do not use strings as keys.
    // 3. Do not use this hash table for individual movies.
    // 4. Overload the operator % using a free function.

    // Compute the hash value based on the hash function. The hash function
    // that this hash table uses is key % BUCKETS.
    int hashValue = hash(key);

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
            delete current -> value;
            current -> value = value;
            duplicate = true;
        }
        while (!duplicate && current -> next != nullptr)
        {
            current = current -> next;

            if (current -> key == key)
            {
                delete current -> value;
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
// given key must match the data type that was specified. That is, the
// given key must exist in this hash table.
//
// Post: The method returns a reference to the value that is mapped to the
// given key.
//
// Param: key, the key through which a value could be accessed.
//
// Return: A reference to a value in this hash table.
template <class T1, class T2>
T2& MyTable<T1, T2>::operator[](const T1& key) const
{
    // Compute the hash value based on the hash function. The hash function
    // that this hash table uses is key % BUCKETS.
    int hashValue = hash(key);

    // Locate the bucket based on the hash value. Travers through the nodes in
    // the bucket to retrieve the value that is mapped to the given key.
    Node* current = buckets[hashValue];
    T2* result;
    while (current != nullptr)
    {
        if (current -> key == key)
        {
            result = current -> value;
        }
        current = current -> next;
    }
    return *result;
} // end of the method operator[]

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
template <class T1, class T2>
void MyTable<T1, T2>::remove(const T1& key)
{
    // Compute the hash value based on the hash function. The hash function
    // that this hash table uses is key % BUCKETS.
    int hashValue = hash(key);

    // Locate the bucket based on the hash value. If the bucket is not empty,
    // locate the value that is mapped to the given key and remove that value.
    if (buckets[hashValue] != nullptr)
    {
        if (buckets[hashValue] -> key == key)
        {
            Node* temp = buckets[hashValue];
            buckets[hashValue] = buckets[hashValue] -> next;
            delete temp -> value;
            delete temp;
        }
        else
        {
            Node* current = buckets[hashValue];
            bool removed = false;
            while (!removed && current -> next != nullptr)
            {
                if (current -> next -> key == key)
                {
                    Node* temp = current -> next;
                    current -> next = current -> next -> next;
                    delete temp -> value;
                    delete temp;
                    removed = true;
                }
                else
                {
                    current = current -> next;
                }
            }
        }
    }
} // end of the method remove

// -----------------------------------exist-----------------------------------
// Description: The method exist checks whether the given key exists in this
// hash table.
//
// Post: This hash table does not change.
//
// Param: key, the key to check.
//
// Return: True if the given key exists in this hash table; false otherwise.
template <class T1, class T2>
bool MyTable<T1, T2>::exist(const T1& key) const
{
    // Compute the hash value based on the hash function. The hash function
    // that this hash table uses is key % BUCKETS.
    int hashValue = hash(key);

    // Locate the bucket based on the hash value. If the bucket is not
    // empty, check all the nodes in that bucket.
    Node* current = buckets[hashValue];
    while (current != nullptr)
    {
        // Return true if the given key is found.
        if (current -> key == key)
        {
            return true;
        }
        current = current -> next;
    }
    return false;
} // end of the method exist

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
template <class T1, class T2>
int MyTable<T1, T2>::hash(const T1& key) const
{
    return key % BUCKETS;
} // end of the hash function