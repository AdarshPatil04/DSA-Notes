/**
 * Time Complexity: O(2^n) due to the two recursive calls
 * Space Complexity: O(n) for the recursion depth
 * This code solves the 0/1 Knapsack problem using a recursive approach.
 * The 0/1 Knapsack problem is a classic optimization problem where we have a knapsack with a maximum weight capacity
 * and a set of items with their respective weights and values. The goal is to maximize the total value of the items
 * that can be included in the knapsack without exceeding its weight capacity.
 *
 * The code uses a recursive function to explore all possible combinations of including or excluding each item,
 * and returns the maximum value that can be obtained.
 *
 *
 * Source: [Coding Ninjas](https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542)
 */

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the 0/1 Knapsack problem
int solveRec(vector<int> &weight, vector<int> &value, int index, int maxWeight)
{
    // Base case: If there is only one item available
    if (index == 0)
    {
        // Check the weight of the item against the capacity limit of the knapsack
        if (weight[0] <= maxWeight)
        {
            // If the item can be included, return its value
            return value[0];
        }
        else
        {
            // If the item cannot be included, return 0
            return 0;
        }
    }

    // Initialize the values of including and excluding the current item
    int include = 0;
    int exclude = 0;

    // If the current item can be included (its weight is less than or equal to the remaining capacity of the knapsack)
    if (weight[index] <= maxWeight)
    {
        // Calculate the total value if we include the current item
        // This is the value of the current item plus the maximum value we can get from the remaining items and remaining capacity
        include = value[index] + solveRec(weight, value, index - 1, maxWeight - weight[index]);
    }

    // Calculate the total value if we exclude the current item
    // This is the maximum value we can get from the remaining items and the same capacity
    exclude = solveRec(weight, value, index - 1, maxWeight);

    // The maximum value we can get is the maximum of the values obtained by including and excluding the current item
    int ans = max(exclude, include);

    // Return the calculated maximum value
    return ans;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Call the recursive function with the last index and the maximum weight
    return solveRec(weight, value, n - 1, maxWeight);
}

int main()
{
    // Weights and values of the items
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};

    // Number of items and maximum weight
    int n = 4;
    int maxWeight = 5;

    // Print the maximum value we can get
    cout << knapsack(weight, value, n, maxWeight);

    // Return 0 to indicate normal termination of the program
    return 0;
}
