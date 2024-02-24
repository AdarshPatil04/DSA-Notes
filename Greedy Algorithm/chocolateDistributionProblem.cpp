/**
 * Time Complexity: O(nlogn)
 * Space Complexity: O(1)
 * @brief This code solves the chocolate distribution problem.
 * 
 * The problem is to find the minimum difference between the maximum and minimum number of chocolates
 * that can be distributed among a given number of students, where each student must receive exactly
 * one packet of chocolates. The code uses a greedy approach to sort the array of chocolates and
 * find the minimum difference by iterating over a subarray of size m.
 * 
 * @link https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
 * 
 * @param a The array of chocolates
 * @param n The number of packets
 * @param m The number of students
 * @return The minimum difference between the maximum and minimum number of chocolates
 */

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum difference between the maximum and minimum number of chocolates
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // Sort the array of chocolates
    sort(a.begin(), a.end());

    // Initialize variables
    int i = 0;          // Start index of the subarray of size m
    int j = m - 1;      // End index of the subarray of size m
    int mini = INT_MAX; // Minimum difference

    // Iterate over the array while the end index is less than the size of the array
    while (j < n)
    {
        // Calculate the difference between the maximum and minimum number of chocolates in the subarray
        int diff = a[j] - a[i];
        // Update the minimum difference
        mini = min(mini, diff);
        // Move the start and end indices of the subarray
        i++;
        j++;
    }
    // Return the minimum difference
    return mini;
}

int main()
{
    // Number of packets
    long long n = 8;
    // Number of students
    long long m = 5;
    // Number of chocolates in each packet
    vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};
    // Calculate and print the minimum difference between the maximum and minimum number of chocolates
    cout << findMinDiff(a, n, m);
    return 0;
}
