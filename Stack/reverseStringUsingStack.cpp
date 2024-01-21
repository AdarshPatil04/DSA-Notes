/**
 * Time Complexity : O(n)
 * Space Complexity : O(n) because of stack
 * This program demonstrates how to reverse a string using a stack.
 * It takes a string as input, pushes each character of the string onto a stack,
 * and then pops and prints the characters in reverse order.
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "babbar";
    stack<char> st;
    // Push all the characters of string s into stack st
    for(int i=0; i<s.length(); i++){
        st.push(s[i]);
    }
    // Pop all the characters of stack st and print them
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}