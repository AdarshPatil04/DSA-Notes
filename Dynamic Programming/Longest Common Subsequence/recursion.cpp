/**
 * The time complexity of the algorithm is O(2^(n+m)), where n and m are the lengths of the input strings.
 * The space complexity is O(n+m) due to the recursive call stack.
 * This code calculates the length of the longest common subsequence between two strings using a recursive approach.
 * The function `longestCommonSubsequence` takes two strings as input and returns the length of the longest common subsequence.
 * The recursive function `solveRec` is used to solve the problem by comparing characters of the two strings and making recursive calls.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(string &text1, string &text2, int i, int j)
{
    // Get the lengths of text1 and text2
    int n = text1.length();
    int m = text2.length();
    // Base case: if i is equal to n or j is equal to m, return 0
    if (i >= n || j >= m)
        return 0;

    // If the characters at index i in text1 and index j in text2 are the same
    if (text1[i] == text2[j])
        // Return 1 plus the result of the recursive call for the next characters in text1 and text2
        return 1 + solveRec(text1, text2, i + 1, j + 1);
    else
        // Otherwise, return the maximum value between the results of the recursive calls for the next character in text1 and the same character in text2,
        // and for the same character in text1 and the next character in text2
        return max(solveRec(text1, text2, i, j + 1), solveRec(text1, text2, i + 1, j));
}

// Function to get the length of the longest common subsequence
int longestCommonSubsequence(string text1, string text2)
{
    // Call the recursive function to solve the problem
    // Start from the first characters in text1 and text2
    return solveRec(text1, text2, 0, 0);
}

int main()
{
    // Define the strings
    string text1 = "abcde";
    string text2 = "ace";
    // Print the length of the longest common subsequence
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}