/**
 * This code implements the Quick Sort algorithm to sort an array of integers in ascending order.
 * The quickSort() function recursively partitions the array and sorts the subarrays using the partition() function.
 * The partition() function selects a pivot element and places it at its correct position in the array,
 * such that all elements smaller than the pivot are on its left and all elements greater than the pivot are on its right.
 * The algorithm continues to recursively sort the left and right subarrays until the entire array is sorted.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to partition the array
int partition(int arr[], int s, int e)
{

    // first element is the pivot
    int pivot = arr[s];
    int count = 0;

    // count the number of elements smaller than the pivot
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    // place the pivot at its correct position
    int pivotIndex = s + count;

    // swap the pivot with the element at pivotIndex
    // swap(pivot, arr[pivotIndex]) can't be used because pivot will change and not arr[s] that's why we will get same values for both elements(all elements will be same)
    swap(arr[s], arr[pivotIndex]);
    int i = s, j = e;

    // place all the elements smaller than the pivot on its left and all the elements greater than the pivot on its right
    while (i < pivotIndex && j > pivotIndex)
    {

        // if the element is already at its correct position then increment i that is arr[i]<=pivot
        if (arr[i] <= pivot)
        {
            i++;
        }

        // if the element is already at its correct position then decrement j that is arr[j]>pivot
        else if (arr[j] > pivot)
        {
            j--;
        }

        // if the element is not at its correct position then swap the elements
        // arr[i]>pivot && arr[j]<=pivot
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // return the pivot index
    return pivotIndex;
}

// Function to sort the array using quick sort
void quickSort(int arr[], int s, int e)
{

    // base case
    if (s >= e)
    {
        return;
    }

    // recursive case
    // partition the array
    int p = partition(arr, s, e);

    // call quickSort() for the left subarray
    quickSort(arr, s, p - 1);

    // call quickSort() for the right subarray
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting the array
    quickSort(arr, 0, n - 1);

    // Printing the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}