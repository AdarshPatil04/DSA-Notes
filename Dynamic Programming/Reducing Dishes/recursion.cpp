/**
 * The time complexity of the code is exponential, O(2^n), and the space complexity is O(n).
 * This code solves the "Reducing Dishes" problem from LeetCode.
 * Given a list of satisfaction levels for dishes, the goal is to find the maximum total satisfaction
 * that can be achieved by cooking a subset of the dishes in a specific order.
 * The code uses a recursive approach to calculate the maximum satisfaction by including or excluding each dish.
 */
// https://leetcode.com/problems/reducing-dishes/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve the problem
int solveRec(vector<int> &satisfaction, int index, int time)
{
    // Base case: If we have reached the end of the satisfaction vector, return 0
    if (index == satisfaction.size())
        return 0;

    // Include the current dish in the cooking sequence
    // The satisfaction gained is the cooking time multiplied by the satisfaction of the dish
    // Recursively solve for the next dish with the cooking time increased by 1
    int include = time * satisfaction[index] + solveRec(satisfaction, index + 1, time + 1);

    // Exclude the current dish from the cooking sequence
    // Recursively solve for the next dish with the same cooking time
    int exclude = solveRec(satisfaction, index + 1, time);

    // Return the maximum satisfaction gained from including or excluding the current dish
    return max(include, exclude);
}

// Function to find the maximum total satisfaction
int maxSatisfaction(vector<int> &satisfaction)
{
    // Step-1: Sort the satisfaction vector in ascending order
    // This ensures that the dishes with the least satisfaction are cooked first
    sort(satisfaction.begin(), satisfaction.end());

    // Solve the problem using recursion starting from the first dish with a cooking time of 1
    return solveRec(satisfaction, 0, 1);
}

int main()
{
    // Test case: Satisfaction levels of the dishes
    vector<int> satisfaction = {-1, -8, 0, 5, -9};

    // Print the maximum total satisfaction
    cout << maxSatisfaction(satisfaction) << endl;

    return 0;
}
