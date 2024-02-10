/**
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 * @file fibonacci.cpp
 * @brief This file contains the implementation of the Fibonacci series using recursion.
 * The Fibonacci series is a sequence of numbers in which each number is the sum of the two preceding ones.
 * This program calculates the nth Fibonacci number using recursion.
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Calculates the nth Fibonacci number using recursion.
 * @param n The position of the Fibonacci number to be calculated.
 * @return The nth Fibonacci number.
 */

int fibonacci(int n)
{

    // base case
    if (n == 0 || n == 1)
    {
        return n;
    }

    // recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 3;

    // prints the nth Fibonacci number
    cout << fibonacci(n);
    return 0;
}