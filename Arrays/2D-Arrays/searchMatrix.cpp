/**
 * This code implements a binary search algorithm to search for a target element in a 2D matrix.
 * The matrix is represented as a vector of vectors, where each inner vector represents a row of the matrix.
 * The code uses binary search to find the target element by treating the 2D matrix as a 1D sorted array.
 * If the target element is found, the function returns true; otherwise, it returns false.
 * 
 * Example:
 * Consider the following matrix:
 *  1  3  5  7
 * 10 11 16 20
 * 23 30 34 60
 * 
 * If the target is 3, the function will return true.
 * If the target is 15, the function will return false.
 */

#include <bits/stdc++.h>
using namespace std;

// This function searches for an element in a matrix using binary search algorithm
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // s stores the starting index of the matrix & e stores the ending index of the matrix
    int s = 0, e = n * m - 1;
    while (s <= e)
    {
        int mid = e + (s - e) / 2;

        // mid / m gives the row number of the mid element & mid % m gives the column number of the mid element
        int element = matrix[mid / m][mid % m];
        if (element == target)
        {
            return true;
        }
        else if (element < target)
        {
            s = mid + 1;
        }

        // element > target
        else
        {
            e = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    int target = 3;

    // Calling the searchMatrix function
    cout << searchMatrix(matrix, target);
    return 0;
}