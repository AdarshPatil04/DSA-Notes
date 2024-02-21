/*
The time complexity of the code is O(2^nk), where n is the number of days and k is the maximum number of transactions allowed. The space complexity is O(n*k), which is the space used by the maximum depth of the recursive tree.
 * This code implements a recursive solution to the problem of finding the maximum profit
 * that can be obtained by buying and selling stocks. The problem is defined as follows:
 * Given an array of stock prices and the maximum number of transactions allowed, find the
 * maximum profit that can be obtained by buying and selling stocks. Each transaction consists
 * of buying a stock and then selling it later at a higher price. The code uses a recursive
 * approach to explore all possible combinations of buying and selling stocks, keeping track
 * of the maximum profit obtained so far.
*/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate maximum profit
int solveRec(int k, vector<int> &prices, int index, int operationNo)
{
    int n = prices.size();
    // Base case: If we have traversed through all the days or we have done all the operations, we return 0
    if (index == n || operationNo == 2 * k)
        return 0;

    int profit = INT_MIN;
    if ((operationNo & 1) == 0)
    {
        // If operationNo is even, we can buy or skip
        // If we buy, we subtract the price from our total profit and increment the operationNo
        int doBuy = -prices[index] + solveRec(k, prices, index + 1, operationNo + 1);
        // If we skip, we move to the next day with the same operationNo
        int skipBuy = 0 + solveRec(k, prices, index + 1, operationNo);
        // We take the maximum of the two options
        profit = max(doBuy, skipBuy);
    }
    else
    {
        // If operationNo is odd, we can sell or skip
        // If we sell, we add the price to our total profit and increment the operationNo
        int doSell = +prices[index] + solveRec(k, prices, index + 1, operationNo + 1);
        // If we skip, we move to the next day with the same operationNo
        int skipSell = 0 + solveRec(k, prices, index + 1, operationNo);
        // We take the maximum of the two options
        profit = max(doSell, skipSell);
    }
    return profit;
}

int maxProfit(int k, vector<int> &prices)
{
    // Call the recursive function with the initial operationNo set to 0 (we can buy on the first day)
    return solveRec(k, prices, 0, 0);
}

int main()
{
    // Test case
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    // Print the maximum profit
    cout << maxProfit(k, prices) << endl;
    return 0;
}
