/**
 * @brief Checks if a given array is rotated and sorted.
 * 
 * This function takes a reference to a vector of integers as input and checks if the array is rotated and sorted.
 * An array is considered rotated and sorted if it can be obtained by rotating a sorted array at some pivot point.
 * The function counts the number of times the previous element is greater than the current element in the array.
 * If the count is less than or equal to 1, it means the array is rotated and sorted, and the function returns true.
 * Otherwise, it returns false.
 * 
 * @param arr The input array to be checked.
 * @return True if the array is rotated and sorted, false otherwise.
 */

#include <bits/stdc++.h>
using namespace std;

bool rotatedAndSorted(vector<int> &arr)
{
    int count = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {   
        
        // If the previous element is greater than the current element, increment count
        if (arr[i - 1] > arr[i])
        {
            count++;
        }
    }

    if (arr[n - 1] > arr[0])
    {
        count++;
    }

    return count <= 1;
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};

    // Printing the result
    cout << rotatedAndSorted(arr);
    return 0;
}