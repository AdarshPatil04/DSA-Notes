/**
 * This code solves the problem of finding the maximum sum of non-adjacent elements in an array.
 * It uses a bottom-up approach (tabulation) to calculate the maximum sum.
 * The time complexity of the solution is O(N), where N is the number of elements in the array.
 * The space complexity is O(N) for the dp array.
 */
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using a bottom-up approach (tabulation)
int solveTab(vector<int> &nums)
{
    // Get the size of the array
    int n = nums.size();

    // If the array is empty, return 0
    if (n == 0)
        return 0;

    // If the array has only one element, return that element
    if (n == 1)
        return nums[0];

    // Create a dp array with size n and initialize the first two elements
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // Iterate over each element in the array starting from the third element
    for (int i = 2; i < n; i++)
    {
        // For each element, calculate the maximum sum including and excluding the current element
        int incl = dp[i - 2] + nums[i]; // Include the current element and the maximum sum for the element two positions before
        int excl = dp[i - 1];           // Exclude the current element and take the maximum sum for the previous element

        // Store the maximum of incl and excl in the dp array
        dp[i] = max(incl, excl);
    }

    // Return the maximum sum for the last element in the dp array
    return dp[n - 1];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Call the tabulation function to solve the problem
    int ans = solveTab(nums);

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
