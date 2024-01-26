/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * This code demonstrates how to interleave the first half of a queue with the second half using a stack.
 * The function `interLeaveQueue` takes a queue of integers as input and interleaves its elements.
 * It first checks if the number of elements in the queue is even.
 * Then, it creates a stack and pushes the first half of the queue elements into the stack.
 * Next, it enqueues back the stack elements and dequeues the first half elements of the queue, enqueuing them back.
 * After that, it pushes the first half elements into the stack again.
 * Finally, it interleaves the elements of the queue and stack by alternatingly pushing elements from the stack and the front of the queue.
 * The main function creates a queue, calls the `interLeaveQueue` function, and prints the interleaved queue.
 */
#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int>& q) 
{
    // Check if the number of elements in the queue is even
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;

    // Create a stack
    stack<int> s;
    int halfSize = q.size() / 2;

    // Push the first half elements of queue to stack
    for (int i = 0; i < halfSize; i++) 
    {
        s.push(q.front());
        q.pop();
    }

    // Enqueue back the stack elements
    while (!s.empty()) 
    {
        q.push(s.top());
        s.pop();
    }

    // Dequeue the first half elements of queue and enqueue them back
    for (int i = 0; i < halfSize; i++) 
    {
        q.push(q.front());
        q.pop();
    }

    // Again push the first half elements into the stack
    for (int i = 0; i < halfSize; i++) 
    {
        s.push(q.front());
        q.pop();
    }

    // Interleave the elements of queue and stack
    while (!s.empty()) 
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() 
{
    // Create a queue
    queue<int> q;
    for (int i = 11; i <= 20; i++) 
    {
        q.push(i);
    }

    // Call the function to interleave the queue
    interLeaveQueue(q);

    // Print the interleaved queue
    cout << "The interleaved queue is: ";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
