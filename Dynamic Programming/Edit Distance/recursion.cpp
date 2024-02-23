/**
 * @brief This code calculates the minimum number of operations (insertions, deletions, and substitutions)
 * required to transform one word into another using recursion.
 *
 * The code uses a recursive approach to solve the edit distance problem, where the edit distance between two words
 * is defined as the minimum number of operations required to transform one word into another.
 * The operations allowed are insertions, deletions, and substitutions of characters.
 *
 * The main function `minDistance` takes two input strings `word1` and `word2` and returns the minimum number of operations
 * required to convert `word1` to `word2`.
 *
 * The recursive function `solveRec` is called by `minDistance` and calculates the minimum number of operations required
 * to transform `word1[i..n]` into `word2[j..m]`, where `i` and `j` are the current indices of `word1` and `word2` respectively.
 *
 * Example usage:
 * string word1 = "horse";
 * string word2 = "ros";
 * cout << minDistance(word1, word2) << endl; // Expected output: 3
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the minimum number of operations (insertions, deletions, and substitutions)
// required to transform word1[i..n] into word2[j..m]
int solveRec(string &word1, string &word2, int i, int j)
{
    int n = word1.length();
    int m = word2.length();

    // If word1 is empty, the answer is the remaining length of word2
    if (i == n)
        return (m - j);

    // If word2 is empty, the answer is the remaining length of word1
    if (j == m)
        return (n - i);

    int ans = 0;

    // If the current characters of word1 and word2 match
    if (word1[i] == word2[j])
    {
        // Recurse for the remaining strings in word1 and word2
        ans = solveRec(word1, word2, i + 1, j + 1);
    }
    else
    {
        // If the current characters don't match, consider all three operations on word1[i]
        // Choose the minimum cost among these operations
        int insertAns = 1 + solveRec(word1, word2, i, j + 1);      // Insert
        int deleteAns = 1 + solveRec(word1, word2, i + 1, j);      // Delete
        int replaceAns = 1 + solveRec(word1, word2, i + 1, j + 1); // Replace

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return ans;
}

// Function to calculate the minimum number of operations required to convert word1 to word2
int minDistance(string word1, string word2)
{
    // Call the recursive function
    return solveRec(word1, word2, 0, 0);
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";

    // Print the minimum number of operations required to convert word1 to word2
    cout << minDistance(word1, word2) << endl; // Expected output: 3

    return 0;
}