/**
 * Time Complexity: O(nlogn)
 * @brief This program demonstrates the implementation of Heap Sort algorithm.
 * 
 * The heap sort algorithm works by first building a max heap from the input array,
 * then repeatedly swapping the root node (which is the maximum element) with the last node,
 * reducing the size of the heap by one, and heapifying the root node again.
 * This process is repeated until the entire array is sorted in ascending order.
 * 
 * @param arr The input array to be sorted.
 * @param n The size of the array.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted with node i which is an index in arr[].
// n is size of heap. This function is used to heapify a Max Heap.
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i;      // For 0-based indexing -> 2*i + 1;
    int right = 2 * i + 1; // For 0-based indexing -> 2*i + 2;

    // If left child is larger than root
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[largest], arr[i]); // Swap the largest element with root

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // Step 1 : Swap the root node with the last node
        swap(arr[size], arr[1]);
        size--;

        // Step 2 : Heapify the root node
        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50}; // Input array
    int n = 5;                             // Size of the array

    // Heap creation
    for (int i = 1; i <= n; i++)
    {
        heapify(arr, n, i); // Build the max heap
    }

    cout << "\nPrinting the array " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    // Heap Sort
    heapSort(arr, n);

    cout << "\nPrinting sorted array using Heap Sort " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
