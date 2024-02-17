/**
 * Time complexity: O(N*sqrt(N)), where N is the input number.
 * This code solves the "Get Minimum Squares" problem using the bottom-up approach of dynamic programming.
 * Given a positive integer n, the goal is to find the minimum number of perfect squares that sum up to n.
 * The code uses tabulation to build a dynamic programming table and iteratively calculates the minimum number of squares for each value from 0 to n.
 * The main function calls the MinSquares function to solve the problem for a specific value of n and prints the result.
 */
// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation (bottom-up approach)
int solveTab(int n)
{
    // Step-1: Initialize a dp array with size n+1 and initial value INT_MAX
    vector<int> dp(n + 1, INT_MAX);

    // Step-2: Analyze the base case. If n is 0, the minimum number of squares is 0
    dp[0] = 0;

    // Step-3: Handle the remaining cases
    for (int i = 1; i <= n; i++)
    {
        // Loop through all numbers j such that j*j is less than or equal to n
        for (int j = 1; j * j <= n; j++)
        {
            // Calculate the square of j
            int temp = j * j;

            // If i minus temp is greater than or equal to 0, update dp[i] as the minimum of the current dp[i] and 1 plus dp[i-temp]
            if (i - temp >= 0)
                dp[i] = min(dp[i], 1 + dp[i - temp]);
        }
    }

    // Return the minimum number of squares for n
    return dp[n];
}

// Function to get the minimum number of squares
int MinSquares(int n)
{
    // Call the tabulation function to solve the problem
    return solveTab(n);
}

int main()
{
    // Test the function with n = 5
    int n = 5;
    cout << MinSquares(n);
    return 0;
}
