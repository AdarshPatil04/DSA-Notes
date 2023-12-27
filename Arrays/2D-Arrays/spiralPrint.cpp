/**
 * @brief This program prints the elements of a 2D array in spiral form.
 * 
 * The spiralPrint function takes a 2D array as input and returns a 1D array containing the elements of the 2D array in spiral form.
 * It starts by defining the boundaries of the spiral and then iteratively prints the elements in a clockwise spiral pattern.
 * The main function initializes a 2D array and calls the spiralPrint function to print the elements in spiral form.
 */

#include <bits/stdc++.h>
using namespace std;

// This function prints the elements of a 2D array in spiral form
vector<int> spiralPrint(vector<vector<int>> &arr)
{
    vector<int> answer;

    // noRows stores the number of rows in the 2D array
    int noRows = arr.size();

    // noColumns stores the number of columns in the 2D array
    int noColumns = arr[0].size();

    /*
    startingRow stores the index of the row from which we need to start printing the elements
    endingRow stores the index of the row at which we need to stop printing the elements
    startingColumn stores the index of the column from which we need to start printing the elements
    endingColumn stores the index of the column at which we need to stop printing the elements
    */
    int startingRow = 0, endingRow = noRows - 1, startingColumn = 0, endingColumn = noColumns - 1;

    // count stores the number of elements printed so far
    int count = 0;

    // total stores the total number of elements in the 2D array
    int total = noRows * noColumns;

    // Continuously printing the elements in spiral form until all the elements have been printed
    while (count < total)
    {

        // Pushing the elements of the first row 
        for (int index = startingColumn; index <= endingColumn && count < total; index++)
        {
            answer.push_back(arr[startingRow][index]);
            count++;
        }

        // Incrementing the starting row
        startingRow++;

        // Pushing the elements of the last column
        for (int index = startingRow; index <= endingRow && count < total; index++)
        {
            answer.push_back(arr[index][endingColumn]);
            count++;
        }

        // Decrementing the ending column
        endingColumn--;

        // Pushing the elements of the last row
        for (int index = endingColumn; index >= startingColumn && count < total; index--)
        {
            answer.push_back(arr[endingRow][index]);
            count++;
        }

        // Decrementing the ending row
        endingRow--;

        // Pushing the elements of the first column
        for (int index = endingRow; index >= startingRow && count < total; index--)
        {
            answer.push_back(arr[index][startingColumn]);
            count++;
        }

        // Incrementing the starting column
        startingColumn++;
    }

    // Returning the 1D array containing the elements of the 2D array in spiral form
    return answer;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    vector<int> res = spiralPrint(arr);

    // Printing the elements of the 2D array in spiral form(which is a 1D array)
    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}