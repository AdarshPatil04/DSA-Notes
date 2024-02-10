/**
 * The time complexity of this code is O(N) and the space complexity is O(1).
 * This code calculates the nth Fibonacci number using space optimization technique.
 * It uses an iterative approach to calculate the Fibonacci number by maintaining only the previous two numbers.
 * The main function takes an input 'n' which represents the position of the Fibonacci number to calculate.
 * It calls the 'fib' function to calculate the nth Fibonacci number and prints the result.
 */
// https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the nth Fibonacci number
int fib(int n)
{
    // Initialize the first two Fibonacci numbers
    int prev2 = 0, prev1 = 1;

    // Calculate the nth Fibonacci number
    for (int i = 2; i <= n; i++)
    {
        // The current Fibonacci number is the sum of the previous two
        int current = prev1 + prev2;

        // Update the previous two Fibonacci numbers
        prev2 = prev1;
        prev1 = current;
    }

    // If n is 0, the Fibonacci number is 0
    if (n == 0)
    {
        return prev2;
    }

    // Otherwise, return the nth Fibonacci number
    return prev1;
}

int main()
{
    // The position of the Fibonacci number to calculate
    int n = 3;

    // Calculate the nth Fibonacci number
    int ans = fib(n);

    // Print the nth Fibonacci number
    cout << ans << endl;

    return 0;
}
