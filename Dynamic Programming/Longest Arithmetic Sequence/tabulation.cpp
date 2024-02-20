/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 * @brief This code calculates the length of the longest arithmetic sequence in an array using tabulation.
 * The code uses dynamic programming to solve the problem. It iterates over the array and for each number,
 * it calculates the difference between the current number and the previous numbers. It then stores the count
 * of the arithmetic sequence for each difference in a dp array. The answer is updated with the maximum count
 * found so far. Finally, the code returns the length of the longest arithmetic sequence.
 *
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem with tabulation
int solveTab(vector<int> &nums, int n, int ans)
{
    // Initialize the dp array for tabulation
    unordered_map<int, int> dp[n + 1];

    // Iterate over the array starting from the second element
    for (int index = 1; index < n; index++)
    {
        // For each number, iterate over the previous numbers
        for (int j = 0; j < index; j++)
        {
            // Calculate the difference between the current number and the j-th number
            int diff = nums[index] - nums[j];
            int cnt = 1;

            // If the difference is already computed for the j-th index, get the count
            if (dp[j].count(diff))
                cnt = dp[j][diff];

            // Store the count plus one for the current index and difference in the dp array
            dp[index][diff] = 1 + cnt;
            // Update the answer with the maximum value between the current answer and the count for the current index and difference
            ans = max(ans, dp[index][diff]);
        }
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
    // Call the tabulation function to solve the problem
    return solveTab(nums, n, ans);
}

int main()
{
    // Define the array
    vector<int> nums = {3, 6, 9, 12};
    // Print the length of the longest arithmetic sequence
    cout << longestArithSeqLength(nums) << endl;
    return 0;
}
