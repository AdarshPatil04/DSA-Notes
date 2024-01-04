/**
 * This program checks if a given string s1 is a permuted substring of another string s2.
 * It uses a sliding window technique to compare the frequency of characters in s1 and the current window of s2.
 * If the frequency of characters in s1 matches the frequency in the current window of s2, it returns true.
 * Otherwise, it continues sliding the window until the end of s2 is reached.
 * If no matching substring is found, it returns false.
 */

#include <bits/stdc++.h>
using namespace std;

// This function checks if the frequency of characters in two strings is equal
bool checkEqual(int count1[26], int count2[26])
{

    for (int i = 0; i < 26; i++)
    {

        // If the frequency of any character is not equal, return false
        if (count1[i] != count2[i])
        {
            return false;
        }
    }
    return true;
}

// This function checks if s1 is a permuted substring of s2
bool permutationInString(string s1, string s2)
{
    int count1[26] = {0};

    // count1 stores the frequency of characters in s1 (The string to be searched for)
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};

    // Running for the first window
    while (i < windowSize && i < s2.length())
    {
        int index = s2[i] - 'a';

        // count2 stores the frequency of characters in the first window of s2
        count2[index]++;
        i++;
    }

    // Checking if the frequency of characters in the first window is equal to that of s1
    if (checkEqual(count1, count2))
    {
        return true;
    }

    // Sliding the window
    while (i < s2.length())
    {

        // Adding the current character to the window
        int newChar = s2[i];
        int index = newChar - 'a';

        // count2 stores the frequency of characters in the current window of s2
        count2[index]++;

        // Removing the first character of the previous window from the current window
        int oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;

        // Checking if the frequency of characters in the current window is equal to that of s1 every time
        if (checkEqual(count1, count2))
        {
            return true;
        }

        i++;
    }
    return false;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";

    // Printing 1 if s1 is a permuted substring of s2, else 0
    cout << permutationInString(s1, s2);
    return 0;
}