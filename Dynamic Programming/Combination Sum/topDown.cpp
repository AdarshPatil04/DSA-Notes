/**
 * The time complexity of the algorithm is O(N), where N is the target value.
 * The space complexity is also O(N) due to the memoization array.
 * This code calculates the number of ways to get a target sum using the numbers in an array.
 * It uses a top-down approach with recursion and memoization to optimize the solution.
 */
// https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252

#include <bits/stdc++.h>
using namespace std;

// Function to find the number of ways to get the target sum using recursion and memoization
int solveMem(vector<int> &num, int tar, vector<int> &dp)
{
    // Base case: if target is 0, there is one way to get the sum (by not choosing any number)
    if (tar == 0)
        return 1;
    // If target is less than 0, there is no way to get the sum
    if (tar < 0)
        return 0;

    // If the subproblem has already been solved, return the stored result
    if (dp[tar] != -1)
        return dp[tar];

    int ans = 0;
    // For each number in the array, subtract it from the target and recursively call the function
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveMem(num, tar - num[i], dp);
    }
    // Store the result of the subproblem in the dp array
    dp[tar] = ans;
    // Return the total number of ways to get the target sum
    return dp[tar];
}

// Function to find the number of ways to get the target sum using the numbers in the array
int findWays(vector<int> &num, int tar)
{
    // Initialize a dp array with size tar+1 and fill it with -1
    vector<int> dp(tar + 1, -1);
    // Call the solveMem function with the dp array
    return solveMem(num, tar, dp);
}

int main()
{
    // Define the array of numbers and the target sum
    vector<int> num = {1, 2, 3};
    int tar = 4;
    // Print the number of ways to get the target sum
    cout << findWays(num, tar) << endl;
    return 0;
}
