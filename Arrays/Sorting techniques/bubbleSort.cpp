/**
 * @brief This program implements the bubble sort algorithm to sort an array of integers in ascending order.
 *
 * The bubble sort algorithm repeatedly compares adjacent elements and swaps them if they are in the wrong order.
 * This process is repeated for each element in the array until the entire array is sorted.
 *
 * @param arr The vector of integers to be sorted.
 */

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{

    // Length of the array
    int n = arr.size();
    bool swapped = false;

    // Bubble sort algorithm
    // Round 0 to n-1
    for (int i = 0; i < n - 1; i++)
    {
        // 0 to n-1, 0 to n-2, 0 to n-3, ..., 0 to 1 cause the last element is already getting sorted
        for (int j = 0; j < n - i - 1; j++)
        {

            // Swapping the adjacent elements if they are in wrong order
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        // If no two elements were swapped by inner loop, then break(Optimization)
        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    bubbleSort(arr);

    // Printing the sorted array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}