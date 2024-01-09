/**
 * @brief This program calculates the power of 2 for a given number using recursion.
 *
 * The powerOfTwo function takes an integer n as input and recursively calculates the power of 2 by multiplying 2 with the result of powerOfTwo(n - 1).
 * The base case is when n is 0, in which case the function returns 1.
 *
 * @param n The number for which the power of 2 is to be calculated.
 * @return The power of 2 for the given number.
 */

#include <bits/stdc++.h>
using namespace std;

int powerOfTwo(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }

    // recursive case
    return 2 * powerOfTwo(n - 1);
}

int main()
{
    int n = 5;
    cout << powerOfTwo(n);
    return 0;
}