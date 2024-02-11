/**
 * The time complexity of the recursive function is exponential (3^N) and the space complexity is constant.
 * This code solves the problem of cutting a rod of length 'n' into segments of lengths 'x', 'y', and 'z'.
 * The goal is to find the maximum number of segments that can be obtained.
 * The code uses a recursive approach to calculate the maximum number of cuts.
 */
// https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(int n, int x, int y, int z)
{
    // base case: if n is zero, no cuts are needed
    if (n == 0)
        return 0;
    // if n is less than zero, return INT_MIN as this state is not possible
    if (n < 0)
        return INT_MIN;

    // calculate the maximum number of cuts for each rod length
    int a = solveRec(n - x, x, y, z) + 1; // for rod length x
    int b = solveRec(n - y, x, y, z) + 1; // for rod length y
    int c = solveRec(n - z, x, y, z) + 1; // for rod length z

    // find the maximum among a, b, and c
    int ans = max(a, max(b, c));
    return ans;
}

// Function to find the maximum number of segments of lengths x, y, and z
int cutSegments(int n, int x, int y, int z)
{
    // Recursive Solution
    int ans = solveRec(n, x, y, z);
    // if ans is less than zero, return 0 as it means no valid cuts can be made
    if (ans < 0)
        return 0;
    else
        return ans; // return the maximum number of cuts
}

int main()
{
    int n = 5, x = 2, y = 5, z = 1;  // initialize rod length and segment lengths
    cout << cutSegments(n, x, y, z); // print the maximum number of cuts
    return 0;
}
