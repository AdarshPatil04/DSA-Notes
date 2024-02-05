/**
 * This program calculates the median of a stream of integers using two heaps.
 * It implements two approaches:
 * 1. Insertion sort approach: O(n^2) time complexity.
 * 2. Heap approach: O(nlogn) time complexity.
 * 
 * The program defines a function `findMedian` that takes an array of integers and its size as input.
 * It uses two priority queues (max heap and min heap) to maintain the elements in the stream.
 * The `callMedian` function is called for each element in the stream to calculate the median.
 * The medians are stored in a vector and returned as the output.
 * 
 * The main function demonstrates the usage of the `findMedian` function with a sample input array.
 */
// Approach-1
// Use Insertion sort -> O(n^2)
//  median -> odd = middle[arr(n/2)]             -> O(1)
//  median -> even = [arr(n-1/2) + arr(n/2)]/2   -> O(1)
//  Insertion for a new Element -> O(n)

// Approach-2
// TC = NLogN where N is the no. of element present in the input

#include <bits/stdc++.h>
using namespace std;

// Function to compare two integers and return a signum value
int signum(int a, int b)
{
    if (a == b)
        return 0; // return 0 if both are equal
    else if (a > b)
        return 1; // return 1 if a is greater than b
    else
        return -1; // return -1 if a is less than b
}

// Function to calculate the median of the input stream
void callMedian(int element, priority_queue<int> &maxi,
                priority_queue<int, vector<int>, greater<int>> &mini, int &median)
{
    // Switch case based on the signum function
    switch (signum(maxi.size(), mini.size()))
    {
    case 0: // if sizes of heaps are equal
        if (element > median)
        {
            mini.push(element);  // push element to min heap if it is greater than median
            median = mini.top(); // update median
        }
        else
        {
            maxi.push(element);  // push element to max heap if it is less than median
            median = maxi.top(); // update median
        }
        break;

    case 1: // if size of max heap is greater than size of min heap
        if (element > median)
        {
            mini.push(element); // push element to min heap if it is greater than median
        }
        else
        {
            mini.push(maxi.top()); // push top of max heap to min heap
            maxi.pop();            // pop the top element from max heap
            maxi.push(element);    // push element to max heap
        }
        median = (maxi.top() + mini.top()) / 2; // update median
        break;

    case -1: // if size of min heap is greater than size of max heap
        if (element > median)
        {
            maxi.push(mini.top()); // push top of min heap to max heap
            mini.pop();            // pop the top element from min heap
            mini.push(element);    // push element to min heap
        }
        else
        {
            maxi.push(element); // push element to max heap
        }
        median = (maxi.top() + mini.top()) / 2; // update median
        break;
    }
}

// Function to find the median of the input stream
vector<int> findMedian(vector<int> &arr, int n)
{
    priority_queue<int> maxHeap;                            // max heap
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap
    vector<int> ans;                                        // vector to store the medians
    int median = 0;                                         // initialize median

    // iterate over the array
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];                          // get the element
        callMedian(element, maxHeap, minHeap, median); // call the function to calculate the median

        ans.push_back(median); // push the median to the vector
    }
    return ans; // return the vector of medians
}

int main()
{
    vector<int> arr = {5, 15, 10, 20, 3}; // input array
    cout << "Input: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " "; // print the input array
    }
    int n = arr.size();                   // size of the array
    vector<int> ans = findMedian(arr, n); // call the function to find the medians
    cout << "\nOutput: ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " "; // print the medians
    }
    return 0;
}
