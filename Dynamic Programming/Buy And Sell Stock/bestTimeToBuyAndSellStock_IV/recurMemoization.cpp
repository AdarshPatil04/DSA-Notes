// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity => O(n*k)
// Space Complexity => O(n*k)
int solveMem(int k, vector<int> &prices, int index, int operationNo, vector<vector<int>> &dp)
{ // Total opr = 2*k
    int n = prices.size();
    // base case
    if (index == n)
        return 0;
    if (operationNo == 2 * k)
        return 0;

    if (dp[index][operationNo] != -1)
        return dp[index][operationNo];

    int profit = INT_MIN;
    if ((operationNo & 1) == 0)
    {
        int doBuy = -prices[index] + solveMem(k, prices, index + 1, operationNo + 1, dp);
        int skipBuy = 0 + solveMem(k, prices, index + 1, operationNo, dp);
        profit = max(doBuy, skipBuy);
    }
    else
    {
        int doSell = +prices[index] + solveMem(k, prices, index + 1, operationNo + 1, dp);
        int skipSell = 0 + solveMem(k, prices, index + 1, operationNo, dp);
        profit = max(doSell, skipSell);
    }
    return dp[index][operationNo] = profit;
}

int maxProfit(int k, vector<int> &prices)
{
    // Memoization+Recurison
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, -1));
    return solveMem(k, prices, 0, 0, dp);
}

int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << maxProfit(k, prices) << endl;
    return 0;
}