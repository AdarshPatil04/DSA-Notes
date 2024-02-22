/**
 * The time complexity of this algorithm is O(n*m), where n and m are the lengths of the input strings.
 * The space complexity is O(m), as it uses two rows of the DP table to store the intermediate results.
 * This code implements the space-optimized version of the Longest Common Subsequence (LCS) problem.
 * It finds the length of the longest common subsequence between two given strings using dynamic programming.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to find the longest common subsequence
int solveSO(string &text1, string &text2)
{
    // Length of the two strings
    int n = text1.length();
    int m = text2.length();

    // Current and next row of the DP table
    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);

    // Iterating over the strings in reverse
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            // If characters match, increment the answer by 1
            if (text1[i] == text2[j])
                ans = 1 + next[j + 1];
            // If characters don't match, take the maximum of the next row and current column
            else
                ans = max(curr[j + 1], next[j]);

            // Update the current cell with the calculated answer
            curr[j] = ans;
        }
        // Update the next row with the current row
        next = curr;
    }
    // Return the first cell of the next row which contains the length of the longest common subsequence
    return next[0];
}

// Function to find the longest common subsequence with space optimization
int longestCommonSubsequence(string text1, string text2)
{
    return solveSO(text1, text2);
}

int main()
{
    // Test strings
    string text1 = "abcde";
    string text2 = "ace";

    // Print the length of the longest common subsequence
    cout << longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
