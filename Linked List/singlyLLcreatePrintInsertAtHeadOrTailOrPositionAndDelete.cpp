/**
 * @brief This code demonstrates the implementation of a singly linked list in C++.
 *        It includes functions to create, print, insert at head, insert at tail, insert at a given position,
 *        and delete a node at a given position in the linked list.
 *        The code also includes a Node class with a constructor and destructor to manage the memory of the nodes.
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
            this->next = NULL;
        }

        // Printing the data of the Node whose memory is being freed
        cout << "Memory is free for node with data: " << value << endl;
    }
};

// Insert at head
void insertAtHead(Node *&head, int data)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = new Node(data);

    // Making the next pointer of the new Node point to the head
    temp->next = head;

    // Making the head point to the new Node
    head = temp;
}

// Insert at tail
void insertAtTail(Node *&tail, int data)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = new Node(data);

    // Making the next pointer of the tail point to the new Node
    tail->next = temp;

    // Making the tail point to the new Node
    tail = tail->next;
}

void insertAtPosition(Node *&head, int position, int data)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = head;
    int count = 1;

    // Traversing the linked list until the position - 1
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // If the position is greater than the length of the linked list then insert at tail
    if (temp->next == NULL)
    {
        insertAtTail(temp, data);
        return;
    }

    // Creating a new Node to insert at the given position
    Node *nodeToInsert = new Node(data);

    // Making the next pointer of the new Node point to the next Node of the temp Node
    nodeToInsert->next = temp->next;

    // Making the next pointer of the temp Node point to the new Node
    temp->next = nodeToInsert;
}

// Print the linked list
void print(Node *head)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = head;

    // Traversing the linked list and printing the data until temp->next is NULL
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete a node at a given position
void deleteNode(int position, Node *&head)
{
    // If the position is 1 then delete the head
    if (position == 1)
    {
        // Creating a temporary Node to store the head
        Node *temp = head;

        // Making the head point to the next Node
        head = temp->next;

        // Making the next pointer of the temp Node point to NULL otherwise our Destructor will work
        temp->next = NULL;

        // Deleting the temp Node
        delete temp;
    }
    else
    {
        // Creating a temporary Node to traverse the linked list
        Node *curr = head;

        // Creating a previous Node to store the previous Node of the curr Node
        // The curr Node is pointing to the head so the previous Node will be NULL initially
        Node *prev = NULL;

        // Traversing the linked list until the position
        int count = 1;
        while (count < position)
        {
            // Making the previous Node point to the curr Node which is the Node before the position
            prev = curr;

            // Making the curr Node point to the next Node which is the Node at the position
            curr = curr->next;

            // Incrementing the count
            count++;
        }

        // Making the next pointer of the previous Node point to the next Node of the curr Node
        prev->next = curr->next;

        // Making the next pointer of the curr Node point to NULL otherwise our Destructor will work
        curr->next = NULL;

        // Deleting the curr Node
        delete curr;
    }
}

int main()
{
    // Create a new Node dynamically with data = 10
    Node *node1 = new Node(10);

    // Printing the data of the Node and the address of the next Node
    cout << node1->data << endl;
    cout << node1->next << endl;

    // Creating a head pointer to point to the node1
    Node *head = node1;

    // Printing the data of the head and the address of the next head before inserting 5 at the head
    print(head);

    // Calling the insertAtHead function
    insertAtHead(head, 5);

    // Printing the data of the head and the address of the next head after inserting 5 at the head
    print(head);

    // Creating a tail pointer to point to the node1 which contains 5 10 where 5 is inserted at the head
    Node *tail = node1;

    // Printing the data of the tail and the address of the next tail before inserting 15 at the tail, output will be 10
    print(tail);

    // Calling the insertAtTail function
    insertAtTail(tail, 15);

    // Printing the head because to get all the data of the LL else only the tail will be printed so output will be 5 10 15 where 15 has know become the tail
    print(head);

    // Calling the insertAtPosition function to insert 7 at position 2, Output: 5 7 10 15
    insertAtPosition(head, 2, 7);

    // Printing the LL
    print(head);

    // Calling the deleteNode function to delete the Node at position 2, Output: 5 10 15
    deleteNode(2, head);

    // Printing the LL
    print(head);
    return 0;
}