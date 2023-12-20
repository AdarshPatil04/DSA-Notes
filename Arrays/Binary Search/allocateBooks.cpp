/**
 * @brief This program implements the binary search algorithm to allocate books to students.
 *
 * The program takes an array of book pages, the number of books, and the number of students as input.
 * It uses the binary search algorithm to find the minimum number of pages that can be allocated to each student,
 * such that each student gets at least one book and the maximum number of pages allocated to any student is minimized.
 *
 * @param arr The array of book pages.
 * @param n The number of books.
 * @param m The number of students.
 * @return The minimum number of pages that can be allocated to each student.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to allocate books to students
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

// Function to allocate books to students
int allocateBooks(vector<int> arr, int n, int m)
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

    // no. of books = 4 and no. of students = 2
    int n = 4, m = 2;
    vector<int> arr = {10, 20, 30, 40};
    cout << allocateBooks(arr, n, m);
    return 0;
}