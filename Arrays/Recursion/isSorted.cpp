/**
 * @brief This program checks if an array is sorted in ascending order using recursion.
 *
 * @param arr Pointer to the array.
 * @param size Size of the array.
 * @return True if the array is sorted, False otherwise.
 */

#include <bits/stdc++.h>
using namespace std;

bool isSorted(int *arr, int size)
{

    // base case
    if (size == 0 || size == 1)
    {
        return true;
    }

    // recursive case
    // if first element is greater than second element then array is not sorted
    if (arr[0] > arr[1])
    {
        return false;
    }

    // if first element is smaller than second element then array is sorted
    else
    {

        // call for next element and check if it is sorted or not
        return isSorted(arr + 1, size - 1);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Printing the '1' if array is sorted else '0'
    cout << isSorted(arr, size);
    return 0;
}