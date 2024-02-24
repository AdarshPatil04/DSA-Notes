/**
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 * @brief This program solves the activity selection problem using a greedy algorithm.
 *        Given a set of activities with their start and end times, the goal is to select
 *        the maximum number of non-overlapping activities that can be performed by a single person.
 *        The program sorts the activities based on their finish time and then iterates over them,
 *        selecting activities that do not overlap with the previously selected activities.
 *        The maximum number of activities that can be performed is returned as the output.
 */
#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort activities based on their finish time
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

// Function to find the maximum number of activities that can
// be performed by a single person.
int activitySelection(vector<int> start, vector<int> end, int n)
{
    // Create a vector of pairs where each pair is a start time and end time of an activity
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }

    // Sort the activities based on their finish time
    sort(v.begin(), v.end(), cmp);

    // Initialize count of activities and end time of first activity
    int cnt = 1;
    int ansEnd = v[0].second;

    // Iterate over the activities
    for (int i = 1; i < n; i++)
    {
        // If the start time of current activity is greater than the end time of previously selected activity
        if (v[i].first > ansEnd)
        {
            // Increment the count and update the end time of selected activity
            cnt++;
            ansEnd = v[i].second;
        }
    }
    // Return the maximum number of activities that can be performed
    return cnt;
}

int main()
{
    // Number of activities
    int n = 6;
    // Start time of activities
    vector<int> start = {1, 3, 2, 5, 8, 5};
    // End time of activities
    vector<int> end = {2, 4, 3, 6, 9, 7};
    // Print the maximum number of activities that can be performed
    cout << activitySelection(start, end, n);
    return 0;
}