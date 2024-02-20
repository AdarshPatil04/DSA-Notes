/**
// Time Complexity => O(n)
// Space Complexity => O(n) -> since there is only 2-columns
 * This code solves the problem of finding the minimum number of swaps required to make two sequences increasing.
 * The code uses memoization and recursion to solve the problem efficiently.
 * It defines a function `minSwap` that takes two vectors `nums1` and `nums2` as input, representing the two sequences.
 * The function returns the minimum number of swaps required to make the sequences increasing.
 * The code also includes a main function that demonstrates the usage of the `minSwap` function.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using memoization
int solveMem(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
{
    // base case: if all elements are used, return 0
    if (index >= nums1.size())
        return 0;

    // if the subproblem has already been solved, return the stored result
    if (dp[index][swapped] != -1)
        return dp[index][swapped];

    // find prev1 and prev2
    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    // if swapped is true, swap prev1 and prev2
    if (swapped)
        swap(prev1, prev2);

    // no-swap
    int ans = INT_MAX;
    // if the current elements are greater than the previous elements
    if (nums1[index] > prev1 && nums2[index] > prev2)
        // do not swap the current elements and move to the next index
        ans = 0 + solveMem(nums1, nums2, index + 1, 0, dp);

    // swap
    // if the current element of nums1 is greater than the previous element of nums2
    // and the current element of nums2 is greater than the previous element of nums1
    if (nums1[index] > prev2 && nums2[index] > prev1)
        // swap the current elements and move to the next index
        ans = min(ans, (1 + solveMem(nums1, nums2, index + 1, 1, dp)));

    // store the result in the dp table and return it
    return dp[index][swapped] = ans;
}

// Function to find the minimum number of swaps to make the sequences increasing
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    // insert -1 in the beginning of nums1 and nums2
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;
    int index = 1;

    // Memoization+Recursion
    // Initialize the dp table
    vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
    return solveMem(nums1, nums2, index, swapped, dp);
}

int main()
{
    // Initialize the arrays
    vector<int> nums1 = {1, 3, 5, 4};
    vector<int> nums2 = {1, 2, 3, 7};

    // Print the minimum number of swaps to make the sequences increasing
    cout << minSwap(nums1, nums2) << endl;

    return 0;
}