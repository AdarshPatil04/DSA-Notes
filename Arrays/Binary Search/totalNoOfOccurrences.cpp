/**
 * This code demonstrates the use of binary search to find the total number of occurrences of a target element in a sorted array.
 * It uses two helper functions, firstOccurrence and lastOccurrence, to find the first and last occurrence of the target element respectively.
 * The firstAndLastPosition function combines the results of the firstOccurrence and lastOccurrence functions to calculate the total number of occurrences.
 * The main function initializes a sorted array and calls the firstAndLastPosition function to find the total number of occurrences of a specific target element.
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

// Making a pair of first and last occurrence and returning the difference of their indices + 1 which is the total number of occurrences of the target element
int firstAndLastPosition(vector<int> &arr, int target)
{
    pair<int, int> p;
    p.first = firstOccurrence(arr, target);
    p.second = lastOccurrence(arr, target);
    int answer = p.second - p.first + 1;
    return answer;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5, 6};

    // Printing total number of occurrences of 3
    cout << firstAndLastPosition(arr, 3);
    return 0;
}