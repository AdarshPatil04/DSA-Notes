/**
 * This program demonstrates how to insert an element at the bottom of a stack.
 * It defines a function insertAtBottom() that takes a stack and an element as input,
 * and recursively inserts the element at the bottom of the stack.
 * The main function creates a stack, pushes some elements into it, and then calls the insertAtBottom() function to insert a new element at the bottom.
 * Finally, it prints the stack elements before and after the insertion.
 */
#include<bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int> &s, int x){
    // Base case
    // If stack is empty
    if(s.empty()){
        s.push(x); // Push x into the stack which is the base case
        return; // Return
    }
    int data = s.top(); // Store the topmost element of the stack in data
    s.pop(); // Pop the topmost element
    // Recursive call
    insertAtBottom(s, x);
    s.push(data); // Push data into the stack
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    stack<int> temp = s;
    cout<<"Stack elements before inserting 4 at the bottom: "<<endl;
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }cout<<endl;
    insertAtBottom(s, 4);
    cout<<"Stack elements after inserting 4 at the bottom: "<<endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}