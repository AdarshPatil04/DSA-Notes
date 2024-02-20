/**
 * // Time Complexity => O(n^2)  -> O(index*target)
// Space Complexity => O(n^2) -> O(index*target)
 * This code solves the problem of partitioning an array into two subsets of equal sum using tabulation.
 * It uses dynamic programming to calculate the number of ways to achieve the target sum.
 * The code initializes a dp table and iterates through the elements and target sums to calculate the number of ways.
 * It returns true if the array can be partitioned into two subsets of equal sum, otherwise false.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation
bool solveTab(vector<int> &nums, int target)
{
    int n = nums.size();
    // Initialize the dp table
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: if there are no elements left and target is 0, return true
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // For each element
    for (int index = n - 1; index >= 0; index--)
    {
        // For each target sum
        for (int tar = 0; tar <= target; tar++)
        {
            bool incl = 0;
            // If the target sum is greater than or equal to the current element
            if (tar - nums[index] >= 0)
                // Add the number of ways to get the target sum by including the current element
                incl = dp[index + 1][tar - nums[index]];

            // Do not pick the element at index
            bool excl = dp[index + 1][tar];

            // Store the result in the dp table
            dp[index][tar] = (incl || excl);
        }
    }
    // Return the number of ways to get the target sum
    return dp[0][target];
}

// Function to check if the array can be partitioned into two subsets of equal sum
bool canPartition(vector<int> &nums)
{
    int target = 0;
    int index = 0;
    // Calculate the total sum of the array
    for (int i = 0; i < nums.size(); i++)
    {
        target += nums[i];
    }
    // If the total sum is odd, return false
    if (target & 1)
        return 0;
    // The target sum for each subset is half of the total sum
    target = target / 2;

    // Tabulation
    return solveTab(nums, target);
}

int main()
{
    // Initialize the array
    vector<int> nums = {1, 5, 11, 5};

    // Print the result of the function
    cout << canPartition(nums) << endl;

    return 0;
}
