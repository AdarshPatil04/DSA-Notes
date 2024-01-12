/**
 * @brief This code demonstrates how to find all permutations of a given string using recursion.
 * 
 * The solve() function is a recursive function that finds all permutations of the given string.
 * It uses backtracking to restore the original string after each iteration.
 * 
 * The permutations() function initializes the necessary variables and calls the solve() function.
 * It returns a vector containing all the permutations of the input string.
 * 
 * The main() function demonstrates the usage of the permutations() function by finding and printing
 * all permutations of the string "abc".
 */

#include<bits/stdc++.h>
using namespace std;

// recursive function to find the permutations of the given string
void solve(string input, int index, vector<string> &answer)
{
    // base case
    // if the index is equal to the size of the string then we have reached the end of the string and we have to push the current string in the answer
    if (index >= input.size())
    {
        answer.push_back(input);
        return;
    }

    // recursive case
    // iterating over the string
    for (int i = index; i < input.size(); i++)
    {
        // swapping the current character with the first character
        swap(input[index], input[i]);

        // calling the recursive function
        solve(input, index + 1, answer);

        // backtracking because we have to restore the original string
        swap(input[index], input[i]);
    }
}

// function to return the permutations of the given string
vector<string> permutations(string input)
{
    // creating a vector to store the answer
    vector<string> answer;

    // creating a variable to store the index of the current character
    int index = 0;

    // calling the recursive function
    solve(input, index, answer);

    // returning the answer vector containing all the permutations
    return answer;
}

int main(){
    string input = "abc";
    cout << "The permutations of the given string are: ";
    vector<string> answer = permutations(input);

    // printing the answer
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return 0;
}