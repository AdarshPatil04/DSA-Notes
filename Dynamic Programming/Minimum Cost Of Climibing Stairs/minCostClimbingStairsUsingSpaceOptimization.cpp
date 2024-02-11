/**
// Time Complexity will be O(N)
// Space Complexity will be O(1)
 * This code solves the problem of finding the minimum cost to climb a set of stairs.
 * The cost to climb each step is given in the 'cost' vector.
 * The code uses dynamic programming with a bottom-up approach and optimizes the space complexity to O(1).
 * It calculates the minimum cost to reach each step starting from the third step, by considering the cost of the current step
 * and the minimum cost to reach either of the two previous steps.
 * Finally, it returns the minimum cost to reach the top from either of the last two steps.
 */
// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using dynamic programming (Bottom-Up Approach)
// This function optimizes the space complexity to O(1)
int solveDP3(vector<int> &cost, int n)
{
    // Initialize the cost of climbing the first and second steps
    int prev2 = cost[0];
    int prev1 = cost[1];

    // Calculate the minimum cost to reach each step starting from the third
    for (int i = 2; i < n; i++)
    {
        // The cost to reach the ith step is the cost of the ith step plus the minimum cost to reach either of the two previous steps
        int curr = cost[i] + min(prev1, prev2);

        // Update the cost of the two previous steps
        prev2 = prev1;
        prev1 = curr;
    }

    // Return the minimum cost to reach the top from either of the last two steps
    return min(prev1, prev2);
}

// Function to find the minimum cost to climb the stairs
int minCostClimbingStairs(vector<int> &cost)
{
    // The total number of steps
    int n = cost.size();

    // Call the function to solve the problem using dynamic programming
    return solveDP3(cost, n);
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
