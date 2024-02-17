/**
 * Time complexity: O(N*sqrt(N)), where N is the input number.
 * This code solves the "Get Minimum Squares" problem using dynamic programming and memoization.
 * Given a positive integer n, the goal is to find the minimum number of perfect squares that sum up to n.
 * The code uses a top-down approach, where the recursive function `solveMem` is called with the current value of n and a memoization array `dp`.
 * The `solveMem` function calculates the minimum number of squares by recursively considering all possible perfect squares less than or equal to n.
 * The result is stored in the `dp` array to avoid redundant calculations.
 * Finally, the `MinSquares` function is called from the `main` function to test the code with a sample value of n.
 */
// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem with memoization
int solveMem(int n, vector<int> &dp)
{
    // Base case: if n is 0, return 0
    if (n == 0)
        return 0;

    // If the problem has already been solved, return the stored result
    if (dp[n] != -1)
        return dp[n];

    // Initialize the answer as n
    int ans = n;

    // Loop through all numbers i such that i*i is less than or equal to n
    for (int i = 1; i * i <= n; i++)
    {
        // Update the answer as the minimum of the current answer and 1 plus the result of the recursive call with n minus i*i
        ans = min(ans, 1 + solveMem(n - i * i, dp));
    }

    // Store the result in dp array for future reference
    dp[n] = ans;

    // Return the answer
    return dp[n];
}

// Function to get the minimum number of squares
int MinSquares(int n)
{
    // Initialize a dp array with size n+1 and initial value -1
    vector<int> dp(n + 1, -1);

    // Call the recursive function to solve the problem
    return solveMem(n, dp);
}

int main()
{
    // Test the function with n = 5
    int n = 5;
    cout << MinSquares(n);
    return 0;
}
