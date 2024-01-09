/**
 * @brief Reverses the characters of a string using recursion.
 * 
 * This function takes a string as input and recursively reverses its characters.
 * It uses a base case to terminate the recursion when the start index becomes greater than the end index.
 * In each recursive call, it swaps the characters at the start and end indices, and then calls itself for the rest of the string.
 * Finally, it prints the reversed string.
 * 
 * @param str The input string to be reversed.
 * @param i The start index of the substring to be reversed.
 * @param j The end index of the substring to be reversed.
 */

#include<bits/stdc++.h>
using namespace std;

void reverseTheCharsOfAString(string str, int i, int j){

    // base case
    // if i is greater than j then return
    if(i>j){
        return;
    }

    // swap the characters at i and j
    swap(str[i],str[j]);

    // recursive case
    // call for the rest of the string
    reverseTheCharsOfAString(str,i+1,j-1);
}

int main(){
    string str = "Hello";

    // Printing the reversed string
    reverseTheCharsOfAString(str,0,str.length()-1);
    return 0;
}