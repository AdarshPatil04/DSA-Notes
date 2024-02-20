/**
// Time Complexity => O(n) -> Inner loop running only 2-times
// Space Complexity => O(n) -> since 2-D vector has only columns
 * This code solves the problem of finding the minimum number of swaps required to make two sequences increasing.
 * It uses tabulation to calculate the minimum number of swaps.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation
int solveTab(vector<int> &nums1, vector<int> &nums2)
{
    // Initialize the dp table
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));

    // For each element
    for (int index = nums1.size() - 1; index >= 1; index--)
    {
        // For each possible swap state
        for (int swapped = 1; swapped >= 0; swapped--)
        {
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
                ans = 0 + dp[index + 1][0];

            // swap
            // if the current element of nums1 is greater than the previous element of nums2
            // and the current element of nums2 is greater than the previous element of nums1
            if (nums1[index] > prev2 && nums2[index] > prev1)
                // swap the current elements and move to the next index
                ans = min(ans, (1 + dp[index + 1][1]));

            // store the result in the dp table
            dp[index][swapped] = ans;
        }
    }
    // return the minimum number of swaps to make the sequences increasing
    return dp[1][0];
}

// Function to find the minimum number of swaps to make the sequences increasing
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    // insert -1 in the beginning of nums1 and nums2
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;
    int index = 1;

    // Tabulation
    return solveTab(nums1, nums2);
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
