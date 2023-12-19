/**
 * This code implements the binary search algorithm to find an element in a rotated sorted array.
 * The array is first divided into two parts at the pivot point, which is the index where the rotation occurs.
 * Then, the binary search is performed on the appropriate part of the array based on the target element.
 * If the target element is found, its index is returned. Otherwise, -1 is returned.
 */

#include <bits/stdc++.h>
using namespace std;

// Binary search function(index)
int binarySearch(vector<int> &arr, int s, int e, int target)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

// Function to find the pivot index
int findPivot(vector<int> &arr, int s, int e)
{
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

int searchElementInRotSortArr(vector<int> &arr, int target)
{
    // Finding the pivot index
    int s = 0, e = arr.size() - 1, pivot = findPivot(arr, s, e);

    // Applying binary search from pivot to end
    if (target >= arr[pivot] && target <= arr[e])
    {
        return binarySearch(arr, pivot, e, target);
    }

    /*
    Applying binary search from start to pivot-1
    target >= arr[s] && target <= arr[pivot - 1]
    */
    else
    {
        return binarySearch(arr, 0, pivot - 1, target);
    }
}

int main()
{

    // Rotated sorted array
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    // Index of the target element
    cout << searchElementInRotSortArr(arr, target);
    return 0;
}