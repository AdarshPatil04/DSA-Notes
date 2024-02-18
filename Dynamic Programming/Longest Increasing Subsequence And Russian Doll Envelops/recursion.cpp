/**
 * The time complexity of the code is exponential O(2^n) and the space complexity is O(n).
 * This code implements a recursive solution to find the length of the longest increasing subsequence in a given sequence of numbers.
 * The code uses a recursive function to explore all possible subsequences and returns the maximum length of the increasing subsequence.
 * The code is based on the problem "Longest Increasing Subsequence" on LeetCode.
 */
// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(vector<int> &nums, int n, int curr, int prev)
{
    // Base case: If we have reached the end of the nums vector, return 0
    if (curr == n)
        return 0;

    // Include the current number in the increasing subsequence
    // Only include the number if it is greater than the previous number or if there is no previous number (prev == -1)
    // The length of the increasing subsequence is increased by 1
    // Recursively solve for the next number with the current number as the new previous number
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
        include = 1 + solveRec(nums, n, curr + 1, curr);

    // Exclude the current number from the increasing subsequence
    // Recursively solve for the next number with the same previous number
    int exclude = solveRec(nums, n, curr + 1, prev);

    // Return the maximum length of the increasing subsequence obtained by including or excluding the current number
    return max(include, exclude);
}

// Function to find the length of the longest increasing subsequence
int lengthOfLIS(vector<int> &nums)
{
    // The length of the nums vector
    int n = nums.size();

    // Solve the problem using recursion starting from the first number with no previous number (-1)
    return solveRec(nums, n, 0, -1);
}

int main()
{
    // Test case: Numbers in the sequence
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Print the length of the longest increasing subsequence
    cout << lengthOfLIS(nums) << endl;

    return 0;
}
