/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 * @brief This code implements a solution to the "Guess Number Higher or Lower" problem using recursive memoization.
 * The problem is to find the minimum amount of money required to guarantee a win in a guessing game where the player
 * has to guess a number between 1 and n. The player can guess any number and the game will tell if the guessed number
 * is higher or lower than the target number. The player has to pay the guessed number as the cost. The goal is to find
 * the minimum amount of money required to guarantee a win in the game.
 *
 * The code uses a recursive approach with memoization to avoid redundant computations. It maintains a 2D dp array to
 * store the maximum cost for each start and end index. The solveMem function recursively calculates the maximum cost
 * for each start and end index by iterating through all possible guesses and taking the minimum value between the
 * current maximum cost and the sum of the current guess and the maximum value between the result of the recursive call
 * for the left subarray and the right subarray. The dp array is used to store the computed maximum cost for each start
 * and end index, so that it can be reused if already computed.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem with memoization
int solveMem(int start, int end, vector<vector<int>> &dp)
{
    // Base case: if start is greater than or equal to end, return 0
    if (start >= end)
        return 0;

    // If the maximum cost for the current start and end is already computed, return it
    if (dp[start][end] != -1)
        return dp[start][end];

    // Initialize the maximum cost with the maximum possible integer
    int maxi = INT_MAX;
    // Iterate from start to end
    for (int i = start; i <= end; i++)
    {
        // Update the maximum cost with the minimum value between the current maximum cost and
        // the sum of the current number and the maximum value between the result of the recursive call for the left subarray and the right subarray
        maxi = min(maxi, i + max(solveMem(start, i - 1, dp), solveMem(i + 1, end, dp)));
    }
    // Store the computed maximum cost for the current start and end in the dp array
    return dp[start][end] = maxi;
}

// Function to get the minimum amount of money to guarantee a win
int getMoneyAmount(int n)
{
    // Initialize the dp array for memoization
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // Call the recursive function to solve the problem
    return solveMem(1, n, dp);
}

int main()
{
    // Define the number
    int n = 10;
    // Print the minimum amount of money to guarantee a win
    cout << getMoneyAmount(n) << endl;
    return 0;
}
