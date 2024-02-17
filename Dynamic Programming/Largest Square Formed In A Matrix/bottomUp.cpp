/**
 * Time complexity: O(N*M), where N is the number of rows and M is the number of columns in the matrix.
 * Space complexity: O(N*M), where N is the number of rows and M is the number of columns in the matrix.
 * This code solves the problem of finding the largest square formed in a matrix using a bottom-up approach.
 * The code takes a matrix as input and returns the maximum size of the square that can be formed in the matrix.
 * It uses dynamic programming to store the maximum size of the square that can be formed ending at each cell.
 * The code iterates through the matrix from the last cell to the first cell, updating the dp array and the maximum size of the square.
 * Finally, it returns the maximum size of the square formed in the matrix.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using a tabulation (bottom-up approach)
// The function takes the matrix and a reference to the maximum size of the square as input
int solveTab(vector<vector<int>> &mat, int &maxi)
{
    // Get the number of rows and columns in the matrix
    int row = mat.size();
    int col = mat[0].size();

    // Initialize a dp array with size (row+1) x (col+1) and initial value 0
    // This array will store the maximum size of the square that can be formed ending at each cell
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    // Start from the last cell and go backwards
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            // Get the values of the right, diagonal, and down cells in the dp array
            int right = dp[i][j + 1];
            int diagonal = dp[i + 1][j + 1];
            int down = dp[i + 1][j];

            // If the current cell in the matrix is 1
            if (mat[i][j] == 1)
            {
                // The maximum size of the square that can be formed ending at the current cell
                // is 1 plus the minimum size among the right, diagonal, and down cells
                dp[i][j] = 1 + min(right, min(diagonal, down));

                // Update the maximum size of the square
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                // If the current cell in the matrix is 0, the maximum size of the square that can be formed ending at the current cell is 0
                dp[i][j] = 0;
            }
        }
    }

    // Return the maximum size of the square that can be formed ending at the first cell
    return dp[0][0];
}

// Function to get the maximum size of the square formed in the matrix
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // Initialize the maximum size of the square as 0
    int maxi = 0;

    // Call the tabulation function to solve the problem
    solveTab(mat, maxi);

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
