/**
 * Approach-I:
 * Time Complexity: O(n*k log n*k)
 * Approach-II:
 * Time Complexity: O(n*k log k)
 * Space Complexity: O(n*k)
 * @brief This code demonstrates how to merge k sorted arrays into one sorted array using a min heap.
 *
 * The code defines a Node class to represent elements in the arrays, with each node containing the element itself,
 * the index of the array the element is from, and the index of the element in its array.
 *
 * It also defines a Comparator class to compare two nodes based on their data values.
 *
 * The mergeKSortedArrays function takes a vector of k sorted arrays and the number of sorted arrays as input.
 * It uses a priority queue (min heap) to store the smallest element not yet added to the final sorted array from each array.
 * The function inserts the first element of each array into the min heap, and then repeatedly extracts the smallest element
 * from the min heap, adds it to the final sorted array, and inserts the next element from the same array into the min heap
 * if there are more elements in that array.
 *
 * The function returns the final sorted array.
 *
 * The main function demonstrates the usage of the mergeKSortedArrays function by merging three sorted arrays and printing
 * the final sorted array.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class to represent elements in the arrays
class node
{
public:
    int data; // The element itself
    int i;    // The index of the array the element is from
    int j;    // The index of the element in its array

    // Constructor
    node(int d, int row, int col)
    {
        this->data = d;
        i = row;
        j = col;
    }
};

// Comparator for the priority queue
class compare
{
public:
    // Overloads the () operator to compare two nodes
    bool operator()(node *a, node *b)
    {
        // Returns true if a's data is greater than b's data
        return a->data > b->data;
    }
};

// Function to merge k sorted arrays
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Min heap to store the smallest element not yet added to the final sorted array from each array
    priority_queue<node *, vector<node *>, compare> minHeap;

    // Insert the first element of each array into the min heap
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    // Vector to store the final sorted array
    vector<int> ans;

    // While the min heap is not empty
    while (minHeap.size() > 0)
    {
        // Get the smallest element from the min heap
        node *temp = minHeap.top();
        minHeap.pop();

        // Add the smallest element to the final sorted array
        ans.push_back(temp->data);

        // If there are more elements in the smallest element's array
        if (temp->j + 1 < kArrays[temp->i].size())
        {
            // Insert the next element from the smallest element's array into the min heap
            node *next = new node(kArrays[temp->i][temp->j + 1], temp->i, temp->j + 1);
            minHeap.push(next);
        }
    }

    // Return the final sorted array
    return ans;
}

int main()
{
    // The k sorted arrays
    vector<vector<int>> kArrays = {{2, 6, 12, 15},
                                   {1, 3, 14, 20},
                                   {3, 5, 8, 10}};
    int k = 3; // The number of sorted arrays

    // Merge the k sorted arrays into one sorted array
    vector<int> ans = mergeKSortedArrays(kArrays, k);

    // Print the final sorted array
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
