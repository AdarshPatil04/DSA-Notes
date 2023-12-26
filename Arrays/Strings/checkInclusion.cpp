/**
 * @brief This program checks if a given string s1 is a permuted substring of another string s2.
 * 
 * The program uses a sliding window approach to check if the frequency of characters in s1 is equal to the frequency of characters in any substring of s2.
 * If the frequencies match, it returns true, indicating that s1 is a permuted substring of s2. Otherwise, it returns false.
 * 
 * @param s1 The string to be searched for as a permuted substring.
 * @param s2 The string in which the permuted substring is to be searched.
 * @return true if s1 is a permuted substring of s2, false otherwise.
 */

#include <bits/stdc++.h>
using namespace std;

// This function checks if the frequency of characters in two strings is equal
bool checkEqual(vector<int> count1, vector<int> count2)
{
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }
    return true;
}

// This function checks if s1 is a permuted substring of s2
bool checkInclusion(string s1, string s2)
{
    int windowSize = s1.length(), n2 = s2.length();

    vector<int> count1(26, 0), count2(26, 0);

    // count1 stores the frequency of characters in s1(The string to be searched for)
    for (int i = 0; i < windowSize; i++)
    {
        count1[s1[i] - 'a']++;
    }

    // First window of size windowSize in s2 and the condition that the window size is less than the length of s2
    for (int i = 0; i < windowSize && i < n2; i++)
    {
        count2[s2[i] - 'a']++;
    }

    // Checking if the frequency of characters in the first window is equal to that of s1
    if (checkEqual(count1, count2))
    {
        return true;
    }

    // Sliding the window
    for (int i = windowSize; i < n2; i++)
    {

        // Adding the current character to the window
        count2[s2[i] - 'a']++;

        // Removing the first character of the previous window from the current window
        count2[s2[i - windowSize] - 'a']--;

        // Checking if the frequency of characters in the current window is equal to that of s1 every time
        if (checkEqual(count1, count2))
        {
            return true;
        }
    }

    // If s1 is not a permuted substring of s2
    return false;
}

int main()
{
    string s1 = "ab", s2 = "eidbaooo";

    // Prints 1 if s1 is a permuted substring of s2 ,0 otherwise if s1 is not a permuted substring of s2
    cout << checkInclusion(s1, s2);
    return 0;
}