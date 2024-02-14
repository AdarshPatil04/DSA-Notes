/**
 * The time complexity of the code is O(N) and the space complexity is O(N).
 * This code calculates the number of derangements using tabulation method.
 * A derangement is a permutation of the elements of a set, such that no element appears in its original position.
 * The code uses dynamic programming to calculate the number of derangements for a given number 'n'.
 * It initializes a dp array with size n+1 and calculates the number of derangements for each number from 3 to n.
 */
// https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#include <bits/stdc++.h>
using namespace std;

// Defining MOD value for the problem
#define MOD 1000000007

// Function to calculate the number of derangements using tabulation
long long int solveTab(int n)
{
    // Step-1: Initialize a dp array with size n+1 and initial value 0
    vector<long long int> dp(n + 1, 0);

    // Step-2: Base cases - 0 derangements for 1 element and 1 derangement for 2 elements
    dp[1] = 0;
    dp[2] = 1;

    // Step-3: Calculate the number of derangements for each number from 3 to n
    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;      // Number of derangements for i-1 elements
        long long int second = dp[i - 2] % MOD;     // Number of derangements for i-2 elements
        long long int sum = (first + second) % MOD; // Sum of the two, modulo MOD

        // Calculate the number of derangements for i elements
        long long int ans = ((i - 1) * (sum)) % MOD;
        dp[i] = ans;
    }

    // Return the number of derangements for n elements
    return dp[n];
}

// Function to count the number of derangements
long long int countDerangements(int n)
{
    // Call the tabulation function
    return solveTab(n);
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
