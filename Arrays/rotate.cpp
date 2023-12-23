/**
 * @brief This program rotates the elements of a vector by a given number of positions.
 *
 * The rotate function takes a vector of integers and an integer value 'k' as input.
 * It creates a temporary vector 'temp' of the same size as the input vector.
 * Then, it iterates through each element of the input vector and assigns it to the corresponding position in the temporary vector,
 * by using the formula (i+k)%arr.size(), where 'i' is the current index and 'arr.size()' is the size of the input vector.
 * Finally, it assigns the temporary vector to the input vector, effectively rotating the elements.
 *
 * @param arr The input vector of integers to be rotated.
 * @param k The number of positions to rotate the elements.
 */

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr, int k)
{
    vector<int> temp(arr.size());

    // (n+2)%n = 2 {(n-1)th element to index 2}
    for (int i = 0; i < arr.size(); i++)
    {
        temp[(i + k) % arr.size()] = arr[i];
    }
    arr = temp;
}

int main()
{

    // Rotate by 3 places
    int k = 3;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    rotate(arr, k);

    // Printing the rotated array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}