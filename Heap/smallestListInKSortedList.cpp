// This code solves the problem of finding the smallest range in a K-sorted list.
// The input is a matrix 'a' representing K sorted lists, where each list has 'n' elements.
// The code uses a priority queue (min heap) to store the minimum element from each list.
// It starts by inserting the first element from each list into the heap and finding the maximum.
// Then, it repeatedly pops the minimum element from the heap and pushes the next element from the same list.
// During this process, it updates the minimum, maximum, and the range.
// Finally, it returns the smallest range in the K-sorted list.

// The time complexity of the code is O(n*klog(k)), where 'n' is the size of each list and 'k' is the number of lists.
// The space complexity is O(k), where 'k' is the number of lists.
// The code uses a node class to store the data and its position in the matrix, and a comparator class for the priority queue.
// It also includes a main function to test the code with a sample input.
// Q : Smallest List In K-sorted list
// link: https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356

// approach 1 -> calculate all possible ranges
//  Total no. of elements = n*k
//  TC => O(N^2*K^2) in finding all possible ranges
//  difference of each range
//  smallest && atleast 1-element in each list => store

// approach 2 -> without using any heap
//  create a array DS
//  Insert the first element from each list
//  initialise min/max
//  cond => smallest range && at least 1-element
//  find difference -> smallest -> store
//  increase min. element value from the list

// TC => O(n*K^2)
// SC => O(K)
// prefer copy/slide for better understanding

// approach 3 -> Using a minHeap to optimize the min/max tc from o(k) to o(logk)
// since heap can find min/max in O(1) but insertion of elements take O(logk)
// Time complexity => O(n*klog(k))
// space complexity => O(k)

#include <bits/stdc++.h>
using namespace std;

// Node class to store data and its position in the matrix
class node
{
public:
    int data; // The value in the matrix
    int row;  // The row index in the matrix
    int col;  // The column index in the matrix

    // Constructor to initialize the node
    node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

// Comparator class for the priority queue
class compare
{
public:
    // Overloading the operator() to make a min heap based on the data of the nodes
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

// Function to find the smallest range in 'k' lists
int kSorted(vector<vector<int>> &a, int k, int n)
{
    // Initialize the minimum and maximum
    int mini = INT_MAX;
    int maxi = INT_MIN;

    // Priority queue (min heap) to store the minimum element from each list
    priority_queue<node *, vector<node *>, compare> pq;

    // Step 1: Insert the first element of each list in the heap & find the maximum
    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        pq.push(new node(element, i, 0));
    }

    // Initialize the start and end according to the maximum and minimum
    int start = mini;
    int end = maxi;

    // Step 2: Pop the minimum and push the next element from the same list
    while (!pq.empty())
    {
        // Fetch the node with the minimum data and remove it from the heap
        node *temp = pq.top();
        pq.pop();

        // Update the minimum
        mini = temp->data;

        // Update the range and maximum
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // If the next element exists, push it into the heap
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            pq.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            // If no more elements are there in the list, break the loop
            break;
        }
    }

    // Return the range
    return (end - start + 1);
}

int main()
{
    // Input matrix
    vector<vector<int>> a = {{1, 3, 5, 7},
                             {2, 4, 6, 8},
                             {0, 9, 10, 11}};
    int k = 3; // Number of lists
    int n = 4; // Size of each list

    // Call the function and print the result
    cout << kSorted(a, k, n);

    return 0;
}
