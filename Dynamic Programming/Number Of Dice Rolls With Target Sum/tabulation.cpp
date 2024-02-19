/**
 * The time complexity of the algorithm is O(N*X*M), where N is the number of dices, X is the target sum, and M is the number of faces on each dice.
 * The space complexity is O(N*X).
 * This program calculates the number of ways to get a target sum using a given number of dices and faces.
 * It uses a tabulation approach to solve the problem.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation
long long solveTab(int M, int N, int X)
{
    // Initialize the dp table
    vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, 0));

    // Base case: if there are no dices left and target is 0, return 1
    dp[0][0] = 1;

    // For each dice
    for (int dice = 1; dice <= N; dice++)
    {
        // For each target sum
        for (int target = 1; target <= X; target++)
        {
            long long ans = 0;
            // For each face of the dice
            for (int idx = 1; idx <= M; idx++)
            {
                // If the target sum is greater than or equal to the current face
                if (target - idx >= 0)
                    // Add the number of ways to get the target sum by including the current face
                    ans = ans + dp[dice - 1][target - idx];
            }
            // Store the result in the dp table
            dp[dice][target] = ans;
        }
    }
    // Return the number of ways to get the target sum
    return dp[N][X];
}

// Function to find the number of ways to get the target sum
long long noOfWays(int M, int N, int X)
{
    // Bottom-Up Approach
    return solveTab(M, N, X);
}

int main()
{
    // Initialize the number of faces, dices, and target sum
    int m = 6, n = 3, x = 8;

    // Print the number of ways to get the target sum
    cout << noOfWays(m, n, x) << endl;

    return 0;
}
