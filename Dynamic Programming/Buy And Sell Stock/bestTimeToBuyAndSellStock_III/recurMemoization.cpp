// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity => O(n)
// Space Complexity => O(n)
int solveMem(vector<int> &prices, int index, int buy, int limit, vector<vector<vector<int>>> &dp)
{
    int n = prices.size();
    // base case
    if (index == n)
        return 0;

    if (limit == 0)
        return 0;

    if (dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

    int profit = INT_MIN;
    if (buy)
    {
        int canBuy = -prices[index] + solveMem(prices, index + 1, 0, limit, dp);
        int skipBuy = 0 + solveMem(prices, index + 1, 1, limit, dp);
        profit = max(canBuy, skipBuy);
    }
    else
    {
        int sell = +prices[index] + solveMem(prices, index + 1, 1, limit - 1, dp);
        int skipSell = 0 + solveMem(prices, index + 1, 0, limit, dp);
        profit = max(sell, skipSell);
    }
    return dp[index][buy][limit] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // Recursion + Memoization
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return solveMem(prices, 0, 1, 2, dp);
}

int main()
{
    // Test Cases
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}