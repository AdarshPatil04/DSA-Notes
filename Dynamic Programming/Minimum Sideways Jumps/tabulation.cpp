/**
 * This code solves the problem of finding the minimum number of sideways jumps required to reach the end of a track,
 * given a sequence of obstacles in the track. The code uses a tabulation approach to calculate the minimum jumps.
 * The time complexity of the code is O(n), where n is the number of positions in the track, and the space complexity
 * is O(4*n), where 4 represents the number of lanes in the track.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation
int solveTab(vector<int> &obs)
{
    // Total number of positions
    int n = obs.size() - 1;

    // Initialize the dp table with a large value (1e9)
    vector<vector<int>> dp(4, vector<int>(obs.size(), 1e9));

    // No jumps are needed at the end of the track
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    // Iterate over the positions from right to left
    for (int currPos = n - 1; currPos >= 0; currPos--)
    {
        // Iterate over the lanes
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            // If the next position in the current lane is not an obstacle, copy the result from the next position
            if (obs[currPos + 1] != currLane)
                dp[currLane][currPos] = dp[currLane][currPos + 1];
            else
            {
                // If the next position in the current lane is an obstacle, make a sideways jump
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    // Check all lanes except the current one and the one with an obstacle at the current position
                    if (currLane != i && obs[currPos] != i)
                        // Make a sideways jump and add the result from the next position in the new lane
                        ans = min(ans, 1 + dp[i][currPos + 1]);
                }
                // Store the result in the dp table
                dp[currLane][currPos] = ans;
            }
        }
    }
    // Return the minimum number of jumps needed to reach the end of the track from position 0 in lane 2
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}

// Function to find the minimum number of sideways jumps
int minSideJumps(vector<int> &obstacles)
{
    // Bottom-Up Approach (Tabulation)
    return solveTab(obstacles);
}

int main()
{
    // Test case: Obstacles at positions 1, 2, and 3
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << minSideJumps(obstacles);
    return 0;
}
