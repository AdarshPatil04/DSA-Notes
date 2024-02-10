/**
 * The time complexity of the program is O(N), where N is the position of the Fibonacci number to be calculated.
 * The space complexity of the program is O(N), as it uses a vector to store the calculated Fibonacci numbers.
 * @brief This program calculates the nth Fibonacci number using the top-down approach of dynamic programming.
 *
 * The program uses a recursive function to calculate the nth Fibonacci number by breaking it down into smaller subproblems.
 * It uses memoization to store the previously calculated Fibonacci numbers in a vector, so that they can be reused instead of recalculated.
 */
#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp)
{
    // Base case: The first and second Fibonacci numbers are 0 and 1
    if (n == 0 || n == 1)
    {
        return n;
    }

    // If the nth Fibonacci number has already been calculated, return it
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Calculate the nth Fibonacci number as the sum of the (n-1)th and (n-2)th Fibonacci numbers
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main()
{
    // The position of the Fibonacci number to be calculated
    int n = 3;

    // Create a 1D array to store the Fibonacci numbers calculated so far
    vector<int> dp(n + 1, -1);

    // Print the nth Fibonacci number
    cout << fib(n, dp) << endl;

    return 0;
}
