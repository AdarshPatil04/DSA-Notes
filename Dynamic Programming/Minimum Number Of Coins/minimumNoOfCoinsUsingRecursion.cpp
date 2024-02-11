/**
// The time complexity of this solution is exponential, O(N^X), where N is the number of elements in the array and X is the target value.
// The space complexity is O(N), where N is the number of elements in the array.
 * This code implements a recursive solution to find the minimum number of elements from a given array
 * that sum up to a target value. The code uses a brute-force approach, iterating over all possible
 * combinations of elements to find the minimum number of elements required. The time complexity of
 * this solution is exponential, making it inefficient for large inputs. The space complexity is linear,
 * as it uses recursion to solve subproblems. If the target value cannot be achieved using the given
 * array elements, the code returns -1.
 */
// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
// This function has a high time complexity due to repeated calculations
int solveRec(vector<int> &num, int x)
{
    // Base case: If x is 0, the minimum number of elements is 0
    if (x == 0)
        return 0;

    // Base case: If x is less than 0, return a large number (infinity)
    if (x < 0)
        return INT_MAX;

    // Initialize the minimum number of elements as a large number (infinity)
    int mini = INT_MAX;

    // Iterate over each element in the array
    for (int i = 0; i < num.size(); i++)
    {
        // Recursively solve the subproblem for x - num[i]
        int ans = solveRec(num, x - num[i]);

        // If the subproblem can be solved, update the minimum number of elements
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }

    // Return the minimum number of elements
    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    // Call the recursive function to solve the problem
    int result = solveRec(num, x);

    // If the result is INT_MAX, it means the problem cannot be solved
    // Return -1 in this case
    if (result == INT_MAX)
    {
        return -1;
    }
    else
    {
        // Otherwise, return the result
        return result;
    }
}

int main()
{
    // Define the array of numbers
    vector<int> num = {1, 2, 3};

    // Define the target value
    int x = 5;

    // Call the function to find the minimum number of elements
    // Print the result
    cout << minimumElements(num, x);

    return 0;
}
