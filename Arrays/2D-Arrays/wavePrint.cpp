/**
 * @brief This program demonstrates how to print the elements of a 2D array in wave form.
 * 
 * The wavePrint function takes a 2D array as input and returns a 1D array containing the elements of the 2D array in wave form.
 * The wave form is achieved by printing the elements in different rows of the same column in alternating directions.
 * If the column number is odd, the elements are printed from bottom to top in the same column.
 * If the column number is even, the elements are printed from top to bottom in the same column.
 * 
 * Example:
 * Input:
 *  1  2  3  4
 *  5  6  7  8
 *  9 10 11 12
 * 13 14 15 16
 * 
 * Output:
 *  1  5  9 13 14 10 6 2 3 7 11 15 16 12 8 4
 */

#include <bits/stdc++.h>
using namespace std;

// This function prints the elements of a 2D array in wave form
vector<int> wavePrint(vector<vector<int>> &arr)
{
    vector<int> answer;

    // noRows stores the number of rows in the 2D array
    int noRows = arr.size();

    // noColumns stores the number of columns in the 2D array
    int noColumns = arr[0].size();

    // Iterating over the columns of the 2D array
    for (int col = 0; col < noColumns; col++)
    {

        // If the column number is odd, we need to print the elements in different rows in the same column from bottom to top
        if (noColumns & 1)
        {
            for (int row = noRows - 1; row >= 0; row--)
            {
                answer.push_back(arr[row][col]);
            }
        }

        // If the column number is even, we need to print the elements in different rows in the same column from top to bottom
        else
        {
            for (int row = 0; row < noRows; row++)
            {
                answer.push_back(arr[row][col]);
            }
        }
    }

    // Returning the 1D array containing the elements of the 2D array in wave form
    return answer;
}

int main()
{

    // arr is the 2D array
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    vector<int> res = wavePrint(arr);

    // Printing the elements of the 2D array in wave form(which is a 1D array)
    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}