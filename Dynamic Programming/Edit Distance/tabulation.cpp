/**
 *  //Time Complexity => O(n*m)
    //Space Complexity => O(n*m)
 * @brief This code calculates the minimum edit distance between two strings using tabulation method.
 *
 * The minimum edit distance is the minimum number of operations (insertion, deletion, or replacement)
 * required to transform one string into another. The code uses a dynamic programming approach to fill
 * a 2D table with the minimum edit distances for all possible substrings of the two input strings.
 * The final result is the value stored in the top-left cell of the table.
 *
 * @param word1 The first input string
 * @param word2 The second input string
 * @return The minimum edit distance between the two input strings
 */
#include <bits/stdc++.h>
using namespace std;

// Function to calculate minimum edit distance between two strings
int solveTab(string &word1, string &word2)
{
    // Get the lengths of the two words
    int n = word1.length();
    int m = word2.length();

    // Initialize a 2D vector to store the minimum edit distances
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the last row and last column of the dp table
    // These represent the base case where one of the strings is empty
    for (int j = 0; j <= m; j++)
        dp[n][j] = m - j; // Distance is the remaining length of the other string

    for (int i = 0; i <= n; i++)
        dp[i][m] = n - i; // Distance is the remaining length of the other string

    // Start filling the dp table from bottom right corner
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if (word1[i] == word2[j])
            {
                // If the characters match, no operation is needed
                // So, the distance is same as for the remaining strings
                ans = dp[i + 1][j + 1];
            }
            else
            {
                // If the characters don't match, we consider three operations:
                // insert, delete, and replace
                int insertAns = 1 + dp[i][j + 1];      // Insert a character in word1
                int deleteAns = 1 + dp[i + 1][j];      // Delete a character from word1
                int replaceAns = 1 + dp[i + 1][j + 1]; // Replace a character in word1

                // The minimum distance is the minimum of the three operations
                ans = min(insertAns, min(deleteAns, replaceAns));
            }

            // Store the minimum distance in the dp table
            dp[i][j] = ans;
        }
    }

    // The minimum edit distance is stored in dp[0][0]
    return dp[0][0];
}

// Function to calculate minimum edit distance between two strings
int minDistance(string word1, string word2)
{
    // Call the function solveTab to calculate the minimum edit distance
    return solveTab(word1, word2);
}

int main()
{
    // Test the function with example inputs
    string word1 = "horse";
    string word2 = "ros";
    cout << minDistance(word1, word2) << endl; // Expected output: 3

    return 0;
}