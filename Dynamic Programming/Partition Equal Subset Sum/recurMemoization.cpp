/**
 * // Time Complexity => O(n^2)  -> O(index*target)
// Space Complexity => O(n^2) -> O(index*target)
 * This code solves the problem of partitioning an array into two subsets of equal sum using memoization technique.
 * It checks if it is possible to divide the array into two subsets such that the sum of elements in both subsets is equal.
 * The code uses a recursive approach with memoization to optimize the solution.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using memoization
bool solveMem(vector<int> &nums, int target, int index, vector<vector<int>> &dp)
{
    int n = nums.size();
    // base case: if target is 0, return true
    if (target == 0)
        return 1;

    // base case: if target is less than 0, return false
    if (target < 0)
        return 0;

    // base case: if all elements are used and target is not 0, return false
    if (index >= n)
        return 0;

    // if the subproblem has already been solved, return the stored result
    if (dp[index][target] != -1)
        return dp[index][target];

    // include: pick the element at index and subtract it from the target
    bool incl = solveMem(nums, target - nums[index], index + 1, dp);

    // exclude: do not pick the element at index
    bool excl = solveMem(nums, target, index + 1, dp);

    // store the result in the dp table and return it
    return dp[index][target] = (incl || excl);
}

// Function to check if the array can be partitioned into two subsets of equal sum
bool canPartition(vector<int> &nums)
{
    int target = 0;
    int index = 0;
    // calculate the total sum of the array
    for (int i = 0; i < nums.size(); i++)
    {
        target += nums[i];
    }
    // if the total sum is odd, return false
    if (target & 1)
        return 0;
    // the target sum for each subset is half of the total sum
    target = target / 2;

    // Memoization
    // Initialize the dp table
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
    return solveMem(nums, target, index, dp);
}

int main()
{
    // Initialize the array
    vector<int> nums = {1, 5, 11, 5};

    // Print the result of the function
    cout << canPartition(nums) << endl;

    return 0;
}
