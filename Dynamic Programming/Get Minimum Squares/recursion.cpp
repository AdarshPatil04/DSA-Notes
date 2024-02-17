/**
 * Time complexity: exponential
 * @brief This code calculates the minimum number of perfect squares required to sum up to a given number 'n'.
 *
 * The code uses a recursive approach to solve the problem. It iterates through all numbers i such that i*i is less than or equal to n,
 * and updates the answer as the minimum of the current answer and 1 plus the result of the recursive call with n minus i*i.
 * The base case is when n is 0, in which case the answer is 0.
 *
 * @param n The input number for which the minimum number of squares is to be calculated.
 * @return The minimum number of perfect squares required to sum up to 'n'.
 */
// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(int n)
{
    // Base case: if n is 0, return 0
    if (n == 0)
        return 0;

    // Initialize the answer as n
    int ans = n;

    // Loop through all numbers i such that i*i is less than or equal to n
    for (int i = 1; i * i <= n; i++)
    {
        // Update the answer as the minimum of the current answer and 1 plus the result of the recursive call with n minus i*i
        ans = min(ans, 1 + solveRec(n - i * i));
    }

    // Return the answer
    return ans;
}

// Function to get the minimum number of squares
int MinSquares(int n)
{
    // Call the recursive function to solve the problem
    return solveRec(n);
}

int main()
{
    // Test the function with n = 5
    int n = 5;
    cout << MinSquares(n);
    return 0;
}
