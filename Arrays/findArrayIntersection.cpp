/**
 * Finds the intersection of two arrays. The arrays are assumed to be sorted in ascending order which is y we use two-pointer approach.
 * Given two arrays, this function returns a vector containing the common elements between the two arrays.
 * The function uses a two-pointer approach to iterate through the arrays and find the common elements.
 * 
 * @param arr1 The first array.
 * @param arr2 The second array.
 * @return A vector containing the common elements between arr1 and arr2.
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> answer;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] == arr2[j])
        {
            answer.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return answer;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {1, 2, 3};
    for (int num : findArrayIntersection(arr1, arr2))
    {
        cout << num << " ";
    }
    return 0;
}