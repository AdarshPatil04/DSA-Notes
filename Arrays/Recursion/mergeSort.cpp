/**
 * @brief This program demonstrates the implementation of the merge sort algorithm.
 *
 * The merge sort algorithm is a divide-and-conquer algorithm that recursively divides the array into two halves,
 * sorts them separately, and then merges the sorted halves to obtain the final sorted array.
 *
 * The merge() function is used to merge two sorted arrays, while the mergeSort() function recursively divides the array
 * and calls the merge() function to merge the sorted halves.
 *
 * The main() function initializes an array, calls the mergeSort() function to sort the array, and then prints the sorted array.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted arrays
void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    // len1 stores the length of the first array and len2 stores the length of the second array
    int len1 = mid - s + 1; // since it is size of array so we have to add 1
    int len2 = e - mid; // e - (mid+1) + 1 = e - mid

    // create two arrays of length len1 and len2
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    // copy the elements of arr into arr1
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainArrayIndex++];
    }

    // copy the elements of arr into arr2
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[mainArrayIndex++];
    }

    // merge the two sorted arrays
    int index1 = 0, index2 = 0;
    mainArrayIndex = s;

    // compare the elements of arr1 and arr2 and store the smaller element in arr
    while (index1 < len1 && index2 < len2)
    {

        // if the element of arr1 is smaller than the element of arr2 then store the element of arr1 in arr
        if (arr1[index1] <= arr2[index2])
        {
            arr[mainArrayIndex++] = arr1[index1++];
        }

        // arr1[index1]>arr2[index2]
        // if the element of arr2 is smaller than the element of arr1 then store the element of arr2 in arr
        else
        {
            arr[mainArrayIndex++] = arr2[index2++];
        }
    }

    // if there are any remaining elements in arr1 then store them in arr
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = arr1[index1++];
    }

    // if there are any remaining elements in arr2 then store them in arr
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = arr2[index2++];
    }

    // delete the arrays arr1 and arr2
    delete[] arr1;
    delete[] arr2;
}

// Function to sort an array using merge sort
void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {

        // return once the array has only one element
        return;
    }

    // recursive case
    int mid = (s + e) / 2;

    // call mergeSort for the first half of the array which is from s to mid
    mergeSort(arr, s, mid);

    // call mergeSort for the second half of the array which is from mid+1 to e
    mergeSort(arr, mid + 1, e);

    // merge the two sorted halves
    merge(arr, s, e);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting the array
    mergeSort(arr, 0, n - 1);

    // Printing the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}