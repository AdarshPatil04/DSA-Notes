/**
 * This code implements a doubly linked list in C++.
 * It defines a Node class with data, previous, and next pointers.
 * The code includes functions to insert and delete nodes at various positions in the linked list.
 * The main function demonstrates the usage of these functions.
 */

#include <bits/stdc++.h>
using namespace std;

// Node class
class Node
{
public:
    // Data
    int data;

    // Pointer to the previous Node
    Node *prev;

    // Pointer to the next Node
    Node *next;

    // Constructor
    Node(int data)
    {
        // Storing the data in the Node
        this->data = data;

        // Initially the previous and next pointers are NULL
        prev = NULL;
        next = NULL;
    }

    // Destructor
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data: " << val << endl;
    }
};

// Print the linked list
void print(Node *head)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = head;

    // Traversing the linked list and printing the data in the Nodes
    while (temp != NULL)
    {
        cout << temp->data << " ";

        // Moving the temporary Node forward
        temp = temp->next;
    }
    cout << endl;
}

// getLength function
void getLength(Node *head)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = head;

    // Variable to store the length of the linked list
    int count = 0;

    // Traversing the linked list and incrementing the count
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // Printing the length of the linked list
    cout << count << endl;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // If Head Node is NULL
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        return;
    }

    else
    { // Creating a new Node
        Node *temp = new Node(data);

        // Making the next of the new Node as the head Node
        temp->next = head;

        // Making the previous of the head Node as the new Node
        head->prev = temp;

        // Making the new Node temp as the head Node
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int data)
{
    // If Tail Node is NULL
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        return;
    }
    else
    {
        // Creating a new Node
        Node *temp = new Node(data);

        // Making the next of the tail Node as the new Node
        tail->next = temp;

        // Making the previous of the new Node as the tail Node
        temp->prev = tail;

        // Making the new Node temp as the tail Node
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // Head Node
    if (position == 1)
    {
        insertAtHead(head, tail, data);
    }

    Node *temp = head;
    int count = 1;

    // Traversing the linked list before the position-1 because position-1 is the temp Node
    while (count < position - 1)
    {
        // Moving the temp Node forward
        temp = temp->next;
        count++;
    }

    // Last Node / Tail Node
    if (temp->next == NULL)
    {
        insertAtTail(temp, head, data);
    }

    // Creating a new Node
    Node *nodeToInsert = new Node(data);

    // Making the next of the new Node as the next of the temp(Node before the position) Node
    nodeToInsert->next = temp->next;

    // Making the previous of the next of the temp Node as the new Node
    nodeToInsert->next->prev = nodeToInsert;

    // Making the next of the temp Node as the new Node
    temp->next = nodeToInsert;

    // Making the previous of the new Node as the temp Node
    nodeToInsert->prev = temp;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    // Head Node
    if (position == 1)
    {
        // Creating a temporary Node to store the head Node
        Node *temp = head;

        // Making the previous of the next of the temp Node as NULL
        temp->next->prev = NULL;

        // Making the head Node point to the next of the temp Node
        head = head->next;

        // Making the next of the temp Node as NULL
        temp->next = NULL;

        // Deleting the temp Node
        delete temp;
        return;
    }
    else
    {
        // Creating a temporary Node to store the current Node (position Node) which is initially the head Node
        Node *curr = head;

        // Creating a previous Node to store the previous Node of the curr Node which is initially NULL
        Node *prev = NULL;

        // Creating a count variable to count the number of Nodes traversed
        int count = 1;

        // Traversing the linked list until the position
        while (count < position)
        {
            // Moving the prev Node forward
            prev = curr;
            curr = curr->next;
            count++;
        }

        // Making the previous of the curr Node as the NULL
        curr->prev = NULL;

        // Making the next of the prev Node as the next of the curr Node
        prev->next = curr->next;

        // Making the next of the curr Node as the NULL
        curr->next = NULL;

        // Deleting the curr Node
        delete curr;
    }
}

int main()
{
    // Creating a Node
    Node *node1 = new Node(10);

    // Storing the address of the first Node in a pointer
    Node *head = node1;
    Node *tail = node1;

    // Printing the data in the first Node
    print(head);

    // Printing the length of the linked list
    getLength(head);

    // Inserting a Node at the head of the linked list
    insertAtHead(head, tail, 20);
    print(head);

    // Inserting a Node at the tail of the linked list
    // Tail before insertion
    print(tail);
    insertAtTail(tail, head, 30);

    // Tail after insertion
    print(tail);

    // Inserting a Node at a given position in the linked list
    insertAtPosition(head, tail, 40, 2);
    print(head);

    // Deleting a Node at a given position in the linked list
    deleteNode(head, tail, 2);
    print(head);
    return 0;
}