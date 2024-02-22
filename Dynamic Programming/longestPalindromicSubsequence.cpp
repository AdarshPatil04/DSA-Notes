/**
 * It uses dynamic programming to solve the problem with time complexity O(n^2)(since n==m so it is O(n^2) instead of O(n*m) ) and space complexity O(n).
 * This code finds the length of the longest palindromic subsequence in a given string.
 * The code first reverses the input string and then calculates the length of the longest palindromic subsequence
 * by comparing characters in the original and reversed strings.
 * The result is printed for two test cases.
 */
// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
using namespace std;

// Function to find the longest palindromic subsequence
int solveSO(string &s, string &rStr)
{
    // Length of the string
    int n = s.length();

    // Current and next row of the DP table
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    // Iterating over the strings in reverse
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int ans = 0;
            // If characters match, increment the answer by 1
            if (s[i] == rStr[j])
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
    // Return the first cell of the next row which contains the length of the longest palindromic subsequence
    return next[0];
}

// Function to find the longest palindromic subsequence with space optimization
int longestPalindromeSubseq(string s)
{
    // Reverse the string
    string rStr = s;
    reverse(rStr.begin(), rStr.end());

    // Call the function with the original and reversed string
    return solveSO(s, rStr);
}

int main()
{
    // Test Cases
    cout << longestPalindromeSubseq("bbbab") << endl; // Expected output: 4
    cout << longestPalindromeSubseq("cbbd") << endl;  // Expected output: 2

    return 0;
}