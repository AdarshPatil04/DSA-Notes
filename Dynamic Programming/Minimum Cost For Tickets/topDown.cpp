/**
 * Time Complexity: O(1) since the number of days is fixed that is 365
 * This code solves the problem of finding the minimum cost to travel every day in a given list of days.
 * The code uses dynamic programming with memoization to optimize the solution.
 * The main function `minimumCoins` takes the total number of days, the list of days, and the list of costs as input.
 * It initializes a dp array with size n+1 and initial value -1.
 * It then calls the recursive function `solveMem` to solve the problem with memoization.
 * The recursive function takes the total number of days, the list of days, the list of costs, the current index, and the dp array as input.
 * It uses three choices: buying a 1-day pass, a 7-day pass, or a 30-day pass.
 * It recursively calculates the cost for each choice and stores the minimum cost in the dp array.
 * Finally, the minimum cost is returned as the result.
 * The code includes a sample testcase in the main function to demonstrate the usage of the `minimumCoins` function.
 */
// https://www.codingninjas.com/codestudio/problems/minimum-coins_2180776

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem with memoization
// The function takes the total number of days (n), the array of days, the array of costs, the current index, and the dp array as input
int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    // Base case: if the index is greater than or equal to n, return 0
    // This means we have considered all the days
    if (index >= n)
        return 0;

    // If the problem has already been solved, return the stored result
    if (dp[index] != -1)
        return dp[index];

    // Calculate the cost if we buy a 1-day pass
    // We add the cost of the 1-day pass to the result of the recursive call for the next day
    int choice1 = cost[0] + solveMem(n, days, cost, index + 1, dp);

    // Calculate the cost if we buy a 7-day pass
    // We find the next day that is not covered by the 7-day pass and make a recursive call for that day
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int choice2 = cost[1] + solveMem(n, days, cost, i, dp);

    // Calculate the cost if we buy a 30-day pass
    // We find the next day that is not covered by the 30-day pass and make a recursive call for that day
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int choice3 = cost[2] + solveMem(n, days, cost, i, dp);

    // Store the minimum cost among the three choices in the dp array
    dp[index] = min(choice1, min(choice2, choice3));

    // Return the minimum cost
    return dp[index];
}

// Function to get the minimum cost to travel every day in the given list of days
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Initialize a dp array with size n+1 and initial value -1
    vector<int> dp(n + 1, -1);

    // Call the recursive function to solve the problem
    return solveMem(n, days, cost, 0, dp);
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
