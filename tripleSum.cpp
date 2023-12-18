/**
 * @brief Finds all triplets in a given array that sum up to a given target sum.
 *
 * This function takes an array of integers and a target sum as input and returns a vector of vectors,
 * where each inner vector represents a triplet of numbers from the input array that sum up to the target sum.
 * The function uses a nested loop to iterate through all possible combinations of three numbers from the array,
 * and checks if their sum is equal to the target sum. If a triplet is found, it is added to the answer vector.
 * The answer vector is then sorted in ascending order before being returned.
 *
 * @param arr The input array of integers.
 * @param sum The target sum.
 * @return A vector of vectors representing the triplets that sum up to the target sum.
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tripleSum(vector<int> &arr, int sum)
{
    vector<vector<int>> answer;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    vector<int> temp;

                    // Finding the min and max of the three numbers
                    temp.push_back(min(arr[i], min(arr[j], arr[k])));
                    temp.push_back(max(arr[i], max(arr[j], arr[k])));

                    // Two numbers are already added to the vector, so we subtract their sum from the target sum to get the third number. But there are 6! possible permutations of the three numbers, so we have found out the min & max of based on first number and the third number will be as per logic explained before. Thus, we will have min(1) max(1) and the third number will be sum-temp[0]-temp[1].
                    temp.push_back(sum - temp[0] - temp[1]);
                    answer.push_back(temp);
                }
            }
        }
    }

    // Sorting the answer vector based on first number.
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int sum = 18;

    // Printing a 2D array
    vector<vector<int>> answer = tripleSum(arr, sum);
    for (vector<int> nums : answer)
    {
        for (int num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}