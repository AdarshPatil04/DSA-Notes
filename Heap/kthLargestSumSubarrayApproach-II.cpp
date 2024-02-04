/**
 * Time Complexity: O(n^2 logk)
 * Space Complexity: O(k)
 * This program calculates the Kth largest sum of subarrays in a given array.
 * It uses a min heap to keep track of the K largest sums encountered so far.
 * The algorithm iterates over the array and calculates the sum of each subarray.
 * If the size of the heap is less than K, the sum is added to the heap.
 * If the sum is greater than the smallest element in the heap, the smallest element is replaced with the sum.
 * Finally, the top of the heap contains the Kth largest sum.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to get the Kth largest sum of subarrays
int getKthLargest(vector<int> &arr, int k)
{
    // Create a min heap (priority queue where the smallest element is at the top)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Get the size of the array
    int n = arr.size();

    // Iterate over the array
    for (int i = 0; i < n; i++)
    {
        // Initialize sum to 0 for each i
        int sum = 0;
        // Iterate from i to end of array
        for (int j = i; j < n; j++)
        {
            // Add current element to sum
            sum += arr[j];

            // If size of heap is less than k, push sum into heap
            if (minHeap.size() < k)
            {
                minHeap.push(sum);
            }
            else
            {
                // If sum is greater than top (smallest) element of heap, replace top with this sum
                if (sum > minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }

    // Top of heap now contains Kth largest sum
    return minHeap.top();
}

int main()
{
    // Initialize array
    vector<int> arr = {10, -10, 20, -40};
    // Set k
    int k = 6;

    // Print the Kth largest sum
    cout << getKthLargest(arr, k) << endl;

    return 0;
}
