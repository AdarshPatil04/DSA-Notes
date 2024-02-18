/**
 * The code uses dynamic programming to solve the problem in O(n^2) time complexity and O(n^2) space complexity.
 * This code implements the tabulation approach to find the length of the longest increasing subsequence in a given sequence of numbers.
 * The main function, lengthOfLIS, takes a vector of integers as input and returns the length of the longest increasing subsequence.
 * The solveTab function is a helper function that performs the tabulation process to calculate the maximum length of the increasing subsequence.
 * The code includes comments to explain the logic and steps involved in the tabulation approach.
 * The main function tests the code by providing a sample sequence of numbers and printing the length of the longest increasing subsequence.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation
int solveTab(vector<int> &nums, int n)
{
    // Initialize the dp table with 0
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Iterate over the numbers from right to left
    for (int curr = n - 1; curr >= 0; curr--)
    {
        // Iterate over the previous numbers from the current number to -1
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // Include the current number in the increasing subsequence
            // Only include the number if there is no previous number (prev == -1) or if it is greater than the previous number
            // The length of the increasing subsequence is increased by 1
            // Add the result from the next number with the current number as the new previous number
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
                include = 1 + dp[curr + 1][curr + 1]; // prev=curr & +1 due to -1-index

            // Exclude the current number from the increasing subsequence
            // The result is the same as the result from the next number with the same previous number
            int exclude = dp[curr + 1][prev + 1];

            // Store the maximum length of the increasing subsequence obtained by including or excluding the current number in the dp table
            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    // Return the maximum length of the increasing subsequence
    return dp[0][0];
}

// Function to find the length of the longest increasing subsequence
int lengthOfLIS(vector<int> &nums)
{
    // The length of the nums vector
    int n = nums.size();

    // Solve the problem using tabulation
    return solveTab(nums, n);
}

int main()
{
    // Test case: Numbers in the sequence
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Print the length of the longest increasing subsequence
    cout << lengthOfLIS(nums) << endl;

    return 0;
}
