/**
 * This program demonstrates the merging of two sorted arrays into a single sorted array.
 * The function `mergedSortedArray` takes two sorted arrays `arr1` and `arr2`, and merges them into `arr3`.
 * The merged array `arr3` is then printed.
 */

#include <bits/stdc++.h>
using namespace std;

void mergedSortedArray(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }

        // arr1[i] >= arr2[j]
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
}

int main()
{
    int arr1[6] = {1, 3, 5, 7, 8, 19};
    int arr2[5] = {2, 4, 6, 8, 10};
    int arr3[11] = {0};
    mergedSortedArray(arr1, 6, arr2, 5, arr3);

    // Printing the merged sorted array
    for(int i = 0; i < 11; i++)
    {
        cout << arr3[i] << " ";
    }
    return 0;
}