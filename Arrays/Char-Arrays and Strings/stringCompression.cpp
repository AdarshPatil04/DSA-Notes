/**
 * @brief This program compresses a given string by replacing consecutive repeated characters with the character followed by the count of its occurrences.
 *
 * The stringCompression function takes a vector of characters as input and compresses the string in-place. It iterates through the string, counting the number of times each character occurs consecutively. If a character occurs more than once, it replaces the consecutive occurrences with the character followed by the count. The compressed string is then returned as a vector of characters.
 *
 * The main function demonstrates the usage of the stringCompression function by compressing a sample string and printing the compressed string.
 */

#include <bits/stdc++.h>
using namespace std;

// This function compresses the given string
vector<char> stringCompression(vector<char> &chars)
{

    // ansIndex is the index of the current character in the compressed string vector
    int ansIndex = 0;
    int n = chars.size();
    int i = 0;
    while (i < n)
    {

        // j is the index of the next character in the string that is not equal to the current character
        int j = i + 1;

        // Counting the number of times the current character occurs in the string
        while (j < n && chars[j] == chars[i])
        {
            j++;
        }

        // Adding the current character to the compressed string vector
        chars[ansIndex++] = chars[i];

        // Storing the count of the current character in the form of digits, Eg: "caaabb" count for a --> j=4, i=1, count=3
        int count = j - i;

        // If the count is greater than 1, we need to add the count to the compressed string vector
        if (count > 1)
        {

            // Converting the count to a string
            string s = to_string(count);

            // Adding each digit of the count to the compressed string vector
            for (int k = 0; k < s.length(); k++)
            {
                chars[ansIndex++] = s[k];
            }
        }

        // Updating i to the index of the next character in the string that is not equal to the current character
        i = j;
    }

    // Returning the compressed string vector
    return chars;
}

int main()
{
    vector<char> chars = {'a', 'b', 'b', 'c', 'c', 'c'};

    // Calling the stringCompression function
    vector<char> res = stringCompression(chars);

    // Making a string from the compressed string vector
    string res_str(res.begin(), res.end());

    // Printing the compressed string
    cout << "The compressed string is: " << res_str << endl;
    return 0;
}