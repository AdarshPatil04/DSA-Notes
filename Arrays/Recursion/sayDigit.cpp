#include<bits/stdc++.h>
using namespace std;

void sayDigit(int n, string arr[]){
    if(n==0){
        return;
    }
    int digit = n % 10;
    n /= 10;
    sayDigit(n, arr);
    cout<<arr[digit]<<" ";
}

int main(){
    int n = 10;
    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    sayDigit(10,arr);

    return 0;
}