/**
 * The time complexity of the code is O(N) + O(N), where N is the length of the rod.
 * The space complexity is O(N) for the recursion depth and the dynamic programming array.
 * This code solves the problem of cutting a rod of length 'n' into segments of lengths 'x', 'y', and 'z'.
 * The goal is to find the maximum number of segments that can be obtained.
 * The code uses a top-down approach with recursion and memoization to optimize the solution.
 * It calculates the maximum number of cuts for each rod length and stores the results in a dynamic programming array.
 */
// https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using recursion and memoization
// Time Complexity => O(N)
// Space Complexity => O(N) + O(N) => space of recursion depth & of dp-array
int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    // base case: if n is zero, no cuts are needed
    if (n == 0)
        return 0;
    // if n is less than zero, return INT_MIN as this state is not possible
    if (n < 0)
        return INT_MIN;

    // if the value is already computed, return it
    if (dp[n] != -1)
        return dp[n];

    // calculate the maximum number of cuts for each rod length
    int a = solveMem(n - x, x, y, z, dp) + 1; // for rod length x
    int b = solveMem(n - y, x, y, z, dp) + 1; // for rod length y
    int c = solveMem(n - z, x, y, z, dp) + 1; // for rod length z

    // store the maximum among a, b, and c in dp[n]
    dp[n] = max(a, max(b, c));
    return dp[n];
}

// Function to find the maximum number of segments of lengths x, y, and z
int cutSegments(int n, int x, int y, int z)
{
    // Recursion + Memoization -> Top-Down Approach
    // step-1: creation of dp vector
    vector<int> dp(n + 1, -1);
    int ans = solveMem(n, x, y, z, dp);
    // if ans is less than zero, return 0 as it means no valid cuts can be made
    if (ans < 0)
        return 0;
    else
        return ans; // return the maximum number of cuts
}

int main()
{
    int n = 5, x = 2, y = 5, z = 1;          // initialize rod length and segment lengths
    cout << cutSegments(n, x, y, z) << endl; // print the maximum number of cuts
    return 0;
}
