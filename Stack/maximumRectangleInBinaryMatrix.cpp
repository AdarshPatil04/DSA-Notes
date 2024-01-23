/**
 * Time Complexity: O(n*m)
 * Space Complexity: O(m)
 * This code calculates the maximum area of a rectangle in a binary matrix.
 * The matrix is represented as a 2D array of integers, where 1 represents a filled cell and 0 represents an empty cell.
 * The algorithm uses the concept of histograms and stack to find the maximum area of a rectangle in each row of the matrix.
 * It iterates through each row of the matrix, updates the values in the matrix based on the previous row, and calculates the maximum area using the largestRectangleArea function.
 * The largestRectangleArea function uses the nextSmallerElement and prevSmallerElement functions to find the next and previous smaller elements for each element in the histogram.
 * The maxArea function returns the maximum area of the rectangle in the binary matrix.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to find the next smaller element
    vector<int> nextSmallerElement(int *arr, int n)
    {
        stack<int> s;       // stack to store the elements
        s.push(-1);         // push -1 into the stack
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
            s.push(i);        // push curr into the stack so that it can be used to find the next smaller element
        }
        return ans; // return ans
    }

    // Function to find the previous smaller element
    vector<int> prevSmallerElement(int *arr, int n)
    {
        stack<int> s;       // stack to store the elements
        s.push(-1);         // push -1 into the stack
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
            s.push(i);        // push curr into the stack so that it can be used to find the previous smaller element
        }
        return ans; // return ans
    }

    // Function to find the largest rectangle in a histogram
    int largestRectangleArea(int *heights, int n)
    {
        vector<int> next(n);                   // vector to store the next smaller element
        next = nextSmallerElement(heights, n); // find the next smaller element
        vector<int> prev(n);                   // vector to store the previous smaller element
        prev = prevSmallerElement(heights, n); // find the previous smaller element
        int area = INT_MIN;                    // variable to store the maximum area
        // traverse the array
        for (int i = 0; i < n; i++)
        {
            int l = heights[i]; // store the current element in l
                                // if the previous smaller element does not exist then set it to -1
            if (next[i] == -1)
            {
                next[i] = n; // set it to n
            }
            int b = next[i] - prev[i] - 1; // store the width of the rectangle in b
            int newArea = l * b;           // store the area of the rectangle in newArea
            area = max(area, newArea);     // update the maximum area
        }
        return area; // return the maximum area
    }

public:
    // Function to find the maximum area rectangle
    int maxArea(int M[][4], int n, int m)
    {
        int area = largestRectangleArea(M[0], m); // store the maximum area
        // traverse the matrix
        for (int i = 1; i < n; i++)
        {
            // traverse the row
            for (int j = 0; j < m; j++)
            {
                // if M[i][j] is not equal to 0 then update it
                if (M[i][j] != 0)
                {
                    M[i][j] = M[i][j] + M[i - 1][j]; // update M[i][j]
                }
                // if M[i][j] is equal to 0 then set it to 0
                else
                {
                    M[i][j] = 0; // set it to 0
                }
            }
            area = max(area, largestRectangleArea(M[i], m)); // update the maximum area
        }
        return area; // return the maximum area
    }
};

int main()
{
    int M[4][4] = {{0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0}};
    Solution obj;
    cout << obj.maxArea(M, 4, 4);
    return 0;
}