/**
 * Time Complexity: O(nlogn)
 * Space Complexity: O(1)
 * This code calculates the minimum and maximum amount to be spent to buy all candies from a candy store.
 * The code takes an array of prices of candies, the number of candies, and the number of candies to get for free when one candy is bought.
 * It sorts the array of candies and then calculates the minimum and maximum amounts by buying candies starting from the cheapest and most expensive, respectively.
 * The minimum amount is calculated by buying the cheapest candy and getting K expensive candies for free.
 * The maximum amount is calculated by buying the most expensive candy and getting K cheap candies for free.
 * The code returns a vector containing the minimum and maximum amounts to be spent.
 */
// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum and maximum amount to be spent to buy all candies
vector<int> candyStore(int candies[], int N, int K)
{
    // Sort the array of candies
    sort(candies, candies + N);

    // Initialize variables
    int mini = 0;     // Minimum amount to be spent
    int buy = 0;      // Index for buying the cheapest candy
    int free = N - 1; // Index for getting the most expensive candy for free

    // Buy candies starting from the cheapest and get K expensive candies for free
    while (buy <= free)
    {
        // Add the price of the cheapest candy to the minimum amount
        mini += candies[buy];
        buy++;     // Move to the next cheapest candy
        free -= K; // Move K steps back from the most expensive candy
    }

    // Initialize variables
    int maxi = 0; // Maximum amount to be spent
    buy = N - 1;  // Index for buying the most expensive candy
    free = 0;     // Index for getting the cheapest candy for free

    // Buy candies starting from the most expensive and get K cheap candies for free
    while (free <= buy)
    {
        // Add the price of the most expensive candy to the maximum amount
        maxi += candies[buy];
        buy--;     // Move to the next most expensive candy
        free += K; // Move K steps forward from the cheapest candy
    }

    // Store the minimum and maximum amounts in a vector and return it
    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);
    return ans;
}

int main()
{
    // Array of prices of candies
    int candies[] = {3, 2, 1, 4};
    // Number of candies
    int N = 4;
    // Number of candies to get for free when one candy is bought
    int K = 2;
    // Calculate the minimum and maximum amounts to be spent to buy all candies
    vector<int> ans = candyStore(candies, N, K);
    // Print the minimum and maximum amounts
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
