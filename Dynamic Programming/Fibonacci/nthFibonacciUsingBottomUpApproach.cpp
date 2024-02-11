/**
 * The time complexity of this code is O(N) and the space complexity is O(N).
 * This code calculates the nth Fibonacci number using the bottom-up approach.
 * It uses dynamic programming to store previously calculated Fibonacci numbers
 * and avoids redundant calculations.
 * For more details, refer to the provided link.
 */
// https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156

#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    // Step 1: Create a 1D array (vector) to store Fibonacci numbers
    vector<int> dp(n + 1);

    // Step 2: Initialize base cases
    // The 0th Fibonacci number is 0
    dp[0] = 0;
    // The 1st Fibonacci number is 1
    dp[1] = 1;

    // Step 3: Fill the array with Fibonacci numbers
    // Start from the 2nd Fibonacci number since we've already initialized the 0th and 1st
    for (int i = 2; i <= n; i++)
    {
        // The ith Fibonacci number is the sum of the (i-1)th and (i-2)th Fibonacci numbers
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return the nth Fibonacci number
    return dp[n];
}

int main()
{
    int n = 3;

    // Calculate the nth Fibonacci number
    int ans = fib(n);

    // Print the nth Fibonacci number
    cout << ans << endl;

    return 0;
}
