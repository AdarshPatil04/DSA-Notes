/**
 * This code calculates the minimum number of operations (insertions, deletions, and substitutions)
 * required to transform one word into another using memoization technique.
 * The code uses a recursive approach with memoization to solve the problem efficiently.
 * It defines a function `minDistance` that takes two strings as input and returns the minimum number of operations required to convert the first string to the second string.
 * The code also includes a helper function `solveMem` that performs the recursive calculation and stores the results in a memoization table.
 * The main function demonstrates the usage of the `minDistance` function by providing sample input and printing the expected output.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum number of operations (insertions, deletions, and substitutions)
// required to transform word1[i..n] into word2[j..m] using memoization
int solveMem(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
{
    int n = word1.length();
    int m = word2.length();

    // If word1 is empty, the answer is the remaining length of word2
    if (i == n)
        return (m - j);

    // If word2 is empty, the answer is the remaining length of word1
    if (j == m)
        return (n - i);

    // If the subproblem has already been solved, return the stored answer
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    // If the current characters of word1 and word2 match
    if (word1[i] == word2[j])
    {
        // Recurse for the remaining strings in word1 and word2
        ans = solveMem(word1, word2, i + 1, j + 1, dp);
    }
    else
    {
        // If the current characters don't match, consider all three operations on word1[i]
        // Choose the minimum cost among these operations
        int insertAns = 1 + solveMem(word1, word2, i, j + 1, dp);      // Insert
        int deleteAns = 1 + solveMem(word1, word2, i + 1, j, dp);      // Delete
        int replaceAns = 1 + solveMem(word1, word2, i + 1, j + 1, dp); // Replace

        ans = min(insertAns, min(deleteAns, replaceAns));
    }

    // Store the answer to the current subproblem in dp table
    return dp[i][j] = ans;
}

// Function to calculate the minimum number of operations required to convert word1 to word2
int minDistance(string word1, string word2)
{
    // Initialize a dp table with -1
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));

    // Call the memoized function
    return solveMem(word1, word2, 0, 0, dp);
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";

    // Print the minimum number of operations required to convert word1 to word2
    cout << minDistance(word1, word2) << endl; // Expected output: 3

    return 0;
}