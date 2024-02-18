/**
 * The time complexity of the code is O(nlog(n)), where n is the number of envelopes.
 * The space complexity is O(n).
 * This code solves the Russian Doll Envelopes problem, which involves finding the maximum number of envelopes that can be nested inside each other.
 * The code uses a custom comparator function to sort the envelopes based on their widths and heights.
 * It then applies an optimal approach to find the maximum number of envelopes that can be nested.
 */
#include <bits/stdc++.h>
using namespace std;

// Custom comparator function to sort the envelopes
// If widths are same, sort by height in decreasing order
// Otherwise, sort by width in increasing order
static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

// Function to solve the problem using an optimal approach
int solveOptimal(vector<vector<int>> &envelopes, int n)
{
    // Base case: If there are no envelopes, return 0
    if (n == 0)
        return 0;

    // Initialize the answer vector
    vector<int> ans;

    // Iterate over the envelopes
    for (int i = 0; i < n; i++)
    {
        // If the answer vector is empty or the height of the current envelope is greater than the last height in the answer vector
        // Add the height of the current envelope to the end of the answer vector
        if (ans.empty() || envelopes[i][1] > ans.back())
            ans.push_back(envelopes[i][1]);
        else
        {
            // If the height of the current envelope is not greater than the last height in the answer vector
            // Find the index of the next immediate greater height in the answer vector
            int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();

            // Replace the next immediate greater height in the answer vector with the height of the current envelope
            ans[index] = envelopes[i][1];
        }
    }
    // Return the size of the answer vector, which is the maximum number of envelopes that can be Russian-dolled
    return ans.size();
}

// Function to find the maximum number of envelopes that can be Russian-dolled
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    // Sort the envelopes using the custom comparator function
    sort(envelopes.begin(), envelopes.end(), cmp);

    // The number of envelopes
    int n = envelopes.size();

    // Solve the problem using an optimal approach
    return solveOptimal(envelopes, n);
}

int main()
{
    // Test case: Envelopes
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};

    // Print the maximum number of envelopes that can be Russian-dolled
    cout << maxEnvelopes(envelopes) << endl;

    return 0;
}
