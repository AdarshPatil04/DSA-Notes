/**
 * Time Complexity: exponential
 * This code solves the problem of finding the largest square formed in a matrix.
 * The code uses a recursive approach to calculate the size of the square at each cell.
 * It starts from the top-left cell and recursively calculates the size of the square
 * by considering the right, diagonal, and down directions.
 * The maximum size of the square is updated whenever a larger square is found.
 * The code returns the maximum size of the square formed in the matrix.
 */
// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
// The function takes the current indices (i, j), the matrix, and the maximum size of the square as input
int solveRec(int i, int j, vector<vector<int>> &mat, int &maxi)
{
    // Base case: if the indices are out of bounds, return 0
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    // Recursive calls for the right, diagonal, and down directions
    int right = solveRec(i, j + 1, mat, maxi);
    int diagonal = solveRec(i + 1, j + 1, mat, maxi);
    int down = solveRec(i + 1, j, mat, maxi);

    // If the current cell is 1, calculate the size of the square
    // The size is 1 plus the minimum size among the right, diagonal, and down directions
    // Update the maximum size of the square
    // Return the size of the square
    if (mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        // If the current cell is 0, return 0
        return 0;
    }
}

// Function to get the maximum size of the square formed in the matrix
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // Initialize the maximum size of the square as 0
    int maxi = 0;

    // Call the recursive function to solve the problem
    solveRec(0, 0, mat, maxi);

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
