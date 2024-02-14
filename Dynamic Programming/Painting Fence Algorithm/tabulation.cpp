/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 * @brief This code solves the "Ninja and the Fence" problem using tabulation technique.
 * The problem is to count the number of ways to paint N fences with K colors, such that no more than two adjacent fences have the same color.
 * The code uses dynamic programming to calculate the number of ways for each number of fences from 1 to N.
 * It defines two helper functions, add() and mul(), to perform addition and multiplication with modulo operation.
 * The solveTab() function implements the tabulation approach and returns the number of ways to paint N fences.
 * The numberOfWays() function calls the solveTab() function and returns the result.
 * The main() function sets the values of N and K, calls the numberOfWays() function, and prints the result.
 * @param n The number of fences.
 * @param k The number of colors.
 * @return The number of ways to paint the fences.
 */
// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208

#include <bits/stdc++.h>
using namespace std;

// Defining MOD value for the problem
#define MOD 1000000007

// Function to add two numbers with modulo operation
int add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

// Function to multiply two numbers with modulo operation
int mul(int a, int b)
{
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

// Function to solve the problem using tabulation
// Time Complexity => O(N)
// Space Complexity => O(N)
int solveTab(int n, int k)
{
    // Step-1: Initialize a dp array with size n+1 and initial value 0
    vector<int> dp(n + 1, 0);

    // Step-2: Base cases - 'k' ways to paint 1 fence and 'k' plus 'k' times 'k-1' ways to paint 2 fences
    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    // Step-3: Calculate the number of ways for each number from 3 to n
    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }

    // Return the number of ways for n fences
    return dp[n];
}

// Function to count the number of ways to paint the fences
int numberOfWays(int n, int k)
{
    // Call the tabulation function
    return solveTab(n, k);
}

int main()
{
    // Number of fences and colors
    int n = 3, k = 2;

    // Print the number of ways to paint the fences
    cout << numberOfWays(n, k);

    // Return 0 to indicate normal termination of the program
    return 0;
}
