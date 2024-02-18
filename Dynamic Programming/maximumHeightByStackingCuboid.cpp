/**
 * the problem in O(n^2) time complexity and O(n) space complexity, where n is the number
 * This code solves the problem of finding the maximum height of a stack of cuboids.
 * Given a set of cuboids, each represented by its dimensions (length, width, height),
 * the code determines the maximum height that can be achieved by stacking the cuboids
 * on top of each other, subject to the constraint that the dimensions of a cuboid must
 * be less than or equal to the corresponding dimensions of the cuboid below it.
 * The code uses dynamic programming with a space-optimized approach to efficiently solve
 * of cuboids. The main function demonstrates the usage of the code with a test case.
 */
// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

#include <bits/stdc++.h>
using namespace std;

// Function to check if a new box can be stacked on top of the base box
// Returns true if all dimensions of the new box are less than or equal to the corresponding dimensions of the base box
bool check(vector<int> base, vector<int> newBox)
{
    if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
        return true;
    else
        return false;
}

// Function to solve the problem using space optimization
int solveSO(int n, vector<vector<int>> &cuboids)
{
    // Initialize the current and next rows with 0
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    // Iterate over the cuboids from right to left
    for (int curr = n - 1; curr >= 0; curr--)
    {
        // Iterate over the previous cuboids from the current cuboid to -1
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // Initialize the include and exclude variables with 0
            int include = 0, exclude = 0;

            // If there is no previous cuboid (prev == -1) or the current cuboid can be stacked on the previous cuboid
            // Include the current cuboid in the stack
            // The height of the stack is increased by the height of the current cuboid
            // Add the result from the next cuboid with the current cuboid as the new previous cuboid
            if (prev == -1 || check(cuboids[curr], cuboids[prev]))
                include = cuboids[curr][2] + nextRow[curr + 1];

            // Exclude the current cuboid from the stack
            // The result is the same as the result from the next cuboid with the same previous cuboid
            exclude = nextRow[prev + 1];

            // Store the maximum height of the stack obtained by including or excluding the current cuboid in the current row
            currRow[prev + 1] = max(include, exclude);
        }
        // Update the next row to be the current row
        nextRow = currRow;
    }
    // Return the maximum height of the stack
    return nextRow[0];
}

// Function to find the maximum height of a stack of cuboids
int maxHeight(vector<vector<int>> &cuboids)
{
    // Step-1: Sort all dimensions of every cuboid
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    // Step-2: Sort all cuboids based on width or length
    sort(cuboids.begin(), cuboids.end());

    // The number of cuboids
    int n = cuboids.size();

    // Step-3: Use the logic of the Longest Increasing Subsequence (LIS) problem
    // Solve the problem using a space-optimized approach
    return solveSO(n, cuboids);
}

int main()
{
    // Test case: Cuboids
    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};

    // Print the maximum height of a stack of cuboids
    cout << maxHeight(cuboids) << endl;

    return 0;
}