/**
//Time Complexity => O(n*(m+n)) where n*m is the size of the matrix
 * This code implements the solution to the problem of finding the maximal rectangle in a binary matrix.
 * The code uses the concept of finding the largest area of a histogram to find the maximum area of a rectangle.
 * It first calculates the heights of the rectangles for each column in the matrix.
 * Then, for each row in the matrix, it updates the heights array and calculates the maximum area using the largestAreaHistogram function.
 * The final result is the maximum area of the rectangle in the binary matrix.
 */
// https://leetcode.com/problems/maximal-rectangle/

#include <bits/stdc++.h>
using namespace std;

// Function to find the previous smaller element for each element in the array
vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1); // Push -1 as the previous smaller element for the first element

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        // Pop elements from the stack while they are greater or equal to the current element
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top(); // The top of the stack is the previous smaller element
        s.push(i);        // Push the current element to the stack
    }
    return ans;
}

// Function to find the next smaller element for each element in the array
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1); // Push -1 as the next smaller element for the last element

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        // Pop elements from the stack while they are greater or equal to the current element
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top(); // The top of the stack is the next smaller element
        s.push(i);        // Push the current element to the stack
    }
    return ans;
}

// Function to find the largest area of a histogram
int largestAreaHistogram(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prev(n);
    prev = prevSmallerElement(arr, n); // Find the previous smaller elements

    vector<int> next(n);
    next = nextSmallerElement(arr, n); // Find the next smaller elements

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = arr[i]; // The height of the rectangle
        if (next[i] == -1)
            next[i] = n;               // If there is no next smaller element, consider the end of the array
        int b = next[i] - prev[i] - 1; // The width of the rectangle
        int newArea = l * b;           // The area of the rectangle
        area = max(area, newArea);     // Update the maximum area
    }
    return area;
}

// Function to find the maximal rectangle in a binary matrix
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<int> height(matrix[0].size(), 0); // Initialize the heights of the rectangles
    int ans = INT_MIN;
    // For every row in the matrix
    for (int i = 0; i < matrix.size(); i++)
    {
        // Update the array of heights
        for (int j = 0; j < height.size(); j++)
        {
            if (matrix[i][j] == '1')
            {
                height[j]++;
            }
            else
            {
                height[j] = 0;
            }
        }
        ans = max(ans, largestAreaHistogram(height)); // Update the maximum area
    }
    return ans;
}

int main()
{
    // Test the function with example inputs
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(matrix) << endl; // Expected output: 6

    return 0;
}
