/**
 * The time complexity of the code is O(n^2) and the space complexity is O(n^2).
 * @brief This code implements a dynamic programming solution to the "Guess Number Higher or Lower" problem.
 * The problem is to find the minimum amount of money required to guarantee a win in a number guessing game.
 * The code uses tabulation to compute the maximum cost for each range of numbers, starting from the end and working backwards.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem with tabulation
int solveTab(int n)
{
    // Initialize the dp array for tabulation
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // Iterate from the end to the start of the array
    for (int start = n; start >= 1; start--)
    {
        // For each number, iterate from the current number to the end of the array
        for (int end = start; end <= n; end++)
        {
            // If the start is equal to the end, continue to the next iteration
            if (start == end)
                continue;
            else
            {
                // Initialize the maximum cost with the maximum possible integer
                int maxi = INT_MAX;
                // Iterate from the start to the end
                for (int i = start; i <= end; i++)
                {
                    // Update the maximum cost with the minimum value between the current maximum cost and
                    // the sum of the current number and the maximum value between the cost for the left subarray and the right subarray
                    maxi = min(maxi, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                // Store the computed maximum cost for the current start and end in the dp array
                dp[start][end] = maxi;
            }
        }
    }
    // Return the maximum cost for the first and last number
    return dp[1][n];
}

// Function to get the minimum amount of money to guarantee a win
int getMoneyAmount(int n)
{
    // Call the tabulation function to solve the problem
    return solveTab(n);
}

int main()
{
    // Define the number
    int n = 10;
    // Print the minimum amount of money to guarantee a win
    cout << getMoneyAmount(n) << endl;
    return 0;
}
