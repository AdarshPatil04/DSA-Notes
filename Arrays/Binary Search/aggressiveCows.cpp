/**
 * @brief This program implements the aggressive cows problem using binary search.
 *
 * The aggressive cows problem involves finding the maximum minimum distance between any two cows
 * in a set of stalls, such that there are a given number of cows placed in the stalls.
 *
 * The program uses binary search to find the maximum minimum distance. It starts with an initial
 * range of possible distances and iteratively narrows down the range until the maximum minimum
 * distance is found.
 *
 * @param stalls The vector of stalls representing the positions of the stalls.
 * @param k The number of cows to be placed in the stalls.
 * @return The maximum minimum distance between any two cows.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to place cows in stalls with given distance
bool ifPossible(vector<int> &stalls, int k, int mid)
{
    int cowsCount = 1;
    int lastPos = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {

        // If the distance between the current stall and the last stall where a cow was placed is greater than or equal to mid
        if (stalls[i] - lastPos >= mid)
        {
            lastPos = stalls[i];
            cowsCount++;

            // If all cows are placed in stalls return true
            if (cowsCount == k)
            {
                return true;
            }

            // Making the current stall the last stall where a cow was placed
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;

    // Finding the maximum distance between any two stalls
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int answer = -1;

    // Binary search algorithm
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // If it is possible to place cows in stalls with distance mid
        if (ifPossible(stalls, k, mid))
        {
            answer = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return answer;
}

int main()
{

    // no. of stalls = 4 and no. of cows = 2
    int n = 4, k = 2;
    vector<int> stalls = {4, 2, 1, 3, 6};

    // Printing the maximum minimum distance between any two cows
    cout << aggressiveCows(stalls, k);
    return 0;
}