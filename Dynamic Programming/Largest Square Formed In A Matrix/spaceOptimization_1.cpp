/**
 * Time complexity: O(N*M), where N is the number of rows and M is the number of columns in the matrix.
 * Space complexity: O(M), where M is the number of columns in the matrix.
 * This code implements a space-optimized approach to find the maximum size of a square formed in a matrix.
 * The code uses dynamic programming to solve the problem efficiently.
 * The solveSO function takes a matrix and a reference to the maximum size of the square as input.
 * It iterates through the matrix from the bottom-right corner to the top-left corner, calculating the maximum size of the square that can be formed ending at each cell.
 * The maxSquare function initializes the maximum size of the square as 0 and calls the solveSO function to solve the problem.
 * The main function tests the code with a sample testcase.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using a space-optimized approach
// The function takes the matrix and a reference to the maximum size of the square as input
int solveSO(vector<vector<int>> &mat, int &maxi)
{
    // Get the number of rows and columns in the matrix
    int row = mat.size();
    int col = mat[0].size();

    // Initialize two arrays curr and next with size col+1 and initial value 0
    // These arrays will store the maximum size of the square that can be formed ending at each cell in the current and next rows
    vector<int> curr(col + 1, 0);
    vector<int> next(col + 1, 0);

    // Start from the last row and go upwards
    for (int i = row - 1; i >= 0; i--)
    {
        // Start from the last cell in the current row and go leftwards
        for (int j = col - 1; j >= 0; j--)
        {
            // Get the values of the right, diagonal, and down cells in the next array
            int right = curr[j + 1];
            int diagonal = next[j + 1];
            int down = next[j];

            // If the current cell in the matrix is 1
            if (mat[i][j] == 1)
            {
                // The maximum size of the square that can be formed ending at the current cell
                // is 1 plus the minimum size among the right, diagonal, and down cells
                curr[j] = 1 + min(right, min(diagonal, down));

                // Update the maximum size of the square
                maxi = max(maxi, curr[j]);
            }
            else
            {
                // If the current cell in the matrix is 0, the maximum size of the square that can be formed ending at the current cell is 0
                curr[j] = 0;
            }
        }

        // After processing the current row, update the next array to be the current array
        next = curr;
    }

    // Return the maximum size of the square that can be formed ending at the first cell in the first row
    return next[0];
}

// Function to get the maximum size of the square formed in the matrix
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // Initialize the maximum size of the square as 0
    int maxi = 0;

    // Call the space-optimized function to solve the problem
    solveSO(mat, maxi);

    // Return the maximum size of the square
    return maxi;
}

int main()
{
    // Test the function with a sample testcase
    int n = 4, m = 4;
    vector<vector<int>> mat = {{1, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 0}, {0, 0, 0, 0}};
    cout << maxSquare(n, m, mat);
    return 0;
}
