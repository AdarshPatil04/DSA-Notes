/**
 * //Time Complexity => O(n*m)
    //Space Complexity => O(m)
 * @brief This code calculates the minimum number of operations (insertions, deletions, and substitutions)
 * required to transform one word into another using dynamic programming with space optimization.
 * It uses the edit distance algorithm to determine the minimum number of operations needed.
 * The code implements the space optimization technique by using two vectors to represent the current and next rows of the dynamic programming table.
 * The algorithm iterates over the rows and columns of the table, considering the cost of different operations (insertion, deletion, and substitution)
 * and choosing the minimum cost at each step. The final result is the value in the top-left cell of the table, which represents the minimum number of operations required.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum number of operations (insertions, deletions, and substitutions)
// required to transform word1 into word2 using dynamic programming with space optimization
int solveSO(string &word1, string &word2)
{
    int n = word1.length();
    int m = word2.length();

    // Initialize two vectors curr and next for the current and next row of the dp table
    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);

    // Fill the last row of the dp table
    for (int j = 0; j <= m; j++)
        next[j] = m - j;

    // Iterate over the rows of the dp table from bottom to top
    for (int i = n - 1; i >= 0; i--)
    {
        // Fill the last column of the current row
        curr[m] = n - i;

        // Iterate over the columns of the dp table from right to left
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;

            // If the current characters of word1 and word2 match
            if (word1[i] == word2[j])
            {
                // The cost is the same as the cost for the next characters of word1 and word2
                ans = next[j + 1];
            }
            else
            {
                // If the current characters don't match, consider all three operations on word1[i]
                // Choose the minimum cost among these operations
                int insertAns = 1 + curr[j + 1];  // Insert
                int deleteAns = 1 + next[j];      // Delete
                int replaceAns = 1 + next[j + 1]; // Replace

                ans = min(insertAns, min(deleteAns, replaceAns));
            }

            // Store the answer to the current cell in the dp table
            curr[j] = ans;
        }

        // Move to the next row of the dp table
        next = curr;
    }

    // The answer is in the top-left cell of the dp table
    return next[0];
}

// Function to calculate the minimum number of operations required to convert word1 to word2
int minDistance(string word1, string word2)
{
    // Call the function with space optimization
    return solveSO(word1, word2);
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";

    // Print the minimum number of operations required to convert word1 to word2
    cout << minDistance(word1, word2) << endl; // Expected output: 3

    return 0;
}