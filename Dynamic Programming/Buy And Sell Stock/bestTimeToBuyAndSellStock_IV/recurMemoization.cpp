/**
 * The time complexity of the solution is O(n*k), where 'n' is the number of stock prices and 'k' is the number of transactions allowed.
 * The space complexity is O(n*k) as well, due to the memoization table used to store previously computed results.
 * This code implements a solution to the problem of finding the maximum profit that can be obtained by buying and selling stocks.
 * The solution uses a recursive approach with memoization to optimize the computation.
 * The 'maxProfit' function takes the number of transactions allowed 'k' and a vector of stock prices as input.
 * It returns the maximum profit that can be obtained by performing at most 'k' transactions.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to calculate maximum profit with 'k' transactions
int solveMem(int k, vector<int> &prices, int index, int operationNo, vector<vector<int>> &dp)
{
    int n = prices.size();

    // base case: if we've gone through all the days or completed all transactions
    if (index == n || operationNo == 2 * k)
        return 0;

    // if this state has already been computed
    if (dp[index][operationNo] != -1)
        return dp[index][operationNo];

    int profit = INT_MIN;

    // if operationNo is even, we can buy a stock
    if ((operationNo & 1) == 0)
    {
        // choose to buy or not to buy
        int doBuy = -prices[index] + solveMem(k, prices, index + 1, operationNo + 1, dp);
        int skipBuy = 0 + solveMem(k, prices, index + 1, operationNo, dp);
        profit = max(doBuy, skipBuy);
    }
    else // if operationNo is odd, we can sell a stock
    {
        // choose to sell or not to sell
        int doSell = +prices[index] + solveMem(k, prices, index + 1, operationNo + 1, dp);
        int skipSell = 0 + solveMem(k, prices, index + 1, operationNo, dp);
        profit = max(doSell, skipSell);
    }

    // store the result in dp table
    return dp[index][operationNo] = profit;
}

// Function to initialize dp table and start the recursion
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, -1));
    return solveMem(k, prices, 0, 0, dp);
}

int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << maxProfit(k, prices) << endl; // prints the maximum profit
    return 0;
}
