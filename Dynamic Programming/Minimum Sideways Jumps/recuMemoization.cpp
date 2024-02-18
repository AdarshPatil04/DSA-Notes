/**
// Time Complexity => O(n)
// Space Complexity => O(4*n)
 * This code solves the problem of finding the minimum number of sideways jumps required to reach the end position
 * given a sequence of obstacles in different lanes. It uses a recursive approach with memoization to optimize the
 * computation. The code defines a function `minSideJumps` that takes a vector of obstacles as input and returns the
 * minimum number of sideways jumps. The main logic is implemented in the `solveMem` function, which recursively
 * calculates the minimum jumps for each position and lane using memoization. The code initializes a dp table to store
 * the computed results and avoids redundant calculations by checking if the result for a position and lane is already
 * available in the dp table. The code also handles the case where the next position in the current lane is an obstacle
 * by making a sideways jump to a different lane. The final result is printed in the `main` function using a test case.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using memoization
int solveMem(vector<int> &obs, int currLane, int currPos, vector<vector<int>> &dp)
{
    // Total number of positions
    int n = obs.size() - 1;

    // Base case: If we have reached the end, no more jumps are needed
    if (currPos == n)
        return 0;

    // If we have already computed the result for this position and lane, return it
    if (dp[currLane][currPos] != -1)
        return dp[currLane][currPos];

    // If the next position in the current lane is not an obstacle, move forward in the same lane
    if (obs[currPos + 1] != currLane)
        return solveMem(obs, currLane, currPos + 1, dp);
    else
    {
        // If the next position in the current lane is an obstacle, make a sideways jump
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            // Check all lanes except the current one and the one with an obstacle at the current position
            if (currLane != i && obs[currPos] != i)
                // Make a sideways jump and recursively solve for the new position
                ans = min(ans, 1 + solveMem(obs, i, currPos, dp));
        }
        // Store the result in the dp table
        dp[currLane][currPos] = ans;
        return dp[currLane][currPos];
    }
}

// Function to find the minimum number of sideways jumps
int minSideJumps(vector<int> &obstacles)
{
    // Initialize the dp table with -1
    vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));

    // Start from lane 2 at position 0
    return solveMem(obstacles, 2, 0, dp);
}

int main()
{
    // Test case: Obstacles at positions 1, 2, and 3
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << minSideJumps(obstacles);
}
