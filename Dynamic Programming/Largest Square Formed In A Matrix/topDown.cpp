/**
 * Time Complexity: O(N*M), where N is the number of rows and M is the number of columns in the matrix.
 * Space Complexity: O(N*M), where N is the number of rows and M is the number of columns in the matrix.
 * This code solves the problem of finding the largest square formed in a matrix.
 * Given a matrix of 0s and 1s, the code finds the maximum size of a square that can be formed using only 1s.
 * The code uses a top-down approach with memoization to optimize the solution.
 * It recursively calculates the size of the square for each cell in the matrix and stores the results in a dp array.
 * The maximum size of the square is updated whenever a larger square is found.
 * Finally, the code returns the maximum size of the square.
 */
// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem with memoization
// The function takes the current indices (i, j), the matrix, the dp array, and the maximum size of the square as input
int solveMem(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp, int &maxi)
{
    // Base case: if the indices are out of bounds, return 0
    // This means we have considered all the cells in the matrix
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    // If the problem has already been solved, return the stored result
    if (dp[i][j] != -1)
        return dp[i][j];

    // Recursive calls for the right, diagonal, and down directions
    int right = solveMem(i, j + 1, mat, dp, maxi);
    int diagonal = solveMem(i + 1, j + 1, mat, dp, maxi);
    int down = solveMem(i + 1, j, mat, dp, maxi);

    // If the current cell is 1, calculate the size of the square
    // The size is 1 plus the minimum size among the right, diagonal, and down directions
    // Update the maximum size of the square
    // Store the size of the square in the dp array
    // Return the size of the square
    if (mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        // If the current cell is 0, store 0 in the dp array and return 0
        return dp[i][j] = 0;
    }
}

// Function to get the maximum size of the square formed in the matrix
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // Initialize the maximum size of the square as 0
    int maxi = 0;

    // Initialize a dp array with size n x m and initial value -1
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // Call the recursive function to solve the problem
    solveMem(0, 0, mat, dp, maxi);

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
