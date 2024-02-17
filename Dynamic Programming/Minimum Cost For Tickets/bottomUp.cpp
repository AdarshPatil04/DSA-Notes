/**
 * Time complexity: O(1) because the number of days is fixed that is 365
 * This code solves the problem of finding the minimum cost to travel every day in a given list of days.
 * The problem is solved using the tabulation (bottom-up) approach of dynamic programming.
 * The code takes the total number of days, an array of days, and an array of costs as input.
 * It calculates the minimum cost by considering three choices: buying a 1-day pass, a 7-day pass, or a 30-day pass.
 * The code iterates through the days in reverse order and calculates the minimum cost for each day.
 * Finally, it returns the minimum cost for the first day.
 */
// https://www.codingninjas.com/codestudio/problems/minimum-coins_2180776

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation (bottom-up approach)
// The function takes the total number of days (n), the array of days, and the array of costs as input
int solveTab(int n, vector<int> &days, vector<int> &cost)
{
    // Step-1: Create a dp array with size n+1 and initial value INT_MAX
    // This array will store the minimum cost for each day
    vector<int> dp(n + 1, INT_MAX);

    // Step-2: Base case analysis
    // If there are no days left, the minimum cost is 0
    dp[n] = 0;

    // Step-3: Handle remaining cases
    // Start from the last day and go backwards
    for (int k = n - 1; k >= 0; k--)
    {
        // Calculate the cost if we buy a 1-day pass
        // We add the cost of the 1-day pass to the minimum cost for the next day
        int choice1 = cost[0] + dp[k + 1];

        // Calculate the cost if we buy a 7-day pass
        // We find the next day that is not covered by the 7-day pass and add the cost of the 7-day pass to the minimum cost for that day
        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;
        int choice2 = cost[1] + dp[i];

        // Calculate the cost if we buy a 30-day pass
        // We find the next day that is not covered by the 30-day pass and add the cost of the 30-day pass to the minimum cost for that day
        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;
        int choice3 = cost[2] + dp[i];

        // Store the minimum cost among the three choices in the dp array
        dp[k] = min(choice1, min(choice2, choice3));
    }

    // Return the minimum cost for the first day
    return dp[0];
}

// Function to get the minimum cost to travel every day in the given list of days
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Call the tabulation function to solve the problem
    return solveTab(n, days, cost);
}

int main()
{
    // Test the function with a sample testcase
    int n = 6;
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> cost = {2, 7, 25};
    cout << minimumCoins(n, days, cost);
    return 0;
}
