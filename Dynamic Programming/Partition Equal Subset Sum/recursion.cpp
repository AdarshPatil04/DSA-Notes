/**
 * The time complexity of the solution is O(2^n) and the space complexity is O(n) due to the recursive call stack.
 * This code solves the problem of partitioning an array into two subsets of equal sum.
 * It uses a recursive approach to check all possible combinations of elements to determine if a partition is possible.
 * The main function initializes an array and calls the canPartition function to check if the partition is possible.
 * The result is then printed to the console.
 */
// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
bool solveRec(vector<int> &nums, int target, int index)
{
    int n = nums.size();
    // base case: if target is 0, return true
    if (target == 0)
        return 1;

    // base case: if target is less than 0, return false
    if (target < 0)
        return 0;

    // base case: if all elements are used and target is not 0, return false
    if (index >= n)
        return 0;

    // include: pick the element at index and subtract it from the target
    bool incl = solveRec(nums, target - nums[index], index + 1);

    // exclude: do not pick the element at index
    bool excl = solveRec(nums, target, index + 1);

    // return true if either include or exclude is true
    return (incl || excl);
}

// Function to check if the array can be partitioned into two subsets of equal sum
bool canPartition(vector<int> &nums)
{
    int target = 0;
    int index = 0;
    // calculate the total sum of the array
    for (int i = 0; i < nums.size(); i++)
    {
        target += nums[i];
    }
    // if the total sum is odd, return false
    if (target & 1)
        return 0;
    // the target sum for each subset is half of the total sum
    target = target / 2;

    // Recursive
    return solveRec(nums, target, index);
}

int main()
{
    // Initialize the array
    vector<int> nums = {1, 5, 11, 5};

    // Print the result of the function
    cout << canPartition(nums) << endl;

    return 0;
}