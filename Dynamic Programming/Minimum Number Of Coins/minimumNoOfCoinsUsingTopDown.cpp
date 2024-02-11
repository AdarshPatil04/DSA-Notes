/**
 * This code solves the problem of finding the minimum number of elements from a given array
 * that sum up to a target value using a top-down approach with memoization.
 * The function `minimumElements` takes an array of numbers `num` and a target value `x` as input,
 * and returns the minimum number of elements required to achieve the target sum.
 * If it is not possible to achieve the target sum using the given array elements, the function returns -1.
 * The code uses recursion and memoization to optimize the solution by avoiding redundant calculations.
 * The time complexity of the code is O(X*N), where X is the target value and N is the number of elements in the array.
 * The space complexity is O(X), where X is the target value.
 */
// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem using a top-down approach (memoization)
// This function has a time complexity of O(X*N) where X is the target value and N is the number of elements in the array
// The space complexity is O(X) where X is the target value
int solveMem(vector<int> &num, int x, vector<int> &dp)
{
    // Base case: If x is 0, the minimum number of elements is 0
    if (x == 0)
        return 0;

    // Base case: If x is less than 0, return a large number (infinity)
    if (x < 0)
        return INT_MAX;

    // If the subproblem has already been solved, return the stored result
    if (dp[x] != -1)
        return dp[x];

    // Initialize the minimum number of elements as a large number (infinity)
    int mini = INT_MAX;

    // Iterate over each element in the array
    for (int i = 0; i < num.size(); i++)
    {
        // Recursively solve the subproblem for x - num[i]
        int ans = solveMem(num, x - num[i], dp);

        // If the subproblem can be solved, update the minimum number of elements
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans); // 1 is added here for num[i]
    }

    // Store the result of the subproblem in the memoization table
    dp[x] = mini;

    // Return the minimum number of elements
    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    // Initialize the memoization table with -1
    vector<int> dp(x + 1, -1);

    // Call the recursive function to solve the problem
    int ans = solveMem(num, x, dp);

    // If the result is INT_MAX, it means the problem cannot be solved
    // Return -1 in this case
    if (ans == INT_MAX)
        return -1;
    else
        // Otherwise, return the result
        return ans;
}

int main()
{
    // Define the array of numbers
    vector<int> num = {1, 2, 3};

    // Define the target value
    int x = 5;

    // Call the function and print the result
    cout << minimumElements(num, x);
    return 0;
}
