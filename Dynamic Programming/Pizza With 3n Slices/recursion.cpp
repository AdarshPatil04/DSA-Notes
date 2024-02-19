/**
 * The time complexity of the code is O(2^n) and the space complexity is O(n) due to the recursive call stack.
 * @brief This code solves the problem of finding the maximum size of slices from a given pizza with 3n slices.
 * The code uses a recursive approach to consider two cases:
 * - Case 1: considering slices from index 0 to k-2
 * - Case 2: considering slices from index 1 to k-1
 * The function `maxSizeSlices` calculates the maximum size of slices by calling the `solveRec` recursive function.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(vector<int> &slices, int startIdx, int endIdx, int n)
{
    // base case: if no slices left or indices crossed, return 0
    if (n == 0 || startIdx > endIdx)
        return 0;

    // include: pick the slice at startIdx and move two steps ahead
    int include = slices[startIdx] + solveRec(slices, startIdx + 2, endIdx, n - 1);

    // exclude: do not pick the slice at startIdx and move one step ahead
    int exclude = 0 + solveRec(slices, startIdx + 1, endIdx, n);

    // return the maximum of include and exclude
    return max(include, exclude);
}

// Function to find the maximum size of slices
int maxSizeSlices(vector<int> &slices)
{
    int k = slices.size();

    // Recursion: Two cases are considered because we can't take both the first and last slice
    // case1: consider slices from index 0 to k-2
    int case1 = solveRec(slices, 0, k - 2, k / 3);

    // case2: consider slices from index 1 to k-1
    int case2 = solveRec(slices, 1, k - 1, k / 3);

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
