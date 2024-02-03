/**
 * Time Complexity: O(nlogk)
 * Space Complexity: O(n)
 * @brief This program finds the kth smallest element in an array using a max heap.
 * 
 * The program uses a priority queue (max heap) to store the k smallest elements from the array.
 * It iterates through the remaining elements of the array and compares them with the top element of the heap.
 * If an element is smaller than the top element, it replaces the top element and maintains the heap property.
 * Finally, the top element of the heap is the kth smallest element in the array.
 * 
 * @return int The kth smallest element in the array.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the kth smallest element in the array
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq; // Create a max heap

        // Step-1 : create a max heap for the first k-elements
        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        // Step-2 : If element is less than array's top
        for (int i = k; i <= r; i++)
        {
            if (arr[i] < pq.top())
            {
                pq.pop();        // Remove the top element from the heap
                pq.push(arr[i]); // Insert the current element into the heap
            }
        }

        // The top of the heap is the kth smallest element
        int ans = pq.top();
        return ans;
    }
};

int main()
{
    int a[6] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    Solution ob;
    cout << ob.kthSmallest(a, 0, 5, k) << endl;
    return 0;
}
