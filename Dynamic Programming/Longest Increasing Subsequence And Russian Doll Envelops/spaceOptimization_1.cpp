/**
 * The algorithm uses dynamic programming to solve the problem in O(n^2) time complexity and O(n) space complexity.
 * This code implements the space-optimized solution to find the length of the longest increasing subsequence in a given sequence of numbers.
 * It iterates over the numbers from right to left, considering each number as the last element of the increasing subsequence.
 * For each number, it checks if including the number in the subsequence results in a longer subsequence than excluding it.
 * The maximum length of the increasing subsequence is stored in the current row and updated in each iteration.
 * Finally, the maximum length of the increasing subsequence is returned.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using space optimization
int solveSO(vector<int> &nums, int n)
{
    // Initialize the current and next rows with 0
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

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
                include = 1 + nextRow[curr + 1]; // prev=curr & +1 due to -1-index

            // Exclude the current number from the increasing subsequence
            // The result is the same as the result from the next number with the same previous number
            int exclude = nextRow[prev + 1];

            // Store the maximum length of the increasing subsequence obtained by including or excluding the current number in the current row
            currRow[prev + 1] = max(include, exclude);
        }
        // Update the next row to be the current row
        nextRow = currRow;
    }
    // Return the maximum length of the increasing subsequence
    return nextRow[0];
}

// Function to find the length of the longest increasing subsequence
int lengthOfLIS(vector<int> &nums)
{
    // The length of the nums vector
    int n = nums.size();

    // Solve the problem using a space-optimized approach
    return solveSO(nums, n);
}

int main()
{
    // Test case: Numbers in the sequence
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Print the length of the longest increasing subsequence
    cout << lengthOfLIS(nums) << endl;

    return 0;
}
