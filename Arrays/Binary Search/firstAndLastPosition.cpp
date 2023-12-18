/**
 * This code demonstrates the implementation of binary search to find the first and last occurrence of a target element in a sorted array.
 * The code defines three functions: firstOccurrence, lastOccurrence, and firstAndLastPosition.
 * - firstOccurrence: Finds the index of the first occurrence of the target element in the array.
 * - lastOccurrence: Finds the index of the last occurrence of the target element in the array.
 * - firstAndLastPosition: Returns a pair of integers representing the first and last occurrence of the target element in the array.
 * The main function initializes an array and calls the firstAndLastPosition function to find the first and last occurrence of a specific element.
 */

#include <bits/stdc++.h>
using namespace std;

// Applying binary search to find the target element then moving left for finding first occurrence and right for finding last occurrence

int firstOccurrence(vector<int> &arr, int target)
{
    int start = 0, answer = -1, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            answer = mid;
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return answer;
}

int lastOccurrence(vector<int> &arr, int target)
{
    int start = 0, answer = -1, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            answer = mid;
            start = mid + 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return answer;
}

// Making a pair of first and last occurrence
pair<int, int> firstAndLastPosition(vector<int> &arr, int target)
{
    pair<int, int> p;
    p.first = firstOccurrence(arr, target);
    p.second = lastOccurrence(arr, target);
    return p;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5, 6};
    pair<int, int> p = firstAndLastPosition(arr, 3);

    // Printing the pair
    cout << p.first << " " << p.second;
    return 0;
}