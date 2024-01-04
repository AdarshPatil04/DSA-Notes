/**
 * @brief This program demonstrates how to reverse the order of words in a string.
 * 
 * The `reverseOrderOfWords` function takes a string as input and returns a new string
 * with the words in reverse order. It skips any leading or trailing spaces and handles
 * multiple spaces between words. The main function initializes a string and calls the
 * `reverseOrderOfWords` function to print the reversed order of words in the string.
 */

// Problem no.: 186 (Leetcode) Explanation: https://youtu.be/vhnRAaJybpA?si=QcBGFi3eO51ND18W 

#include<bits/stdc++.h>
using namespace std;

// This function reverses the order of words in a string
string reverseOrderOfWords(string s){
    string result;
    int i = 0, n = s.length();

    // Traverse the string
    while(i<n){

        // For skipping the spaces
        while(i<n && s[i] == ' '){
            i++;
        }

        // Break if i reaches the end of the string
        if(i>=n){
            break;
        }

        // Store the index of the first character of the word
        int j = i+1;

        // Traverse the word
        while(j<n && s[j] != ' '){
            j++;
        }

        // Store the word in a string
        string sub = s.substr(i, j-i);

        // If the result is empty, store the word in the result
        if(result.length() == 0){
            result = sub;
        }

        // Otherwise, store the word in the result with a space before it
        else{
            result = sub + " " + result;
        }

        // Increment i to the index of the next word/spaces
        i = j+1;
    }
    return result;
}

int main(){
    string s = "the sky is blue";

    // Printing the reversed order of words in the string
    cout<<reverseOrderOfWords(s)<<endl;
    return 0;
}