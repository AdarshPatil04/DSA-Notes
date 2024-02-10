/**
 * The code has a time complexity of O(N) and space Complexity will be O(N) + O(N) = O(N).
 * This code solves the problem of finding the minimum cost to climb a set of stairs.
 * The cost to climb each step is given in the 'cost' vector.
 * The code uses a recursive approach to calculate the minimum cost by considering two cases:
 * 1. Climbing from the (n-1)th step
 * 2. Climbing from the (n-2)th step
 * The minimum cost is then printed as the output.
 */
// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(vector<int> &cost, int n)
{
    // Base case: If there are no steps, the cost is 0
    if (n == 0)
        return cost[0];

    // Base case: If there is only one step, the cost is the cost of that step
    if (n == 1)
        return cost[1];

    // Recursive case: The cost to reach the nth step is the cost of the nth step plus the minimum cost to reach either of the two previous steps
    return cost[n] + min(solveRec(cost, n - 1), solveRec(cost, n - 2));
}

// Main function
int main()
{
    // The cost to climb each step
    vector<int> cost = {10, 15, 20};

    // The total number of steps
    int n = cost.size();

    // Print the minimum cost to reach the top of the floor
    // We can reach the top by either climbing from the (n-1)th step or the (n-2)th step, so we consider both cases and take the minimum
    cout << min(solveRec(cost, n - 1), solveRec(cost, n - 2)) << endl;

    return 0;
}
