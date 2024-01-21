/**
 * This code demonstrates the reversal of a stack using recursion.
 * The code defines two functions: insertAtBottom() and reverseStack().
 * The insertAtBottom() function is a helper function that inserts an element at the bottom of a stack.
 * The reverseStack() function recursively reverses the given stack by using the insertAtBottom() function.
 * The main() function initializes a stack, pushes elements into it, and then reverses the stack.
 * The reversed stack is then printed to the console.
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

// Function to reverse a stack
void reverseStack(stack<int> &s){
    // Base case
    if(s.empty()){
        return; // Return
    }
    int temp = s.top(); // Store the topmost element of the stack in temp
    s.pop(); // Pop the topmost element
    // Recursive call
    reverseStack(s);
    insertAtBottom(s,temp); // Insert temp at the bottom of the stack
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    stack<int> temp = s;
    cout<<"Stack elements before reversing: "<<endl;
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }cout<<endl;
    reverseStack(s);
    cout<<"Stack elements after reversing: "<<endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
