// The time complexity of this solution is exponential, O(N^X), where N is the number of elements in the array and X is the target value.
// The space complexity is O(N), where N is the number of elements in the array.
// This code solves the problem of finding the minimum number of elements from a given array that sum up to a target value using recursion.
// It uses a recursive approach to calculate the minimum number of elements by considering all possible combinations of elements from the array.
// The code uses a recursive function 'solveRec' to solve the problem and a main function to test the solution.
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

// Main function
int main()
{
    // The array of numbers
    vector<int> num = {1, 2, 5};

    // The target sum
    int x = 11;

    // Print the minimum number of elements that sum to x
    cout << solveRec(num, x);

    return 0;
}
