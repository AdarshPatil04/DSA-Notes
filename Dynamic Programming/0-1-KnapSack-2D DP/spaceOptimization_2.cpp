//https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;

//Time Complexity => O(N*W)
//Space Complexity => O(maxWeight)
int solveTabSO2(vector<int>& weight, vector<int>& value, int n, int maxWeight) {

	//Step-1: 
	vector<int> curr(maxWeight+1, 0);

	//Step-2:
	for(int w = weight[0]; w<=maxWeight; w++) {
		if(weight[0] <= maxWeight) 
			curr[w] = value[0];
		else 
			curr[w] = 0;
	}

	//step-3:
	for(int i=1; i<n; i++) {
		for(int w=maxWeight; w>=0; w--) {
			
			int include = 0;
			if(weight[i] <= w)
				include = value[i] + curr[w-weight[i]];
			
			int exclude = 0 + curr[w];

			curr[w] = max(include, exclude);
		}
	}
	return curr[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	//Space-Optimisation -> O(N)
	return solveTabSO2(weight, value, n, maxWeight);
}
