/**
 * This program demonstrates how to delete the middle element of a stack.
 * The program defines a function `deleteMiddle` that takes a stack and its size as input.
 * It uses a recursive function `solve` to delete the middle element of the stack.
 * The `solve` function pops the topmost element of the stack until the count is equal to size/2.
 * After deleting the middle element, the program prints the stack elements before and after deletion.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to delete the middle element of stack
void solve(stack<int> &st, int size, int count)
{
    // Base case
    // If count is equal to size/2
    if (count == size / 2)
    {
        st.pop(); // Pop the middle element
        return;   // Return
    }
    int temp = st.top(); // Store the topmost element of stack in temp
    st.pop();            // Pop the topmost element
    // Recursive case
    solve(st, size, count + 1); // Recursive call
    st.push(temp);              // Push temp onto stack
}

// Function to delete the middle element of stack
void deleteMiddle(stack<int> &st, int size)
{
    int count = 0;          // Initialize count as 0
    solve(st, size, count); // Call solve function
}

int main()
{
    stack<int> st;
    st.push(1); // Push 1 onto stack
    st.push(2); // Push 2 onto stack
    st.push(3); // Push 3 onto stack
    st.push(4); // Push 4 onto stack
    st.push(5); // Push 5 onto stack
    cout << "Stack elements before deleting middle element: " << endl;
    stack<int> temp = st;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    deleteMiddle(st, st.size()); // Delete the middle element of stack
    cout << "Stack elements after deleting middle element: " << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}