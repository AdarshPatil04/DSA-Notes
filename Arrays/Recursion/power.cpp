/**
 * @brief Calculates the power of a number using recursion.
 * 
 * This code defines a function named power that calculates the power of a number 'a' raised to the power 'b' using recursion.
 * The base cases are when 'b' is 0 or 1, in which case the function returns 1 or 'a' respectively.
 * For other values of 'b', the function recursively calculates the power of 'a' raised to 'b/2' and then multiplies it with itself.
 * If 'b' is even, the function returns the square of the calculated power, otherwise it returns the square of the power multiplied by 'a'.
 * The main function demonstrates the usage of the power function by calculating and printing the result of 2 raised to the power 5.
 */

#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{

    // base case
    // if b is 0 then return 1
    if (b == 0)
    {
        return 1;
    }

    // if b is 1 then return a
    if (b == 1)
    {
        return a;
    }

    // recursive case
    int answer = power(a, b / 2);

    // if b is even then return answer * answer
    if (b % 2 == 0)
    {
        return answer * answer;
    }

    // if b is odd then return answer * answer * a
    else
    {
        return answer * answer * a;
    }
}

int main()
{
    int a = 2;
    int b = 5;

    // Printing a raised to the power b
    cout << power(a, b);
    return 0;
}