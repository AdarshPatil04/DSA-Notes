/**
 * @brief This program demonstrates various string operations such as finding the length of a string,
 *        reversing a string, and checking if a word is a palindrome (case insensitive).
 *        It defines functions to convert a character to lowercase, check if a word is a palindrome,
 *        reverse a string, and find the length of a string.
 *        The main function uses these functions to perform the operations on a given string.
 */

#include <bits/stdc++.h>
using namespace std;

// This function converts a character to lowercase
char toLowerCase(char ch)
{

    // If the character is already lowercase, return the character
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }

    // Otherwise, return the lowercase of the character
    else
    {

        // Subtracting 'A' from the character gives index value and adding 'a' to it gives the lowercase of the character
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

// This function returns true if the word is a palindrome; otherwise, it returns false
bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1;

    // Traverse the word from both ends
    while (i < j)
    {

        // If the characters at the current indices are not equal, the word is not a palindrome
        if (toLowerCase(s[i]) != toLowerCase(s[j]))
        {
            return false;
        }

        // Increment i and decrement j
        i++;
        j--;
    }
    return true;
}

// This function reverses a string
string reverse(string s)
{
    int i = 0, j = s.length() - 1;

    // Traverse the string from both ends
    while (i < j)
    {

        // Swap the characters at the current indices
        swap(s[i++], s[j--]);
    }
    return s;
}

// This function returns the length of a string
int length(string s)
{
    int i = 0;

    // Traverse the string until the null character is encountered
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int main()
{
    string s = "Noon";

    // Printing the length of the string
    cout << "The length of the string is: " << length(s) << endl;

    // Printing the reverse of the string
    cout << "The reversed string is: " << reverse(s) << endl;

    // Printing whether the word is a palindrome or not
    cout << "Whether the string is palindrome or not ( not case sensitive): " << isPalindrome(s) << endl;

    return 0;
}