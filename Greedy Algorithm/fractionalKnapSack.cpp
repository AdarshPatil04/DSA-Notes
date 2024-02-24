/**
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 * @brief This code implements the Fractional Knapsack problem using a greedy algorithm.
 *
 * The Fractional Knapsack problem involves selecting items with maximum total value to fit into a knapsack
 * with a given weight capacity. Each item has a value and a weight, and the goal is to maximize the total
 * value of the selected items while ensuring that the total weight does not exceed the capacity of the knapsack.
 *
 * The code uses a greedy approach by calculating the value per unit weight for each item and sorting the items
 * in descending order of value per unit weight. It then iterates over the items, adding them to the knapsack
 * until the capacity is reached. If an item cannot be fully included, a fraction of it is taken to fill the knapsack.
 *
 * The code returns the maximum total value that can be put in the knapsack.
 */
// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Structure to represent an item
struct Item
{
    int value;  // Value of the item
    int weight; // Weight of the item
};

// Comparator function to sort items based on their value per unit weight
bool cmp(pair<double, Item> a, pair<double, Item> b)
{
    return a.first > b.first;
}

// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Create a vector to store the items along with their value per unit weight
    vector<pair<double, Item>> v;

    // Calculate the value per unit weight for each item and add it to the vector
    for (int i = 0; i < n; i++)
    {
        double perUnitValue = (1.0 * arr[i].value) / arr[i].weight;
        pair<double, Item> p = make_pair(perUnitValue, arr[i]);
        v.push_back(p);
    }

    // Sort the items in descending order of value per unit weight
    sort(v.begin(), v.end(), cmp);

    // Initialize the total value of the knapsack to 0
    double totalValue = 0;

    // Iterate over the items
    for (int i = 0; i < n; i++)
    {
        // If the weight of the item is more than the remaining capacity of the knapsack
        if (v[i].second.weight > W)
        {
            // Take a fraction of the item that fills the knapsack
            totalValue += W * v[i].first;
            W = 0;
        }
        else
        {
            // If the item can be fully included, add its value to the total value
            totalValue += v[i].second.value;
            // Decrease the remaining capacity of the knapsack
            W = W - v[i].second.weight;
        }
    }
    // Return the maximum total value that can be put in the knapsack
    return totalValue;
}

int main()
{
    // Number of items
    int n = 3;
    // Capacity of the knapsack
    int W = 50;
    // Values and weights of the items
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    // Print the maximum total value that can be put in the knapsack
    cout << fractionalKnapsack(W, arr, n);
    return 0;
}
