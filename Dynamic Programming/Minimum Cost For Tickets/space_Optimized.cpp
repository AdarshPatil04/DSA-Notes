/**
 * Time complexity: O(N), where N is the number of days in the given list.
 * Space complexity: O(1).
 * @brief This code solves the minimum cost for tickets problem using a space-optimized approach.
 *
 * The problem is to find the minimum cost to travel every day in a given list of days, where three types of tickets are available:
 * - 1-day pass: costs 'cost[0]'
 * - 7-day pass: costs 'cost[1]'
 * - 30-day pass: costs 'cost[2]'
 *
 * The code uses two queues to store the cost for the current day using a 7-day pass and a 30-day pass.
 * It iterates through all the days and performs the following steps:
 * 1. Remove expired days from the queues.
 * 2. Add the cost for the current day to the queues.
 * 3. Update the minimum cost for the current day.
 *
 * The code returns the minimum cost to travel every day in the given list of days.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using a space-optimized approach
// The function takes the total number of days (n), the array of days, and the array of costs as input
int SolveSpaceOpt(int n, vector<int> &days, vector<int> &cost)
{
    // Initialize the answer as 0
    int ans = 0;

    // Initialize two queues to store the cost for the current day using a 7-day pass and a 30-day pass
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    // Loop through all the days
    for (int day : days)
    {
        // Step-1: Remove expired days
        // If the first day in the queue plus 30 is less than or equal to the current day, pop it from the queue
        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();

        // If the first day in the queue plus 7 is less than or equal to the current day, pop it from the queue
        while (!week.empty() && week.front().first + 7 <= day)
            week.pop();

        // Step-2: Add cost for current days
        // Push the current day and the current answer plus the cost of a 7-day pass into the week queue
        week.push(make_pair(day, ans + cost[1]));

        // Push the current day and the current answer plus the cost of a 30-day pass into the month queue
        month.push(make_pair(day, ans + cost[2]));

        // Step-3: Update ans
        // Update the answer as the minimum of the current answer plus the cost of a 1-day pass,
        // and the minimum of the second element of the front pair in the week queue and the month queue
        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }

    // Return the answer
    return ans;
}

// Function to get the minimum cost to travel every day in the given list of days
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Call the space-optimized function to solve the problem
    return SolveSpaceOpt(n, days, cost);
}

int main()
{
    // Test the function with a sample testcase
    int n = 6;
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> cost = {2, 7, 25};
    cout << minimumCoins(n, days, cost);
    return 0;
}
