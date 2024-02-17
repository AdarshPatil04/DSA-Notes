// Time Complexity: exponential
// This code solves the minimum cost for tickets problem using a recursive approach.
// The problem is to find the minimum cost to travel every day in a given list of days, where three types of passes are available: 1-day pass, 7-day pass, and 30-day pass.
// The code defines a recursive function solveRec() that takes the total number of days, the array of days, the array of costs, and the current index as input.
// The function calculates the cost for three choices: buying a 1-day pass, buying a 7-day pass, and buying a 30-day pass.
// It recursively calls itself for the next day that is not covered by the pass and returns the minimum cost among the three choices.
// The main function calls the solveRec() function with a sample testcase and prints the minimum cost.
// https://www.codingninjas.com/codestudio/problems/minimum-coins_2180776

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
// The function takes the total number of days (n), the array of days, the array of costs, and the current index as input
int solveRec(int n, vector<int> &days, vector<int> &cost, int index)
{
    // Base case: if the index is greater than or equal to n, return 0
    // This means we have considered all the days
    if (index >= n)
        return 0;

    // Calculate the cost if we buy a 1-day pass
    // We add the cost of the 1-day pass to the result of the recursive call for the next day
    int choice1 = cost[0] + solveRec(n, days, cost, index + 1);

    // Calculate the cost if we buy a 7-day pass
    // We find the next day that is not covered by the 7-day pass and make a recursive call for that day
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ; // Find the next day that is not covered by the 7-day pass
    int choice2 = cost[1] + solveRec(n, days, cost, i);

    // Calculate the cost if we buy a 30-day pass
    // We find the next day that is not covered by the 30-day pass and make a recursive call for that day
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ; // Find the next day that is not covered by the 30-day pass
    int choice3 = cost[2] + solveRec(n, days, cost, i);

    // Return the minimum cost among the three choices
    return min(choice1, min(choice2, choice3));
}

// Function to get the minimum cost to travel every day in the given list of days
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Call the recursive function to solve the problem
    return solveRec(n, days, cost, 0);
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
