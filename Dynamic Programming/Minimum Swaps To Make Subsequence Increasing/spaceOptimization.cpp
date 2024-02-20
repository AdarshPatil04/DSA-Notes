/**
 * The time complexity of the algorithm is O(n) and the space complexity is O(1).
 * This code solves the problem of finding the minimum number of swaps required to make two sequences increasing.
 * It uses space-optimized dynamic programming to efficiently calculate the minimum swaps.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using space optimized dynamic programming
int solveSO(vector<int> &nums1, vector<int> &nums2)
{
    // Initialize the variables to store the minimum number of swaps
    int swap = 0;
    int noSwap = 0;
    int currSwap = 0;
    int currNoSwap = 0;

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
            {
                int temp = prev1;
                prev1 = prev2;
                prev2 = temp;
            }

            // no-swap
            int ans = INT_MAX;
            // if the current elements are greater than the previous elements
            if (nums1[index] > prev1 && nums2[index] > prev2)
                // do not swap the current elements and move to the next index
                ans = 0 + noSwap;

            // swap
            // if the current element of nums1 is greater than the previous element of nums2
            // and the current element of nums2 is greater than the previous element of nums1
            if (nums1[index] > prev2 && nums2[index] > prev1)
                // swap the current elements and move to the next index
                ans = min(ans, (1 + swap));

            // store the result in the currSwap or currNoSwap variable
            if (swapped)
                currSwap = ans;
            else
                currNoSwap = ans;
        }
        // update the swap and noSwap variables for the next iteration
        swap = currSwap;
        noSwap = currNoSwap;
    }
    // return the minimum number of swaps to make the sequences increasing
    return min(swap, noSwap);
}

// Function to find the minimum number of swaps to make the sequences increasing
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    // insert -1 in the beginning of nums1 and nums2
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;
    int index = 1;

    // Space Optimization
    return solveSO(nums1, nums2);
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
