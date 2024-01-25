/**
 * Time Complexity : O(n) for all operations
 * This code demonstrates how to reverse the first k elements of a queue.
 * It uses a stack to temporarily store the first k elements, then pops them off the stack
 * and pushes them back onto the queue, effectively reversing their order.
 * The remaining elements in the queue are then popped off and pushed back on to maintain their original order.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // Create a stack to hold the first k elements from the queue
    stack<int> s;
    
    // Pop the first k elements from the queue and push them onto the stack
    for(int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    // Pop the elements off of the stack and push them back onto the queue
    // This effectively reverses the first k elements
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    // For the remaining elements in the queue, pop them off and then push them back on
    // This leaves these elements in their original order
    int t = q.size() - k;
    while(t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    // Return the modified queue
    return q;
}

int main() {
    // Create a queue
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    int k = 3;
    queue<int> ans = modifyQueue(q, k);
    while(!ans.empty()) {
        cout<<ans.front()<<" ";
        ans.pop();
    }
    cout<<endl;
    return 0;
}
