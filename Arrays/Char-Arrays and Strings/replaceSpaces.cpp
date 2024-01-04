/**
 * @brief This program replaces spaces in a given string with "@40".
 *        It takes a string as input, iterates through each character,
 *        and replaces spaces with "@40". The modified string is then returned.
 * 
 * @param s The input string
 * @return The modified string with spaces replaced by "@40"
 */

#include<bits/stdc++.h>
using namespace std;   

string replaceSpaces(string s){

    // Create an empty temporary string and later add characters to it
    string temp = "";
    for(int i=0; i<s.length(); i++){

        // If the character is a space, replace it with "@40"
        if(s[i] == ' '){
            temp += "@40";
        }

        // Else, add the character to the string
        else{
            temp.push_back(s[i]);
        }
    }
    return temp;
}

int main(){
    string s = "Hello World";

    // Print the modified string
    cout<<replaceSpaces(s);
    return 0;
}