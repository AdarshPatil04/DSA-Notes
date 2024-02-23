/**
 * // Time Complexity => O(n*m)
    // Space Complexity => O(n*m)
 * @brief This code implements the wildcard matching problem using dynamic programming.
 *        It checks whether a given string matches a given pattern that may contain wildcard characters '?' and '*'.
 *        The code uses tabulation to solve the problem, storing the results of subproblems in a 2D vector.
 *        It iterates through the string and the pattern, updating the values in the vector based on the matching conditions.
 *        The final result is obtained from the last element of the vector.
 *        The main function tests the code with example inputs.
 *
 * @param str The input string to be matched.
 * @param pattern The pattern to match against the string.
 * @return true if the string matches the pattern, false otherwise.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the wildcard matching problem using dynamic programming
bool solveTab(string &str, string &pattern)
{
    // Get the lengths of the string and the pattern
    int n = str.length();
    int m = pattern.length();

    // Initialize a 2D vector to store the results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // The base case: an empty string matches with an empty pattern
    dp[0][0] = true;

    // For each character in the pattern
    for (int j = 1; j <= m; j++)
    {
        bool flag = true;
        // If the pattern contains only '*', it matches with an empty string
        for (int k = 1; k <= j; k++)
        {
            if (pattern[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    // For each character in the string and the pattern
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // If the characters match or the pattern has '?', the result is the same as the previous characters
            if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            // If the pattern has '*', it can match with the current character or not
            else if (pattern[j - 1] == '*')
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
            // If the characters don't match and the pattern doesn't have '*' or '?', the string and the pattern don't match
            else
                dp[i][j] = false;
        }
    }

    // The result is stored in dp[n][m]
    return dp[n][m];
}

// Function to check whether a string matches with a pattern
bool isMatch(string s, string p)
{
    // Call the function solveTab to check the match
    return solveTab(s, p);
}

int main()
{
    // Test the function with example inputs
    string s = "adceb";
    string p = "*a*b";
    cout << isMatch(s, p) << endl; // Expected output: 1 (true)

    return 0;
}