/**
 * Calculates the factorial of a given number using recursion.
 *
 * @param n The number for which factorial is to be calculated.
 * @return The factorial of the given number.
 */

#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{

    // base case
    if (n == 0)
    {
        return 1;
    }

    // recursive case
    return n * factorial(n - 1);
}

int main()
{
    int n = 5;
    cout << factorial(n);
    return 0;
}