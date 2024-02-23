/**
 * // Time Complexity => O(n*m)
    // Space Complexity => O(n*m)
 * This code implements the wildcard matching algorithm using recursive memoization.
 * Given a string 's' and a pattern 'p' containing wildcard characters '*', '?',
 * the code checks if the string 's' matches the pattern 'p'.
 * The algorithm uses dynamic programming to store the results of subproblems in a memoization table.
 * It recursively checks if the current characters of 's' and 'p' match, or if the current character of 'p' is a wildcard.
 * The memoization table is used to avoid redundant computations and improve the efficiency of the algorithm.
 * The code returns true if 's' matches 'p', and false otherwise.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if string 'str' matches with pattern 'pattern'
bool solveMem(string &str, string &pattern, int i, int j, vector<vector<int>> &dp)
{
    // If both strings are empty, return true
    if (i == 0 && j == 0)
        return true;

    // If 'str' is not empty and 'pattern' is, return false
    if (i > 0 && j == 0)
        return false;

    // If 'str' is empty and 'pattern' is not, check if all remaining characters in 'pattern' are '*'
    if (i == 0 && j > 0)
    {
        for (int k = 1; k <= j; k++)
        {
            if (pattern[k - 1] != '*')
                return false;
        }
        return true;
    }

    // If the subproblem has already been solved, return the stored answer
    if (dp[i][j] != -1)
        return dp[i][j];

    // If current characters of 'str' and 'pattern' match, or current character of 'pattern' is '?'
    if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
        return dp[i][j] = solveMem(str, pattern, i - 1, j - 1, dp);

    // If current character of 'pattern' is '*', consider all possibilities and return true if any possibility is true
    else if (pattern[j - 1] == '*')
        return dp[i][j] = (solveMem(str, pattern, i - 1, j, dp) || solveMem(str, pattern, i, j - 1, dp));

    // If none of the above conditions are met, return false
    else
        return false;
}

// Function to check if string 's' matches with pattern 'p'
bool isMatch(string s, string p)
{
    // Initialize a dp table with -1
    int n = s.length();
    int m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Call the memoized function
    return solveMem(s, p, n, m, dp);
}

int main()
{
    string s = "adceb";
    string p = "*a*b";

    // Print whether string 's' matches with pattern 'p'
    cout << isMatch(s, p) << endl; // Expected output: 1 (true)

    return 0;
}