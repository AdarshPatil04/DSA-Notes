/**
 * Time Complexity: O(nlogk)
 * Space Complexity: O(k)
 * @brief This program finds the kth largest element in an array using a min heap.
 * 
 * The program uses a priority queue (min heap) to store the k largest elements from the array.
 * It iterates through the remaining elements of the array and compares them with the top element of the heap.
 * If the current element is greater than the top element of the heap, it replaces the top element with the current element.
 * Finally, the top element of the heap is the kth largest element in the array.
 */

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    /**
     * @brief Finds the kth largest element in the array.
     * 
     * @param arr The given array.
     * @param l The starting index of the array.
     * @param r The ending index of the array.
     * @param k The kth largest element to find.
     * @return The kth largest element in the array.
     */
    int kthLargest(int arr[], int l, int r, int k) {
        priority_queue<int, vector<int>, greater<int> > pq; // Create a min heap

        // Step-1 : create a min heap for the first k-elements
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        
        // Step-2 : If element is greater than heap's top
        for(int i = k; i<=r; i++){
            if(arr[i] > pq.top()){
                pq.pop(); // Remove the top element from the heap
                pq.push(arr[i]); // Insert the current element into the heap
            }
        }
        
        // The top of the heap is the kth largest element
        int ans = pq.top();
        return ans;
    }
};

int main(){
    int a[6] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    Solution ob;
    cout << ob.kthLargest(a, 0, 5, k) << endl;
    return 0;
}
