
/**
 * @file gcd.cpp
 * @brief This file contains the implementation of the Euclidean Algorithm to find the greatest common divisor (GCD) of two numbers.
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Calculates the GCD of two numbers using the Euclidean Algorithm.
 * @param a The first number.
 * @param b The second number.
 * @return The GCD of the two numbers.
 */

int gcd(int a, int b)
{
    // Base case
    if (a == 0)
    {
        return b;
    }

    // Base case
    if (b == 0)
    {
        return a;
    }
    while (a != b)
    {
        // If a is greater
        if (a > b)
        {

            // Subtract a from b
            a = a - b;
        }

        // If b is greater
        else
        {

            // Subtract b from a
            b = b - a;
        }
    }

    // Return the GCD
    return a;
}

int main()
{
    int a = 10, b = 15;

    // Printing the GCD
    cout << gcd(a, b);
    return 0;
}