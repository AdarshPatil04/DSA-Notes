// The time complexity of the algorithm is O(n), where n is the number of days, and the space complexity is O(n).
// This code implements a dynamic programming solution to find the maximum profit that can be obtained by buying and selling stocks. 
// The algorithm uses memoization to optimize the recursive solution. 
// It calculates the maximum profit by considering two options at each day: buying or selling the stock. 
// The maximum profit is calculated by recursively exploring all possible combinations of buying and selling, 
// while keeping track of the remaining transactions and the current state (buying or selling). 
#include <bits/stdc++.h>
using namespace std;

// Function to calculate maximum profit with memoization
int solveMem(vector<int> &prices, int index, int buy, int limit, vector<vector<vector<int>>> &dp)
{
    int n = prices.size();
    // Base case: If we have traversed through all the days or we have reached the limit of transactions, we return 0
    if (index == n || limit == 0)
        return 0;

    // If we have already calculated the profit for the current day with the current flag and limit, we return it
    if (dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

    int profit = INT_MIN;
    if (buy)
    {
        // If buy is 1, we can buy or skip
        // If we buy, we subtract the price from our total profit and set the buy to 0
        int canBuy = -prices[index] + solveMem(prices, index + 1, 0, limit, dp);
        // If we skip, we move to the next day with the same buy
        int skipBuy = 0 + solveMem(prices, index + 1, 1, limit, dp);
        // We take the maximum of the two options
        profit = max(canBuy, skipBuy);
    }
    else
    {
        // If buy is 0, we can sell or skip
        // If we sell, we add the price to our total profit, set the buy to 1, and decrease the limit by 1
        int sell = +prices[index] + solveMem(prices, index + 1, 1, limit - 1, dp);
        // If we skip, we move to the next day with the same buy and limit
        int skipSell = 0 + solveMem(prices, index + 1, 0, limit, dp);
        // We take the maximum of the two options
        profit = max(sell, skipSell);
    }
    // We store the maximum profit for the current day with the current buy and limit in our dp table
    return dp[index][buy][limit] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // Initialize dp table with -1
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    // Call the solveMem function with the initial buy set to 1 (we can buy on the first day) and limit set to 2 (we can make at most 2 transactions)
    return solveMem(prices, 0, 1, 2, dp);
}

int main()
{
    // Test case
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    // Print the maximum profit
    cout << maxProfit(prices) << endl;
    return 0;
}
