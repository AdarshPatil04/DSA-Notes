/**
 * @brief This program finds the index of the peak element in a mountain array.
 * A mountain array is defined as an array that increases until a certain index and then decreases.
 * The program uses binary search to find the peak element by comparing the middle element with its adjacent elements.
 * If the middle element is smaller than the next element, the peak element lies in the right half of the array.
 * Otherwise, the peak element lies in the left half of the array.
 * The program continues to search in the appropriate half until the peak element is found.
 * The index of the peak element is then returned.
 */

#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int s = 0, answer = 0, e = arr.size() - 1;
    while (s < e)
    {

        // Left half of the array
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }

        /* Right half of the array
        (arr[mid] > arr[mid + 1])*/
        else
        {
            e = mid;
        }

        // Storing the index of the peak element
        answer = mid;
    }
    return answer;
}

int main()
{
    vector<int> arr = {3, 4, 5, 1};

    // Printing the index of the peak element
    cout << peakIndexInMountainArray(arr);
    return 0;
}