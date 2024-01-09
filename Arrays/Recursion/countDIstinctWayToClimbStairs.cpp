/**
 * Calculates the number of distinct ways to climb n stairs using recursion.
 * 
 * The function countDistinctWayToClimbStairs takes an integer n as input and recursively calculates the number of distinct ways to climb n stairs.
 * The base cases are when n is less than 0, in which case the function returns 0, and when n is equal to 0, in which case the function returns 1.
 * In the recursive case, the function calls itself with n-1 and n-2 as inputs, and returns the sum of the results.
 * 
 * Note: This code can be optimized using dynamic programming to avoid redundant calculations.
 */

#include <bits/stdc++.h>
using namespace std;

// Calculates the number of distinct ways to climb n stairs using recursion.
int countDistinctWayToClimbStairs(int n)
{

    // base case
    // no way to climb negative stairs so return 0
    if (n < 0)
    {
        return 0;
    }

    // no. of ways to climb 0 stairs is 1
    if (n == 0)
    {
        return 1;
    }

    // recursive case
    // Condition for climbing 1 or 2 stairs at a time
    return countDistinctWayToClimbStairs(n - 1) + countDistinctWayToClimbStairs(n - 2);
}

int main()
{
    int n = 3;

    // prints the number of distinct ways to climb n stairs
    cout << countDistinctWayToClimbStairs(n);
    return 0;
}