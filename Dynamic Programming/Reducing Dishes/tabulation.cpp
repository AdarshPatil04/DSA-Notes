/**
 * The time complexity of the algorithm is O(n^2), where n is the number of dishes.
 * The space complexity is O(n^2) as well.
 * This code solves the problem of maximizing the total satisfaction gained from cooking dishes.
 * It uses the tabulation technique to calculate the maximum satisfaction by considering all possible cooking sequences.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation
int solveTab(vector<int> &satisfaction)
{
    // Total number of dishes
    int n = satisfaction.size();

    // Initialize the dp table with 0
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Iterate over the dishes from right to left
    for (int index = n - 1; index >= 0; index--)
    {
        // Iterate over the cooking times from the current index to 0
        for (int time = index; time >= 0; time--)
        {
            // Include the current dish in the cooking sequence
            // The satisfaction gained is the cooking time multiplied by the satisfaction of the dish
            // Add the result from the next dish with the cooking time increased by 1
            int incl = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];

            // Exclude the current dish from the cooking sequence
            // The result is the same as the result from the next dish with the same cooking time
            int excl = dp[index + 1][time];

            // Store the maximum satisfaction gained from including or excluding the current dish in the dp table
            dp[index][time] = max(incl, excl);
        }
    }
    // Return the maximum total satisfaction
    return dp[0][0];
}

// Function to find the maximum total satisfaction
int maxSatisfaction(vector<int> &satisfaction)
{
    // Solve the problem using tabulation
    return solveTab(satisfaction);
}

int main()
{
    // Test case: Satisfaction levels of the dishes
    vector<int> satisfaction = {-1, -8, 0, 5, -9};

    // Print the maximum total satisfaction
    cout << maxSatisfaction(satisfaction) << endl;

    return 0;
}
