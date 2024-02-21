/**
 *        The time complexity of the algorithm is O(n^2) and the space complexity is O(n).
 * @brief This code calculates the number of unique binary search trees that can be formed using n nodes.
 *        It uses a recursive approach with memoization to optimize the computation.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem with memoization
int solveMem(int n, vector<int> &dp)
{
    // Base case: if n is less than or equal to 1, return 1
    if (n <= 1)
        return 1;

    // If the number of unique binary search trees for n is already computed, return it
    if (dp[n] != -1)
        return dp[n];

    int ans = 0;
    // Iterate from 1 to n, considering each number as the root node
    for (int i = 1; i <= n; i++)
    {
        // Update the answer with the sum of the current answer and
        // the product of the number of unique binary search trees for the left subarray and the right subarray
        ans += solveMem(i - 1, dp) * solveMem(n - i, dp);
    }
    // Store the computed number of unique binary search trees for n in the dp array
    return dp[n] = ans;
}

// Function to get the number of unique binary search trees
int numTrees(int n)
{
    // Initialize the dp array for memoization
    vector<int> dp(n + 1, -1);
    // Call the recursive function to solve the problem
    return solveMem(n, dp);
}

int main()
{
    // Define the number
    int n = 3;
    // Print the number of unique binary search trees
    cout << numTrees(n) << endl;
    return 0;
}