/**
 * This code calculates the kth largest sum of subarrays in a given array.
 * It iterates over the array and calculates the sum of all possible subarrays starting from each element.
 * The sums are stored in a vector and sorted in ascending order.
 * The kth largest sum is then returned.
 *
 * Time complexity: O(n^2 logn)
 * Space complexity: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;

// Function to get the kth largest sum of subarrays
int getKthLargest(vector<int> &arr, int k)
{
	// Vector to store the sums of all possible subarrays
	vector<int> sumStore;

	// Iterate over the array
	for (int i = 0; i < arr.size(); i++)
	{
		int sum = 0;
		// For each element, calculate the sum of all subarrays starting from it
		for (int j = i; j < arr.size(); j++)
		{
			sum += arr[j];
			// Store the sum in the vector
			sumStore.push_back(sum);
		}
	}

	// Sort the vector in ascending order
	sort(sumStore.begin(), sumStore.end());

	// Return the kth largest sum, which is the (n-k)th element from the start
	return sumStore[sumStore.size() - k];
}

int main()
{
	// Input array
	vector<int> arr = {10, -10, 20, -40};
	// The value of k
	int k = 6;

	// Print the kth largest sum of subarrays
	cout << getKthLargest(arr, k) << endl;

	return 0;
}
