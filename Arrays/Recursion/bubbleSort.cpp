/**
 * @brief This program implements the bubble sort algorithm using recursion.
 *        It sorts an array of integers in ascending order.
 * 
 * @param arr The array to be sorted.
 * @param n The size of the array.
 */

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){

    // base case
    // if n becomes 1 then return
    if(n == 1){
        return;
    }

    // recursive case
    // bubble the largest element to the end
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            swap(arr[i], arr[i + 1]);
        }
    }

    // call for the rest of the array
    bubbleSort(arr, n - 1);
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Printing the sorted array
    bubbleSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}