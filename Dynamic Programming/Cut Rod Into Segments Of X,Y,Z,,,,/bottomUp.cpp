// The time complexity of the algorithm is O(N), where N is the length of the rod.
// The space complexity is O(N) as well.
// This code solves the problem of cutting a rod of length 'n' into segments of lengths 'x', 'y', and 'z'.
// It uses the bottom-up approach of dynamic programming to find the maximum number of cuts that can be made.
// The main function initializes the rod length and segment lengths, calls the cutSegments function, and prints the maximum number of cuts.
// https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using tabulation (bottom-up approach)
int solveTab(int n, int x, int y, int z)
{
    // //step-1: creation of dp array
    // vector<int> dp(n+1, INT_MIN);
    // //step-2
    // dp[0] = 0;
    // //step-3
    // for(int i=1; i<=n; i++) {
    // 	if(i-x >= 0)
    // 		dp[i] = max(dp[i], dp[i-x] + 1) ;
    // 	if(i-y >= 0)
    // 		dp[i] = max(dp[i], dp[i-y] + 1) ;
    // 	if(i-z >= 0)
    // 		dp[i] = max(dp[i], dp[i-z] + 1) ;
    // }
    // //step-4
    // return dp[n];

    // step-1: creation of dp array
    vector<int> dp(n + 1, -1);

    // step-2: base case initialization
    dp[0] = 0;

    // step-3: fill the dp array in bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        // if the rod can be cut into length x and the remaining part has a valid solution because if it is -1 then -1+1 = 0 which is not valid
        if (i - x >= 0 && dp[i - x] != -1)
            dp[i] = max(dp[i], dp[i - x] + 1);

        // if the rod can be cut into length y and the remaining part has a valid solution
        if (i - y >= 0 && dp[i - y] != -1)
            dp[i] = max(dp[i], dp[i - y] + 1);

        // if the rod can be cut into length z and the remaining part has a valid solution
        if (i - z >= 0 && dp[i - z] != -1)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }
    // step-4: return the maximum number of cuts for the rod of length n
    return dp[n];
}

// Function to find the maximum number of segments of lengths x, y, and z
int cutSegments(int n, int x, int y, int z)
{
    // Tabulation -> Bottom-Up Approach
    int ans = solveTab(n, x, y, z);
    // if ans is less than zero, return 0 as it means no valid cuts can be made
    if (ans < 0)
        return 0;
    else
        return ans; // return the maximum number of cuts
}

int main()
{
    int n = 5, x = 2, y = 5, z = 1;          // initialize rod length and segment lengths
    cout << cutSegments(n, x, y, z) << endl; // print the maximum number of cuts
    return 0;
}
