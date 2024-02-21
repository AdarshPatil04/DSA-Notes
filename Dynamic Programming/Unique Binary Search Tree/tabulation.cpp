/**
 * It uses tabulation to solve the problem, with a time complexity of O(n^2) and a space complexity of O(n).
 * This code calculates the number of unique binary search trees (BSTs) that can be formed with a given number of nodes.
 * The code initializes a dynamic programming (dp) array and iterates through the number of nodes and root nodes to calculate the number of unique BSTs.
 * The number of unique BSTs for a given node is the sum of the product of the number of unique BSTs for the left subarray and the right subarray.
 * Finally, the code returns the number of unique BSTs for the given number of nodes.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem with tabulation
int solveTab(int n)
{
    // Initialize the dp array for tabulation
    vector<int> dp(n + 1, 0);

    // After analyzing base case, we know that there is 1 unique BST for a sequence of length 0 (empty tree) and 1 (a single node)
    dp[0] = dp[1] = 1;

    // Iterate from 2 to n (node-> number of nodes)
    for (int node = 2; node <= n; node++)
    {
        // For each number of nodes, iterate from 1 to node (j-> root node)
        for (int j = 1; j <= node; j++)
        {
            // The number of unique BSTs for a given node is the sum of the product of the number of unique BSTs for the left subarray and the right subarray
            dp[node] += dp[j - 1] * dp[node - j];
        }
    }
    // Return the number of unique BSTs for n
    return dp[n];
}

// Function to get the number of unique binary search trees
int numTrees(int n)
{
    // Call the tabulation function to solve the problem
    return solveTab(n);
}

int main()
{
    // Define the number
    int n = 3;
    // Print the number of unique binary search trees
    cout << numTrees(n) << endl;
    return 0;
}
