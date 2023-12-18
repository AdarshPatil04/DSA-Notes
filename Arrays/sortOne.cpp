/**
 * @brief This code sorts an array of integers containing only 0s and 1s.
 *        It rearranges the elements such that all the 0s are placed before all the 1s.
 *        The sorting is done in-place using a two-pointer approach.
 * 
 * @param arr The array of integers to be sorted.
 * @param size The size of the array.
 */

#include <bits/stdc++.h>
using namespace std;

void sortOne(int arr[], int size)
{
    int i = 0, j = size - 1;
    while (i < j)
    {
        while (arr[i] == 0 && i < j)
        {
            i++;
        }
        while (arr[j] == 1 && i < j)
        {
            j--;
        }

        // means arr[i] == 1 and arr[j] == 0
        if (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = {1, 0, 1, 0, 1, 0};
    sortOne(arr, 6);
    return 0;
}