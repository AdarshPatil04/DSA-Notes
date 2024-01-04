/**
 * This code finds the maximum occurring character in a given string.
 * It uses an array of 26 characters to store the count of each character.
 * The string is traversed and the count of each character is incremented.
 * Finally, the character with the maximum count is returned.
 */

#include<bits/stdc++.h>
using namespace std;

// Function to get the maximum occurring character in a string
char getMaxOccChar(string s){

    // Create array of 26 characters and initialize it with 0 
    int arr[26] = {0};

    // Traverse the string and increment the count of each character
    for(int i=0; i<s.length(); i++){

        // Subtracting 'a' from each character will give us the index of that character in the array
        int number = s[i] - 'a';

        // Increment the count of that character
        arr[number]++;
    }

    // Find the maximum occurring character
    int maxi = -1, answer = 0;
    for(int i=0; i<26; i++){
        if(arr[i] > maxi){
            maxi = arr[i];

            // Adding 'a' to the index will give us the character
            answer = i+'a';
        }
    }

    return answer;
}

int main(){
    string s = "test";

    // Print the maximum occurring character
    cout<<getMaxOccChar(s);
    return 0;
}