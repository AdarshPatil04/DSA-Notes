/**
 * Time Complexity: O(m+n)
 * Space Complexity: O(m+n)
 * @file mergeTwoMaxBinaryHeaps.cpp
 * @brief This file contains the implementation of a class that merges two max binary heaps into one.
 * A max binary heap is a complete binary tree where the value of each node is greater than or equal to the values of its children.
 * The class provides a function to merge two max heaps and return the merged max heap.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to heapify a subtree rooted with node i which is an index in ans[].
    // n is size of heap. This function is used to heapify a Max Heap.
    void heapify(vector<int> &ans, int size, int &i)
    {
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // left = 2*i + 1
        int right = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (left < size && ans[largest] < ans[left])
        {
            largest = left;
        }

        // If right child is larger than largest so far
        if (right < size && ans[largest] < ans[right])
        {
            largest = right;
        }

        // If largest is not root
        if (largest != i)
        {
            swap(ans[largest], ans[i]); // Swap the largest element with root

            // Recursively heapify the affected sub-tree
            heapify(ans, size, largest);
        }
    }

    // Function to merge two max heaps a and b into one
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        // Step-1 : merge two vectors into one
        vector<int> ans;

        for (auto i : a)
            ans.push_back(i);
        for (auto i : b)
            ans.push_back(i);

        // Step-2 : create a max heap using merged arrays
        int size = ans.size();

        // Heapify each node from the last internal node all the way up to the root node
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(ans, size, i);
        }

        return ans; // Return the merged max heap
    }
};

int main()
{
    vector<int> a = {10, 5, 6, 2}; // First max heap
    vector<int> b = {12, 7, 9}; // Second max heap

    // Print the first max heap
    cout << "a: ";
    for (auto i : a)
        cout << i << " ";
    cout << endl;

    // Print the second max heap
    cout << "b: ";
    for (auto i : b)
        cout << i << " ";
    cout << endl;

    Solution obj;
    // Merge the two max heaps into one
    vector<int> merged = obj.mergeHeaps(a, b, a.size(), b.size());

    // Print the merged max heap
    cout << "merged: ";
    for (auto i : merged)
        cout << i << " ";
    return 0;
}
