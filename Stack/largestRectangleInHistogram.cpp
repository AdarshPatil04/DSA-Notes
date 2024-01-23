/**
 * Time Complexity: O(n)
 * @brief This code calculates the largest rectangle area in a histogram.
 * 
 * The code uses the concept of finding the next smaller and previous smaller elements
 * for each element in the histogram. It then calculates the area of the rectangle
 * formed by each element as the height and the width between the next smaller and
 * previous smaller elements. The maximum area among all rectangles is returned as
 * the largest rectangle area in the histogram.
 * 
 * @return int The largest rectangle area in the histogram.
 */
#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to find the next smaller element
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
        stack<int> s; // stack to store the elements
        s.push(-1); // push -1 into the stack
        vector<int> ans(n); // vector to store the next smaller element
        // traverse the array from right to left
        for (int i = n - 1; i >= 0; i--)
        { 
            int curr = arr[i]; // store the current element of the array in curr
            // pop the elements from the stack until the top of stack is greater than or equal to curr
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop(); // pop the top of stack
            }
            ans[i] = s.top(); // store the top of stack in ans
            s.push(i); // push curr into the stack so that it can be used to find the next smaller element
        }
        return ans; // return ans
    }

// Function to find the previous smaller element
    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
        stack<int> s; // stack to store the elements
        s.push(-1); // push -1 into the stack
        vector<int> ans(n); // vector to store the previous smaller element
        // traverse the array from left to right
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i]; // store the current element of the array in curr
            // pop the elements from the stack until the top of stack is greater than or equal to curr
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop(); // pop the top of stack
            }
            ans[i] = s.top(); // store the top of stack in ans
            s.push(i); // push curr into the stack so that it can be used to find the previous smaller element
        }
        return ans; // return ans
    }

public:
    // Function to find the largest rectangle in a histogram
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size(); // store the size of the array in n
        vector<int> next(n); // vector to store the next smaller element
        next = nextSmallerElement(heights, n); // find the next smaller element
        vector<int> prev(n); // vector to store the previous smaller element
        prev = prevSmallerElement(heights, n); // find the previous smaller element
        int area = INT_MIN; // variable to store the maximum area
        // traverse the array
        for (int i = 0; i < n; i++)
        {
            int l = heights[i]; // store the height of the rectangle in l
            // if next[i] is -1 then store n in next[i]
            if (next[i] == -1)
            {
                next[i] = n; // store n in next[i]
            }
            int b = next[i] - prev[i] - 1; // store the width of the rectangle in b
            int newArea = l * b; // store the area of the rectangle in newArea
            area = max(area, newArea); // update the maximum area
        }
        return area; // return the maximum area
    }
};

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution obj;
    cout << obj.largestRectangleArea(heights); // print the maximum area
    return 0;
}