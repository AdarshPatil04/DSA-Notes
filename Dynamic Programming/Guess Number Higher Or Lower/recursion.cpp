/**
 * The time complexity of the code is O(n!), where n is the range of numbers to guess.
 * The space complexity is O(n).
 * @brief This code implements a recursive solution to the "Guess Number Higher or Lower" problem.
 * The problem is to find the minimum amount of money required to guarantee a win in a guessing game.
 * The game involves guessing a number between a given range, and the player has to pay the amount equal to the guessed number.
 * The goal is to minimize the amount of money required to guarantee a win.
 * The code uses a recursive approach to calculate the minimum amount of money required.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(int start, int end)
{
    // Base case: if start is greater than or equal to end, return 0
    if (start >= end)
        return 0;

    // Initialize the maximum value with the maximum possible integer
    int maxi = INT_MAX;
    // Iterate from start to end
    for (int i = start; i <= end; i++)
    {
        // Update the maximum value with the minimum value between the current maximum value and
        // the sum of the current number and the maximum value between the result of the recursive call for the left subarray and the right subarray
        maxi = min(maxi, i + max(solveRec(start, i - 1), solveRec(i + 1, end)));
    }
    // Return the maximum value
    return maxi;
}

// Function to get the minimum amount of money to guarantee a win
int getMoneyAmount(int n)
{
    // Call the recursive function to solve the problem
    return solveRec(1, n);
}

int main()
{
    // Define the number
    int n = 10;
    // Print the minimum amount of money to guarantee a win
    cout << getMoneyAmount(n) << endl;
    return 0;
}
