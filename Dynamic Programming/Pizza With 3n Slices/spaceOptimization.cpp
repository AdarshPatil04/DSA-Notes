/**
 * The time complexity of the algorithm is O(n^2) and the space complexity is O(n).
 * This code solves the problem of finding the maximum size of slices in a pizza with 3n slices.
 * It uses space optimized dynamic programming to efficiently compute the solution.
 * The code initializes and updates two sets of dynamic programming vectors to consider different ranges of slices.
 * It iterates backwards through the slices and computes the maximum size of slices by including or excluding each slice.
 * Finally, it returns the maximum size of slices among the two cases.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using space optimized dynamic programming
int solveSO(vector<int> &slices)
{
    int k = slices.size();
    // Initialize the dp vectors
    vector<int> prev1(k + 2, 0);
    vector<int> curr1(k + 2, 0);
    vector<int> next1(k + 2, 0);

    vector<int> prev2(k + 2, 0);
    vector<int> curr2(k + 2, 0);
    vector<int> next2(k + 2, 0);

    // Fill the dp vectors considering slices from index 0 to k-2
    for (int i = k - 2; i >= 0; i--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            // include: pick the slice at index i and move two steps ahead
            int include = slices[i] + next1[n - 1];
            
            // exclude: do not pick the slice at index i and move one step ahead
            int exclude = 0 + curr1[n];

            // store the maximum of include and exclude
            prev1[n] = max(include, exclude);
        }
        // update the dp vectors for the next iteration
        next1 = curr1;
        curr1 = prev1;
    }
    // case1: maximum size of slices considering slices from index 0 to k-2
    int case1 = curr1[k / 3];

    // Fill the dp vectors considering slices from index 1 to k-1
    for (int i = k - 1; i >= 1; i--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            // include: pick the slice at index i and move two steps ahead
            int include = slices[i] + next2[n - 1];
            
            // exclude: do not pick the slice at index i and move one step ahead
            int exclude = 0 + curr2[n];

            // store the maximum of include and exclude
            prev2[n] = max(include, exclude);
        }
        // update the dp vectors for the next iteration
        next2 = curr2;
        curr2 = prev2;
    }
    // case2: maximum size of slices considering slices from index 1 to k-1
    int case2 = curr2[k / 3];

    // return the maximum of case1 and case2
    return max(case1, case2);
}

// Function to find the maximum size of slices
int maxSizeSlices(vector<int> &slices)
{
    // Space Optimized
    return solveSO(slices);
}

int main()
{
    // Initialize the slices
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    
    // Print the maximum size of slices
    cout << maxSizeSlices(slices) << endl;
    
    return 0;
}
