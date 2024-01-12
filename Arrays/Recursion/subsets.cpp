/**
 * @brief This program generates all possible subsets of a given array using recursion.
 *
 * The program defines a recursive function `solve` that finds the subsets of the given array.
 * It starts by excluding the current element and recursively calls itself with the next index.
 * Then, it includes the current element by pushing it into the output vector and recursively calls itself with the next index.
 * After each recursive call, it backtracks by removing the current element from the output vector.
 * When the index reaches the size of the array, it adds the current output to the answer vector.
 *
 * The `subsets` function initializes the answer and output vectors, and calls the `solve` function.
 * It returns the answer vector containing all the subsets.
 *
 * In the `main` function, a sample array is defined and the subsets are generated and printed.
 */

#include <bits/stdc++.h>
using namespace std;

// recursive function to find the subsets of the given array
void solve(vector<int> &nums, int index, vector<int> &output, vector<vector<int>> &answer)
{
    // base case
    // if the index is equal to the size of the array then we have reached the end of the array and we have to push the current output in the answer
    if (index >= nums.size())
    {
        answer.push_back(output);
        return;
    }

    // excluding the current element
    solve(nums, index + 1, output, answer);

    // including the current element
    // pushing the current element in the output
    int element = nums[index];
    output.push_back(element);
    solve(nums, index + 1, output, answer);

    // backtracking because we have to remove the current element from the output so that the previous state of output is maintained
    // before backtracking answer is already updated with the output since last include is called so base case is reached and the output is pushed in the answer and then backtracking is done
    output.pop_back();
}

// function to return the subsets of the given array
vector<vector<int>> subsets(vector<int> &nums)
{
    // creating a vector of vectors to store the answer
    vector<vector<int>> answer;

    // creating a vector to store the current subset
    vector<int> output;

    // creating a variable to store the index of the current element
    int index = 0;

    // calling the recursive function
    solve(nums, index, output, answer);

    // returning the answer containing all the subsets
    return answer;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    // Storing the answer in a vector of vectors
    vector<vector<int>> answer = subsets(nums);

    // printing the answer which is a jagged array
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}