/**
 * @brief This program calculates the number of ways to get a target sum by rolling a given number of dice with a given number of faces.
 * It uses space optimized dynamic programming to solve the problem efficiently.
 * The time complexity of the algorithm is O(N*X*M), where N is the number of dice, X is the target sum, and M is the number of faces on each dice.
 * The space complexity is O(X), where X is the target sum.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using space optimized dynamic programming
long long solveSO(int M, int N, int X)
{
    // Initialize the dp vectors
    vector<long long> prev(X + 1, 0);
    vector<long long> curr(X + 1, 0);

    // Base case: if there are no dices left and target is 0, return 1
    prev[0] = 1;

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
                    ans = ans + prev[target - idx];
            }
            // Store the result in the curr vector
            curr[target] = ans;
        }
        // Update the prev vector for the next iteration
        prev = curr;
    }
    // Return the number of ways to get the target sum
    return prev[X];
}

// Function to find the number of ways to get the target sum
long long noOfWays(int M, int N, int X)
{
    // Space Optimization
    return solveSO(M, N, X);
}

int main()
{
    // Initialize the number of faces, dices, and target sum
    int m = 6, n = 3, x = 8;

    // Print the number of ways to get the target sum
    cout << noOfWays(m, n, x) << endl;

    return 0;
}
