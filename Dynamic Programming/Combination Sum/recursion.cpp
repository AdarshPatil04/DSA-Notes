/**
 * The time complexity of this recursive solution is exponential.
 * This code calculates the number of ways to get a target sum using the numbers in an array.
 * It uses a recursive approach to find all possible combinations of numbers that sum up to the target.
 */
// https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252

#include <bits/stdc++.h>
using namespace std;

// Recursive function to find the number of ways to get the target sum
int solveRec(vector<int> &num, int tar)
{
    // Base case: if target is 0, there is one way to get the sum (by not choosing any number)
    if (tar == 0)
        return 1;
    // If target is less than 0, there is no way to get the sum
    if (tar < 0)
        return 0;

    int ans = 0;
    // For each number in the array, subtract it from the target and recursively call the function
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveRec(num, tar - num[i]);
    }
    // Return the total number of ways to get the target sum
    return ans;
}

// Function to find the number of ways to get the target sum using the numbers in the array
int findWays(vector<int> &num, int tar)
{
    // Call the recursive function
    return solveRec(num, tar);
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
