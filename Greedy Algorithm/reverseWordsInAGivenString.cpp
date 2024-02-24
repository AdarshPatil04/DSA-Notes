// Time Complexity: O(n)
// Space Complexity: O(1)
// This code takes a string as input and reverses the order of the words in the string.
// It uses a temporary string to hold each word and an answer string to hold the final reversed string.
// The code iterates over the input string from end to start, identifying words based on the dot separator.
// Each word is reversed and added to the answer string, along with a dot separator.
// Finally, the last word is reversed and added to the answer string.
// The reversed string is then returned as the output.
// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

#include <bits/stdc++.h>
using namespace std;

// Function to reverse words in a given string.
string reverseWords(string S)
{
    // Initialize temporary string to hold each word
    string temp = "";
    // Initialize answer string to hold the final reversed string
    string ans = "";

    // Iterate over the string from end to start
    for (int i = S.length() - 1; i >= 0; i--)
    {
        // If the current character is a dot
        if (S[i] == '.')
        {
            // Reverse the temporary string
            reverse(temp.begin(), temp.end());
            // Add the reversed word to the answer string
            ans = ans + temp;
            // Add a dot to the answer string
            ans.push_back('.');
            // Clear the temporary string
            temp = "";
        }
        else
        {
            // If the current character is not a dot, add it to the temporary string
            temp.push_back(S[i]);
        }
    }

    // Reverse the last word
    reverse(temp.begin(), temp.end());
    // Add the last word to the answer string
    ans = ans + temp;
    // Return the reversed string
    return ans;
}

int main()
{
    // Given string
    string S = "i.like.this.program.very.much";
    // Call the function to reverse the words in the string
    cout << reverseWords(S);
    return 0;
}
