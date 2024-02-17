/**
 * Time complexity: O(N^3), where N is the number of vertices in the polygon.
 * Space complexity: O(N^2), where N is the number of vertices in the polygon.
 * This code solves the problem of finding the minimum score of triangulation of a polygon using the bottom-up approach.
 * The code uses dynamic programming to calculate the minimum score by considering all possible triangulations of the polygon.
 * It iterates over each vertex of the polygon in reverse order and calculates the minimum score for each subproblem.
 * The minimum score is calculated by considering all possible triangles formed by the vertices of the polygon.
 * The code stores the results of subproblems in a DP table to avoid redundant calculations.
 * Finally, it returns the minimum score of triangulation of the polygon.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation
int solveTab(vector<int> &v)
{
    // Get the number of vertices in the polygon
    int n = v.size();

    // Initialize the DP table
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Iterate over each vertex of the polygon in reverse order
    for (int i = n - 1; i >= 0; i--)
    {
        // Iterate over each vertex of the polygon starting from i+2
        for (int j = i + 2; j < n; j++)
        {
            // Initialize the minimum score to maximum possible value
            int ans = INT_MAX;

            // Iterate over each vertex of the polygon between i and j
            for (int k = i + 1; k < j; k++)
            {
                // For each vertex, calculate the score of the triangle formed by vertices i, j, and k
                // Add the scores of the remaining polygons on the left and right of the vertex k
                // Update the minimum score
                ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
            }

            // Store the result of the subproblem in the DP table
            dp[i][j] = ans;
        }
    }

    // Return the minimum score of triangulation of the polygon
    return dp[0][n - 1];
}

// Function to find the minimum score of triangulation of a polygon
int minScoreTriangulation(vector<int> &values)
{
    // Call the function to solve the problem using tabulation
    return solveTab(values);
}

int main()
{
    // Define the values of the vertices of the polygon
    vector<int> values = {1, 3, 1, 4, 1, 5};

    // Print the minimum score of triangulation of the polygon
    cout << minScoreTriangulation(values);

    return 0;
}
