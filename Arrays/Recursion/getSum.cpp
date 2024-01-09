/**
 * @brief Calculates the sum of elements in an array using recursion.
 *
 * This function takes an array and its size as input and recursively calculates
 * the sum of all elements in the array. It uses a base case to handle the empty
 * array and another base case to handle the array with only one element. In the
 * recursive case, it adds the first element with the sum of the rest of the array.
 *
 * @param arr Pointer to the array of integers
 * @param size Size of the array
 * @return Sum of all elements in the array
 */

#include <bits/stdc++.h>
using namespace std;

int getSUm(int *arr, int size)
{

    // base case
    // If size is 0 then sum is 0
    if (size == 0)
    {
        return 0;
    }

    // If size is 1 then sum is the element itself
    if (size == 1)
    {
        return arr[0];
    }

    // recursive case
    // add first element with the sum of rest of the array
    return arr[0] + getSUm(arr + 1, size - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Printing the sum of the array
    cout << getSUm(arr, size);
    return 0;
}