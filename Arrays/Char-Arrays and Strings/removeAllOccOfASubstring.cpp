/**
 * @brief This code demonstrates the removal of all occurrences of a given string from another string.
 * 
 * The `removeOcc` function takes two string parameters: `s` (the original string) and `part` (the string to be removed).
 * It uses a while loop to iterate as long as the original string is not empty and contains the given string.
 * Inside the loop, it uses the `find` function to locate the first occurrence of the given string in the original string.
 * Then, it uses the `erase` function to remove the given string from the original string.
 * Finally, it returns the modified string.
 * 
 * The `main` function demonstrates the usage of the `removeOcc` function by removing all occurrences of "abc" from the string "daabcbaabcbc".
 * The modified string is then printed to the console.
 */

#include<bits/stdc++.h>
using namespace std;

// Function to remove all occurrences of a given string from another string
string removeOcc(string s, string part){

    // Iterate if the string is not empty and it contains the given string to be found out, s.find(part) returns the index of the first occurrence of the given string
    while(s.length() != 0 && s.find(part) < s.length()){

        // Erase the given string from the string, s.erase(index, length) erases the string from the given index to the given length
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main(){
    string s = "daabcbaabcbc";

    // Print the modified string
    cout<<removeOcc(s, "abc");
    return 0;
}