/**
 * This code demonstrates the usage of the deque container in C++.
 * It shows how to push elements into the deque from the front and back,
 * pop elements from the front and back, access the front and back elements,
 * and check the size and emptiness of the deque.
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    // Declaring a deque
    deque<int> dq;

    // Pushing elements into deque from front and back and printing them
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    for(auto i:dq){
        cout<<i<<" ";
    }
    cout<<endl;

    // Popping elements from front and back and printing the remaining
    dq.pop_back();
    dq.pop_front();
    for(auto i:dq){
        cout<<i<<" ";
    }
    cout<<endl;

    // Printing the front and back elements of the deque
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;

    // Printing the size of the deque and whether it is empty or not
    cout<<dq.size()<<endl;
    cout<<dq.empty()<<endl;
    return 0;
}