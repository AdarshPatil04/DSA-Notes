/**
// Time Complexity => O(n^2) -> O(index*target)
// Space Complexity => O(n)  -> O(target)
 * This code solves the problem of partitioning an array into two subsets of equal sum.
 * It uses space-optimized dynamic programming to find the number of ways to achieve the target sum.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using space optimized dynamic programming
bool solveSO(vector<int> &nums, int target)
{
    int n = nums.size();
    // Initialize the dp vectors
    vector<int> curr(target + 1, 0);
    vector<int> next(target + 1, 0);

    // Base case: if there are no elements left and target is 0, return true
    curr[0] = 1;
    next[0] = 1;

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
                incl = next[tar - nums[index]];

            // Do not pick the element at index
            bool excl = next[tar];

            // Store the result in the curr vector
            curr[tar] = (incl || excl);
        }
        // Update the next vector for the next iteration
        next = curr;
    }
    // Return the number of ways to get the target sum
    return next[target];
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

    // Space Optimization
    return solveSO(nums, target);
}

int main()
{
    // Initialize the array
    vector<int> nums = {1, 5, 11, 5};

    // Print the result of the function
    cout << canPartition(nums) << endl;

    return 0;
}
