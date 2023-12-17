/**
 * @brief Checks if the occurrences of elements in a given vector are unique.
 *
 * This function takes a vector of integers as input and checks if the occurrences
 * of each element in the vector are unique. It counts the occurrences of each element
 * and stores them in a separate vector. Then, it sorts the vector of occurrences and
 * checks if any adjacent elements are equal. If there are any equal adjacent elements,
 * it returns false indicating that the occurrences are not unique. Otherwise, it returns
 * true indicating that the occurrences are unique.
 *
 * @param arr The input vector of integers.
 * @return true if the occurrences of elements are unique, false otherwise.
 */

#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    int size = arr.size();
    vector<int> answer;
    int i = 0;

    // Sorting the array to save space and time so that while loop can be used to iterate with a step of count
    sort(arr.begin(), arr.end());
    while (i < size)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }

        // Making an array of occurrences of each element
        answer.push_back(count);
        i += count;
    }

    // Checking if any adjacent elements are equal
    for (int i = 0; i < answer.size() - 1; i++)
    {
        if (answer[i] == answer[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3, 3, 3};

    // Used boolalpha to print true or false instead of 1 or 0
    cout << boolalpha << uniqueOccurrences(arr) << endl;
    return 0;
}