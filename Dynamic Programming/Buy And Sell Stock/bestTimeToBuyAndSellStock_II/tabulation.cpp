/**
 * The time complexity of the solution is O(n), where n is the number of prices.
 * The space complexity is O(n) as well.
 * This code implements a solution to the "Best Time to Buy and Sell Stock II" problem using tabulation.
 * The problem is to find the maximum profit that can be obtained by buying and selling stocks on consecutive days.
 * The solution uses dynamic programming to compute the maximum profit for each day and flag (0 or 1).
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem with tabulation
int solveTab(vector<int> &prices)
{
    // Get the size of the prices
    int n = prices.size();
    // Initialize the dp array for tabulation
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // Iterate from the end to the start of the prices
    for (int start = n - 1; start >= 0; start--)
    {
        // For each price, iterate over the flags (0 and 1)
        for (int flag = 0; flag <= 1; flag++)
        {
            int profit = 0;
            if (flag)
            {
                // If flag is 1, we can buy or skip
                // Calculate the profit for buying (subtract the current price from the profit for the next day with flag 0)
                // and for skipping (the profit for the next day with flag 1)
                int buy = -prices[start] + dp[start + 1][0];
                int skipBuy = 0 + dp[start + 1][1];
                // Update the profit with the maximum value between the profit for buying and skipping
                profit = max(buy, skipBuy);
            }
            else
            {
                // If flag is 0, we can sell or skip
                // Calculate the profit for selling (add the current price to the profit for the next day with flag 1)
                // and for skipping (the profit for the next day with flag 0)
                int sell = +prices[start] + dp[start + 1][1];
                int skipSell = 0 + dp[start + 1][0];
                // Update the profit with the maximum value between the profit for selling and skipping
                profit = max(sell, skipSell);
            }
            // Store the computed profit for the current day and flag in the dp array
            dp[start][flag] = profit;
        }
    }
    // Return the profit for the first day with flag 1
    return dp[0][1];
}

// Function to get the maximum profit
int maxProfit(vector<int> &prices)
{
    // Call the tabulation function to solve the problem
    return solveTab(prices);
}

// Main function
int main()
{
    // Define the prices
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // Print the maximum profit
    cout << maxProfit(prices) << endl;
    return 0;
}
