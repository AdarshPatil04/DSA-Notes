/**
 * @brief This program checks whether a given string is a palindrome without considering extra characters and case sensitivity.
 * 
 * The program defines several helper functions:
 * - `isValid(char ch)`: Checks whether a character is an alphabet or a digit.
 * - `toLowerCase(char ch)`: Converts a character to lowercase.
 * - `palindrome(string s)`: Checks whether a word is a palindrome.
 * - `isPalindrome(string s)`: Checks whether a given string is a palindrome without extra characters and case sensitivity.
 * 
 * The main function initializes a string `s` with a sentence and calls `isPalindrome(s)` to check if it is a palindrome.
 * The result is printed as 1 if the string is a palindrome and 0 otherwise.
 */

#include <bits/stdc++.h>
using namespace std;

// This function checks whether the character is an alphabet or a digit
bool isValid(char ch)
{

    // If the character is an alphabet or a digit, return true; otherwise, return false
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}

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

        // Subtracting 'A' from the character gives ascii value and adding 'a' to it gives the lowercase of the character
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

// This function returns true if the word is a palindrome; otherwise, it returns false
bool palindrome(string s)
{
    int i = 0, j = s.length() - 1;

    // Traverse the word from both ends
    while (i < j)
    {

        // If the characters at the current indices are not equal, the word is not a palindrome
        if (s[i] != s[j])
        {
            return false;
        }

        // Increment i and decrement j
        i++;
        j--;
    }
    return true;
}

// This function checks whether the given string is a palindrome or not
bool isPalindrome(string s){

    // Removes all the invalid characters from the string
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {

        // If the character is an alphabet or a digit, add it to the string
        if (isValid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }

    // Convert the string to lowercase
    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = toLowerCase(temp[i]);
    }
    
    // To check whether "amanaplanacanalpanama" is a palindrome or not
    return palindrome(temp);

}

int main()
{
    string s = "A man, a plan, a canal: Panama";

    // Print 1 if the string is a palindrome without the extra characters (case insensitive); otherwise, print 0
    cout<<"Whether the string is a palindrome without the extra characters (case insensitive): "<<isPalindrome(s);
    return 0;
}