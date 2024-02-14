/**
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * @brief This code calculates the number of derangements for a given number of elements using space optimization technique.
 *
 * Derangement is a permutation of the elements of a set, such that no element appears in its original position.
 * The code uses a dynamic programming approach to calculate the number of derangements.
 * It defines a function `solveSpaceOpt` that iteratively calculates the number of derangements for each number from 3 to n.
 * The function `countDerangements` calls the `solveSpaceOpt` function and returns the number of derangements for n elements.
 * The main function initializes the number of elements and prints the number of derangements.
 *
 */
// https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#include <bits/stdc++.h>
using namespace std;

// Defining MOD value for the problem
#define MOD 1000000007

// Function to calculate the number of derangements using space optimization
long long int solveSpaceOpt(int n)
{
    // Initialize previous two values for the number of derangements
    long long int prev1 = 1; // For n=2
    long long int prev2 = 0; // For n=1

    // Calculate the number of derangements for each number from 3 to n
    for (int i = 3; i <= n; i++)
    {
        // Calculate the sum of the number of derangements for i-1 and i-2 elements
        long long int sum = ((prev1 + prev2) % MOD);

        // Calculate the number of derangements for i elements
        long long int ans = (((i - 1) * sum) % MOD);

        // Update the previous two values
        prev2 = prev1;
        prev1 = ans;
    }

    // Return the number of derangements for n elements
    return prev1;
}

// Function to count the number of derangements
long long int countDerangements(int n)
{
    // Call the space optimization function
    return solveSpaceOpt(n);
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
