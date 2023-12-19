/**
 * @brief This program calculates the square root of a given number with a specified precision.
 *        It uses the binary search algorithm to find the approximate square root and then refines
 *        the result by iterating and adjusting the precision.
 *
 * @param n The number for which the square root is to be calculated.
 * @param precision The desired precision of the square root.
 * @return The square root of the given number with the specified precision.
 */

#include <bits/stdc++.h>
using namespace std;

// long long int is used to avoid overflow of square of mid
long long int sqrRoot(int n)
{
    int s = 0, e = n;
    long long answer = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        long long int square = mid * mid;
        if (square == n)
        {
            return mid;
        }

        // Checking on left side
        else if (square > n)
        {
            e = mid - 1;
        }

        /*
        square < n
        Checking on right side
        */
        else
        {
            s = mid + 1;
            answer = mid;
        }
    }
    return answer;
}

double morePrecision(int n, int precision, int tempSol)
{
    double factor = 1;

    // Storing the approx. square root in answer
    double answer = tempSol;
    for (int i = 0; i < precision; i++)
    {

        // Calculating the factor
        factor /= 10;

        // Checking for the square < n
        for (double j = answer; (j * j) < n; j = j + factor)
        {
            answer = j;
        }
    }
    return answer;
}

int main()
{
    int n, precision;
    cin >> n >> precision;
    int tempSol = sqrRoot(n);

    // Printing the square root with precision
    cout << morePrecision(n, precision, tempSol);
    return 0;
}