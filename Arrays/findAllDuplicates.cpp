/**
 * @brief Finds all the duplicate elements in a given vector of integers.
 *
 * This function takes a reference to a vector of integers as input and returns
 * a vector containing all the duplicate elements present in the input vector.
 * The function uses the concept of negation to mark the visited elements and
 * identify the duplicates.
 *
 * @param nums The input vector of integers.
 * @return A vector containing all the duplicate elements in the input vector.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> findAllDuplicates(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        // cout << nums[abs(nums[i]) - 1] << endl;
        if (nums[abs(nums[i]) - 1] > 0)
        {
            nums[abs(nums[i]) - 1] *= -1;
            // cout << "if" << nums[abs(nums[i]) - 1] << endl;
        }
        else if (nums[abs(nums[i]) - 1] < 0)
        {
            ans.push_back(abs(nums[i]));
            // cout << "else" << nums[abs(nums[i]) - 1] << endl;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    for (int num : findAllDuplicates(nums))
    {
        cout << num << " ";
    }
    return 0;
}