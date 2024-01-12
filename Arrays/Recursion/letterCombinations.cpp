/**
 * @brief This program generates all possible letter combinations for a given sequence of digits in a phone keypad using recursion.
 * 
 * The program takes a string of digits as input and recursively finds all possible letter combinations for the digits.
 * It uses a mapping array to map each digit to its corresponding letters. The recursive function iterates over the letters
 * for each digit and builds the combinations. The base case is reached when the index exceeds the size of the digits string,
 * and at that point, the current combination is added to the answer vector. The program then returns the answer vector
 * containing all the letter combinations.
 * 
 * @param digits The input string of digits.
 * @return vector<string> The vector containing all possible letter combinations for the given digits.
 */

#include <bits/stdc++.h>
using namespace std;

// recursive function to find the letter combinations of the given digits
void solve(string digits, int index, string output, vector<string> &answer, string mapping[])
{
    // base case
    if (index >= digits.size())
    {
        // Pushing the current output in the answer
        answer.push_back(output);
        return;
    }

    // recursive case
    // Finding the current number and the corresponding letters
    int number = digits[index] - '0';
    string letters = mapping[number];

    // Iterating over the letters
    for (int i = 0; i < letters.size(); i++)
    {
        // Pushing the current letter in the output
        output.push_back(letters[i]);

        // For the next index we have to call the recursive function and at last it reaches the base case with last index + 1
        solve(digits, index + 1, output, answer, mapping);

        // After reaching the base case we have to backtrack to the previous state of output
        output.pop_back();
    }
}

// function to return the letter combinations of the given digits
vector<string> letterCombinations(string digits)
{
    vector<string> answer;
    string output;
    int index = 0;

    // If the digits string is empty then we have to return the empty answer
    if (digits.size() == 0)
    {
        return answer;
    }

    // Mapping the numbers to the corresponding letters
    string mapping[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // Calling the recursive function
    solve(digits, index, output, answer, mapping);

    // Returning the answer as a vector of strings
    return answer;
}

int main()
{
    // Given input
    string digits = "23";

    // Storing the answer in a vector
    vector<string> answer = letterCombinations(digits);

    // Printing the answer
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return 0;
}