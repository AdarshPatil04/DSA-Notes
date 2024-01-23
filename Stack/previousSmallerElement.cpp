/**
 * Time Complexity: O(n)
 * @brief This code finds the previous smaller element for each element in an array using a stack.
 * 
 * The function `previousSmallerElement` takes an array `arr` and its size `n` as input and returns a vector `ans` 
 * containing the previous smaller element for each element in the array. It uses a stack to store the elements and 
 * traverses the array from left to right. For each element, it pops the elements from the stack until the top of the 
 * stack is greater than or equal to the current element. Then, it stores the top of the stack in the `ans` vector and 
 * pushes the current element into the stack. Finally, it returns the `ans` vector.
 * 
 * The `main` function demonstrates the usage of the `previousSmallerElement` function by creating an array and calling 
 * the function. It prints the elements of the `ans` vector.
 */
#include<bits/stdc++.h>
using namespace std;

// Function to find the previous smaller element
vector<int> previousSmallerElement(vector<int> &arr, int n)
{
    stack<int> s; // stack to store the elements
    s.push(-1); // push -1 into the stack
    vector<int> ans(n); // vector to store the previous smaller element
    // traverse the array from left to right
    for(int i=0; i<n ; i++) {
        int curr = arr[i]; // store the current element of the array in curr
        // pop the elements from the stack until the top of stack is greater than or equal to curr
        while(s.top() >= curr)
        {
            s.pop(); // pop the top of stack
        }
        ans[i] = s.top(); // store the top of stack in ans
        s.push(curr); // push curr into the stack so that it can be used to find the previous smaller element
    }
    return ans; // return ans
}

int main(){
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> ans = previousSmallerElement(arr, arr.size());
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}