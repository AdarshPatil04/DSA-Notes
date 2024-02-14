/**
 * The time complexity of this solution is exponential.
 * This code solves the "Ninja and the Fence" problem using a recursive approach.
 * The problem is to count the number of ways to paint 'n' fences using 'k' colors,
 * such that no two adjacent fences have the same color.
 * The code defines two helper functions, 'add' and 'mul', to perform addition and multiplication
 * with modulo operation. The recursive function 'solveRec' calculates the number of ways
 * to paint the fences by considering different cases. The main function calls 'numberOfWays'
 * to print the result.
 */
// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208

#include <bits/stdc++.h>
using namespace std;

// Defining MOD value for the problem
#define MOD 1000000007

// Function to add two numbers with modulo operation
int add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

// Function to multiply two numbers with modulo operation
int mul(int a, int b)
{
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

// Recursive function to solve the problem
int solveRec(int n, int k)
{
    // Base case: If there is only one fence, there are 'k' ways to paint it
    if (n == 1)
        return k;

    // Base case: If there are two fences, the number of ways is 'k' plus 'k' times 'k-1'
    if (n == 2)
        return add(k, mul(k, (k - 1)));

    // Recursive case: The number of ways is the sum of 'k-1' times the number of ways for 'n-1' and 'n-2' fences
    int ans = add(mul(solveRec(n - 2, k), (k - 1)), mul(solveRec(n - 1, k), (k - 1)));

    // Return the calculated value
    return ans;
}

// Function to count the number of ways to paint the fences
int numberOfWays(int n, int k)
{
    // Call the recursive function
    return solveRec(n, k);
}

int main()
{
    // Number of fences and colors
    int n = 3, k = 2;

    // Print the number of ways to paint the fences
    cout << numberOfWays(n, k);

    // Return 0 to indicate normal termination of the program
    return 0;
}
