/**
 * The time complexity of the code is O(2^n) and the space complexity is O(n) due to the recursive call stack.
 * This code solves the problem of finding the maximum profit that can be obtained by buying and selling stocks.
 * It uses a recursive approach to explore all possible buying and selling combinations.
 * The function maxProfit takes a vector of stock prices as input and returns the maximum profit.
 * The solveRec function is a recursive helper function that calculates the profit for each buying and selling decision.
 */
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(vector<int> &prices, int index, int buy, int limit)
{
    // Get the size of the prices
    int n = prices.size();
    // Base case: if index is equal to n or limit is 0, return 0
    if (index == n || limit == 0)
        return 0;

    // Initialize the profit as the minimum possible integer
    int profit = INT_MIN;
    if (buy)
    {
        // If buy is 1, we can buy or skip
        // Calculate the profit for buying (subtract the current price from the result of the recursive call for the next day with buy 0)
        // and for skipping (the result of the recursive call for the next day with buy 1)
        int canBuy = -prices[index] + solveRec(prices, index + 1, 0, limit);
        int skipBuy = 0 + solveRec(prices, index + 1, 1, limit);
        // Update the profit with the maximum value between the profit for buying and skipping
        profit = max(canBuy, skipBuy);
    }
    else
    {
        // If buy is 0, we can sell or skip
        // Calculate the profit for selling (add the current price to the result of the recursive call for the next day with buy 1 and limit decreased by 1)
        // and for skipping (the result of the recursive call for the next day with buy 0)
        int sell = +prices[index] + solveRec(prices, index + 1, 1, limit - 1);
        int skipSell = 0 + solveRec(prices, index + 1, 0, limit);
        // Update the profit with the maximum value between the profit for selling and skipping
        profit = max(sell, skipSell);
    }
    // Return the profit
    return profit;
}

// Function to get the maximum profit
int maxProfit(vector<int> &prices)
{
    // Call the recursive function to solve the problem
    // Start from the first day (0), set buy to 1 (can buy), and set limit to 2 (can make 2 transactions)
    return solveRec(prices, 0, 1, 2);
}

// Main function
int main()
{
    // Define the prices
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    // Print the maximum profit
    cout << maxProfit(prices) << endl;
    return 0;
}
