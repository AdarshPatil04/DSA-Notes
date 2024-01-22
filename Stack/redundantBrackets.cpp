/**
 * Time Complexity: O(n)
 * Space Complexity: O(n) because of the stack
 * @brief This program checks if a given string contains redundant brackets.
 * 
 * The program uses a stack to process the string character by character.
 * It pushes opening brackets and operators onto the stack, and when it encounters a closing bracket,
 * it pops elements from the stack until it finds an opening bracket.
 * If there are no operators between the opening and closing brackets, it considers the brackets as redundant.
 * The program returns true if redundant brackets are found, and false otherwise.
 * 
 * @param s The input string to check for redundant brackets.
 * @return true if redundant brackets are found, false otherwise.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to check if the given string contains redundant brackets
bool findRedundantBrackets(string &s)
{
    stack<char> st; // Create a stack of characters
    // Traverse the given string
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i]; // Store the current character in ch
        // If the current character is an opening bracket or an operator
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch); // Push the current character into the stack
        }
        // If the current character is a closing bracket
        else
        {
            // If the topmost element of the stack is an opening bracket
            if (ch == ')')
            {
                bool isRedundant = true; // Initialize a boolean variable isRedundant to true
                // Pop the topmost element of the stack until an opening bracket is encountered
                while (st.top() != '(')
                {
                    char top = st.top(); // Store the topmost element of the stack in top
                    // If the topmost element of the stack is an operator
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false; // Set isRedundant to false
                    }
                    st.pop(); // Pop the topmost element of the stack
                }
                // If isRedundant is true
                if (isRedundant == true)
                    return true; // Return true
                st.pop(); // Pop the opening bracket
            }
        }
    }
    return false; // Return false
}

int main()
{
    string s = "((a+b))";
    if (findRedundantBrackets(s))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}