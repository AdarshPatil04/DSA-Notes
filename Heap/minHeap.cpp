/**
 * Time Complexity: O(n)
 * @brief This code demonstrates the implementation of a Min Heap data structure.
 *        It includes functions to heapify a subtree, build a Min Heap from an array,
 *        and print the Min Heap. The main function initializes an input array,
 *        builds a Min Heap from it, and then prints the Min Heap.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted with node i which is an index in arr[].
// n is size of heap. This function is used to heapify a Min Heap.
void heapify(vector<int> &arr, int n, int i)
{

    int smallest = i;      // Initialize smallest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root
    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }

    // If right child is smaller than smallest so far
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    // If smallest is not root
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]); // Swap the smallest element with root

        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

// Function to build a Min Heap from an array
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size(); // Get the size of the array

    // Index of last non-leaf node is (n/2 - 1). Start from this index and heapify all nodes one by one.
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return arr; // Return the heapified array
}

int main()
{
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9}; // Input array

    // Build a Min Heap from the input array
    vector<int> minHeap = buildMinHeap(arr);

    // Print the Min Heap
    for (int i = 0; i < minHeap.size(); i++)
    {
        cout << minHeap[i] << " ";
    }
    return 0;
}
