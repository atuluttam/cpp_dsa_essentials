/*---------------------------------------------------------------------
 *                  code :  hash_table
 *               @author :  Atul Uttam
 *          Date Created :  16-03-2023(20:22:43)
 --------------------------------------------------------------------*/
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T data;
    Node *next;

    Node(string key, T data)
    {
        this->key = key;
        this->data = data;
        this->next = nullptr;
    }

    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
};
template <typename T>
class HashTable
{
    Node<T> **table;
    int cs; // total entries that have been inserted
    int ts; // size of the table

    int hashFunction(string key)
    {
        int idx = 0;
        int power = 1;

        // if key abc then hash will be a*29 + b*29^2 + c*29^3
        for (auto ch : key)
        {
            idx = (idx + ch * power) % ts;
            power = (power * 29) % ts;
        }
        return idx;
    }

    void reHash()
    {
        // save the ptr to the old table and do the insertion in the new table
        Node<T> **oldTable = table;
        int oldTs = ts;

        // increase the hash table size
        cs = 0;
        ts = 2 * ts + 1; // ideally table size should be a prime number
        table = new Node<T> *[ts];

        for (int i = 0; i < ts; i++)
        {
            table[i] = nullptr;
        }

        // copy elements from the old table to new table
        for (int i = 0; i < oldTs; i++)
        {
            Node<T> *temp = oldTable[i];

            while (temp != nullptr)
            {
                string key = temp->key;
                T data = temp->data;

                insert(key, data); // this insertion will take place in the new table
                                   // since now table variable is pointing to new table
                temp = temp->next;
            }

            // destroy the ith linked list in the old table
            if (oldTable[i] != nullptr)
            {
                delete oldTable[i]; // it will destroy all the list of ith index
                                    // coz of destructor in node class
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int default_size = 7)
    {
        cs = 0;
        ts = default_size;

        table = new Node<T> *[ts];

        for (int i = 0; i < ts; i++)
        {
            table[i] = nullptr;
        }
    }

    void insert(string key, T data)
    {
        int idx = hashFunction(key);
        Node<T> *n = new Node<T>(key, data);

        // insertion at head of the linked list
        n->next = table[idx];
        table[idx] = n;
        cs++;

        // if the load factor of the table is greater than 0.7 then rehash
        float loadFactor = cs / float(ts);
        if (loadFactor > 0.7)
        {
            reHash();
        }
    }

    T *search(string key)
    {
        int idx = hashFunction(key);
        Node<T> *temp = table[idx];

        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return &temp->data;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    T& operator[](string key)
    {
        // return the value
        //  if key is not found then create a new node and return
        //  return the existing node
        T *valueFound = search(key);
        if (valueFound == NULL)
        {
            T object;
            insert(key, object);
            valueFound = search(key);
        }

        return *valueFound;
    }

    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            cout << "Bucket " << i << "->";

            Node<T> *temp = table[i];
            while (temp != nullptr)
            {
                cout << "(" << temp->key << "," << temp->data << ")"
                     << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
