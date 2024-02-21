// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem with tabulation and space optimization
// Time Complexity => O(n*k)
// Space Complexity => O(k)
int solveSOPrev(int k, vector<int> &prices)
{
    // Get the size of the prices
    int n = prices.size();
    // Initialize the current and next dp arrays for tabulation
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    vector<vector<int>> next(2, vector<int>(k + 1, 0));

    // Iterate from the end to the start of the prices
    for (int index = n - 1; index >= 0; index--)
    {
        // For each price, iterate over the flags (0 and 1)
        for (int buy = 0; buy <= 1; buy++)
        {
            // For each flag, iterate over the limits (1 to k)
            for (int operationNo = 1; operationNo <= k; operationNo++)
            {
                int profit = 0;
                if (buy)
                {
                    // If buy is 1, we can buy or skip
                    // Calculate the profit for buying (subtract the current price from the profit for the next day with buy 0)
                    // and for skipping (the profit for the next day with buy 1)
                    int doBuy = -prices[index] + next[0][operationNo];
                    int skipBuy = 0 + next[1][operationNo];
                    // Update the profit with the maximum value between the profit for buying and skipping
                    profit = max(doBuy, skipBuy);
                }
                else
                {
                    // If buy is 0, we can sell or skip
                    // Calculate the profit for selling (add the current price to the profit for the next day with buy 1 and operationNo decreased by 1)
                    // and for skipping (the profit for the next day with buy 0)
                    int doSell = +prices[index] + next[1][operationNo - 1];
                    int skipSell = 0 + next[0][operationNo];
                    // Update the profit with the maximum value between the profit for selling and skipping
                    profit = max(doSell, skipSell);
                }
                // Store the computed profit for the current day, buy, and operationNo in the current dp array
                curr[buy][operationNo] = profit;
            }
        }
        // Update the next dp array with the current dp array
        next = curr;
    }
    // Return the profit for the first day with buy 1 and operationNo k
    return next[1][k];
}

// Function to get the maximum profit
int maxProfit(int k, vector<int> &prices)
{
    // Call the tabulation function with space optimization to solve the problem
    return solveSOPrev(k, prices);
}

// Main function
int main()
{
    // Define the prices
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    // Define the maximum number of transactions
    int k = 2;
    // Print the maximum profit
    cout << maxProfit(k, prices) << endl;
    return 0;
}
