/**
 * The time complexity of this code is O(n), where n is the number of prices in the input vector.
 * The space complexity is O(1) as it uses constant space to store the minimum price and the maximum profit.
 * This code calculates the maximum profit that can be obtained by buying and selling stocks.
 * It uses the concept of dynamic programming to find the maximum difference between the prices of stocks.
 */
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum profit
int maxProfit(vector<int> &prices)
{
    // Initialize the minimum price as the first price
    int mini = prices[0];
    // Initialize the profit as 0
    int profit = 0;

    // Iterate over the prices starting from the second price
    for (int i = 1; i < prices.size(); i++)
    {
        // Calculate the difference between the current price and the minimum price
        int diff = prices[i] - mini;
        // Update the profit with the maximum value between the current profit and the difference
        profit = max(profit, diff);
        // Update the minimum price with the minimum value between the current minimum price and the current price
        mini = min(mini, prices[i]);
    }
    // Return the profit
    return profit;
}

int main()
{
    // Define the prices
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // Print the maximum profit
    cout << maxProfit(prices) << endl;
    return 0;
}
