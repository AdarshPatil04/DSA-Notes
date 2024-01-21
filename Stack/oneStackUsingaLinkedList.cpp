/**
 * @brief This code implements a stack using a linked list.
 * 
 * The Stack class provides the functionality to push elements onto the stack,
 * pop elements from the top of the stack, get the topmost element of the stack,
 * and check if the stack is empty.
 * 
 * The Node class represents a node in the linked list, with each node storing
 * an integer value and a pointer to the next node.
 * 
 * The main function demonstrates the usage of the Stack class by creating a stack,
 * pushing elements onto the stack, popping an element, and printing the topmost
 * element and whether the stack is empty.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;
};

// Stack class
class Stack
{
public:
    Node *top;

    // Constructor
    Stack()
    {
        top = NULL;
    }

    // push function to insert an element at top of stack
    void push(int element)
    {
        Node *newNode = new Node(); // Create a new node
        // If newNode cannot be dynamically allocated meaning if the system goes out of memory
        if (!newNode)
        {
            cout << "Stack Overflow" << endl; // Print "Stack Overflow"
            return;                           // Return
        }
        newNode->data = element; // Initialize newNode->data as element
        newNode->next = top;     // Make newNode->next as top
        top = newNode;           // Make newNode as top
    }

    // pop function to delete an element from top of stack
    void pop()
    {
        // If top is NULL
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl; // Print "Stack Underflow"
            return;                            // Return
        }
        Node *temp = top; // Store top in temp
        top = top->next;  // Move top one step ahead
        delete temp;      // Delete temp
    }

    // getTop function to return the topmost element of stack
    int getTop()
    {
        // If top is NULL
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl; // Print "Stack Underflow"
            return -1;                         // Return -1
        }
        return top->data; // Return topmost element
    }

    // isEmpty function to check if stack is empty or not
    bool isEmpty()
    {
        return top == NULL; // Return true if top is NULL else return false
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    cout << s.getTop() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}
