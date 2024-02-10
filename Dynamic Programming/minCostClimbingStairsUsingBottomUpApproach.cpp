/**
// Time Complexity will be O(N)
// Space Complexity will be O(N)
 * This code solves the problem of finding the minimum cost to climb a set of stairs.
 * The cost to climb each step is given in the form of an array.
 * The code uses dynamic programming with a bottom-up approach to find the minimum cost.
 * It creates a 1D array to store the minimum cost to reach each step.
 * The code iterates through the array, calculating the minimum cost to reach each step based on the cost of the current step and the minimum cost to reach the previous two steps.
 * Finally, it returns the minimum cost to reach the top from either of the last two steps.
 */
// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using dynamic programming (Bottom-Up Approach)
int solveDP2(vector<int> &cost, int n)
{
    // Step 1: Create a 1D array (vector) to store the minimum cost to reach each step
    vector<int> dp(n + 1);

    // Step 2: Initialize base cases
    // The cost to reach the first and second steps is just the cost of those steps
    dp[0] = cost[0];
    dp[1] = cost[1];

    // Step 3: Fill the array with the minimum cost to reach each step
    // Start from the third step since we've already initialized the first and second steps
    for (int i = 2; i < n; i++)
    {
        // The cost to reach the ith step is the cost of the ith step plus the minimum cost to reach either of the two previous steps
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    // Return the minimum cost to reach the top from either of the last two steps
    return min(dp[n - 1], dp[n - 2]);
}

// Function to find the minimum cost to climb the stairs
int minCostClimbingStairs(vector<int> &cost)
{
    // The total number of steps
    int n = cost.size();

    // Call the function to solve the problem using dynamic programming
    return solveDP2(cost, n);
}

// Main function
int main()
{
    // The cost to climb each step
    vector<int> cost = {10, 15, 20};

    // Print the minimum cost to climb the stairs
    cout << minCostClimbingStairs(cost) << endl;

    return 0;
}
