/**
 * The time complexity of the solution is O(N), where N is the number of elements in the array.
 * The space complexity is O(1) as it uses only a constant amount of space.
 * This code solves the problem of finding the maximum sum of non-adjacent elements in an array.
 * It uses a bottom-up approach (tabulation) with space optimization to efficiently calculate the maximum sum.
 */
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using a bottom-up approach (tabulation) with space optimization
int solveSpaceOpt(vector<int> &nums)
{
    // Get the size of the array
    int n = nums.size();

    // Initialize the maximum sums for the first two elements
    int prev1 = nums[0];
    int prev2 = 0;

    // Iterate over each element in the array starting from the second element
    for (int i = 1; i < n; i++)
    {
        // For each element, calculate the maximum sum including and excluding the current element
        int incl = prev2 + nums[i]; // Include the current element and the maximum sum for the element two positions before
        int excl = prev1;           // Exclude the current element and take the maximum sum for the previous element

        // Calculate the maximum of incl and excl
        int ans = max(incl, excl);

        // Update the maximum sums for the next iteration
        prev2 = prev1;
        prev1 = ans;
    }

    // Return the maximum sum for the last element
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Call the space-optimized function to solve the problem
    int ans = solveSpaceOpt(nums);

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
