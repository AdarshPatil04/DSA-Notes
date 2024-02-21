/**
 * The time complexity of the solution is O(n), where n is the number of days.
 * The space complexity is O(n) as well, due to the memoization table.
 * This code calculates the maximum profit that can be obtained by buying and selling stocks.
 * It uses a recursive approach with memoization to optimize the solution.
 * The function `maxProfit` takes a vector of stock prices as input and returns the maximum profit.
 * The `solveMem` function is a helper function that calculates the maximum profit recursively with memoization.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to calculate maximum profit with memoization
int solveMem(vector<int> &prices, int start, int end, int flag, vector<vector<int>> &dp)
{
    // Base case: If we have traversed through all the days, we return 0
    if (start == end)
        return 0;

    // If we have already calculated the profit for the current day with the current flag, we return it
    if (dp[start][flag] != -1)
        return dp[start][flag];

    int profit = 0;
    if (flag)
    {
        // If flag is 1, we can buy or skip
        // If we buy, we subtract the price from our total profit and set the flag to 0
        int buy = -prices[start] + solveMem(prices, start + 1, end, 0, dp);
        // If we skip, we move to the next day with the same flag
        int skipBuy = 0 + solveMem(prices, start + 1, end, 1, dp);
        // We take the maximum of the two options
        profit = max(buy, skipBuy);
    }
    else
    {
        // If flag is 0, we can sell or skip
        // If we sell, we add the price to our total profit and set the flag to 1
        int sell = +prices[start] + solveMem(prices, start + 1, end, 1, dp);
        // If we skip, we move to the next day with the same flag
        int skipSell = 0 + solveMem(prices, start + 1, end, 0, dp);
        // We take the maximum of the two options
        profit = max(sell, skipSell);
    }
    // We store the maximum profit for the current day with the current flag in our dp table
    return dp[start][flag] = profit;
}

int maxProfit(vector<int> &prices)
{
    // Initialize dp table with -1
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    // Call the solveMem function with the initial flag set to 1 (we can buy on the first day)
    return solveMem(prices, 0, prices.size(), 1, dp);
}

int main()
{
    // Test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // Print the maximum profit
    cout << maxProfit(prices) << endl;
    return 0;
}
