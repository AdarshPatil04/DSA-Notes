/**
 * The time complexity of the code is O(2^n) and the space complexity is O(n).
 * This code implements a solution to the problem of finding the minimum cost to build a binary tree from the given leaf values.
 * The code uses a recursive approach to calculate the minimum cost by considering each number as the partition point.
 * It also utilizes dynamic programming to store the maximum values for each subarray, which helps in optimizing the solution.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    // Base case: if left is equal to right, return 0
    if (left == right)
        return 0;

    int mini = INT_MAX;
    // Iterate from left to right, considering each number as the partition point
    for (int k = left; k < right; k++)
    {
        // Update the minimum value with the minimum value between the current minimum value and
        // the sum of the product of the maximum values for the left and right subarrays and
        // the result of the recursive calls for the left and right subarrays
        mini = min(mini, maxi[{left, k}] * maxi[{k + 1, right}] + solveRec(arr, maxi, left, k) + solveRec(arr, maxi, k + 1, right));
    }
    // Return the minimum value
    return mini;
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
    // Call the recursive function to solve the problem
    return solveRec(arr, maxi, 0, n - 1);
}

int main()
{
    // Define the array
    vector<int> arr = {6, 2, 4};
    // Print the minimum cost to build a binary tree from the leaf values
    cout << mctFromLeafValues(arr) << endl;
    return 0;
}
