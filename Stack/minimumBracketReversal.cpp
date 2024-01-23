/**
 * @brief This program calculates the minimum number of operations required to make a given string balanced.
 *        A string is considered balanced if it can be formed by pairing opening and closing brackets in a valid manner.
 *        The program uses a stack to identify and remove invalid expressions from the string.
 *        It then counts the remaining unpaired opening and closing brackets to calculate the minimum operations required.
 *        If the string length is odd, it is not possible to make it balanced and -1 is returned.
 * 
 * @param str The input string to be checked for balance.
 * @return int The minimum number of operations required to make the string balanced, or -1 if not possible.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to find minimum number of operations required to make the string balanced
int findMinimumOperations(string str)
{

    // odd condition
    if (str.length() % 2 == 1)
    {
        return -1; // not possible
    }
    stack<char> s; // stack to store invalid expression
    // traverse the string
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i]; // store the current character in ch
        // if ch is open brace
        if (ch == '{')
        {
            s.push(ch); // push ch into the stack
        }
        else
        {
            // ch is closed brace then check if stack is empty or top of stack is open brace then pop the top of stack because it is valid
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            // Otherwise store the ch into the stack because it is invalid
            else
            {
                s.push(ch);
            }
        }
    }

    // stack containing invalid expression
    int a = 0, b = 0; // count of open and closed braces
    // traverse the stack
    while (!s.empty())
    {
        // if top of stack is open brace then increment b otherwise increment a
        if (s.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop(); // pop the top of stack
    }

    // Logic to calculate minimum operations
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans; // return ans
}

int main()
{
    string str;
    cin >> str;
    // Prints the minimum number of operations required to make the string balanced or -1 if not possible
    cout << findMinimumOperations(str);
}