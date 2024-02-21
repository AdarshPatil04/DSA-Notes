// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity => O(n)
// Space Complexity => O(1)
int solveSO(vector<int> &prices)
{
    int n = prices.size();
    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int start = n - 1; start >= 0; start--)
    {
        for (int flag = 0; flag <= 1; flag++)
        {

            int profit = 0;
            if (flag)
            {
                // we can buy or skip -> buy or skipBuy if flag = 1 else sell
                int buy = -prices[start] + next[0];
                int skipBuy = 0 + next[1];
                profit = max(buy, skipBuy);
            }
            else
            {
                // we can sell or skip -> sell or skipSell if flag = 0 else buy
                int sell = +prices[start] + next[1];
                int skipSell = 0 + next[0];
                profit = max(sell, skipSell);
            }
            curr[flag] = profit;
        }
        next = curr;
    }
    return curr[1];
}

int maxProfit(vector<int> &prices)
{

    // Space-Optimization
    return solveSO(prices);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}