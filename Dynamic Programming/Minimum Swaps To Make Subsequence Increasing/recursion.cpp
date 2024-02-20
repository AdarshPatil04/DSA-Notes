/**
 * The time complexity of the code is O(2^n) and the space complexity is O(n) due to the recursive call stack.
 * This code calculates the minimum number of swaps required to make two sequences increasing.
 * It uses a recursive approach to check all possible swaps and returns the minimum number of swaps.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
{
    // base case: if all elements are used, return 0
    if (index >= nums1.size())
        return 0;

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
        ans = 0 + solveRec(nums1, nums2, index + 1, 0);

    // swap
    // if the current element of nums1 is greater than the previous element of nums2
    // and the current element of nums2 is greater than the previous element of nums1
    if (nums1[index] > prev2 && nums2[index] > prev1)
        // swap the current elements and move to the next index
        ans = min(ans, (1 + solveRec(nums1, nums2, index + 1, 1)));

    return ans;
}

// Function to find the minimum number of swaps to make the sequences increasing
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    // insert -1 in the beginning of nums1 and nums2
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;
    int index = 1;
    return solveRec(nums1, nums2, index, swapped);
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
