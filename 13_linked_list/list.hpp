/*---------------------------------------------------------------------
 *                  code : list
 *               @author :  Atul Uttam
 *          Date Created :  12-02-2023(02:09:35)
 --------------------------------------------------------------------*/

#include <iostream>
using namespace std;
// farward class declaration so that every one know that list class exit
class List;
class Node
{
    int data;

public:
    Node *next;
    Node(int d) : data(d), next(nullptr){};
    // getter function
    int getData()
    {
        return data;
    }
    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
        }
        cout << "Deleting Node with Data" << data << endl;
    }
    friend class List;
};

class List
{
    Node *head;
    Node *tail;
    int searchHelper(Node *start, int key)
    {
        // base case
        if (start == nullptr)
        {
            return -1;
        }
        // value matches
        if (start->data == key)
        {
            return 0;
        }
        // remaining part of the linked list
        int subIdx = searchHelper(start->next, key);
        if (subIdx == -1)
        {
            return -1;
        }
        return subIdx + 1;
    }

public:
    List() : head(nullptr), tail(nullptr){};

    Node *begin()
    {
        return head;
    }

    // intertion from the front
    void push_front(int data)
    {
        if (head == nullptr)
        {
            Node *temp = new Node(data);
            head = tail = temp;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
        }
    }
    // intertion from the back
    void push_back(int data)
    {
        if (head == nullptr)
        {
            Node *temp = new Node(data);
            head = tail = temp;
        }
        else
        {
            Node *temp = new Node(data);
            tail->next = temp;
            tail = temp;
        }
    }
    // insert at any location
    void insert(int data, int pos)
    {
        if (pos == 0)
        {
            push_front(data);
            return;
        }
        Node *nd;
        for (int jump = 1; jump <= pos - 1; jump++)
        {
            nd = nd->next;
        }
        Node *temp = new Node(data);
        temp->next = nd->next;
        nd->next = temp;
    }
    // Searching in a Linked List
    int search(int key)
    {

        Node *temp = head;
        int idx = 0;

        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return idx;
            }
            idx++;
            temp = temp->next;
        }
        return -1;
    }
    int recursiveSearch(int key)
    {
        int idx = searchHelper(head, key);
        return idx;
    }

    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    // Homework
    //  pop_back
    //  remove (pos)

    void pop_back()
    {
        Node *temp = tail;
    }

    void remove(int pos)
    {
    }
    Node *recReverse(Node *head)
    {
        // base case
        if (head == nullptr or head->next == nullptr)
        {
            return head;
        }
        // otherwise
        Node *sHead = recReverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return sHead;
    }

    void reverse(Node *&head)
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *temp;

        while (current != nullptr)
        {
            // store next
            temp = current->next;
            // update the current
            current->next = prev;

            // prev and current
            prev = current;
            current = temp;
        }

        head = prev;
        return;
    }

    ~List()
    {
        if (head != nullptr)
        {
            delete head;
            head = nullptr;
        }
    }
};
