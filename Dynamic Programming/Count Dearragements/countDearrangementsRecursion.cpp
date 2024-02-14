/**
 * Time Complexity: exponential
 * This code calculates the number of derangements for a given number of elements.
 * A derangement is a permutation of the elements such that no element appears in its original position.
 * The code uses a recursive approach to calculate the number of derangements.
 * It defines a recursive function `solveRec` that calculates the number of derangements for a given number `n`.
 * The base cases are when `n` is 1 or 2, where the number of derangements is 0 and 1 respectively.
 * For larger values of `n`, the number of derangements is calculated as (n-1) times the sum of the number of derangements for (n-1) and (n-2).
 * The code also defines a function `countDerangements` that calls the recursive function `solveRec` and returns the number of derangements.
 * In the `main` function, a sample value of `n` is provided and the number of derangements is printed.
 */
// https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#include <bits/stdc++.h>
using namespace std;

// MOD value for the problem
#define MOD 1000000007

// Recursive function to calculate the number of derangements
long long int solveRec(int n)
{
    // Base case: If there is only one element, there are no derangements
    if (n == 1)
        return 0;
    // Base case: If there are two elements, there is one derangement
    if (n == 2)
        return 1;

    // Recursive case: The number of derangements is (n-1) times the sum of the number of derangements for n-1 and n-2
    int ans = (((n - 1) % MOD) * ((solveRec(n - 2) % MOD) + (solveRec(n - 1) % MOD)) % MOD);

    return ans;
}

// Function to count the number of derangements
long long int countDerangements(int n)
{
    // Call the recursive function
    return solveRec(n);
}

int main()
{
    // Number of elements
    int n = 3;
    // Print the number of derangements
    cout << countDerangements(n) << endl;
    return 0;
}
