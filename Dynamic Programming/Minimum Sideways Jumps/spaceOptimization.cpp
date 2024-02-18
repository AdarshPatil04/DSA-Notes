/**
 * Time Complexity: O(n), where n is the number of positions in the track
 * Space Complexity: O(1)
 * @brief This code implements a space-optimized solution to find the minimum number of sideways jumps required to reach the end of a track, given a sequence of obstacles.
 *
 * The code uses dynamic programming to calculate the minimum number of jumps needed at each position and lane. It iterates over the positions from right to left, and for each position, it considers all possible lanes and calculates the minimum number of jumps required to reach the end of the track. The result is stored in a space-optimized manner using two arrays: curr and next. The curr array stores the minimum number of jumps at the current position, while the next array stores the minimum number of jumps at the next position. The next array is updated to be the curr array at the end of each iteration. Finally, the minimum number of jumps needed to reach the end of the track from position 0 in lane 2 is returned as the result.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using space optimization
int solveSO(vector<int> &obs)
{
    // Total number of positions
    int n = obs.size() - 1;

    // Initialize the current and next arrays with a large value (INT_MAX)
    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    // No jumps are needed at the end of the track
    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    // Iterate over the positions from right to left
    for (int currPos = n - 1; currPos >= 0; currPos--)
    {
        // Iterate over the lanes
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            // If the next position in the current lane is not an obstacle, copy the result from the next position
            if (obs[currPos + 1] != currLane)
                curr[currLane] = next[currLane];
            else
            {
                // If the next position in the current lane is an obstacle, make a sideways jump
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    // Check all lanes except the current one and the one with an obstacle at the current position
                    if (currLane != i && obs[currPos] != i)
                        // Make a sideways jump and add the result from the next position in the new lane
                        ans = min(ans, 1 + next[i]);
                }
                // Store the result in the current array
                curr[currLane] = ans;
            }
        }
        // Update the next array to be the current array
        next = curr;
    }
    // Return the minimum number of jumps needed to reach the end of the track from position 0 in lane 2
    return min(next[2], min(1 + next[1], 1 + next[3]));
}

// Function to find the minimum number of sideways jumps
int minSideJumps(vector<int> &obstacles)
{
    // Space-Optimized Approach
    return solveSO(obstacles);
}

int main()
{
    // Test case: Obstacles at positions 1, 2, and 3
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << minSideJumps(obstacles);
    return 0;
}