#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &arr){
    int s = 0, e = arr.size() - 1;
    while(s < e){
        int mid = s + (e - s) / 2;
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }
    return s;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << findPivot(arr);
    return 0;
}