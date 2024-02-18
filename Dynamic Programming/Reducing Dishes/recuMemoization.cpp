/**
 * The time complexity of the solution is O(n^2), where n is the number of dishes, and the space complexity is O(n^2).
 * This code implements a solution to the "Reducing Dishes" problem using memoization technique.
 * The problem is to find the maximum total satisfaction that can be obtained by cooking a sequence of dishes.
 * Each dish has a satisfaction level and a cooking time, and the satisfaction gained from a dish is the cooking time multiplied by the satisfaction level.
 * The code uses a recursive approach with memoization to avoid redundant computations and improve efficiency.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using memoization
int solveMem(vector<int> &satisfaction, int idx, int time, vector<vector<int>> &dp)
{
    // Base case: If we have reached the end of the satisfaction vector, return 0
    if (idx == satisfaction.size())
        return 0;

    // If we have already computed the result for this index and time, return it
    if (dp[idx][time] != -1)
        return dp[idx][time];

    // Include the current dish in the cooking sequence
    // The satisfaction gained is the cooking time multiplied by the satisfaction of the dish
    // Recursively solve for the next dish with the cooking time increased by 1
    int incl = satisfaction[idx] * (time + 1) + solveMem(satisfaction, idx + 1, time + 1, dp);

    // Exclude the current dish from the cooking sequence
    // Recursively solve for the next dish with the same cooking time
    int excl = solveMem(satisfaction, idx + 1, time, dp);

    // Store the maximum satisfaction gained from including or excluding the current dish in the dp table
    return dp[idx][time] = max(incl, excl);
}

// Function to find the maximum total satisfaction
int maxSatisfaction(vector<int> &satisfaction)
{
    // Sort the satisfaction vector in ascending order
    // This ensures that the dishes with the least satisfaction are cooked first
    sort(satisfaction.begin(), satisfaction.end());

    // Initialize the dp table with -1
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    // Solve the problem using memoization starting from the first dish with a cooking time of 0
    return solveMem(satisfaction, 0, 0, dp);
}

int main()
{
    // Test case: Satisfaction levels of the dishes
    vector<int> satisfaction = {-1, -8, 0, 5, -9};

    // Print the maximum total satisfaction
    cout << maxSatisfaction(satisfaction) << endl;

    return 0;
}
