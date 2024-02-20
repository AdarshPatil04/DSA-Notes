/**
 * This code finds the length of the longest subsequence in an array
 * with a given difference. It uses dynamic programming to store the
 * counts of subsequence lengths for each element in the array. The
 * algorithm iterates over the array, calculates the temporary value
 * as the difference between the current number and the given difference,
 * and checks if the temporary value is already computed. If it is, it
 * retrieves the count from the dynamic programming array. Then, it
 * stores the count plus one for the current number in the dynamic
 * programming array and updates the answer with the maximum value
 * between the current answer and the count for the current number.
 * Finally, it returns the answer, which represents the length of the
 * longest subsequence with the given difference.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subsequence with a given difference
int longestSubsequence(vector<int> &arr, int difference)
{
    // Get the size of the array
    int n = arr.size();
    // Initialize the dp array for tabulation
    unordered_map<int, int> dp;
    // Initialize the answer
    int ans = 0;

    // Iterate over the array
    for (int i = 0; i < n; i++)
    {
        // Calculate the temporary value as the difference between the current number and the given difference
        int temp = arr[i] - difference;
        int tempAns = 0;
        // If the temporary value is already computed, get the count
        if (dp.count(temp))
            tempAns = dp[temp];

        // Store the count plus one for the current number in the dp array
        dp[arr[i]] = 1 + tempAns;

        // Update the answer with the maximum value between the current answer and the count for the current number
        ans = max(ans, dp[arr[i]]);
    }
    // Return the answer
    return ans;
}

int main()
{
    // Define the array
    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    // Define the difference
    int difference = -2;
    // Print the length of the longest subsequence with the given difference
    cout << longestSubsequence(arr, difference) << endl;
    return 0;
}
