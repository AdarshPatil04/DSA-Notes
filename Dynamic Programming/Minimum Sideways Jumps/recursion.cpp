/**
 * This code solves the problem of finding the minimum number of sideways jumps required to reach the end position
 * given a sequence of obstacles in different lanes. The code uses a recursive approach to explore all possible
 * paths and returns the minimum number of jumps. The time complexity of the code is O(2^n) and the space complexity
 * is O(4*n), where n is the number of positions in the obstacle sequence.
 */
// https://leetcode.com/problems/minimum-sideway-jumps/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(vector<int> &obs, int currLane, int currPos)
{
    // Total number of positions
    int n = obs.size() - 1;

    // Base case: If we have reached the end, no more jumps are needed
    if (currPos == n)
        return 0;

    // If the next position in the current lane is not an obstacle, move forward in the same lane
    if (obs[currPos + 1] != currLane)
    {
        return solveRec(obs, currLane, currPos + 1);
    }
    else
    {
        // If the next position in the current lane is an obstacle, make a sideways jump
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            // Check all lanes except the current one and the one with an obstacle at the current position
            if (currLane != i && obs[currPos] != i)
                // Make a sideways jump and recursively solve for the new position
                ans = min(ans, 1 + solveRec(obs, i, currPos));
        }
        return ans;
    }
}

// Function to find the minimum number of sideways jumps
int minSideJumps(vector<int> &obstacles)
{
    // Start from lane 2 at position 0
    return solveRec(obstacles, 2, 0);
}

int main()
{
    // Test case: Obstacles at positions 1, 2, and 3
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << minSideJumps(obstacles);
}
