/**
 * The time complexity of the code is O(N), where N is the number of elements.
 * The space complexity is O(N) + O(N) for recursion depth and the dp array.
 * This code calculates the number of derangements for a given number of elements using memoization.
 * A derangement is a permutation of the elements such that no element appears in its original position.
 * The code uses a recursive approach with memoization to avoid redundant calculations.
 */
// https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#include <bits/stdc++.h>
using namespace std;

// Defining MOD value for the problem
#define MOD 1000000007

// Recursive function to calculate the number of derangements using memoization
// Time Complexity => O(N)
// Space Complexity => O(N)+O(N) -> for recursion depth + dp-array
long long int solveMem(int n, vector<long long int> &dp)
{
    // Base case: If there is only one element, there are no derangements
    if (n == 1)
        return 0;

    // Base case: If there are two elements, there is one derangement
    if (n == 2)
        return 1;

    // If the value is already calculated, return it
    if (dp[n] != -1)
        return dp[n];

    // Calculate the number of derangements using the formula derived from the problem
    dp[n] = (((n - 1) % MOD) * ((solveMem(n - 2, dp) % MOD) + (solveMem(n - 1, dp) % MOD)) % MOD);

    // Return the calculated value
    return dp[n];
}

// Function to count the number of derangements
long long int countDerangements(int n)
{
    // Initialize a dp array with -1
    vector<long long int> dp(n + 1, -1);

    // Call the recursive function
    return solveMem(n, dp);
}

int main()
{
    // Number of elements
    int n = 3;

    // Print the number of derangements
    cout << countDerangements(n) << endl;

    // Return 0 to indicate normal termination of the program
    return 0;
}
