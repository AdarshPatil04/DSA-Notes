/**
 * The code uses an optimal approach with a time complexity of O(nlog(n)) and a space complexity of O(n).
 * This code implements the solution to find the length of the longest increasing subsequence in a given sequence of numbers.
 * It first initializes an answer vector with the first number in the sequence.
 * Then, it iterates over the numbers from the second number to the last number.
 * For each number, it checks if it is greater than the last number in the answer vector.
 * If it is, the number is added to the end of the answer vector.
 * If it is not, it finds the index of the next immediate greater element in the answer vector and replaces it with the current number.
 * Finally, the code returns the size of the answer vector, which represents the length of the longest increasing subsequence.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using an optimal approach
int solveOptimal(vector<int> &nums, int n)
{
    // Base case: If there are no numbers, return 0
    if (n == 0)
        return 0;

    // Initialize the answer vector with the first number
    vector<int> ans;
    ans.push_back(nums[0]);

    // Iterate over the numbers from the second number to the last number
    for (int i = 1; i < n; i++)
    {
        // If the current number is greater than the last number in the answer vector
        // Add the current number to the end of the answer vector
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            // If the current number is not greater than the last number in the answer vector
            // Find the index of the next immediate greater element in the answer vector
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

            // Replace the next immediate greater element in the answer vector with the current number
            ans[index] = nums[i];
        }
    }
    // Return the size of the answer vector, which is the length of the longest increasing subsequence
    return ans.size();
}

// Function to find the length of the longest increasing subsequence
int lengthOfLIS(vector<int> &nums)
{
    // The length of the nums vector
    int n = nums.size();

    // Solve the problem using an optimal approach
    return solveOptimal(nums, n);
}

int main()
{
    // Test case: Numbers in the sequence
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Print the length of the longest increasing subsequence
    cout << lengthOfLIS(nums) << endl;

    return 0;
}
