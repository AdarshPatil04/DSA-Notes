/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * This program demonstrates how to interleave the first half of a queue with the second half.
 * It creates a new queue and fetches the first half elements from the input queue, pushing them into the new queue.
 * Then, it alternates between pushing elements from the new queue and the remaining elements from the input queue into the input queue itself.
 * Finally, it prints the interleaved queue.
 */
#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int>& q) 
{
    // Create a new queue
    queue<int> newQ;
    
    // Get the half size of the original queue
    int n = q.size() / 2;

    // Fetch first half elements from input queue and push into a newQueue
    for(int i = 0; i < n; i++)
    {
        int val = q.front();
        q.pop();
        newQ.push(val);
    }

    // Push alternative elements in input queue itself
    while(!newQ.empty())
    {
        int val = newQ.front();
        newQ.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }
}

int main() 
{
    // Create a queue
    queue<int> q;
    for (int i = 11; i <= 20; i++) {
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
