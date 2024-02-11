/**
 * The time complexity of the solution is O(N), where N is the size of the input array.
 * The space complexity is O(N).
 * This code solves the house robbery problem, where each house has a certain value.
 * The goal is to find the maximum sum of non-adjacent house values that can be robbed.
 * The solution uses a bottom-up approach (tabulation) with space optimization.
 */
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using a bottom-up approach (tabulation) with space optimization
long int solve(vector<int> &nums)
{
    int n = nums.size(); // Get the size of the array

    // Initialize the maximum sums for the first two elements
    long int prev1 = nums[0];
    long int prev2 = 0;

    // Iterate over each element in the array starting from the second element
    for (int i = 1; i < n; i++)
    {
        long long int incl = prev2 + nums[i]; // Include the current element and the maximum sum for the element two positions before
        long long int excl = prev1 + 0;       // Exclude the current element and take the maximum sum for the previous element

        // Calculate the maximum of incl and excl
        long long int ans = max(incl, excl);

        // Update the maximum sums for the next iteration
        prev2 = prev1;
        prev1 = ans;
    }

    // Return the maximum sum for the last element
    return prev1;
}

// Function to find the maximum sum of non-adjacent elements
long int houseRobber(vector<int> &valueInHouse)
{
    // make n = valueInHouse.size();
    int n = valueInHouse.size();

    // if there is only one house, return the value of that house
    if (n == 1)
    {
        return valueInHouse[0];
    }

    // Make two vectors to store the values of the houses
    vector<int> first, second;

    // Iterate over the valueInHouse vector and store the values in the first and second vectors
    for (int i = 0; i < n; i++)
    {
        // if i is not the last element, push the value in the first vector
        if (i != n - 1)
        {
            first.push_back(valueInHouse[i]);
        }

        // if i is not the first element, push the value in the second vector
        if (i != 0)
        {
            second.push_back(valueInHouse[i]);
        }
    }

    // return the maximum sum of the two vectors
    return max(solve(first), solve(second));
}

int main()
{
    // Define the array of numbers
    vector<int> nums = {2, 7, 9, 3, 1};

    // Call the function to find the maximum sum of non-adjacent elements
    // Print the result
    cout << "The maximum sum of non-adjacent elements is: " << houseRobber(nums) << endl;

    return 0;
}
