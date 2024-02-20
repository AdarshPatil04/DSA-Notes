/**
 * The time complexity of the code is O(n^2) and the space complexity is O(n^2).
 * This code implements the solution to find the length of the longest arithmetic sequence
 * in an array using recursive function with memoization technique.
 * The code calculates the difference between each pair of numbers in the array and checks if
 * there is a sequence with the same difference. It uses memoization to store the computed results
 * and avoid redundant calculations.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem with memoization
int solveMem(vector<int> &nums, int index, int diff, unordered_map<int, int> dp[])
{
    // Base case: if index is less than 0, return 0
    if (index < 0)
        return 0;

    // If the difference is already computed for the current index, return it
    if (dp[index].count(diff))
        return dp[index][diff];

    int ans = 0;
    // Backward logic: iterate from the current index to 0
    for (int j = index - 1; j >= 0; j--)
    {
        // If the difference between the current number and the j-th number equals the given difference
        if (nums[index] - nums[j] == diff)
            // Update the answer with the maximum value between the current answer and 1 plus the result of the recursive call
            ans = max(ans, (1 + solveMem(nums, j, diff, dp)));
    }
    // Store the computed answer for the current index and difference in the dp array
    return dp[index][diff] = ans;
}

// Function to find the length of the longest arithmetic sequence
int longestArithSeqLength(vector<int> &nums)
{
    // Get the size of the array
    int n = nums.size();
    // If the size is less than or equal to 2, return the size
    if (n <= 2)
        return n;
    int ans = 0;
    // Initialize the dp array for memoization
    unordered_map<int, int> dp[n + 1];
    // Iterate over the array
    for (int i = 0; i < n; i++)
    {
        // For each number, iterate over the rest of the array
        for (int j = i + 1; j < n; j++)
        {
            // Calculate the difference between the current number and the j-th number
            int diff = nums[j] - nums[i];
            // Update the answer with the maximum value between the current answer and 2 plus the result of the recursive call
            ans = max(ans, (2 + solveMem(nums, i, diff, dp)));
        }
    }
    // Return the answer
    return ans;
}

int main()
{
    // Define the array
    vector<int> nums = {3, 6, 9, 12};
    // Print the length of the longest arithmetic sequence
    cout << longestArithSeqLength(nums) << endl;
    return 0;
}
