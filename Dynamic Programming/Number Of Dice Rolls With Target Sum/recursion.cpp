/**
 * The time complexity of the recursive function is exponential, O(faces^dices), and the space complexity is O(dices).
 * This code calculates the number of ways to get a target sum by rolling a given number of dice with a given number of faces.
 * It uses a recursive approach to solve the problem, but it may result in a Time Limit Exceeded (TLE) for large inputs.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
long long int solveRec(int faces, int dices, int target)
{
    // base case: if target is less than 0, return 0
    if (target < 0)
        return 0;

    // base case: if target is 0 and there are still dices left, return 0
    if (target == 0 && dices != 0)
        return 0;

    // base case: if there are no dices left and target is not 0, return 0
    if (dices == 0 && target != 0)
        return 0;

    // base case: if there are no dices left and target is 0, return 1
    if (target == 0 && dices == 0)
        return 1;

    long long ans = 0;
    // for each face of the dice
    for (int i = 1; i <= faces; i++)
    {
        // add the number of ways to get the target by including the current face
        ans = ans + solveRec(faces, dices - 1, target - i);
    }
    return ans;
}

// Function to find the number of ways to get the target sum
long long noOfWays(int M, int N, int X)
{
    // Recursive Approach -> TLE
    return solveRec(M, N, X);
}

int main()
{
    // Initialize the number of faces, dices, and target sum
    int m = 6, n = 3, x = 8;

    // Print the number of ways to get the target sum
    cout << noOfWays(m, n, x) << endl;

    return 0;
}
