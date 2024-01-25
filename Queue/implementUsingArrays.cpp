/**
 * Time Complexity : O(1) for all operations
 * @brief This code implements a queue data structure using arrays.
 * 
 * The Queue class provides methods to enqueue (insert) elements, dequeue (remove) elements,
 * check if the queue is empty, and retrieve the front element of the queue.
 * The implementation uses an array to store the elements, with a front and rear pointer
 * to keep track of the positions in the array.
 * 
 * Example usage:
 * Queue q;
 * q.enqueue(10);
 * q.enqueue(20);
 * q.enqueue(30);
 * cout << q.dequeue() << endl; // Output: 10
 * cout << q.front() << endl;   // Output: 20
 * cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
 */
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;   // array to store elements
    int qfront; // front of queue
    int rear;   // rear of queue
    int size;   // size of queue

public:
    // constructor
    Queue()
    {
        size = 100001;       // size of queue
        arr = new int[size]; // allocate memory
        qfront = 0;          // initialize front
        rear = 0;            // initialize rear
    }

    // destructor
    bool isEmpty()
    {
        // if front and rear are equal, queue is empty
        if (qfront == rear)
        {
            return true; // return true
        }
        // else queue is not empty
        else
        {
            return false; // return false
        }
    }

    // enqueue() : Inserts an element x to queue
    void enqueue(int data)
    {
        // if rear is equal to size, queue is full
        if (rear == size)
        {
            cout << "Queue is Full" << endl;
        }
        // else insert data
        else
        {
            arr[rear] = data; // insert data
            rear++; // increment rear
        }
    }

    // dequeue() : Removes an element from queue
    int dequeue()
    {
        // if front and rear are equal, queue is empty
        if (qfront == rear)
        {
            return -1; // return -1
        }
        // else remove element
        else
        {
            int ans = arr[qfront]; // store front element
            arr[qfront] = -1; // set front element to -1
            qfront++; // increment front
            // if front and rear are equal
            if (qfront == rear)
            {
                qfront = 0; // set front to 0
                rear = 0; // set rear to 0
            }
            return ans; // return front element
        }
    }

    // front() : Returns front element of queue
    int front()
    {
        // if front and rear are equal, queue is empty
        if (qfront == rear)
        {
            return -1; // return -1
        }
        // else return front element
        else
        {
            return arr[qfront]; // return front element
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
    return 0;
}
