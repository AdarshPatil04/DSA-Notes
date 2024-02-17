/**
 * Time complexity: O(N*M), where N is the number of rows and M is the number of columns in the matrix.
 * Space complexity: O(1).
 * This code finds the maximum size of a square sub-matrix with all 1s in a given matrix.
 * It uses dynamic programming and space optimization techniques to solve the problem efficiently.
 * The main function `maxSquare` takes the number of rows, number of columns, and the matrix as input.
 * It calls the helper function `findMaxSquareSize` to calculate the maximum size of the square sub-matrix.
 * The helper function traverses the matrix and updates each cell with the size of the largest square sub-matrix ending at that cell.
 * Finally, the maximum size found is returned and printed in the main function.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum size of the square sub-matrix with all 1s

int findMaxSquareSize(int numRows, int numCols, vector<vector<int>> &matrix, int &maxSquareSize)
{
    // Traverse through the given matrix
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            // If the current cell is 1 and it's not on the first row or first column
            if (i > 0 && j > 0 && matrix[i][j])
            {
                // Get the minimum value from the top, left, and top-left diagonal cell
                int leftCell = matrix[i][j - 1];
                int diagonalCell = matrix[i - 1][j - 1];
                int topCell = matrix[i - 1][j];

                // Update the value of the current cell by adding 1 to the minimum value
                matrix[i][j] = 1 + min(leftCell, min(diagonalCell, topCell));
            }
            // Update the maximum size found so far
            maxSquareSize = max(maxSquareSize, matrix[i][j]);
        }
    }
    // Return the maximum size found
    return maxSquareSize;
}

// Function to find the maximum size of the square sub-matrix with all 1s
int maxSquare(int numRows, int numCols, vector<vector<int>> matrix)
{
    int maxSquareSize = 0;
    // Call the helper function
    findMaxSquareSize(numRows, numCols, matrix, maxSquareSize);
    // Return the maximum size found
    return maxSquareSize;
}

int main()
{
    // Define the size of the matrix and the matrix
    int numRows = 4, numCols = 4;
    vector<vector<int>> matrix = {{1, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 0}, {0, 0, 0, 0}};
    // Print the maximum size of the square sub-matrix with all 1s
    cout << maxSquare(numRows, numCols, matrix);
    return 0;
}
