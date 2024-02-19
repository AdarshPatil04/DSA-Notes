/**
 * The time complexity of the solution is O(n^2) and the space complexity is O(n^2).
 * @file topDown.cpp
 * @brief This file contains the implementation of a dynamic programming solution to the "Pizza With 3n Slices" problem.
 * The problem is to find the maximum sum of slices that can be taken from a pizza with 3n slices, where no adjacent slices can be taken.
 * The solution uses a top-down approach with memoization to optimize the recursive function.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using memoization
int solveMem(vector<int> &slices, int startIdx, int endIdx, int n, vector<vector<int>> &dp)
{
    // base case: if no slices left or indices crossed, return 0
    if (n == 0 || startIdx > endIdx)
        return 0;

    // if the subproblem has already been solved, return the stored result
    if (dp[startIdx][n] != -1)
        return dp[startIdx][n];

    // include: pick the slice at startIdx and move two steps ahead
    int include = slices[startIdx] + solveMem(slices, startIdx + 2, endIdx, n - 1, dp);

    // exclude: do not pick the slice at startIdx and move one step ahead
    int exclude = 0 + solveMem(slices, startIdx + 1, endIdx, n, dp);

    // store and return the maximum of include and exclude
    return dp[startIdx][n] = max(include, exclude);
}

// Function to find the maximum size of slices
int maxSizeSlices(vector<int> &slices)
{
    int k = slices.size();

    // Initialize the memoization tables
    vector<vector<int>> dp1(k, vector<int>(k, -1));
    vector<vector<int>> dp2(k, vector<int>(k, -1));

    // Two cases are considered because we can't take both the first and last slice
    // case1: consider slices from index 0 to k-2
    int case1 = solveMem(slices, 0, k - 2, k / 3, dp1);

    // case2: consider slices from index 1 to k-1
    int case2 = solveMem(slices, 1, k - 1, k / 3, dp2);

    // return the maximum of case1 and case2
    return max(case1, case2);
}

int main()
{
    // Initialize the slices
    vector<int> slices = {1, 2, 3, 4, 5, 6};

    // Print the maximum size of slices
    cout << maxSizeSlices(slices) << endl;

    return 0;
}
