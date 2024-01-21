/**
 * @file
 * @brief This file contains the implementation of a stack using an array.
 *
 * The Stack class provides the functionality to push elements onto the stack,
 * pop elements from the stack, get the topmost element of the stack, and check
 * if the stack is empty or not. The stack is implemented using an array.
 *
 * Example usage:
 *
 * Stack s(5);
 * s.push(1);
 * s.push(2);
 * s.push(3);
 * s.pop();
 * cout << s.getTop() << endl;
 * cout << s.isEmpty() << endl;
 */
#include <bits/stdc++.h>
using namespace std;

// Stack class
class Stack
{
public:
    int *arr; // Array to store elements
    int top;  // Index of topmost element
    int size; // Size of stack

    // Constructor
    Stack(int size)
    {
        this->size = size;   // Initialize size
        arr = new int[size]; // Create an array of size 'size'
        top = -1;            // Initialize top as -1
    }

    // push function to insert an element at top of stack
    void push(int element)
    {
        // If top is less than size-1
        if (size - top > 1)
        {
            top++;              // Increment top
            arr[top] = element; // Insert element at top
        }
        // If top is equal to size-1
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    // pop function to delete an element from top of stack
    void pop()
    {
        // If top is greater than or equal to 0
        if (top >= 0)
        {
            top--; // Decrement top
        }
        // If top is less than 0
        else
        {
            cout << "Stack Underflow" << endl; // Print "Stack Underflow"
        }
    }

    // getTop function to return the topmost element of stack
    int getTop()
    {
        // If top is greater than or equal to 0
        if (top >= 0)
        {
            return arr[top]; // Return topmost element
        }
        // If top is less than 0
        else
        {
            cout << "Stack Underflow" << endl; // Print "Stack Underflow"
            return -1;                         // Return -1
        }
    }

    // isEmpty function to check if stack is empty or not
    bool isEmpty()
    {
        // If top is equal to -1
        if (top == -1)
        {
            return true; // Return true
        }
        // If top is not equal to -1
        else
        {
            return false; // Return false
        }
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();
    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    s.pop();
    cout << s.getTop() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}