/**
 * The time complexity of the algorithm is O(n*m) and the space complexity is O(n*m), where n and m are the lengths of the input strings.
 * This code calculates the length of the longest common subsequence between two strings using recursive approach with memoization.
 * The function `longestCommonSubsequence` takes two strings as input and returns the length of the longest common subsequence.
 * The recursive function `solveMem` is used to solve the problem with memoization.
 * It uses a 2D dp array to store the computed results for each pair of characters in the strings.
 * The base case is when either of the strings is empty, in which case the length of the common subsequence is 0.
 * If the characters at the current indices in the strings are the same, the length of the common subsequence is incremented by 1 and the function is called recursively for the next characters.
 * If the characters are different, the function is called recursively for the next character in either of the strings and the maximum length is returned.
 * The dp array is used to store the computed results so that they can be reused instead of recomputing them.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem with memoization
int solveMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    // Get the lengths of text1 and text2
    int n = text1.length();
    int m = text2.length();
    // Base case: if i is equal to n or j is equal to m, return 0
    if (i >= n || j >= m)
        return 0;

    // If the profit for the current characters in text1 and text2 is already computed, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If the characters at index i in text1 and index j in text2 are the same
    if (text1[i] == text2[j])
        // Return 1 plus the result of the recursive call for the next characters in text1 and text2
        return 1 + solveMem(text1, text2, i + 1, j + 1, dp);
    else
        // Otherwise, return the maximum value between the results of the recursive calls for the next character in text1 and the same character in text2,
        // and for the same character in text1 and the next character in text2
        return dp[i][j] = max(solveMem(text1, text2, i, j + 1, dp), solveMem(text1, text2, i + 1, j, dp));
}

// Function to get the length of the longest common subsequence
int longestCommonSubsequence(string text1, string text2)
{
    // Get the lengths of text1 and text2
    int n = text1.length();
    int m = text2.length();
    // Initialize the dp array for memoization
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // Call the recursive function to solve the problem
    // Start from the first characters in text1 and text2
    return solveMem(text1, text2, 0, 0, dp);
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