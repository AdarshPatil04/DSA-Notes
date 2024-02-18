/**
 * The time complexity of the solution is O(n^2) and the space complexity is O(n^2).
 * This code implements the solution to find the length of the longest increasing subsequence using memoization.
 * The code uses a recursive approach with memoization to avoid redundant computations.
 * The code takes a vector of integers as input and returns the length of the longest increasing subsequence.
 * It initializes a dp table with -1 and solves the problem recursively, considering two cases: including or excluding the current number.
 * The maximum length of the increasing subsequence is stored in the dp table to avoid recomputation.
 * Finally, the length of the longest increasing subsequence is printed.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem using memoization
int solveMem(vector<int> &nums, int n, int curr, int prev, vector<vector<int>> &dp)
{
    // Base case: If we have reached the end of the nums vector, return 0
    if (curr == n)
        return 0;

    // If we have already computed the result for this index and previous index, return it
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // Include the current number in the increasing subsequence
    // Only include the number if it is greater than the previous number or if there is no previous number (prev == -1)
    // The length of the increasing subsequence is increased by 1
    // Recursively solve for the next number with the current number as the new previous number
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
        include = 1 + solveMem(nums, n, curr + 1, curr, dp);

    // Exclude the current number from the increasing subsequence
    // Recursively solve for the next number with the same previous number
    int exclude = solveMem(nums, n, curr + 1, prev, dp);

    // Store the maximum length of the increasing subsequence obtained by including or excluding the current number in the dp table
    return dp[curr][prev + 1] = max(include, exclude);
}

// Function to find the length of the longest increasing subsequence
int lengthOfLIS(vector<int> &nums)
{
    // The length of the nums vector
    int n = nums.size();

    // Initialize the dp table with -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // Solve the problem using memoization starting from the first number with no previous number (-1)
    return solveMem(nums, n, 0, -1, dp);
}

int main()
{
    // Test case: Numbers in the sequence
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Print the length of the longest increasing subsequence
    cout << lengthOfLIS(nums) << endl;

    return 0;
}
