/**
 * The time complexity of the code is O(n), where n is the number of prices, and the space complexity is O(1).
 * This code solves the problem of finding the maximum profit that can be obtained by buying and selling stocks,
 * considering a transaction fee. The code uses dynamic programming with tabulation and space optimization to
 * efficiently compute the maximum profit. The code defines a function maxProfit that takes a vector of prices and a fee as
 * input and returns the maximum profit. The main function demonstrates the usage of the maxProfit function by
 * providing a sample input and printing the maximum profit.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem with tabulation and space optimization
int solveSO(vector<int> &prices, int fee)
{
    // Get the size of the prices
    int n = prices.size();
    // Initialize the current and next dp arrays for tabulation
    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    // Iterate from the end to the start of the prices
    for (int start = n - 1; start >= 0; start--)
    {
        // For each price, iterate over the buyss (0 and 1)
        for (int buys = 0; buys <= 1; buys++)
        {
            // Initialize the profit as 0
            int profit = 0;
            if (buys)
            {
                // If buys is 1, we can buy or skip
                // Calculate the profit for buying (subtract the current price from the profit for the next day with buys 0)
                // and for skipping (the profit for the next day with buys 1)
                int buy = -prices[start] + next[0];
                int skipBuy = 0 + next[1];
                // Update the profit with the maximum value between the profit for buying and skipping
                profit = max(buy, skipBuy);
            }
            else
            {
                // If buys is 0, we can sell or skip
                // Calculate the profit for selling (add the current price to the profit for the next day with buys 1 and subtract the fee)
                // and for skipping (the profit for the next day with buys 0)
                int sell = +prices[start] + next[1] - fee;
                int skipSell = 0 + next[0];
                // Update the profit with the maximum value between the profit for selling and skipping
                profit = max(sell, skipSell);
            }
            // Store the computed profit for the current day and buys in the current dp array
            curr[buys] = profit;
        }
        // Update the next dp array with the current dp array
        next = curr;
    }
    // Return the profit for the first day with buys 1 (can buy)
    return curr[1];
}

// Function to get the maximum profit
int maxProfit(vector<int> &prices, int fee)
{
    // Call the tabulation function with space optimization to solve the problem
    return solveSO(prices, fee);
}

int main()
{
    // Define the prices
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // Define the fee
    int fee = 2;
    // Print the maximum profit
    cout << maxProfit(prices, fee) << endl;
    return 0;
}
