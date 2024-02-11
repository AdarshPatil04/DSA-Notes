// The time complexity of this code is O(X*N), where X is the target value and N is the number of elements in the array.
// The space complexity is O(X), where X is the target value.
// This code solves the problem of finding the minimum number of elements from a given array that add up to a target value.
// It uses a bottom-up approach (tabulation) to calculate the minimum number of elements.
// The code initializes a dp array with size x+1 and initializes all elements to INT_MAX.
// It then iterates over each possible sum from 1 to x and for each sum, iterates over each element in the array.
// If the current sum can be obtained by adding the current element to a previous sum, it updates the minimum number of elements needed to get the current sum.
// If the minimum number of elements to get a sum of x is still INT_MAX, it means the problem cannot be solved and -1 is returned.
// Otherwise, the minimum number of elements is returned.
// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using a bottom-up approach (tabulation)
// This function has a time complexity of O(X*N) where X is the target value and N is the number of elements in the array
// The space complexity is O(X) where X is the target value
int solveTab(vector<int> &num, int x)
{
    // Step-1: Create a dp array with size x+1 and initialize all elements to INT_MAX
    vector<int> dp(x + 1, INT_MAX);

    // Step-2: The minimum number of elements to get a sum of 0 is 0
    dp[0] = 0;

    // Step-3: Iterate over each possible sum from 1 to x
    for (int i = 1; i <= x; i++)
    {
        // For each possible sum, iterate over each element in the array
        for (int j = 0; j < num.size(); j++)
        {
            // If the current sum can be obtained by adding the current element to a previous sum
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
            {
                // Update the minimum number of elements needed to get the current sum
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    // If the minimum number of elements to get a sum of x is still INT_MAX, it means the problem cannot be solved
    // Return -1 in this case
    if (dp[x] == INT_MAX)
        return -1;
    else
        // Otherwise, return the minimum number of elements
        return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // Call the tabulation function to solve the problem
    return solveTab(num, x);
}

int main()
{
    // Define the array of numbers
    vector<int> num = {1, 2, 3};

    // Define the target value
    int x = 5;

    // Call the function to find the minimum number of elements that add up to x
    // Print the result
    cout << minimumElements(num, x);

    return 0;
}
