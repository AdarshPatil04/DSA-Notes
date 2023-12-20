/**
 * @brief This code implements the paintersPartition algorithm, which solves the problem of partitioning boards among painters.
 * (Same as book Allocation problem)
 *
 * The paintersPartition function takes an array of board lengths (one unit length requires one unit time), the number of boards, and the number of painters as input.
 * It uses binary search to find the minimum time required to paint all the boards such that each painter paints contiguous boards.
 * The isPossible function is used as a helper function to check if it is possible to paint the boards within a given time limit.
 *
 * @param arr The array of board lengths
 * @param n The number of boards
 * @param m The number of painters
 * @return The minimum time required to paint all the boards
 */

#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to paint boards with given time
bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

// Function to partition the boards
int paintersPartition(vector<int> arr, int n, int m)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int answer = -1;

    // Binary search algorithm
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, n, m, mid))
        {
            answer = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return answer;
}

int main()
{

    // no. of boards = 4 and no. of painters = 2
    int n = 4, m = 2;
    vector<int> arr = {5, 5, 5, 5};
    cout << paintersPartition(arr, n, m);
    return 0;
}