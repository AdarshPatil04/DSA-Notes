/**
 * The time complexity of the algorithm is O(N*X*M), where N is the number of dice, X is the target sum, and M is the number of faces on each dice.
 * The space complexity is O(N*X), where N is the number of dice and X is the target sum.
 * This code calculates the number of ways to get a target sum by rolling a given number of dice with a given number of faces.
 * It uses a recursive approach with memoization to avoid redundant calculations.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using memoization
long long int solveMem(int faces, int dices, int target, vector<vector<long long>> &dp)
{
    // base case: if target is less than 0, return 0
    if (target < 0)
        return 0;

    // base case: if target is 0 and there are still dices left, return 0
    if (target == 0 && dices != 0)
        return 0;

    // base case: if there are no dices left and target is not 0, return 0
    if (dices == 0 && target != 0)
        return 0;

    // base case: if there are no dices left and target is 0, return 1
    if (target == 0 && dices == 0)
        return 1;

    // if the subproblem has already been solved, return the stored result
    if (dp[dices][target] != -1)
        return dp[dices][target];

    long long ans = 0;
    // for each face of the dice
    for (int i = 1; i <= faces; i++)
    {
        // add the number of ways to get the target by including the current face
        ans = ans + solveMem(faces, dices - 1, target - i, dp);
    }
    // store the result in the dp table
    dp[dices][target] = ans;
    return dp[dices][target];
}

// Function to find the number of ways to get the target sum
long long noOfWays(int M, int N, int X)
{
    // Top-Down Approach
    // Initialize the dp table
    vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, -1));
    return solveMem(M, N, X, dp);
}

int main()
{
    // Initialize the number of faces, dices, and target sum
    int m = 6, n = 3, x = 8;

    // Print the number of ways to get the target sum
    cout << noOfWays(m, n, x) << endl;

    return 0;
}
