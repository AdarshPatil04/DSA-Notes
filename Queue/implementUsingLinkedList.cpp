/**
 * @file
 * This file contains the implementation of a queue using a linked list.
 * The Queue class provides methods to enqueue, dequeue, get the front element,
 * and check if the queue is empty.
 * The Node class represents a node in the linked list.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class to represent a node in the linked list
class Node
{
public:
    int data; // data of the node
    Node *next; // pointer to the next node
    // constructor
    Node(int data)
    {
        this->data = data; // initialize data
        this->next = NULL; // initialize next
    }
};

// Queue class to represent a queue using a linked list
class Queue
{
    Node *front, *rear; // pointers to the front and rear of the queue

public:
    // constructor
    Queue()
    {
        front = rear = NULL; // initialize front and rear
    }

    // Function to add an element to the rear of the queue
    void enqueue(int data)
    {
        Node *newNode = new Node(data); // create a new node

        // If queue is empty, then new node is front and rear both
        if (rear == NULL)
        {
            front = rear = newNode;
            return;
        }

        // Add the new node at the end of queue and change rear
        rear->next = newNode;
        rear = newNode;
    }

    // Function to remove an element from the front of the queue
    void dequeue()
    {
        // If queue is empty, return NULL.
        if (front == NULL)
            return;

        // Store the old front and move front one node ahead
        Node *temp = front;
        front = front->next;

        // If front becomes NULL, then change rear also as NULL
        if (front == NULL)
            rear = NULL;

        delete (temp); // delete the old front
    }

    // Function to get the front of the queue
    int getFront()
    {
        // If queue is empty, return -1.
        if (front == NULL)
            return -1;
        else
            return front->data; // return the front of the queue
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (front == NULL); // return true if queue is empty
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.getFront() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
    return 0;
}
