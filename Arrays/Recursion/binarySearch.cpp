/**
 * @brief This code implements the binary search algorithm to find the index of a given key in a sorted array.
 *
 * @param arr Pointer to the array.
 * @param s Starting index of the array.
 * @param e Ending index of the array.
 * @param key The element to be searched.
 * @return The index of the key if found, -1 otherwise.
 */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int s, int e, int key)
{

    // base case
    // if starting index is greater than ending index then key is not present
    if (s > e)
    {
        return -1;
    }

    // middle index
    int mid = (s + e) / 2;

    // key found at mid index
    if (arr[mid] == key)
    {
        return mid;
    }

    // recursive case
    // if key is smaller than arr[mid] then it will be present in the left half
    else if (key < arr[mid])
    {
        return binarySearch(arr, s, mid - 1, key);
    }

    // key >= arr[mid]
    // if key is greater than arr[mid] then it will be present in the right half
    else
    {
        return binarySearch(arr, mid + 1, e, key);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int key = 3;
    int size = sizeof(arr) / sizeof(arr[0]);

    // Printing the '1' if key is present else '-1'
    cout << binarySearch(arr, 0, size - 1, key);
    return 0;
}