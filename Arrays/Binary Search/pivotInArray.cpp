/**
 * @brief This program finds the pivot element in a rotated sorted array.
 *
 * The pivot element is the element in the array where the elements to its right are smaller than it,
 * and the elements to its left are greater than it. This program uses binary search to find the pivot element.
 *
 * @param nums The input vector representing the rotated sorted array.
 * @return int The index of the pivot element in the array. Returns -1 if pivot element is not found.
 */

#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        // If mid is the pivot
        if (mid > 0 && nums[mid] < nums[mid - 1])
        {
            return mid;
        }

        // Since the pivot is not found, we need to search in one of the halves
        // Pivot likely in left half. Eg: 0 7
        else if (nums[mid] < nums[right])
        {
            right = mid - 1;
        }

        /*nums[mid] > nums[right]
        Pivot likely in right half. Eg: 7 0*/
        else
        {
            left = mid + 1;
        }
    }

    // Pivot not found
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Index of the pivot element
    cout << findPivot(nums);
    return 0;
}
