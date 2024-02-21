// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity => O(n)
// Space Complexity => O(n)
int solveMem(vector<int> &prices, int start, int end, int flag, vector<vector<int>> &dp)
{
    // base case
    if (start == end)
        return 0;

    if (dp[start][flag] != -1)
        return dp[start][flag];

    int profit = 0;
    if (flag)
    {
        // we can buy or skip -> buy or skipBuy if flag = 1 else sell
        int buy = -prices[start] + solveMem(prices, start + 1, end, 0, dp);
        int skipBuy = 0 + solveMem(prices, start + 1, end, 1, dp);
        profit = max(buy, skipBuy);
    }
    else
    {
        // we can sell or skip -> sell or skipSell if flag = 0 else buy
        int sell = +prices[start] + solveMem(prices, start + 1, end, 1, dp);
        int skipSell = 0 + solveMem(prices, start + 1, end, 0, dp);
        profit = max(sell, skipSell);
    }
    return dp[start][flag] = profit;
}

int maxProfit(vector<int> &prices)
{
    // Recursion + Memoization
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return solveMem(prices, 0, prices.size(), 1, dp);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}