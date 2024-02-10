/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * This code solves the problem of finding the minimum cost to climb a set of stairs.
 * The cost to climb each step is given in the form of an array.
 * The code uses dynamic programming with a top-down approach to solve the problem.
 * It recursively calculates the minimum cost to reach each step and stores the results in a memoization table.
 * The final result is the minimum cost to reach the top from either of the last two stairs.
 */
// https://leetcode.com/problems/min-cost-climbing-stairs/

// Importing necessary libraries
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem using dynamic programming (Top-Down Approach)
int solveDP1(vector<int> &cost, int n, vector<int> &dp)
{
    // Base case: If there are no steps or only one step, the cost is the cost of that step
    if (n == 0 || n == 1)
        return cost[n];

    // If the subproblem has already been solved, return the stored result
    if (dp[n] != -1)
        return dp[n];

    // Recursive case: The cost to reach the nth step is the cost of the nth step plus the minimum cost to reach either of the two previous steps
    return dp[n] = cost[n] + min(solveDP1(cost, n - 1, dp), solveDP1(cost, n - 2, dp));
}

// Function to find the minimum cost to climb the stairs
int minCostClimbingStairs(vector<int> &cost)
{
    // The total number of steps
    int n = cost.size();

    // Create a memoization table and initialize it with -1
    vector<int> dp(n + 1, -1);

    // The final result is the minimum cost to reach the top from either of the last two stairs
    return min(solveDP1(cost, n - 1, dp), solveDP1(cost, n - 2, dp));
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
