/**
 * @brief This code implements the insertion sort algorithm to sort a vector of integers in ascending order.
 *
 * The insertion sort algorithm works by dividing the input array into a sorted and an unsorted region.
 * It iterates through the unsorted region, comparing each element with the elements in the sorted region
 * and inserting it at the correct position to maintain the sorted order.
 *
 * Time Complexity: W.S.:- O(n^2), B.S.:- O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    // Start from the second element because the first element is already sorted
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];

        /* Alternative code:

        // start from the element before the current element
        int j = i - 1;
        while(j>=0){

            // Check if the element is greater than the temp
            if(arr[j]>temp){
                arr[j+1] = arr[j];
                j--;
            }
            else{
                break;
            }

        // Insert the element at the correct position
        arr[j+1] = temp;
    }
        */

        // start from the element before the current element
        int j = i - 1;

        // Check if the element is greater than the temp
        while (j >= 0 && arr[j] > temp)
        {

            // Shift the elements to the right
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the element at the correct position
        arr[j + 1] = temp;
    }
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    insertionSort(arr);

    // Print the sorted array
    for(auto i: arr){
        cout<<i<<" ";
    }
    return 0;
}