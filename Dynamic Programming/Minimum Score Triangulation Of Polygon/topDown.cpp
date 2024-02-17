/**
 * Time complexity: O(N^3), where N is the number of vertices in the polygon.
 * Space complexity: O(N^2), where N is the number of vertices in the polygon.
 * This code solves the problem of finding the minimum score of triangulation of a polygon.
 * The polygon is represented by a vector of values, where each value represents the length of a side of the polygon.
 * The code uses recursion and memoization to efficiently calculate the minimum score.
 * It iterates over each vertex of the polygon and calculates the score of the triangle formed by three vertices.
 * It then recursively calculates the scores of the remaining polygons on the left and right of the current vertex.
 * The minimum score is updated at each step, and the results are stored in a memoization table for future use.
 * The code returns the minimum score of triangulation of the polygon.
 */
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using recursion and memoization
int solveMem(int i, int j, vector<int> &v, vector<vector<int>> &dp)
{
    // Base case: if there are only two adjacent vertices left in the polygon, no triangle can be formed
    if (i + 1 == j)
        return 0;

    // If the subproblem has already been solved, return the stored result
    if (dp[i][j] != -1)
        return dp[i][j];

    // Initialize the minimum score to maximum possible value
    int ans = INT_MAX;

    // Iterate over each vertex of the polygon
    for (int k = i + 1; k < j; k++)
    {
        // For each vertex, calculate the score of the triangle formed by vertices i, j, and k
        // Add the scores of the remaining polygons on the left and right of the vertex k
        // Update the minimum score
        ans = min(ans, v[i] * v[j] * v[k] + solveMem(i, k, v, dp) + solveMem(k, j, v, dp));
    }

    // Store the result of the subproblem for future use
    dp[i][j] = ans;

    // Return the minimum score
    return dp[i][j];
}

// Function to find the minimum score of triangulation of a polygon
int minScoreTriangulation(vector<int> &values)
{
    // Get the number of vertices in the polygon
    int n = values.size();

    // Initialize the memoization table
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Call the function to solve the problem using recursion and memoization
    return solveMem(0, n - 1, values, dp);
}

int main()
{
    // Define the values of the vertices of the polygon
    vector<int> values = {1, 3, 1, 4, 1, 5};

    // Print the minimum score of triangulation of the polygon
    cout << minScoreTriangulation(values);

    return 0;
}
