/**
 * @brief This code calculates the inversion count of an array using merge sort.
 * 
 * An inversion occurs when two elements in the array are out of order. 
 * The inversion count represents the number of inversions in the array.
 * 
 * The code uses the merge sort algorithm to sort the array and count the inversions.
 * It recursively divides the array into two halves, sorts them separately, and then merges them back together.
 * During the merge step, the code counts the inversions by comparing the elements from the two halves.
 * 
 * Example:
 * Input: [5, 4, 3, 2, 1]
 * Output: 10
 * Explanation: There are 10 inversions in the array: (5, 4), (5, 3), (5, 2), (5, 1), (4, 3), (4, 2), (4, 1), (3, 2), (3, 1), (2, 1)
 * Note: In the pair first one is greater than second one. If it was a sorted array then there are no inversion pairs formed because the first one will not be greater than second one.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted arrays
int merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    // len1 stores the length of the first array and len2 stores the length of the second array
    int len1 = mid - s + 1; // since it is size of array so we have to add 1
    int len2 = e - mid;     // e - (mid+1) + 1 = e - mid
    int inversionCount = 0;

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

            // len1 - index1 because all the elements after index1 are greater than arr1[index1] since arr1 is already sorted. So, increment inversionCount by len1 - index1
            inversionCount += len1 - index1;
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

    return inversionCount;
}

// Function to sort an array using merge sort
int mergeSort(int *arr, int s, int e)
{
    int inversionCount = 0;

    // base case
    if (s < e)
    {
        // recursive case
        int mid = (s + e) / 2;

        // call mergeSort for the first half of the array which is from s to mid
        // increment inversionCount by the number of inversions in the first half of the array
        inversionCount += (arr, s, mid);

        // call mergeSort for the second half of the array which is from mid+1 to e
        // increment inversionCount by the number of inversions in the second half of the array
        inversionCount += (arr, mid + 1, e);

        // merge the two sorted halves
        // increment inversionCount by the number of inversions in the merged array
        inversionCount += (arr, s, e);
    }

    // return the inversion count of the array
    return inversionCount;
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Printing the inversion count of the given array using merge sort
    cout << mergeSort(arr, 0, n - 1);
    return 0;
}