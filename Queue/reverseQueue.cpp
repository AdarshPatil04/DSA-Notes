/**
 * Time Complexity : O(n) for all operations
 * Space Complexity : O(n)
 * @brief This program demonstrates how to reverse the elements of a queue using a stack.
 *
 * The program defines a function rev() that takes a queue as input and returns a reversed queue.
 * It uses a stack to reverse the elements of the queue. The function first removes all elements from the queue
 * and pushes them onto the stack. Then, it pops the elements from the stack and pushes them back into the queue,
 * effectively reversing the order of the elements. Finally, the program prints the elements of the reversed queue.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to reverse the elements of a queue
queue<int> reverse(queue<int> q)
{
    // Create a stack to hold the elements of the queue
    stack<int> s;

    // While the queue is not empty
    while (!q.empty())
    {
        // Get the front element of the queue
        int element = q.front();
        // Remove the front element from the queue
        q.pop();
        // Push the element onto the stack
        s.push(element);
    }

    // While the stack is not empty
    while (!s.empty())
    {
        // Get the top element of the stack
        int element = s.top();
        // Remove the top element from the stack
        s.pop();
        // Push the element onto the queue
        q.push(element);
    }
    // Return the reversed queue
    return q;
}

int main()
{
    // Create a queue
    queue<int> q;

    // Add elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Reverse the queue
    q = reverse(q);

    // Print the elements of the reversed queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
