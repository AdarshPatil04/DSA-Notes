/**
 * The time complexity of the code is O(2^n) and the space complexity is O(n).
 * This code solves the problem of finding the maximum profit that can be obtained by buying and selling stocks.
 * There can be multiple transactions, but you may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 * The code uses a recursive approach to explore all possible buying and selling combinations.
 * The main function calls the maxProfit function which calculates and returns the maximum profit.
 * The prices vector contains the prices of stocks on different days.
 * The solveRec function is a recursive helper function that calculates the maximum profit by considering different buying and selling options.
 */
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
// Time Complexity => O(2^n)
// Space Complexity => O(n) -> space of recursive call stack
int solveRec(vector<int> &prices, int start, int end, int flag)
{
    // Base case: if start is equal to end, return 0
    if (start == end)
        return 0;

    int profit = 0;
    if (flag)
    {
        // If flag is 1, we can buy or skip
        // Calculate the profit for buying (subtract the current price from the result of the recursive call for the next day with flag 0)
        // and for skipping (the result of the recursive call for the next day with flag 1)
        int buy = -prices[start] + solveRec(prices, start + 1, end, 0);
        int skipBuy = 0 + solveRec(prices, start + 1, end, 1);
        // Update the profit with the maximum value between the profit for buying and skipping
        profit = max(buy, skipBuy);
    }
    else
    {
        // If flag is 0, we can sell or skip
        // Calculate the profit for selling (add the current price to the result of the recursive call for the next day with flag 1)
        // and for skipping (the result of the recursive call for the next day with flag 0)
        int sell = +prices[start] + solveRec(prices, start + 1, end, 1);
        int skipSell = 0 + solveRec(prices, start + 1, end, 0);
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
    // Start from the first day (0), end at the last day (prices.size()), and set the flag to 1 (can buy)
    return solveRec(prices, 0, prices.size(), 1);
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
