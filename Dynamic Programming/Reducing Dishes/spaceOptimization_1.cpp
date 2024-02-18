/**
 * The code uses a space-optimized approach to solve the problem in O(n^2) time complexity and O(n) space complexity.
 * This code implements a dynamic programming solution to the "Reducing Dishes" problem.
 * The problem is to find the maximum total satisfaction that can be obtained by cooking a sequence of dishes.
 * Each dish has a satisfaction level, and the cooking time for each dish is equal to its position in the sequence.
 * It sorts the satisfaction levels in ascending order to ensure that the dishes with the least satisfaction are cooked first.
 * The code then iterates over the dishes from right to left, calculating the maximum satisfaction gained by including or excluding each dish.
 * The maximum total satisfaction is returned as the output.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using space optimization
int solveSO(vector<int> &satisfaction)
{
    // Total number of dishes
    int n = satisfaction.size();

    // Initialize the current and next arrays with 0
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    // Iterate over the dishes from right to left
    for (int index = n - 1; index >= 0; index--)
    {
        // Iterate over the cooking times from the current index to 0
        for (int time = index; time >= 0; time--)
        {
            // Include the current dish in the cooking sequence
            // The satisfaction gained is the cooking time multiplied by the satisfaction of the dish
            // Add the result from the next dish with the cooking time increased by 1
            int incl = satisfaction[index] * (time + 1) + next[time + 1];

            // Exclude the current dish from the cooking sequence
            // The result is the same as the result from the next dish with the same cooking time
            int excl = next[time];

            // Store the maximum satisfaction gained from including or excluding the current dish in the current array
            curr[time] = max(incl, excl);
        }
        // Update the next array to be the current array
        next = curr;
    }
    // Return the maximum total satisfaction
    return next[0];
}

// Function to find the maximum total satisfaction
int maxSatisfaction(vector<int> &satisfaction)
{
    // Sort the satisfaction vector in ascending order
    // This ensures that the dishes with the least satisfaction are cooked first
    sort(satisfaction.begin(), satisfaction.end());

    // Solve the problem using a space-optimized approach
    return solveSO(satisfaction);
}

int main()
{
    // Test case: Satisfaction levels of the dishes
    vector<int> satisfaction = {-1, -8, 0, 5, -9};

    // Print the maximum total satisfaction
    cout << maxSatisfaction(satisfaction) << endl;

    return 0;
}
