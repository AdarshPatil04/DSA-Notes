/**
 *        The time complexity of the code is O(2^n) and the space complexity is O(n) due to the recursive call stack.
 * @brief This code calculates the number of unique binary search trees that can be formed using n nodes.
 *        It uses a recursive approach to solve the problem.
 */
#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(int n)
{
    // Base case: if n is less than or equal to 1, return 1
    if (n <= 1)
        return 1;

    int ans = 0;
    // Iterate from 1 to n, considering each number as the root node
    for (int i = 1; i <= n; i++)
    {
        // Update the answer with the sum of the current answer and
        // the product of the result of the recursive call for the left subarray and the right subarray
        ans += solveRec(i - 1) * solveRec(n - i);
    }
    // Return the answer
    return ans;
}

// Function to get the number of unique binary search trees
int numTrees(int n)
{
    // Call the recursive function to solve the problem
    return solveRec(n);
}

int main()
{
    // Define the number
    int n = 3;
    // Print the number of unique binary search trees
    cout << numTrees(n) << endl;
    return 0;
}
