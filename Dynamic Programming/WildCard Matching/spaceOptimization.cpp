/**
 * // Time Complexity => O(n*m)
    // Space Complexity => O(m)
 * @brief This code implements the wildcard matching problem using dynamic programming.
 *        It uses a space-optimized approach to solve the problem efficiently.
 *        The code checks whether a given string matches a given pattern, where the pattern can contain wildcard characters '?' and '*'.
 *        '?' matches any single character, while '*' matches any sequence of characters (including an empty sequence).
 *        The code returns true if the string matches the pattern, and false otherwise.
 *        The main function tests the code with example inputs.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the wildcard matching problem using dynamic programming
// This function uses a space optimized approach
bool solveSO(string &str, string &pattern)
{
    // Get the lengths of the string and the pattern
    int n = str.length();
    int m = pattern.length();

    // Initialize two vectors to store the results of subproblems
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    // The base case: an empty string matches with an empty pattern
    prev[0] = true;

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
        prev[j] = flag;
    }

    // For each character in the string and the pattern
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // If the characters match or the pattern has '?', the result is the same as the previous characters
            if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
                curr[j] = prev[j - 1];
            // If the pattern has '*', it can match with the current character or not
            else if (pattern[j - 1] == '*')
                curr[j] = (prev[j] || curr[j - 1]);
            // If the characters don't match and the pattern doesn't have '*' or '?', the string and the pattern don't match
            else
                curr[j] = false;
        }
        prev = curr; // Update the previous row
    }

    // The result is stored in prev[m]
    return prev[m];
}

// Function to check whether a string matches with a pattern
bool isMatch(string s, string p)
{
    // Call the function solveSO to check the match
    return solveSO(s, p);
}

int main()
{
    // Test the function with example inputs
    string s = "adceb";
    string p = "*a*b";
    cout << isMatch(s, p) << endl; // Expected output: 1 (true)

    return 0;
}