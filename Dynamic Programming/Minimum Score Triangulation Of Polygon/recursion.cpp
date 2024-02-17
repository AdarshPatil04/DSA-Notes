/**
 * Time complexity: O(2^N), where N is the number of vertices in the polygon.
 * Space complexity: O(N), where N is the number of vertices in the polygon.
 * @brief This code calculates the minimum score of triangulation of a polygon using recursion.
 *
 * The code defines a recursive function `solveRec` that takes a vector of integers representing the values of the vertices of the polygon,
 * and two indices `i` and `j` representing the range of vertices to consider. The function calculates the minimum score of triangulation
 * for the given range of vertices by considering all possible triangles formed by the vertices and recursively calculating the scores
 * of the remaining polygons on the left and right of each vertex. The minimum score is updated at each step and returned as the result.
 *
 * The main function initializes the values of the vertices of the polygon, calls the `minScoreTriangulation` function with the values,
 * and prints the minimum score of triangulation.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(vector<int> &v, int i, int j)
{
    // Base case: if there are only two adjacent vertices left in the polygon, no triangle can be formed
    if (i + 1 == j)
    {
        return 0;
    }

    // Initialize the minimum score to maximum possible value
    int ans = INT_MAX;

    // Iterate over each vertex of the polygon
    for (int k = i + 1; k < j; k++)
    {
        // For each vertex, calculate the score of the triangle formed by vertices i, j, and k
        // Add the scores of the remaining polygons on the left and right of the vertex k
        // Update the minimum score
        ans = min(ans, v[i] * v[j] * v[k] + solveRec(v, i, k) + solveRec(v, k, j));
    }

    // Return the minimum score
    return ans;
}

// Function to find the minimum score of triangulation of a polygon
int minScoreTriangulation(vector<int> &values)
{
    // Get the number of vertices in the polygon
    int n = values.size();

    // Call the recursive function to solve the problem
    return solveRec(values, 0, n - 1);
}

int main()
{
    // Define the values of the vertices of the polygon
    vector<int> values = {1, 3, 1, 4, 1, 5};

    // Print the minimum score of triangulation of the polygon
    cout << minScoreTriangulation(values);

    return 0;
}
