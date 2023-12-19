/**
 * @brief Finds the pivot element in a rotated sorted array.
 *
 * This function uses binary search to find the pivot element in a rotated sorted array.
 * The pivot element is the least element in the array, and all elements to its right are smaller than it.
 *
 * @param arr The input vector representing the rotated sorted array.
 * @return The index of the pivot element in the array.
 */

#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    // Printing the index of the pivot element
    cout << findPivot(arr);
    return 0;
}