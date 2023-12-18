/**
 * This program finds pairs of numbers in an array that sum up to a given value.
 * It uses a nested loop to iterate through all possible pairs of numbers in the array.
 * If a pair is found whose sum matches the given value, it is added to the answer vector.
 * The answer vector is then sorted and returned.
 */

#include <bits/stdc++.h>
using namespace std;

//2D vector is used to store the pairs
vector<vector<int>> pairSum(vector<int> &arr, int sum)
{
    vector<vector<int>> answer;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==sum){
                vector<int> temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                answer.push_back(temp);
            }
        }
    }
    
    // Sorting the answer vector
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> arr = {2, -3, 3, 3, -2};
    int sum = 0;

    // Printing the pairs
    vector<vector<int>> answer = pairSum(arr, sum);
    for (vector<int> nums : answer)
    {
        for(int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}