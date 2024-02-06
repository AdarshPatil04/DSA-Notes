/**
 * This code finds the longest common prefix among a given array of strings.
 * It uses the approach of comparing characters of the first string with the rest of the strings.
 * If a character doesn't match or the string size is less than the current index, it breaks the loop.
 * The code has a time complexity of O(M*N), where N is the number of strings and M is the length of the string.
 * The space complexity is O(1), but when considering the length of the answer string, it becomes O(M).
 */

// https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383
// Approach-1 : Without Trie
// Time Complexity = O(M*N) where 'N' is the no. of strings and 'M' is the length of the string
// Space Complexity = O(1) but when ans length included then it became O(M) where M is the length of the ans string

// Include necessary libraries
#include <bits/stdc++.h>
using namespace std;

// Function to find the longest common prefix
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = ""; // Initialize the answer as an empty string

    // Traverse all the characters of the first string
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i]; // Get the current character

        bool match = true; // Initialize match as true

        // Compare the current character with the rest of the strings
        for (int j = 1; j < n; j++)
        {
            // If the character does not match or the string size is less than i
            if (ch != arr[j][i] || arr[j].size() < i)
            {
                match = false; // Set match as false
                break;         // Break the loop
            }
        }

        // If match is false, break the loop
        if (match == false)
            break;
        else
            ans.push_back(ch); // Otherwise, add the character to the answer
    }
    return ans; // Return the answer
}

// Main function
int main()
{
    vector<string> arr = {"flower", "flow", "flight"}; // Initialize the array of strings
    int n = arr.size();                                // Get the size of the array
    cout << longestCommonPrefix(arr, n) << endl;       // Print the longest common prefix
    return 0;                                          // End the program
}
