/**
 * The time complexity of the solution is O(n*k), where n is the number of prices and k is the number of allowed transactions.
 * The space complexity is O(k).
 * This code implements a dynamic programming solution to find the maximum profit
 * that can be obtained by buying and selling stocks, with a given number of allowed transactions.
 * The solution uses space optimization technique to reduce the space complexity.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to calculate maximum profit with space optimization
int solveSO(int k, vector<int> &prices)
{
    int n = prices.size();
    // curr and next vectors to store the current and next state
    vector<int> curr(2 * k + 1, 0);
    vector<int> next(2 * k + 1, 0);

    // Start from the last day and go to the first day
    for (int index = n - 1; index >= 0; index--)
    {
        // operationNo can be from 0 to 2*k-1
        for (int operationNo = 2 * k - 1; operationNo >= 0; operationNo--)
        {
            int profit = INT_MIN;
            if ((operationNo & 1) == 0)
            {
                // If operationNo is even, we can buy or skip
                // If we buy, we subtract the price from our total profit and increment the operationNo
                int doBuy = -prices[index] + next[operationNo + 1];
                // If we skip, we move to the next day with the same operationNo
                int skipBuy = 0 + next[operationNo];
                // We take the maximum of the two options
                profit = max(doBuy, skipBuy);
            }
            else
            {
                // If operationNo is odd, we can sell or skip
                // If we sell, we add the price to our total profit and increment the operationNo
                int doSell = +prices[index] + next[operationNo + 1];
                // If we skip, we move to the next day with the same operationNo
                int skipSell = 0 + next[operationNo];
                // We take the maximum of the two options
                profit = max(doSell, skipSell);
            }
            // We store the maximum profit for the current day with the current operationNo in our curr vector
            curr[operationNo] = profit;
        }
        // Update the next state to be the current state
        next = curr;
    }
    // Return the maximum profit when we can buy on the first day
    return next[0];
}

int maxProfit(int k, vector<int> &prices)
{
    // Call the solveSO function to get the maximum profit
    return solveSO(k, prices);
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
