// This code finds the element with the maximum frequency in an array.
// It uses an unordered_map to store the frequency of each element.
// The code iterates through the array to update the frequency count and find the maximum frequency.
// Finally, it iterates through the array again to find the first element with the maximum frequency.
// The element with the maximum frequency is returned as the result.
// The time complexity of this code is O(n), where n is the size of the array.
// Q : Maximum Frequency Number
// https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319

// Time complexity => O(n)

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum frequency element in an array
int maximumFrequency(vector<int> &arr, int n)
{
    // Create an unordered_map to store the frequency of elements
    unordered_map<int, int> count;

    // Initialize variables to store the maximum frequency and the corresponding element
    int maxFreq = 0;
    int maxAns = 0;

    // Traverse the array
    for (int i = 0; i < arr.size(); i++)
    {
        // Increment the count of current element in the map
        count[arr[i]]++;

        // Update the maximum frequency
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    // Traverse the array again
    for (int i = 0; i < arr.size(); i++)
    {
        // If the frequency of the current element is equal to the maximum frequency
        if (maxFreq == count[arr[i]])
        {
            // Update the maximum frequency element
            maxAns = arr[i];

            // Break the loop as we found the first maximum frequency element
            break;
        }
    }

    // Return the maximum frequency element
    return maxAns;
}

int main()
{
    vector<int> arr = {1, 2, 2, 3, 1, 2, 3, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3};
    int n = arr.size();
    cout << maximumFrequency(arr, n) << endl;
    return 0;
}
