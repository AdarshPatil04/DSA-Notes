/**
 * @brief This program demonstrates the implementation of linear search using recursion.
 * 
 * The linearSearch function takes an array, its size, and a key as input parameters.
 * It recursively searches for the key in the array and returns true if found, false otherwise.
 * The main function initializes an array, a key, and the size of the array.
 * It calls the linearSearch function and prints '1' if the key is present, '0' otherwise.
 */

#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{

    // base case
    // if size is 0 then key is not present
    if (size == 0)
    {
        return false;
    }

    // if first element is equal to key then key is present
    if (arr[0] == key)
    {
        return true;
    }

    // recursive case
    // call for next element
    return linearSearch(arr + 1, size - 1, key);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int key = 3;
    int size = sizeof(arr) / sizeof(arr[0]);

    // Printing the '1' if key is present else '0'
    cout<<linearSearch(arr, size, key);
    return 0;
}