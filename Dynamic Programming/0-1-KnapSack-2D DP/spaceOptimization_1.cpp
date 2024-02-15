/**
 * Time Complexity: O(N*W), where N is the number of items and W is the maximum weight
 * Space Complexity: O(2*maxWeight) for the dp array
 * This code solves the 0/1 Knapsack problem using tabulation with space optimization.
 * Given a set of items, each with a weight and a value, the goal is to determine the maximum value
 * that can be obtained by selecting a subset of the items such that the sum of the weights of the
 * selected items is less than or equal to a given maximum weight.
 *
 * The code uses dynamic programming to solve the problem in bottom-up manner, starting from the base case
 * and building up the solution for larger subproblems. It optimizes the space complexity by using two vectors
 * to store the values for the current and previous iterations instead of a 2D array.
 * Source: https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542
 */

#include <bits/stdc++.h>
using namespace std;

// Function to solve the 0/1 Knapsack problem using tabulation with space optimizationF
int solveTabSO(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // Step-1: Initialize two vectors 'prev' and 'curr' with size maxWeight+1 and initial value 0
    vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);

    // Step-2: Analyse the base case
    // For the first item, if its weight is less than or equal to the maximum weight,
    // its value is the maximum value we can get. Otherwise, the maximum value is 0.
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    // Step-3: Take care of remaining recursive calls
    // For each item from the second to the last, and for each possible weight from 0 to maxWeight,
    // calculate the maximum value we can get by either including or excluding the current item.
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            // If the current item can be included (its weight is less than or equal to the remaining capacity of the knapsack),
            // the maximum value we can get by including it is its value plus the maximum value we can get from the remaining items and remaining capacity.
            int include = 0;
            if (weight[i] <= w)
                include = value[i] + prev[w - weight[i]];

            // The maximum value we can get by excluding the current item is the maximum value we can get from the remaining items and the same capacity.
            int exclude = prev[w];

            // The maximum value we can get is the maximum of the values obtained by including and excluding the current item.
            curr[w] = max(include, exclude);
        }

        // Update the 'prev' vector to be the 'curr' vector for the next iteration
        prev = curr;
    }

    // Return the maximum value we can get for n items and maximum weight
    return prev[maxWeight];
}

// Function to solve the 0/1 Knapsack problem
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Call the tabulation function with space optimization
    return solveTabSO(weight, value, n, maxWeight);
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
