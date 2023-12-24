/**
 * This program calculates the sum of two arrays of integers.
 * It takes two vectors as input and returns a vector containing the sum of the arrays.
 * The arrays are added digit by digit, starting from the least significant digit.
 * If the sum of two digits is greater than 9, the carry is propagated to the next digit.
 * The final sum is reversed and returned as the output.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to reverse the array
vector<int> reverseArray(vector<int> &arr)
{
    int s = 0;
    int e = arr.size()-1;
    while (s < e)
    {
        swap(arr[s++], arr[e--]);
    }
    return arr;
}

// Function to calculate the sum of two arrays
vector<int> arraySum(vector<int> &arr1, vector<int> &arr2)
{
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    int carry = 0;
    vector<int> answer;

    // if val1 & val2 exists and there is a carry either 0 or 1
    while (i >= 0 && j >= 0)
    {
        int value1 = arr1[i], value2 = arr2[j];
        int sum = value1 + value2 + carry;
        carry = sum/ 10;
        sum %= 10;
        answer.push_back(sum);
        i--;
        j--;
    }

    // if val1 exists and there is a carry either 0 or 1
    while (i >= 0)
    {
        int sum = arr1[i] + carry;
        carry = sum/ 10;
        sum %= 10;
        answer.push_back(sum);
        i--;
    }

    // if val2 exists and there is a carry either 0 or 1
    while (j >= 0)
    {
        int sum = arr2[j] + carry;
        carry = sum/ 10;
        sum %= 10;
        answer.push_back(sum);
        j--;
    }

    // if there is a carry either 0 or 1 in the MSB
    while (carry != 0)
    {
        int sum = carry;
        carry = sum/ 10;
        sum %= 10;
        answer.push_back(sum);
    }

    // reverse the answer vector because we added the digits from the LSB and pushed them to the vector
    return reverseArray(answer);
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {6};

    // Printing the sum of the two arrays
    for (int i : arraySum(arr1, arr2))
    {
        cout << i << " ";
    }
    return 0;
}