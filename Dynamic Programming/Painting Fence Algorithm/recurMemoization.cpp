/**
 * Time Complexity: O(N)
 * Space Complexity: O(N) + O(N)
 * This code solves the "Ninja and the Fence" problem using a recursive approach with memoization.
 * The problem is to count the number of ways to paint N fences using K colors, such that no more than two adjacent fences have the same color.
 * The code defines two helper functions: add(a, b) and mul(a, b) to perform addition and multiplication with modulo operation.
 * The solveMem(n, k, dp) function recursively calculates the number of ways to paint N fences using K colors, and stores the results in a memoization array dp.
 * The numberOfWays(n, k) function initializes the memoization array and calls the solveMem function.
 * The main function sets the values of N and K, calls the numberOfWays function, and prints the result.
 */
// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208

// Importing required libraries
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

// Recursive function to solve the problem using memoization
int solveMem(int n, int k, vector<int> &dp)
{
    // Base case: If there is only one fence, there are 'k' ways to paint it
    if (n == 1)
        return k;

    // Base case: If there are two fences, the number of ways is 'k' plus 'k' times 'k-1'
    if (n == 2)
        return add(k, mul(k, k - 1));

    // If the value is already calculated, return it
    if (dp[n] != -1)
        return dp[n];

    // Calculate the number of ways using the formula derived from the problem
    dp[n] = add(mul(solveMem(n - 2, k, dp), k - 1), mul(solveMem(n - 1, k, dp), k - 1));

    // Return the calculated value
    return dp[n];
}

// Function to count the number of ways to paint the fences
int numberOfWays(int n, int k)
{
    // Initialize a dp array with -1
    vector<int> dp(n + 1, -1);

    // Call the recursive function
    return solveMem(n, k, dp);
}

// Driver function
int main()
{
    // Number of fences and colors
    int n = 3, k = 2;

    // Print the number of ways to paint the fences
    cout << numberOfWays(n, k);

    // Return 0 to indicate normal termination of the program
    return 0;
}
