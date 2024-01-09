/**
 * @brief This program checks if a given string is a palindrome or not using recursion.
 * 
 * The program defines a function checkPalindrome() that takes a string, starting index (i), and ending index (j) as parameters.
 * It recursively checks if the characters at the given indices are equal, starting from the outermost indices and moving towards the center.
 * If the characters are not equal at any point, the function returns false.
 * If the function reaches a point where the starting index is greater than the ending index, it means all characters have been checked and are equal, so it returns true.
 * 
 * The main function initializes a string and calls the checkPalindrome() function with the string, starting index 0, and ending index (length - 1).
 * It then prints '1' if the string is a palindrome, and '0' otherwise.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to check if a string is palindrome or not
bool checkPalindrome(string str, int i, int j)
{

    // base case
    // if i is greater than j then return true
    if (i > j)
    {
        return true;
    }

    // if the characters at i and j are not equal then return false
    if (str[i] != str[j])
    {
        return false;
    }

    // recursive case
    // call for the rest of the string
    return checkPalindrome(str, i + 1, j - 1);
}

int main()
{
    string str = "abba";

    // Printing '1' if the string is palindrome, else '0'
    cout << checkPalindrome(str, 0, str.length() - 1);
    return 0;
}