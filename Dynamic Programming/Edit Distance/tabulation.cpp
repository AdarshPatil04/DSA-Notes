// https://leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity => O(n*m)
// Space Complexity => O(n*m)
int solveTab(string &word1, string &word2)
{
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // after analyzing base case
    for (int j = 0; j <= m; j++)
        dp[n][j] = m - j;

    for (int i = 0; i <= n; i++)
        dp[i][m] = n - i;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if (word1[i] == word2[j])
            {
                ans = dp[i + 1][j + 1];
            }
            else
            {
                int insertAns = 1 + dp[i][j + 1];
                int deleteAns = 1 + dp[i + 1][j];
                int replaceAns = 1 + dp[i + 1][j + 1];
                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int minDistance(string word1, string word2)
{
    // Tabulation
    return solveTab(word1, word2);
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";
    cout << minDistance(word1, word2) << endl; // Expected output: 3
    return 0;
}