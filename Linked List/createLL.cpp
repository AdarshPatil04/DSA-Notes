/**
 * @brief This code demonstrates the creation of a linked list using a Node class.
 *        The Node class represents a single node in the linked list, containing an integer data value
 *        and a pointer to the next node in the list.
 *        The main function creates a new Node with data = 10, prints the data of the Node, and the address of the next Node.
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
};

int main()
{

    // Create a new Node dynamically with data = 10
    Node *head = new Node(10);

    // Printing the data of the Node and the address of the next Node
    cout << head->data << endl;
    cout << head->next << endl;
    return 0;
}