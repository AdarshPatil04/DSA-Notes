/**
 * @brief This code demonstrates the implementation of a heap data structure in C++.
 *
 * A heap is a complete binary tree that satisfies the heap property. In a max heap, the value of each node is greater than or equal to the values of its children.
 * This code provides a class 'heap' that supports operations like insertion, deletion, and printing of the heap.
 * It also includes a function 'heapify' that can be used to build a max heap from an array.
 *
 * The main function creates an instance of the 'heap' class, inserts values into the heap, and performs deletion of the root element.
 * It also demonstrates the usage of the 'heapify' function to build a max heap from an array.
 */
#include <bits/stdc++.h>
using namespace std;

// Heap is a data structure which is a Complete Binary Tree (CBT) that comes with a heap order property.
// A CBT is a Binary Tree (BT) in which all the levels are completely filled except the last level.
// Nodes are always added from the left in CBT or lean towards the left.

// Max Heap => Parent is always greater than children.
// Min Heap => Parent is always smaller than children.

// Node -> ith index (For 1-based indexing)
// left child  -> 2*i index
// right child -> (2*i + 1) index
// parent      -> (i/2)index

// Node -> ith index (For 0-based indexing)
// left child  -> 2*i+1 index
// right child -> (2*i + 2) index
// parent      -> (i/2)index

class heap
{
public:
    int arr[100]; // Array to store the heap
    int size;     // Size of the heap

    // Constructor to initialize the heap
    heap()
    {
        arr[0] = -1; // Initialize the first element as -1
        size = 0;    // Initialize the size as 0
    }

    // Function to insert a value into the heap
    // Time Complexity -> O(logn) -> since we are comparing value with i/2 index
    void insert(int val)
    {
        size = size + 1;  // Increase the size of the heap
        int index = size; // Set the index as the size
        arr[size] = val;  // Insert the value at the end of the heap

        // Heapify the heap from bottom to top
        while (index > 1)
        {
            int parent = index / 2; // Get the index of the parent

            // If the parent's value is less than the current value, swap them
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent; // Update the index to the parent's index
            }
            else
            {
                return; // If the heap property is satisfied, return
            }
        }
    }

    // Function to print the heap
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to delete the root from the heap
    // Time Complexity -> O(logn)
    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "\nNothing to delete"; // If the heap is empty, print a message
            return;
        }

        // Step 1 : put last element into the first index
        arr[1] = arr[size];

        // Step 2 : remove last element
        size--;

        // Step 3 : take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;      // Get the index of the left child
            int rightIndex = 2 * i + 1; // Get the index of the right child

            // If the left child's value is greater than the current value, swap them
            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex; // Update the index to the left child's index
            }
            // If the right child's value is greater than the current value, swap them
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex; // Update the index to the right child's index
            }
            else
            {
                return; // If the heap property is satisfied, return
            }
        }
    }
};

// In CBT leaf nodes lies between (n/2 + 1)index to nth index

// In Heapify function one have to perform the operations on only 1st to n/2th indexes of nodes

// Time Complexity => O(logn) me heapify sahi jagah pahuncha deti hai
// Build Max heap -> written here for 1-based indexing
void heapify(int arr[], int n, int i)
{

    int largest = i;       // Initialize the largest as root
    int left = 2 * i;      // Get the index of the left child
    int right = 2 * i + 1; // Get the index of the right child

    // If the left child's value is greater than the largest, update the largest
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    // If the right child's value is greater than the largest, update the largest
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    // If the largest is not root
    if (largest != i)
    {
        swap(arr[largest], arr[i]); // Swap the largest and the root
        heapify(arr, n, largest);   // Recursively heapify the affected sub-tree
    }
}

int main()
{
    heap h;       // Create a heap
    h.insert(55); // Insert values into the heap
    h.insert(54);
    h.insert(53);
    h.insert(50);
    h.insert(52);
    h.print(); // Print the heap

    h.deletefromHeap(); // Delete the root from the heap
    h.print();          // Print the heap
    cout << "Heapify function" << endl;
    int arr[6] = {-1, 54, 53, 55, 52, 50}; // Create an array
    int n = 5;                             // Set the size of the array

    // Time Complexity -> O(n)
    // For 1-based indexing -> go from n/2 to 0 -> below written
    // For 0-based indexing -> go from n/2-1 to 0
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i); // Build the heap
    }
    cout << "Printing the array now:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " "; // Print the array
    }
    return 0;
}
