/**
 * @brief This program demonstrates modular exponentiation.
 *
 * The modular exponentiation algorithm calculates the value of (x^n) % m efficiently,
 * where x is the base, n is the exponent, and m is the modulus.
 * It uses the binary exponentiation technique to reduce the number of multiplications.
 * The algorithm iteratively calculates the result by squaring the base and dividing the exponent by 2.
 * If the exponent is odd, it multiplies the result by the base.
 * The final result is the remainder when the intermediate result is divided by the modulus.
 *
 * @param x The base value.
 * @param n The exponent value.
 * @param m The modulus value.
 * @return The result of (x^n) % m.
 */

#include <bits/stdc++.h>
using namespace std;

// Modular Exponentiation
int modularExponentiation(int x, int n, int m)
{
    int res = 1;
    while (n > 0)
    {
        // If n is odd, multiply the extra x once
        if (n & 1)
        {
            res = ((1LL * res * x) % m) % m;
        }

        // For even n, multiply x by itself and also for odd n after multiplying x once
        x = ((1LL * x * x) % m) % m;

        // Divide n by 2
        n = n >> 1;
    }
    return res;
}

int main()
{
    int x = 4, n = 3, m = 10;
    cout << modularExponentiation(x, n, m);
    return 0;
}