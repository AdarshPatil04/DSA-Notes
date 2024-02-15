/**
 * The code uses dynamic programming to calculate the maximum value and has a time complexity of O(N*W),
 * where N is the number of items and W is the maximum weight.
 * The space complexity is O(maxWeight) for the dp array.
 * This code solves the 0/1 Knapsack problem using tabulation with space optimization.
 * Given a set of items, each with a weight and a value, the goal is to determine the maximum value
 * that can be obtained by selecting a subset of the items such that the sum of their weights does not exceed a given capacity.
 */
// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;

// Function to solve the 0/1 Knapsack problem using tabulation with space optimization
int solveTabSO2(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{

    // Step-1: Initialize a vector 'curr' with size maxWeight+1 and initial value 0
    vector<int> curr(maxWeight + 1, 0);

    // Step-2: Analyse the base case
    // For the first item, if its weight is less than or equal to the maximum weight,
    // its value is the maximum value we can get. Otherwise, the maximum value is 0.
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    // Step-3: Take care of remaining recursive calls
    // For each item from the second to the last, and for each possible weight from maxWeight to 0,
    // calculate the maximum value we can get by either including or excluding the current item.
    for (int i = 1; i < n; i++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {

            // If the current item can be included (its weight is less than or equal to the remaining capacity of the knapsack),
            // the maximum value we can get by including it is its value plus the maximum value we can get from the remaining capacity.
            int include = 0;
            if (weight[i] <= w)
                include = value[i] + curr[w - weight[i]];

            // The maximum value we can get by excluding the current item is the maximum value we can get from the same capacity.
            int exclude = curr[w];

            // The maximum value we can get is the maximum of the values obtained by including and excluding the current item.
            curr[w] = max(include, exclude);
        }
    }

    // Return the maximum value we can get for n items and maximum weight
    return curr[maxWeight];
}

// Function to solve the 0/1 Knapsack problem
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Call the tabulation function with space optimization
    return solveTabSO2(weight, value, n, maxWeight);
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
    cout << knapsack(weight, value, n, maxWeight) << endl;

    // Return 0 to indicate normal termination of the program
    return 0;
}