/**
 * @brief This code demonstrates the implementation of a circular linked list in C++.
 *        It includes functions to insert a node at a specific position, delete a node,
 *        and print the elements of the circular linked list.
 *        The main function showcases the usage of these functions by performing various operations on the circular linked list.
 */

#include <bits/stdc++.h>
using namespace std;

// Node class
class Node
{
public:
    // Data
    int data;

    // (Pointer to the next Node) / (Address of the next Node)
    Node *next;

    // Constructor to create a new Node
    Node(int data)
    {
        // data is the data given by the user
        this->data = data;

        // Initially the next pointer is NULL
        next = NULL;
    }

    // Destructor to delete the Node
    ~Node()
    {
        // Storing the data of the Node in a variable
        int value = this->data;

        // Checking if the next pointer is not NULL
        if (this->next != NULL)
        {
            // Deleting the next Node
            delete next;

            // Making the next pointer point to NULL
            next = NULL;
        }

        // Printing the data of the Node whose memory is being freed
        cout << "Memory is free for node with data: " << value << endl;
    }
};

void insertAtNode(Node *&tail, int element, int d)
{

    // If the list is empty
    if (tail == NULL)
    {
        // Create a new node
        Node *newNode = new Node(d);
        // Make the tail point to the new node
        tail = newNode;
        // Make the new node point to itself
        newNode->next = newNode;
        return;
    }

    else
    {
        // Non-empty list -  assume that the node with data d exists
        Node *curr = tail;
        // Traverse the list till the node with data element is reached
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found - curr points to the node with data d
        // Create a new node
        Node *temp = new Node(d);
        // Make the new node point to the next node of curr
        temp->next = curr->next;
        // Make curr point to the new node
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int element)
{
    // If the list is empty
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    // If list is non-empty - assume that the node with data element exists
    else
    {
        Node *prev = tail;
        Node *curr = tail->next;
        // Traverse the list till the node with data element is reached
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        // curr points to the node with data element and prev points to the node before curr
        // Making the next of prev point to the next of curr
        prev->next = curr->next;
        // Checking if the curr node is the only node in the list

        if(curr == prev)
        {
            tail = NULL;
        }

        // Checking if the curr node is not the only node in the list 
        // Checking if the curr node is the tail node
        else if (curr == tail)
        {
            // Making the prev node as the tail node
            tail = prev;
        }
        // Making the next of curr point to NULL
        curr->next = NULL;
        // Deleting the curr node
        delete curr;
    }
}

void print(Node *tail)
{
    // Making a temporary pointer to traverse the list
    Node *temp = tail;

    // Checking if the list is empty
    if(tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    // Non-empty list
    // Traversing the list
    do
    {
        // Printing the data in the nodes
        cout << tail->data << " ";
        // Moving the pointer forward
        tail = tail->next;
        // Checking if the pointer has reached the tail again
    } while (temp != tail);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    // Insert in an empty list
    insertAtNode(tail, 5, 3);
    print(tail);
    // Delete 3
    deleteNode(tail, 3);
    print(tail);
     // Insert in an empty list
    insertAtNode(tail, 5, 3);
    print(tail);
    // Insert at the end and beginning doesn't make sense for circular LL since we don't know which is the end and which is the beginning so, we will insert at a node
    // Insert 4 after 3
    insertAtNode(tail, 3, 4);
    print(tail);
    // Insert 6 after 3
    insertAtNode(tail, 3, 6);
    print(tail);
    // Insert 7 after 3
    insertAtNode(tail, 3, 7);
    print(tail);
    // Delete 6
    deleteNode(tail, 6);
    print(tail);
    // Delete 4
    deleteNode(tail, 4);
    print(tail);

    return 0;
}
