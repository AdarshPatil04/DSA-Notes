/**
 * @brief This program calculates the number of unique binary search trees using the Catalan number formula.
 *
 * The program defines a function `catalanNum` to calculate the nth Catalan number using a loop.
 * It then defines a function `numTrees` that calls the `catalanNum` function to get the number of unique binary search trees.
 * In the main function, it sets the value of `n` to 3 and prints the number of unique binary search trees.
 *
 * @return 0 on successful execution
 */

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the nth Catalan number
long long int catalanNum(long long int n)
{
    // Base case: if n is less than or equal to 1, return 1
    if (n <= 1)
        return 1;

    // Initialize the answer
    long long int ans = 1;
    // Iterate from 1 to n
    for (long long int i = 1; i <= n; i++)
    {
        // Update the answer with the product of the current answer and 2*(2*i-1) divided by (i+1)
        ans = ans * (2 * (2 * i - 1)) / (i + 1);
    }
    // Return the answer
    return ans;
}

// Function to get the number of unique binary search trees
int numTrees(int n)
{
    // Call the function to calculate the nth Catalan number
    return catalanNum(n);
}

int main()
{
    // Define the number
    int n = 3;
    // Print the number of unique binary search trees
    cout << numTrees(n) << endl;
    return 0;
}
