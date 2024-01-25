/**
 * @file dequeImplementation.cpp
 * @brief This file contains the implementation of a deque (double-ended queue) using a dynamic array.
 * 
 * A deque is a data structure that allows insertion and deletion of elements from both ends in constant time.
 * This implementation uses a circular array to maintain the circular nature of the deque.
 * The deque supports operations like pushFront, pushRear, popFront, popRear, getFront, getRear, isEmpty, and isFull.
 * 
 * Example usage:
 * Deque dq(5);
 * dq.pushFront(10);
 * dq.pushRear(20);
 * dq.pushFront(30);
 * dq.pushRear(40);
 * cout << dq.popFront() << endl; // 30
 * cout << dq.popRear() << endl; // 40
 * cout << dq.getFront() << endl; // 10
 * cout << dq.getRear() << endl; // 20
 */
#include <bits/stdc++.h>
using namespace std;

class Deque
{	
    int *arr; // Dynamic array to store elements
    int front; // Index of the front element
    int rear; // Index of the rear element
    int size; // Maximum size of the deque

public:
    // Constructor to initialize the deque
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Function to add an element to the front of the deque
    bool pushFront(int x)
    {
        // Check if the deque is full
        if( isFull() ) {
            return false;
        }
        // If deque is empty, insert the first element
        else if(isEmpty()) {
            front  = rear = 0;
        }
        // If front is at the first position and deque is not full, then set front at the last position
        else if(front == 0 && rear != size-1) {
            front = size-1;
        } 
        // Normal case, move front one position ahead
        else
        {
            front--;
        }
        // Add the element to the deque
        arr[front] = x;
        return true;
    }

    // Function to add an element to the rear of the deque
    bool pushRear(int x)
    {
        // Check if the deque is full
        if( isFull() ) {
            return false;
        }
        // If deque is empty, insert the first element
        else if(isEmpty()) {
            front  = rear = 0;
        }
        // If rear is at the last position and deque is not full, then set rear at the first position
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } 
        // Normal case, move rear one position ahead
        else
        {
             rear++;
        }
        // Add the element to the deque
        arr[rear] = x;
        return true;
    }

    // Function to remove an element from the front of the deque
    int popFront()
    {
        // Check if the deque is empty
        if(isEmpty()){
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        // If the deque has only one element
        if(front == rear) { 
            front = rear = -1;
        }
        // Wrap around to maintain the circular nature of the deque
        else if(front == size - 1) {
            front = 0; 
        }
        // Normal case, move front one position ahead
        else
        {
            front++;
        }
        return ans;
    }

    // Function to remove an element from the rear of the deque
    int popRear()
    {
         // Check if the deque is empty
         if(isEmpty()){
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        // If the deque has only one element
        if(front == rear) { 
            front = rear = -1;
        }
        // Wrap around to maintain the circular nature of the deque
        else if(rear == 0) {
            rear = size-1; 
        }
        // Normal case, move rear one position back
        else
        {
            rear--;
        }
        return ans;
    }

    // Function to get the front element of the deque
    int getFront()
    {
        // If the deque is empty, return -1
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Function to get the rear element of the deque
    int getRear()
    {
       // If the deque is empty, return -1
       if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Function to check if the deque is empty
    bool isEmpty()
    {
        if(front == -1)
            return true;
        else
            return false;
    }

    // Function to check if the deque is full
    bool isFull()
    {
		if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Deque dq(5);

    // Push elements to the front and rear of the deque
    dq.pushFront(10);
    dq.pushRear(20);
    dq.pushFront(30);
    dq.pushRear(40);

    // Pop elements from the front and rear of the deque
    cout << dq.popFront() << endl; // 30
    cout << dq.popRear() << endl; // 40

    // Get the front and rear elements of the deque
    cout << dq.getFront() << endl; // 10
    cout << dq.getRear() << endl; // 20

    return 0;
}
