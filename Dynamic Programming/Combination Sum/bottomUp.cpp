/**
 * Time complexity: O(N*M), where N is the target value and M is the size of the num array.
 * Space complexity: O(N), where N is the target value.
 * This code calculates the number of ways to get a target sum using dynamic programming.
 * It uses a bottom-up approach to fill a dp array, where each element represents the number of ways to achieve a specific sum.
 * The code iterates through the target values and the numbers in the array to calculate the number of ways for each sum.
 * The final result is the value at the target sum index in the dp array.
 */
// https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252

#include <bits/stdc++.h>
using namespace std;

// Function to find the number of ways to get the target sum using dynamic programming
int solveTab(vector<int> &num, int tar)
{
    // Step-1: Initialize a dp array with size tar+1 and fill it with 0
    vector<int> dp(tar + 1, 0);

    // Step-2: Analyze the base case. If target is 0, there is one way to get the sum (by not choosing any number)
    dp[0] = 1;

    // Step-3: Traverse on target from 1 to tar
    for (int i = 1; i <= tar; i++)
    {
        // Traverse on num vector
        for (int j = 0; j < num.size(); j++)
        {
            // If the current target is greater than or equal to the current number, add the number of ways to get the target - current number to the dp array
            if (i - num[j] >= 0)
                dp[i] += dp[i - num[j]];
        }
    }
    // Return the total number of ways to get the target sum
    return dp[tar];
}

// Function to find the number of ways to get the target sum using the numbers in the array
int findWays(vector<int> &num, int tar)
{
    // Call the solveTab function
    return solveTab(num, tar);
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
