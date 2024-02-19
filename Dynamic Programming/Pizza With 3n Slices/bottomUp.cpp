/**
 * The time complexity of the code is O(n^2) and the space complexity is O(n^2).
 * This code solves the problem of finding the maximum size of slices in a pizza with 3n slices.
 * It uses a bottom-up dynamic programming approach to calculate the maximum size of slices.
 * The code initializes two dp tables and fills them iteratively to find the maximum size of slices.
 */
// https://leetcode.com/problems/pizza-with-3n-slices/
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation
int solveTab(vector<int> &slices)
{
    int k = slices.size();
    // Initialize the dp tables
    vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
    vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

    // Fill the dp1 table considering slices from index 0 to k-2
    for (int i = k - 2; i >= 0; i--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            // include: pick the slice at index i and move two steps ahead
            int include = slices[i] + dp1[i + 2][n - 1];

            // exclude: do not pick the slice at index i and move one step ahead
            int exclude = 0 + dp1[i + 1][n];

            // store the maximum of include and exclude
            dp1[i][n] = max(include, exclude);
        }
    }
    // case1: maximum size of slices considering slices from index 0 to k-2
    int case1 = dp1[0][k / 3];

    // Fill the dp2 table considering slices from index 1 to k-1
    for (int i = k - 1; i >= 0; i--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            // include: pick the slice at index i and move two steps ahead
            int include = slices[i] + dp2[i + 2][n - 1];

            // exclude: do not pick the slice at index i and move one step ahead
            int exclude = 0 + dp2[i + 1][n];

            // store the maximum of include and exclude
            dp2[i][n] = max(include, exclude);
        }
    }
    // case2: maximum size of slices considering slices from index 1 to k-1
    int case2 = dp2[1][k / 3];

    // return the maximum of case1 and case2
    return max(case1, case2);
}

// Function to find the maximum size of slices
int maxSizeSlices(vector<int> &slices)
{
    // Tabulation
    return solveTab(slices);
}

int main()
{
    // Initialize the slices
    vector<int> slices = {1, 2, 3, 4, 5, 6};

    // Print the maximum size of slices
    cout << maxSizeSlices(slices) << endl;

    return 0;
}
