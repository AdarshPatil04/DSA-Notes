/**
 * allowed. The time complexity of the solution is O(n), where n is the number of prices,
 * and the space complexity is O(n).
 * This code implements a dynamic programming solution to find the maximum profit
 * that can be obtained by buying and selling stocks. The solution uses tabulation
 * to compute the maximum profit for each day, considering the number of transactions
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem with tabulation
int solveTab(vector<int> &prices)
{
    // Get the size of the prices
    int n = prices.size();
    // Initialize the dp array for tabulation
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Iterate from the end to the start of the prices
    for (int index = n - 1; index >= 0; index--)
    {
        // For each price, iterate over the flags (0 and 1)
        for (int buy = 0; buy <= 1; buy++)
        {
            // For each flag, iterate over the limits (1 and 2)
            for (int limit = 1; limit <= 2; limit++)
            {
                // Initialize the profit as the minimum possible integer
                int profit = INT_MIN;
                if (buy)
                {
                    // If buy is 1, we can buy or skip
                    // Calculate the profit for buying (subtract the current price from the profit for the next day with buy 0)
                    // and for skipping (the profit for the next day with buy 1)
                    int canBuy = -prices[index] + dp[index + 1][0][limit];
                    int skipBuy = 0 + dp[index + 1][1][limit];
                    // Update the profit with the maximum value between the profit for buying and skipping
                    profit = max(canBuy, skipBuy);
                }
                else
                {
                    // If buy is 0, we can sell or skip
                    // Calculate the profit for selling (add the current price to the profit for the next day with buy 1 and limit decreased by 1)
                    // and for skipping (the profit for the next day with buy 0)
                    int sell = +prices[index] + dp[index + 1][1][limit - 1];
                    int skipSell = 0 + dp[index + 1][0][limit];
                    // Update the profit with the maximum value between the profit for selling and skipping
                    profit = max(sell, skipSell);
                }
                // Store the computed profit for the current day, buy, and limit in the dp array
                dp[index][buy][limit] = profit;
            }
        }
    }
    // Return the profit for the first day with buy 1 and limit 2
    return dp[0][1][2];
}

// Function to get the maximum profit
int maxProfit(vector<int> &prices)
{
    // Call the tabulation function to solve the problem
    return solveTab(prices);
}

int main()
{
    // Define the prices
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    // Print the maximum profit
    cout << maxProfit(prices) << endl;
    return 0;
}
