//https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;

//Time Complexity => O(N*W)
//Space Complexity => O(N*W)
int solveTab(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
	
	//step-1: creation of 2-D Array
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

	//step-2: analyse the base case
	for(int w = weight[0]; w <= maxWeight; w++) {
		if(weight[0] <= maxWeight)
			dp[0][w] = value[0];
		else
			dp[0][w] = 0;
	}

	//step-3: run loop for the remaining cases
	for(int index = 1; index<n; index++) {
		for(int w = 0; w <= maxWeight; w++) {

			int include = 0;
			if(weight[index] <= w)
				include = value[index] + dp[index-1][w-weight[index]];
			
			int exclude = 0 + dp[index-1][w];

			dp[index][w] = max(include, exclude);	
		}
	}
	return dp[n-1][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Tabulation-> Bottom Up
	return solveTab(weight, value, n, maxWeight);
}
