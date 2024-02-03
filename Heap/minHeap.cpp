#include <bits/stdc++.h> 
using namespace std;

void heapify(vector<int> &arr, int n, int i){

    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }

    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}


vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i=n/2; i>=0; i--){
        heapify(arr, n, i);
    }
    return arr;
}

int main(){
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    vector<int> minHeap = buildMinHeap(arr);
    for(int i=0; i<minHeap.size(); i++){
        cout << minHeap[i] << " ";
    }
    return 0;
}

