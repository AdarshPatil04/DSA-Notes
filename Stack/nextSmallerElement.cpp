/**
 * Time Complexity: O(n)
 * @brief This program finds the next smaller element for each element in an array.
 * 
 * The program uses a stack to store the elements and traverses the array from right to left.
 * For each element, it pops the elements from the stack until the top of the stack is greater than or equal to the current element.
 * Then, it stores the top of the stack as the next smaller element for the current element.
 * Finally, it returns a vector containing the next smaller element for each element in the array.
 */
#include<bits/stdc++.h>
using namespace std;

// Function to find the next smaller element
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s; // stack to store the elements
    s.push(-1); // push -1 into the stack
    vector<int> ans(n); // vector to store the next smaller element
    // traverse the array from right to left
    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i]; // store the current element of the array in curr
        // pop the elements from the stack until the top of stack is greater than or equal to curr
        while(s.top() >= curr)
        {
            s.pop(); // pop the top of stack
        }
        ans[i] = s.top(); // store the top of stack in ans
        s.push(curr); // push curr into the stack so that it can be used to find the next smaller element
    }
    return ans; // return ans
}

int main(){
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> ans = nextSmallerElement(arr, arr.size());
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}
