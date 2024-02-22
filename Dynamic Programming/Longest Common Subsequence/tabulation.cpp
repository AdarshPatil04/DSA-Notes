/**
 * The code uses a dynamic programming approach to solve the problem, with a time complexity of O(n*m) and a space complexity of O(n*m), where n and m are the lengths of the input strings.
 * This code implements the tabulation approach to find the length of the longest common subsequence between two strings.
 * The longest common subsequence is defined as the longest sequence of characters that appears in the same order in both strings.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem with tabulation
int solveTab(string &text1, string &text2)
{
    // Get the lengths of text1 and text2
    int n = text1.length();
    int m = text2.length();
    // Initialize the dp array for tabulation
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Iterate from the end to the start of the characters in text1 and text2
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            // Initialize the answer as 0
            int ans = 0;
            // If the characters at index i in text1 and index j in text2 are the same
            if (text1[i] == text2[j])
                // Update the answer with 1 plus the value in the dp array for the next characters in text1 and text2
                ans = 1 + dp[i + 1][j + 1];
            else
                // Otherwise, update the answer with the maximum value between the values in the dp array for the next character in text1 and the same character in text2,
                // and for the same character in text1 and the next character in text2
                ans = max(dp[i][j + 1], dp[i + 1][j]);
            // Store the computed answer for the current characters in text1 and text2 in the dp array
            dp[i][j] = ans;
        }
    }
    // Return the answer for the first characters in text1 and text2
    return dp[0][0];
}

// Function to get the length of the longest common subsequence
int longestCommonSubsequence(string text1, string text2)
{
    // Call the tabulation function to solve the problem
    return solveTab(text1, text2);
}

int main()
{
    // Define the strings
    string text1 = "abcde";
    string text2 = "ace";
    // Print the length of the longest common subsequence
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
