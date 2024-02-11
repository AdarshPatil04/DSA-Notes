/**
 * The code has a high time complexity due to repeated calculations.
 * This code calculates the maximum sum of non-adjacent elements in an array using recursion.
 * The function `maximumNonAdjacentSum` takes an array of integers as input and returns the maximum sum.
 * The recursive function `solveRec` is used to solve the problem by considering two cases:
 * 1. Including the current element in the sum.
 * 2. Excluding the current element from the sum.
 * The function `solveRec` is called recursively to calculate the maximum sum.
 * The base cases are defined to handle the empty array and negative indices.
 */
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
// This function has a high time complexity due to repeated calculations
int solveRec(vector<int> &nums, int n)
{
    // Base case: If n is 0, return the first element of the array
    if (n == 0)
        return nums[0];

    // Base case: If n is less than 0, return 0
    if (n < 0)
        return 0;

    // Recursive calls:
    // incl represents the maximum sum including the current element
    // excl represents the maximum sum excluding the current element
    int incl = solveRec(nums, n - 2) + nums[n];
    int excl = solveRec(nums, n - 1);

    // Return the maximum of incl and excl
    return max(incl, excl);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Get the size of the array
    int n = nums.size();

    // Call the recursive function to solve the problem
    return solveRec(nums, n - 1);
}

int main()
{
    // Define the array of numbers
    vector<int> nums = {5, 5, 10, 100, 10, 5};

    // Call the function to find the maximum sum of non-adjacent elements
    // Print the result
    cout << maximumNonAdjacentSum(nums);

    return 0;
}
