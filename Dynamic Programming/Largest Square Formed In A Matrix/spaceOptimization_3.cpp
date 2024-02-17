/**
 * Time complexity: O(N*M), where N is the number of rows and M is the number of columns in the matrix.
 * Space complexity: O(1).
 * This code finds the maximum size of the square sub-matrix with all 1s in a given matrix.
 * It uses a space-optimized approach to solve the problem efficiently.
 * The main function, maxSquare, takes the dimensions of the matrix and the matrix itself as input.
 * It initializes the maximum size of the square as 0 and calls the solveSO3 function to find the maximum size.
 * The solveSO3 function uses dynamic programming to calculate the maximum size of the square sub-matrix.
 * It iterates through the matrix from bottom-right to top-left and updates the current cell based on the values of the right, diagonal, and down cells.
 * The maximum size found so far is updated and returned as the result.
 * Finally, the main function returns the maximum size of the square sub-matrix.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum size of the square sub-matrix with all 1s
int solveSO3(vector<vector<int>> &mat, int &maxSquareSize)
{

    int numRows = mat.size();    // Number of rows in the matrix
    int numCols = mat[0].size(); // Number of columns in the matrix

    vector<int> curr(numCols + 1, 0); // Current row in the matrix
    vector<int> next(numCols + 1, 0); // Next row in the matrix

    // Traverse through the given matrix from bottom-right to top-left
    for (int i = numRows - 1; i >= 0; i--)
    {
        for (int j = numCols - 1; j >= 0; j--)
        {

            int right = curr[j + 1];    // Right cell
            int diagonal = next[j + 1]; // Diagonal cell
            int down = next[j];         // Down cell

            // If the current cell is 1
            if (mat[i][j] == 1)
            {
                // Update the value of the current cell by adding 1 to the minimum value of right, diagonal, and down cells
                curr[j] = 1 + min(right, min(diagonal, down));
                // Update the maximum size found so far
                maxSquareSize = max(maxSquareSize, curr[j]);
            }
            else
            {
                // If the current cell is 0, then update the current cell to 0
                curr[j] = 0;
            }
        }
        // Update the next row as the current row
        next = curr;
    }
    // Return the maximum size found
    return next[0];
}

// Function to get the maximum size of the square formed in the matrix
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // Initialize the maximum size of the square as 0
    int maxSquareSize = 0;

    // Call the space-optimized function to solve the problem
    solveSO3(mat, maxSquareSize);

    // Return the maximum size of the square
    return maxSquareSize;
}

int main()
{
    // Test the function with a sample testcase
    int n = 4, m = 4;
    vector<vector<int>> mat = {{1, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 0}, {0, 0, 0, 0}};
    cout << maxSquare(n, m, mat);
    return 0;
}