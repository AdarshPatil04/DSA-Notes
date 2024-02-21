/**
 * The time complexity of the solution is O(n^3) and the space complexity is O(n^2), where n is the number of elements in the input array.
 * This code implements a solution to the problem of finding the minimum cost to build a binary tree from the given leaf values.
 * The code uses a recursive approach with memoization to optimize the computation.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem with memoization
int solveMem(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
{
    // Base case: if left is equal to right, return 0
    if (left == right)
        return 0;

    // If the minimum cost for the current left and right is already computed, return it
    if (dp[left][right] != -1)
        return dp[left][right];

    // Initialize the minimum cost with the maximum possible integer
    int mini = INT_MAX;
    // Iterate from left to right, considering each number as the partition point
    for (int k = left; k < right; k++)
    {
        // Update the minimum cost with the minimum value between the current minimum cost and
        // the sum of the product of the maximum values for the left and right subarrays and
        // the result of the recursive calls for the left and right subarrays
        mini = min(mini, maxi[{left, k}] * maxi[{k + 1, right}] + solveMem(arr, maxi, left, k, dp) + solveMem(arr, maxi, k + 1, right, dp));
    }
    // Store the computed minimum cost for the current left and right in the dp array
    return dp[left][right] = mini;
}

// Function to get the minimum cost to build a binary tree from the leaf values
int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();

    // Initialize the map to store the maximum values for each subarray
    map<pair<int, int>, int> maxi;
    for (int i = 0; i < n; i++)
    {
        // Store the maximum value for the subarray with a single element
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            // Store the maximum value for the subarray from i to j
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }

    // Initialize the dp array for memoization
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // Call the recursive function to solve the problem
    return solveMem(arr, maxi, 0, n - 1, dp);
}

int main()
{
    // Define the array
    vector<int> arr = {6, 2, 4};
    // Print the minimum cost to build a binary tree from the leaf values
    cout << mctFromLeafValues(arr) << endl;
    return 0;
}
