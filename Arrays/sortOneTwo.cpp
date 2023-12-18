/**
 * This code implements the Dutch National Flag algorithm to sort an array of integers containing only 0s, 1s, and 2s.
 * The algorithm partitions the array into three sections: the low section (containing 0s), the mid section (containing 1s), and the high section (containing 2s).
 * It uses three pointers, low, mid, and high, to keep track of the boundaries between the sections.
 * The algorithm iterates through the array and swaps elements to move 0s to the low section, 1s to the mid section, and 2s to the high section.
 * After sorting, the array is printed to the console.
 */

#include<bits/stdc++.h>
using namespace std;

void sortOneTwo(int arr[], int size){
    int low = 0, mid = 0, high = size - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        
        // arr[mid] == 2
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    int arr[6] = {1, 0, 2, 1, 0, 2};
    sortOneTwo(arr, 6);
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
    return 0;
}