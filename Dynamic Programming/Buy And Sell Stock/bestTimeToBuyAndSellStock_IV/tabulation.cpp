/**
 * The time complexity of the code is O(n*k), where n is the size of the prices array and k is the maximum
 * number of transactions allowed. The space complexity is O(n*k).
 * This code implements a dynamic programming solution to the problem of finding the maximum profit
 * that can be obtained by buying and selling stocks, given a maximum number of transactions allowed.
 * The code uses tabulation to build a 2D dp array, where each cell represents the maximum profit
 * that can be obtained at a specific day and with a specific number of transactions. The code iterates
 * through the prices array from the end to the start, and for each price, it iterates over the operation
 * numbers (from 2*k-1 to 0). It calculates the maximum profit for buying or selling at the current price,
 * and stores it in the dp array. Finally, it returns the maximum profit for the first day with operationNo 0.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem with tabulation
int solveTab(int k, vector<int> &prices)
{
    // Get the size of the prices
    int n = prices.size();
    // Initialize the dp array for tabulation
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    // Iterate from the end to the start of the prices
    for (int index = n - 1; index >= 0; index--)
    {
        // For each price, iterate over the operation numbers (from 2*k-1 to 0)
        for (int operationNo = 2 * k - 1; operationNo >= 0; operationNo--)
        {
            // Initialize the profit as the minimum possible integer
            int profit = INT_MIN;
            if ((operationNo & 1) == 0)
            {
                // If operationNo is even, we can buy or skip
                // Calculate the profit for buying (subtract the current price from the profit for the next day with operationNo increased by 1)
                // and for skipping (the profit for the next day with the same operationNo)
                int doBuy = -prices[index] + dp[index + 1][operationNo + 1];
                int skipBuy = 0 + dp[index + 1][operationNo];
                // Update the profit with the maximum value between the profit for buying and skipping
                profit = max(doBuy, skipBuy);
            }
            else
            {
                // If operationNo is odd, we can sell or skip
                // Calculate the profit for selling (add the current price to the profit for the next day with operationNo increased by 1)
                // and for skipping (the profit for the next day with the same operationNo)
                int doSell = +prices[index] + dp[index + 1][operationNo + 1];
                int skipSell = 0 + dp[index + 1][operationNo];
                // Update the profit with the maximum value between the profit for selling and skipping
                profit = max(doSell, skipSell);
            }
            // Store the computed profit for the current day and operationNo in the dp array
            dp[index][operationNo] = profit;
        }
    }
    // Return the profit for the first day with operationNo 0
    return dp[0][0];
}

// Function to get the maximum profit
int maxProfit(int k, vector<int> &prices)
{
    // Call the tabulation function to solve the problem
    return solveTab(k, prices);
}

int main()
{
    // Define the prices
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    // Define the maximum number of transactions
    int k = 2;
    // Print the maximum profit
    cout << maxProfit(k, prices) << endl;
    return 0;
}
