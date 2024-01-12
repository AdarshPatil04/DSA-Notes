/**
 * @brief This program generates all possible subsequences of a given string using recursion.
 * 
 * The program defines a recursive function `solve` that takes the input string, an index, an output string, and a vector to store the subsequences.
 * The base case of the recursion is when the index is equal to the size of the input string, indicating that we have reached the end of the string.
 * In each recursive call, the function excludes the current character and makes a recursive call with the next index.
 * Then, it includes the current character, adds it to the output string, and makes another recursive call with the next index.
 * After each recursive call, the function backtracks by removing the current character from the output string to maintain the previous state.
 * The function stores the valid subsequences in the answer vector.
 * 
 * The `subsequences` function initializes the necessary variables and calls the `solve` function to generate the subsequences.
 * It returns the answer vector containing all the subsequences.
 * 
 * The main function demonstrates the usage of the `subsequences` function by generating subsequences for the input string "abc" and printing them.
 * 
 * Time Complexity: O(2^n), where n is the length of the input string.
 */

#include <bits/stdc++.h>
using namespace std;

// recursive function to find the subsequences of the given string
void solve(string input, int index, string output, vector<string> &answer)
{
    // base case
    // if the index is equal to the size of the string then we have reached the end of the string and we have to push the current output in the answer
    if (index >= input.size())
    {

        // Empty string should not be included in the answer
        if (output != "")
        {
            answer.push_back(output);
        }
        return;
    }

    // excluding the current character
    solve(input, index + 1, output, answer);

    // including the current character
    // pushing the current character in the output
    char character = input[index];
    output.push_back(character);
    solve(input, index + 1, output, answer);

    // backtracking because we have to remove the current character from the output so that the previous state of output is maintained
    // before backtracking answer is already updated with the output since last include is called so base case is reached and the output is pushed in the answer and then backtracking is done
    output.pop_back();
}

// function to return the subsequences of the given string
vector<string> subsequences(string input)
{
    // creating a vector to store the answer
    vector<string> answer;

    // creating a string to store the current subsequence
    string output;

    // creating a variable to store the index of the current character
    int index = 0;

    // calling the recursive function
    solve(input, index, output, answer);

    // returning the answer containing all the subsequences
    return answer;
}

int main()
{
    string input = "abc";

    // Storing the answer in a vector
    vector<string> answer = subsequences(input);

    // printing the answer which is a jagged array
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}

// Time Complexity: O(2^n)