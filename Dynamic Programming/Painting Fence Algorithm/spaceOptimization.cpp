/**
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * @brief This code solves the "Ninja and the Fence" problem using space optimization technique.
 * The problem is to count the number of ways to paint N fences with K colors, such that no more than two adjacent fences have the same color.
 * The code implements a dynamic programming approach with space optimization, reducing the space complexity to O(1).
 * It defines functions to add and multiply numbers with modulo operation, and a solveSO function to calculate the number of ways using the space optimization technique.
 * The main function initializes the number of fences and colors, calls the solveSO function, and prints the result.
 * @param n The number of fences
 * @param k The number of colors
 * @return The number of ways to paint the fences
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

// Function to solve the problem using space optimization
int solveSO(int n, int k)
{
    // Step-1: Initialize previous two values for the number of ways
    int prev2 = k;                     // For n=1
    int prev1 = add(k, mul(k, k - 1)); // For n=2

    // Step-2: Calculate the number of ways for each number from 3 to n
    for (int i = 3; i <= n; i++)
    {
        // Calculate the number of ways using the formula derived from the problem
        int ans = add(mul(prev1, k - 1), mul(prev2, k - 1));

        // Update the previous two values
        prev2 = prev1;
        prev1 = ans;
    }

    // Step-3: Return the number of ways for n fences
    return prev1;
}

// Function to count the number of ways to paint the fences
int numberOfWays(int n, int k)
{
    // Call the space optimization function
    return solveSO(n, k);
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
