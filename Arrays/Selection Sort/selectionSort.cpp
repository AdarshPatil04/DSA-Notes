/**
 * @brief Sorts a vector of integers using the selection sort algorithm.
 *
 * @param arr The vector of integers to be sorted.
 */

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{

    // Length of the array
    int n = arr.size();

    // Selection sort algorithm
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // Finding the minimum element in the unsorted array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {

                // Updating the index of minimum element
                minIndex = j;
            }
        }

        // Swapping the minimum element with the (first) element of the unsorted array
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    selectionSort(arr);

    // Printing the sorted array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}