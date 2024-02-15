/**
 * Time Complexity: O(N*W)
 * Space Complexity: O(N*W) + O(N*W)
 * This code solves the 0/1 Knapsack problem using memoization technique.
 * The 0/1 Knapsack problem is a classic optimization problem where we have a set of items,
 * each with a weight and a value, and we want to determine the maximum value we can obtain
 * by selecting a subset of items such that the total weight does not exceed a given maximum weight.
 * The code uses a recursive approach with memoization to avoid redundant calculations and improve efficiency.
 * It defines a function 'knapsack' that takes the weights, values, number of items, and maximum weight as input,
 * and returns the maximum value that can be obtained.
 * The main function initializes the weights and values of the items, and calls the 'knapsack' function to solve the problem.
 */
// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;

// Function to solve the knapsack problem using memoization
int solveMem(vector<int> &weight, vector<int> &value, int index, int maxWeight, vector<vector<int>> &dp)
{
    // Base case: If there are no items or the maximum weight is 0, the maximum value is 0
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }

    // If the subproblem has already been solved, return the stored result
    if (dp[index][maxWeight] != -1)
        return dp[index][maxWeight];

    // Calculate the maximum value if the current item is included or excluded
    int include = 0;
    if (weight[index] <= maxWeight)
    {
        include = value[index] + solveMem(weight, value, index - 1, maxWeight - weight[index], dp);
    }
    int exclude = 0 + solveMem(weight, value, index - 1, maxWeight, dp);

    // Store the maximum value of the two options in the dp table
    dp[index][maxWeight] = max(exclude, include);
    return dp[index][maxWeight];
}

// Function to solve the knapsack problem
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Initialize a dp table with -1
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // Solve the problem using memoization
    return solveMem(weight, value, n - 1, maxWeight, dp);
}

int main()
{
    // Define the weights and values of the items
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    // Define the number of items and the maximum weight
    int n = 4;
    int maxWeight = 5;
    // Print the maximum value that can be obtained
    cout << knapsack(weight, value, n, maxWeight) << endl;
    return 0;
}
