/**
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 * @brief This code calculates the minimum cost of connecting ropes.
 * 
 * The code uses a priority queue (min heap) to store the lengths of the ropes.
 * It repeatedly selects the two smallest ropes, connects them, and adds the cost to the total cost.
 * The process continues until only one rope remains.
 * The final cost is returned as the result.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        // Step-1 : Create a minHeap using priority queue
        // The priority queue is a standard STL in C++ which by default creates a max heap.
        // We modify it to create a min heap by specifying 'greater' in the third template parameter.
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        
        // Step-2 : Push all elements into the priority queue
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        // Step-3 : Calculate minimum cost
        long long cost = 0;
        
        // Continue till only one element remains in the priority queue
        while(pq.size() > 1){
            
            // Pop two smallest elements from the priority queue
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            // Calculate their sum
            long long sum = a + b;
            
            // Add the sum to the cost
            cost += sum;
            
            // Push the sum back into the priority queue
            pq.push(sum);
        }
        // Return the final cost
        return cost;
    }
};

int main() {
    // Array of rope lengths
    long long arr[4] = {4, 2, 7, 6};
    // Number of ropes
    long long n = 4;
    // Create a Solution object
    Solution ob;
    // Call the minCost function and print the result
    cout << ob.minCost(arr, n) << endl;
    return 0;
}
