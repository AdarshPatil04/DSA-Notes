/**
 * @brief This code implements a circular queue using a dynamic array.
 * 
 * The CircularQueue class provides methods to enqueue and dequeue elements,
 * get the front element, and check if the queue is empty. The queue is
 * implemented using a circular array to efficiently utilize the available
 * space. The size of the queue is specified during object creation.
 * 
 * Example usage:
 * 
 * CircularQueue q(5);
 * q.enqueue(10);
 * q.enqueue(20);
 * q.enqueue(30);
 * q.enqueue(40);
 * q.enqueue(50);
 * 
 * cout << q.dequeue() << endl; // 10
 * cout << q.dequeue() << endl; // 20
 * 
 * q.enqueue(60);
 * q.enqueue(70);
 * 
 * cout << q.getFront() << endl; // 30
 * 
 * cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl; // Queue is not empty
 */
#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
    int *arr;  // Dynamic array to store elements
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int size;  // Maximum size of the queue

public:
    // Constructor to initialize the queue
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Function to add an element to the rear of the queue
    bool enqueue(int value)
    {
        // Check if the queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        else if (front == -1) // Inserting the first element
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) // Wrap around to maintain the circular nature of the queue
        {
            rear = 0;
        }
        else // Normal case
        {
            rear++;
        }
        // Add the element to the queue
        arr[rear] = value;
        return true;
    }

    // Function to remove an element from the front of the queue
    int dequeue()
    {
        // Check if the queue is empty
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) // If the queue has only one element
        {
            front = rear = -1;
        }
        else if (front == size - 1) // Wrap around to maintain the circular nature of the queue
        {
            front = 0;
        }
        else // Normal case
        {
            front++;
        }
        return ans;
    }

    // Function to get the front element of the queue
    int getFront()
    {
        // If the queue is empty, return -1
        if (front == -1)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (front == -1);
    }
};

int main()
{
    CircularQueue q(5);

    // Enqueue elements into the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Dequeue elements from the queue
    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20

    // Enqueue more elements into the queue
    q.enqueue(60);
    q.enqueue(70); 

    // Display the front element
    cout << q.getFront() << endl; // 30

    // Check if the queue is empty
    cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl; // Queue is not empty

    return 0;
}
