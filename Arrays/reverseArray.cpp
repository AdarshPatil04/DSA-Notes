/**
 * @brief Reverses the elements of a given array.
 * 
 * This function takes an array as input and reverses its elements in-place.
 * It uses a two-pointer approach to swap the elements from the start and end of the array.
 * The reversed array is then returned.
 * 
 * @param arr The input array to be reversed.
 * @return vector<int> The reversed array.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> reverseArray(vector<int>& arr)
{
    int s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    return arr;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> res = reverseArray(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}