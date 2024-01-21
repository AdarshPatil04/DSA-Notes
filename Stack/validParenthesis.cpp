/**
 * @brief This program checks if a given string contains valid parenthesis.
 *        It uses a stack to keep track of opening brackets and matches them with closing brackets.
 *        If the string contains valid parenthesis, it prints "Valid", otherwise it prints "Invalid".
 *
 * @param expression The string to be checked for valid parenthesis.
 * @return true if the string contains valid parenthesis, false otherwise.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to check if a string contains valid parenthesis
bool isValidParenthesis(string expression)
{
    stack<char> st; // Create a stack of characters
    // Loop over the expression
    for (int i = 0; i < expression.length(); i++)
    {
        // If the current character is an opening bracket, push it into the stack
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            st.push(expression[i]); // Push the current character into the stack
        }
        // If the current character is a closing bracket
        else
        {
            // If the stack is not empty
            if (!st.empty())
            {
                // If the current character is a closing bracket and the top of the stack is the corresponding opening bracket, pop the top of the stack
                if (expression[i] == ')' && st.top() == '(' || expression[i] == '}' && st.top() == '{' || expression[i] == ']' && st.top() == '[')
                {
                    st.pop(); // Pop the top of the stack
                }
                // If the current character is a closing bracket and the top of the stack is not the corresponding opening bracket, return false
                else
                {
                    return false; // Return false
                }
            }
            // If the stack is empty, return false
            else
            {
                return false; // Return false
            }
        }
    }
    // If the stack is empty, return true
    if (st.empty())
    {
        return true; // Return true
    }
    // If the stack is not empty, return false
    else
    {
        return false; // Return false
    }
}

int main()
{
    string expression = "{([])}";
    cout << expression << endl;
    if (isValidParenthesis(expression))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
    return 0;
}