/**
 * This code demonstrates the usage of priority queues in C++.
 * It creates a max heap and a min heap using the priority_queue container.
 * Elements are inserted into the heaps and their top elements are printed.
 * The top element is then removed from each heap and the new top element is printed.
 * Finally, the size and emptiness of each heap is checked and displayed.
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Max Heap using priority queue
    priority_queue<int> maxHeap;

    // Insert elements into the max heap
    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);

    // Print the top element of the max heap
    cout << "Element at top => " << maxHeap.top() << endl;

    // Remove the top element from the max heap
    maxHeap.pop();

    // Print the top element of the max heap
    cout << "Element at top => " << maxHeap.top() << endl;

    // Print the size of the max heap
    cout << "Size is " << maxHeap.size() << endl;

    // Check if the max heap is empty
    if (maxHeap.empty())
    {
        cout << "Max heap is empty" << endl;
    }
    else
    {
        cout << "Max heap is not empty" << endl;
    }

    // Min heap using priority queue
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements into the min heap
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    // Print the top element of the min heap
    cout << "Element at top => " << minHeap.top() << endl;

    // Remove the top element from the min heap
    minHeap.pop();

    // Print the top element of the min heap
    cout << "Element at top => " << minHeap.top() << endl;

    // Print the size of the min heap
    cout << "Size is " << minHeap.size() << endl;

    // Check if the min heap is empty
    if (minHeap.empty())
    {
        cout << "Min heap is empty" << endl;
    }
    else
    {
        cout << "Min heap is not empty" << endl;
    }

    return 0;
}
