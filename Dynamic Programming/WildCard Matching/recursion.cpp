/**
 * // Time Complexity => O(2^(n+m))
    // Space Complexity => O(n+m) -> recursive call stack
 * @brief This code implements a recursive function to check if a given string 's' matches a pattern 'p' using wildcard characters.
 *
 * The function `solveRec` recursively checks if the characters of 's' and 'p' match according to the following rules:
 * - '?' matches any single character.
 * - '*' matches any sequence of characters (including an empty sequence).
 *
 * The function `isMatch` calls the recursive function `solveRec` and returns true if the string 's' matches the pattern 'p', and false otherwise.
 *
 * The main function demonstrates the usage of the `isMatch` function by checking if the string 'adceb' matches the pattern '*a*b'.
 *
 * @param s The input string to be matched.
 * @param p The pattern string to match against.
 * @return true if the string 's' matches the pattern 'p', false otherwise.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if string 's' matches with pattern 'p'
bool solveRec(string &s, string &p, int i, int j)
{
    // If both strings are empty, return true
    if (i < 0 && j < 0)
        return true;

    // If 's' is empty and 'p' is not, return false
    if (i >= 0 && j < 0)
        return false;

    // If 's' is not empty and 'p' is, check if all remaining characters in 'p' are '*'
    if (i < 0 && j >= 0)
    {
        for (int i = 0; i <= j; i++)
        {
            if (p[i] != '*')
                return false;
        }
        return true;
    }

    // If current characters of 's' and 'p' match, or current character of 'p' is '?'
    if (s[i] == p[j] || p[j] == '?')
        return solveRec(s, p, i - 1, j - 1);

    // If current character of 'p' is '*', consider all possibilities and return true if any possibility is true
    else if (p[j] == '*')
        return (solveRec(s, p, i, j - 1) || solveRec(s, p, i - 1, j));

    // If none of the above conditions are met, return false
    else
        return false;
}

// Function to check if string 's' matches with pattern 'p'
bool isMatch(string s, string p)
{
    // Call the recursive function
    int n = s.length() - 1;
    int m = p.length() - 1;
    return solveRec(s, p, n, m);
}

int main()
{
    string s = "adceb";
    string p = "*a*b";

    // Print whether string 's' matches with pattern 'p'
    cout << isMatch(s, p) << endl; // Expected output: 1 (true)

    return 0;
}