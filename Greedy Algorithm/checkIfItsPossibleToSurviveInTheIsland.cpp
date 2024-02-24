/**
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * This code calculates the minimum number of days required to survive on an island.
 * Given the number of days to survive (S), the number of units of food required each day (N),
 * and the number of units of food that can be bought each day (M), the code determines if it is
 * possible to survive and returns the minimum number of days required. If it is not possible to
 * survive, the code returns -1.
 */
// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum number of days to survive on the island
int minimumDays(int S, int N, int M)
{
    // Calculate the number of Sundays
    int sundays = S / 7;
    // Calculate the number of days when buying is possible
    int buyingDays = S - sundays;
    // Calculate the total amount of food required
    int totalFood = S * M;
    int ans = 0;

    // Calculate the minimum number of days to buy all the required food
    if (totalFood % N == 0)
    {
        ans = totalFood / N;
    }
    else
    {
        ans = totalFood / N + 1;
    }

    // If it is possible to survive, return the minimum number of days, otherwise return -1
    if (ans <= buyingDays)
        return ans;
    else
        return -1;
}

int main()
{
    // Number of days to survive
    int S = 10;
    // Number of units of food required each day
    int N = 16;
    // Number of units of food that can be bought each day
    int M = 2;
    // Calculate and print the minimum number of days to survive
    cout << minimumDays(S, N, M);
    return 0;
}
