// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity => O(n*k)
// Space Complexity => O(k)
int solveSO(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<int> curr(2 * k + 1, 0);
    vector<int> next(2 * k + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int operationNo = 2 * k - 1; operationNo >= 0; operationNo--)
        {
            int profit = INT_MIN;
            if ((operationNo & 1) == 0)
            {
                int doBuy = -prices[index] + next[operationNo + 1];
                int skipBuy = 0 + next[operationNo];
                profit = max(doBuy, skipBuy);
            }
            else
            {
                int doSell = +prices[index] + next[operationNo + 1];
                int skipSell = 0 + next[operationNo];
                profit = max(doSell, skipSell);
            }
            curr[operationNo] = profit;
        }
        next = curr;
    }
    return next[0];
}

int maxProfit(int k, vector<int> &prices)
{
    // Space-Optimization
    return solveSO(k, prices);
}

int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << maxProfit(k, prices) << endl;
    return 0;
}