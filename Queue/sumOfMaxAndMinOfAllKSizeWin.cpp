/**
 * @brief Calculates the sum of the maximum and minimum elements of all windows of size k in an array.
 * 
 * This function uses a deque to efficiently find the maximum and minimum elements of each window.
 * It iterates through the array, maintaining two deques to store the indices of the maximum and minimum elements.
 * For each element, it removes elements from the back of the deques that are less than or equal to the current element.
 * It then adds the current element to both deques.
 * After processing the first window, it adds the maximum and minimum elements to the answer.
 * For the remaining windows, it removes elements that are out of the current window and repeats the process.
 * Finally, it returns the sum of the maximum and minimum elements of all windows.
 * 
 * @param arr The array of integers.
 * @param n The size of the array.
 * @param k The size of the window.
 * @return The sum of the maximum and minimum elements of all windows of size k.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum of maximum and minimum of all windows of size k in the array
int solve(int *arr, int n, int k) {

    // Deque to store the indices of maximum elements of the window
    deque<int> maxi(k);
    // Deque to store the indices of minimum elements of the window
    deque<int> mini(k);

    // Process the first k elements in the array
    for(int i=0; i<k; i++) {

        // Remove elements from the back of maxi deque which are less than or equal to current element
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        // Remove elements from the back of mini deque which are greater than or equal to current element
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        // Add the current element to both the deques
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    // Add the maximum and minimum element of the first window to the answer
    ans += arr[maxi.front()] + arr[mini.front()];

    // Process the remaining windows
    for(int i=k; i<n; i++) {

        // Remove elements which are out of the current window
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        // Add the current element to the deques
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);    

        // Add the maximum and minimum element of the current window to the answer
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main() {

    // Array of integers
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    // Size of the window
    int k = 4;
    // Print the sum of maximum and minimum of all windows of size k in the array
    cout << solve(arr, 7, k) << endl;

    return 0;
}
