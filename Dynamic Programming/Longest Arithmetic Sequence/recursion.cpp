/**
// Time Complexity => O(n^2)
// Space Complexity => O(n) -> Recursive call stack
 * This code calculates the length of the longest arithmetic sequence in an array using a recursive approach.
 * The main function, `longestArithSeqLength`, iterates over the array and calculates the difference between each pair of numbers.
 * It then calls the `solveRec` function recursively to find the length of the arithmetic sequence starting from each number.
 * The `solveRec` function iterates backwards from the current index and checks if the difference between the current number and the j-th number equals the given difference.
 * If it does, it updates the answer with the maximum value between the current answer and 1 plus the result of the recursive call.
 * Finally, the code returns the length of the longest arithmetic sequence found.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(vector<int> &nums, int index, int diff)
{
    // Base case: if index is less than 0, return 0
    if (index < 0)
        return 0;

    int ans = 0;
    // Backward logic: iterate from the current index to 0
    for (int j = index - 1; j >= 0; j--)
    {
        // If the difference between the current number and the j-th number equals the given difference
        if (nums[index] - nums[j] == diff)
            // Update the answer with the maximum value between the current answer and 1 plus the result of the recursive call
            ans = max(ans, (1 + solveRec(nums, j, diff)));
    }
    // Return the answer
    return ans;
}

// Function to find the length of the longest arithmetic sequence
int longestArithSeqLength(vector<int> &nums)
{
    // Get the size of the array
    int n = nums.size();
    // If the size is less than or equal to 2, return the size
    if (n <= 2)
        return n;
    int ans = 0;
    // Iterate over the array
    for (int i = 0; i < n; i++)
    {
        // For each number, iterate over the rest of the array
        for (int j = i + 1; j < n; j++)
        {
            // Calculate the difference between the current number and the j-th number
            int diff = nums[j] - nums[i];
            // Update the answer with the maximum value between the current answer and 2 plus the result of the recursive call
            ans = max(ans, (2 + solveRec(nums, i, diff)));
        }
    }
    // Return the answer
    return ans;
}

// Main function
int main()
{
    // Define the array
    vector<int> nums = {3, 6, 9, 12};
    // Print the length of the longest arithmetic sequence
    cout << longestArithSeqLength(nums) << endl;
    return 0;
}
