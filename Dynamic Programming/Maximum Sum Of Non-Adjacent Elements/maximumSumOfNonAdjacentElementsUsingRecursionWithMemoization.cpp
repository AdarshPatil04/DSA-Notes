/**
 * The time complexity of the code is O(N) + O(N), where N is the number of elements in the array, and the space complexity is O(N).
 * This code solves the problem of finding the maximum sum of non-adjacent elements in an array using a top-down approach with memoization.
 * The function `maximumNonAdjacentSum` takes an array of integers as input and returns the maximum sum of non-adjacent elements.
 * The code uses recursion to explore all possible combinations of including or excluding each element in the sum.
 * It also uses memoization to store the results of subproblems, avoiding redundant calculations and improving performance.
 */
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem using a top-down approach (memoization)
int solveMem(vector<int> &nums, int n, vector<int> &dp)
{
    // Base case: If n is less than 0, return 0
    if (n < 0)
        return 0;

    // Base case: If n is 0, return the first element of the array
    if (n == 0)
        return nums[0];

    // If the subproblem has already been solved, return the stored result
    if (dp[n] != -1)
        return dp[n];

    // Recursive calls:
    // incl represents the maximum sum including the current element
    // excl represents the maximum sum excluding the current element
    int incl = solveMem(nums, n - 2, dp) + nums[n];
    int excl = solveMem(nums, n - 1, dp);

    // Store the maximum of incl and excl in the dp array
    dp[n] = max(incl, excl);

    // Return the maximum of incl and excl
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Get the size of the array
    int n = nums.size();

    // Initialize the dp array with -1
    vector<int> dp(n, -1);

    // Call the recursive function to solve the problem
    int ans = solveMem(nums, n - 1, dp);

    // Return the result
    return ans;
}

int main()
{
    // Define the array of numbers
    vector<int> nums = {5, 5, 10, 100, 10, 5};

    // Call the function to find the maximum sum of non-adjacent elements
    // Print the result
    cout << maximumNonAdjacentSum(nums);

    return 0;
}
