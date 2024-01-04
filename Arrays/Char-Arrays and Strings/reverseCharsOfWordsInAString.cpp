/**
 * This program takes a string as input and reverses the characters of words in the string.
 * It uses the 'reverse' function to reverse individual words in the string.
 * The 'reverseWords' function iterates through the string, identifies words separated by spaces,
 * and reverses each word using the 'reverse' function.
 * The reverseWords function in this code is done using inplace modification of the input string.
 * Finally, it returns the string with reversed words.
 */

#include <bits/stdc++.h>
using namespace std;

// This function reverses a word
string reverse(string s)
{
    int i = 0, j = s.length() - 1;

    // Traverse the word from both ends
    while (i < j)
    {

        // Swap the characters at the current indices
        swap(s[i++], s[j--]);
    }
    return s;
}

// This function reverses the words in a string
string reverseWords(string s)
{
    int i = 0, j = 0;

    // Traverse the string
    while (j < s.length())
    {

        // If the current character is a space, reverse the word
        if (s[j] == ' ')
        {

            /* substr(0, i) returns the substring of s starting from index 0 and of length i (i.e. the word before the space
            substr(i, j-i) returns the substring of s starting from index i and of length j-i and then reverse it
            substr(j, s.length()-j) returns the substring of s starting from index j and of length s.length()-j which are the words till the end of the string */
            s = s.substr(0, i) + reverse(s.substr(i, j - i)) + s.substr(j, s.length() - j);
            i = j + 1;
        }
        j++;
    }

    // Reverse the last word and incase there are some spaces/other characters at the end of the string also add it to the result
    s = s.substr(0, i) + reverse(s.substr(i, j - i)) + s.substr(j, s.length() - j);
    return s;
}

int main()
{
    string s = "the sky is blue";

    cout << reverseWords(s) << endl;
    return 0;
}