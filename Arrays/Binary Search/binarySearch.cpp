/**
 * @brief This program implements the binary search algorithm to search for a target element in a sorted array.
 *
 * @param arr The sorted array to search in.
 * @param size The size of the array.
 * @param target The element to search for.
 * @return The index of the target element if found, -1 otherwise.
 */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0, end = size - 1;
    while (start <= end)
    {

        // Equivalent to (start + end) / 2, but avoids overflow of the int type(2^31+2^31)
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        // Go to the left half
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }

        // arr[mid] > target. Go to the right half
        else
        {
            end = mid - 1;
        }
    }
    return -1; // target not found
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << binarySearch(arr, 6, 4);
    return 0;
}