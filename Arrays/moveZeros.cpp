/**
 * @brief Moves all the zeros in the given vector to the end of the vector.
 *
 * This function iterates through the vector and swaps non-zero elements with the elements at the beginning of the vector.
 * As a result, all the zeros are moved to the end of the vector while maintaining the relative order of non-zero elements.
 *
 * @param arr The vector of integers to be modified.
 */

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr)
{
    int nonZero = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        // arr[i] == 0 --> Ignore, arr[i] != 0 --> Swap But order is maintained(no sorting)
        if (arr[i] != 0)
        {
            swap(arr[i], arr[nonZero++]);
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    moveZeroes(arr);

    // Printing the array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}