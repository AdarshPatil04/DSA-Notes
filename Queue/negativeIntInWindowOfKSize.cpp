/**
 * This code prints the first negative integer in every window of size k.
 * It uses a deque to hold the indices of negative numbers in the current window,
 * and a vector to store the first negative number in each window.
 * The code processes the first window separately, and then iterates through the remaining windows.
 * If there is no negative number in a window, it adds 0 to the answer vector.
 * The code returns the answer vector containing the first negative integers in each window.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to print the first negative integer in every window of size k
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    // Create a deque to hold the indices of negative numbers in the current window
    deque<long long int> dq;
    // Create a vector to hold the first negative number in each window
    vector<long long> ans;

    // Process the first window of size K
    for (int i = 0; i < K; i++)
    {
        // If the current element is negative, add its index to the deque
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // Add the first negative number of the first window to the answer vector
    // If there is no negative number, add 0
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // Now process the remaining windows
    for (int i = K; i < N; i++)
    {
        // If the first element of the previous window is still in the deque, remove it
        if (!dq.empty() && (i - dq.front()) >= K)
        {
            dq.pop_front();
        }

        // Then add the current element to the deque if it is negative
        if (A[i] < 0)
            dq.push_back(i);

        // Add the first negative number of the current window to the answer vector
        // If there is no negative number, add 0
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    // Return the answer vector
    return ans;
}

int main()
{
    // Predefined number of test cases
    long long int t = 1;
    while (t--)
    {
        // Predefined size of the array
        long long int n = 5;
        // Predefined array
        long long int arr[n] = {1, -2, 3, 4, -5};
        // Predefined size of the window
        long long int k = 3;

        // Call the function and store the result in a vector
        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        // Print the elements of the result vector
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
