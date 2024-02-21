/**
 * The time complexity of the algorithm is O(n), where n is the number of prices.
 * It uses space optimization technique to reduce the space complexity to O(1).
 * This code calculates the maximum profit that can be obtained by buying and selling stocks.
 * The code iterates from the last day to the first day, considering two flags: 0 and 1.
 * For each day, it calculates the maximum profit by either buying or selling the stock, or skipping the transaction.
 * The maximum profit is stored in the curr vector, and the next vector is updated for the next iteration.
 * Finally, the maximum profit when buying on the first day is returned.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to calculate maximum profit with space optimization
int solveSO(vector<int> &prices)
{
    int n = prices.size();
    // curr and next vectors to store the current and next state
    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    // Start from the last day and go to the first day
    for (int start = n - 1; start >= 0; start--)
    {
        // flag can be 0 or 1
        for (int flag = 0; flag <= 1; flag++)
        {
            int profit = 0;
            if (flag)
            {
                // If flag is 1, we can buy or skip
                // If we buy, we subtract the price from our total profit and set the flag to 0
                int buy = -prices[start] + next[0];
                // If we skip, we move to the next day with the same flag
                int skipBuy = 0 + next[1];
                // We take the maximum of the two options
                profit = max(buy, skipBuy);
            }
            else
            {
                // If flag is 0, we can sell or skip
                // If we sell, we add the price to our total profit and set the flag to 1
                int sell = +prices[start] + next[1];
                // If we skip, we move to the next day with the same flag
                int skipSell = 0 + next[0];
                // We take the maximum of the two options
                profit = max(sell, skipSell);
            }
            // We store the maximum profit for the current day with the current flag in our curr vector
            curr[flag] = profit;
        }
        // Update the next state to be the current state
        next = curr;
    }
    // Return the maximum profit when we can buy on the first day
    return curr[1];
}

int maxProfit(vector<int> &prices)
{
    // Call the solveSO function to get the maximum profit
    return solveSO(prices);
}

int main()
{
    // Test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // Print the maximum profit
    cout << maxProfit(prices) << endl;
    return 0;
}