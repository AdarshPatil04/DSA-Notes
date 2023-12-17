/**
 * @brief This program finds the duplicate element in a given vector of integers from 1 to N-1.
 * 
 * The program uses the XOR operation to find the duplicate element. It XORs all the elements in the vector
 * with each other and then XORs the result with the elements from 1 to n-1, where n is the size of the vector.
 * The final result will be the duplicate element.
 * 
 * @param arr The vector of integers to search for the duplicate element.
 */

#include <bits\stdc++.h>
using namespace std;

void findDuplicate(vector<int> &arr)
{
    int answer = 0;
    for(int i=0;i<arr.size();i++){
        answer ^= arr[i];
        // Doing bitwise XOR for each element in the array
        // cout<<answer<<endl;
    }
    // cout<<"-------"<<endl;
    for(int i=1;i<arr.size();i++){
        answer ^= i;
        // Doing bitwise XOR starting from 1 to N-1(here 6) in the array
        // cout<<answer<<endl;
    }
    cout<<answer<<endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 5, 6};
    findDuplicate(arr);
    return 0;
}