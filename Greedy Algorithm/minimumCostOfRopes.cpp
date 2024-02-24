/**
 * Time Complexity: O(nlogn)    
 * Space Complexity: O(n)
 * This program calculates the minimum cost of connecting ropes.
 * Given an array of lengths of ropes, the program finds the minimum cost
 * of connecting all the ropes together. The cost of connecting two ropes
 * is equal to the sum of their lengths. The program uses a priority queue
 * to efficiently find the two shortest ropes and connect them until only
 * one rope remains. The total cost of connecting all the ropes is then returned.
 */
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Function to return the minimum cost of connecting the ropes.
long long minCost(long long arr[], long long n)
{
    // Create a priority queue to store the lengths of the ropes
    // The queue is ordered in ascending order using a greater comparator
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    // Push all the lengths of the ropes into the priority queue
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    // Initialize the total cost to 0
    long long cost = 0;

    // While there is more than one rope in the priority queue
    while (pq.size() > 1)
    {
        // Pop the two shortest ropes from the priority queue
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        // The cost of connecting these two ropes is the sum of their lengths
        long long sum = a + b;
        // Add this cost to the total cost
        cost += sum;

        // Push the length of the new rope back into the priority queue
        pq.push(sum);
    }
    // Return the total cost of connecting all the ropes
    return cost;
}

int main()
{
    // Array of lengths of ropes
    long long arr[] = {4, 2, 7, 6, 9};
    // Number of ropes
    long long n = 5;
    // Calculate and print the minimum cost of connecting the ropes
    cout << minCost(arr, n);
    return 0;
}
