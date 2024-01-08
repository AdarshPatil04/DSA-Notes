
/**
 * This code removes all adjacent duplicates from a given string.
 * It uses a stack to store the characters and checks if the top of the stack is equal to the current character.
 * If they are equal, it pops the top of the stack. Otherwise, it pushes the current character onto the stack.
 * Finally, it reverses the characters in the stack and returns the resulting string.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to remove all adjacent duplicates from a string
string removeAdjacentDuplicates(string s)
{

    // Using stack to store the characters
    stack<char> st;
    string ans;

    // Traversing the string
    for (int i = 0; i < s.length(); i++)
    {

        // If stack is empty, push the character
        if (st.empty())
        {
            st.push(s[i]);
        }

        // If stack is not empty
        else
        {

            // If top of stack is equal to current character, pop the top
            if (st.top() == s[i])
            {
                st.pop();
            }

            // Else push the current character
            else
            {
                st.push(s[i]);
            }
        }
    }

    // Storing the characters in the string
    while (st.empty() == false)
    {
        ans.push_back(st.top());
        st.pop();
    }

    // Reversing the string. Since we are storing the characters in the stack in reverse order (i.e) ac --> ca (so we need to reverse it)
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "abbaca";

    // Printing the string after removing adjacent duplicates
    cout << removeAdjacentDuplicates(s);
    return 0;
}